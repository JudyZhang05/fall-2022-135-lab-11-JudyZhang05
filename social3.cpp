#include <iostream>
#include "network.hpp"
#include "profile.hpp"

//TASK C

Network::Network(){
    numUsers = 0;
    for (int y = 0; y < MAX_USERS; y++){
        for (int x = 0; x < MAX_USERS; x++){
            following[y][x] = false;
        }
    }
}

bool Network::follow(std::string usrn1, std::string usrn2){
    if (findID(usrn1) != -1 && findID(usrn2) != -1){
        following[findID(usrn1)][findID(usrn2)] = true;
        return true;
    }
    return false;
}

void Network::printDot(){
    std::cout << "digraph {\n";
    for (int i = 0; i < numUsers; i++){
        std::cout << "  \"@" << profiles[i].getUsername() << "\"\n";
    }
    std::cout << '\n';
    for (int y = 0; y < numUsers; y++){
        for (int x = 0; x < numUsers; x++){
            if (following[y][x] == true){
                std::cout << "  \"@" << profiles[y].getUsername() << "\" -> \"@" << profiles[x].getUsername() << "\"\n";
            }
        }
    }
    std::cout << "}\n";
}