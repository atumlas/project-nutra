#pragma once

#include <memory>

#include "SDL2/SDL.h"

#include "input_state.hpp"

class InputManagerParameterizedTestFixture;

namespace Nutra::Core {
    class InputManager {
        public:
            static InputManager & getInstance() {
                static InputManager instance;
                return instance;
            }
            void updateState(SDL_Event & event);
            InputState & getCurrentState() const noexcept;

            // Test fixture
            friend class InputManagerParameterizedTestFixture;

        private:
            InputManager();
            ~InputManager()                                = default;
            InputManager(InputManager const &)             = delete;
            InputManager & operator=(InputManager const &) = delete;
            std::unique_ptr<InputState> m_CurrentInputState;
    };
} // namespace Nutra::Core
