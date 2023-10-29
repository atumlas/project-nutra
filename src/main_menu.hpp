#pragma once

#include "../libs/core/src/scene.hpp"

#include "spdlog/spdlog.h"

#include <string>

namespace Nutra::Game {
    class MainMenu : public Nutra::Core::Scene {
        public:
            MainMenu();

            void onCreate() override;
            void onDestroy() override;
    };
} // namespace Nutra::Game
