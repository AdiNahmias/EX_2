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
            this->p1->set_card_to_stack(vec[i]);
        }else{
            this->p2->set_card_to_stack(vec[i]);
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
//need to check if the players have cards in therh stack
if((this->p1->stacksize() > 0) && (this->p2->stacksize() >0) ){

    Card arr1[26];
    Card arr2[26];
    int i = 0;

    Card card1 = this->p1->get_card_from_stack();
    Card card2 = this->p2->get_card_from_stack();
    if(card1.getnum() > card2.getnum()){
        this->p1->set_card_to_cardesTaken(card1);
        this->p1->set_card_to_cardesTaken(card2);
    }
    if(card1.getnum() < card2.getnum()){
        this->p2->set_card_to_cardesTaken(card1);
        this->p2->set_card_to_cardesTaken(card2);
    }
    //if the players put the same number card
    else{
        while((card1.getnum() == card2.getnum()) && (this->p1->stacksize()!= 0) && (this->p2->stacksize()!= 0)){
        //put the same card in the arr
        arr1[i] = card1;
        arr2[i] = card2;
        i++;
        //put the close cards in the arr
        arr1[i] = this->p1->get_card_from_stack();
        arr2[i] = this->p2->get_card_from_stack();
        //again open cards
        //if the 2 cards is the same we going back to the beginning of while
        card1 = this->p1->get_card_from_stack();
        card2 = this->p2->get_card_from_stack();
        i++;
        }//end while
        arr1[i] = card1;
        arr2[i] = card2;
        //the 2 cards are not the same
        if(card1.getnum() > card2.getnum()){
            //player1 takes all the cards in the 2 arr
            for(size_t k = 0; k < i; k++){
                this->p1->set_card_to_cardesTaken(arr1[k]);
            }
            for(size_t k = 0; k < i; k++){
                this->p1->set_card_to_cardesTaken(arr2[k]);
            }
        }if(card1.getnum() < card2.getnum()){
            //player2 takes all the cards in the 2 arr
            for(size_t k = 0; k < i; k++){
                this->p2->set_card_to_cardesTaken(arr1[k]);
            }
            for(size_t k = 0; k < i; k++){
                this->p2->set_card_to_cardesTaken(arr2[k]);
            }
        }else{
            //we brake the while because the players finish there stack
            std::cout << "--------No one won in this turn---------" << std::endl;
        }
        }
    }else{

    return;
    }
}
   

