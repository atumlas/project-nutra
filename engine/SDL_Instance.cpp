#include "SDL_Instance.hpp"

#include <stdexcept>
#include <string>

Nutra::Core::SDL_Instance::SDL_Instance() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        throw new std::runtime_error("SDL could not initialize! SDL_Error: " + std::string(SDL_GetError()));
    }
}

Nutra::Core::SDL_Instance::~SDL_Instance() {
    SDL_Quit();
}

[[nodiscard]] int Nutra::Core::SDL_Instance::pollEvent(SDL_Event * event) noexcept {
    return SDL_PollEvent(event);
}

[[nodiscard]] SDL_Window * Nutra::Core::SDL_Instance::createWindow(char const * name, int x, int y, int width,
                                                                   int height, Uint32 flags) noexcept {
    return SDL_CreateWindow(name, x, y, width, height, flags);
}