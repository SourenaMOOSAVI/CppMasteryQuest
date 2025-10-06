
// vectorBasedTemplatedStack.h
// A simple stack implementation using std::vector and templates.
// Provides push, pop, top, empty, and size operations with dynamic resizing.

#ifndef VECTBASEDSTACK_H
#define VECTBASEDSTACK_H


#include <stdexcept> // for std::out_of_range
#include <vector>    // for std::vector


// Templated stack class implemented using std::vector as the underlying container.
// Provides efficient stack operations (LIFO) with automatic memory management.
template <typename T>
class vectBasedStack {
private:
  std::vector<T> elements; // Internal storage for stack elements

public:
  // Pushes an element onto the top of the stack.
  // Amortized O(1) time due to vector's dynamic resizing.
  void push(const T &value) {
    elements.push_back(value);
  }

  // Removes the top element from the stack.
  // Throws std::out_of_range if the stack is empty.
  void pop() {
    if (empty()) {
      throw std::out_of_range("Stack is empty");
    }
    elements.pop_back();
  }

  // Returns a reference to the top element of the stack.
  // Throws std::out_of_range if the stack is empty.
  T &top() {
    if (empty()) {
      throw std::out_of_range("Stack is empty");
    }
    return elements.back();
  }

  // Checks if the stack is empty.
  // Returns true if there are no elements, false otherwise.
  bool empty() const { return elements.empty(); }

  // Returns the number of elements currently in the stack.
  size_t size() const { return elements.size(); }
};

#endif // VECTBASEDSTACK_H
