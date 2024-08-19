#include "LogicComponent.h"
#include "../ComponentManager/LogicManager.h"
LogicComponent::LogicComponent()
{
	LogicManager::Instance()->AddComponent(this);
}

LogicComponent::~LogicComponent()
{
	LogicManager::Instance()->RemoveComp(this);
}
