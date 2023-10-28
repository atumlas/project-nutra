#pragma once

#include <array>
#include <initializer_list>

#include "keycode.hpp"

namespace Nutra::Core {
    class KeyCodeMapping {
        public:
            ~KeyCodeMapping() = default;

            KeyCodeMapping & operator=(std::initializer_list<KEYCODE> KeyCodes);

            [[nodiscard]] auto operator[](size_t index) -> uint64_t const &;

        private:
            std::array<uint64_t, 4> m_key_code_mapping;
    };
} // namespace Nutra::Core
