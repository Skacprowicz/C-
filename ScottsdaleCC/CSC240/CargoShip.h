//#ifdef CARGOSHIP_H
//#define CARGOSHIP_H

#pragma once // does not function properly with repl.it compiler.
#include <iostream>
using namespace std;

class CargoShip : public Ship
{
    private:
        int capacity;
    
    public:
        CargoShip(string, string, string, int);
        void setCapacity(int n){ this->capacity = n;};
        int getCapacity(){ return this->capacity;};
        void toString() override;
};

//#endif