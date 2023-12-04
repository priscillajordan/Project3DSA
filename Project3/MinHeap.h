#include <iostream>
#include "VacationStruct.h"
using namespace std;

class MinHeap {

private:
    VacationData *heap; // MinHeap Array
    VacationData userData;
    int numElements;


public:
    MinHeap();
    void Insert(VacationData element); // insert value into heap
    void Swap(VacationData parent, VacationData child, int index); // swap values in heap
    void CalculateDifference(VacationData& elements); // calculate difference based on user input
    //initialize user input
    void SetParameters(string _month, int _duration, int _age, string _gender, string _accomodation, double _budget);
    VacationData Peek(); // returns heap[0]
};
