#include "data_processing.h"
#include <iostream>
#include <cassert>
#include <vector>

void testSortAscending() {
    std::vector<int> data = {5, 2, 9, 1, 5, 6};
    sortAscending(data);
    assert((data == std::vector<int>{1, 2, 5, 5, 6, 9}));
    std::cout << "testSortAscending passed!" << std::endl;
}

void testSortDescending() {
    std::vector<int> data = {5, 2, 9, 1, 5, 6};
    sortDescending(data);
    assert((data == std::vector<int>{9, 6, 5, 5, 2, 1}));
    std::cout << "testSortDescending passed!" << std::endl;
}

void testRemoveDuplicates() {
    std::vector<int> data = {5, 2, 9, 1, 5, 6};
    removeDuplicates(data);
    assert((data == std::vector<int>{1, 2, 5, 6, 9}));
    std::cout << "testRemoveDuplicates passed!" << std::endl;
}

void testSquareValues() {
    std::vector<int> data = {1, 2, 3, 4};
    squareValues(data);
    assert((data == std::vector<int>{1, 4, 9, 16}));
    std::cout << "testSquareValues passed!" << std::endl;
}

int main() {
    testSortAscending();
    testSortDescending();
    testRemoveDuplicates();
    testSquareValues();
    return 0;
}