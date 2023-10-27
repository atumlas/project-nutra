#include "input_manager.hpp"
#include "keycodes.hpp"

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
    ASSERT_TRUE(inputManager->getCurrentState().getKeyboardInputState().isKeyDown(KeyCode::A));
}

TEST_F(InputManagerTest, handlesKeyUp) {
    // Arrange
    SDL_Event downEvent;
    downEvent.type           = SDL_KEYDOWN;
    downEvent.key.keysym.sym = SDLK_a;
    inputManager->updateState(downEvent);
    SDL_Event upEvent;
    upEvent.type           = SDL_KEYUP;
    upEvent.key.keysym.sym = SDLK_a;

    // Act
    inputManager->updateState(upEvent);

    // Assert
    ASSERT_FALSE(inputManager->getCurrentState().getKeyboardInputState().isKeyDown(KeyCode::A));
}

TEST_F(InputManagerTest, canMapActionToState) {
    // Arrange
    SDL_Event event;
    event.type           = SDL_KEYDOWN;
    event.key.keysym.sym = SDLK_a;

    // Act
    inputManager->updateState(event);

    // Assert
    ASSERT_TRUE(inputManager->isActionDown(Action::MOVE_LEFT));
}