#ifndef GAME_HPP
#define GAME_HPP
#include "player.hpp"
#include "card.hpp"
#include "iostream"
#include "stdio.h"
using namespace std;
#include <vector>



class Game{

    private:
        Player *p1;
        Player *p2;
        vector<Card> vec;
        vector<string> turns;
        string num_cards[13];

    public:
        //Game(){}
        Game(Player &p1,Player &p2);
        void reset_num_cards();
        void division_card(Player p1, Player p2, vector<Card>& vec);
        void print_card_stack(vector <Card> &vec);
        void reset_card_stack(vector <Card> &vec);
        void shuffleCardStack(vector<Card>& vec);
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
        void playTurn();


};

#endif