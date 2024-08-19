#include "GraphicsComponent.h"
#include "../ComponentManager/GraphicsManager.h"

GraphicsComponent::GraphicsComponent()
{
    GraphicsManager::Instance()->AddComponent(this);
}

GraphicsComponent::GraphicsComponent(GameObject* owner)
    : BaseComponent(owner)
{
    GraphicsManager::Instance()->AddComponent(this);
}

GraphicsComponent::~GraphicsComponent()
{
    GraphicsManager::Instance()->RemoveComp(this);
}