#include <iostream>
<<<<<<< HEAD
#include "House.h"

using namespace std;

House::House(Member owner, int id, string City, string descriptions, double HouseRating, double minScore, bool listed,
             bool occupateStatus) {
    this->owner = owner;
    this->id = id;
    this->City = City;
    this->descriptions = descriptions;
    this->HouseRating = HouseRating;
    this->minScore = minScore;
    this->listed = listed;
    this->occupateStatus = occupateStatus;
}

Member House::getMember() {
    return owner;
}

int House::getId() {
    return id;
}

string House::getCity() {
    return City;
}

string House::getDescriptions() {
    return descriptions;
}

double House::getHouseRating() {
    return HouseRating;
}

double House::getMinScore() {
    return minScore;
}

bool House::getListed() {
    return listed;
}

bool House::getOccupateStatus() {
    return occupateStatus;
}

void House::setOccupateStatus(bool o) {
    this->occupateStatus = o;
}

void House::readHouse() {
    cout << endl << "INPUT HOUSE DETAILS" << endl;
    cout << "House Name: ";
    cin >> HName;
    cout << "City: ";
    cin >> City;
    cout << "Occupation Status: ";
    occupateStatus = false;
    HouseRating = 5;
    cout << "Minimum Score: ";
    cin >> minScore;
}

void House::displayHouse() {
    cout << left << setw(10) << HName
         << left << setw(10) << City
         << left << setw(10) << occupateStatus
         << left << setw(10) << HouseRating
         << left << setw(10) << setprecision(5) << minScore << endl;
}
=======
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;
#define FILE_NAME "House.dat"

class House{
protected:
    string HName;
    string City;
    int HouseRating;
    bool occupateStatus;
    int minScore;
public:
    House();
    
    void readHouse() {
        cout << endl << "INPUT HOUSE DETAILS" << endl;
        cout << "House Name: ";
        cin >> HName;
        cout << "City: ";
        cin >> City;
        cout << "Occupation Status: ";
        occupateStatus = false;
        HouseRating = 5;
        cout << "Minimum Score: ";
        cin >> minScore;
    };

    void displayHouse() {
        cout << left << setw(10) << HName
             << left << setw(10) << City
             << left << setw(10) << occupateStatus
             << left << setw(10) << HouseRating
             << left << setw(10) << setprecision(5) << minScore << endl;
    }
};
>>>>>>> main

int writeToFile(House house, string filename) {
    house.readHouse();
    fstream file;
    /// write to file
<<<<<<< HEAD
    file.open(filename, ios::out | ios::binary | ios::app);
    if (!file) {
        cout << "Error writing file" << endl;
        return -1;
    }
    file.write((char *) &house, sizeof(house));
=======
    file.open(filename, ios::out|ios::binary|ios::app);
    if (!file){
        cout << "Error writing file" << endl;
        return -1;
    }
    file.write((char*)&house,sizeof(house));
>>>>>>> main
    file.close();
    cout << "SAVED YOUR HOUSE DETAILS" << endl;
    return 0;
}

int readFromFile(string filename) {
    House house;
    fstream file;
<<<<<<< HEAD
    file.open(filename, ios::in | ios::binary);
    if (!file) {
        cout << "Error opening file" << endl;
        return -1;
    }
    if (file.read((char *) &house, sizeof(house))) {
=======
    file.open(filename,ios::in|ios::binary);
    if (!file){
        cout << "Error opening file" << endl;
        return -1;
    }
    if (file.read((char*)&house,sizeof(house))) {
>>>>>>> main
        cout << endl
             << left << setw(10) << "HOUSE NAME"
             << left << setw(10) << "CITY"
             << left << setw(10) << "OCCUPATION STATUS"
             << left << setw(10) << "HOUSE RATING"
<<<<<<< HEAD
             << left << setw(10) << "MINIMUM SCORE REQUIRED" << endl;
        while (!file.eof()) {
            house.displayHouse();
            file.read((char *) &house, sizeof(house));
        }
    } else {
=======
             << left << setw(10) << "MINIMUM SCORE REQUIRED"  << endl;
        while(!file.eof()) {
            house.displayHouse();
            file.read((char*)&house,sizeof(house));
        }
    }
    else {
>>>>>>> main
        cout << "Error reading from file" << endl;
        return -1;
    }
    file.close();
    return 0;
}

<<<<<<< HEAD
int deleteFromFile(string filename) {
=======
int deleteFromFile(string filename){
>>>>>>> main
    House house;
    string houseName;
    cout << "Please input house name you want to delete: ";
    cin >> houseName;
    fstream file;
<<<<<<< HEAD
    file.open(filename, ios::in | ios::binary);
    if (!file) {
        cout << "Error opening file" << endl;
        return -1;
    }
    vector<string> HName;
    while (getline(file, houseName))
=======
    file.open(filename,ios::in|ios::binary);
    if (!file){
        cout << "Error opening file" << endl;
        return -1;
    }
    vector <string> HName;
    while (getline(file,houseName))
>>>>>>> main
        HName.push_back(houseName);
    file.close();
    return 0;
}