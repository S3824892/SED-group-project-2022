#include <iostream>
using namespace std;

class Admin : public Member(){
private:
string Admin_username;
string Admin_password;

public:
bool LogInAdmin() {
  cout << "Enter admin username: ";
  cin >> username;
  cout << "Enter admin password: ";
  cin >> password;
  if (Admin_username == "admin" && Admin_password == "password") {
    cout << "Login as Admin successfuly" << "/n";
    return true;
  } else {
    cout << "Error: Incorrect username or password." << "/n";
    return false;
  }
}
  
// View all members in the system
void ViewAllMembers() {
  std::cout << "ID  | Name" << std::endl;
  for (const auto& member : members_) {
    std::cout << member.GetId() << " | " << member.GetName() << std::endl;
  }
}

// View all houses in the system
void ViewAllHouses() {
  std::cout << "ID  | Location" << std::endl;
  for (const auto& house : houses_) {
    std::cout << house.GetId() << " | " << house.GetLocation() << std::endl;
  }
}

// View all house listings in the system 
void ViewAllHouseListings() {
  std::cout << "ID  | House ID | Member ID | Start       | End         | Min Occupier Rating" << std::endl;
  for (const auto& listing : listings_) {
    std::cout << listing.GetId() << " | " << listing.GetHouseId() << " | " << listing.GetMemberId() << " | "
              << listing.GetStart().ToString() << " | " << listing.GetEnd().ToString() << " | "
              << listing.GetMinOccupierRating() << std::endl;
  }
}
}
