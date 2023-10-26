#pragma once

#include "SDL2/SDL.h"

#include <iostream>
#include <string>
#include <string_view>

#include "../libs/core/src/Renderer.hpp"
#include "../libs/core/src/SDL_Instance.hpp"
#include "../libs/core/src/Window.hpp"

namespace Nutra::Game {
    class Application {
        public:
            explicit Application(std::shared_ptr<Nutra::Core::SDL_Instance> sdl, char const * name);
            explicit Application(std::shared_ptr<Nutra::Core::SDL_Instance> sdl, std::string name);
            ~Application() = default;

            void run() noexcept;

        private:
            std::string m_ApplicationName;

            std::shared_ptr<Nutra::Core::SDL_Instance> m_SDL_Instance;
            std::shared_ptr<Nutra::Core::Window> m_Window;
            std::unique_ptr<Nutra::Core::Renderer> m_Renderer;

            bool m_Running;

            void initialize();
            void handleEvents() noexcept;
            void update() noexcept;
            void render() noexcept;
    };
} // namespace Nutra::Game