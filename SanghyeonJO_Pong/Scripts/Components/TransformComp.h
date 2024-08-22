#pragma once
#include "AEMath.h"
#include "AEVec2.h"

#include "../ComponentManager/EngineManager.h"
#include "../Components/EngineComponent.h"

class TransformComp : public EngineComponent
{
	AEVec2 pos;
	AEVec2 scale;
	float rot;

	AEMtx33 trancsformMatrix;

	void CalculateMatrix();
public:
	TransformComp();
	TransformComp(GameObject* owner);
	
	~TransformComp();
	void Update() override;

	//Gettors
	const AEVec2& GetPos() const { return pos; };
	const AEVec2& Getscale() const { return scale; };
	const float GetRot() const { return rot; };
	const AEMtx33& GetMatrix() const;
	//Mutators
	void SetPos(const AEVec2& otherPos);
	void SetScale(const AEVec2& otherScale);
	void SetRot(const float& otherRot);
	void PrintMatrix();
	static std::string GetType()
	{
		return "TransformComp";
	}
	void LoadFromJson(const json& data)override ;

	json SaveToJson()override ;
	//For the RTTI
	static BaseRTTI* CreateTransformComp();

};