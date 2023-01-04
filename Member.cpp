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
    };
};
