#pragma once
#include "EngineComponent.h"

struct AABB {
    float x, y; // 중심 좌표
    float halfWidth, halfHeight; // 반 너비, 반 높이
};

struct Circle {
    float x, y; // 중심 좌표
    float radius; // 반지름
};

class CollisionComp : public EngineComponent{
public:
    CollisionComp();

    void SetAABB(float x, float y, float halfWidth, float halfHeight);
    void SetCircle(float x, float y, float radius);

    bool CheckCollision(const CollisionComp& other) const;
    void ResolveCollision(CollisionComp& other);

private:
    enum CollisionType {
        None,
        AABBType,
        CircleType
    };

    CollisionType type;
    AABB aabb;
    Circle circle;

    bool CheckCollisionAABB(const AABB& box1, const AABB& box2) const;
    void ResolveCollisionAABB(AABB& box1, AABB& box2) const;

    bool CheckCollisionCircle(const Circle& circle1, const Circle& circle2) const;
    void ResolveCollisionCircle(Circle& circle1, Circle& circle2) const;
};
