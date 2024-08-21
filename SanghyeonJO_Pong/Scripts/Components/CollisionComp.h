#pragma once
#include "../Components/EngineComponent.h"
#include <string>

#include "AEVec2.h"

class CollisionComp : public EngineComponent
{
	AEVec2 x, y; // 중심 좌표
	AEVec2 halfWidth, halfHeight; // 반 너비, 반 높이
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
		