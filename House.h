#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include "Member.h"
#define FILE_NAME "House.dat"

class House {
protected:
    string HName;
    Member owner;
    int id;
    string City;
    string descriptions;
    double HouseRating;
    double minScore;
    bool listed;
    bool occupateStatus;
public:
    House();

    House(Member owner, int id, string City, string descriptions, double HouseRating, double minScore, bool listed,
          bool occupateStatus);

    Member getMember();

    int getId();

    string getCity();

    string getDescriptions();

    double getHouseRating();

    double getMinScore();

    bool getListed();

    bool getOccupateStatus();

    void setOccupateStatus(bool o);

    void readHouse();

    void displayHouse();
};

int writeToFile(House house, string filename);

int readFromFile(string filename);

int deleteFromFile(string filename);

#endif