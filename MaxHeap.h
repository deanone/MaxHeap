#ifndef MAX_HEAP_H
#define MAX_HEAP_H

class MaxHeap
{
    int* arr;
    int capacity;
    int size;

public:
    /*!
     * Constructor.
     * @param capacity the capacity of the max heap.
     */
    MaxHeap(int capacity);

    /*!
     * Destructor. 
     */
    ~MaxHeap();

    /*!
     * Returns the parent of a node i.
     * @param i the index of the node for which its parent is requested. 
     */
    int parent(int i);

    /*!
     * Returns the left child of a node i.
     * @param i the index of the node for which its left child is requested. 
     */
    int left(int i);

    /*!
     * Retursn the right child of a node i.
     * @param i the index of the node for which its right child is requested.
     */
    int right(int i);

    /*!
     * Up heapifies the heap starting for node i. The sub-trees are assumed to be already heapified.
     * @param i the index of the node from which the up-heapify process begins. 
     */
    void maxHeapify(int i);

    /*!
     * Inserts a new value in the max heap.
     * @param val the new value to be inserted in the max heap.
     */
    void insert(int val);

    /*!
     * Extracts the maximum value of the max heap, i.e., its root. It also preserves the heap property.
     * @param the maximum value of the max heap. 
     */
    int extractMax();

    /*!
     * Simple print of heap.
     */
    void print();

};

#endif // MAX_HEAP_H