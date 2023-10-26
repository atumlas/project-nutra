#pragma once

#include <cstdint>

namespace Nutra::Core {
    class InputManager;
    class MouseInputState {
        public:
            MouseInputState()  = default;
            ~MouseInputState() = default;

            [[nodiscard]] int getMouseX() const noexcept;
            [[nodiscard]] int getMouseY() const noexcept;
            [[nodiscard]] bool isMouseButtonDown(uint8_t button) const noexcept;

            friend class InputManager;

        private:
            int m_MouseX;
            int m_MouseY;
            uint8_t m_MouseButtonState; // 0x00000001 = left, 0x00000002 = middle, 0x00000004 = right etc.
    };
} // namespace Nutra::Core