#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
#include "Member.h"

using std::string;

class House {
protected:
    Member owner;
    int id;
    string location;
    string descriptions;
    double rating;
    double minOccuRating;
    bool listed;
    bool occupied;
public:
    House(Member owner, int id, string location, string descriptions, double rating, double minOccuRating, bool listed,
          bool occupied);

    Member getMember();

    int getId();

    string getLocation();

    string getDescriptions();

    double getRating();

    double getMinOccuRating();

    bool getListed();

    bool getOccupied();

    void setOccupied(bool o);
};

#endif