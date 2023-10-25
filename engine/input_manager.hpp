#pragma once

#include <memory>

#include "SDL2/SDL.h"

#include "input_state.hpp"

namespace Nutra::Core {
    class InputManager {
        public:
            InputManager();
            ~InputManager() = default;
            void updateState(SDL_Event & event);
            void clearState();
            InputState const & getCurrentState() const noexcept;

        private:
            std::unique_ptr<InputState> m_CurrentInputState;
    };
} // namespace Nutra::Core
