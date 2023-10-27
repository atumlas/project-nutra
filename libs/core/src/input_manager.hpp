#pragma once

#include <map>
#include <memory>
#include <vector>

#include "SDL2/SDL.h"

#include "action.hpp"
#include "input_state.hpp"
#include "keycode.hpp"
#include "keycode_mapping.hpp"


class InputManagerTest;

namespace Nutra::Core {
    class InputManager {
        public:
            static InputManager & getInstance() {
                static InputManager instance;
                return instance;
            }
            void updateState(SDL_Event & event);
            InputState & getCurrentState() const noexcept;
            bool isActionDown(Action action) const noexcept;

            // friendly Test fixture :)
            friend class InputManagerTest;

        private:
            InputManager();
            ~InputManager()                                = default;
            InputManager(InputManager const &)             = delete;
            InputManager & operator=(InputManager const &) = delete;
            void setDefaultKeyMap();

            std::unique_ptr<InputState> m_CurrentInputState;
            std::map<Action, KeyCodeMapping> m_ActionToKeyMap;
    };
} // namespace Nutra::Core
