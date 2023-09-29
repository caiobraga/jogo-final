//
// Created by Lucas N. Ferreira on 28/09/23.
//

#pragma once

#include "DrawSpriteComponent.h"

class DrawSpriteSheetComponent : public DrawSpriteComponent {
public:
    // (Lower draw order corresponds with further back)
    DrawSpriteSheetComponent(class Actor* owner, const std::string &spriteSheetPath, const std::string &spriteSheetData,  int drawOrder = 100);
    ~DrawSpriteSheetComponent() override;

    void Draw(SDL_Renderer* renderer) override;

    void SetCurrentSprite(const int spriteNumber) { mCurrentSprite = spriteNumber; };

private:
    void LoadSpriteSheet(const std::string& texturePath, const std::string& dataPath);

    std::vector<SDL_Rect*> mSpriteSheetData;

    int mCurrentSprite;
};
