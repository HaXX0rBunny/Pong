#pragma once
#include "../Components/EngineComponent.h"
#include <string>

#include "AEVec2.h"

class CollisionComp : public EngineComponent
{
	AEVec2 x, y; // �߽� ��ǥ
	AEVec2 halfWidth, halfHeight; // �� �ʺ�, �� ����
	CollisionComp();
	~CollisionComp();
	void SetAABB(float x, float y, float halfWidth, float halfHeight);
	void SetCircle(float x, float y, float radius);

	bool CheckCollision(const CollisionComp& other) const;
	void ResolveCollision(CollisionComp& other);

	std::string GetType() {
		return "CollisionComp";
	}
	int CollisionInterSection();
	virtual void LoadFromJson(const json& data) = 0;
};
		