#pragma once

template <typename T>
struct IterableType {
        T * p;
        IterableType(T * p) : p(p) {
        }
        bool operator!=(IterableType<T> rhs) {
            return p != rhs.p;
        }
        T & operator*() {
            return *p;
        }
        void operator++() {
            ++p;
        }
};