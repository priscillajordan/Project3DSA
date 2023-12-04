#include <iostream>
#include "MinHeap.h"
#include <fstream>
#include <sstream>
using namespace std;

int main() {

    MinHeap destinations;
    destinations.SetParameters("April", 12, 25, "Male", "Airbnb", 35676.51);
    string travelData = "/Users/christiancooper/Desktop/Project3MinHeap/travel_data.csv";
    ifstream file(travelData);

    string header;
    getline(file, header);

    string data;
    while(getline(file, data)) {

        istringstream stream(data);
        string destination;
        getline(stream, destination, ',');

        string month;
        getline(stream, month, ',');

        string duration;
        getline(stream, duration, ',');

        string age;
        getline(stream, age, ',');

        string gender;
        getline(stream, gender, ',');

        string accomodation;
        getline(stream, accomodation, ',');

        string budget;
        getline(stream, budget, ',');

        destinations.Insert({destination, month, stoi(duration), stoi(age), gender, accomodation, stod(budget)});

    }

    cout << "Destination: " << destinations.Peek().city << endl;
    cout << "Cost: " << destinations.Peek().budget << endl;

    return 0;
}
