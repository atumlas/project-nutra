#include "input_manager.hpp"

#include <ranges>

Nutra::Core::InputManager::InputManager() {
    m_currentInputState = std::make_unique<InputState>();
    setDefaultKeyMap();
}

auto Nutra::Core::InputManager::setDefaultKeyMap() -> void {
    m_action_to_keymap[INPUT_ACTION::MOVE_LEFT]  = {KEYCODE::A, KEYCODE::LEFT};
    m_action_to_keymap[INPUT_ACTION::MOVE_RIGHT] = {KEYCODE::D, KEYCODE::RIGHT};
    m_action_to_keymap[INPUT_ACTION::MOVE_UP]    = {KEYCODE::W, KEYCODE::UP};
    m_action_to_keymap[INPUT_ACTION::MOVE_DOWN]  = {KEYCODE::S, KEYCODE::DOWN};
}

auto Nutra::Core::InputManager::handleEvent(SDL_Event & event) -> void {
    switch (event.type) {
    case SDL_MOUSEMOTION:
        {
            m_currentInputState->m_MouseX = event.motion.x;
            m_currentInputState->m_MouseY = event.motion.y;
            break;
        }
    case SDL_MOUSEBUTTONDOWN:
        {
            uint8_t keyCode =
                static_cast<uint8_t>(Nutra::Core::convertSDLMouseButtonToNutraKeyCode(event.button.button));
            m_currentInputState->m_KeyPressedState[keyCode / 64] |= 1ULL << (keyCode % 64);
            m_currentInputState->m_KeyDownState[keyCode / 64] |= 1ULL << (keyCode % 64);
            break;
        }
    case SDL_MOUSEBUTTONUP:
        {
            uint8_t keyCode =
                static_cast<uint8_t>(Nutra::Core::convertSDLMouseButtonToNutraKeyCode(event.button.button));
            m_currentInputState->m_KeyPressedState[keyCode / 64] ^= 1ULL << (keyCode % 64);
            m_currentInputState->m_KeyUpState[keyCode / 64] |= 1ULL << (keyCode % 64);
            break;
        }
    case SDL_KEYDOWN:
        {
            uint8_t keyCode = static_cast<uint8_t>(Nutra::Core::convertSDLKeyCodeToNutraKeyCode(event.key.keysym.sym));
            m_currentInputState->m_KeyPressedState[keyCode / 64] |= 1ULL << (keyCode % 64);
            m_currentInputState->m_KeyDownState[keyCode / 64] |= 1ULL << (keyCode % 64);
            break;
        }
    case SDL_KEYUP:
        {
            uint8_t keyCode = static_cast<uint8_t>(Nutra::Core::convertSDLKeyCodeToNutraKeyCode(event.key.keysym.sym));
            m_currentInputState->m_KeyPressedState[keyCode / 64] ^= 1ULL << (keyCode % 64);
            m_currentInputState->m_KeyUpState[keyCode / 64] |= 1ULL << (keyCode % 64);
            break;
        }
    default:
        break;
    }
}

auto Nutra::Core::InputManager::getCurrentState() const noexcept -> Nutra::Core::InputState & {
    return *m_currentInputState.get();
}

auto Nutra::Core::InputManager::beginNewFrame() -> void {
    for (auto index : std::views::iota(0, 4)) {
        m_currentInputState->m_KeyDownState[index] = 0;
        m_currentInputState->m_KeyUpState[index]   = 0;
    }
}