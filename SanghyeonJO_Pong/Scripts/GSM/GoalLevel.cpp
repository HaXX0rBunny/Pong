#include "GoalLevel.h"
#include "GameStateManager.h"
#include <iostream>
void Levels::GoalLevel::Init()
{
	
	std::cout << "Goal level Init" << std::endl;
}

void Levels::GoalLevel::Update()
{
	std::cout << "Goal level Update" << std::endl;
	std::cout << "Yow Win" << std::endl;
	//after something . change level to exit

	GSM::GameStateManager::GetGSMPtr()->ChangeLevel(nullptr);
}
void Levels::GoalLevel::Exit()
{
	std::cout << "Goal level Exit" << std::endl;

}