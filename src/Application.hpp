#pragma once

#include "SDL2/SDL.h"

#include <iostream>
#include <string>

#include "Renderer.hpp"
#include "Window.hpp"

namespace Nutra::Core {
    class Application {
        public:
            explicit Application(char const * name);
            explicit Application(std::string name);
            virtual ~Application() = default;

            void initialize();
            void run();

        private:
            std::string m_ApplicationName;

            std::shared_ptr<Window> m_Window     = 0;
            std::unique_ptr<Renderer> m_Renderer = 0;

            bool m_Running;

            void handleEvents();
            void update();
            void render();
    };
} // namespace Nutra::Core