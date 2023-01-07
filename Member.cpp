#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
#define FILE_NAME "user.dat"

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
    int addMember(){
        std::fstream myfile;
        myfile.open("user.dat", std::ios::out); 
        if (!myfile.is_open()) { 
            cout << "Fail to create/open file \n";
            return -1;
        }else{//Get the username and password from console and save to file

            //adding username
            cout << "Enter your username: ";
            cin >> username; //ignore previous '\n' entered by user
            getline(cin, username); //read a line from console
            myfile << username;

            //adding password
            cout << "Enter the password: ";
            cin >> password; //ignore previous '\n' entered by user
            getline(cin, password); //read a line from console
            myfile << username;
            myfile.close();
            cout << "Saved to the file! \n";
            creditPoint += 500;
        }
    //Search
void SearchHouses(int member_id, int start_time, int end_time, string city){
    // Check if the city is available
    if (city != "Hanoi" || city != "Hue" || city !="Sai Gon"){
      cout << "Error: City is not available." << "\n";
      return;
   }
    cout << "ID\tLocation\tDescription\tHouse Rating\tOwner ID" << "\n";
    for (House& h : houses){
      if (h.City()== city && h.occupateStatus()&& h.owner_id()!= Member.id &&
          members[member_id].credit_points()>= h.requestors().size()* (end_time - start_time + 1)&&
          members[member_id].occupier_rating()>= min_occupier_rating){
        cout << h.id()<< "\t" << h.info().location()<< "\t" << h.info().description()<< "\t"
                  << h.house_rating()<< "\t" << h.owner_id()<< "\n";
     }
   }
}

//Rate Occupiers
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
