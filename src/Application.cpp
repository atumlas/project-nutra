#include "Application.hpp"

Nutra::Core::Application::Application(char const * name) : m_ApplicationName(name) {
    initialize();
}

Nutra::Core::Application::Application(std::string name) : m_ApplicationName(name) {
    initialize();
}

void Nutra::Core::Application::initialize() {

    m_Window   = std::make_shared<Window>(m_ApplicationName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                        640, 480, SDL_WINDOW_HIDDEN);
    m_Renderer = std::make_unique<Renderer>(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    m_Running  = true;
}

void Nutra::Core::Application::run() {
    m_Window->show();
    while (m_Running) {
        handleEvents();
        update();
        render();
    }
}

void Nutra::Core::Application::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            m_Running = false;
            break;
        default:
            break;
        }
    }
}

void Nutra::Core::Application::render() {
    m_Renderer->setDrawColor(0, 0, 0, 0);
    m_Renderer->clear();
    m_Renderer->present();
}

void Nutra::Core::Application::update() {
}
