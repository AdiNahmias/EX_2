#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "iostream"
#include "stdio.h"
#include "card.hpp"
using namespace std;
#include <string>
#include <stack>
#include <vector>

class Player {

private:
    string my_player;
    vector<Card> player_Stack;
    vector<Card> cardesTaken_stack;

public:
    
    Player(){}
    Player(string player_name);
    int stacksize();
    int cardesTaken(); 
    string getname();
    void print_card_stack_player();
    void get_card_to_stack(Card c);
    Card get_card_from_stack();
      
   
};

#endif

