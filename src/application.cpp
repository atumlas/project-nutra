#include "application.hpp"

#include "../libs/core/src/input_manager.hpp"

Nutra::Game::Application::Application(std::shared_ptr<Nutra::Core::SDL_Instance> sdl, char const * name)
    : m_ApplicationName(name), m_sdlInstance(sdl) {
    initialize();
}

Nutra::Game::Application::Application(std::shared_ptr<Nutra::Core::SDL_Instance> sdl, std::string name)
    : m_ApplicationName(name), m_sdlInstance(sdl) {
    initialize();
}

auto Nutra::Game::Application::initialize() -> void {

    m_window = std::make_shared<Nutra::Core::Window>(m_sdlInstance, m_ApplicationName.c_str(), SDL_WINDOWPOS_UNDEFINED,
                                                     SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_HIDDEN);
    m_renderer =
        std::make_unique<Nutra::Core::Renderer>(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

auto Nutra::Game::Application::run() noexcept -> void {
    m_Running = true;
    m_window->show();
    while (m_Running) {
        handleEvents();
        update();
        render();
    }
}

auto Nutra::Game::Application::handleEvents() noexcept -> void {
    Nutra::Core::InputManager::getInstance().beginNewFrame();
    SDL_Event event;
    while (m_sdlInstance->pollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            m_Running = false;
            break;
        case SDL_MOUSEMOTION:
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP:
        case SDL_KEYDOWN:
        case SDL_KEYUP:
            Nutra::Core::InputManager::getInstance().handleEvent(event);
            break;
        default:
            break;
        }
    }
}

auto Nutra::Game::Application::render() noexcept -> void {
    m_renderer->setDrawColor(0, 0, 0, 0);
    m_renderer->clear();
    m_renderer->present();
}

auto Nutra::Game::Application::update() noexcept -> void {
}
