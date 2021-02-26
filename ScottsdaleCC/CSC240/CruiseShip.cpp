#pragma once
#include "CruiseShip.h"

CruiseShip::CruiseShip(string sT, string n, string y, int c) : Ship( sT, n, y)
{
    this->capacity = c;
}

void CruiseShip::toString()
{
    cout << this->getName() << " " << this->getCapacity() << endl;
}
