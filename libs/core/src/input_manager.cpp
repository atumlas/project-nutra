#include "input_manager.hpp"

Nutra::Core::InputManager::InputManager() {
    m_CurrentInputState = std::make_unique<InputState>();
    // TODO: Read keymap from file and set it to their default values only if the file is not found
    setDefaultKeyMap();
    // TODO: Store the default keymap in a file
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
            m_CurrentInputState->m_MouseInputState->m_MouseX = event.motion.x;
            m_CurrentInputState->m_MouseInputState->m_MouseY = event.motion.y;
            break;
        }
    case SDL_MOUSEBUTTONDOWN:
        {
            m_CurrentInputState->m_MouseInputState->m_MouseButtonState |= event.button.button;
            break;
        }
    case SDL_MOUSEBUTTONUP:
        {
            m_CurrentInputState->m_MouseInputState->m_MouseButtonState ^= event.button.button;
            break;
        }
    case SDL_KEYDOWN:
        {
            uint8_t keyCode = static_cast<uint8_t>(Nutra::Core::convertSDLKeyCodeToNutraKeyCode(event.key.keysym.sym));
            m_CurrentInputState->m_KeyboardInputState->m_keyBoardState[keyCode / 64] |= 1ULL << (keyCode % 64);
            break;
        }
    case SDL_KEYUP:
        {
            uint8_t keyCode = static_cast<uint8_t>(Nutra::Core::convertSDLKeyCodeToNutraKeyCode(event.key.keysym.sym));
            m_CurrentInputState->m_KeyboardInputState->m_keyBoardState[keyCode / 64] ^= 1ULL << (keyCode % 64);
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
    for (int i = 0; i < 4; ++i) {
        isKeyDown = m_CurrentInputState->m_KeyboardInputState->m_keyBoardState[i] & keyCodeMapping[i];
        if (isKeyDown) {
            break;
        }
    }
    return isKeyDown;
}