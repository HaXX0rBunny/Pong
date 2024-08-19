#pragma once

#include <string>	
#include <list>
#include <map>
#include <vector>
struct Event
{
	Event();
	virtual ~Event();

	std::string name;
};

class Entity
{
public:
	virtual void OnEvent(Event* ev) = 0;
};

struct LocalEvent : public Event
{
	Entity* owner;
};

class EventManager
{
    static EventManager* Instance_;
    EventManager() = default;
    std::vector<EventManager*> Component;
    ~EventManager();
public:
    static EventManager* Instance() {
        if (Instance_ == nullptr)
            Instance_ = new EventManager;
        return Instance_;
    }
    static void clear();
    EventManager* GetComponent(const std::string& str) const;
    void AddComponent(EventManager* component);
    void RemoveComp(EventManager* component);
    void Update();


};
