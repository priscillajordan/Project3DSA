#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include "VacationStruct.h"

using namespace std; 

class HashMap {
private:

    int hashFunction(string key) ; 

        
public:
    static const int capacity = 100;

    vector<list<pair<string, vector<VacationData>>>> theMap;

    HashMap();// : theMap(capacity) {}

    void insert( string key, const vector<VacationData>& value); 

    bool search( string key, vector<VacationData>& value) ; 

   // const vector<list<pair<string, vector<VacationData>>>>& getBuckets() ; 


};