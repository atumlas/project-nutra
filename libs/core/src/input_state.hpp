#pragma once

#include <memory>

#include "keyboard_input_state.hpp"
#include "mouse_input_state.hpp"

namespace Nutra::Core {
    class InputManager;
    class InputState {
        public:
            InputState();
            ~InputState()                              = default;
            InputState(InputState const &)             = delete;
            InputState & operator=(InputState const &) = delete;
            MouseInputState & getMouseInputState() const noexcept;
            KeyboardInputState & getKeyboardInputState() const noexcept;
            friend class InputManager;

        private:
            std::unique_ptr<MouseInputState> m_MouseInputState;
            std::unique_ptr<KeyboardInputState> m_KeyboardInputState;
    };
} // namespace Nutra::Core