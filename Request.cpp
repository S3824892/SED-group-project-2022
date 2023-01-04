#include <iostream>
#include "Request.h"

Request::Request(int id, Member occupant, House house) {
    this->id = id;
    this->occupant = occupant;
    this->house = house;
}

int Request::getId() {
    return id;
}

Member Request::getOccupant() {
    return occupant;
}

House Request::getHouse() {
    return house;
}
