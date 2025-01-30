#include <iostream>
#include <string>
#include "dynamicArray.h"
#include "linkedList.h"

int main() {
    dynamicArray<std::string> arr;
    LinkedList<int> list;


    // Adding elements
    arr.push_back("Hello");
    arr.push_back("World");
    arr.push_back("Dynamic");
    arr.push_back("Array");

    list.push_front(10);
    list.push_back(20);
    list.push_back(30);

    // Display elements
    std::cout << "Array elements:" << std::endl;
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Insert at index
    arr.insert(2, "C++");
    std::cout << "After insertion:" << std::endl;
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Remove an element
    arr.remove_at(1);
    std::cout << "After removal:" << std::endl;
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Accessing with `at()` method
    try {
        std::cout << "Element at index 3: " << arr.at(3) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Clear array
    arr.clear();
    std::cout << "Array cleared. Is empty: " << std::boolalpha << arr.is_empty() << std::endl;


    std::cout << "LinkedList elements: ";
    list.print();

    std::cout << "Size of the LinkedList: " << list.size() << std::endl;

    return 0;
}
