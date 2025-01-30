// LinkedList<T>: A generic, singly linked list implementation in C++
// Features include adding nodes, traversal, and more.

#pragma once
#include <iostream>
#include <memory>

// Templated Linked List class
template<typename T>
class LinkedList
{
private:
    struct Node
    {
        T data;                         // Data stored in the node
        std::unique_ptr<Node> next;     // Pointer to the next node

        Node(const T& value) : data(value), next(nullptr) {}
    };
    
    std::unique_ptr<Node> head;         // Pointer to the head node
    size_t listSize;                    // Number of elements in the list

public:
    // Default constructor initializes an empty list
    LinkedList() : head(nullptr), listSize(0) {}

    // Add a node to the beginning of the list
    void push_front(const T& value)
    {
        auto newNode = std::make_unique<Node>(value);
        newNode->next = std::move(head);  // Set new node's next to current head
        head = std::move(newNode);        // Update head to the new node
        ++listSize;
    }

    // Add a node to the end of the list
    void push_back(const T& value)
    {
        auto newNode = std::make_unique<Node>(value);
        if (!head)
        {
            head = std::move(newNode);  // Set head if the list is empty
        }
        else
        {
            Node* current = head.get();
            while(current->next)
            {
                current = current->next.get(); // Traverse to the last node
            }
            current->next = std::move(newNode); // Attach the new node
        }
        ++listSize;
    }

    // Traverse and print elements
    void print() const
    {
        Node* current = head.get();
        while (current)
        {
            std::cout << current->data << " -> ";
            current = current->next.get();
        }
        std::cout << "nullptr" << std::endl; // End of the list  
    }

    // Get the size of the list
    size_t size() const
    {
        return listSize;
    }

    // Destructor ensures all nodes are properly deleted
    ~LinkedList() = default;
};