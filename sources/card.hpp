#ifndef CARD_HPP
#define CARD_HPP
#include "iostream"
#include "stdio.h"
using namespace std;
namespace ariel{

};

class Card{

    private:
        int n;
        string num;
        string shape;
        


    public:
        Card(){}
        Card(int n, string num, string shape);
        string getnum_string();
        string getshape();
        int getnum();
        
       
};







#endif
