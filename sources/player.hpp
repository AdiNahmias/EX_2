#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "iostream"
#include "stdio.h"
using namespace std;

#include <string>

class Player {

private:
    std::string my_player;

public:
    Player(){}
    Player(std::string player_name);
    int stacksize();
    int cardesTaken(); 
    string getname();
      
   
};

#endif

