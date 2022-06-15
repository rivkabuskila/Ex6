//
// Created by rivka on 30/05/2022.
//

#include "Game.hpp"
Game::Game(Team& home,Team& foreign){
    this->home_group=&home;
    this->foreign_group=&foreign;
    this->point_home_group=0;
    this->point_foreign_group=0;

}
void Game::add(std::string name, int point){
    if ("home_group"==name){
        this->point_home_group+=point;
        this->home_group->points_scored_by_a_team+=point;
        std::cout << this->foreign_group->name;
        this->foreign_group->points_the_team_absorbed+=point;
    }
    else{
        this->point_foreign_group+=point;
        this->foreign_group->points_scored_by_a_team+=point;
        this->home_group->points_the_team_absorbed+=point;
    }
}
void Game::win(){
    if (this->point_home_group > this->point_foreign_group){
        this->home_group->win++;
        this->home_group->Sequence_of_lost=0;
        this->foreign_group->lost++;
        this->foreign_group->Sequence_of_win=0;
    }
    else{
        this->foreign_group->win++;
        this->foreign_group->Sequence_of_lost=0;
        this->home_group->lost++;
        this->home_group->Sequence_of_win=0;
    }
}

