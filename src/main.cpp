#include "application.hpp"

#include "../libs/core/src/sdl_instance.hpp"

#include "nutra_config.hpp"
#include "main_menu.hpp"

#include "spdlog/spdlog.h"

#include <format>
#include <iostream>

auto main(int argc, char * argv[]) -> int {
    spdlog::info("Starting {} version {}.{}.{}", PROJECT_NAME, PROJECT_VERSION_MAJOR, PROJECT_VERSION_MINOR,
                 PROJECT_VERSION_PATCH);
    try {
        auto sdl  = std::make_shared<Nutra::Core::SDL_Instance>();
        Nutra::Core::Scene * mainMenu = new Nutra::Game::MainMenu();
        auto game = std::make_unique<Nutra::Game::Application>(sdl, PROJECT_NAME, mainMenu);
        game->run();
    } catch (std::exception & e) {
        spdlog::error("An error occured during starting: {}", e.what());
        return -1;
    }
    return 0;
}