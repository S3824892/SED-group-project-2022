#ifndef HOUSE_H
#define HOUSE_H

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

class House {
protected:
  int owner_id;
  std::string HName;
  std::string City;
  int HouseRating;
  bool occupateStatus;
  int minScore;

public:
  House();

  void readHouse();
  void displayHouse();

  // Member functions to set/get the values of the member variables
  int GetOwnerId() const { return owner_id; }
  void SetOwnerId(int owner_id) { this->owner_id = owner_id; }
  std::string GetName() const { return HName; }
  void SetName(const std::string& HName) { this->HName = HName; }
  std::string GetCity() const { return City; }
  void SetCity(const std::string& City) { this->City = City; }
  int GetRating() const { return HouseRating; }
  void SetRating(int HouseRating) { this->HouseRating = HouseRating; }
  bool IsOccupyStatus() const { return occupateStatus; }
  void SetOccupyStatus(bool occupateStatus) { this->occupateStatus = occupateStatus; }
  int GetMinScore() const { return minScore; }
  void SetMinScore(int minScore) { this->minScore = minScore; }
};

int writeToFile(House house, std::string filename);
int readFromFile(std::string filename);
int deleteFromFile(std::string filename);

#endif // HOUSE_H
