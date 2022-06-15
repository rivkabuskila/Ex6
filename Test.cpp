//
// Created by rivka on 12/06/2022.

#include "sources/Leauge.hpp"
#include "sources/Schedule.hpp"
#include "sources/Team.hpp"
#include "doctest.h"
#include <vector>
TEST_CASE("game") {
std::string names[20]={"team1","team2","team3","team4","team5","team6","team7","team8", "team9", "team10","team11", "team12",
                       "team13", "team14", "team15", "team16","team17","team18",
                       "team19", "team20"};
   Leauge l;
   Schedule s(l);
   std::vector<Team>v = l.groups;
    for (unsigned long i = 0; i < 20 ; ++i) {
        CHECK(v.at(i).name==names[i]);
    }
    s.game();
    s.finish();
    std::vector<Team>v1 = s.leading_groups(3);
    int win1= v1.at(0).win;
    int lost1= v1.at(0).lost;
    int p1;
    if (lost1!=0){
        p1= win1/lost1;
    }
    else{
        p1=1;
    }
    int win2= v1.at(1).win;
    int lost2= v1.at(1).lost;
    int p2;
    if (lost2!=0){
        p2= win2/lost2;
    }
    else{
        p2=1;
    }
    int win3= v1.at(2).win;
    int lost3= v1.at(2).lost;
    int p3;
    if (lost3!=0){
        p3= win3/lost3;
    }
    else{
        p3=1;
    }
    bool a1 = false;
    if (p1 >= p2) a1= true;
    CHECK(a1== true);
    bool a2 = false;
    if (p2 >= p3) a2= true;
    CHECK(a2== true);
    bool a3 = false;
    if (p1 >= p3) a3= true;
    CHECK(a3== true);
}

