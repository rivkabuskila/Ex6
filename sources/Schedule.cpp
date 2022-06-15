
//
// Created by rivka on 06/06/2022.
//
#include "Schedule.hpp"

Schedule::Schedule(Leauge &leauge) {
    this->leauge = leauge;
    unsigned long j = 0;
    unsigned long k = 0;
    unsigned long m = 0;
    tournament.resize(40);
    while (j!=20){
          m=0;
        for (unsigned long i = 0; i < 10 ; ++i) {
            Team a = this->leauge.groups.at(i);
            Team b =this->leauge.groups.at(j);
            Game g(a,b);
            tournament[k].push_back(g);
            m=m+j+1;
        }
        k++;
        j++;
    }

}
void Schedule::game() {
    //took from stackoverflow
    //base
    std::default_random_engine generator1;
    std::normal_distribution<double> distribution1(50.0, 100.0);
    int sample1;
    //home
    std::default_random_engine generator2;
    std::normal_distribution<double> distribution2(55.0, 100.0);
    int sample2;
//    std::cout << this->tournament.size();
    for (unsigned long i = 0; i < this->tournament.size(); ++i) {
//        std::cout << this->tournament.at(i).size();
        for (unsigned long j = 0; j < this->tournament.at(i).size(); ++j) {
            sample1 = (int) distribution1(generator1);
            sample2 = (int) distribution2(generator2);
            if (sample1 < 50) sample1 = 50;
            if (sample1 > 100) sample1 = 100;
            if (sample2 < 50) sample1 = 55;
            if (sample2 > 100) sample1 = 100;
            this->tournament.at(i).at(j).add("home_group", sample2);
            this->tournament.at(i).at(j).add("foreign_group", sample1);
            this->tournament.at(i).at(j).win();
        }
    }
}
void Schedule::finish(){
    unsigned long index=1;
    double p;
    std::tuple <int,double,int> t;
    unsigned long index2=index;
    for (unsigned long i = 0; i < 20 ; ++i) {
        int win = this->leauge.groups[i].win;
        int lost = this->leauge.groups[i].lost;
        if (lost != 0){
            double p = win/lost;
        }
        else {
            p=1;
        }
        int points = this->leauge.groups[i].points_scored_by_a_team-this->leauge.groups[i].points_the_team_absorbed;
        t = std::make_tuple(i,p, points);
        if (index == 1 ){
            Scoreboard[index]=t;
            index++;
        }
        else{
            for (unsigned long j = 1; j < index; ++j) {
                if (get<1>(t) > get<1>(Scoreboard[j])){
                    index2=j;
                    break;
                }
                else  if (get<1>(t) == get<1>(Scoreboard[j])){
                    if (get<2>(t) > get<2>(Scoreboard[j]))
                    index2=j;
                    break;
                }
            }
            if (index2==index){
                Scoreboard[index]=t;
                index++;
            }
            else{
                for (unsigned long j = index; j <= index2 ; --j) {
                    Scoreboard[j+1]=Scoreboard[j];
                }
                Scoreboard[index2]=t;
                index++;
            }
        }
    }
}
std::vector<Team> Schedule::leading_groups(int num){
    std::vector<Team>v;
    for (unsigned long i = 1; i <= num; ++i) {
        unsigned long index = (unsigned long)get<0>(this->Scoreboard[i]);
        v.push_back(this->leauge.groups.at(index));
    }
    return v;
}

int Schedule::points_top_group(){
    int count=0;
    for (unsigned long i = 1; i < 20; ++i) {
        int p = get<2>(this->Scoreboard[i]);
        if (p > 0){
            count++;
        }
    }
    return count;
}

int Schedule::Sequence_of_lost(){
    int max=0;
    for (unsigned long i = 0; i <20 ; ++i) {
        int lost = this->leauge.groups.at(i).Sequence_of_lost;
        if (max < lost){
            max=lost;
        }
    }
    return max;
}
int Schedule::Sequence_of_win(){
    int max=0;
    for (unsigned long i = 0; i <20 ; ++i) {
        int win = this->leauge.groups.at(i).Sequence_of_win;
        if (max < win){
            max=win;
        }
    }
    return max;
}


