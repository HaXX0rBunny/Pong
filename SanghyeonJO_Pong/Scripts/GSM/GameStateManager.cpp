#include "GameStateManager.h"
#include "BaseLevel.h"

#include "../ComponentManager/EngineManager.h"
#include "../ComponentManager/LogicManager.h"
#include "../ComponentManager/GraphicsManager.h"


GSM::GameStateManager* GSM::GameStateManager::ptr = nullptr;

GSM::GameStateManager::GameStateManager() : previousLevel(nullptr), currentLevel(nullptr) {}

GSM::GameStateManager::~GameStateManager() {
    if (previousLevel) delete previousLevel;
    if (currentLevel) delete currentLevel;
}

GSM::GameStateManager* GSM::GameStateManager::GetGSMPtr() {
    if (ptr == nullptr) {
        ptr = new GameStateManager;
    }
    return ptr;
}

void GSM::GameStateManager::DeleteGSM() {
    if (ptr) {
        delete ptr;
        ptr = nullptr;
    }
}

void GSM::GameStateManager::Init() {
    if (currentLevel) {
        currentLevel->Init();
    }
}

void GSM::GameStateManager::Update() {
    if (currentLevel) {
        EngineManager::Instance()->Update();
        LogicManager::Instance()->Update();
        GraphicsManager::Instance()->Update();

        currentLevel->Update();
    }
}

void GSM::GameStateManager::Exit() {
    if (currentLevel) {
        currentLevel->Exit();
    }
}

void GSM::GameStateManager::ChangeLevel(BaseLevel* newLvl) {
    if (previousLevel)
        delete previousLevel;
    previousLevel = currentLevel;

    Exit();
    currentLevel = newLvl;
    Init();
}

bool GSM::GameStateManager::ShouldExit() {
    return currentLevel == nullptr;
}
