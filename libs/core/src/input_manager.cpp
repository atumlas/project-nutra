#include "input_manager.hpp"

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
            m_currentInputState->m_mouse_x = event.motion.x;
            m_currentInputState->m_mouse_y = event.motion.y;
            break;
        }
    case SDL_MOUSEBUTTONDOWN:
        {
            uint8_t keyCode =
                static_cast<uint8_t>(Nutra::Core::convertSDLMouseButtonToNutraKeyCode(event.button.button));
            m_currentInputState->m_keyPressedState[keyCode / 64] |= 1ULL << (keyCode % 64);
            m_currentInputState->m_keyDownState[keyCode / 64] |= 1ULL << (keyCode % 64);
            break;
        }
    case SDL_MOUSEBUTTONUP:
        {
            uint8_t keyCode =
                static_cast<uint8_t>(Nutra::Core::convertSDLMouseButtonToNutraKeyCode(event.button.button));
            m_currentInputState->m_keyPressedState[keyCode / 64] ^= 1ULL << (keyCode % 64);
            m_currentInputState->m_keyUpState[keyCode / 64] |= 1ULL << (keyCode % 64);
            break;
        }
    case SDL_KEYDOWN:
        {
            uint8_t keyCode = static_cast<uint8_t>(Nutra::Core::convertSDLKeyCodeToNutraKeyCode(event.key.keysym.sym));
            m_currentInputState->m_keyPressedState[keyCode / 64] |= 1ULL << (keyCode % 64);
            m_currentInputState->m_keyDownState[keyCode / 64] |= 1ULL << (keyCode % 64);
            break;
        }
    case SDL_KEYUP:
        {
            uint8_t keyCode = static_cast<uint8_t>(Nutra::Core::convertSDLKeyCodeToNutraKeyCode(event.key.keysym.sym));
            m_currentInputState->m_keyPressedState[keyCode / 64] ^= 1ULL << (keyCode % 64);
            m_currentInputState->m_keyUpState[keyCode / 64] |= 1ULL << (keyCode % 64);
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
    for (auto index : {0, 1, 2, 3}) {
        m_currentInputState->m_keyDownState[index] = 0;
        m_currentInputState->m_keyUpState[index]   = 0;
    }
}