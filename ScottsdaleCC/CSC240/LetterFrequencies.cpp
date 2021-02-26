/**
 * @file LetterFrequencies.cpp
 * @author Sam Kacprowicz
 * @brief This program will get a filename from the user and display the 
 * number of occurances of each letter in the file, ignoring 
 * upper-, or lower-case, and non-Alphabet symbols. 
 * @version 0.1
 * @date 2020-03-11
 * 
 */
#include <iostream>
#include <fstream>

using namespace std;

//--------- Function Prototypes --------------//
void getAndPrintText(string &rv);
char toLowerCase(char c);
void countOccurances(string words, int letterCount[]);
void displayFrequencies(int letterCount[]);
bool continueProgram();

int main()
{
    string fileContents;
    int letters[26];
    int* arrayPtr = letters;
    //int continueProgram = 1;

    do{
        fileContents = "";                          // Set fileContents to empty string at start of each run.
        getAndPrintText(fileContents);              // Get filename from user, and print contents to screen.
        countOccurances(fileContents, &letters[0]); // Store occurances in array.
        displayFrequencies(&letters[0]);            // Display stats to screen.
    }while(continueProgram());                      // Ask user if they want another analysis.
    return 0;
}


//----------- Functions -------------------//
/**
 * @brief Get the And Print Text file, and store in String. 
 * 
 * @param rv 
 */
void getAndPrintText(string &rv)
{
    ifstream inFile;                        // Object used to read from file.
    string fileName;                        // Stores user-input filename.
    char letter;                            // Holds value of char read from file, then copies it to string.

    printf("%s", "Enter the filename: ");   // Prompt user to enter filename.
    getline(cin, fileName);                 // Get and store fileName.
    
    inFile.open(fileName);                  // Open file.
    if(!inFile)                             // Check to see if file was opened;
    {
        cout << "File not opened\n";        // Tell user if there was a problem.
        return;                             // Get outta dodge.
    }
    cout << "\n--- FILE CONTENTS ---\n\n";
    while(inFile)                           // WHILE !EOF
    {
        inFile.get(letter);                 // Get a letter from the file.
        cout << letter;                     // Print the letter to the screen.
        rv += letter;                       // Add the letter to the string. 
    }
    cout << "---- END OF FILE ----\n\n";
}

/**
 * @brief Method will count the occurances of each letter in the text, and will store 
 * the occurance number in an array, where the index is the letter's position in the alphabet.
 * Array indicies will be based on A = 0, Z = 25. 
 * 
 * @param words 
 * @param letterCount 
 */
void countOccurances(string words, int letterCount[])
{
    char c;    
    
    for(int i = 0; i < 26; i++) letterCount[i] = 0; // Initialize all elements to zero.
    
    for(int i = 0; words[i] != '\0'; i++)           
    {        
        c = toLowerCase(words[i]);                  // Convert to lower-case.
        if(c >= 'a' && c <= 'z')                    // If character is a letter.
        {
            letterCount[c - 'a']++;                 // Increment the number of times that letter appears.
        }
    }
}

/**
 * @brief Method uses two FOR-LOOPS to, first, count the number of characters, and then to display 
 * the occurances of the number of letters as a percentage. Halfway through the printing the user 
 * will be prompted whether they would like to continue or not. 
 * 
 * @param letterCount 
 */
void displayFrequencies(int letterCount[])
{
    char letter = 'A';
    string letterStats;    
    string percentage = "";         
    char userInput;          // Used to store user's response to continue printing.
    int numOfLetters = 0;
    

    // FOR-LOOP will count the number of letters in the text.
    for(int i = 0; i < 26; i++) 
    {
        if(letterCount[i] > 0) numOfLetters += letterCount[i];
    }

    cout << "\nLETTER FREQUENCIES:\n\n";
    for(int i = 0; i < 26; i++)
    {           
        if(i == 13)
        {
            int keepAsking = 1;
            while(keepAsking)
            {
                cout << "\nContinue printing? (Y/N): ";
                userInput = getchar();
                getchar();
                cout << "\n";
                switch(userInput)
                {
                    case 'y':
                    case 'Y': 
                        keepAsking = 0;
                        continue;
                        break;
                    case 'n':
                    case 'N':
                        return;
                        break;
                    default:
                        cout << "\nInvalid input. Please enter 'Y' or 'N'.\n";
                        break;
                }
            }        
        }   

        letterStats = "";  
        percentage = to_string((((double)letterCount[i]/(double)numOfLetters)*100));

        letterStats = letterStats + (char)letter + ": " + to_string(letterCount[i]) + " " + percentage + "%";
        if(letterCount[i] > 0) 
        {
            letterStats = letterStats + " (" + to_string(letterCount[i]) + "/" + to_string(numOfLetters) + ")";  
        }
        cout << "* " << letterStats << endl;      
        letter++;
    }
}

/**
 * @brief Converts a character to lower-case. The conversion method is to simply add 32 to the char, but only after 
 * determining that the char is an upper-case letter.
 * 
 * @param c - char to convert.
 * @return char - converted char.
 */
char toLowerCase(char c)
{
    if(c >= 'A' && c <= 'Z') c += 32;
    return c;
}

/**
 * @brief Asks the user if they would like the program to analyze another text file. Validates input
 * and will only accept upper-, or lower-case 'Y' or 'N'.
 * 
 * @return true 
 * @return false 
 */
bool continueProgram()
{
    bool rv;
    char userInput;
    int keepAsking = 1;
    while (keepAsking)
    {
        cout << "\nWould you like to analyze another file? (Y/N): ";
        userInput = getchar();
        getchar();
        switch (userInput)
        {
            case 'y':
            case 'Y':
                keepAsking = 0;
                rv = true;
                break;
            case 'n':
            case 'N':
                keepAsking = 0;
                rv = false;
                break;
            default:
                cout << "\nInvalid input. Please enter 'Y' or 'N'.\n";
                break;
        }
    }
    return rv;
}