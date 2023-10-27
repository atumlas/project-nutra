#pragma once

#include <initializer_list>
#include <vector>

#include "keycodes.hpp"

namespace Nutra::Core {
    class KeyCodeMapping {
        public:
            ~KeyCodeMapping() = default;

            KeyCodeMapping & operator=(std::initializer_list<KeyCode> KeyCodes) {
                for (auto & keyCode : m_KeyCodeMapping) {
                    keyCode = 0;
                }
                for (auto const & keyCode : KeyCodes) {
                    uint8_t keyCodeAsInt = static_cast<int>(keyCode);
                    m_KeyCodeMapping[keyCodeAsInt / 64] |= 1ULL << (keyCodeAsInt % 64);
                }
                return *this;
            }

            uint64_t operator[](int index) const noexcept {
                return m_KeyCodeMapping[index];
            }

        private:
            uint64_t m_KeyCodeMapping[4];
    };
} // namespace Nutra::Core
