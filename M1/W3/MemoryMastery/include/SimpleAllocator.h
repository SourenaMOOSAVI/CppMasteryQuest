#pragma once
#include <cstddef>
#include <new>
#include <iostream>
#include <limits>

namespace mm {

template <typename T>
struct SimpleAllocator {
    using value_type = T;

    SimpleAllocator() noexcept = default;
    template <typename U> constexpr SimpleAllocator(const SimpleAllocator<U>&) noexcept {}

    T* allocate(std::size_t n) {
        std::cout << "[SimpleAllocator] allocate " << n << " element(s)\n";
        if (n > std::numeric_limits<std::size_t>::max() / sizeof(T))
            throw std::bad_array_new_length();
        void* p = ::operator new(n * sizeof(T));
        return static_cast<T*>(p);
    }

    void deallocate(T* p, std::size_t /*n*/) noexcept {
        ::operator delete(static_cast<void*>(p));
    }
};

template <class T, class U>
bool operator==(const SimpleAllocator<T>&, const SimpleAllocator<U>&) noexcept { return true; }
template <class T, class U>
bool operator!=(const SimpleAllocator<T>&, const SimpleAllocator<U>&) noexcept { return false; }

} // namespace mm
