#pragma once

#include <string>	
#include <list>
#include <map>

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
	//Make singleton
	
	//A container for all my events*

	//A container to have which entities are registered to which events
	//map of (event, container of entities*)

	//Interface:
	//Add an event (event*) this are pointers to dynamic memory, called as the following: AddEvent(new Event);
	// 
	// templated fn:
	//		Register entities to a certain event TYPE
	//		Unregister entities to a certain event TYPE
	//
	// DispatchAllEvents
	//

	//delete undispatched events if any on destructor


};
