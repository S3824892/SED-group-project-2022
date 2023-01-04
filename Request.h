#ifndef REQUEST_H
#define REQUEST_H

#include <iostream>
#include "House.h"
#include "Member.h"

class Request {
protected:
    int id;
    Member occupant;
    House house;
public:
    Request(int id, Member occupant, House house);

    int getId();

    Member getOccupant();

    House getHouse();
};

#endif