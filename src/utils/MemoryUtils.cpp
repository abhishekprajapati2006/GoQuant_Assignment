#include "MemoryUtils.h"
#include <iostream>
#include <cstring>

// Function to allocate memory for an array of integers
int* allocateIntArray(size_t size) {
    int* array = new int[size];
    if (!array) {
        std::cerr << "Memory allocation failed for int array" << std::endl;
        return nullptr;
    }
    return array;
}

// Function to deallocate memory for an array of integers
void deallocateIntArray(int* array) {
    delete[] array;
}

// Function to copy a string
char* copyString(const char* source) {
    size_t length = std::strlen(source);
    char* copy = new char[length + 1]; // +1 for the null terminator
    if (!copy) {
        std::cerr << "Memory allocation failed for string copy" << std::endl;
        return nullptr;
    }
    std::strcpy(copy, source);
    return copy;
}

// Function to deallocate memory for a string
void deallocateString(char* str) {
    delete[] str;
}