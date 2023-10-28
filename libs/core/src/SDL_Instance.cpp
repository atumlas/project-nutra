#include "SDL_Instance.hpp"

#include <format>
#include <stdexcept>
#include <string>

Nutra::Core::SDL_Instance::SDL_Instance() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        throw new std::runtime_error(std::format("SDL could not initialize! SDL_Error: {}", SDL_GetError()));
    }
}

Nutra::Core::SDL_Instance::~SDL_Instance() {
    SDL_Quit();
}

[[nodiscard]] auto Nutra::Core::SDL_Instance::pollEvent(SDL_Event * event) noexcept -> int {
    return SDL_PollEvent(event);
}

[[nodiscard]] auto Nutra::Core::SDL_Instance::createWindow(char const * name, int x, int y, int width, int height,
                                                           Uint32 flags) noexcept -> SDL_Window * {
    return SDL_CreateWindow(name, x, y, width, height, flags);
}