#include "Registry.h"
#include "../Components/TransformComp.h"
#include "../Components/PlayerComp.h"
#include "../Components/RigidbodyComp.h"
#include "../Components/SpriteComp.h"
#include "../Components/AudioComponent.h"

Registry* Registry::Instance_ = nullptr;  

Registry::Registry()
{
    //Register All the functions

    rttiMap.insert({ TransformComp::GetType(), TransformComp::CreateTransformComp});
    rttiMap.insert({ PlayerComp::GetType(), PlayerComp::CreatePlayerComp });
    rttiMap.insert({ RigidbodyComp::GetType(), RigidbodyComp::CreateRigidbodyComp });
    rttiMap.insert({ SpriteComp::GetType(), SpriteComp::CreateSpriteComp });
    rttiMap.insert({ AudioComp::GetType(), AudioComp::CreateAudioComp });
    

//    rttiMap.insert(std::pair<std::string, BaseRTTI * (*)()>("TransformComp", TransformComp::CreateTransformComp));
}
Registry::~Registry()
{
    Delete();
}




void Registry::Delete()
{
    if (Instance_ != nullptr)
        delete Instance_;
    Instance_ = nullptr;
}

BaseRTTI* Registry::FindAndCreate(const std::string& type)///<<< 
{
    if (rttiMap.find(type) == rttiMap.end())
    {
        return nullptr;// if not found   
    }
    if (rttiMap.find(type)->second() == nullptr)// if have not function;
        return nullptr;
    return rttiMap.find(type)->second();
 //final find create somethiong
}
