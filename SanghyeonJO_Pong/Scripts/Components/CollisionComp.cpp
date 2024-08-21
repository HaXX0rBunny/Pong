#include "CollisionComp.h"
#include <cmath>

// 생성자
CollisionComp::CollisionComp() : type(None) {}

// AABB 초기화
void CollisionComp::SetAABB(float x, float y, float halfWidth, float halfHeight) {
    type = AABBType;
    aabb = { x, y, halfWidth, halfHeight };
}

// Circle 초기화
void CollisionComp::SetCircle(float x, float y, float radius) {
    type = CircleType;
    circle = { x, y, radius };
}

// AABB 충돌 감지
bool CollisionComp::CheckCollision(const CollisionComp& other) const {
    if (type == AABBType && other.type == AABBType) {
        return CheckCollisionAABB(aabb, other.aabb);
    }
    else if (type == CircleType && other.type == CircleType) {
        return CheckCollisionCircle(circle, other.circle);
    }
    // 다른 충돌 유형은 필요에 따라 추가
    return false;
}

// 충돌 해결
void CollisionComp::ResolveCollision(CollisionComp& other) {
    if (type == AABBType && other.type == AABBType) {
        ResolveCollisionAABB(aabb, other.aabb);
    }
    else if (type == CircleType && other.type == CircleType) {
        ResolveCollisionCircle(circle, other.circle);
    }
    // 다른 충돌 유형은 필요에 따라 추가
}

// AABB 충돌 감지 구현
bool CollisionComp::CheckCollisionAABB(const AABB& box1, const AABB& box2) const {
    return (std::abs(box1.x - box2.x) <= (box1.halfWidth + box2.halfWidth)) &&
        (std::abs(box1.y - box2.y) <= (box1.halfHeight + box2.halfHeight));
}

// AABB 충돌 해결 구현
void CollisionComp::ResolveCollisionAABB(AABB& box1, AABB& box2) const {
    float xOverlap = (box1.halfWidth + box2.halfWidth) - std::abs(box1.x - box2.x);
    float yOverlap = (box1.halfHeight + box2.halfHeight) - std::abs(box1.y - box2.y);

    if (xOverlap < yOverlap) {
        if (box1.x < box2.x)
            box1.x -= xOverlap;
        else
            box1.x += xOverlap;
    }
    else {
        if (box1.y < box2.y)
            box1.y -= yOverlap;
        else
            box1.y += yOverlap;
    }
}

// Circle 충돌 감지 구현
bool CollisionComp::CheckCollisionCircle(const Circle& circle1, const Circle& circle2) const {
    float dx = circle1.x - circle2.x;
    float dy = circle1.y - circle2.y;
    float distanceSquared = dx * dx + dy * dy;
    float radiusSum = circle1.radius + circle2.radius;
    return distanceSquared <= radiusSum * radiusSum;
}

// Circle 충돌 해결 구현
void CollisionComp::ResolveCollisionCircle(Circle& circle1, Circle& circle2) const {
    float dx = circle2.x - circle1.x;
    float dy = circle2.y - circle1.y;
    float distance = std::sqrt(dx * dx + dy * dy);
    float overlap = (circle1.radius + circle2.radius) - distance;

    float offsetX = overlap * (dx / distance) / 2;
    float offsetY = overlap * (dy / distance) / 2;

    circle1.x -= offsetX;
    circle1.y -= offsetY;
    circle2.x += offsetX;
    circle2.y += offsetY;
}
