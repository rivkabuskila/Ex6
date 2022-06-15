//
// Created by rivka on 30/05/2022.
//

#ifndef B_BALL_TEAM_H
#define B_BALL_TEAM_H
#include <iostream>

class Team {
public:
    std::string name;
    double talent_level;
    int win;
    int lost;
    int points_scored_by_a_team;
    int points_the_team_absorbed;
    int Sequence_of_win;
    int Sequence_of_lost;
public:
    Team(std::string& name,double talent_level);
    double get_talent_level();
    void set_name(std::string name);
    void set_talent_level(double talent_level);

};


#endif //B_BALL_TEAM_H
