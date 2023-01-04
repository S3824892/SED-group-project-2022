#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Request.h"
#include "House.h"

using namespace std;
#define FILE_NAME "user.dat"

class Member {
protected:
    string username;
    string password;
    int id;
    int creditPoint;
    int occupierScore;
    int phoneNumber;
    bool occupyStatus;
    vector<Request> requestList;

public:
    Member(string username = "", string password = "", int creditPoint = 0,
           int occupierScore = 0, int phoneNumber = 0, bool occupyStatus = false)
            : username(username), password(password), creditPoint(creditPoint), occupierScore(occupierScore),
              phoneNumber(phoneNumber), occupyStatus(occupyStatus) {};

    friend class User;

    void viewRequestList();

    void respondRequest();

    void checkAvailability(House h);
};

class User : public Member {
protected:
    std::vector<Member> members{};

public:
    User();

    int addMember();
};

#endif