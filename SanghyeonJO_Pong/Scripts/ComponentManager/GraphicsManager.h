#pragma once
#include "../Components/GraphicsComponent.h"
#include <vector>
class GraphicsManager
{
    static std::unique_ptr<GraphicsManager> Instance_;
    std::vector<GraphicsComponent*> Component;

public:
    static GraphicsManager* Instance() {
        if (!Instance_) {
            Instance_ = std::make_unique<GraphicsManager>();
        }
        return Instance_.get();
    }
    ~GraphicsManager();
    void clear();
    GraphicsComponent* GetComponent(const std::string& str) const;
    void AddComponent(GraphicsComponent* component);
    void RemoveComp(GraphicsComponent* component);
    void Update();
};