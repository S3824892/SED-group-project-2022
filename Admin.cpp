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
  cout << "ID  | Name" << endl;
  for (const auto& member : members_) {
    cout << member.GetId() << " | " << member.GetName() << endl;
  }
}

// View all houses in the system
void ViewAllHouses() {
  cout << "ID  | Location" << endl;
  for (const auto& house : houses_) {
    cout << house.GetId() << " | " << house.GetLocation() << endl;
  }
}

// View all house listings in the system 
void ViewAllHouseListings() {
  cout << "ID  | House ID | Member ID | Start       | End         | Min Occupier Rating" << endl;
  for (const auto& listing : listings_) {
    cout << listing.GetId() << " | " << listing.GetHouseId() << " | " << listing.GetMemberId() << " | "
              << listing.GetStart().ToString() << " | " << listing.GetEnd().ToString() << " | "
              << listing.GetMinOccupierRating() << endl;
  }
}
}
