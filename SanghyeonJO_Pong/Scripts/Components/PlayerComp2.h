#pragma once
#include "../Components/LogicComponent.h"

class PlayerComp2: public LogicComponent
{
	float moveSpeed;
	float spin;
	float worldLimit;
public:
	PlayerComp2(GameObject* owner);
	~PlayerComp2();
	void Update() override;
	static std::string GetType()
	{
		return "PlayerComp";
	}
	void LoadFromJson(const json& data)override ;

	static BaseRTTI* CreatePlayerComp();

	json SaveToJson()override ;
};