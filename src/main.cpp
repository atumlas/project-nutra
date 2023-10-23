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
    auto game = std::make_unique<ExampleApplication>();
    game->run();
    return 0;
}