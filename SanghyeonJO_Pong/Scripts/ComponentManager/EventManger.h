#pragma once

#include <string>
#include <list>
#include <map>
#include <vector>
#include <memory>

// �⺻ Event ����ü
struct Event {
    std::string name;
    Event(const std::string& name) : name(name) {}
    virtual ~Event() = default;
};

// Ư�� �̺�Ʈ�� ó���� �� �ִ� ��ƼƼ �������̽�
class Entity {
public:
    virtual void OnEvent(Event* ev) = 0;
    virtual ~Entity() = default;
};

// EventManager �̱��� Ŭ����
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

    // �̺�Ʈ �߰�
    void AddEvent(Event* event) {
        events.push_back(event);
    }

    // ��ƼƼ�� Ư�� �̺�Ʈ�� ���
    void RegisterEntity(const std::string& eventName, Entity* entity) {
        registeredEntities[eventName].push_back(entity);
    }

    // ��ƼƼ�� �̺�Ʈ ��� ����
    void UnregisterEntity(const std::string& eventName, Entity* entity) {
        auto& entityList = registeredEntities[eventName];
        entityList.remove(entity);
    }

    // ��� �̺�Ʈ ����ġ
    void DispatchAllEvents() {
        for (auto event : events) {
            const std::string& eventName = event->name;
            auto& entityList = registeredEntities[eventName];
            for (auto entity : entityList) {
                entity->OnEvent(event);
            }
            delete event;  // �̺�Ʈ ó�� �� �޸� ����
        }
        events.clear();  // ó���� �̺�Ʈ ��� ����
    }

    // �Ҹ��ڿ��� ��ó���� �̺�Ʈ ����
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

// �̱��� �ν��Ͻ� �ʱ�ȭ
EventManager* EventManager::Instance_ = nullptr;
