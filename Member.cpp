#include <iostream>
#include <fstream>
#include <vector>

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
                r.getHouse().setOccupied(true);
            }
        }
    }
}

void Member::checkAvailability(House h) {
    if (h.getOccupied()) {
        cout << "This house is unavailable!\n";
    } else {
        cout << "This house is available!\n";
    }
}