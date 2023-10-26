#include "application.hpp"

#include "../libs/core/src/SDL_Instance.hpp"

int main(int argc, char * argv[]) {
    try {
        auto sdl  = std::make_shared<Nutra::Core::SDL_Instance>();
        auto game = std::make_unique<Nutra::Game::Application>(sdl, "Game");
        game->run();
    } catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;
}