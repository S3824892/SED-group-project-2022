#ifndef __USER_H__
#define __USER_H__

#include <iostream>
#include <vector>
#include <string>

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
    int addMember();
    void SearchHouses(int member_id, int start_time, int end_time, const std::string& city);
    void RateOccupier(int owner_id, int occupier_id, int score, const std::string& comment);
};

#endif
