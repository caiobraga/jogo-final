//
// Created by Lucas N. Ferreira on 28/09/23.
//

#pragma once
#include "../Component.h"
#include "../../Math.h"
#include <vector>

enum class ColliderLayer
{
    Player,
    Enemy,
    Blocks
};

enum class CollisionSide
{
    Top,
    Down,
    Left,
    Right
};

class AABBColliderComponent : public Component
{
public:
    AABBColliderComponent(class Actor* owner, int dx, int dy, int w, int h, ColliderLayer layer, int updateOrder = 10);
    ~AABBColliderComponent() override;

    bool Intersect(const AABBColliderComponent& b) const;
    float ResolveVertical(const AABBColliderComponent& b) const;
    float ResolveHorizontal(const AABBColliderComponent& b) const;

    // State getter/setter
    ColliderLayer GetLayer() const { return mLayer; }
    void SetLayer(ColliderLayer layer) { mLayer = layer; }

    CollisionSide GetDirection(const AABBColliderComponent& b) const;

    Vector2 GetMin() const;
    Vector2 GetMax() const;

private:
    Vector2 mOffset;
    int mWidth;
    int mHeight;

    ColliderLayer mLayer;
};