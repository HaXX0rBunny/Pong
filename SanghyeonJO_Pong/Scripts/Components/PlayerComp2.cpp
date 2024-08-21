#include "PlayerComp2.h"
#include "AEEngine.h"
#include "AEInput.h"
#include "TransformComp.h"
#include "RigidbodyComp.h"
#include "../GameObject/GameObject.h"
PlayerComp2::PlayerComp2(GameObject* owner) {
	moveSpeed = 10;
	spin = 1;
	worldLimit = 375;
}

PlayerComp2::~PlayerComp2()
{
}


void PlayerComp2::Update()
{

	//if (BaseComponent::Update() == false)
	//	return;
	//Check for input

	TransformComp* t = own->GetComponent<TransformComp>();
	if (!t)
		return;
	RigidbodyComp* r = own->GetComponent<RigidbodyComp>();
	if (!r)
		return;
	if (t)
	{

		s32 mouseX, mouseY;
		AEInputGetCursorPosition(&mouseX, &mouseY);

		// ȭ���� ���̸� �������� ���콺 Y ��ǥ�� ��ȯ�մϴ�.
		f32 screenHeight = (f32)900/2;
		f32 normalizedMouseY = screenHeight - mouseY;
		if (t->GetPos().y<worldLimit && t->GetPos().y >-worldLimit)
		{
			t->SetPos({ t->GetPos().x, normalizedMouseY });
			if (t->GetPos().y >= worldLimit)
				t->SetPos(AEVec2{ t->GetPos().x, worldLimit - 1 });
			else if (t->GetPos().y <= -worldLimit)
				t->SetPos(AEVec2{ t->GetPos().x, -worldLimit + 1 });
		}
	}

}

void PlayerComp2::LoadFromJson(const json& data)
{
}

BaseRTTI* PlayerComp2::CreatePlayerComp()
{
	return nullptr;
}

json PlayerComp2::SaveToJson()
{
	return json();
}
