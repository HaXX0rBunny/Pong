#include "EngineComponent.h"
#include "../ComponentManager/EngineManager.h"

EngineComponent::EngineComponent()
{
	EngineManager::Instance()->AddComponent(this);
}

EngineComponent::~EngineComponent()
{
	EngineManager::Instance()->RemoveComp(this);
}
