# Input Handling

Two classes Input manager and input state. Input manager is a singleton that handles the input state. Input state is a struct that holds the current state of the input seperated by keyboard and mouse input. The input manager is updates the input state every frame. The input state is then used by the game to handle input.

## Naive input handling

The input state is passed to every widget currently shown on the screen. The widget then checks if the input state (mouse part) is inside its bounds and if it is, it handles the input. This is a naive approach and is not very efficient.
