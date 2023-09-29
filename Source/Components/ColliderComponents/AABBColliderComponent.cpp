//
// Created by Lucas N. Ferreira on 28/09/23.
//

#include "AABBColliderComponent.h"
#include "../../Actors/Actor.h"
#include "../../Game.h"

AABBColliderComponent::AABBColliderComponent(class Actor* owner, int dx, int dy, int w, int h, ColliderLayer layer, int updateOrder)
        :Component(owner, updateOrder)
        ,mOffset(Vector2((float)dx, (float)dy))
        ,mWidth(w)
        ,mHeight(h)
        ,mLayer(layer)
{
    // --------------
    // TODO - PARTE 1
    // --------------

    // TODO 3.1 (1 linha): Adicione (AddCollider) esse componente que está sendo criado (this) à lista
    //  de colliders do jogo.
}

AABBColliderComponent::~AABBColliderComponent()
{
    // --------------
    // TODO - PARTE 1
    // --------------

    // TODO 4.1 (1 linha): Remova (RemoveCollider) esse componente que está sendo criado (this) da lista
    //  de colliders do jogo.
}

Vector2 AABBColliderComponent::GetMin() const {
    // --------------
    // TODO - PARTE 1
    // --------------

    // TODO 5.1 (1 linha): Calcule (e retorne) o ponto mínimo dessa AABB. A variável `mOffset`
    //  define a posição da AABB com relação à posição do objeto dono do componente. Portanto,
    //  basta somar a posição do objeto dono do componente a esse deslocamento.
}

Vector2 AABBColliderComponent::GetMax() const {
    // --------------
    // TODO - PARTE 1
    // --------------

    // TODO 6.1 (1 linha): Calcule (e retorne) o ponto máximo dessa AABB. As variáveis membro
    //  `mWidth` e `mHeight` definem a altura e a largura da AABB, respectivamente. Portanto.
    //   basta somar a largura à coordenada x e a altura à coordenada y do ponto mínimo da AABB.
}

bool AABBColliderComponent::Intersect(const AABBColliderComponent& b) const
{
    // --------------
    // TODO - PARTE 1
    // --------------

    // TODO 7.1 (~5 linhas): Verifique se esta AABB está colidindo com a AABB b passada como parâmetro.
    //  Retorne Verdadeiro se estiver e Falso, caso contrário.
}

CollisionSide AABBColliderComponent::GetDirection(const AABBColliderComponent& b) const
{
    // --------------
    // TODO - PARTE 1
    // --------------

    // TODO 8.1 (~10-15 linhas): Calcule o lado em que essa AABB colidiu com a AABB b passada como parâmetro.
    //  Retorne CollisionSide::Top caso a colisão foi na parte de cima, CollisionSide::Down se foi na parte debaixo,
    //  CollisionSide::left se foi na esquerda, e CollisionSide::right na direita.
}