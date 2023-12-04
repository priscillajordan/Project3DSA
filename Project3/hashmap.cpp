#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include "hashmap.h"

using namespace std; 

//constructor initializing the size of hashmap to capacity
HashMap::HashMap() 
{
    theMap.resize(capacity); 
}


//hash function to convert key into a hash code
//hash function inspired from here: https://stackoverflow.com/questions/8317508/hash-function-for-a-string
int HashMap::hashFunction(string key) 
{
    int hash = 0;
    for (int i = 0; i < key.length(); i++) 
    {
        hash = abs((hash * 51) + key[i]);
    }
    return hash % capacity;
}


//insert value into hashmap with key value pair
void HashMap::insert(string key, const vector<VacationData>& value) 
{
    int hashCode = hashFunction(key);
    auto& map = theMap[hashCode];

    //insert value where key is the hashcode and value is vector of structs
    map.push_back(make_pair(key, value));
}


//search for key, value pair in vector and return true if found
bool HashMap::search(string key, vector<VacationData>& value)  
{
    int hashCode = hashFunction(key);

    //iterate through hash map and find the key's value 
    for (auto& it : theMap[hashCode]) {
        if (it.first == key) 
        {
            value = it.second;
            return true;
        }
    }

    return false;
}
