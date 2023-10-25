#include "input_manager.hpp"

Nutra::Core::InputManager::InputManager() {
    m_CurrentInputState = std::make_unique<InputState>();
}

void Nutra::Core::InputManager::updateState(SDL_Event & event) {
    switch (event.type) {
    case SDL_MOUSEMOTION:
        {
            m_CurrentInputState->m_MouseInputState->m_MouseX = event.motion.x;
            m_CurrentInputState->m_MouseInputState->m_MouseY = event.motion.y;
            break;
        }
    case SDL_MOUSEBUTTONDOWN:
    case SDL_MOUSEBUTTONUP:
        {
            m_CurrentInputState->m_MouseInputState->m_MouseButtonState |= event.button.button;
            break;
        }
    case SDL_KEYDOWN:
    case SDL_KEYUP:
        {
            uint8_t keyCode = static_cast<uint8_t>(Nutra::Core::convertSDLKeyCodeToNutraKeyCode(event.key.keysym.sym));
            m_CurrentInputState->m_KeyboardInputState->m_keyBoardState[keyCode / 64] |= 1 << (keyCode % 64);
            break;
        }
    default:
        break;
    }
}

void Nutra::Core::InputManager::clearState() {
    m_CurrentInputState = std::make_unique<InputState>();
}

Nutra::Core::InputState const & Nutra::Core::InputManager::getCurrentState() const noexcept {
    return *m_CurrentInputState.get();
}