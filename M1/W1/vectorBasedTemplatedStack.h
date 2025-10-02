#ifndef VECTBASEDSTACK_H
#define VECTBASEDSTACK_H

#include <stdexcept>
#include <vector>

template <typename T> 
class vectBasedStack {
private:
  std::vector<T> elements;

public:
  // Push an element onto the stack
  void push(const T &value) { 
    elements.push_back(value); 
    }

  // Pop (remove) an element from the stack
  void pop() {
    if (empty()) {
      throw std::out_of_range("Stack is empty");
    }
    elements.pop_back();
  }

  // get the top element of the stack
  T &top() {
    if (empty()) {
      throw std::out_of_range("Stack is empty");
    }
    return elements.back();
  }

  // Check if the stack is empty
  bool empty() const { return elements.empty(); }

  // Get the size of the stack
  size_t size() const { return elements.size(); }
};

#endif
