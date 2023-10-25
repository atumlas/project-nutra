#pragma once

#include <memory>

#include "keyboard_input_state.hpp"
#include "mouse_input_state.hpp"

namespace Nutra::Core {
    class InputManager;
    class InputState {
        public:
            InputState();
            ~InputState() = default;

            friend class InputManager;

        private:
            std::unique_ptr<Nutra::Core::MouseInputState> m_MouseInputState;
            std::unique_ptr<Nutra::Core::KeyboardInputState> m_KeyboardInputState;
    };
} // namespace Nutra::Core