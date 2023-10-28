#pragma once

#include <array>
#include <memory>
#include <stdexcept>

#include "input_state_type.hpp"
#include "keycode.hpp"

namespace Nutra::Core {
    class InputManager;
    class InputState {
        public:
            InputState()  = default;
            ~InputState() = default;

            InputState(InputState const &)             = delete;
            InputState & operator=(InputState const &) = delete;

            [[nodiscard]] auto getMouseX() const noexcept -> int;
            [[nodiscard]] auto getMouseY() const noexcept -> int;

            template <INPUT_STATE_TYPE inputStateType>
            [[nodiscard]] auto isKey(KEYCODE key) const -> bool {
                uint8_t keyAsInt = static_cast<uint8_t>(key);
                if constexpr (inputStateType == INPUT_STATE_TYPE::KEY_DOWN) {
                    return m_keyDownState[keyAsInt / 64] & (1ULL << (keyAsInt % 64));
                } else if constexpr (inputStateType == INPUT_STATE_TYPE::KEY_UP) {
                    return m_keyUpState[keyAsInt / 64] & (1ULL << (keyAsInt % 64));
                } else if constexpr (inputStateType == INPUT_STATE_TYPE::KEY_PRESSED) {
                    return m_keyPressedState[keyAsInt / 64] & (1ULL << (keyAsInt % 64));
                } else {
                    throw std::runtime_error("Invalid input state type");
                }
            }

            friend class InputManager;

        private:
            int m_mouse_x;
            int m_mouse_y;
            std::array<uint64_t, 4> m_keyPressedState;
            std::array<uint64_t, 4> m_keyDownState;
            std::array<uint64_t, 4> m_keyUpState;
    };
} // namespace Nutra::Core