//
// Created by Lucas N. Ferreira on 03/08/23.
//

#include "Mario.h"
#include "../Game.h"
#include "../Components/RigidBodyComponent.h"
#include "../Components/DrawComponents/DrawSpriteComponent.h"
#include "../Components/DrawComponents/DrawPolygonComponent.h"
#include "../Components/ColliderComponents/AABBColliderComponent.h"

const float GRAVITY = 400.0f;

Mario::Mario(Game* game,
           const float forwardForce,
           const float frictionCoefficient)
        :Actor(game)
        ,mIsOnGround(false)
        ,mForwardForce(forwardForce)
        ,mFrictionCoefficient(frictionCoefficient)
{
    // --------------
    // TODO - PARTE 1
    // --------------

    // TODO 9.1 (~1 linha): crie um DrawSpriteComponent passando o sprite do mario parado (idle) como
    //  parâmetro. Os sprites do mario em estado pequeno tem tamânho 32x32. Portanto utilize esses valores
    //  como largura e altura.

    // TODO 9.2 (~2 linha): crie um RigidBodyComponent e um AABBColliderComponent. Para o AABBColliderComponent,
    //  considere deslocamentos 0 tanto em x quanto em y e tamanho 32 tanto para largura quanto altura.

    // TODO 9.3 (~6 linhas): crie um DrawPolygonComponent para desenhar a AABB em volta do sprite do mario.
    //  Isso será útil para debugar as colisões. Você terá que calcular os 4 vértices da AABB para criar
    //  esse componente.
}

void Mario::OnProcessInput(const uint8_t* state)
{
    // --------------
    // TODO - PARTE 1
    // --------------

    // TODO 10.1 (~2 linhas): Aplique uma força para a direita caso o jogador tenha pressionado a tecla D.

    // TODO 10.2 (~2 linhas): Aplique uma força para a esquerda caso o jogador tenha pressionado a tecla A.

    // TODO 10.3 (~3 linhas): Altere o componente y da velocidade para um valor negativo grande (e.g -500)
    //  caso o jogador tenha pressionado a tecla Espaço.
}

void Mario::OnUpdate(float deltaTime)
{
    // --------------
    // TODO - PARTE 1
    // --------------

    // TODO 14.1 (~1 linhas): Aplique a força peso considerando a aceleração da gravidade GRAVITY.

    // TODO 14.2 (~4 linhas): Aplique a força de atrito considerando a constante de atrito mFrictionCoefficient.
    //  Se a velocidade for positiva, aplique a força para trás. Se for negativa, para frente.

    // TODO 14.3 (~4 linhas): Aplique a força de atrito considerando a constante de atrito mFrictionCoefficient.
    //  Se a velocidade for positiva, aplique a força para trás. Se for negativa, para frente.

    // TODO 14.4 (~15-20 linhas): Percorra o vetor de AABBs do jogo (mGame->GetColliders()) verificando se o mario
    //  colide com cada bloco (ColliderLayer::Blocks). Se houver colisão, utilize a função
    //  AABBColliderComponent::GetDirection para obter em qual direção ela ocorreu e calcule o deslocamento necessário
    //  para afastar o mário desse bloco. Aplique esse deslocamento na componente (x ou y) correta da posição
    //  do mario e altere para zero a mesmo componente da velocidade.
}
