#pragma once

#include <string>
#include <list>
#include <map>
#include <typeinfo>
#include <typeindex>

// Base Event class
struct Event
{
    Event() {}
    virtual ~Event() {}

    std::string name;
};

// Base Entity class
class Entity
{
public:
    virtual void OnEvent(Event* ev) = 0;
};

// Local Event class
struct LocalEvent : public Event
{
    Entity* owner;
};

// Event Manager Singleton
class EventManager
{

    // Singleton instance
    static std::unique_ptr<EventManager> Instance_;

    // Container for events
    std::list<Event*> events;

    // Map of event type to entities registered to that event
    std::map<std::type_index, std::list<Entity*>> eventRegistry;

    // Private constructor for Singleton pattern
    EventManager() {}

public:
    // Get the singleton instance
    static EventManager* Instance() {
        if (!Instance_) {
            Instance_ = std::make_unique<EventManager>();
        }
        return Instance_.get();
    }

    // Destructor: Delete all events in the list
    ~EventManager()
    {
        for (auto& event : events)
        {
            delete event;
        }
    }

    // Add an event to the event list
    void AddEvent(Event* ev)
    {
        events.push_back(ev);
    }

    // Register an entity to a specific event type
    template <typename T>
    void RegisterEntity(Entity* entity)
    {
        eventRegistry[typeid(T)].push_back(entity);
    }

    // Unregister an entity from a specific event type
    template <typename T>
    void UnregisterEntity(Entity* entity)
    {
        auto& entities = eventRegistry[typeid(T)];
        entities.remove(entity);
    }

    // Dispatch all events to the appropriate entities
    void DispatchAllEvents()
    {
        for (auto& event : events)
        {
            auto& entities = eventRegistry[typeid(*event)];
            for (auto& entity : entities)
            {
                entity->OnEvent(event);
            }
            delete event; // Delete the event after processing
        }
        events.clear(); // Clear the event list after dispatch
    }
};

// Define static instance pointer
EventManager* EventManager::instance = nullptr;

