#ifndef CARD_HPP
#define CARD_HPP
#include "iostream"
#include "stdio.h"
using namespace std;
namespace ariel{

};

class Card{

    private:
        string num;
        string shape;
        


    public:
        Card(){}
        Card(string num, string shape);
        string getshape();
        string getnum();
        
       
};







#endif
