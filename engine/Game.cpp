#include "Game.hpp"

Nutra::Core::Game::Game(std::shared_ptr<SDL_Instance> sdl, char const * name)
    : m_ApplicationName(name), m_SDL_Instance(sdl) {
    initialize();
}

Nutra::Core::Game::Game(std::shared_ptr<SDL_Instance> sdl, std::string name)
    : m_ApplicationName(name), m_SDL_Instance(sdl) {
    initialize();
}

void Nutra::Core::Game::initialize() {

    m_Window   = std::make_shared<Window>(m_SDL_Instance, m_ApplicationName.c_str(), SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_HIDDEN);
    m_Renderer = std::make_unique<Renderer>(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void Nutra::Core::Game::run() noexcept {
    m_Running = true;
    m_Window->show();
    while (m_Running) {
        handleEvents();
        update();
        render();
    }
}

void Nutra::Core::Game::handleEvents() noexcept {
    SDL_Event event;
    while (m_SDL_Instance->pollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            m_Running = false;
            break;
        default:
            break;
        }
    }
}

void Nutra::Core::Game::render() noexcept {
    m_Renderer->setDrawColor(0, 0, 0, 0);
    m_Renderer->clear();
    m_Renderer->present();
}

void Nutra::Core::Game::update() noexcept {
}
