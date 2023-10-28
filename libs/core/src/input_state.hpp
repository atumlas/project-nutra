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
                    return m_KeyDownState[keyAsInt / 64] & (1ULL << (keyAsInt % 64));
                } else if constexpr (inputStateType == INPUT_STATE_TYPE::KEY_UP) {
                    return m_KeyUpState[keyAsInt / 64] & (1ULL << (keyAsInt % 64));
                } else if constexpr (inputStateType == INPUT_STATE_TYPE::KEY_PRESSED) {
                    return m_KeyPressedState[keyAsInt / 64] & (1ULL << (keyAsInt % 64));
                } else {
                    throw std::runtime_error("Invalid input state type");
                }
            }

            friend class InputManager;

        private:
            int m_MouseX;
            int m_MouseY;
            std::array<uint64_t, 4> m_KeyPressedState;
            std::array<uint64_t, 4> m_KeyDownState;
            std::array<uint64_t, 4> m_KeyUpState;
    };
} // namespace Nutra::Core