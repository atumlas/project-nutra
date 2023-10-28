#pragma once

#include "SDL2/SDL.h"

namespace Nutra::Core {
    class SDL_Instance {
        public:
            SDL_Instance();

            ~SDL_Instance();

            [[nodiscard]] auto pollEvent(SDL_Event * event) noexcept -> int;
            [[nodiscard]] auto createWindow(char const * name, int x, int y, int width, int height,
                                            Uint32 flags) noexcept -> SDL_Window *;
    };
} // namespace Nutra::Core