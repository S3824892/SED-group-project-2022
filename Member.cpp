#include <iostream>

#include "Member.h"

void Member::viewRequestList() {
    for (Request r: requestList) {
        cout << r.getOccupant().username << " requested to stay at house " << r.getHouse().getId() << '\n';
    }
}

void Member::respondRequest() {
    int tempID;
    char rep;
    cout << "Input request ID:";
    cin >> tempID;
    cout << "Accept/Reject request? (A/R)";
    cin >> rep;
    if (rep == 'A') {
        for (Request r: requestList) {
            if (r.getId() == tempID) {
                r.getHouse().setOccupateStatus(true);
            }
        }
    }
}

void Member::checkAvailability(House h) {
    if (h.getOccupateStatus()) {
        cout << "This house is unavailable!\n";
    } else {
        cout << "This house is available!\n";
    }
}

int User::addMember() {
    std::fstream myfile;
    myfile.open("user.dat", std::ios::out);
    if (!myfile.is_open()) {
        cout << "Fail to create/open file \n";
        return -1;
    } else {//Get the username and password from console and save to file

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
    return 0;
}