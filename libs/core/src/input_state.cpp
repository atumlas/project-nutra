#include "input_state.hpp"

bool Nutra::Core::InputState::isKeyDown(KeyCode key) const noexcept {
    uint8_t keyAsInt = static_cast<uint8_t>(key);
    return m_keyState[keyAsInt / 64] & (1ULL << (keyAsInt % 64));
}

[[nodiscard]] int Nutra::Core::InputState::getMouseX() const noexcept {
    return m_MouseX;
}

[[nodiscard]] int Nutra::Core::InputState::getMouseY() const noexcept {
    return m_MouseY;
}
