#include "Window.hpp"

Nutra::Core::Window::Window(std::string_view name, int x, int y, int width, int height, Uint32 flags) {
    m_Window = SDL_CreateWindow(name.data(), x, y, width, height, flags);
    if (!m_Window) {
        exit(1);
    }
}

Nutra::Core::Window::~Window() {
    SDL_DestroyWindow(m_Window);
}

std::pair<int, int> Nutra::Core::Window::getWindowSize(Nutra::Core::Window & window) {
    int w, h;
    SDL_GetWindowSize(m_Window, &w, &h);
    return std::make_pair(w, h);
}

void Nutra::Core::Window::show() const {
    SDL_ShowWindow(m_Window);
}