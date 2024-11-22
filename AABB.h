#pragma once
#include "Vector2.h"
#include "Vector3.h"

struct AABB
{
    Vector3 min;
    Vector3 max;

    // AABB内に点が含まれているかの判定
    bool contains(const Vector3& point) const {
        return (point.x >= min.x && point.x <= max.x) &&
            (point.y >= min.y && point.y <= max.y) &&
            (point.z >= min.z && point.z <= max.z);
    }

    // AABBが別のAABBに完全に含まれているかの判定
    bool contains(const AABB& other) const {
        return (other.min.x >= min.x && other.max.x <= max.x) &&
            (other.min.y >= min.y && other.max.y <= max.y) &&
            (other.min.z >= min.z && other.max.z <= max.z);
    }

    // AABBの中心を取得
    Vector3 getCenter() const {
        return Vector3((min.x + max.x) / 2.0f,
            (min.y + max.y) / 2.0f,
            (min.z + max.z) / 2.0f);
    }

    // AABBのサイズを取得
    Vector3 getSize() const {
        return Vector3(max.x - min.x, max.y - min.y, max.z - min.z);
    }

    // AABBが他のAABBと衝突しているかの判定
    bool isColliding(const AABB& other) const {
        // X軸での重なりをチェック
        if (max.x < other.min.x || min.x > other.max.x) {
            return false;
        }

        // Y軸での重なりをチェック
        if (max.y < other.min.y || min.y > other.max.y) {
            return false;
        }

        // Z軸での重なりをチェック
        if (max.z < other.min.z || min.z > other.max.z) {
            return false;
        }

        // すべての軸で重なっていれば衝突している
        return true;
    }
};
