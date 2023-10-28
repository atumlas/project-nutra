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
            [[nodiscard]] auto getWindowSize(Window & window) noexcept -> std::pair<int, int>;
            auto show() const noexcept -> void;
            [[nodiscard]] auto createRenderer(SDL_Window * window, int index, Uint32 flags) noexcept -> SDL_Renderer *;

            friend class Renderer;

        private:
            std::shared_ptr<SDL_Instance> m_sdlInstance;
            SDL_Window * m_window;
    };
} // namespace Nutra::Core