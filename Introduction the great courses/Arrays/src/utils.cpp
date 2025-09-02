#include "utils.hpp"

int getIndex(int i, int size)
{
    // int index = i % (sizeof(array) / sizeof(std::string));
    int index = i % size;

    return index;
}