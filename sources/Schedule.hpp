//
// Created by rivka on 06/06/2022.
//

#ifndef B_BALL_SCHEDULE_H
#define B_BALL_SCHEDULE_H

#include "Leauge.hpp"
#include "vector"
#include "Game.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
class Schedule {
   Leauge leauge;
   std::vector<std::vector<Game>> tournament;
   std::map<int, std::tuple<int,double,int>> Scoreboard;

public:
    Schedule(Leauge &leauge);
    void game();
    void finish();
    std::vector<Team> leading_groups(int num);
    int points_top_group();
    int Sequence_of_lost();
    int Sequence_of_win();
    };


#endif //B_BALL_SCHEDULE_H
