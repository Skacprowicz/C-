//#ifdef CRUISESHIP_H
//#define CRUISESHIP_H


#pragma once // does not function properly with repl.it

#include <iostream>
using namespace std;

class CruiseShip : public Ship
{
    private:
        int capacity;
    public:
        CruiseShip(string, string, string, int);
        void setCapacity(int n){ this->capacity = n;};
        int getCapacity(){ return this->capacity;};
        void toString() override;
};

//#endif