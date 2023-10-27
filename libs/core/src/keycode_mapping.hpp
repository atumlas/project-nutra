#pragma once

#include <array>
#include <initializer_list>
#include <iterator>

#include "iterable_type.hpp"
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
                    uint8_t keyCodeAsInt = static_cast<uint8_t>(keyCode);
                    m_KeyCodeMapping[keyCodeAsInt / 64] |= 1ULL << (keyCodeAsInt % 64);
                }
                return *this;
            }

            uint64_t & operator[](size_t index) {
                return m_KeyCodeMapping[index];
            }

            IterableType<uint64_t> begin() {
                return IterableType<uint64_t>(m_KeyCodeMapping.data());
            }

            IterableType<uint64_t> end() {
                return IterableType<uint64_t>(m_KeyCodeMapping.data() + m_KeyCodeMapping.size());
            }

        private:
            std::array<uint64_t, 4> m_KeyCodeMapping;
    };
} // namespace Nutra::Core
