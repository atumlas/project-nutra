#pragma once

#include <memory>
#include <stdexcept>
#include <unordered_map>
#include <vector>

#include "SDL2/SDL.h"

#include "input_action.hpp"
#include "input_state.hpp"
#include "input_state_type.hpp"
#include "keycode.hpp"
#include "keycode_mapping.hpp"

class InputManagerTest;

namespace Nutra::Core {
    class InputManager {
        public:
            static InputManager & getInstance() {
                static InputManager instance;
                return instance;
            }
            auto handleEvent(SDL_Event & event) -> void;
            auto getCurrentState() const noexcept -> InputState &;

            template <INPUT_STATE_TYPE inputStateType>
            [[nodiscard]] auto isAction(INPUT_ACTION action) const -> bool {
                KeyCodeMapping keyCodeMapping = m_action_to_keymap.at(action);
                bool isKeyDown                = false;
                std::array<uint64_t, 4> keyState;

                if constexpr (inputStateType == INPUT_STATE_TYPE::KEY_DOWN) {
                    keyState = m_currentInputState->m_keyDownState;
                } else if constexpr (inputStateType == INPUT_STATE_TYPE::KEY_UP) {
                    keyState = m_currentInputState->m_keyUpState;
                } else if constexpr (inputStateType == INPUT_STATE_TYPE::KEY_PRESSED) {
                    keyState = m_currentInputState->m_keyPressedState;
                } else {
                    throw std::runtime_error("Invalid input state type");
                }
                for (auto index : {0, 1, 2, 3}) {
                    isKeyDown = keyState[index] & keyCodeMapping[index];
                    if (isKeyDown) {
                        break;
                    }
                }
                return isKeyDown;
            }

            auto beginNewFrame() -> void;

            // friendly Test fixture :)
            friend class InputManagerTest;

        private:
            InputManager();
            ~InputManager() = default;

            InputManager(InputManager const &)             = delete;
            InputManager & operator=(InputManager const &) = delete;

            auto setDefaultKeyMap() -> void;

            std::unique_ptr<InputState> m_currentInputState;
            std::unordered_map<INPUT_ACTION, KeyCodeMapping> m_action_to_keymap;
    };
} // namespace Nutra::Core
