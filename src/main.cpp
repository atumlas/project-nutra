#include "Application.hpp"

class ExampleApplication : public Nutra::Core::Application {
    public:
        ExampleApplication() : Application("Example") {
        }

        ~ExampleApplication() {
        }
};

int main(int argc, char * argv[]) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        exit(1);
    }
    atexit(SDL_Quit);
    try {
        auto game = std::make_unique<ExampleApplication>();
        game->run();
    } catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
    return 0;
}