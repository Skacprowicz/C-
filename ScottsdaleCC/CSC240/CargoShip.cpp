//#pragma once
#include "CargoShip.h"


CargoShip::CargoShip(string sT, string n, string y, int c): Ship(sT, n, y)
{
    this->capacity = c;
}

void CargoShip::toString()
{
    cout << this->getName() << " " << this->getCapacity() << endl;
}