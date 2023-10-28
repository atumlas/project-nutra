#include "keycode.hpp"

#include <stdexcept>

auto Nutra::Core::convertSDLKeyCodeToNutraKeyCode(SDL_Keycode & sdlKeyCode) -> Nutra::Core::KEYCODE {
    switch (sdlKeyCode) {
    case SDLK_UNKNOWN:
        return Nutra::Core::KEYCODE::UNKNOWN;
        break;
    case SDLK_RETURN:
        return Nutra::Core::KEYCODE::RETURN;
        break;
    case SDLK_ESCAPE:
        return Nutra::Core::KEYCODE::ESCAPE;
        break;
    case SDLK_BACKSPACE:
        return Nutra::Core::KEYCODE::BACKSPACE;
        break;
    case SDLK_TAB:
        return Nutra::Core::KEYCODE::TAB;
        break;
    case SDLK_SPACE:
        return Nutra::Core::KEYCODE::SPACE;
        break;
    case SDLK_EXCLAIM:
        return Nutra::Core::KEYCODE::EXCLAIM;
        break;
    case SDLK_QUOTEDBL:
        return Nutra::Core::KEYCODE::QUOTEDBL;
        break;
    case SDLK_HASH:
        return Nutra::Core::KEYCODE::HASH;
        break;
    case SDLK_PERCENT:
        return Nutra::Core::KEYCODE::PERCENT;
        break;
    case SDLK_DOLLAR:
        return Nutra::Core::KEYCODE::DOLLAR;
        break;
    case SDLK_AMPERSAND:
        return Nutra::Core::KEYCODE::AMPERSAND;
        break;
    case SDLK_QUOTE:
        return Nutra::Core::KEYCODE::QUOTE;
        break;
    case SDLK_LEFTPAREN:
        return Nutra::Core::KEYCODE::LEFTPAREN;
        break;
    case SDLK_RIGHTPAREN:
        return Nutra::Core::KEYCODE::RIGHTPAREN;
        break;
    case SDLK_ASTERISK:
        return Nutra::Core::KEYCODE::ASTERISK;
        break;
    case SDLK_PLUS:
        return Nutra::Core::KEYCODE::PLUS;
        break;
    case SDLK_COMMA:
        return Nutra::Core::KEYCODE::COMMA;
        break;
    case SDLK_MINUS:
        return Nutra::Core::KEYCODE::MINUS;
        break;
    case SDLK_PERIOD:
        return Nutra::Core::KEYCODE::PERIOD;
        break;
    case SDLK_SLASH:
        return Nutra::Core::KEYCODE::SLASH;
        break;
    case SDLK_0:
        return Nutra::Core::KEYCODE::ZERO;
        break;
    case SDLK_1:
        return Nutra::Core::KEYCODE::ONE;
        break;
    case SDLK_2:
        return Nutra::Core::KEYCODE::TWO;
        break;
    case SDLK_3:
        return Nutra::Core::KEYCODE::THREE;
        break;
    case SDLK_4:
        return Nutra::Core::KEYCODE::FOUR;
        break;
    case SDLK_5:
        return Nutra::Core::KEYCODE::FIVE;
        break;
    case SDLK_6:
        return Nutra::Core::KEYCODE::SIX;
        break;
    case SDLK_7:
        return Nutra::Core::KEYCODE::SEVEN;
        break;
    case SDLK_8:
        return Nutra::Core::KEYCODE::EIGHT;
        break;
    case SDLK_9:
        return Nutra::Core::KEYCODE::NINE;
        break;
    case SDLK_COLON:
        return Nutra::Core::KEYCODE::COLON;
        break;
    case SDLK_SEMICOLON:
        return Nutra::Core::KEYCODE::SEMICOLON;
        break;
    case SDLK_LESS:
        return Nutra::Core::KEYCODE::LESS;
        break;
    case SDLK_EQUALS:
        return Nutra::Core::KEYCODE::EQUALS;
        break;
    case SDLK_GREATER:
        return Nutra::Core::KEYCODE::GREATER;
        break;
    case SDLK_QUESTION:
        return Nutra::Core::KEYCODE::QUESTION;
        break;
    case SDLK_AT:
        return Nutra::Core::KEYCODE::AT;
        break;
    case SDLK_LEFTBRACKET:
        return Nutra::Core::KEYCODE::LEFTBRACKET;
        break;
    case SDLK_BACKSLASH:
        return Nutra::Core::KEYCODE::BACKSLASH;
        break;
    case SDLK_RIGHTBRACKET:
        return Nutra::Core::KEYCODE::RIGHTBRACKET;
        break;
    case SDLK_CARET:
        return Nutra::Core::KEYCODE::CARET;
        break;
    case SDLK_UNDERSCORE:
        return Nutra::Core::KEYCODE::UNDERSCORE;
        break;
    case SDLK_BACKQUOTE:
        return Nutra::Core::KEYCODE::BACKQUOTE;
        break;
    case SDLK_a:
        return Nutra::Core::KEYCODE::A;
        break;
    case SDLK_b:
        return Nutra::Core::KEYCODE::B;
        break;
    case SDLK_c:
        return Nutra::Core::KEYCODE::C;
        break;
    case SDLK_d:
        return Nutra::Core::KEYCODE::D;
        break;
    case SDLK_e:
        return Nutra::Core::KEYCODE::E;
        break;
    case SDLK_f:
        return Nutra::Core::KEYCODE::F;
        break;
    case SDLK_g:
        return Nutra::Core::KEYCODE::G;
        break;
    case SDLK_h:
        return Nutra::Core::KEYCODE::H;
        break;
    case SDLK_i:
        return Nutra::Core::KEYCODE::I;
        break;
    case SDLK_j:
        return Nutra::Core::KEYCODE::J;
        break;
    case SDLK_k:
        return Nutra::Core::KEYCODE::K;
        break;
    case SDLK_l:
        return Nutra::Core::KEYCODE::L;
        break;
    case SDLK_m:
        return Nutra::Core::KEYCODE::M;
        break;
    case SDLK_n:
        return Nutra::Core::KEYCODE::N;
        break;
    case SDLK_o:
        return Nutra::Core::KEYCODE::O;
        break;
    case SDLK_p:
        return Nutra::Core::KEYCODE::P;
        break;
    case SDLK_q:
        return Nutra::Core::KEYCODE::Q;
        break;
    case SDLK_r:
        return Nutra::Core::KEYCODE::R;
        break;
    case SDLK_s:
        return Nutra::Core::KEYCODE::S;
        break;
    case SDLK_t:
        return Nutra::Core::KEYCODE::T;
        break;
    case SDLK_u:
        return Nutra::Core::KEYCODE::U;
        break;
    case SDLK_v:
        return Nutra::Core::KEYCODE::V;
        break;
    case SDLK_w:
        return Nutra::Core::KEYCODE::W;
        break;
    case SDLK_x:
        return Nutra::Core::KEYCODE::X;
        break;
    case SDLK_y:
        return Nutra::Core::KEYCODE::Y;
        break;
    case SDLK_z:
        return Nutra::Core::KEYCODE::Z;
        break;
    case SDLK_CAPSLOCK:
        return Nutra::Core::KEYCODE::CAPSLOCK;
        break;
    case SDLK_F1:
        return Nutra::Core::KEYCODE::F1;
        break;
    case SDLK_F2:
        return Nutra::Core::KEYCODE::F2;
        break;
    case SDLK_F3:
        return Nutra::Core::KEYCODE::F3;
        break;
    case SDLK_F4:
        return Nutra::Core::KEYCODE::F4;
        break;
    case SDLK_F5:
        return Nutra::Core::KEYCODE::F5;
        break;
    case SDLK_F6:
        return Nutra::Core::KEYCODE::F6;
        break;
    case SDLK_F7:
        return Nutra::Core::KEYCODE::F7;
        break;
    case SDLK_F8:
        return Nutra::Core::KEYCODE::F8;
        break;
    case SDLK_F9:
        return Nutra::Core::KEYCODE::F9;
        break;
    case SDLK_F10:
        return Nutra::Core::KEYCODE::F10;
        break;
    case SDLK_F11:
        return Nutra::Core::KEYCODE::F11;
        break;
    case SDLK_F12:
        return Nutra::Core::KEYCODE::F12;
        break;
    case SDLK_PRINTSCREEN:
        return Nutra::Core::KEYCODE::PRINTSCREEN;
        break;
    case SDLK_SCROLLLOCK:
        return Nutra::Core::KEYCODE::SCROLLLOCK;
        break;
    case SDLK_PAUSE:
        return Nutra::Core::KEYCODE::PAUSE;
        break;
    case SDLK_INSERT:
        return Nutra::Core::KEYCODE::INSERT;
        break;
    case SDLK_HOME:
        return Nutra::Core::KEYCODE::HOME;
        break;
    case SDLK_PAGEUP:
        return Nutra::Core::KEYCODE::PAGEUP;
        break;
    case SDLK_DELETE:
        return Nutra::Core::KEYCODE::DELETE;
        break;
    case SDLK_END:
        return Nutra::Core::KEYCODE::END;
        break;
    case SDLK_PAGEDOWN:
        return Nutra::Core::KEYCODE::PAGEDOWN;
        break;
    case SDLK_RIGHT:
        return Nutra::Core::KEYCODE::RIGHT;
        break;
    case SDLK_LEFT:
        return Nutra::Core::KEYCODE::LEFT;
        break;
    case SDLK_DOWN:
        return Nutra::Core::KEYCODE::DOWN;
        break;
    case SDLK_UP:
        return Nutra::Core::KEYCODE::UP;
        break;
    case SDLK_NUMLOCKCLEAR:
        return Nutra::Core::KEYCODE::NUMLOCKCLEAR;
        break;
    case SDLK_KP_DIVIDE:
        return Nutra::Core::KEYCODE::KP_DIVIDE;
        break;
    case SDLK_KP_MULTIPLY:
        return Nutra::Core::KEYCODE::KP_MULTIPLY;
        break;
    case SDLK_KP_MINUS:
        return Nutra::Core::KEYCODE::KP_MINUS;
        break;
    case SDLK_KP_PLUS:
        return Nutra::Core::KEYCODE::KP_PLUS;
        break;
    case SDLK_KP_ENTER:
        return Nutra::Core::KEYCODE::KP_ENTER;
        break;
    case SDLK_KP_1:
        return Nutra::Core::KEYCODE::KP_1;
        break;
    case SDLK_KP_2:
        return Nutra::Core::KEYCODE::KP_2;
        break;
    case SDLK_KP_3:
        return Nutra::Core::KEYCODE::KP_3;
        break;
    case SDLK_KP_4:
        return Nutra::Core::KEYCODE::KP_4;
        break;
    case SDLK_KP_5:
        return Nutra::Core::KEYCODE::KP_5;
        break;
    case SDLK_KP_6:
        return Nutra::Core::KEYCODE::KP_6;
        break;
    case SDLK_KP_7:
        return Nutra::Core::KEYCODE::KP_7;
        break;
    case SDLK_KP_8:
        return Nutra::Core::KEYCODE::KP_8;
        break;
    case SDLK_KP_9:
        return Nutra::Core::KEYCODE::KP_9;
        break;
    case SDLK_KP_0:
        return Nutra::Core::KEYCODE::KP_0;
        break;
    case SDLK_KP_PERIOD:
        return Nutra::Core::KEYCODE::KP_PERIOD;
        break;
    case SDLK_APPLICATION:
        return Nutra::Core::KEYCODE::APPLICATION;
        break;
    case SDLK_POWER:
        return Nutra::Core::KEYCODE::POWER;
        break;
    case SDLK_KP_EQUALS:
        return Nutra::Core::KEYCODE::KP_EQUALS;
        break;
    case SDLK_F13:
        return Nutra::Core::KEYCODE::F13;
        break;
    case SDLK_F14:
        return Nutra::Core::KEYCODE::F14;
        break;
    case SDLK_F15:
        return Nutra::Core::KEYCODE::F15;
        break;
    case SDLK_F16:
        return Nutra::Core::KEYCODE::F16;
        break;
    case SDLK_F17:
        return Nutra::Core::KEYCODE::F17;
        break;
    case SDLK_F18:
        return Nutra::Core::KEYCODE::F18;
        break;
    case SDLK_F19:
        return Nutra::Core::KEYCODE::F19;
        break;
    case SDLK_F20:
        return Nutra::Core::KEYCODE::F20;
        break;
    case SDLK_F21:
        return Nutra::Core::KEYCODE::F21;
        break;
    case SDLK_F22:
        return Nutra::Core::KEYCODE::F22;
        break;
    case SDLK_F23:
        return Nutra::Core::KEYCODE::F23;
        break;
    case SDLK_F24:
        return Nutra::Core::KEYCODE::F24;
        break;
    case SDLK_EXECUTE:
        return Nutra::Core::KEYCODE::EXECUTE;
        break;
    case SDLK_HELP:
        return Nutra::Core::KEYCODE::HELP;
        break;
    case SDLK_MENU:
        return Nutra::Core::KEYCODE::MENU;
        break;
    case SDLK_SELECT:
        return Nutra::Core::KEYCODE::SELECT;
        break;
    case SDLK_STOP:
        return Nutra::Core::KEYCODE::STOP;
        break;
    case SDLK_AGAIN:
        return Nutra::Core::KEYCODE::AGAIN;
        break;
    case SDLK_UNDO:
        return Nutra::Core::KEYCODE::UNDO;
        break;
    case SDLK_CUT:
        return Nutra::Core::KEYCODE::CUT;
        break;
    case SDLK_COPY:
        return Nutra::Core::KEYCODE::COPY;
        break;
    case SDLK_PASTE:
        return Nutra::Core::KEYCODE::PASTE;
        break;
    case SDLK_FIND:
        return Nutra::Core::KEYCODE::FIND;
        break;
    case SDLK_MUTE:
        return Nutra::Core::KEYCODE::MUTE;
        break;
    case SDLK_VOLUMEUP:
        return Nutra::Core::KEYCODE::VOLUMEUP;
        break;
    case SDLK_VOLUMEDOWN:
        return Nutra::Core::KEYCODE::VOLUMEDOWN;
        break;
    case SDLK_KP_COMMA:
        return Nutra::Core::KEYCODE::KP_COMMA;
        break;
    case SDLK_KP_EQUALSAS400:
        return Nutra::Core::KEYCODE::KP_EQUALSAS400;
        break;
    case SDLK_ALTERASE:
        return Nutra::Core::KEYCODE::ALTERASE;
        break;
    case SDLK_SYSREQ:
        return Nutra::Core::KEYCODE::SYSREQ;
        break;
    case SDLK_CANCEL:
        return Nutra::Core::KEYCODE::CANCEL;
        break;
    case SDLK_CLEAR:
        return Nutra::Core::KEYCODE::CLEAR;
        break;
    case SDLK_PRIOR:
        return Nutra::Core::KEYCODE::PRIOR;
        break;
    case SDLK_RETURN2:
        return Nutra::Core::KEYCODE::RETURN2;
        break;
    case SDLK_SEPARATOR:
        return Nutra::Core::KEYCODE::SEPARATOR;
        break;
    case SDLK_OUT:
        return Nutra::Core::KEYCODE::OUT;
        break;
    case SDLK_OPER:
        return Nutra::Core::KEYCODE::OPER;
        break;
    case SDLK_CLEARAGAIN:
        return Nutra::Core::KEYCODE::CLEARAGAIN;
        break;
    case SDLK_CRSEL:
        return Nutra::Core::KEYCODE::CRSEL;
        break;
    case SDLK_EXSEL:
        return Nutra::Core::KEYCODE::EXSEL;
        break;
    case SDLK_KP_00:
        return Nutra::Core::KEYCODE::KP_00;
        break;
    case SDLK_KP_000:
        return Nutra::Core::KEYCODE::KP_000;
        break;
    case SDLK_THOUSANDSSEPARATOR:
        return Nutra::Core::KEYCODE::THOUSANDSSEPARATOR;
        break;
    case SDLK_DECIMALSEPARATOR:
        return Nutra::Core::KEYCODE::DECIMALSEPARATOR;
        break;
    case SDLK_CURRENCYUNIT:
        return Nutra::Core::KEYCODE::CURRENCYUNIT;
        break;
    case SDLK_CURRENCYSUBUNIT:
        return Nutra::Core::KEYCODE::CURRENCYSUBUNIT;
        break;
    case SDLK_KP_LEFTPAREN:
        return Nutra::Core::KEYCODE::KP_LEFTPAREN;
        break;
    case SDLK_KP_RIGHTPAREN:
        return Nutra::Core::KEYCODE::KP_RIGHTPAREN;
        break;
    case SDLK_KP_LEFTBRACE:
        return Nutra::Core::KEYCODE::KP_LEFTBRACE;
        break;
    case SDLK_KP_RIGHTBRACE:
        return Nutra::Core::KEYCODE::KP_RIGHTBRACE;
        break;
    case SDLK_KP_TAB:
        return Nutra::Core::KEYCODE::KP_TAB;
        break;
    case SDLK_KP_BACKSPACE:
        return Nutra::Core::KEYCODE::KP_BACKSPACE;
        break;
    case SDLK_KP_A:
        return Nutra::Core::KEYCODE::KP_A;
        break;
    case SDLK_KP_B:
        return Nutra::Core::KEYCODE::KP_B;
        break;
    case SDLK_KP_C:
        return Nutra::Core::KEYCODE::KP_C;
        break;
    case SDLK_KP_D:
        return Nutra::Core::KEYCODE::KP_D;
        break;
    case SDLK_KP_E:
        return Nutra::Core::KEYCODE::KP_E;
        break;
    case SDLK_KP_F:
        return Nutra::Core::KEYCODE::KP_F;
        break;
    case SDLK_KP_XOR:
        return Nutra::Core::KEYCODE::KP_XOR;
        break;
    case SDLK_KP_POWER:
        return Nutra::Core::KEYCODE::KP_POWER;
        break;
    case SDLK_KP_PERCENT:
        return Nutra::Core::KEYCODE::KP_PERCENT;
        break;
    case SDLK_KP_LESS:
        return Nutra::Core::KEYCODE::KP_LESS;
        break;
    case SDLK_KP_GREATER:
        return Nutra::Core::KEYCODE::KP_GREATER;
        break;
    case SDLK_KP_AMPERSAND:
        return Nutra::Core::KEYCODE::KP_AMPERSAND;
        break;
    case SDLK_KP_DBLAMPERSAND:
        return Nutra::Core::KEYCODE::KP_DBLAMPERSAND;
        break;
    case SDLK_KP_VERTICALBAR:
        return Nutra::Core::KEYCODE::KP_VERTICALBAR;
        break;
    case SDLK_KP_DBLVERTICALBAR:
        return Nutra::Core::KEYCODE::KP_DBLVERTICALBAR;
        break;
    case SDLK_KP_COLON:
        return Nutra::Core::KEYCODE::KP_COLON;
        break;
    case SDLK_KP_HASH:
        return Nutra::Core::KEYCODE::KP_HASH;
        break;
    case SDLK_KP_SPACE:
        return Nutra::Core::KEYCODE::KP_SPACE;
        break;
    case SDLK_KP_AT:
        return Nutra::Core::KEYCODE::KP_AT;
        break;
    case SDLK_KP_EXCLAM:
        return Nutra::Core::KEYCODE::KP_EXCLAM;
        break;
    case SDLK_KP_MEMSTORE:
        return Nutra::Core::KEYCODE::KP_MEMSTORE;
        break;
    case SDLK_KP_MEMRECALL:
        return Nutra::Core::KEYCODE::KP_MEMRECALL;
        break;
    case SDLK_KP_MEMCLEAR:
        return Nutra::Core::KEYCODE::KP_MEMCLEAR;
        break;
    case SDLK_KP_MEMADD:
        return Nutra::Core::KEYCODE::KP_MEMADD;
        break;
    case SDLK_KP_MEMSUBTRACT:
        return Nutra::Core::KEYCODE::KP_MEMSUBTRACT;
        break;
    case SDLK_KP_MEMMULTIPLY:
        return Nutra::Core::KEYCODE::KP_MEMMULTIPLY;
        break;
    case SDLK_KP_MEMDIVIDE:
        return Nutra::Core::KEYCODE::KP_MEMDIVIDE;
        break;
    case SDLK_KP_PLUSMINUS:
        return Nutra::Core::KEYCODE::KP_PLUSMINUS;
        break;
    case SDLK_KP_CLEAR:
        return Nutra::Core::KEYCODE::KP_CLEAR;
        break;
    case SDLK_KP_CLEARENTRY:
        return Nutra::Core::KEYCODE::KP_CLEARENTRY;
        break;
    case SDLK_KP_BINARY:
        return Nutra::Core::KEYCODE::KP_BINARY;
        break;
    case SDLK_KP_OCTAL:
        return Nutra::Core::KEYCODE::KP_OCTAL;
        break;
    case SDLK_KP_DECIMAL:
        return Nutra::Core::KEYCODE::KP_DECIMAL;
        break;
    case SDLK_KP_HEXADECIMAL:
        return Nutra::Core::KEYCODE::KP_HEXADECIMAL;
        break;
    case SDLK_LCTRL:
        return Nutra::Core::KEYCODE::LCTRL;
        break;
    case SDLK_LSHIFT:
        return Nutra::Core::KEYCODE::LSHIFT;
        break;
    case SDLK_LALT:
        return Nutra::Core::KEYCODE::LALT;
        break;
    case SDLK_LGUI:
        return Nutra::Core::KEYCODE::LGUI;
        break;
    case SDLK_RCTRL:
        return Nutra::Core::KEYCODE::RCTRL;
        break;
    case SDLK_RSHIFT:
        return Nutra::Core::KEYCODE::RSHIFT;
        break;
    case SDLK_RALT:
        return Nutra::Core::KEYCODE::RALT;
        break;
    case SDLK_RGUI:
        return Nutra::Core::KEYCODE::RGUI;
        break;
    case SDLK_MODE:
        return Nutra::Core::KEYCODE::MODE;
        break;
    case SDLK_AUDIONEXT:
        return Nutra::Core::KEYCODE::AUDIONEXT;
        break;
    case SDLK_AUDIOPREV:
        return Nutra::Core::KEYCODE::AUDIOPREV;
        break;
    case SDLK_AUDIOSTOP:
        return Nutra::Core::KEYCODE::AUDIOSTOP;
        break;
    case SDLK_AUDIOPLAY:
        return Nutra::Core::KEYCODE::AUDIOPLAY;
        break;
    case SDLK_AUDIOMUTE:
        return Nutra::Core::KEYCODE::AUDIOMUTE;
        break;
    case SDLK_MEDIASELECT:
        return Nutra::Core::KEYCODE::MEDIASELECT;
        break;
    case SDLK_WWW:
        return Nutra::Core::KEYCODE::WWW;
        break;
    case SDLK_MAIL:
        return Nutra::Core::KEYCODE::MAIL;
        break;
    case SDLK_CALCULATOR:
        return Nutra::Core::KEYCODE::CALCULATOR;
        break;
    case SDLK_COMPUTER:
        return Nutra::Core::KEYCODE::COMPUTER;
        break;
    case SDLK_AC_SEARCH:
        return Nutra::Core::KEYCODE::AC_SEARCH;
        break;
    case SDLK_AC_HOME:
        return Nutra::Core::KEYCODE::AC_HOME;
        break;
    case SDLK_AC_BACK:
        return Nutra::Core::KEYCODE::AC_BACK;
        break;
    case SDLK_AC_FORWARD:
        return Nutra::Core::KEYCODE::AC_FORWARD;
        break;
    case SDLK_AC_STOP:
        return Nutra::Core::KEYCODE::AC_STOP;
        break;
    case SDLK_AC_REFRESH:
        return Nutra::Core::KEYCODE::AC_REFRESH;
        break;
    case SDLK_AC_BOOKMARKS:
        return Nutra::Core::KEYCODE::AC_BOOKMARKS;
        break;
    case SDLK_BRIGHTNESSDOWN:
        return Nutra::Core::KEYCODE::BRIGHTNESSDOWN;
        break;
    case SDLK_BRIGHTNESSUP:
        return Nutra::Core::KEYCODE::BRIGHTNESSUP;
        break;
    case SDLK_DISPLAYSWITCH:
        return Nutra::Core::KEYCODE::DISPLAYSWITCH;
        break;
    case SDLK_KBDILLUMTOGGLE:
        return Nutra::Core::KEYCODE::KBDILLUMTOGGLE;
        break;
    case SDLK_KBDILLUMDOWN:
        return Nutra::Core::KEYCODE::KBDILLUMDOWN;
        break;
    case SDLK_KBDILLUMUP:
        return Nutra::Core::KEYCODE::KBDILLUMUP;
        break;
    case SDLK_EJECT:
        return Nutra::Core::KEYCODE::EJECT;
        break;
    case SDLK_SLEEP:
        return Nutra::Core::KEYCODE::SLEEP;
        break;
    case SDLK_APP1:
        return Nutra::Core::KEYCODE::APP1;
        break;
    case SDLK_APP2:
        return Nutra::Core::KEYCODE::APP2;
        break;
    case SDLK_AUDIOREWIND:
        return Nutra::Core::KEYCODE::AUDIOREWIND;
        break;
    case SDLK_AUDIOFASTFORWARD:
        return Nutra::Core::KEYCODE::AUDIOFASTFORWARD;
        break;
    case SDLK_SOFTLEFT:
        return Nutra::Core::KEYCODE::SOFTLEFT;
        break;
    case SDLK_SOFTRIGHT:
        return Nutra::Core::KEYCODE::SOFTRIGHT;
        break;
    case SDLK_CALL:
        return Nutra::Core::KEYCODE::CALL;
        break;
    case SDLK_ENDCALL:
        return Nutra::Core::KEYCODE::ENDCALL;
        break;

    default:
        throw std::runtime_error("Unhandled SDL_Nutra::Core::KeyCode");
    }
}

auto Nutra::Core::convertSDLMouseButtonToNutraKeyCode(uint8_t mouseButtonIndex) -> Nutra::Core::KEYCODE {
    switch (mouseButtonIndex) {
    case SDL_BUTTON_LEFT:
        return Nutra::Core::KEYCODE::MOUSE_BUTTON_LEFT;
        break;
    case SDL_BUTTON_MIDDLE:
        return Nutra::Core::KEYCODE::MOUSE_BUTTON_MIDDLE;
        break;
    case SDL_BUTTON_RIGHT:
        return Nutra::Core::KEYCODE::MOUSE_BUTTON_RIGHT;
        break;

    default:
        throw std::runtime_error("Unhandled SDL_Nutra::Core::KeyCode");
    }
}