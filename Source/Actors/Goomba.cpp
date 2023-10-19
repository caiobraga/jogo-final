//
// Created by Lucas N. Ferreira on 30/09/23.
//


#include <iostream>
#include "Goomba.h"
#include "../Game.h"
#include "../Components/DrawComponents/DrawAnimatedComponent.h"
#include "../Components/DrawComponents/DrawPolygonComponent.h"

Goomba::Goomba(Game* game, float forwardSpeed, float deathTime)
        : Actor(game)
        , mDyingTimer(deathTime)
        , mIsDying(false)
        , mForwardSpeed(forwardSpeed)
{
    // --------------
    // TODO - PARTE 5
    // --------------

    // TODO 1.1 (2 linhas): Crie o `RigidBodyComponent` com massa `1.0f` e coeficiente de atrito `0.0`
    //  (basta omitir esse parâmetro para inicializa-lo com zero). Altere a velocidade horizontal do
    //  goomba para `mForwardSpeed`
    mRigidBodyComponent = new RigidBodyComponent(this, 1.0f, 0.0f);
    this->mRigidBodyComponent->SetVelocity(Vector2(mForwardSpeed, 0));

    // TODO 1.2 (1 linha): Crie o `AABBColliderComponent` com dimensões `(0,0,32,32)` e tipo de colisão
    //  `ColliderLayer::Enemy`.
    mColliderComponent = new AABBColliderComponent(this, 0, 0, 32, 32, ColliderLayer::Enemy);

    // TODO 1.3 (1 linha): Crie o componente `DrawAnimatedComponent` passando os caminhos da imagem (.png) e
    //  dos dados (.json) do sprite sheet do goomba que você criou com o TexturePacker.
    mDrawComponent = new DrawAnimatedComponent(this, "D:\\Henrique\\UFV\\Inf 216\\mario\\mario\\Assets\\Sprites\\Goomba\\Goomba.png", "D:\\Henrique\\UFV\\Inf 216\\mario\\mario\\Assets\\Sprites\\Goomba\\Goomba.json");
    //  - 1.3.1 (2 linha): Utilize a função `AddAnimation` para adicionar as animações "walk" e "dead".
    mDrawComponent->AddAnimation("walk", { 1,2 });
    mDrawComponent->AddAnimation("dead", { 0 });
    //  - 1.3.2 (2 linhas): Utilize a função `SetAnimation` para definir a animação inicial como "walk".
    //    Em seguida, utilize a função `SetAnimFPS` para definir a taxa de atualização de quadros da animação
    //    para 5.0f.
    mDrawComponent->SetAnimation("walk");
    mDrawComponent->SetAnimFPS(5.0f);
}

void Goomba::Kill()
{
    // --------------
    // TODO - PARTE 5
    // --------------

    // TODO 2.1 (~4 linhas): altere a animação para "dead" e o valor da variável mIsDying para verdadeiro.
    //  Além disso, desabilite `SetEnabled(false)` os componentes `mRigidBodyComponent` e  `mColliderComponent`
    mDrawComponent->SetAnimation("dead");
    mIsDying = true;
    mRigidBodyComponent->SetEnabled(false);
    mColliderComponent->SetEnabled(false);
}

void Goomba::OnUpdate(float deltaTime)
{
    // --------------
    // TODO - PARTE 5
    // --------------

    // TODO 3.1 (~4 linhas): Verifique se a variável `mDyingTimer` é verdadeira. Se for, decremente o cronômetro
    //  `mDyingTimer` pelo delta time. Quando esse cronômetro chegar a zero, altere o estado do goomba para `ActorState::Destroy`
    if (mIsDying) {
        mDyingTimer -= deltaTime;
        if (mDyingTimer <= 0.0) {
            mState = ActorState::Destroy;
        }
    }

    // TODO 3.2 (~2 linhas): Verifique se a posição vertical do goomba é maior do que o tamanho da tela. Se for,
    //  altere o estado do goomba para `ActorState::Destroy`
    if (this->GetPosition().y > GetGame()->GetWindowHeight()) mState = ActorState::Destroy;
}

void Goomba::OnCollision(std::unordered_map<CollisionSide, AABBColliderComponent::Overlap>& responses)
{
    // --------------
    // TODO - PARTE 5
    // --------------

    // TODO 4.1 (~4 linhas): Percorra o mapa `responses` atualizando o estado do jogador bom base no
    //  tipo de colisão ocorrida. Se a colisão foi à esquerda, altere a velocidade horizontal para
    //  mForwardSpeed. Se foi à direita, altera a velocidade horizontal para -mForwardSpeed.
    for (auto& entry : responses) {
        AABBColliderComponent::Overlap overlap = entry.second;
        CollisionSide side = entry.first;
        AABBColliderComponent* target = overlap.target;



        if (side == CollisionSide::Right)
            this->GetComponent<RigidBodyComponent>()->SetVelocity(Vector2(-mForwardSpeed, this->GetComponent<RigidBodyComponent>()->GetVelocity().y));

     
        if (side == CollisionSide::Left) 
            this->GetComponent<RigidBodyComponent>()->SetVelocity(Vector2(mForwardSpeed, this->GetComponent<RigidBodyComponent>()->GetVelocity().y));
    
        

    }
}