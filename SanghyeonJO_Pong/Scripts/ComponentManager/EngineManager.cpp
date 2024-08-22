#include "EngineManager.h"
std::unique_ptr<EngineManager> EngineManager::Instance_ = nullptr;

EngineManager::~EngineManager()
{
    // 컴포넌트들을 해제합니다.
    for (auto component : Component) {
        delete component;
    }
    Component.clear();
}

void EngineManager::clear()
{
    if (Instance_) {
        delete Instance_;
        Instance_ = nullptr;
    }
}

EngineComponent* EngineManager::GetComponent(const std::string& str) const
{
    for (auto a : Component)
        if (a->GetType() == str)
            return a;
    return nullptr;
}

void EngineManager::AddComponent(EngineComponent* component)
{
    Component.push_back(component);
}

void EngineManager::RemoveComp(EngineComponent* component)
{
    Component.erase(std::find(Component.begin(), Component.end(), component));
}

void EngineManager::Update()
{
    for (auto it : Component)
    {
        it->Update();
    }
}
