#include <iostream>
#include "profile.hpp"
#include "network.hpp"

int main() {
    std::cout << "\n\nTASK A\n\n"; //______________________________________

    Profile p1("marco", "Marco");    
    std::cout << p1.getUsername() << std::endl; // marco
    std::cout << p1.getFullName() << std::endl; // Marco (@marco)

    p1.setDisplayName("Marco Rossi"); 
    std::cout << p1.getUsername() << std::endl; // marco
    std::cout << p1.getFullName() << std::endl; // Marco Rossi (@marco)
    
    Profile p2("tarma1", "Tarma Roving");    
    std::cout << p2.getUsername() << std::endl; // tarma1
    std::cout << p2.getFullName() << std::endl; // Tarma Roving (@tarma1)

    
    std::cout << "\n\nTASK B\n\n"; //______________________________________

    Network nw;
    std::cout << nw.addUser("mario", "Mario") << std::endl;     // true (1)
    std::cout << nw.addUser("luigi", "Luigi") << std::endl;     // true (1)

    std::cout << nw.addUser("mario", "Mario2") << std::endl;    // false (0)
    std::cout << nw.addUser("mario 2", "Mario2") << std::endl;  // false (0)
    std::cout << nw.addUser("mario-2", "Mario2") << std::endl;  // false (0)

    for(int i = 2; i < 20; i++)
        std::cout << nw.addUser("mario" + std::to_string(i), 
                    "Mario" + std::to_string(i)) << std::endl;   // true (1)

    std::cout << nw.addUser("yoshi", "Yoshi") << std::endl;     // false (0)


    std::cout << "\n\nTASK C\n\n"; //______________________________________

    Network new_Network;
    // add three users
    new_Network.addUser("mario", "Mario");
    new_Network.addUser("luigi", "Luigi");
    new_Network.addUser("yoshi", "Yoshi");

    // make them follow each other
    new_Network.follow("mario", "luigi");
    new_Network.follow("mario", "yoshi");
    new_Network.follow("luigi", "mario");
    new_Network.follow("luigi", "yoshi");
    new_Network.follow("yoshi", "mario");
    new_Network.follow("yoshi", "luigi");

    // add a user who does not follow others
    new_Network.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        std::string usrn = "mario" + std::to_string(i);
        std::string dspn = "Mario " + std::to_string(i);
        new_Network.addUser(usrn, dspn);
        new_Network.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    new_Network.follow("mario2", "luigi");

    new_Network.printDot();
    return 0;
}

// #include <iostream>
// #include <cctype>
// #include "network.hpp"
// #include "profile.hpp"


// class Profile {
// private:
//     std::string username;
//     std::string displayname;
// public:
//     // Profile constructor for a user (initializing 
//     // private variables username=usrn, displayname=dspn)
//     Profile(std::string usrn, std::string dspn);
//     // Default Profile constructor (username="", displayname="")
//     Profile();
//     // Return username
//     std::string getUsername();
//     // Return name in the format: "displayname (@username)"
//     std::string getFullName();
//     // Change display name
//     void setDisplayName(std::string dspn);
// };



// class Network {
// private:
//     static const int MAX_USERS = 20; // max number of user profiles
//     int numUsers;                    // number of registered users
//     Profile profiles[MAX_USERS];     // user profiles array:
//                                     // mapping integer ID -> Profile

//     // Returns user ID (index in the 'profiles' array) by their username
//     // (or -1 if username is not found)
//     int findID (std::string usrn);

//     bool following[MAX_USERS][MAX_USERS];  // friendship matrix:
//     // following[id1][id2] == true when id1 is following id2

// public:
//     // Constructor, makes an empty network (numUsers = 0)
//     Network();
//     // Attempts to sign up a new user with specified username and displayname
//     // return true if the operation was successful, otherwise return false
//     bool addUser(std::string usrn, std::string dspn);


//     // Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
//     // return true if success (if both usernames exist), otherwise return false
//     bool follow(std::string usrn1, std::string usrn2);

//     // Print Dot file (graphical representation of the network)
//     void printDot();
// };


// //TASK B

// Network::Network(){
//     numUsers = 0;
// }

// int Network::findID(std::string usrn){
//     for (int i = 0; i < MAX_USERS; i++){
//         if (profiles[i].getUsername() == usrn){
//             return i;
//         }
//     }
//     return -1;
// }

// bool Network::addUser(std::string usrn, std::string dspn){
//     if (numUsers < MAX_USERS){
//         for (int check = 0; check < usrn.length(); check++){
//             if (!isalpha(usrn[check])){
//                 return false;
//             }
//         }
//         for (int i = 0; i < numUsers; i++){
//             if (profiles[i].getUsername() == usrn){
//                 return false;
//             }
//         }
//         int add = (numUsers == 0) ? 0 : 1;
//         profiles[numUsers+add] = Profile(usrn, dspn);
//         return true;
//     }
//     return false;
// }

// std::string Profile::getUsername(){
//     return username;
// }

// std::string Profile::getFullName(){
//     return displayname;
// }

// void Profile::setDisplayName(std::string dspn){
//     displayname = dspn;
// }

// Profile::Profile(std::string usrn, std::string dspn){
//     username = usrn;
//     displayname = dspn;
// }

// //USAGE EX
// int main(){
        
//     Network nw;
//     std::cout << nw.addUser("mario", "Mario") << std::endl;     // true (1)
//     std::cout << nw.addUser("luigi", "Luigi") << std::endl;     // true (1)

//     std::cout << nw.addUser("mario", "Mario2") << std::endl;    // false (0)
//     std::cout << nw.addUser("mario 2", "Mario2") << std::endl;  // false (0)
//     std::cout << nw.addUser("mario-2", "Mario2") << std::endl;  // false (0)

//     for(int i = 2; i < 20; i++)
//         std::cout << nw.addUser("mario" + std::to_string(i), 
//                     "Mario" + std::to_string(i)) << std::endl;   // true (1)

//     std::cout << nw.addUser("yoshi", "Yoshi") << std::endl;     // false (0)
//     return 0;
// }
