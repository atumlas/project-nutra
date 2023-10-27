#pragma once

#include <array>
#include <memory>

#include "keycodes.hpp"

namespace Nutra::Core {
    class InputManager;
    class InputState {
        public:
            InputState()                               = default;
            ~InputState()                              = default;
            InputState(InputState const &)             = delete;
            InputState & operator=(InputState const &) = delete;
            [[nodiscard]] int getMouseX() const noexcept;
            [[nodiscard]] int getMouseY() const noexcept;
            bool isKeyDown(KeyCode key) const noexcept;
            friend class InputManager;

        private:
            int m_MouseX;
            int m_MouseY;
            std::array<uint64_t, 4> m_keyState;
    };
} // namespace Nutra::Core