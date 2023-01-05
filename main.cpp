#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::string;

int main(){
// Welcome screen
  cout << "EEET2482/COSC2082 ASSIGNMENT" << "\n";
  cout << "VACATION HOUSE EXCHANGE APPLICATION" << "\n";
  cout << "Instructors: Mr. Linh Tran & Phong Ngo" << "\n";
  cout << "Group: Group Name" << "\n";
  cout << "sXXXXXXX, Student Name" << "\n";
  cout << "sXXXXXXX, Student Name" << "\n";
  cout << "sXXXXXXX, Student Name" << "\n";
  cout << "Use the app as 1. Guest   2. Member   3. Admin" << "\n";
  cout << "Enter your choice: ";
  int user_type;
  cin >> user_type;

  if (user_type == 1){
    // Guest user
    while (true){
      cout << "This is your menu:" << "\n";
      cout << "0. Exit" << "\n";
      cout << "1. View available houses" << "\n";
      cout << "Enter your choice: ";
      int choice;
      cin >> choice;

      if (choice == 0){
        break;
     } else if (choice == 1){
        cout << "Enter start date (YYYY-MM-DD): ";
        string start_date;
        cin >> start_date;
        cout << "Enter end date (YYYY-MM-DD): ";
        string end_date;
        cin >> end_date;
        cout << "Enter city: ";
        string city;
        cin >> city;
        system.ViewAvailableHouses(-1, start_date, end_date, city);
     } else {
        cout << "Error: Invalid menu choice." << "\n";
     }
   }
 } else if (user_type == 2){
    // Member user
    cout << "Enter username: ";
    string username;
    cin >> username;

    int member_id = -1;
    for (int i = 0; i < system.members().size(); i++){
      if (system.members()[i].personal_info().username()== username){
        member_id = i;
        break;
     }
   }

    if (member_id == -1){
      cout << "Error: Invalid username." << "\n";
      return 0;
   }

    while (true){
      cout << "This is your menu:" << "\n";
      cout << "0. Exit" << "\n";
      cout << "1. View Information" << "\n";
      cout << "2. List House" << "\n";
      cout << "3. View Available Houses" << "\n";
      cout << "4. Request to Occupy House" << "\n";
      cout << "5. View Occupy Requests" << "\n";
      cout << "6. Leave Review" << "\n";
      cout << "Enter your choice: ";
      int choice;
      cin >> choice;

      if (choice == 0){
        break;
     } else if (choice == 1){
        system.ViewMemberInfo(member_id);
     } else if (choice == 2){
        cout << "Enter start date (YYYY-MM-DD): ";
        string start_date;
        cin >> start_date;
        cout << "Enter end date (YYYY-MM-DD): ";
        string end_date;
        cin >> end_date;
        cout << "Enter points per day: ";
        int points_per_day;
        cin >> points_per_day;
        cout << "Enter minimum required occupier rating (optional, leave blank for no requirement): ";
        string min_rating_str;
        cin >> min_rating_str;
        int min_rating = -1;
        if (min_rating_str != ""){
          min_rating = std::stoi(min_rating_str);
       }
        system.ListHouse(member_id, start_date, end_date, points_per_day, min_rating);
     } else if (choice == 3){
        cout << "Enter start date (YYYY-MM-DD): ";
        string start_date;
        cin >> start_date;
        cout << "Enter end date (YYYY-MM-DD): ";
        string end_date;
        cin >> end_date;
        cout << "Enter city: ";
        string city;
        cin >> city;
        system.ViewAvailableHouses(member_id, start_date, end_date, city);
     } else if (choice == 4){
        cout << "Enter house ID: ";
        int house_id;
        cin >> house_id;
        cout << "Enter start date (YYYY-MM-DD): ";
        string start_date;
        cin >> start_date;
        cout << "Enter end date (YYYY-MM-DD): ";
        string end_date;
        cin >> end_date;
        system.RequestToOccupyHouse(member_id, house_id, start_date, end_date);
     } else if (choice == 5){
        system.ViewOccupyRequests(member_id);
        } else if (choice == 6){
        cout << "Enter house ID: ";
        int house_id;
        cin >> house_id;
        cout << "Enter score (1-10): ";
        int score;
        cin >> score;
        cout << "Enter comment: ";
        string comment;
        cin >> comment;
        system.LeaveReview(member_id, house_id, score, comment);
     } else {
        cout << "Error: Invalid menu choice." << "\n";
     }
   }
 } else if (user_type == 3){
    // Admin user
    while (true){
      cout << "This is your menu:" << "\n";
      cout << "0. Exit" << "\n";
      cout << "1. View All Members" << "\n";
      cout << "2. View All Houses" << "\n";
      cout << "Enter your choice: ";
      int choice;
      cin >> choice;

      if (choice == 0){
        break;
     } else if (choice == 1){
        system.ViewAllMembers();
     } else if (choice == 2){
        system.ViewAllHouses();
     } else {
        cout << "Error: Invalid menu choice." << "\n";
     }
   }
 } else {
    cout << "Error: Invalid user type." << "\n";
 }
}
