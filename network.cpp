#include <iostream>
#include <cctype>
#include "network.hpp"
#include "profile.hpp"

//TASK B

Network::Network(){
    numUsers = 0;
}

int Network::findID(std::string usrn){
    for (int i = 0; i < MAX_USERS; i++){
        if (profiles[i].getUsername() == usrn){
            return i;
        }
    }
    return -1;
}

bool Network::addUser(std::string usrn, std::string dspn){
    if (numUsers < MAX_USERS){
        for (int check = 0; check < usrn.length(); check++){
            if (!isalpha(usrn[check])){
                return false;
            }
        }
        for (int i = 0; i < numUsers; i++){
            if (profiles[i].getUsername() == usrn){
                return false;
            }
        }
        int add = (numUsers == 0) ? 0 : 1;
        profiles[numUsers+add] = Profile(usrn, dspn);
        return true;
    }
    return false;
}

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