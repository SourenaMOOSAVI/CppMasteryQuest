#ifndef STACK_H
#define STACK_H

#include <memory>
#include <stdexcept>

template <typename T>
class Stack {
private:
    // Node definition using unique_ptr for safe memory management
    struct Node {
        T data;
        std::unique_ptr<Node> next;
        Node(const T& value, std::unique_ptr<Node> nextNode = nullptr)
            : data(value), next(std::move(nextNode)) {}
        Node(T&& value, std::unique_ptr<Node> nextNode = nullptr)
            : data(std::move(value)), next(std::move(nextNode)) {}
    };

    std::unique_ptr<Node> head;  // top of stack
    size_t count = 0;            // track size

public:
    // Default constructor
    Stack() = default;

    // Disable copy (deep copy could be implemented if needed)
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    // Enable move
    Stack(Stack&& other) noexcept
        : head(std::move(other.head)), count(other.count) {
        other.count = 0;
    }

    Stack& operator=(Stack&& other) noexcept {
        if (this != &other) {
            head = std::move(other.head);
            count = other.count;
            other.count = 0;
        }
        return *this;
    }

    // Destructor handled automatically (unique_ptr frees nodes)

    // Push by copy
    void push(const T& value) {
        head = std::make_unique<Node>(value, std::move(head));
        ++count;
    }

    // Push by move
    void push(T&& value) {
        head = std::make_unique<Node>(std::move(value), std::move(head));
        ++count;
    }

    // Pop top element
    void pop() {
        if (empty()) {
            throw std::out_of_range("Stack underflow: cannot pop from empty stack.");
        }
        head = std::move(head->next);  // old head automatically freed
        --count;
    }

    // Access top element
    T& top() {
        if (empty()) {
            throw std::out_of_range("Stack is empty: no top element.");
        }
        return head->data;
    }

    const T& top() const {
        if (empty()) {
            throw std::out_of_range("Stack is empty: no top element.");
        }
        return head->data;
    }

    // Check size
    size_t size() const noexcept {
        return count;
    }

    // Check if empty
    bool empty() const noexcept {
        return count == 0;
    }
};

#endif // STACK_H