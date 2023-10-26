#pragma once

#include <cstdint>

#include <array>

#include "keycodes.hpp"

namespace Nutra::Core {
    class InputManager;
    class KeyboardInputState {
        public:
            KeyboardInputState()  = default;
            ~KeyboardInputState() = default;
            bool isKeyDown(KeyCode key) const noexcept;
            friend class InputManager;

        private:
            std::array<uint64_t, 4> m_keyBoardState;
    };
} // namespace Nutra::Core