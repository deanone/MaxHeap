#include "MaxHeap.h"

#include <iostream>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

MaxHeap::MaxHeap(int capacity)
{
    this->capacity = capacity;
    arr = new int[capacity];
    size = 0;
}

MaxHeap::~MaxHeap()
{
    delete[] arr;
    arr = nullptr; 
}

int MaxHeap::parent(int i)
{
    return ((i - 1) / 2);
}

int MaxHeap::left(int i)
{
    return ((2 * i) + 1);
}

int MaxHeap::right(int i)
{
    return ((2 * i) + 2);
}

void MaxHeap::maxHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;

    if ((l < size) && (arr[l] > arr[largest]))
    {
        largest = l;
    }

    if ((r < size) && (arr[r] > arr[largest]))
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        maxHeapify(largest);
    }
}

void MaxHeap::insert(int val)
{
    if (size == capacity)
    {
        return;
    }

    size++;
    int i = size - 1;
    arr[i] = val;

    while ((i != 0) && (arr[i] > arr[parent(i)]))
    {
        swap(&arr[i], &arr[parent(i)]);
        i = parent(i);
    }
}

int MaxHeap::extractMax()
{
    if (size == 1)
    {
        size--;
        return arr[0];
    }

    int root = arr[0];
    arr[0] = arr[size - 1];
    size--;
    maxHeapify(0);
    return root;
}

void MaxHeap::print()
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Node " << arr[i] << ":\n";
        if (i == 0)
        {
            std::cout << "No parent\n";
        }
        else
        {
            std::cout << "Parent: " << arr[parent(i)] << "\n";
        }

        if (left(i) >= size)
        {
            std::cout << "No left child\n";
        }
        else
        {
            std::cout << "Left child: " << arr[left(i)] << "\n";
        }

        if (right(i) >= size)
        {
            std::cout << "No right child\n";
        }
        else
        {
            std::cout << "Right child: " << arr[right(i)] << "\n";
        }
        std::cout << "--------------------------------------------\n";
    }
}