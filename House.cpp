#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;
#define FILE_NAME "House.dat"

class House{
protected:
    Member* owner;  // Pointer to the owner of the house
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
        cin >> occupateStatus;
        HouseRating = 5;
        cout << "Minimum Score: ";
        cin >> minScore;
    };

    void displayHouse() {
        cout << left << setw(10) << HName
             << left << setw(10) << owner->GetId()  // Use member function to get owner's ID
             << left << setw(10) << City
             << left << setw(10) << occupateStatus
             << left << setw(10) << HouseRating
             << left << setw(10) << setprecision(5) << minScore << endl;
    }

    // Member functions to set/get the values of the member variables
    void SetOwner(Member* owner) { this->owner = owner; }
    Member* GetOwner() const { return owner; }
    void SetName(const std::string& name) { HName = name; }
    std::string GetName() const { return HName; }
    void SetCity(const std::string& city) { City = city; }
    std::string GetCity() const { return City; }
    void SetOccupyStatus(bool status) { occupateStatus = status; }
    bool GetOccupyStatus() const { return occupateStatus; }
    void SetHouseRating(int rating) { HouseRating = rating; }
    int GetHouseRating() const { return HouseRating; }
    void SetMinScore(int min_score) { minScore = min_score; }
    int GetMinScore() const { return minScore; }
};

int writeToFile(House house, string filename) {
    house.readHouse();
    fstream file;
    /// write to file
    file.open(filename, ios::out|ios::binary|ios::app);
    if (!file){
        cout << "Error writing file" << endl;
        return -1;
    }
    file.write((char*)&house,sizeof(house));
    file.close();
    cout << "SAVED YOUR HOUSE DETAILS" << endl;
    return 0;
}

int readFromFile(string filename) {
    House house;
    fstream file;
    file.open(filename,ios::in|ios::binary);
    if (!file){
        cout << "Error opening file" << endl;
        return -1;
    }
    if (file.read((char*)&house,sizeof(house))) {
        cout << endl
             << left << setw(10) << "HOUSE NAME"
             << left << setw(10) << "CITY"
             << left << setw(10) << "OCCUPATION STATUS"
             << left << setw(10) << "HOUSE RATING"
             << left << setw(10) << "MINIMUM SCORE REQUIRED"  << endl;
        while(!file.eof()) {
            house.displayHouse();
            file.read((char*)&house,sizeof(house));
        }
    }
    else {
        cout << "Error reading from file" << endl;
        return -1;
    }
    file.close();
    return 0;
}
int deleteFromFile(string filename){
    House house;
    string houseName;
    cout << "Please input house name you want to delete: ";
    cin >> houseName;
    fstream file;
    file.open(filename, ios::in | ios::binary);
    if (!file){
        cout << "Error opening file" << endl;
        return -1;
    }

    // Read all houses from the file into a vector
    vector<House> houses;
    while (file.read((char*)&house, sizeof(house))) {
        houses.push_back(house);
    }
    file.close();

    // Erase the house with the matching name from the vector
    houses.erase(std::remove_if(houses.begin(), houses.end(), [&](const House& h) {
        return h.GetName() == houseName;
    }), houses.end());

    // Re-write the updated vector to the file
    file.open(filename, ios::out | ios::binary | ios::trunc);
    for (const auto& h : houses) {
        file.write((char*)&h, sizeof(h));
    }
    file.close();

    return 0;
}
