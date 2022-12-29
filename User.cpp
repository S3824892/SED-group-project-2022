#include <iostream>
#include <fstream>
#include <vector>
using std::string;
using std::cout;
using std::cin;

class System{
protected:
    std::vector <Member> members{};
public:
    System{};
    bool addMember(){
            int id;
            cout << "Input student ID: "; cin >> id;
            int position = findMember(id); 
            if ( position >= 0) { //Student is already in the system
                cout << "Member has registered \n";
                return false;
            } else { //Add new Member
                string username;
                cout << "Input username: "; 
                do {
                    getline(cin, username);
                } while (username == "");
                members.push_back( Member(username, id) );
                cout << "Input password: "; 
                do {
                    getline(cin, password);
                } while (password == "");
                members.push_back( Member(password, id) );
                cout << "Added to the system successfully \n";
                return true;
            }
        }
        
        int findMember(int id){
            for (int i = 0; i < members.size(); i++){
                if (members[i].id == id){
                    return i; //return position if matched
                }
            }
            return -1; //return -1 if does not matched
        }
};