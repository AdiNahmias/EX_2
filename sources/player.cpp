#include <string>
#include "player.hpp"
#include "iostream"
#include "stdio.h"
using namespace std;


//constructor
Player::Player(string player_name){
    this->my_player = player_name; 
}  

string Player::getname(){
    return my_player;
} 


//prints the amount of cards left.    
int  Player::stacksize(){
    return 1;
}

// prints the amount of cards this player has won
int Player::cardesTaken(){
    return 1;
}

