#include "keyboard_input_state.hpp"

bool Nutra::Core::KeyboardInputState::isKeyDown(KeyCode key) const noexcept {
    uint8_t keyAsInt = static_cast<uint8_t>(key);
    return m_keyBoardState[keyAsInt / 64] & (1 << (keyAsInt % 64));
}