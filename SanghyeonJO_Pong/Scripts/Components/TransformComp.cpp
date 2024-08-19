#include "TransformComp.h"
#include <iostream>
#include "../GameObject/GOManager.h"
void TransformComp::CalculateMatrix() {
	//Create a transform matrix
	AEMtx33 translateMtx;
	AEMtx33Trans(&translateMtx, pos.x, pos.y);

	AEMtx33 rotaitionMtx;
	AEMtx33Rot(&rotaitionMtx, rot);

	AEMtx33 scaleMtx;
	AEMtx33Scale(&scaleMtx, scale.x, scale.y);

	//Concatenate thme
	AEMtx33Concat(&trancsformMatrix, &rotaitionMtx, &scaleMtx);
	AEMtx33Concat(&trancsformMatrix, &translateMtx, &trancsformMatrix);
}
TransformComp::TransformComp()
{
	pos.x = 0;
	pos.y = 0;
	scale.x = 1;
	scale.y = 1;
	rot = 0; // 기본 회전 값 추가
	CalculateMatrix();
}
TransformComp::TransformComp(GameObject* owner)
{
	pos.x = 0;
	pos.y = 0;

	scale.x = 1;
	scale.y = 1;

	CalculateMatrix();
}


TransformComp::~TransformComp()
{
}

void TransformComp::Update() {

	CalculateMatrix();
}
const AEMtx33& TransformComp::GetMatrix() const
{
	return trancsformMatrix;
}
void TransformComp::SetPos(const AEVec2& otherPos)
{
	this->pos = otherPos;
	CalculateMatrix();
}
void TransformComp::SetScale(const AEVec2& otherScale)
{
	this->scale = otherScale;
	CalculateMatrix();
}
void TransformComp::SetRot(const float& otherRot)
{
	this->rot = otherRot;
	CalculateMatrix();
}

void TransformComp::PrintMatrix()
{
	std::cout << "Printing Transform Comp. With this values: " << std::endl;
	std::cout << "Translate : " << pos.x << " " << pos.y;
	std::cout << "Rotation  : " << rot;
	std::cout << "Scale     : " << scale.x << " " << scale.y;
	for(int i=0; i<3; i++)
	{
		std::cout << " | ";
		for (int x = 0; x < 3; x++){
			std::cout << " " << trancsformMatrix.m[i][x];
		}
		std::cout << " |";
		std::cout << std::endl;
	}
}

void TransformComp::LoadFromJson(const json& data)
{
	//Check how you saved, load form there
	auto compData = data.find("compData");

	if (compData != data.end())
	{
		auto p = compData->find("Pos");
		pos.x = p->begin().value();
		pos.y = (p->begin() + 1).value();
		//scale
		auto s = compData->find("Sca");
		scale.x = p->begin().value();
		scale.y = (p->begin() + 1).value();
		
		//Rot
		auto r= compData->find("Rot");
		rot = r.value();
	}
	//Data is loaded
	//Utilize the data;
	CalculateMatrix();
}
json TransformComp::SaveToJson()
{
	json data;
	//save the type
	data["Type"] = GetType();
	//Save my data
	json compData;
		//pos
		compData["Pos"] = {pos.x, pos.y};
		//sacle
		compData["Sca"] = { scale.x, scale.y };
		//rot
		compData["Rot"] = rot;
	data["CompData"] = compData;
	return data;
}
BaseRTTI* TransformComp::CreateTransformComp()
{

		//Set value need it
	BaseRTTI* out = new TransformComp(GOManager::Instance()->GetLastObj());
	return out;
}
