//#ifdef SHIP_H
//#define SHIP_H

#pragma once // does not function properly with repl.it

#include <iostream>
using namespace std;

class Ship
{
    private:
        string name;
        string year;
        string shipType;
    public:
        Ship(string, string, string);
        string getName(){ return this->name;};
        string getYear(){ return this->year;};
        void setName(string n){ this->name = n;};
        void setYear(string y){ this->year = y;};
        virtual void toString();
        //virtual void setCapacity(int n){};

};

//#endif