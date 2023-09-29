//
// Created by Lucas N. Ferreira on 08/09/23.
//

#include <SDL.h>
#include "RigidBodyComponent.h"
#include "../Actors/Actor.h"
#include "../Game.h"

const int MAX_SPEED = 250.0f;

RigidBodyComponent::RigidBodyComponent(class Actor* owner, float mass, int updateOrder)
        :Component(owner, updateOrder)
        ,mMass(mass)
        ,mAngularSpeed(0.0f)
        ,mVelocity(Vector2::Zero)
        ,mAcceleration(Vector2::Zero)
{

}

void RigidBodyComponent::ApplyForce(const Vector2 &force) {
    mAcceleration += force * (1.f/mMass);
}

void RigidBodyComponent::Update(float deltaTime)
{
    Vector2 position = mOwner->GetPosition();

    mVelocity += mAcceleration * deltaTime;

    if(Math::NearZero(mVelocity.x, 1.0f)) {
        mVelocity.Set(0.f, mVelocity.y);
    }

    if(mVelocity.x > MAX_SPEED)
    {
        mVelocity.x = MAX_SPEED;
    }
    else if(mVelocity.x < -MAX_SPEED)
    {
        mVelocity.x = -MAX_SPEED;
    }

//    if(mVelocity.y > MAX_SPEED)
//    {
//        mVelocity.y = MAX_SPEED;
//    }
//    else if(mVelocity.y < -MAX_SPEED)
//    {
//        mVelocity.y = -MAX_SPEED;
//    }

    position += mVelocity * deltaTime;
    mOwner->SetPosition(position);

    mAcceleration.Set(0.f, 0.f);
}

