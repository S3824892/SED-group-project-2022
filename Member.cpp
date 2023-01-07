#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
#define FILE_NAME "Member.dat"

class Member{
protected:
    string username;
    string password;
    int creditPoint;
    int occupierScore;
    int phoneNumber;
    bool occupyStatus;
    House houses;

public:
    Member(string username = "", string password = "", int creditPoint = 0,
            int occupierScore = 0, int phoneNumber = 0, bool occupyStatus = false) 
        : username(username), password(password), creditPoint(creditPoint), occupierScore(occupierScore),
           phoneNumber(phoneNumber), occupyStatus(occupyStatus){};
    friend class User;
};



class User : public Member{
protected:
    std::vector <Member> members{};
    
public:
    User();
    int addMember() {
      std::fstream myfile;
      myfile.open(FILE_NAME, std::ios::out); 
      if (!myfile.is_open()) { 
        std::cout << "Fail to create/open file \n";
        return -1;
      } else {
        // Get the username and password from console and save to file
        std::cout << "Enter your username: ";
        std::getline(std::cin, username);
        myfile << username << std::endl;

        std::cout << "Enter the password: ";
        std::getline(std::cin, password);
        myfile << password << std::endl;

        myfile.close();
        std::cout << "Saved to the file! \n";
        creditPoint += 500;
      }

// Search for houses
void SearchHouses(int member_id, int start_time, int end_time, const std::string& city) {
  // Check if the city is available
  if (city != "Hanoi" && city != "Hue" && city != "Sai Gon") {
    std::cout << "Error: City is not available." << std::endl;
    return;
  }
  std::cout << "ID\tLocation\tDescription\tHouse Rating\tOwner ID" << std::endl;
  for (auto& h : houses_) {
    if (h.GetCity() == city && h.IsOccupyStatus() && h.GetOwnerId() != member_id &&
        members_[member_id].GetCreditPoints() >= h.GetRequestors().size() * (end_time - start_time + 1) &&
        members_[member_id].GetOccupierRating() >= h.GetMinOccupierRating()) {
      std::cout << h.GetId() << "\t" << h.GetInfo().location() << "\t" << h.GetInfo().description() << "\t"
                << h.GetHouseRating() << "\t" << h.GetOwnerId() << std::endl;
    }
  }
}

// Rate occupiers
void RateOccupier(int owner_id, int occupier_id, int score, const std::string& comment) {
  auto owner_it = std::find_if(members_.begin(), members_.end(), [&](const Member& m) {
    return m.GetId() == owner_id;
  });
  if (owner_it == members_.end()) {
    std::cout << "Error: Owner not found." << std::endl;
    return;
  }
  Member& owner = *owner_it;

  auto occupier_it = std::find_if(members_.begin(), members_.end(), [&](const Member& m) {
    return m.GetId() == occupier_id;
  });
  if (occupier_it == members_.end()) {
    std::cout << "Error: Occupier not found." << std::endl;
    return;
  }
  Member& occupier = *occupier_it;

  if (!owner.HasOccupiedHouse(occupier_id)) {
    std::cout << "Error: Occupier has not occupied a house owned by this member." << std::endl;
    return;
  }

  // Update occupier score and add review
  occupier.AddReview(score, comment);
  occupier.SetOccupierScore(occupier.GetOccupierScore() + score);
  std::cout << "Success: Occupier rating updated." << std::endl;
}

  occupier.LeaveReview(owner_id, score, comment);
  }

//Rate house
void RateHouse(int member_id, int house_id, int score, const std::string& comment) {
  auto member_it = std::find_if(members_.begin(), members_.end(), [&](const Member& m) {
    return m.GetId() == member_id;
  });
  if (member_it == members_.end()) {
    std::cout << "Error: Member not found." << std::endl;
    return;
  }
  Member& member = *member_it;

  auto house_it = std::find_if(houses_.begin(), houses_.end(), [&](const House& h) {
    return h.GetId() == house_id;
  });
  if (house_it == houses_.end()) {
    std::cout << "Error: House not found." << std::endl;
    return;
  }
  House& house = *house_it;

  if (!house.IsOccupiedBy(member_id)) {
    std::cout << "Error: Member has not occupied this house." << std::endl;
    return;
  }
  house.LeaveReview(member_id, score, comment);
}    
        return 0;
    }
};
