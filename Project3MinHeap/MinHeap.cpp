#include "MinHeap.h"

// Constructor
MinHeap::MinHeap() {

    heap = new VacationData[20000];
    numElements = 0;

}

// insert element into min heap
void MinHeap::Insert(VacationData k) {

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

void MinHeap::Swap(VacationData parent, VacationData child, int index) {

    heap[(index - 1) / 2] = child;
    heap[index] = parent;

}

// calculate the differences between the users budget and the element inserted
void MinHeap::CalculateDifference(VacationData& element) {

    if (element.month != d.month) {
        element.difference += 1;
    }

    element.difference += abs(d.duration - element.duration);
    element.difference += abs(d.age - element.age);

    if (element.gender != d.gender) {
        element.difference += 1;
    }
    if (element.accommodation != d.accommodation) {
        element.difference += 1;
    }

    element.difference += abs(d.budget - element.budget);

}

void MinHeap::SetParameters(string _month, int _duration, int _age, string _gender, string _accomodation, double _budget) {

    d.month = _month;
    d.duration = _duration;
    d.age = _age;
    d.gender = _gender;
    d.accommodation = _accomodation;
    d.budget = _budget;

}

// returns the root
VacationData MinHeap::Peek() {

    return heap[0];
}




