#ifndef LINKEDLISTBASEDSTAK_H
#define LINKEDLISTBASEDSTAK_H

#include <cstddef>
#include <memory>
#include <stdexcept>

template <typename T>

class Stack_ {
private:
  // Node definition
  struct Node {
    T data;
    Node *next;
    Node(const T &val, Node *nxt) : data(val), next(nxt) {};
  };

  Node *head = nullptr;
  std::size_t count = 0;

public:
  ~Stack_() {
    while (!empty())
      pop();
  }

  void push(const T& val) {
    head = new Node(val, head);
    ++count;
  }

  void pop() {
    if(empty()) throw std::underflow_error("Stack is empty");
      Node* temp = head;
      head = head->next;
      delete temp;
      --count;
  }

  T& top() {
    if (empty()) throw std::underflow_error("Stack is empty");
    return head->value;
  }

  bool empty() const { return head == nullptr; }
  size_t size() const { return count; }
};

#endif
