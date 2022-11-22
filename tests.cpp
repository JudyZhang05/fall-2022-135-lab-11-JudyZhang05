#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"

Profile example("Exam","Please");
Profile example2("Nothing","Here");
Profile example3("Joe","Mama");
Profile example4("Need","Money");

TEST_CASE("TASK A"){
    CHECK(example.getUsername() == "Exam");
    CHECK(example2.getUsername() == "Nothing");
    CHECK(example3.getUsername() == "Joe");    
    CHECK(example4.getUsername() == "Need");    

    CHECK(example.getFullName() == "Please");
    CHECK(example2.getFullName() == "Here");
    CHECK(example3.getFullName() == "Mama");
    CHECK(example4.getFullName() == "Money");

}

Network nwtest;

TEST_CASE("TASK B"){
    CHECK(nwtest.addUser("Joe","Joe Mama") == true);
    CHECK(nwtest.addUser("Need","Need Money") == true);
    CHECK(nwtest.addUser("Gambling","Gambling Addict") == true);
    CHECK(nwtest.addUser("Joe","MyLittlePony") == false);
    CHECK(nwtest.addUser("Gambling","Unicorn123") == false);
    CHECK(nwtest.addUser("Need","CoolestPersonInTheWorld34") == false);
}

TEST_CASE("TASK C"){
    CHECK(nwtest.follow("Joe","Need") == true);
    CHECK(nwtest.follow("Joe","Gambling") == true);
    CHECK(nwtest.follow("Need","Joe") == true);

    CHECK(nwtest.follow("Unicorn123","Need") == false);
    CHECK(nwtest.follow("TheCoolestPersionInTheWorld34","MyLittlePony") == false);
    CHECK(nwtest.follow("Joe","Joe Mama") == false);
}