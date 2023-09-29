//
// Created by Lucas N. Ferreira on 28/09/23.
//

#include "DrawSpriteSheetComponent.h"
#include "../../Actors/Actor.h"
#include "../../Game.h"
#include "../../Json.h"
#include <fstream>

DrawSpriteSheetComponent::DrawSpriteSheetComponent(class Actor* owner, const std::string &spriteSheetPath, const std::string &spriteSheetData, int drawOrder)
        :DrawSpriteComponent(owner, spriteSheetPath, 0, 0, drawOrder)
        ,mCurrentSprite(0)
{
    // --------------
    // TODO - PARTE 3
    // --------------
}

DrawSpriteSheetComponent::~DrawSpriteSheetComponent()
{
    // --------------
    // TODO - PARTE 3
    // --------------
}

void DrawSpriteSheetComponent::LoadSpriteSheet(const std::string& texturePath, const std::string& dataPath)
{
    // --------------
    // TODO - PARTE 3
    // --------------
}

void DrawSpriteSheetComponent::Draw(SDL_Renderer *renderer)
{
    // --------------
    // TODO - PARTE 3
    // --------------
}