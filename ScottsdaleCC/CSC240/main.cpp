#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <algorithm>

#include "Ship.h"
#include "Ship.cpp"
#include "CargoShip.h"
#include "CargoShip.cpp"
#include "CruiseShip.cpp"
#include "CruiseShip.cpp"
using namespace std;

const int MAX = 20;

int main(int argc, char *argv[])
{
    string fileName;                                            // Stores the name of file that holds ship list.    
    

    /*
    Ship testShip;
    testShip.setName("Townsend");
    testShip.setYear("1666");
    testShip.toString();

    CargoShip cargoUno;
    cargoUno.setCapacity(666);
    cargoUno.setName("Kerberos");
    cargoUno.setYear("125"); 
    cargoUno.toString();

    CruiseShip crooze;
    crooze.setCapacity(42);
    crooze.setName("Vat Are U Sinking About");
    crooze.setYear("1976");
    crooze.toString();

    */

    //------------------ TESTING -------------------------//
    Ship *shipsPtr[MAX];                                        // Make array of Ship pointers. "MAX" defined globally, above.
    string tokens[4];                                            // Store one line of tokens.
    int pos = 0;                                                // Used as index to traverse through array of Ships.
    string line;                                            // Holds single line from file.

    string shipType,
        shipName, 
        shipWeight,
        shipCapacity;
    
    string fields[4];

    fstream input;
    input.open(argv[1]);

    if(!input.good())                                           // Check if everything is okay.
    { 
        cout << "\n\aERROR OPENING FILE\n";                     // Otherwise, ring bell, tell USER there's a problem opening desired file.      
        return -1;                                              // EXIT MAIN
    }
    //else{ cout << "\nFile opened successfully!\n\n";}

    while(input.good())
    {   
        getline(input, line);                                   // Store single line from file into line var.
        std::stringstream ss(line);                             // Make stringstream object of line                
        
        for(int i = 0; i < line.length(); i++)
        {
            line.erase(std::remove(line.begin(), line.end(), i), line.end());
        }
        cout << line << endl;
        
        int tokPos = 0;                                         // Used to traverse through tokens array.
        while(getline(ss, tokens[tokPos], '"'))                 // Break up line at each ',' and store into tokens array.
        {
            tokPos++;                                           // Increment index.
        }

        if(tokens[0].find("Cargo") != string::npos)             // check if it's CargoShip. 
        {
            shipsPtr[pos] = new CargoShip(tokens[0], tokens[1], tokens[2], stoi(tokens[3]));                    // Instantiate CargoShip object.           
        }
        else if(tokens[0].find("Cruise") != string::npos)
        {
            shipsPtr[pos] = new CruiseShip(tokens[0], tokens[1], tokens[2], stoi(tokens[3]));                   // Instantiate CruiseShip Object.                                    
        }
        else
        {
            shipsPtr[pos] = new Ship(tokens[0], tokens[1], tokens[2]);                         // Instantiate Ship object.
        }
        
        pos++;
    }

    
    input.close();                                              // Close the file.
    return 0;                                                   // END OF MAIN
}