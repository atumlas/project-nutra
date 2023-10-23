#pragma once

#include "SDL2/SDL.h"

#include <iostream>
#include <string>
#include <string_view>

#include "Renderer.hpp"
#include "Window.hpp"

namespace Nutra::Core {
    class Application {
        public:
            explicit Application(char const * name);
            explicit Application(std::string name);
            virtual ~Application() = default;

            void run() noexcept;

        private:
            std::string m_ApplicationName;

            std::shared_ptr<Window> m_Window;
            std::unique_ptr<Renderer> m_Renderer;

            bool m_Running;

            void initialize();
            void handleEvents() noexcept;
            void update() noexcept;
            void render() noexcept;
    };
} // namespace Nutra::Core