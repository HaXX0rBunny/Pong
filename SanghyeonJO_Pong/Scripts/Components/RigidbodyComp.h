#pragma once
#include "../Components/EngineComponent.h"
#include "AEVec2.h"
class RigidbodyComp : public EngineComponent
{
	float drag = 0.5f;
	AEVec2 Velocity;
	AEVec2 MaxVelocity;
	bool CheckEpsilon(float v, float Ep = EPSILON);


public:
	RigidbodyComp();
	RigidbodyComp(GameObject* owner);
	
	//void Addvelocity(const AEVec2& otherVec);
	void AddVelocity(float x , float y);
	AEVec2 GetVelocity();
	void SetVelocity(float x, float y);
	void ClearVelocity();
	
	
	void Update() override;
	static std::string GetType()
	{
		return "RigidbodyComp";
	}
	void LoadFromJson(const json& data)override;

	json SaveToJson()override ;
	static BaseRTTI* CreateRigidbodyComp();
};