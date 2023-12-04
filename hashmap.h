#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include "VacationStruct.h"

using namespace std; 

//class object for a hashmap 
class HashMap 
{
private:

    int hashFunction(string key) ; 
        
public:

    static const int capacity = 32;  //there are 32 cities, so can't be more than 32 keys 
    vector<list<pair<string, vector<VacationData>>>> theMap;   //data structure defining the hashmap with list for separate chaining
    HashMap();
    void insert( string key, const vector<VacationData>& value); 
    bool search( string key, vector<VacationData>& value); 

};