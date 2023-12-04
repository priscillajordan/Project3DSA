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

//return the struct with the lowest difference calculated between user values and its entries
VacationData recommendPlace(HashMap hashmap, VacationData userEntry) 
{
    double minDifference = 1000000; //random placeholder value to start with a really large number 

    VacationData structToRecommend;

    for (int i = 0; i < HashMap::capacity; i++)    //iterate through number of keys 
    {
        for (auto& entry : hashmap.theMap[i])  
        {
             vector<VacationData> vacations = entry.second;

            for (auto& it : vacations)    //go through every value in the vector 
            {
                //calculate the difference between each variable in the struct and total it 
                double difference = abs(userEntry.age - it.age) + abs(userEntry.budget - it.budget) + abs(userEntry.duration - it.duration);
                //for string variables, if it's not a match, just add 1
                if(userEntry.gender != it.gender) 
                { 
                    difference += 1; 
                }
                if(userEntry.month != it.month) 
                { 
                    difference += 1; 
                }
                if(userEntry.accommodation != it.accommodation) 
                { 
                    difference += 1; 
                }

                //compare current difference with minimum to find struct with closest match   
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
HashMap populateHashMap(vector<VacationData> vacationVector) 
{
    HashMap hashmap;

    //iterate over vectors to populate hashmap 
    for (auto& it : vacationVector) 
    {
        vector<VacationData> tempVector;
        //if city already exists in hashmap, append VacationData to vector before inserting it in hashmap 
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
    vector<VacationData> vacationVector;
    VacationData userInput;   //user input information 
    VacationData place;   //csv file information

    //this is where front-end goes 
    userInput.month = "November";
    userInput.duration = 15;
    userInput.age = 49;
    userInput.gender = "Male";
    userInput.accommodation = "Eco-Lodge";
    userInput.budget = 45438.48;

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

        //read in the data
        getline(inputString, place.city, ',');
        getline(inputString, place.month, ',');
        getline(inputString, tempString, ',');
        place.duration = atoi(tempString.c_str());
        getline(inputString, tempString, ',');
        place.age = atoi(tempString.c_str());
        getline(inputString, place.gender, ',');
        getline(inputString, place.accommodation, ',');
        getline(inputString, tempString, ',');
        place.budget = atof(tempString.c_str());

        vacationVector.push_back(place);

        line = "";
    }

    //build hashmap from the csv data table 
    HashMap hashmap = populateHashMap(vacationVector);

    VacationData toRecommend = recommendPlace(hashmap, userInput);   //get recommended place

    cout << "Vacation city: " << toRecommend.city << endl;
    cout << "Info: " << toRecommend.month << toRecommend.age << toRecommend.gender << toRecommend.budget << endl; 
    

    return 0;
}