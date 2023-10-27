#include "input_manager.hpp"

Nutra::Core::InputManager::InputManager() {
    m_CurrentInputState = std::make_unique<InputState>();
    setDefaultKeyMap();
}

void Nutra::Core::InputManager::setDefaultKeyMap() {
    m_ActionToKeyMap[Action::MOVE_LEFT]  = {KeyCode::A, KeyCode::LEFT};
    m_ActionToKeyMap[Action::MOVE_RIGHT] = {KeyCode::D, KeyCode::RIGHT};
    m_ActionToKeyMap[Action::MOVE_UP]    = {KeyCode::W, KeyCode::UP};
    m_ActionToKeyMap[Action::MOVE_DOWN]  = {KeyCode::S, KeyCode::DOWN};
}

void Nutra::Core::InputManager::updateState(SDL_Event & event) {
    switch (event.type) {
    case SDL_MOUSEMOTION:
        {
            m_CurrentInputState->m_MouseX = event.motion.x;
            m_CurrentInputState->m_MouseY = event.motion.y;
            break;
        }
    case SDL_MOUSEBUTTONDOWN:
        {
            uint8_t keyCode =
                static_cast<uint8_t>(Nutra::Core::convertSDLMouseButtonToNutraKeyCode(event.button.button));
            m_CurrentInputState->m_keyState[keyCode / 64] |= 1ULL << (keyCode % 64);
            break;
        }
    case SDL_MOUSEBUTTONUP:
        {
            uint8_t keyCode =
                static_cast<uint8_t>(Nutra::Core::convertSDLMouseButtonToNutraKeyCode(event.button.button));
            m_CurrentInputState->m_keyState[keyCode / 64] ^= 1ULL << (keyCode % 64);
            break;
        }
    case SDL_KEYDOWN:
        {
            uint8_t keyCode = static_cast<uint8_t>(Nutra::Core::convertSDLKeyCodeToNutraKeyCode(event.key.keysym.sym));
            m_CurrentInputState->m_keyState[keyCode / 64] |= 1ULL << (keyCode % 64);
            break;
        }
    case SDL_KEYUP:
        {
            uint8_t keyCode = static_cast<uint8_t>(Nutra::Core::convertSDLKeyCodeToNutraKeyCode(event.key.keysym.sym));
            m_CurrentInputState->m_keyState[keyCode / 64] ^= 1ULL << (keyCode % 64);
            break;
        }
    default:
        break;
    }
}

Nutra::Core::InputState & Nutra::Core::InputManager::getCurrentState() const noexcept {
    return *m_CurrentInputState.get();
}

bool Nutra::Core::InputManager::isActionDown(Action action) const noexcept {
    KeyCodeMapping keyCodeMapping = m_ActionToKeyMap.at(action);
    bool isKeyDown                = false;
    for (int i = 0; i < 4; i++) {
        isKeyDown = m_CurrentInputState->m_keyState[i] & keyCodeMapping[i];
        if (isKeyDown) {
            break;
        }
    }
    return isKeyDown;
}