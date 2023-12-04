#include <iostream>
using namespace std;

// Destination values
struct Place {
    string location;
    string month;
    double cost;
    double difference;
};

class MinHeap {

private:
    Place *heap; // MinHeap Array
    double *differences;
    int numElements;

public:
    MinHeap();
    void Insert(Place k);
    void Swap(Place parent, Place child, int index);
    void CalculateDifference(double budget);
};
