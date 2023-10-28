#include "keycode_mapping.hpp"

auto Nutra::Core::KeyCodeMapping::operator=(std::initializer_list<KEYCODE> KeyCodes) -> Nutra::Core::KeyCodeMapping & {
    for (auto const & keyCode : KeyCodes) {
        uint8_t keyCodeAsInt = static_cast<uint8_t>(keyCode);
        m_KeyCodeMapping[keyCodeAsInt / 64] |= 1ULL << (keyCodeAsInt % 64);
    }
    return *this;
}

auto Nutra::Core::KeyCodeMapping::operator[](size_t index) -> uint64_t const & {
    return m_KeyCodeMapping[index];
}