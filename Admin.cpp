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
}
