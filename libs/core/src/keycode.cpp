#include "keycode.hpp"

#include <stdexcept>

Nutra::Core::KeyCode Nutra::Core::convertSDLKeyCodeToNutraKeyCode(SDL_Keycode & sdlKeyCode) {
    switch (sdlKeyCode) {
    case SDLK_UNKNOWN:
        return Nutra::Core::KeyCode::UNKNOWN;
        break;
    case SDLK_RETURN:
        return Nutra::Core::KeyCode::RETURN;
        break;
    case SDLK_ESCAPE:
        return Nutra::Core::KeyCode::ESCAPE;
        break;
    case SDLK_BACKSPACE:
        return Nutra::Core::KeyCode::BACKSPACE;
        break;
    case SDLK_TAB:
        return Nutra::Core::KeyCode::TAB;
        break;
    case SDLK_SPACE:
        return Nutra::Core::KeyCode::SPACE;
        break;
    case SDLK_EXCLAIM:
        return Nutra::Core::KeyCode::EXCLAIM;
        break;
    case SDLK_QUOTEDBL:
        return Nutra::Core::KeyCode::QUOTEDBL;
        break;
    case SDLK_HASH:
        return Nutra::Core::KeyCode::HASH;
        break;
    case SDLK_PERCENT:
        return Nutra::Core::KeyCode::PERCENT;
        break;
    case SDLK_DOLLAR:
        return Nutra::Core::KeyCode::DOLLAR;
        break;
    case SDLK_AMPERSAND:
        return Nutra::Core::KeyCode::AMPERSAND;
        break;
    case SDLK_QUOTE:
        return Nutra::Core::KeyCode::QUOTE;
        break;
    case SDLK_LEFTPAREN:
        return Nutra::Core::KeyCode::LEFTPAREN;
        break;
    case SDLK_RIGHTPAREN:
        return Nutra::Core::KeyCode::RIGHTPAREN;
        break;
    case SDLK_ASTERISK:
        return Nutra::Core::KeyCode::ASTERISK;
        break;
    case SDLK_PLUS:
        return Nutra::Core::KeyCode::PLUS;
        break;
    case SDLK_COMMA:
        return Nutra::Core::KeyCode::COMMA;
        break;
    case SDLK_MINUS:
        return Nutra::Core::KeyCode::MINUS;
        break;
    case SDLK_PERIOD:
        return Nutra::Core::KeyCode::PERIOD;
        break;
    case SDLK_SLASH:
        return Nutra::Core::KeyCode::SLASH;
        break;
    case SDLK_0:
        return Nutra::Core::KeyCode::ZERO;
        break;
    case SDLK_1:
        return Nutra::Core::KeyCode::ONE;
        break;
    case SDLK_2:
        return Nutra::Core::KeyCode::TWO;
        break;
    case SDLK_3:
        return Nutra::Core::KeyCode::THREE;
        break;
    case SDLK_4:
        return Nutra::Core::KeyCode::FOUR;
        break;
    case SDLK_5:
        return Nutra::Core::KeyCode::FIVE;
        break;
    case SDLK_6:
        return Nutra::Core::KeyCode::SIX;
        break;
    case SDLK_7:
        return Nutra::Core::KeyCode::SEVEN;
        break;
    case SDLK_8:
        return Nutra::Core::KeyCode::EIGHT;
        break;
    case SDLK_9:
        return Nutra::Core::KeyCode::NINE;
        break;
    case SDLK_COLON:
        return Nutra::Core::KeyCode::COLON;
        break;
    case SDLK_SEMICOLON:
        return Nutra::Core::KeyCode::SEMICOLON;
        break;
    case SDLK_LESS:
        return Nutra::Core::KeyCode::LESS;
        break;
    case SDLK_EQUALS:
        return Nutra::Core::KeyCode::EQUALS;
        break;
    case SDLK_GREATER:
        return Nutra::Core::KeyCode::GREATER;
        break;
    case SDLK_QUESTION:
        return Nutra::Core::KeyCode::QUESTION;
        break;
    case SDLK_AT:
        return Nutra::Core::KeyCode::AT;
        break;
    case SDLK_LEFTBRACKET:
        return Nutra::Core::KeyCode::LEFTBRACKET;
        break;
    case SDLK_BACKSLASH:
        return Nutra::Core::KeyCode::BACKSLASH;
        break;
    case SDLK_RIGHTBRACKET:
        return Nutra::Core::KeyCode::RIGHTBRACKET;
        break;
    case SDLK_CARET:
        return Nutra::Core::KeyCode::CARET;
        break;
    case SDLK_UNDERSCORE:
        return Nutra::Core::KeyCode::UNDERSCORE;
        break;
    case SDLK_BACKQUOTE:
        return Nutra::Core::KeyCode::BACKQUOTE;
        break;
    case SDLK_a:
        return Nutra::Core::KeyCode::A;
        break;
    case SDLK_b:
        return Nutra::Core::KeyCode::B;
        break;
    case SDLK_c:
        return Nutra::Core::KeyCode::C;
        break;
    case SDLK_d:
        return Nutra::Core::KeyCode::D;
        break;
    case SDLK_e:
        return Nutra::Core::KeyCode::E;
        break;
    case SDLK_f:
        return Nutra::Core::KeyCode::F;
        break;
    case SDLK_g:
        return Nutra::Core::KeyCode::G;
        break;
    case SDLK_h:
        return Nutra::Core::KeyCode::H;
        break;
    case SDLK_i:
        return Nutra::Core::KeyCode::I;
        break;
    case SDLK_j:
        return Nutra::Core::KeyCode::J;
        break;
    case SDLK_k:
        return Nutra::Core::KeyCode::K;
        break;
    case SDLK_l:
        return Nutra::Core::KeyCode::L;
        break;
    case SDLK_m:
        return Nutra::Core::KeyCode::M;
        break;
    case SDLK_n:
        return Nutra::Core::KeyCode::N;
        break;
    case SDLK_o:
        return Nutra::Core::KeyCode::O;
        break;
    case SDLK_p:
        return Nutra::Core::KeyCode::P;
        break;
    case SDLK_q:
        return Nutra::Core::KeyCode::Q;
        break;
    case SDLK_r:
        return Nutra::Core::KeyCode::R;
        break;
    case SDLK_s:
        return Nutra::Core::KeyCode::S;
        break;
    case SDLK_t:
        return Nutra::Core::KeyCode::T;
        break;
    case SDLK_u:
        return Nutra::Core::KeyCode::U;
        break;
    case SDLK_v:
        return Nutra::Core::KeyCode::V;
        break;
    case SDLK_w:
        return Nutra::Core::KeyCode::W;
        break;
    case SDLK_x:
        return Nutra::Core::KeyCode::X;
        break;
    case SDLK_y:
        return Nutra::Core::KeyCode::Y;
        break;
    case SDLK_z:
        return Nutra::Core::KeyCode::Z;
        break;
    case SDLK_CAPSLOCK:
        return Nutra::Core::KeyCode::CAPSLOCK;
        break;
    case SDLK_F1:
        return Nutra::Core::KeyCode::F1;
        break;
    case SDLK_F2:
        return Nutra::Core::KeyCode::F2;
        break;
    case SDLK_F3:
        return Nutra::Core::KeyCode::F3;
        break;
    case SDLK_F4:
        return Nutra::Core::KeyCode::F4;
        break;
    case SDLK_F5:
        return Nutra::Core::KeyCode::F5;
        break;
    case SDLK_F6:
        return Nutra::Core::KeyCode::F6;
        break;
    case SDLK_F7:
        return Nutra::Core::KeyCode::F7;
        break;
    case SDLK_F8:
        return Nutra::Core::KeyCode::F8;
        break;
    case SDLK_F9:
        return Nutra::Core::KeyCode::F9;
        break;
    case SDLK_F10:
        return Nutra::Core::KeyCode::F10;
        break;
    case SDLK_F11:
        return Nutra::Core::KeyCode::F11;
        break;
    case SDLK_F12:
        return Nutra::Core::KeyCode::F12;
        break;
    case SDLK_PRINTSCREEN:
        return Nutra::Core::KeyCode::PRINTSCREEN;
        break;
    case SDLK_SCROLLLOCK:
        return Nutra::Core::KeyCode::SCROLLLOCK;
        break;
    case SDLK_PAUSE:
        return Nutra::Core::KeyCode::PAUSE;
        break;
    case SDLK_INSERT:
        return Nutra::Core::KeyCode::INSERT;
        break;
    case SDLK_HOME:
        return Nutra::Core::KeyCode::HOME;
        break;
    case SDLK_PAGEUP:
        return Nutra::Core::KeyCode::PAGEUP;
        break;
    case SDLK_DELETE:
        return Nutra::Core::KeyCode::DELETE;
        break;
    case SDLK_END:
        return Nutra::Core::KeyCode::END;
        break;
    case SDLK_PAGEDOWN:
        return Nutra::Core::KeyCode::PAGEDOWN;
        break;
    case SDLK_RIGHT:
        return Nutra::Core::KeyCode::RIGHT;
        break;
    case SDLK_LEFT:
        return Nutra::Core::KeyCode::LEFT;
        break;
    case SDLK_DOWN:
        return Nutra::Core::KeyCode::DOWN;
        break;
    case SDLK_UP:
        return Nutra::Core::KeyCode::UP;
        break;
    case SDLK_NUMLOCKCLEAR:
        return Nutra::Core::KeyCode::NUMLOCKCLEAR;
        break;
    case SDLK_KP_DIVIDE:
        return Nutra::Core::KeyCode::KP_DIVIDE;
        break;
    case SDLK_KP_MULTIPLY:
        return Nutra::Core::KeyCode::KP_MULTIPLY;
        break;
    case SDLK_KP_MINUS:
        return Nutra::Core::KeyCode::KP_MINUS;
        break;
    case SDLK_KP_PLUS:
        return Nutra::Core::KeyCode::KP_PLUS;
        break;
    case SDLK_KP_ENTER:
        return Nutra::Core::KeyCode::KP_ENTER;
        break;
    case SDLK_KP_1:
        return Nutra::Core::KeyCode::KP_1;
        break;
    case SDLK_KP_2:
        return Nutra::Core::KeyCode::KP_2;
        break;
    case SDLK_KP_3:
        return Nutra::Core::KeyCode::KP_3;
        break;
    case SDLK_KP_4:
        return Nutra::Core::KeyCode::KP_4;
        break;
    case SDLK_KP_5:
        return Nutra::Core::KeyCode::KP_5;
        break;
    case SDLK_KP_6:
        return Nutra::Core::KeyCode::KP_6;
        break;
    case SDLK_KP_7:
        return Nutra::Core::KeyCode::KP_7;
        break;
    case SDLK_KP_8:
        return Nutra::Core::KeyCode::KP_8;
        break;
    case SDLK_KP_9:
        return Nutra::Core::KeyCode::KP_9;
        break;
    case SDLK_KP_0:
        return Nutra::Core::KeyCode::KP_0;
        break;
    case SDLK_KP_PERIOD:
        return Nutra::Core::KeyCode::KP_PERIOD;
        break;
    case SDLK_APPLICATION:
        return Nutra::Core::KeyCode::APPLICATION;
        break;
    case SDLK_POWER:
        return Nutra::Core::KeyCode::POWER;
        break;
    case SDLK_KP_EQUALS:
        return Nutra::Core::KeyCode::KP_EQUALS;
        break;
    case SDLK_F13:
        return Nutra::Core::KeyCode::F13;
        break;
    case SDLK_F14:
        return Nutra::Core::KeyCode::F14;
        break;
    case SDLK_F15:
        return Nutra::Core::KeyCode::F15;
        break;
    case SDLK_F16:
        return Nutra::Core::KeyCode::F16;
        break;
    case SDLK_F17:
        return Nutra::Core::KeyCode::F17;
        break;
    case SDLK_F18:
        return Nutra::Core::KeyCode::F18;
        break;
    case SDLK_F19:
        return Nutra::Core::KeyCode::F19;
        break;
    case SDLK_F20:
        return Nutra::Core::KeyCode::F20;
        break;
    case SDLK_F21:
        return Nutra::Core::KeyCode::F21;
        break;
    case SDLK_F22:
        return Nutra::Core::KeyCode::F22;
        break;
    case SDLK_F23:
        return Nutra::Core::KeyCode::F23;
        break;
    case SDLK_F24:
        return Nutra::Core::KeyCode::F24;
        break;
    case SDLK_EXECUTE:
        return Nutra::Core::KeyCode::EXECUTE;
        break;
    case SDLK_HELP:
        return Nutra::Core::KeyCode::HELP;
        break;
    case SDLK_MENU:
        return Nutra::Core::KeyCode::MENU;
        break;
    case SDLK_SELECT:
        return Nutra::Core::KeyCode::SELECT;
        break;
    case SDLK_STOP:
        return Nutra::Core::KeyCode::STOP;
        break;
    case SDLK_AGAIN:
        return Nutra::Core::KeyCode::AGAIN;
        break;
    case SDLK_UNDO:
        return Nutra::Core::KeyCode::UNDO;
        break;
    case SDLK_CUT:
        return Nutra::Core::KeyCode::CUT;
        break;
    case SDLK_COPY:
        return Nutra::Core::KeyCode::COPY;
        break;
    case SDLK_PASTE:
        return Nutra::Core::KeyCode::PASTE;
        break;
    case SDLK_FIND:
        return Nutra::Core::KeyCode::FIND;
        break;
    case SDLK_MUTE:
        return Nutra::Core::KeyCode::MUTE;
        break;
    case SDLK_VOLUMEUP:
        return Nutra::Core::KeyCode::VOLUMEUP;
        break;
    case SDLK_VOLUMEDOWN:
        return Nutra::Core::KeyCode::VOLUMEDOWN;
        break;
    case SDLK_KP_COMMA:
        return Nutra::Core::KeyCode::KP_COMMA;
        break;
    case SDLK_KP_EQUALSAS400:
        return Nutra::Core::KeyCode::KP_EQUALSAS400;
        break;
    case SDLK_ALTERASE:
        return Nutra::Core::KeyCode::ALTERASE;
        break;
    case SDLK_SYSREQ:
        return Nutra::Core::KeyCode::SYSREQ;
        break;
    case SDLK_CANCEL:
        return Nutra::Core::KeyCode::CANCEL;
        break;
    case SDLK_CLEAR:
        return Nutra::Core::KeyCode::CLEAR;
        break;
    case SDLK_PRIOR:
        return Nutra::Core::KeyCode::PRIOR;
        break;
    case SDLK_RETURN2:
        return Nutra::Core::KeyCode::RETURN2;
        break;
    case SDLK_SEPARATOR:
        return Nutra::Core::KeyCode::SEPARATOR;
        break;
    case SDLK_OUT:
        return Nutra::Core::KeyCode::OUT;
        break;
    case SDLK_OPER:
        return Nutra::Core::KeyCode::OPER;
        break;
    case SDLK_CLEARAGAIN:
        return Nutra::Core::KeyCode::CLEARAGAIN;
        break;
    case SDLK_CRSEL:
        return Nutra::Core::KeyCode::CRSEL;
        break;
    case SDLK_EXSEL:
        return Nutra::Core::KeyCode::EXSEL;
        break;
    case SDLK_KP_00:
        return Nutra::Core::KeyCode::KP_00;
        break;
    case SDLK_KP_000:
        return Nutra::Core::KeyCode::KP_000;
        break;
    case SDLK_THOUSANDSSEPARATOR:
        return Nutra::Core::KeyCode::THOUSANDSSEPARATOR;
        break;
    case SDLK_DECIMALSEPARATOR:
        return Nutra::Core::KeyCode::DECIMALSEPARATOR;
        break;
    case SDLK_CURRENCYUNIT:
        return Nutra::Core::KeyCode::CURRENCYUNIT;
        break;
    case SDLK_CURRENCYSUBUNIT:
        return Nutra::Core::KeyCode::CURRENCYSUBUNIT;
        break;
    case SDLK_KP_LEFTPAREN:
        return Nutra::Core::KeyCode::KP_LEFTPAREN;
        break;
    case SDLK_KP_RIGHTPAREN:
        return Nutra::Core::KeyCode::KP_RIGHTPAREN;
        break;
    case SDLK_KP_LEFTBRACE:
        return Nutra::Core::KeyCode::KP_LEFTBRACE;
        break;
    case SDLK_KP_RIGHTBRACE:
        return Nutra::Core::KeyCode::KP_RIGHTBRACE;
        break;
    case SDLK_KP_TAB:
        return Nutra::Core::KeyCode::KP_TAB;
        break;
    case SDLK_KP_BACKSPACE:
        return Nutra::Core::KeyCode::KP_BACKSPACE;
        break;
    case SDLK_KP_A:
        return Nutra::Core::KeyCode::KP_A;
        break;
    case SDLK_KP_B:
        return Nutra::Core::KeyCode::KP_B;
        break;
    case SDLK_KP_C:
        return Nutra::Core::KeyCode::KP_C;
        break;
    case SDLK_KP_D:
        return Nutra::Core::KeyCode::KP_D;
        break;
    case SDLK_KP_E:
        return Nutra::Core::KeyCode::KP_E;
        break;
    case SDLK_KP_F:
        return Nutra::Core::KeyCode::KP_F;
        break;
    case SDLK_KP_XOR:
        return Nutra::Core::KeyCode::KP_XOR;
        break;
    case SDLK_KP_POWER:
        return Nutra::Core::KeyCode::KP_POWER;
        break;
    case SDLK_KP_PERCENT:
        return Nutra::Core::KeyCode::KP_PERCENT;
        break;
    case SDLK_KP_LESS:
        return Nutra::Core::KeyCode::KP_LESS;
        break;
    case SDLK_KP_GREATER:
        return Nutra::Core::KeyCode::KP_GREATER;
        break;
    case SDLK_KP_AMPERSAND:
        return Nutra::Core::KeyCode::KP_AMPERSAND;
        break;
    case SDLK_KP_DBLAMPERSAND:
        return Nutra::Core::KeyCode::KP_DBLAMPERSAND;
        break;
    case SDLK_KP_VERTICALBAR:
        return Nutra::Core::KeyCode::KP_VERTICALBAR;
        break;
    case SDLK_KP_DBLVERTICALBAR:
        return Nutra::Core::KeyCode::KP_DBLVERTICALBAR;
        break;
    case SDLK_KP_COLON:
        return Nutra::Core::KeyCode::KP_COLON;
        break;
    case SDLK_KP_HASH:
        return Nutra::Core::KeyCode::KP_HASH;
        break;
    case SDLK_KP_SPACE:
        return Nutra::Core::KeyCode::KP_SPACE;
        break;
    case SDLK_KP_AT:
        return Nutra::Core::KeyCode::KP_AT;
        break;
    case SDLK_KP_EXCLAM:
        return Nutra::Core::KeyCode::KP_EXCLAM;
        break;
    case SDLK_KP_MEMSTORE:
        return Nutra::Core::KeyCode::KP_MEMSTORE;
        break;
    case SDLK_KP_MEMRECALL:
        return Nutra::Core::KeyCode::KP_MEMRECALL;
        break;
    case SDLK_KP_MEMCLEAR:
        return Nutra::Core::KeyCode::KP_MEMCLEAR;
        break;
    case SDLK_KP_MEMADD:
        return Nutra::Core::KeyCode::KP_MEMADD;
        break;
    case SDLK_KP_MEMSUBTRACT:
        return Nutra::Core::KeyCode::KP_MEMSUBTRACT;
        break;
    case SDLK_KP_MEMMULTIPLY:
        return Nutra::Core::KeyCode::KP_MEMMULTIPLY;
        break;
    case SDLK_KP_MEMDIVIDE:
        return Nutra::Core::KeyCode::KP_MEMDIVIDE;
        break;
    case SDLK_KP_PLUSMINUS:
        return Nutra::Core::KeyCode::KP_PLUSMINUS;
        break;
    case SDLK_KP_CLEAR:
        return Nutra::Core::KeyCode::KP_CLEAR;
        break;
    case SDLK_KP_CLEARENTRY:
        return Nutra::Core::KeyCode::KP_CLEARENTRY;
        break;
    case SDLK_KP_BINARY:
        return Nutra::Core::KeyCode::KP_BINARY;
        break;
    case SDLK_KP_OCTAL:
        return Nutra::Core::KeyCode::KP_OCTAL;
        break;
    case SDLK_KP_DECIMAL:
        return Nutra::Core::KeyCode::KP_DECIMAL;
        break;
    case SDLK_KP_HEXADECIMAL:
        return Nutra::Core::KeyCode::KP_HEXADECIMAL;
        break;
    case SDLK_LCTRL:
        return Nutra::Core::KeyCode::LCTRL;
        break;
    case SDLK_LSHIFT:
        return Nutra::Core::KeyCode::LSHIFT;
        break;
    case SDLK_LALT:
        return Nutra::Core::KeyCode::LALT;
        break;
    case SDLK_LGUI:
        return Nutra::Core::KeyCode::LGUI;
        break;
    case SDLK_RCTRL:
        return Nutra::Core::KeyCode::RCTRL;
        break;
    case SDLK_RSHIFT:
        return Nutra::Core::KeyCode::RSHIFT;
        break;
    case SDLK_RALT:
        return Nutra::Core::KeyCode::RALT;
        break;
    case SDLK_RGUI:
        return Nutra::Core::KeyCode::RGUI;
        break;
    case SDLK_MODE:
        return Nutra::Core::KeyCode::MODE;
        break;
    case SDLK_AUDIONEXT:
        return Nutra::Core::KeyCode::AUDIONEXT;
        break;
    case SDLK_AUDIOPREV:
        return Nutra::Core::KeyCode::AUDIOPREV;
        break;
    case SDLK_AUDIOSTOP:
        return Nutra::Core::KeyCode::AUDIOSTOP;
        break;
    case SDLK_AUDIOPLAY:
        return Nutra::Core::KeyCode::AUDIOPLAY;
        break;
    case SDLK_AUDIOMUTE:
        return Nutra::Core::KeyCode::AUDIOMUTE;
        break;
    case SDLK_MEDIASELECT:
        return Nutra::Core::KeyCode::MEDIASELECT;
        break;
    case SDLK_WWW:
        return Nutra::Core::KeyCode::WWW;
        break;
    case SDLK_MAIL:
        return Nutra::Core::KeyCode::MAIL;
        break;
    case SDLK_CALCULATOR:
        return Nutra::Core::KeyCode::CALCULATOR;
        break;
    case SDLK_COMPUTER:
        return Nutra::Core::KeyCode::COMPUTER;
        break;
    case SDLK_AC_SEARCH:
        return Nutra::Core::KeyCode::AC_SEARCH;
        break;
    case SDLK_AC_HOME:
        return Nutra::Core::KeyCode::AC_HOME;
        break;
    case SDLK_AC_BACK:
        return Nutra::Core::KeyCode::AC_BACK;
        break;
    case SDLK_AC_FORWARD:
        return Nutra::Core::KeyCode::AC_FORWARD;
        break;
    case SDLK_AC_STOP:
        return Nutra::Core::KeyCode::AC_STOP;
        break;
    case SDLK_AC_REFRESH:
        return Nutra::Core::KeyCode::AC_REFRESH;
        break;
    case SDLK_AC_BOOKMARKS:
        return Nutra::Core::KeyCode::AC_BOOKMARKS;
        break;
    case SDLK_BRIGHTNESSDOWN:
        return Nutra::Core::KeyCode::BRIGHTNESSDOWN;
        break;
    case SDLK_BRIGHTNESSUP:
        return Nutra::Core::KeyCode::BRIGHTNESSUP;
        break;
    case SDLK_DISPLAYSWITCH:
        return Nutra::Core::KeyCode::DISPLAYSWITCH;
        break;
    case SDLK_KBDILLUMTOGGLE:
        return Nutra::Core::KeyCode::KBDILLUMTOGGLE;
        break;
    case SDLK_KBDILLUMDOWN:
        return Nutra::Core::KeyCode::KBDILLUMDOWN;
        break;
    case SDLK_KBDILLUMUP:
        return Nutra::Core::KeyCode::KBDILLUMUP;
        break;
    case SDLK_EJECT:
        return Nutra::Core::KeyCode::EJECT;
        break;
    case SDLK_SLEEP:
        return Nutra::Core::KeyCode::SLEEP;
        break;
    case SDLK_APP1:
        return Nutra::Core::KeyCode::APP1;
        break;
    case SDLK_APP2:
        return Nutra::Core::KeyCode::APP2;
        break;
    case SDLK_AUDIOREWIND:
        return Nutra::Core::KeyCode::AUDIOREWIND;
        break;
    case SDLK_AUDIOFASTFORWARD:
        return Nutra::Core::KeyCode::AUDIOFASTFORWARD;
        break;
    case SDLK_SOFTLEFT:
        return Nutra::Core::KeyCode::SOFTLEFT;
        break;
    case SDLK_SOFTRIGHT:
        return Nutra::Core::KeyCode::SOFTRIGHT;
        break;
    case SDLK_CALL:
        return Nutra::Core::KeyCode::CALL;
        break;
    case SDLK_ENDCALL:
        return Nutra::Core::KeyCode::ENDCALL;
        break;

    default:
        throw std::runtime_error("Unhandled SDL_Nutra::Core::KeyCode");
    }
}

Nutra::Core::KeyCode Nutra::Core::convertSDLMouseButtonToNutraKeyCode(uint8_t mouseButtonIndex) {
    switch (mouseButtonIndex) {
    case SDL_BUTTON_LEFT:
        return Nutra::Core::KeyCode::MOUSE_BUTTON_LEFT;
        break;
    case SDL_BUTTON_MIDDLE:
        return Nutra::Core::KeyCode::MOUSE_BUTTON_MIDDLE;
        break;
    case SDL_BUTTON_RIGHT:
        return Nutra::Core::KeyCode::MOUSE_BUTTON_RIGHT;
        break;

    default:
        throw std::runtime_error("Unhandled SDL_Nutra::Core::KeyCode");
    }
}