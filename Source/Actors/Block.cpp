//
// Created by Lucas N. Ferreira on 03/08/23.
//

#include "Block.h"
#include "../Game.h"
#include "../Components/DrawComponents/DrawSpriteComponent.h"
#include "../Components/DrawComponents/DrawPolygonComponent.h"
#include "../Components/ColliderComponents/AABBColliderComponent.h"

Block::Block(Game* game, const std::string &texturePath)
        :Actor(game)
        ,mSpriteComponent(nullptr)
{
    // --------------
    // TODO - PARTE 1
    // --------------

    // TODO 11.1 (1 linha): crie um DrawSpriteComponent para a imagem `texturePath`
    //  Os sprites de blocos têm tamânho 32x32. Portanto utilize esses valores como largura e altura.

    // TODO 11.2 (1 linha): crie um um AABBColliderComponent com deslocamentos 0 tanto em x quanto
    //  em y e tamanho 32 tanto para largura quanto altura.

    // TODO 11.3 (~6 linhas): crie um DrawPolygonComponent para desenhar a AABB em volta do sprite do bloco.
    //  Isso será útil para debugar as colisões. Você terá que calcular os 4 vértices da AABB para criar
    //  esse componente.
}
