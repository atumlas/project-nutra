#pragma once

#include <memory>

#include "SDL2/SDL.h"

#include "Window.hpp"

namespace Nutra::Core {
    class Renderer {
        public:
            Renderer(std::shared_ptr<Window> window, int index, Uint32 flags);
            ~Renderer();
            void clear() noexcept;
            void setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) noexcept;
            void present() noexcept;

        private:
            SDL_Renderer * m_Renderer;
            std::shared_ptr<Window> m_Window;
    };
} // namespace Nutra::Core