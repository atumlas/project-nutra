#include "application.hpp"

#include "../libs/core/src/SDL_Instance.hpp"

#include "nutra-config.hpp"

#include <format>
#include <iostream>


int main(int argc, char * argv[]) {
    std::cout << std::format("{} {}.{}.{}", PROJECT_NAME, PROJECT_VERSION_MAJOR, PROJECT_VERSION_MINOR,
                             PROJECT_VERSION_PATCH)
              << std::endl;
    try {
        auto sdl  = std::make_shared<Nutra::Core::SDL_Instance>();
        auto game = std::make_unique<Nutra::Game::Application>(sdl, PROJECT_NAME);
        game->run();
    } catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;
}