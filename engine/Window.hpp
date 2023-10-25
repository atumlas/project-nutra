#pragma once

#include <memory>
#include <string_view>
#include <utility>

#include "SDL2/SDL.h"

#include "SDL_Instance.hpp"

namespace Nutra::Core {
    class Window {

        public:
            Window(std::shared_ptr<SDL_Instance> sdl, std::string_view name, int x, int y, int width, int height,
                   Uint32 flags);
            ~Window();
            [[nodiscard]] std::pair<int, int> getWindowSize(Window & window) noexcept;
            void show() const noexcept;
            [[nodiscard]] SDL_Renderer * createRenderer(SDL_Window * window, int index, Uint32 flags) noexcept;

            friend class Renderer;

        private:
            std::shared_ptr<SDL_Instance> m_SDL_Instance;
            SDL_Window * m_Window;
    };
} // namespace Nutra::Core