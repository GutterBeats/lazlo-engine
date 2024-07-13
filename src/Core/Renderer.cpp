//
// Created by Anthony Lesch on 7/12/24.
//

#include "Renderer.h"

Renderer::Renderer(SDL_Window* window)
{
    m_Renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (m_Renderer == nullptr)
    {
        SDL_Log("Unable to create a renderer!: %s", SDL_GetError());
        exit(1);
    }
}

SDL_Renderer* Renderer::GetRenderer() const
{
    return m_Renderer;
}

void Renderer::RenderEntity(const Entity& entity) const
{
    entity.Draw(m_Renderer);
}

void Renderer::StartFrame() const
{
    SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);
    SDL_RenderClear(m_Renderer);
}

void Renderer::EndFrame() const
{
    SDL_RenderPresent(m_Renderer);
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(m_Renderer);
}
