#include "input_manager.hpp"

#include <gtest/gtest.h>

#include <utility>

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

TEST_F(InputManagerTest, handlesKeyDown) {
    // Arrange
    SDL_Event event;
    event.type           = SDL_KEYDOWN;
    event.key.keysym.sym = SDLK_a;

    // Act
    inputManager->updateState(event);

    // Assert
    ASSERT_TRUE(inputManager->getCurrentState().isKeyDown(KeyCode::A));
}

TEST_F(InputManagerTest, handlesMouseButtonDown) {
    // Arrange
    SDL_Event event;
    event.type          = SDL_MOUSEBUTTONDOWN;
    event.button.button = SDL_BUTTON_LEFT;

    // Act
    inputManager->updateState(event);

    // Assert
    ASSERT_TRUE(inputManager->getCurrentState().isKeyDown(KeyCode::MOUSE_BUTTON_LEFT));
}

TEST_F(InputManagerTest, handlesKeyUp) {
    // Arrange
    SDL_Event event;
    event.type           = SDL_KEYDOWN;
    event.key.keysym.sym = SDLK_a;
    inputManager->updateState(event);
    SDL_Event upEvent;
    event.type           = SDL_KEYUP;
    event.key.keysym.sym = SDLK_a;

    // Act
    inputManager->updateState(event);

    // Assert
    ASSERT_FALSE(inputManager->getCurrentState().isKeyDown(KeyCode::A));
}

TEST_F(InputManagerTest, handlesMouseButtonUp) {
    // Arrange
    SDL_Event event;
    event.type          = SDL_MOUSEBUTTONDOWN;
    event.button.button = SDL_BUTTON_LEFT;
    inputManager->updateState(event);
    event.type          = SDL_MOUSEBUTTONUP;
    event.button.button = SDL_BUTTON_LEFT;

    // Act
    inputManager->updateState(event);

    // Assert
    ASSERT_FALSE(inputManager->getCurrentState().isKeyDown(KeyCode::MOUSE_BUTTON_LEFT));
}

TEST_F(InputManagerTest, canMapActionToState) {
    // Arrange
    SDL_Event event;
    event.type           = SDL_KEYDOWN;
    event.key.keysym.sym = SDLK_LEFT;

    // Act
    inputManager->updateState(event);

    // Assert
    ASSERT_TRUE(inputManager->isActionDown(Action::MOVE_LEFT));
}

TEST_F(InputManagerTest, canHandleSingleKeyUpForAction) {
    // Arrange
    SDL_Event event;
    event.type           = SDL_KEYDOWN;
    event.key.keysym.sym = SDLK_LEFT;
    inputManager->updateState(event);
    event.type           = SDL_KEYDOWN;
    event.key.keysym.sym = SDLK_a;
    inputManager->updateState(event);
    event.type           = SDL_KEYUP;
    event.key.keysym.sym = SDLK_LEFT;

    // Act
    inputManager->updateState(event);

    // Assert
    ASSERT_TRUE(inputManager->isActionDown(Action::MOVE_LEFT));
}

TEST_F(InputManagerTest, CanHandleMouseMovement) {
    // Arrange
    SDL_Event event;
    event.type     = SDL_MOUSEMOTION;
    event.motion.x = 10;
    event.motion.y = 20;

    // Act
    inputManager->updateState(event);

    // Assert
    ASSERT_EQ(inputManager->getCurrentState().getMouseX(), 10);
    ASSERT_EQ(inputManager->getCurrentState().getMouseY(), 20);
}