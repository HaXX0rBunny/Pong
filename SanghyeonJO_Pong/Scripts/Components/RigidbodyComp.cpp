#include "RigidbodyComp.h"
#include "../GameObject/GameObject.h"
#include "TransformComp.h"
#include "AEEngine.h"
#include "AEFrameRateController.h"
bool RigidbodyComp::CheckEpsilon(float v, float Ep)
{
	if (v< -Ep || v > Ep)
		return true;
	return false;

}
RigidbodyComp::RigidbodyComp()
{
	Velocity.x = 0;
	Velocity.y = 0;
	MaxVelocity.x = 100;
	MaxVelocity.y = 100;
}

RigidbodyComp::RigidbodyComp(GameObject* owner): Velocity()
{
	Velocity.x = 0;
	Velocity.y = 0;
	MaxVelocity.x = 100;
	MaxVelocity.y = 100;
}

void RigidbodyComp::AddVelocity(float x, float y)
{
	Velocity.x += x;
	Velocity.y += y;

	AEClamp(Velocity.x, -MaxVelocity.x, MaxVelocity.x);

	AEClamp(Velocity.y, -MaxVelocity.y, MaxVelocity.y);
}

void RigidbodyComp::ClearVelocity()
{
	Velocity.x = 0;
	Velocity.y = 0;
}

void RigidbodyComp::Update()
{
	//Do NOT COPY THIS
	TransformComp* t = own->GetComponent<TransformComp>();
	if (!t)
		return;
	float x = t->GetPos().x + static_cast<float>(Velocity.x * AEFrameRateControllerGetFrameTime());
	float y = t->GetPos().y + static_cast<float>(Velocity.y * AEFrameRateControllerGetFrameTime());

	//Velocity.x /= drag;

	//Velocity.y /= drag;

	if (CheckEpsilon(Velocity.x) == false)
		Velocity.x = 0;

	if (CheckEpsilon(Velocity.y) == false)
		Velocity.y = 0;

	t->SetPos({ x,y });
}

void RigidbodyComp::LoadFromJson(const json& data)
{
}

json RigidbodyComp::SaveToJson()
{
	return json();
}

BaseRTTI* RigidbodyComp::CreateRigidbodyComp()
{
	return nullptr;
}
