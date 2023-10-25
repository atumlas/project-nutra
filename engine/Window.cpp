#include "Window.hpp"

#include <stdexcept>

Nutra::Core::Window::Window(std::shared_ptr<SDL_Instance> sdl, std::string_view name, int x, int y, int width,
                            int height, Uint32 flags)
    : m_SDL_Instance(sdl) {
    m_Window = sdl->createWindow(name.data(), x, y, width, height, flags);
    if (!m_Window) {
        throw new std::runtime_error("Failed to create window");
    }
}

Nutra::Core::Window::~Window() {
    SDL_DestroyWindow(m_Window);
}

std::pair<int, int> Nutra::Core::Window::getWindowSize(Nutra::Core::Window & window) noexcept {
    int w, h;
    SDL_GetWindowSize(m_Window, &w, &h);
    return std::make_pair(w, h);
}

void Nutra::Core::Window::show() const noexcept {
    SDL_ShowWindow(m_Window);
}

[[nodiscard]] SDL_Renderer * Nutra::Core::Window::createRenderer(SDL_Window * window, int index,
                                                                 Uint32 flags) noexcept {
    return SDL_CreateRenderer(window, index, flags);
}