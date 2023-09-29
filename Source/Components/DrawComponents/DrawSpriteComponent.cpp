//
// Created by Lucas N. Ferreira on 28/09/23.
//

#include "DrawSpriteComponent.h"
#include "../../Actors/Actor.h"
#include "../../Game.h"

DrawSpriteComponent::DrawSpriteComponent(class Actor* owner, const std::string &texturePath, const int width, const int height, const int drawOrder)
        :DrawComponent(owner, drawOrder)
        ,mWidth(width)
        ,mHeight(height)
{
    // --------------
    // TODO - PARTE 1
    // --------------

    // TODO 2.1 (1 linhas): Utilize a função LoadTexture da classe game para criar uma textura a partir da
    //  imagem `texturePath` passado como parâmetro no construtor. Armazene o ponteiro retornada (SDLTexture*)
    //  na variável membro 'mSpriteSheetSurface'.
}

void DrawSpriteComponent::Draw(SDL_Renderer *renderer)
{
    Vector2 pos = mOwner->GetPosition();

    // --------------
    // TODO - PARTE 1
    // --------------

    // TODO 2.2 (~3 linhas): Utilize a função SDL_RenderCopy para desenhar a textura armazenada
    //  na variável membro mSpriteSheetSurface. Você terá que criar dois retângulos do tipo
    //  SDL_Rect e passá-los como parâmetro para a função: (1) `srcrect` para definir a região do
    //  sprite que você desejá desenhar (nesse caso queremos desenhar o sprite inteiro) e
    //  (2) `dstrect` para definir a região da tela onde será desenhado o sprite.
}