#pragma once

#include "game_object.hpp"

#include <iostream>
#include <string>
#include <unordered_map>

namespace Nutra::Core {
    class Scene {
        private:
            std::string m_Id;
            std::unordered_map<std::string, std::shared_ptr<GameObject>> m_GameObjects;

        public:
            Scene(std::string id);
            Scene(char const * id);
            Scene();
            virtual ~Scene() = default;

            virtual void onCreate()  = 0;
            virtual void onDestroy() = 0;
    };
} // namespace Nutra::Core
