#pragma once

#include <array>
#include <initializer_list>

#include "keycode.hpp"

namespace Nutra::Core {
    class KeyCodeMapping {
        public:
            ~KeyCodeMapping() = default;

            KeyCodeMapping & operator=(std::initializer_list<KeyCode> KeyCodes) {
                for (auto const & keyCode : KeyCodes) {
                    uint8_t keyCodeAsInt = static_cast<uint8_t>(keyCode);
                    m_KeyCodeMapping[keyCodeAsInt / 64] |= 1ULL << (keyCodeAsInt % 64);
                }
                return *this;
            }

            uint64_t & operator[](size_t index) {
                return m_KeyCodeMapping[index];
            }

        private:
            std::array<uint64_t, 4> m_KeyCodeMapping;
    };
} // namespace Nutra::Core
