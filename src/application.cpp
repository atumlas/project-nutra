#include "Game.hpp"

#include "../libs/core/src/input_manager.hpp"

Nutra::Game::Application::Application(std::shared_ptr<Nutra::Core::SDL_Instance> sdl, char const * name)
    : m_ApplicationName(name), m_SDL_Instance(sdl) {
    initialize();
}

Nutra::Game::Application::Application(std::shared_ptr<Nutra::Core::SDL_Instance> sdl, std::string name)
    : m_ApplicationName(name), m_SDL_Instance(sdl) {
    initialize();
}

void Nutra::Game::Application::initialize() {

    m_Window = std::make_shared<Nutra::Core::Window>(m_SDL_Instance, m_ApplicationName.c_str(), SDL_WINDOWPOS_UNDEFINED,
                                                     SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_HIDDEN);
    m_Renderer =
        std::make_unique<Nutra::Core::Renderer>(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void Nutra::Game::Application::run() noexcept {
    m_Running = true;
    m_Window->show();
    while (m_Running) {
        handleEvents();
        update();
        render();
    }
}

void Nutra::Game::Application::handleEvents() noexcept {
    SDL_Event event;
    while (m_SDL_Instance->pollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            m_Running = false;
            break;
        case SDL_MOUSEMOTION:
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP:
        case SDL_KEYDOWN:
        case SDL_KEYUP:
            Nutra::Core::InputManager::getInstance().updateState(event);
            break;
        default:
            break;
        }
    }
}

void Nutra::Game::Application::render() noexcept {
    m_Renderer->setDrawColor(0, 0, 0, 0);
    m_Renderer->clear();
    m_Renderer->present();
}

void Nutra::Game::Application::update() noexcept {
}
