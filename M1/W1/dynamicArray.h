// dynamicArray<T>: A generic dynamic array implementation in C++
// Features include resizable capacity, element access, and insertion/removal operations.

#pragma once
#include <memory>
#include <stdexcept>

// Templated Dynamic Array class
template <typename T>
class dynamicArray
{
private:
    std::unique_ptr<T[]> data; // Smart pointer for managing dynamic array memory
    size_t capacity; // Total capacity of the array
    size_t count; // Current number of elements in the array


    // Resize the array when the capacity is reached
    void resize()
    {
        capacity *= 2; // Double the capacity
        auto newData = std::make_unique<T[]>(capacity);
        for (size_t i = 0; i < count; i++)
        {
            newData[i] = std::move(data[i]); // Move elements to the new array
        }
        data = std::move(newData);
    }

public:
    // Constructor with an optional initial size
    dynamicArray(size_t initialSize = 10)
        : data(std::make_unique<T[]>(initialSize)), capacity(initialSize), count(0) {};
    
    // Add an element to the end of the array
    void push_back(const T& value)
    {
        if (count == capacity) resize();
        data[count++] = value; // Add element and increment count
    }

    // Overload operator[] for direct element access
    T& operator[](size_t index)
    {
        return data[index];
    }

    const T& operator[](size_t index) const
    {
        return data[index];
    }

    // Get the current size of the array
    size_t size() const
    {
        return count;
    }

    // Clear all elements in the array
    void clear()
    {
        count = 0; // Reset the count
    }

    // Check if the array is empty
    bool is_empty() const
    {
        return count == 0;
    }

    // Get an element with bounds checking
    T& at(size_t index)
    {
        if(index >= count)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    const T& at(size_t index) const
    {
        if (index >= count)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    // Remove an element at a specific index
    void remove_at(size_t index)
    {
        if (index >= count)
        {
            throw std::out_of_range("Index out of bounds");
        }
        for (size_t i = index; i < count - 1; ++i)
        {
            data[i] = std::move(data[i+1]); // Shift elements to the left
        }
        --count;  // Decrement count
    }

    // Insert an element at a specific index
    void insert(size_t index, const T& value)
    {
        if (index > count)
        {
            throw std::out_of_range("Index out of bounds");
        }
        if (count == capacity) resize();
        for (size_t i = count; i > index; --i)
        {
            data[i] = std::move(data[i - 1]); // Shift elements to the right
        }
        data[index] = value; // Insert new element
        ++count; // Increment count
    }
};