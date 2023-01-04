#include <iostream>
#include "House.h"

House::House(Member owner, int id, string location, string descriptions, double rating, double minOccuRating,
             bool listed, bool occupied) {
    this->owner = owner;
    this->id = id;
    this->location = location;
    this->descriptions = descriptions;
    this->rating = rating;
    this->minOccuRating = minOccuRating;
    this->listed = listed;
    this->occupied = occupied;
}

Member House::getMember() {
    return owner;
}

int House::getId() {
    return id;
}

string House::getLocation() {
    return location;
}

string House::getDescriptions() {
    return descriptions;
}

double House::getRating() {
    return rating;
}

double House::getMinOccuRating() {
    return minOccuRating;
}

bool House::getListed() {
    return listed;
}

bool House::getOccupied() {
    return occupied;
}

void House::setOccupied(bool o) {
    this->occupied = o;
}