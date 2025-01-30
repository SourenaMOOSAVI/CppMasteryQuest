#ifndef WEAKPTR_H
#define WEAKPTR_H

#include "SharedPtr.h"

template <typename T>
class WeakPtr {
private:
    SharedPtr<T>* sharedPtr;

public:
    WeakPtr();
    explicit WeakPtr(const SharedPtr<T>& sharedPtr);
    ~WeakPtr() = default;

    SharedPtr<T> lock() const;
    bool expired() const; // Added the expired method

    WeakPtr(const WeakPtr& other);
    WeakPtr& operator=(const WeakPtr& other);

    WeakPtr(WeakPtr&& other) noexcept;
    WeakPtr& operator=(WeakPtr&& other) noexcept;
};

// Implementation

template <typename T>
WeakPtr<T>::WeakPtr() : sharedPtr(nullptr) {}

template <typename T>
WeakPtr<T>::WeakPtr(const SharedPtr<T>& sharedPtr)
    : sharedPtr(const_cast<SharedPtr<T>*>(&sharedPtr)) {}

template <typename T>
SharedPtr<T> WeakPtr<T>::lock() const {
    return (sharedPtr && sharedPtr->use_count() > 0) ? *sharedPtr : SharedPtr<T>();
}

template <typename T>
bool WeakPtr<T>::expired() const {
    return !sharedPtr || sharedPtr->use_count() == 0;
}

template <typename T>
WeakPtr<T>::WeakPtr(const WeakPtr& other) : sharedPtr(other.sharedPtr) {}

template <typename T>
WeakPtr<T>& WeakPtr<T>::operator=(const WeakPtr& other) {
    if (this != &other) {
        sharedPtr = other.sharedPtr;
    }
    return *this;
}

template <typename T>
WeakPtr<T>::WeakPtr(WeakPtr&& other) noexcept : sharedPtr(other.sharedPtr) {
    other.sharedPtr = nullptr;
}

template <typename T>
WeakPtr<T>& WeakPtr<T>::operator=(WeakPtr&& other) noexcept {
    if (this != &other) {
        sharedPtr = other.sharedPtr;
        other.sharedPtr = nullptr;
    }
    return *this;
}

#endif // WEAKPTR_H
