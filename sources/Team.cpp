//
// Created by rivka on 30/05/2022.
//

#include "Team.hpp"

Team::Team(std::string& name, double talent_level){
    this->name=name;
    this->talent_level=talent_level;
    this->points_the_team_absorbed=0;
    this->points_scored_by_a_team=0;
    this->win=0;
    this->lost=0;
    this->Sequence_of_lost=0;
    this->Sequence_of_win=0;
}


double Team::get_talent_level(){
    return this->talent_level;
}

void Team::set_name(std::string name){
    this->name=name;
}
void Team::set_talent_level(double talent_level){
    this->talent_level=talent_level;
}