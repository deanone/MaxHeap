#include "MaxHeap.h"

#include <iostream>

int main()
{
    int capacity = 10;
    MaxHeap* heap = new MaxHeap(capacity);

    for (int i = 0; i < 8; i++)
    {
        heap->insert(i);
    }

    heap->print();

    std::cout << "Max element: " << heap->extractMax() << "\n";

    delete heap;

    return 0;
}