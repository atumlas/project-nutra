#include "input_state.hpp"

[[nodiscard]] auto Nutra::Core::InputState::getMouseX() const noexcept -> int {
    return m_MouseX;
}

[[nodiscard]] auto Nutra::Core::InputState::getMouseY() const noexcept -> int {
    return m_MouseY;
}