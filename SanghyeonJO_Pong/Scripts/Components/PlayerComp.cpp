#include "PlayerComp.h"
#include "AEEngine.h"
#include "AEInput.h"
#include "TransformComp.h"
#include "RigidbodyComp.h"
#include "../GameObject/GameObject.h"
PlayerComp::PlayerComp(GameObject* owner) {
	moveSpeed = 10;
	spin = 1;
	worldLimit = 375;
}

PlayerComp::~PlayerComp()
{
}

void PlayerComp::Update()
{

	TransformComp* t = own->GetComponent<TransformComp>();
	if (!t)
		return;
	RigidbodyComp* r = own->GetComponent<RigidbodyComp>();
	if (!r)
		return;
	if (t)
	{
		if (t->GetPos().y<worldLimit && t->GetPos().y >-worldLimit)
		{
			if (AEInputCheckCurr(AEVK_W))
			{
				t->SetPos({ t->GetPos().x, t->GetPos().y + moveSpeed });

			}

			if (AEInputCheckCurr(AEVK_S))
			{
				t->SetPos({ t->GetPos().x, t->GetPos().y - moveSpeed });

			}
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
