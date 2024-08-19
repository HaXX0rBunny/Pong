#pragma once
#include "BaseLevel.h"
#include "../GameObject/GameObject.h"
namespace Levels
{
	class MainLevel :public GSM::BaseLevel
	{
		void Init() override;
		void Update() override;
		void Exit() override;
	public: 
		int counter=0;
		GameObject* player;
		GameObject* planet;
	};
}