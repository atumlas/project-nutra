#pragma once

#include "SDL2/SDL.h"

#include <iostream>
#include <string>
#include <string_view>

#include "../libs/core/src/renderer.hpp"
#include "../libs/core/src/scene.hpp"
#include "../libs/core/src/sdl_instance.hpp"
#include "../libs/core/src/window.hpp"

namespace Nutra::Game {
    class Application {
        public:
            explicit Application(std::shared_ptr<Nutra::Core::SDL_Instance> sdl, char const * name, Nutra::Core::Scene * initialScene);
            explicit Application(std::shared_ptr<Nutra::Core::SDL_Instance> sdl, std::string name, Nutra::Core::Scene * initialScene);
            ~Application() = default;

            auto run() noexcept -> void;

        private:
            std::string m_ApplicationName;

            std::shared_ptr<Nutra::Core::SDL_Instance> m_SdlInstance;
            std::shared_ptr<Nutra::Core::Window> m_Window;
            std::unique_ptr<Nutra::Core::Renderer> m_Renderer;

            Nutra::Core::Scene * m_InitialScene;

            bool m_Running;

            auto initialize() -> void;
            auto handleEvents() noexcept -> void;
            auto update() noexcept -> void;
            auto render() noexcept -> void;
    };
} // namespace Nutra::Game