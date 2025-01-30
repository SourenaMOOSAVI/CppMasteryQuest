#ifndef SHAREDPTR_H
#define SHAREDPTR_H

#include <cstddef> // For size_t
#include <utility> // For std::move

// SharedPtr class template
template <typename T>
class SharedPtr {
private:
    T* ptr;              // Raw pointer to the managed object
    size_t* ref_count;   // Pointer to the reference count

    void release() {
        if (ref_count) {
            --(*ref_count);
            if (*ref_count == 0) {
                delete ptr;
                delete ref_count;
            }
        }
    }

public:
    // Default constructor
    SharedPtr() : ptr(nullptr), ref_count(nullptr) {}

    // Constructor with raw pointer
    explicit SharedPtr(T* rawPtr) : ptr(rawPtr), ref_count(new size_t(1)) {}

    // Copy constructor
    SharedPtr(const SharedPtr& other) : ptr(other.ptr), ref_count(other.ref_count) {
        if (ref_count) {
            ++(*ref_count);
        }
    }

    // Move constructor
    SharedPtr(SharedPtr&& other) noexcept : ptr(other.ptr), ref_count(other.ref_count) {
        other.ptr = nullptr;
        other.ref_count = nullptr;
    }

    // Copy assignment operator
    SharedPtr& operator=(const SharedPtr& other) {
        if (this != &other) {
            release();
            ptr = other.ptr;
            ref_count = other.ref_count;
            if (ref_count) {
                ++(*ref_count);
            }
        }
        return *this;
    }

    // Move assignment operator
    SharedPtr& operator=(SharedPtr&& other) noexcept {
        if (this != &other) {
            release();
            ptr = other.ptr;
            ref_count = other.ref_count;
            other.ptr = nullptr;
            other.ref_count = nullptr;
        }
        return *this;
    }

    // Destructor
    ~SharedPtr() {
        release();
    }

    // Access the raw pointer
    T* get() const {
        return ptr;
    }

    // Dereference operator
    T& operator*() const {
        return *ptr;
    }

    // Arrow operator
    T* operator->() const {
        return ptr;
    }

    // Returns the reference count
    size_t use_count() const {
        return ref_count ? *ref_count : 0;
    }

    // Checks if this is the sole owner of the managed object
    bool unique() const {
        return ref_count && *ref_count == 1;
    }

    // Resets the SharedPtr
    void reset(T* newPtr = nullptr) {
        release();
        ptr = newPtr;
        ref_count = newPtr ? new size_t(1) : nullptr;
    }

    // Explicit conversion to bool
    explicit operator bool() const {
        return ptr != nullptr;
    }

    // Friend function to overload operator!
    friend bool operator!(const SharedPtr& sp) {
        return sp.get() == nullptr;
    }
};

#endif // SHAREDPTR_H
