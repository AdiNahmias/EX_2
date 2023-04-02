#include <string>
#include "player.hpp"
#include "card.hpp"
#include "iostream"
#include "stdio.h"
using namespace std;
#include <vector>


//constructor
Player::Player(string player_name){
    this->my_player = player_name;
    
} 

void Player::get_card_to_stack(Card c){

    this->player_Stack.push_back(c);
}

void Player::print_card_stack_player() {
    for (size_t i = 0; i < player_Stack.size(); i++) {
        
        std::cout << this->player_Stack.at(i).getnum()<< "," << this->player_Stack.at(i).getshape() << std::endl;
    }
}


string Player::getname(){
    return my_player;
} 


//prints the amount of cards left.    
int Player::stacksize(){
    return this->player_Stack.size();
}

// prints the amount of cards this player has won
int Player::cardesTaken(){
    return this->cardesTaken_stack.size();
    
}

