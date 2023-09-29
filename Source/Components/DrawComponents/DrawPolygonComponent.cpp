//
// Created by Lucas N. Ferreira on 28/09/23.
//

#include "DrawPolygonComponent.h"
#include "../../Actors/Actor.h"
#include "../../Game.h"

DrawPolygonComponent::DrawPolygonComponent(class Actor* owner, std::vector<Vector2> &vertices, int drawOrder)
        :DrawComponent(owner)
        ,mVertices(vertices)
        ,mDrawOrder(drawOrder)
{
}

void DrawPolygonComponent::Draw(SDL_Renderer *renderer)
{
    Vector2 pos = mOwner->GetPosition();

    // Transform all vertices
    Matrix3 rotationMatrix = Matrix3::CreateRotation(-mOwner->GetRotation());

    std::vector<Vector2> vertices;
    for(auto & vertex : mVertices) {
        Vector2 transformedVertex = Vector2::Transform(vertex,rotationMatrix);
        vertices.emplace_back(transformedVertex);
    }

    // Set draw color to white
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

    // Render vertices as lines
    for(int i = 0; i < vertices.size() - 1; i++) {
        SDL_RenderDrawLine(renderer, pos.x + vertices[i].x, pos.y + vertices[i].y,
                           pos.x + vertices[i+1].x, pos.y + vertices[i+1].y);
    }

    // Close geometry
    SDL_RenderDrawLine(renderer, pos.x + vertices[vertices.size() - 1].x, pos.y + vertices[vertices.size() - 1].y,
                       pos.x + vertices[0].x, pos.y + vertices[0].y);
}