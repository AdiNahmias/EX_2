#include "game.hpp"
#include "player.hpp"
#include "card.hpp"
#include "iostream"
#include "stdio.h"


Card::Card(int n, string num, string shape){
    this->n = n;
    this->num = num;
    this->shape = shape;
 }

string Card::getshape(){
    return this->shape;
} 
string Card::getnum_string(){
    return this->num;
}

int Card::getnum(){
    return this->n;
} 


