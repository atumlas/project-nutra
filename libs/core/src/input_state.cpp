#include "input_state.hpp"

Nutra::Core::InputState::InputState() {
    m_MouseInputState    = std::make_unique<MouseInputState>();
    m_KeyboardInputState = std::make_unique<KeyboardInputState>();
}

Nutra::Core::MouseInputState & Nutra::Core::InputState::getMouseInputState() const noexcept {
    return *m_MouseInputState;
}

Nutra::Core::KeyboardInputState & Nutra::Core::InputState::getKeyboardInputState() const noexcept {
    return *m_KeyboardInputState;
}
