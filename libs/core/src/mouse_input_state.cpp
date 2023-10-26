#include "mouse_input_state.hpp"

[[nodiscard]] int Nutra::Core::MouseInputState::getMouseX() const noexcept {
    return m_MouseX;
}

[[nodiscard]] int Nutra::Core::MouseInputState::getMouseY() const noexcept {
    return m_MouseY;
}

[[nodiscard]] bool Nutra::Core::MouseInputState::isMouseButtonDown(uint8_t button) const noexcept {
    return m_MouseButtonState & button;
}