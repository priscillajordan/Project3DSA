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
void HashMap::insert(string key,const vector<VacationData>& value) 
{
    int hashCode = hashFunction(key);
    auto& bucket = theMap[hashCode];

    // for (auto& entry : bucket) {
    //     if (entry.first == key) {
    //         entry.second = value;
    //         return;
    //     }
    // }

    bucket.push_back(make_pair(key, value));
}


//search for key, value pair in vector 
bool HashMap::search(string key, vector<VacationData>& value)  
{
    int hashCode = hashFunction(key);
    //const auto& bucket = theMap[hashCode];

    for (auto& it : theMap[hashCode]) {
        if (it.first == key) 
        {
            value = it.second;
            return true;
        }
    }

    return false;
}



// //insert value into the hashmap with key, value pair
// void HashMap::insert(string key, vector<VacationData> value) 
// {
//     if(!search(key, value))   //to not insert duplicate keys
//     {
//         int hashCode = hashFunction(key);
//         map[hashCode].push_back(make_pair(key, value));
//     }
// }

// //search for key, value pair in vector
// bool HashMap::search(string key, vector<VacationData>& value)  
// {
//     int hashCode = hashFunction(key);
//     //iterate through vector and compare first val of each pair to key 
//     for (auto& it : map[hashCode]) 
//     {
//         if (it.first == key) 
//         {
//             value = it.second;
//             return true;
//         }
//     }    return false;
// }



// std::vector<VacationData> HashMap::get(const std::string& key)  {
//     int hashCode = hashFunction(key);
    
//     // Iterate through the list of key-value pairs in the specified bucket
//     for (const auto& pair : map[hashCode]) {
//         if (pair.first == key) {
//             // Return the vector of values associated with the key
//             return pair.second;
//         }
//     }

//     // Return an empty vector if the key is not found
//     return {};
// }

// std::vector<std::string> HashMap::getAllKeys()  {
//     std::vector<std::string> keys;

//     // Iterate over all buckets in the map
//     for (const auto& bucket : map) {
//         // Iterate over all key-value pairs in the bucket
//         for (const auto& pair : bucket) {
//             keys.push_back(pair.first);
//         }
//     }

//     return keys;
// }
