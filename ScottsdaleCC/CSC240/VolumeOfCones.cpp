/**
 * @file VolumeOfCones.cpp
 * @author Sam Kacprowicz
 * @brief This program will compute the volume of a series of cones. The total number of cones will be determined by the USER.
 * @version 0.1
 * @date 2020-03-23
 * 
 */

#include <iostream>
#include <cmath>
using namespace std;

//--------- Function Prototypes ----------//
int getConeNumber();
bool programRunning();
float computeVolume(int cones);

//--------- START MAIN ----------------//
int main()
{    
    int cones;                  // Number of cones whose volume must be computed.
    float totalVolume;          // Will hold the total volume of all of the cones.
    float radius;               
    float height; 
    float oneThird = .33333337; // Used for formula to compute cone volume.
    float pi = 3.14159;         // Used to compute cone volume.
    bool radiusBad;             
    bool heightBad;   


    do
    {   
        totalVolume = 0;                            // Initialize var for currrent iteration.     
        int coneNumber = 1;                         // Holds the number of the cone we're asking USER for data on.
        cones = getConeNumber();                    // Get number of cones from user.        
        while(cones > 0)                            
        {                
            radiusBad = true;                       
            heightBad = true;        
            while(radiusBad)
            {
                cout << "Enter cone #" << coneNumber << "'s radius: ";                      // Ask USER for radius.
                cin >> radius;                                                          
                if(radius > 0) radiusBad = false;                                           // If radius is > 0, terminate loop.
                else cout << "\a\nINVALID INPUT -- User must enter a positive number.\n\n"; // Otherwise tell them we need a (+) #.
            }
            while(heightBad)
            {
                cout << "Enter cone #" << coneNumber << "'s height: ";                      // Ask USER for height.
                cin >> height;                                          
                if(height > 0) heightBad = false;                                           // If height is >, terminate loop.
                else cout << "\a\nINVALID INPUT -- User must enter a positive number.\n\n"; // Otherwise tell USER we need a (+) #.
            }
            totalVolume += (oneThird)*pi*(pow(radius, 2))*height;                           // Compute running total volume.
            coneNumber++;                                                                   // increase current cone number.
            cones--;                                                                        // Cross 1 cone off the to-do list.
        }
        cout << "The total volume of the cones is: " << totalVolume << endl;                // Display the total volume to the USER.
    }while(programRunning());                                                               // Ask USER if they want another calculation.
    
    //----- END MAIN --------//
    return 0;
}

//------- Functions -----------//

/**
 * @brief Prompt the USER to enter the number of cones for which they'd like the total volume to be calculated.
 *  Will perform input validation, which ensures that the number is non-negative.
 * @return rv - the number of cones the User entered.
 */
int getConeNumber()
{
    int rv;                             
    bool keepAsking = true;
    while(keepAsking)
    {
        cout << "How Many Cones?: ";    // ask USER for the number of cones.
        cin >> rv;
        if(rv > 0) keepAsking = false;  // if number of cones is non-negative, exit WHILE-LOOP.
        else cout << "\a\nINVALID INPUT -- The number of cones must be non-negative.\n\n"; 
    }
    return rv;
}

/**
 * @brief This method will ask the USER if they would like another calculation of total volume. If not, the program will end. 
 * It will validate input, ensuring that only the following characters are accepted: Y, y, C, c.
 * 
 * @return true - if the user would like to continue.
 * @return false - if the user wants to exit the program.
 */
bool programRunning()
{
    char userInput;                 // Used to store user's response
    bool keepAsking = true;         // will control termination of while loop
    while(keepAsking)
    {
        cout << "Would you like to compute more volumes? (Y/N): ";
        cin >> userInput;
        switch(userInput)
        {
            case 'Y':
            case 'y':
                keepAsking = false; // Stop while loop.
                return true;
                break;
            case 'N':
            case 'n':
                keepAsking = false; // Stop While Loop.
                return false;
                break;
            default:
                cout << "\nINVALID INPUT -- User must enter a 'Y' or 'N'.\n\n"; // Tell USER they MUST enter either Y, y, N, n.
                break;
        }
    }
    return -1;
}
