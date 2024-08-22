#pragma once
#include "../Components/EngineComponent.h"
#include <vector>
class EngineManager
{
    static std::unique_ptr<EngineManager> Instance_;
    EngineManager() = default;
    std::vector<EngineComponent*> Component;

public:
    static EngineManager* Instance() {
        if (!Instance_) {
            Instance_ = std::make_unique<EngineManager>();
        }
        return Instance_.get();
    }
    ~EngineManager();
    static void clear();
    EngineComponent* GetComponent(const std::string& str) const;
    void AddComponent(EngineComponent* component);
    void RemoveComp(EngineComponent* component);
    void Update();
};
