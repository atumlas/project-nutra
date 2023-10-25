#pragma once

#include "SDL2/SDL.h"

namespace Nutra::Core {
    class SDL_Instance {
        public:
            SDL_Instance();

            ~SDL_Instance();

            [[nodiscard]] int pollEvent(SDL_Event * event) noexcept;
            [[nodiscard]] SDL_Window * createWindow(char const * name, int x, int y, int width, int height,
                                                    Uint32 flags) noexcept;
    };
} // namespace Nutra::Core