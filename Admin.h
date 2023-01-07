#ifndef ADMIN_H_
#define ADMIN_H_

#include <iostream>
#include <string>

#include "member.h" // Replace with the header file for the Member class

class Admin : public Member {
private:
  std::string Admin_username;
  std::string Admin_password;

public:
  bool LogInAdmin();
  void ViewAllMembers();
  void ViewAllHouses();
  void ViewAllHouseListings();
};

#endif // ADMIN_H_
