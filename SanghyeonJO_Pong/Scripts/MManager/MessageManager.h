#pragma once
// Or Event Manager(SingleTon)
// Anything Can be an event

// Something we read to in gorm other about

//We React to event

//obj register to contain events


//Global event local event 
//    Event ->( data ).......
//Ex: collider Event -> Pos
//    explosion Event -> Pos Radius
//    enemy saw    -> pos Las , enemy direc, enemy type
//    On death
//    On walk
//    On Achivemnet


//List Of current game events
//~~~ Whitch Obj React to which Events
#include <string>

struct Message
{
	Message(const std::string& name) : name(name) {}
	virtual ~Message() = default;
	std::string name;
};
class Entity 
{
public:
	virtual void OnEvent(Message* ev)= 0;
};
struct GlobalEvent : public Message
{
	GlobalEvent(const std::string& name, Entity* owner) : Message(name), owner(owner) {}
	Entity* owner;
};
struct LocalEvent : public Message
{
	LocalEvent(const std::string& name, Entity* owner) : Message(name), owner(owner) {}
	Entity* owner;
};
#include <list>
#include <map>
class MessageManager
{
	MessageManager();
	~MessageManager();
	MessageManager(const MessageManager& other) = delete;
	const MessageManager& operator=(const MessageManager& other) = delete;
	//Make SingleTon
	static MessageManager instance_;
	static MessageManager& Instance() {
		
		return instance_;
	}
	

	//A constainer for all my event
	
	//A container to have which entities are registerd to which events
	//map of (evnets, constainer of entities(list or vector or map) *)
	
	//std::map<std::string, std::list<Entity*>> registeredEntities;


	//Interface:
	//Add an event(event*(of any type) ) this are pointers to dynamic memorym, called as the following: AddEvent(new Event);
	// Register Entities
	// UnRegister Entities
	//
	//Templateed fn:
	//		Register entities to a certain event Type
	//		Unregister entities to a cerain event Type
	///
	// DispatchAllEvnets
	// 

	//delete undispatched events if any on destructor



};