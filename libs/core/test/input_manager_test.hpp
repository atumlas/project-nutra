#include "input_manager.hpp"

#include <gtest/gtest.h>

using namespace Nutra::Core;
class InputManagerTest : public ::testing::Test {
    public:
        InputManager * inputManager;

        InputManagerTest() {
            inputManager = new InputManager();
        }

        ~InputManagerTest() {
            delete inputManager;
        }
};

TEST_F(InputManagerTest, canHandleKeyDown) {
    // Arrange
    SDL_Event event;
    event.type           = SDL_KEYDOWN;
    event.key.keysym.sym = SDLK_a;

    // Act
    inputManager->handleEvent(event);

    // Assert
    ASSERT_TRUE(inputManager->getCurrentState().isKey<INPUT_STATE_TYPE::KEY_DOWN>(KEYCODE::A));
}

TEST_F(InputManagerTest, canHandleMouseButtonDown) {
    // Arrange
    SDL_Event event;
    event.type          = SDL_MOUSEBUTTONDOWN;
    event.button.button = SDL_BUTTON_LEFT;

    // Act
    inputManager->handleEvent(event);

    // Assert
    ASSERT_TRUE(inputManager->getCurrentState().isKey<INPUT_STATE_TYPE::KEY_DOWN>(KEYCODE::MOUSE_BUTTON_LEFT));
}

TEST_F(InputManagerTest, canHandleKeyUp) {
    // Arrange
    SDL_Event event;
    event.type           = SDL_KEYDOWN;
    event.key.keysym.sym = SDLK_a;
    inputManager->handleEvent(event);
    inputManager->beginNewFrame();
    SDL_Event upEvent;
    event.type           = SDL_KEYUP;
    event.key.keysym.sym = SDLK_a;

    // Act
    inputManager->handleEvent(event);

    // Assert
    ASSERT_FALSE(inputManager->getCurrentState().isKey<INPUT_STATE_TYPE::KEY_PRESSED>(KEYCODE::A));
    ASSERT_TRUE(inputManager->getCurrentState().isKey<INPUT_STATE_TYPE::KEY_UP>(KEYCODE::A));
}

TEST_F(InputManagerTest, canHandleMouseButtonUp) {
    // Arrange
    SDL_Event event;
    event.type          = SDL_MOUSEBUTTONDOWN;
    event.button.button = SDL_BUTTON_LEFT;
    inputManager->handleEvent(event);
    inputManager->beginNewFrame();
    event.type          = SDL_MOUSEBUTTONUP;
    event.button.button = SDL_BUTTON_LEFT;

    // Act
    inputManager->handleEvent(event);

    // Assert
    ASSERT_FALSE(inputManager->getCurrentState().isKey<INPUT_STATE_TYPE::KEY_PRESSED>(KEYCODE::MOUSE_BUTTON_LEFT));
    ASSERT_TRUE(inputManager->getCurrentState().isKey<INPUT_STATE_TYPE::KEY_UP>(KEYCODE::MOUSE_BUTTON_LEFT));
}

TEST_F(InputManagerTest, canMapActionToState) {
    // Arrange
    SDL_Event event;
    event.type           = SDL_KEYDOWN;
    event.key.keysym.sym = SDLK_LEFT;

    // Act
    inputManager->handleEvent(event);

    // Assert
    ASSERT_TRUE(inputManager->isAction<INPUT_STATE_TYPE::KEY_DOWN>(INPUT_ACTION::MOVE_LEFT));
}

TEST_F(InputManagerTest, canHandleSingleKeyUpForAction) {
    // Arrange
    SDL_Event event;
    event.type           = SDL_KEYDOWN;
    event.key.keysym.sym = SDLK_LEFT;
    inputManager->handleEvent(event);
    event.type           = SDL_KEYDOWN;
    event.key.keysym.sym = SDLK_a;
    inputManager->handleEvent(event);
    inputManager->beginNewFrame();
    event.type           = SDL_KEYUP;
    event.key.keysym.sym = SDLK_LEFT;

    // Act
    inputManager->handleEvent(event);

    // Assert
    ASSERT_TRUE(inputManager->isAction<INPUT_STATE_TYPE::KEY_PRESSED>(INPUT_ACTION::MOVE_LEFT));
}

TEST_F(InputManagerTest, canHandleMouseMovement) {
    // Arrange
    SDL_Event event;
    event.type     = SDL_MOUSEMOTION;
    event.motion.x = 10;
    event.motion.y = 20;

    // Act
    inputManager->handleEvent(event);

    // Assert
    ASSERT_EQ(inputManager->getCurrentState().getMouseX(), 10);
    ASSERT_EQ(inputManager->getCurrentState().getMouseY(), 20);
}