#include <iostream>
#include "VacationStruct.h"
using namespace std;

class MinHeap {

private:
    VacationData *heap; // MinHeap Array
    VacationData d;
    int numElements;


public:
    MinHeap();
    void Insert(VacationData k);
    void Swap(VacationData parent, VacationData child, int index);
    void CalculateDifference(VacationData& elements);
    void SetParameters(string _month, int _duration, int _age, string _gender, string _accomodation, double _budget);
    VacationData Peek();
};
