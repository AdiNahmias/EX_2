#include "game.hpp"
#include "player.hpp"
#include "card.hpp"
#include "iostream"
#include "stdio.h"


Card::Card(string num, string shape){
    this->num = num;
    this->shape = shape;
 }

string Card::getshape(){
    return this->shape;
} 

string Card::getnum(){
    return this->num;
} 


