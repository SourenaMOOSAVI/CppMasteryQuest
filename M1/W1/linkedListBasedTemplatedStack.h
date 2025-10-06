
// LinkedListBasedTemplatedStack.h
// A simple stack implementation using a singly linked list and templates.
// Provides push, pop, top, empty, and size operations.

#ifndef LINKEDLISTBASEDSTAK_H
#define LINKEDLISTBASEDSTAK_H


#include <cstddef>      // for std::size_t
#include <stdexcept>    // for std::underflow_error


// Templated stack class implemented using a singly linked list.
// Provides basic stack operations: push, pop, top, empty, and size.
template <typename T>
class Stack_ {
private:
  // Node definition for singly linked list
  struct Node {
    T data;         // Value stored in the node
    Node *next;     // Pointer to the next node

    // Node constructor
    Node(const T &val, Node *nxt) : data(val), next(nxt) {}
  };

  Node *head = nullptr;        // Pointer to the top of the stack
  std::size_t count = 0;       // Number of elements in the stack

public:
  // Destructor: releases all nodes in the stack
  ~Stack_() {
    while (!empty())
      pop();
  }

  // Pushes a value onto the stack
  void push(const T& val) {
    head = new Node(val, head); // Create new node and set as new head
    ++count;
  }

  // Removes the top element from the stack
  // Throws std::underflow_error if the stack is empty
  void pop() {
    if (empty()) throw std::underflow_error("Stack is empty");
    Node* temp = head;
    head = head->next;
    delete temp;
    --count;
  }

  // Returns a reference to the top element
  // Throws std::underflow_error if the stack is empty
  T& top() {
    if (empty()) throw std::underflow_error("Stack is empty");
    return head->data;
  }

  // Checks if the stack is empty
  bool empty() const { return head == nullptr; }

  // Returns the number of elements in the stack
  size_t size() const { return count; }
};

#endif // LINKEDLISTBASEDSTAK_H
