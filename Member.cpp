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
    void SearchAvailableHouses(int member_id, int start_time, int end_time, string city){
        // Check if the city is available
        if (std::find(AVAILABLE_CITIES.begin(), AVAILABLE_CITIES.end(), city)== AVAILABLE_CITIES.end()){
          cout << "Error: City is not available." << "\n";
          return;
       }
        cout << "ID\tLocation\tDescription\tHouse Rating\tOwner ID" << "\n";
        for (auto& h : houses_){
          if (h.info().location()== city && h.is_available()&& h.owner_id()!= member_id &&
              members_[member_id].credit_points()>= h.requestors().size()* (end_time - start_time + 1)&&
              members_[member_id].occupier_rating()>= min_occupier_rating){
            cout << h.id()<< "\t" << h.info().location()<< "\t" << h.info().description()<< "\t"
                      << h.house_rating()<< "\t" << h.owner_id()<< "\n";
         }
       }
    }

    //Rate houses
    void RateHouse(int occupier_id, int house_id, int score, string comment){
      // Check if the occupier has occupied the house
      if (std::find(houses_[house_id].occupiers().begin(), houses_[house_id].occupiers().end(), occupier_id)== houses_[house_id].occupiers().end()){
        cout << "Error: Occupier has not occupied this house." << "\n";
        return;
     }
    Review review;
      review.id = reviews_.size();
      review.house_id = house_id;
      review.occupier_id = occupier_id;
      review.score = score;
      review.comment = comment;
      reviews_.push_back(review);

      // Update occupier rating
      int total_score = 0;
      int num_reviews = 0;
      for (auto& r : reviews_){
        if (r.occupier_id == occupier_id){
          total_score += r.score;
          num_reviews++;
       }
     }
      members_[occupier_id].SetOccupierRating(total_score / num_reviews);

      // Update house rating
      total_score = 0;
      num_reviews = 0;
      for (auto& r : reviews_){
        if (r.house_id == house_id){
          total_score += r.score;
          num_reviews++;
       }
     }
      houses_[house_id].SetHouseRating(total_score / num_reviews);
    }    
        return 0;
    }
};
