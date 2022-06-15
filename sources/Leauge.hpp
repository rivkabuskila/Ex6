//
// Created by rivka on 30/05/2022.
//

#ifndef B_BALL_LEAUGE_H
#define B_BALL_LEAUGE_H
#include "Team.hpp"
#include <vector>
#include <stdlib.h>     /*  rand */

class Leauge {
public:
    std::vector<Team> groups;
    std::string names[20]={"team1","team2","team3","team4","team5","team6","team7","team8", "team9", "team10","team11", "team12",
                           "team13", "team14", "team15", "team16","team17","team18",
                           "team19", "team20"};
public:
    Leauge();
    Leauge(Team* groups);
    int found_name();

};


#endif //B_BALL_LEAUGE_H
