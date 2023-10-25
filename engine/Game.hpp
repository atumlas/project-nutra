#pragma once

#include "SDL2/SDL.h"

#include <iostream>
#include <string>
#include <string_view>

#include "Renderer.hpp"
#include "SDL_Instance.hpp"
#include "Window.hpp"

namespace Nutra::Core {
    class Game {
        public:
            explicit Game(std::shared_ptr<SDL_Instance> sdl, char const * name);
            explicit Game(std::shared_ptr<SDL_Instance> sdl, std::string name);
            ~Game() = default;

            void run() noexcept;

        private:
            std::string m_ApplicationName;

            std::shared_ptr<SDL_Instance> m_SDL_Instance;
            std::shared_ptr<Window> m_Window;
            std::unique_ptr<Renderer> m_Renderer;

            bool m_Running;

            void initialize();
            void handleEvents() noexcept;
            void update() noexcept;
            void render() noexcept;
    };
} // namespace Nutra::Core