#pragma once

#include <memory>
#include <string_view>
#include <utility>

#include "SDL2/SDL.h"

namespace Nutra::Core {
    class Window {

        public:
            Window(std::string_view name, int x, int y, int width, int height, Uint32 flags);
            ~Window();
            std::pair<int, int> getWindowSize(Window & window);
            void show() const;

            friend class Renderer;

        private:
            SDL_Window * m_Window;
    };
} // namespace Nutra::Core