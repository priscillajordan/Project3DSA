#include "MinHeap.h"

// Constructor
MinHeap::MinHeap() {

    heap = new Place[20000];
    differences = new double[20000];
    numElements = 0;

}

// Insert element in heap
// O(log n)
void MinHeap::Insert(Place k) {

    int i = numElements;
    numElements++;
    heap[i] = k;

    // If parent is greater than child, swap elements
    while(i != 0 && heap[(i - 1) / 2].cost > heap[i].cost) {
        Swap(heap[(i - 1) / 2], heap[i], i);
    }

}

void MinHeap::Swap(Place parent, Place child, int index) {

    heap[(index - 1) / 2] = child;
    heap[index] = parent;

}

void MinHeap::CalculateDifference(double budget) {

}




