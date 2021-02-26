//#pragma once
#include "Ship.h"
// Implement the logic for Ship

Ship::Ship(string sT, string n, string y)
{
    this->name = n;
    this->year = y;
    this->shipType = sT;
}

void Ship::toString()
{
    cout << this->getName() << " " << this->getYear() << endl;
}