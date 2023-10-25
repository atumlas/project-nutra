#include "input_state.hpp"

Nutra::Core::InputState::InputState() {
    m_MouseInputState    = std::make_unique<MouseInputState>();
    m_KeyboardInputState = std::make_unique<KeyboardInputState>();
}
