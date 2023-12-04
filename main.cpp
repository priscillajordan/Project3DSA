#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <list>
#include <utility>
#include <string>
#include <cmath>
#include <algorithm>
#include "VacationStruct.h"
#include "hashmap.h"

using namespace std; 

//return the struct with the lowest difference between user values and its entries
VacationData recommendPlace(HashMap hashmap, VacationData userData) 
{
    double minDifference = 1000000; //random placeholder value to start with a really large number 

    VacationData structToRecommend;

    for (int i = 0; i < HashMap::capacity; i++) 
    {
        //const auto& bucket = hashmap.theMap[i];

        for (auto& entry : hashmap.theMap[i]) {

             vector<VacationData> vacations = entry.second;

            for (auto& it : vacations) 
            {
                //calculate the difference between each variable and total it 
                double difference = abs(userData.age - it.age) + abs(userData.budget - it.budget) + abs(userData.duration - it.duration);

                if(userData.gender != it.gender) 
                { 
                    difference += 1; 
                }
                if(userData.month != it.month) 
                { 
                    difference += 1; 
                }

                if(userData.accommodation != it.accommodation) 
                { 
                    difference += 1; 
                }

                if(difference < minDifference) {
                    minDifference = difference; 
                    structToRecommend = it; 
                }
            }
        }
    }


    return structToRecommend;
}
    

//fill hashmap structure with structs of vacation data, where key is city and value is vector of structs
HashMap populateHashMap(vector<VacationData> data) 
{
    HashMap hashmap;

    for (auto& it : data) 
    {
        vector<VacationData> tempVector;
        //if city already exists in hashmap, then append to the vector before inserting it in hashmap 
        if (hashmap.search(it.city, tempVector)) 
        {
            tempVector.push_back(it);
            hashmap.insert(it.city, tempVector);
        } 
        //insert a new entry in the hashmap
        else {
            hashmap.insert(it.city, {it});
        }
    }

    return hashmap;
}


int main() 
{ 
    vector<VacationData> data;

    VacationData userInput;
    VacationData spot;


    userInput.month = "July";
    userInput.duration = 5;
    userInput.age = 43;
    userInput.gender = "Male";
    userInput.accommodation = "Hotel";
    userInput.budget = 15213.13;

    ifstream inputFile;
    inputFile.open("travel_data.csv");

    if (!inputFile.is_open()) {
        cout << "Couldn't open file." << endl;
        return -1;
    }

    string line = "";

    //parsing csv file inspired from here: https://www.youtube.com/watch?v=NFvxA-57LLA&t=642s
    while (getline(inputFile, line)) 
    {
        //define variables corresponding to factors 
        string city, month, gender, accomodation, tempString = "";
        int duration, age; 
        double budget; 

        stringstream inputString(line);

        getline(inputString, spot.city, ',');
        getline(inputString, spot.month, ',');
        getline(inputString, tempString, ',');
        spot.duration = atoi(tempString.c_str());
        getline(inputString, tempString, ',');
        spot.age = atoi(tempString.c_str());
        getline(inputString, spot.gender, ',');
        getline(inputString, spot.accommodation, ',');
        getline(inputString, tempString, ',');
        spot.budget = atof(tempString.c_str());

        data.push_back(spot);

        line = "";
    }

    HashMap hashmap = populateHashMap(data);

    VacationData recommendation = recommendPlace(hashmap, userInput); 

    //for(int i = 0; i < 5; i++) {
        cout << "Recommended vacation city: " << recommendation.city << endl;
        cout << "Info: " << recommendation.month << recommendation.age << recommendation.gender << recommendation.budget << endl; 
    //}
    

    return 0;
}