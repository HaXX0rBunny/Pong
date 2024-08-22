#pragma once
#include "../Components/LogicComponent.h"
#include <vector>
class LogicManager
{
    static std::unique_ptr<LogicManager> Instance_;
    LogicManager() = default;
    std::vector<LogicComponent*> Component;

public:
    static LogicManager* Instance() {
        if (!Instance_) {
            Instance_ = std::make_unique<LogicManager>();
        }
        return Instance_.get();
    }
    ~LogicManager();
    static void clear();
    LogicComponent* GetComponent(const std::string& str) const;
    void AddComponent(LogicComponent* component);
    void RemoveComp(LogicComponent* component);
    void Update();
};
