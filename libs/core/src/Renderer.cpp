#include "Renderer.hpp"

#include <stdexcept>

Nutra::Core::Renderer::Renderer(std::shared_ptr<Window> window, int index, Uint32 flags) : m_window(window) {
    m_renderer = window->createRenderer(window->m_window, index, flags);
    if (!m_renderer) {
        throw new std::runtime_error("Failed to create renderer");
    }
}

Nutra::Core::Renderer::~Renderer() {
    SDL_DestroyRenderer(m_renderer);
}

auto Nutra::Core::Renderer::clear() noexcept -> void {
    SDL_RenderClear(m_renderer);
}

auto Nutra::Core::Renderer::setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) noexcept -> void {
    SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
}

auto Nutra::Core::Renderer::present() noexcept -> void {
    SDL_RenderPresent(m_renderer);
}