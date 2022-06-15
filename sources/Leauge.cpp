//
// Created by rivka on 30/05/2022.
//

#include "Leauge.hpp"
Leauge::Leauge() {
    this->groups.reserve(20);
    for (unsigned long i = 0; i < 20; ++i) {
        double level = rand() % 1;
        this->groups.push_back(Team(names[i], level));
    }
}
int Leauge::found_name() {
    for (unsigned long i = 0; i < 20; ++i) {
        bool f = false;
        for (unsigned long j = 0; j < 20 && !f; ++j) {
          if (names[i]== this->groups.at(i).name){
             f= true;
          }
        }
        if (!f){
            return i;
        }
    }
    return -1;
}
Leauge::Leauge(Team* groups){
        unsigned long i=0;
        bool finish=false;
        std::string name;
        double level;
        while (!finish){
            std::cout << "enter name and level if you finish enter finish";
            std::cin >> name;
            if (name == "finish"){
                finish= true;
            }
            else{
                std::cin >> level;
                this->groups[i++] = Team(name, level);
            }
        }
        while (i < 20){
            double level = rand() % 1;
            int j = found_name();
            this->groups[i++] = Team(names[j], level);
        }
}