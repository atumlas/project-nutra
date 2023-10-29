#include "main_menu.hpp"

Nutra::Game::MainMenu::MainMenu() : Scene("MainMenuScene") {
}

void Nutra::Game::MainMenu::onCreate() {
    spdlog::info("Creating Main Menu");
}

void Nutra::Game::MainMenu::onDestroy() {
    spdlog::info("Destroying Main Menu");
}
