#pragma once

#include <string>
#include <list>
#include <map>
#include <vector>
#include <memory>

// 기본 Event 구조체
struct Event {
    std::string name;
    Event(const std::string& name) : name(name) {}
    virtual ~Event() = default;
};

// 특정 이벤트를 처리할 수 있는 엔티티 인터페이스
class Entity {
public:
    virtual void OnEvent(Event* ev) = 0;
    virtual ~Entity() = default;
};

// EventManager 싱글톤 클래스
class EventManager {
public:
    static EventManager* Instance() {
        if (!Instance_) {
            Instance_ = new EventManager();
        }
        return Instance_;
    }

    static void Clear() {
        if (Instance_) {
            delete Instance_;
            Instance_ = nullptr;
        }
    }

    // 이벤트 추가
    void AddEvent(Event* event) {
        events.push_back(event);
    }

    // 엔티티를 특정 이벤트에 등록
    void RegisterEntity(const std::string& eventName, Entity* entity) {
        registeredEntities[eventName].push_back(entity);
    }

    // 엔티티의 이벤트 등록 해제
    void UnregisterEntity(const std::string& eventName, Entity* entity) {
        auto& entityList = registeredEntities[eventName];
        entityList.remove(entity);
    }

    // 모든 이벤트 디스패치
    void DispatchAllEvents() {
        for (auto event : events) {
            const std::string& eventName = event->name;
            auto& entityList = registeredEntities[eventName];
            for (auto entity : entityList) {
                entity->OnEvent(event);
            }
            delete event;  // 이벤트 처리 후 메모리 해제
        }
        events.clear();  // 처리된 이벤트 목록 비우기
    }

    // 소멸자에서 미처리된 이벤트 삭제
    ~EventManager() {
        for (auto event : events) {
            delete event;
        }
        events.clear();
    }

private:
    EventManager() = default;
    static EventManager* Instance_;

    std::list<Event*> events;
    std::map<std::string, std::list<Entity*>> registeredEntities;
};

// 싱글톤 인스턴스 초기화
EventManager* EventManager::Instance_ = nullptr;
