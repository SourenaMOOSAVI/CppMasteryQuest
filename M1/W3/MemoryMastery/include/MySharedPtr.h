#pragma once
#include <cstddef>
#include <utility>
#include <cassert>
#include <atomic>

namespace mm {

/*
 Minimal, educational shared pointer.
 - header-only
 - supports copy/move, use_count(), reset()
 - NOT full-featured: no weak_ptr, no custom deleter, no aliasing ctor
*/

template <typename T>
class MySharedPtr {
public:
    MySharedPtr() noexcept : ptr_(nullptr), count_(nullptr) {}

    explicit MySharedPtr(T* ptr) : ptr_(ptr) {
        if (ptr_) count_ = new std::size_t(1);
        else count_ = nullptr;
    }

    // copy
    MySharedPtr(const MySharedPtr& other) noexcept
        : ptr_(other.ptr_), count_(other.count_) {
        if (count_) ++(*count_);
    }

    // move
    MySharedPtr(MySharedPtr&& other) noexcept
        : ptr_(other.ptr_), count_(other.count_) {
        other.ptr_ = nullptr;
        other.count_ = nullptr;
    }

    MySharedPtr& operator=(const MySharedPtr& other) noexcept {
        if (this == &other) return *this;
        release();
        ptr_ = other.ptr_;
        count_ = other.count_;
        if (count_) ++(*count_);
        return *this;
    }

    MySharedPtr& operator=(MySharedPtr&& other) noexcept {
        if (this != &other) {
            release();
            ptr_ = other.ptr_;
            count_ = other.count_;
            other.ptr_ = nullptr;
            other.count_ = nullptr;
        }
        return *this;
    }

    ~MySharedPtr() {
        release();
    }

    T* get() const noexcept { return ptr_; }
    T& operator*() const noexcept { assert(ptr_); return *ptr_; }
    T* operator->() const noexcept { return ptr_; }
    explicit operator bool() const noexcept { return ptr_ != nullptr; }

    std::size_t use_count() const noexcept { return count_ ? *count_ : 0; }

    void reset(T* p = nullptr) {
        release();
        if (p) {
            ptr_ = p;
            count_ = new std::size_t(1);
        } else {
            ptr_ = nullptr;
            count_ = nullptr;
        }
    }

    void swap(MySharedPtr& other) noexcept {
        std::swap(ptr_, other.ptr_);
        std::swap(count_, other.count_);
    }

private:
    void release() noexcept {
        if (!count_) return;
        if (--(*count_) == 0) {
            delete ptr_;
            delete count_;
        }
        ptr_ = nullptr;
        count_ = nullptr;
    }

    T* ptr_;
    std::size_t* count_;
};

} // namespace mm