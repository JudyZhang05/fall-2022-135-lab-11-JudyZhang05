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

    
    // std::cout << "\n\nTASK B\n\n"; //______________________________________

    // Network nw;
    // std::cout << nw.addUser("mario", "Mario") << std::endl;     // true (1)
    // std::cout << nw.addUser("luigi", "Luigi") << std::endl;     // true (1)

    // std::cout << nw.addUser("mario", "Mario2") << std::endl;    // false (0)
    // std::cout << nw.addUser("mario 2", "Mario2") << std::endl;  // false (0)
    // std::cout << nw.addUser("mario-2", "Mario2") << std::endl;  // false (0)

    // for(int i = 2; i < 20; i++)
    //     std::cout << nw.addUser("mario" + std::to_string(i), 
    //                 "Mario" + std::to_string(i)) << std::endl;   // true (1)

    // std::cout << nw.addUser("yoshi", "Yoshi") << std::endl;     // false (0)


    // std::cout << "\n\nTASK C\n\n"; //______________________________________

    // Network new_Network;
    // // add three users
    // new_Network.addUser("mario", "Mario");
    // new_Network.addUser("luigi", "Luigi");
    // new_Network.addUser("yoshi", "Yoshi");

    // // make them follow each other
    // new_Network.follow("mario", "luigi");
    // new_Network.follow("mario", "yoshi");
    // new_Network.follow("luigi", "mario");
    // new_Network.follow("luigi", "yoshi");
    // new_Network.follow("yoshi", "mario");
    // new_Network.follow("yoshi", "luigi");

    // // add a user who does not follow others
    // new_Network.addUser("wario", "Wario");
    
    // // add clone users who follow @mario
    // for(int i = 2; i < 6; i++) {
    //     std::string usrn = "mario" + std::to_string(i);
    //     std::string dspn = "Mario " + std::to_string(i);
    //     new_Network.addUser(usrn, dspn);
    //     new_Network.follow(usrn, "mario");
    // }
    // // additionally, make @mario2 follow @luigi
    // new_Network.follow("mario2", "luigi");

    // new_Network.printDot();
    return 0;
}