#include "MinHeap.h"

// Constructor
MinHeap::MinHeap() {

    heap = new Place[20000];
    numElements = 0;

}

// insert element into min heap
void MinHeap::Insert(Place k) {

    CalculateDifference(k);
    int i = numElements;
    numElements++;
    heap[i] = k;

    // If parent is greater than child, swap elements
    while(i != 0 && heap[(i - 1) / 2].difference > heap[i].difference) {
        Swap(heap[(i - 1) / 2], heap[i], i);
        i = (i - 1) / 2;
    }

}

void MinHeap::Swap(Place parent, Place child, int index) {

    heap[(index - 1) / 2] = child;
    heap[index] = parent;

}

// calculate the differences between the users budget and the element inserted
void MinHeap::CalculateDifference(Place& element) {

    if (element.cost > _budget) {

        element.difference = element.cost - _budget;

    } else {

        element.difference = _budget - element.cost;

    }

}

void MinHeap::SetBudget(double budget) {

    _budget = budget;

}

// returns the root
Place MinHeap::Peek() {

    return heap[0];
}




