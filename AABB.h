#pragma once
#include "Vector2.h"
#include "Vector3.h"


struct  AABB
{
    Vector3 min;
    Vector3 max;
};

bool isColliding(const AABB& box1, const AABB& box2) {
    // X軸での重なりをチェック
    if (box1.max.x < box2.min.x || box1.min.x > box2.max.x) {
        return false;
    }

    // Y軸での重なりをチェック
    if (box1.max.y < box2.min.y || box1.min.y > box2.max.y) {
        return false;
    }
    // 両方の軸で重なっていれば衝突している
    return true;
}