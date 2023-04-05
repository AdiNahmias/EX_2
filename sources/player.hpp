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
    
    
    Player(string player_name);
    int stacksize();
    int cardesTaken(); 
    string getname();
    void print_card_stack_player();
    void set_card_to_stack(Card card);
    void set_card_to_cardesTaken(Card card);
    Card get_card_from_stack();
    void print_cardesTaken(); 
      
   
};

#endif

