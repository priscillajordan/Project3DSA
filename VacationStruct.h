#include <iostream>
#include <string>
#pragma once

using namespace std; 

//defines variables for each row in the csv dataset 
struct VacationData
{
    string city; 
    string month; 
    int duration; 
    int age;
    string gender;
    string accommodation;
    double budget;
    double difference; 
};
