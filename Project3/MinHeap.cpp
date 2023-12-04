#include "MinHeap.h"

// Constructor
MinHeap::MinHeap() {

    // heap is initialized as having 20000 elements
    heap = new VacationData[20000];
    numElements = 0;

}

// insert element into min heap
void MinHeap::Insert(VacationData element) 
{
    // sets difference for element
    CalculateDifference(element);
    int i = numElements;
    numElements++;
    heap[i] = element;

    // If parent is greater than child, swap elements
    while(i != 0 && heap[(i - 1) / 2].difference > heap[i].difference) {
        Swap(heap[(i - 1) / 2], heap[i], i);
        i = (i - 1) / 2;
    }

}

// swaps parent and child if parent > child
void MinHeap::Swap(VacationData parent, VacationData child, int index) {

    // (index - 1)/2 is the index of the parent, this sets that index to the child element
    heap[(index - 1) / 2] = child;
    // the child index becomes the parent
    heap[index] = parent;

}

// calculate the differences between the users budget and the element inserted
void MinHeap::CalculateDifference(VacationData& element) {

    // if the user input month and the data element month are different, 1 gets added to the difference
    if (element.month != userData.month) {
        element.difference += 1;
    }

    // the difference from the user input for age and duration are added to difference for that element
    element.difference += abs(userData.duration - element.duration);
    element.difference += abs(userData.age - element.age);

    // if the user input gender and accomodation and the data element gender and accomodation are different, 1 gets added to the difference
    if (element.gender != userData.gender) {
        element.difference += 1;
    }
    if (element.accommodation != userData.accommodation) {
        element.difference += 1;
    }

    // if the budgets are different, the difference between the budgets are added to the difference
    element.difference += abs(userData.budget - element.budget);

}

// sets parameters based on user input
void MinHeap::SetParameters(string _month, int _duration, int _age, string _gender, string _accomodation, double _budget) {

    userData.month = _month;
    userData.duration = _duration;
    userData.age = _age;
    userData.gender = _gender;
    userData.accommodation = _accomodation;
    userData.budget = _budget;

}

// returns the root
VacationData MinHeap::Peek() {

    return heap[0];
}




