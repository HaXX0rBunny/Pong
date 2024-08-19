#include "PlayerComp.h"
#include "AEEngine.h"
#include "AEInput.h"
#include "TransformComp.h"
#include "RigidbodyComp.h"
#include "../GameObject/GameObject.h"
PlayerComp::PlayerComp(GameObject* owner) {
	moveSpeed = 10;
	spin = 1;
}

PlayerComp::~PlayerComp()
{
}

void PlayerComp::Update()
{

	//if (BaseComponent::Update() == false)
	//	return;
	//Check for input

	TransformComp* t = own->GetComponent<TransformComp>();
	if (!t)
		return;
	RigidbodyComp* r = own->GetComponent<RigidbodyComp>();
	if (!t)
		return;
	if (t)
	{
		if (AEInputCheckCurr(AEVK_W))
		{
			//t->SetPos({ t->GetPos().x, t->GetPos().y + moveSpeed });
			//Move my transform
			r->AddVelocity(0, moveSpeed);
		}
		if (AEInputCheckCurr(AEVK_A))
		{
			//t->SetPos({ t->GetPos().x - moveSpeed, t->GetPos().y });
			//Move my transform

			r->AddVelocity(-moveSpeed, 0);
		}
		if (AEInputCheckCurr(AEVK_S))
		{
			//t->SetPos({ t->GetPos().x, t->GetPos().y - moveSpeed });
			//Move my transform

			r->AddVelocity(0, -moveSpeed);
		}
		if (AEInputCheckCurr(AEVK_D))
		{
			//t->SetPos({ t->GetPos().x + moveSpeed, t->GetPos().y });
			//Move my transform

			r->AddVelocity(moveSpeed, 0);
		}
		if (AEInputCheckCurr(AEVK_SPACE))
		{
			//t->SetPos({ t->GetPos().x + 1, t->GetPos().y });
			//Move my transform

			r->AddVelocity(moveSpeed, 0);
		}
		if (AEInputCheckCurr(AEVK_Q))
		{
			//t->SetPos({ t->GetPos().x- moveSpeed, t->GetPos().y + moveSpeed });
				//Move my transform
		}
		if (AEInputCheckCurr(AEVK_E))
		{
			//t->SetPos({ t->GetPos().x + moveSpeed, t->GetPos().y + moveSpeed });
			//Move my transform
		}

		
	}

}

void PlayerComp::LoadFromJson(const json& data)
{
}

BaseRTTI* PlayerComp::CreatePlayerComp()
{
	return nullptr;
}

json PlayerComp::SaveToJson()
{
	return json();
}
