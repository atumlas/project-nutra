#pragma once

#include <memory>

#include "SDL2/SDL.h"

#include "Window.hpp"

namespace Nutra::Core {
    class Renderer {
        public:
            Renderer(std::shared_ptr<Window> window, int index, Uint32 flags);
            ~Renderer();
            auto clear() noexcept -> void;
            auto setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) noexcept -> void;
            auto present() noexcept -> void;

        private:
            SDL_Renderer * m_renderer;
            std::shared_ptr<Window> m_window;
    };
} // namespace Nutra::Core