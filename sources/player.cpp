#include <string>
#include "player.hpp"
#include "iostream"
#include "stdio.h"
using namespace std;



Player::Player(std::string player_name){
    this->my_player = player_name; 
}  

string Player::getname(){
    return my_player;
} 


//prints the amount of cards left. should be 21 but can be less if a draw was played    
int  Player::stacksize(){
    return 1;
}

// prints the amount of cards this player has won
int Player::cardesTaken(){
    return 1;
}

