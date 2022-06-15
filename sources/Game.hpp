//
// Created by rivka on 30/05/2022.
//

#ifndef B_BALL_GAME_H
#define B_BALL_GAME_H
#include "Team.hpp"

class Game {
public:
    Team* home_group;
    Team* foreign_group;
    int point_home_group;
    int point_foreign_group;
public:
    Game(Team& home,Team& foreign);
    void add(std::string name, int point);
    void win();
};


#endif //B_BALL_GAME_H
