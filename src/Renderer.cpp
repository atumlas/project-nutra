#include "Renderer.hpp"

#include <stdexcept>

Nutra::Core::Renderer::Renderer(std::shared_ptr<Window> window, int index, Uint32 flags) : m_Window(window) {
    m_Renderer = SDL_CreateRenderer(window->m_Window, index, flags);
    if (!m_Renderer) {
        throw new std::runtime_error("Failed to create renderer");
    }
}

Nutra::Core::Renderer::~Renderer() {
    SDL_DestroyRenderer(m_Renderer);
}

void Nutra::Core::Renderer::clear() noexcept {
    SDL_RenderClear(m_Renderer);
}

void Nutra::Core::Renderer::setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) noexcept {
    SDL_SetRenderDrawColor(m_Renderer, r, g, b, a);
}

void Nutra::Core::Renderer::present() noexcept {
    SDL_RenderPresent(m_Renderer);
}