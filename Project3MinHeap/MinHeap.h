#include <iostream>
using namespace std;

// Destination values
struct Place {
    string destination;
    string month;
    int duration;
    int age;
    string gender;
    string accomodation;
    double cost;

    double difference;
};

class MinHeap {

private:
    Place *heap; // MinHeap Array
    int numElements;
    double _budget;

public:
    MinHeap();
    void Insert(Place k);
    void Swap(Place parent, Place child, int index);
    void CalculateDifference(Place& elements);
    void SetBudget(double budget);
    Place Peek();
};
