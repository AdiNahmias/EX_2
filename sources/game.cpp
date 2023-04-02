#include "game.hpp"
#include "player.hpp"
#include "iostream"
#include "stdio.h"
#include <vector>
#include <algorithm>
#include <random>



void Game::print_card_stack(vector <Card> &vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec.at(i).getnum()<< "," << vec.at(i).getshape() << std::endl;
    }
}

void Game::reset_card_stack(vector <Card> &vec){
    for(int i=1; i<=13; i++){
        vec.push_back(Card(i,"heart"));
        
    }
    for(int i = 1; i<=13; i++){
        vec.push_back(Card(i,"diamond"));
        
    }
    for(int i = 1; i<=13; i++){
        vec.push_back(Card(i,"spades"));
    }
    for(int i = 1; i<=13; i++){
        vec.push_back(Card(i,"clubs"));
    }

 }


void Game::shuffleCardStack(vector<Card>& vec) {
    // Create a random number generator
    random_device rd;
    mt19937 g(rd());

    // Shuffle the vector using the random number generator
    shuffle(vec.begin(), vec.end(), g);
}

void Game::division_card(Player p1, Player p2, vector<Card>& vec){
    for(size_t i= 0; i < vec.size(); i++){
        if(i % 2 == 0){
            this->p1->get_card_to_stack(vec[i]);
        }else{
            this->p2->get_card_to_stack(vec[i]);
        }
    }
}

//constructor
Game::Game(Player &p1, Player &p2){
    this->p1 = &p1;
    this->p2 = &p2;
    //reset th stack card
    reset_card_stack(this->vec);
    std::cout << "--------before shuffle---------" << std::endl;
    print_card_stack(this->vec);
    //shuffle cards in the Stack
    shuffleCardStack(this->vec);
    std::cout << "--------after shuffle---------" << std::endl;
    print_card_stack(this->vec);

    if (vec.size() < 52) {
    std::cout << "Error: Not enough cards in the deck\n";
    return;
    }
    //division cards
    division_card(p1,p2,vec);
    std::cout << "--------player 1 stack---------" << std::endl;
    p1.print_card_stack_player();
    std::cout << "--------player 2 stack---------" << std::endl;
    p2.print_card_stack_player();

 }


//print the last turn stats
void Game::printLastTurn() {
    

 }

//playes the game untill the end
void Game::playAll(){

}
// prints the name of the winning player
void Game::printWiner(){

}

// // prints all the turns played one line per turn (same format as game.printLastTurn())
void Game::printLog(){

}
//for each player prints basic statistics: 
// win rate, cards won, <other stats you want to print>
// Also print the draw rate and amount of draws that happand.
void Game::printStats(){

}
//play one turn
void Game::playTurn(){
    card card1 = this->p1->player_Stack.pop_back();
    card card2 = this->p2->player_Stack.pop_back();
    if(card1.num > card2.num){
        // p1 cardes taken + 2
        this->p1->cardesTaken.push_back(card1);
        this->p1->cardesTaken.push_back(card2);
        
    }

}