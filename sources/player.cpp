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

Card Player::get_card_from_stack(){
    Card c = this->player_Stack.back();
    this->player_Stack.pop_back();
    return c;
}

void Player::set_card_to_stack(Card c){
    this->player_Stack.push_back(c);
}

void Player::set_card_to_cardesTaken(Card c){

    this->cardesTaken_stack.push_back(c);
}


void Player::print_card_stack_player() {
    for (size_t i = 0; i < player_Stack.size(); i++) {
        
        std::cout << this->player_Stack.at(i).getnum()<< " of " << this->player_Stack.at(i).getshape() << std::endl;
    }
}

void Player::print_cardesTaken() {
    for (size_t i = 0; i < cardesTaken_stack.size(); i++) {
        
        std::cout << this->cardesTaken_stack.at(i).getnum()<< " of " << this->cardesTaken_stack.at(i).getshape() << std::endl;
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

