#ifndef GAME_HPP
#define GAME_HPP
#include "player.hpp"
#include "card.hpp"
#include "iostream"
#include "stdio.h"
using namespace std;
#include <vector>
#include <array>
#include <string>

const int CARDS_NUM = 13;



class Game{

    private:
        Player *p1;
        Player *p2;
        vector<Card> vec;
        vector<string> turns;
        array<string, CARDS_NUM> num_cards;

    public:
        //Game(){}
        Game(Player &player_1,Player &player_2);
        void reset_num_cards();
        void division_card();
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