#pragma once

#include "../libs/core/src/scene.hpp"

namespace Nutra::Game {
    class MainMenu : public Nutra::Core::Scene {
        public:
            MainMenu()
                : Scene("lol"){

                  };

            void onCreate() override;
            void onDestroy() override;
    };
} // namespace Nutra::Game
