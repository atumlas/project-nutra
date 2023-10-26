#include "input_manager.hpp"
#include "keycodes.hpp"

#include <gtest/gtest.h>

#include <utility>

using namespace Nutra::Core;

class InputManagerParameterizedTestFixture : public ::testing::TestWithParam<std::pair<SDL_KeyCode, KeyCode>> {
    protected:
        InputManager * inputManager;

        InputManagerParameterizedTestFixture() {
            inputManager = new InputManager();
        }

        ~InputManagerParameterizedTestFixture() {
            delete inputManager;
        }
};

// The paramiters for this test suite are a pair of SDL_KeyCode and the expected nutra KeyCode
INSTANTIATE_TEST_SUITE_P(
    CanHandleKeydown, InputManagerParameterizedTestFixture,
    ::testing::Values(
        std::make_pair(SDLK_UNKNOWN, KeyCode::UNKNOWN), std::make_pair(SDLK_RETURN, KeyCode::RETURN),
        std::make_pair(SDLK_ESCAPE, KeyCode::ESCAPE), std::make_pair(SDLK_BACKSPACE, KeyCode::BACKSPACE),
        std::make_pair(SDLK_TAB, KeyCode::TAB), std::make_pair(SDLK_SPACE, KeyCode::SPACE),
        std::make_pair(SDLK_EXCLAIM, KeyCode::EXCLAIM), std::make_pair(SDLK_QUOTEDBL, KeyCode::QUOTEDBL),
        std::make_pair(SDLK_HASH, KeyCode::HASH), std::make_pair(SDLK_PERCENT, KeyCode::PERCENT),
        std::make_pair(SDLK_DOLLAR, KeyCode::DOLLAR), std::make_pair(SDLK_AMPERSAND, KeyCode::AMPERSAND),
        std::make_pair(SDLK_QUOTE, KeyCode::QUOTE), std::make_pair(SDLK_LEFTPAREN, KeyCode::LEFTPAREN),
        std::make_pair(SDLK_RIGHTPAREN, KeyCode::RIGHTPAREN), std::make_pair(SDLK_ASTERISK, KeyCode::ASTERISK),
        std::make_pair(SDLK_PLUS, KeyCode::PLUS), std::make_pair(SDLK_COMMA, KeyCode::COMMA),
        std::make_pair(SDLK_MINUS, KeyCode::MINUS), std::make_pair(SDLK_PERIOD, KeyCode::PERIOD),
        std::make_pair(SDLK_SLASH, KeyCode::SLASH), std::make_pair(SDLK_0, KeyCode::ZERO),
        std::make_pair(SDLK_1, KeyCode::ONE), std::make_pair(SDLK_2, KeyCode::TWO),
        std::make_pair(SDLK_3, KeyCode::THREE), std::make_pair(SDLK_4, KeyCode::FOUR),
        std::make_pair(SDLK_5, KeyCode::FIVE), std::make_pair(SDLK_6, KeyCode::SIX),
        std::make_pair(SDLK_7, KeyCode::SEVEN), std::make_pair(SDLK_8, KeyCode::EIGHT),
        std::make_pair(SDLK_9, KeyCode::NINE), std::make_pair(SDLK_COLON, KeyCode::COLON),
        std::make_pair(SDLK_SEMICOLON, KeyCode::SEMICOLON), std::make_pair(SDLK_LESS, KeyCode::LESS),
        std::make_pair(SDLK_EQUALS, KeyCode::EQUALS), std::make_pair(SDLK_GREATER, KeyCode::GREATER),
        std::make_pair(SDLK_QUESTION, KeyCode::QUESTION), std::make_pair(SDLK_AT, KeyCode::AT),
        std::make_pair(SDLK_LEFTBRACKET, KeyCode::LEFTBRACKET), std::make_pair(SDLK_BACKSLASH, KeyCode::BACKSLASH),
        std::make_pair(SDLK_RIGHTBRACKET, KeyCode::RIGHTBRACKET), std::make_pair(SDLK_CARET, KeyCode::CARET),
        std::make_pair(SDLK_UNDERSCORE, KeyCode::UNDERSCORE), std::make_pair(SDLK_BACKQUOTE, KeyCode::BACKQUOTE),
        std::make_pair(SDLK_a, KeyCode::A), std::make_pair(SDLK_b, KeyCode::B), std::make_pair(SDLK_c, KeyCode::C),
        std::make_pair(SDLK_d, KeyCode::D), std::make_pair(SDLK_e, KeyCode::E), std::make_pair(SDLK_f, KeyCode::F),
        std::make_pair(SDLK_g, KeyCode::G), std::make_pair(SDLK_h, KeyCode::H), std::make_pair(SDLK_i, KeyCode::I),
        std::make_pair(SDLK_j, KeyCode::J), std::make_pair(SDLK_k, KeyCode::K), std::make_pair(SDLK_l, KeyCode::L),
        std::make_pair(SDLK_m, KeyCode::M), std::make_pair(SDLK_n, KeyCode::N), std::make_pair(SDLK_o, KeyCode::O),
        std::make_pair(SDLK_p, KeyCode::P), std::make_pair(SDLK_q, KeyCode::Q), std::make_pair(SDLK_r, KeyCode::R),
        std::make_pair(SDLK_s, KeyCode::S), std::make_pair(SDLK_t, KeyCode::T), std::make_pair(SDLK_u, KeyCode::U),
        std::make_pair(SDLK_v, KeyCode::V), std::make_pair(SDLK_w, KeyCode::W), std::make_pair(SDLK_x, KeyCode::X),
        std::make_pair(SDLK_y, KeyCode::Y), std::make_pair(SDLK_z, KeyCode::Z),
        std::make_pair(SDLK_CAPSLOCK, KeyCode::CAPSLOCK), std::make_pair(SDLK_F1, KeyCode::F1),
        std::make_pair(SDLK_F2, KeyCode::F2), std::make_pair(SDLK_F3, KeyCode::F3),
        std::make_pair(SDLK_F4, KeyCode::F4), std::make_pair(SDLK_F5, KeyCode::F5),
        std::make_pair(SDLK_F6, KeyCode::F6), std::make_pair(SDLK_F7, KeyCode::F7),
        std::make_pair(SDLK_F8, KeyCode::F8), std::make_pair(SDLK_F9, KeyCode::F9),
        std::make_pair(SDLK_F10, KeyCode::F10), std::make_pair(SDLK_F11, KeyCode::F11),
        std::make_pair(SDLK_F12, KeyCode::F12), std::make_pair(SDLK_PRINTSCREEN, KeyCode::PRINTSCREEN),
        std::make_pair(SDLK_SCROLLLOCK, KeyCode::SCROLLLOCK), std::make_pair(SDLK_PAUSE, KeyCode::PAUSE),
        std::make_pair(SDLK_INSERT, KeyCode::INSERT), std::make_pair(SDLK_HOME, KeyCode::HOME),
        std::make_pair(SDLK_PAGEUP, KeyCode::PAGEUP), std::make_pair(SDLK_DELETE, KeyCode::DELETE),
        std::make_pair(SDLK_END, KeyCode::END), std::make_pair(SDLK_PAGEDOWN, KeyCode::PAGEDOWN),
        std::make_pair(SDLK_RIGHT, KeyCode::RIGHT), std::make_pair(SDLK_LEFT, KeyCode::LEFT),
        std::make_pair(SDLK_DOWN, KeyCode::DOWN), std::make_pair(SDLK_UP, KeyCode::UP),
        std::make_pair(SDLK_NUMLOCKCLEAR, KeyCode::NUMLOCKCLEAR), std::make_pair(SDLK_KP_DIVIDE, KeyCode::KP_DIVIDE),
        std::make_pair(SDLK_KP_MULTIPLY, KeyCode::KP_MULTIPLY), std::make_pair(SDLK_KP_MINUS, KeyCode::KP_MINUS),
        std::make_pair(SDLK_KP_PLUS, KeyCode::KP_PLUS), std::make_pair(SDLK_KP_ENTER, KeyCode::KP_ENTER),
        std::make_pair(SDLK_KP_1, KeyCode::KP_1), std::make_pair(SDLK_KP_2, KeyCode::KP_2),
        std::make_pair(SDLK_KP_3, KeyCode::KP_3), std::make_pair(SDLK_KP_4, KeyCode::KP_4),
        std::make_pair(SDLK_KP_5, KeyCode::KP_5), std::make_pair(SDLK_KP_6, KeyCode::KP_6),
        std::make_pair(SDLK_KP_7, KeyCode::KP_7), std::make_pair(SDLK_KP_8, KeyCode::KP_8),
        std::make_pair(SDLK_KP_9, KeyCode::KP_9), std::make_pair(SDLK_KP_0, KeyCode::KP_0),
        std::make_pair(SDLK_KP_PERIOD, KeyCode::KP_PERIOD), std::make_pair(SDLK_APPLICATION, KeyCode::APPLICATION),
        std::make_pair(SDLK_POWER, KeyCode::POWER), std::make_pair(SDLK_KP_EQUALS, KeyCode::KP_EQUALS),
        std::make_pair(SDLK_F13, KeyCode::F13), std::make_pair(SDLK_F14, KeyCode::F14),
        std::make_pair(SDLK_F15, KeyCode::F15), std::make_pair(SDLK_F16, KeyCode::F16),
        std::make_pair(SDLK_F17, KeyCode::F17), std::make_pair(SDLK_F18, KeyCode::F18),
        std::make_pair(SDLK_F19, KeyCode::F19), std::make_pair(SDLK_F20, KeyCode::F20),
        std::make_pair(SDLK_F21, KeyCode::F21), std::make_pair(SDLK_F22, KeyCode::F22),
        std::make_pair(SDLK_F23, KeyCode::F23), std::make_pair(SDLK_F24, KeyCode::F24),
        std::make_pair(SDLK_EXECUTE, KeyCode::EXECUTE), std::make_pair(SDLK_HELP, KeyCode::HELP),
        std::make_pair(SDLK_MENU, KeyCode::MENU), std::make_pair(SDLK_SELECT, KeyCode::SELECT),
        std::make_pair(SDLK_STOP, KeyCode::STOP), std::make_pair(SDLK_AGAIN, KeyCode::AGAIN),
        std::make_pair(SDLK_UNDO, KeyCode::UNDO), std::make_pair(SDLK_CUT, KeyCode::CUT),
        std::make_pair(SDLK_COPY, KeyCode::COPY), std::make_pair(SDLK_PASTE, KeyCode::PASTE),
        std::make_pair(SDLK_FIND, KeyCode::FIND), std::make_pair(SDLK_MUTE, KeyCode::MUTE),
        std::make_pair(SDLK_VOLUMEUP, KeyCode::VOLUMEUP), std::make_pair(SDLK_VOLUMEDOWN, KeyCode::VOLUMEDOWN),
        std::make_pair(SDLK_KP_COMMA, KeyCode::KP_COMMA), std::make_pair(SDLK_KP_EQUALSAS400, KeyCode::KP_EQUALSAS400),
        std::make_pair(SDLK_ALTERASE, KeyCode::ALTERASE), std::make_pair(SDLK_SYSREQ, KeyCode::SYSREQ),
        std::make_pair(SDLK_CANCEL, KeyCode::CANCEL), std::make_pair(SDLK_CLEAR, KeyCode::CLEAR),
        std::make_pair(SDLK_PRIOR, KeyCode::PRIOR), std::make_pair(SDLK_RETURN2, KeyCode::RETURN2),
        std::make_pair(SDLK_SEPARATOR, KeyCode::SEPARATOR), std::make_pair(SDLK_OUT, KeyCode::OUT),
        std::make_pair(SDLK_OPER, KeyCode::OPER), std::make_pair(SDLK_CLEARAGAIN, KeyCode::CLEARAGAIN),
        std::make_pair(SDLK_CRSEL, KeyCode::CRSEL), std::make_pair(SDLK_EXSEL, KeyCode::EXSEL),
        std::make_pair(SDLK_KP_00, KeyCode::KP_00), std::make_pair(SDLK_KP_000, KeyCode::KP_000),
        std::make_pair(SDLK_THOUSANDSSEPARATOR, KeyCode::THOUSANDSSEPARATOR),
        std::make_pair(SDLK_DECIMALSEPARATOR, KeyCode::DECIMALSEPARATOR),
        std::make_pair(SDLK_CURRENCYUNIT, KeyCode::CURRENCYUNIT),
        std::make_pair(SDLK_CURRENCYSUBUNIT, KeyCode::CURRENCYSUBUNIT),
        std::make_pair(SDLK_KP_LEFTPAREN, KeyCode::KP_LEFTPAREN),
        std::make_pair(SDLK_KP_RIGHTPAREN, KeyCode::KP_RIGHTPAREN),
        std::make_pair(SDLK_KP_LEFTBRACE, KeyCode::KP_LEFTBRACE),
        std::make_pair(SDLK_KP_RIGHTBRACE, KeyCode::KP_RIGHTBRACE), std::make_pair(SDLK_KP_TAB, KeyCode::KP_TAB),
        std::make_pair(SDLK_KP_BACKSPACE, KeyCode::KP_BACKSPACE), std::make_pair(SDLK_KP_A, KeyCode::KP_A),
        std::make_pair(SDLK_KP_B, KeyCode::KP_B), std::make_pair(SDLK_KP_C, KeyCode::KP_C),
        std::make_pair(SDLK_KP_D, KeyCode::KP_D), std::make_pair(SDLK_KP_E, KeyCode::KP_E),
        std::make_pair(SDLK_KP_F, KeyCode::KP_F), std::make_pair(SDLK_KP_XOR, KeyCode::KP_XOR),
        std::make_pair(SDLK_KP_POWER, KeyCode::KP_POWER), std::make_pair(SDLK_KP_PERCENT, KeyCode::KP_PERCENT),
        std::make_pair(SDLK_KP_LESS, KeyCode::KP_LESS), std::make_pair(SDLK_KP_GREATER, KeyCode::KP_GREATER),
        std::make_pair(SDLK_KP_AMPERSAND, KeyCode::KP_AMPERSAND),
        std::make_pair(SDLK_KP_DBLAMPERSAND, KeyCode::KP_DBLAMPERSAND),
        std::make_pair(SDLK_KP_VERTICALBAR, KeyCode::KP_VERTICALBAR),
        std::make_pair(SDLK_KP_DBLVERTICALBAR, KeyCode::KP_DBLVERTICALBAR),
        std::make_pair(SDLK_KP_COLON, KeyCode::KP_COLON), std::make_pair(SDLK_KP_HASH, KeyCode::KP_HASH),
        std::make_pair(SDLK_KP_SPACE, KeyCode::KP_SPACE), std::make_pair(SDLK_KP_AT, KeyCode::KP_AT),
        std::make_pair(SDLK_KP_EXCLAM, KeyCode::KP_EXCLAM), std::make_pair(SDLK_KP_MEMSTORE, KeyCode::KP_MEMSTORE),
        std::make_pair(SDLK_KP_MEMRECALL, KeyCode::KP_MEMRECALL),
        std::make_pair(SDLK_KP_MEMCLEAR, KeyCode::KP_MEMCLEAR), std::make_pair(SDLK_KP_MEMADD, KeyCode::KP_MEMADD),
        std::make_pair(SDLK_KP_MEMSUBTRACT, KeyCode::KP_MEMSUBTRACT),
        std::make_pair(SDLK_KP_MEMMULTIPLY, KeyCode::KP_MEMMULTIPLY),
        std::make_pair(SDLK_KP_MEMDIVIDE, KeyCode::KP_MEMDIVIDE),
        std::make_pair(SDLK_KP_PLUSMINUS, KeyCode::KP_PLUSMINUS), std::make_pair(SDLK_KP_CLEAR, KeyCode::KP_CLEAR),
        std::make_pair(SDLK_KP_CLEARENTRY, KeyCode::KP_CLEARENTRY), std::make_pair(SDLK_KP_BINARY, KeyCode::KP_BINARY),
        std::make_pair(SDLK_KP_OCTAL, KeyCode::KP_OCTAL), std::make_pair(SDLK_KP_DECIMAL, KeyCode::KP_DECIMAL),
        std::make_pair(SDLK_KP_HEXADECIMAL, KeyCode::KP_HEXADECIMAL), std::make_pair(SDLK_LCTRL, KeyCode::LCTRL),
        std::make_pair(SDLK_LSHIFT, KeyCode::LSHIFT), std::make_pair(SDLK_LALT, KeyCode::LALT),
        std::make_pair(SDLK_LGUI, KeyCode::LGUI), std::make_pair(SDLK_RCTRL, KeyCode::RCTRL),
        std::make_pair(SDLK_RSHIFT, KeyCode::RSHIFT), std::make_pair(SDLK_RALT, KeyCode::RALT),
        std::make_pair(SDLK_RGUI, KeyCode::RGUI), std::make_pair(SDLK_MODE, KeyCode::MODE),
        std::make_pair(SDLK_AUDIONEXT, KeyCode::AUDIONEXT), std::make_pair(SDLK_AUDIOPREV, KeyCode::AUDIOPREV),
        std::make_pair(SDLK_AUDIOSTOP, KeyCode::AUDIOSTOP), std::make_pair(SDLK_AUDIOPLAY, KeyCode::AUDIOPLAY),
        std::make_pair(SDLK_AUDIOMUTE, KeyCode::AUDIOMUTE), std::make_pair(SDLK_MEDIASELECT, KeyCode::MEDIASELECT),
        std::make_pair(SDLK_WWW, KeyCode::WWW), std::make_pair(SDLK_MAIL, KeyCode::MAIL),
        std::make_pair(SDLK_CALCULATOR, KeyCode::CALCULATOR), std::make_pair(SDLK_COMPUTER, KeyCode::COMPUTER),
        std::make_pair(SDLK_AC_SEARCH, KeyCode::AC_SEARCH), std::make_pair(SDLK_AC_HOME, KeyCode::AC_HOME),
        std::make_pair(SDLK_AC_BACK, KeyCode::AC_BACK), std::make_pair(SDLK_AC_FORWARD, KeyCode::AC_FORWARD),
        std::make_pair(SDLK_AC_STOP, KeyCode::AC_STOP), std::make_pair(SDLK_AC_REFRESH, KeyCode::AC_REFRESH),
        std::make_pair(SDLK_AC_BOOKMARKS, KeyCode::AC_BOOKMARKS),
        std::make_pair(SDLK_BRIGHTNESSDOWN, KeyCode::BRIGHTNESSDOWN),
        std::make_pair(SDLK_BRIGHTNESSUP, KeyCode::BRIGHTNESSUP),
        std::make_pair(SDLK_DISPLAYSWITCH, KeyCode::DISPLAYSWITCH),
        std::make_pair(SDLK_KBDILLUMTOGGLE, KeyCode::KBDILLUMTOGGLE),
        std::make_pair(SDLK_KBDILLUMDOWN, KeyCode::KBDILLUMDOWN), std::make_pair(SDLK_KBDILLUMUP, KeyCode::KBDILLUMUP),
        std::make_pair(SDLK_EJECT, KeyCode::EJECT), std::make_pair(SDLK_SLEEP, KeyCode::SLEEP),
        std::make_pair(SDLK_APP1, KeyCode::APP1), std::make_pair(SDLK_APP2, KeyCode::APP2),
        std::make_pair(SDLK_AUDIOREWIND, KeyCode::AUDIOREWIND),
        std::make_pair(SDLK_AUDIOFASTFORWARD, KeyCode::AUDIOFASTFORWARD),
        std::make_pair(SDLK_SOFTLEFT, KeyCode::SOFTLEFT), std::make_pair(SDLK_SOFTRIGHT, KeyCode::SOFTRIGHT),
        std::make_pair(SDLK_CALL, KeyCode::CALL), std::make_pair(SDLK_ENDCALL, KeyCode::ENDCALL)));

TEST_P(InputManagerParameterizedTestFixture, handlesKeyDown) {
    // Arrange
    auto [sdlKeyCode, nutraKeyCode] = GetParam();
    SDL_Event event;
    event.type           = SDL_KEYDOWN;
    event.key.keysym.sym = sdlKeyCode;

    // Act
    inputManager->updateState(event);

    // Assert
    ASSERT_TRUE(inputManager->getCurrentState().getKeyboardInputState().isKeyDown(nutraKeyCode));
}

TEST_P(InputManagerParameterizedTestFixture, handlesKeyUp) {
    // Arrange
    auto [sdlKeyCode, nutraKeyCode] = GetParam();
    SDL_Event downEvent;
    downEvent.type           = SDL_KEYDOWN;
    downEvent.key.keysym.sym = sdlKeyCode;
    inputManager->updateState(downEvent);
    SDL_Event upEvent;
    upEvent.type           = SDL_KEYUP;
    upEvent.key.keysym.sym = sdlKeyCode;

    // Act
    inputManager->updateState(upEvent);

    // Assert
    ASSERT_FALSE(inputManager->getCurrentState().getKeyboardInputState().isKeyDown(nutraKeyCode));
}