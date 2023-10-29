#include "application.hpp"

#include "../libs/core/src/input_manager.hpp"

Nutra::Game::Application::Application(std::shared_ptr<Nutra::Core::SDL_Instance> sdl, char const * name)
    : m_ApplicationName(name), m_SdlInstance(sdl) {
    this->initialize();
}

Nutra::Game::Application::Application(std::shared_ptr<Nutra::Core::SDL_Instance> sdl, std::string name)
    : m_ApplicationName(name), m_SdlInstance(sdl) {
    this->initialize();
}

auto Nutra::Game::Application::initialize() -> void {

    m_Window = std::make_shared<Nutra::Core::Window>(m_SdlInstance, m_ApplicationName.c_str(), SDL_WINDOWPOS_UNDEFINED,
                                                     SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_HIDDEN);
    m_Renderer =
        std::make_unique<Nutra::Core::Renderer>(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

auto Nutra::Game::Application::run() noexcept -> void {
    m_Running = true;
    m_Window->show();
    while (m_Running) {
        this->handleEvents();
        this->update();
        this->render();
    }
}

auto Nutra::Game::Application::handleEvents() noexcept -> void {
    Nutra::Core::InputManager::getInstance().beginNewFrame();
    SDL_Event event;
    while (m_SdlInstance->pollEvent(&event)) {
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
    m_Renderer->setDrawColor(0, 0, 0, 0);
    m_Renderer->clear();
    m_Renderer->present();
}

auto Nutra::Game::Application::update() noexcept -> void {
}
