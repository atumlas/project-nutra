#include "Window.hpp"

#include <stdexcept>

Nutra::Core::Window::Window(std::shared_ptr<SDL_Instance> sdl, std::string_view name, int x, int y, int width,
                            int height, Uint32 flags)
    : m_sdlInstance(sdl) {
    m_window = sdl->createWindow(name.data(), x, y, width, height, flags);
    if (!m_window) {
        throw new std::runtime_error("Failed to create window");
    }
}

Nutra::Core::Window::~Window() {
    SDL_DestroyWindow(m_window);
}

auto Nutra::Core::Window::getWindowSize(Nutra::Core::Window & window) noexcept -> std::pair<int, int> {
    int w, h;
    SDL_GetWindowSize(m_window, &w, &h);
    return std::make_pair(w, h);
}

auto Nutra::Core::Window::show() const noexcept -> void {
    SDL_ShowWindow(m_window);
}

[[nodiscard]] auto Nutra::Core::Window::createRenderer(SDL_Window * window, int index, Uint32 flags) noexcept
    -> SDL_Renderer * {
    return SDL_CreateRenderer(window, index, flags);
}