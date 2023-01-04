#include <iostream>
#include <fstream>
#include <string.h>
using std::string;
using std::cin;
using std::cout;

class House{
protected:
    string HName;
    string City;
    int HouseRating;
    bool occupateStatus;
    int minScore;
public:
    House(string HName = "", string City = "", int minScore = 0,
            int HouseRating = 0, bool occupated = false) 
        : HName(HName), City(City), HouseRating(HouseRating), occupateStatus(occupateStatus),minScore(minScore){};

    
    int addHouse() {
        std::fstream myfile;
        myfile.open("House.dat", std::ios::out);
        if (!myfile.is_open()) { 
            cout << "Fail to create/open file \n";
            return -1;
        }else{
            cout << std::endl << "INPUT HOUSE DETAILS" << std::endl;
            cout << "HOUSE NAME: ";
            getline(cin, HName);
            myfile << HName;
            cout << "CITY: ";
            getline(cin, City);
            myfile << City;
            cout << "MINIMUM RATING: ";
            cin >> minScore;
            myfile << minScore;
            occupateStatus = false;
            myfile << occupateStatus;
            myfile.close();
        }
    };

    int removeHouse(){
        std::fstream myfile;
        myfile.open("House.dat", std::ios::out);
        int choice = 0;
        if (!myfile.is_open()) { 
            cout << "Fail to create/open file \n";
            return -1;
        }else{
            cout << "Do you want to unlist your house? \n";
            cout << "1. Yes \n";
            cout << "2. No \n";
            cin >> choice;
            if (int choice = 1){
                cout << 
            }
    };
};