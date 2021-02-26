/**
 * @file Scores.cpp
 * @author Sam Kacprowicz
 * @brief This program will demonstrate the student's ability to work with dynamic arrays. It will have the
 * USER enter a number, which will be the number of elements in a dynamically-allocated array that will hold 
 * floating-point numbers. The USER will then enter the value of the elements, one-by-one, until the array is
 * full. A running-total will accumulate as the elements are entered. Once the array is full, the average
 * of the elements will be calculated using the runnning-total and the number the USER had previously entered
 * as the desired amount of elements.
 *      Once the average has been printed to the screen, the elements the the array will be sorted, from least
 * to greatest, with a function written to sort using the INSERTION-SORT algorithm. The elements will then
 * be printed to the screen from least to greatest. 
 *      Finally, a function that will determine if the array contains a USER-SPECIFIED value will inform the 
 * USER if the array contains that value.
 * @version 0.1
 * @date 2020-04-08
 * 
 * 
 */

#include <iostream>
#include <string>

using namespace std;

//---------- FUNCTION PROTOTYPES ---------------//
void sort(float* score, int num_scores);    // a prototype whose function has a
                                            // dynamic array as its first
                                            // parameter. It is a pointer variable
void indexOf(float* score, int size, float id);       

int main()
{
    float *score = nullptr;	                    // a pointer variable.
    int num_scores = 0;                         // # of score.
    int scoreSize = 0;                          // Holds size of array.
    int pos = 0;                                // Used in FOR-LOOPS to traverse.
    float total = 0.0;                            // Will hold running total of the sum of numbers entered.
    float avg = 0.0;                              // Hold the average of the elements in array.
    float id = 0.0;                               // Holds number user wants to search for.


    //--------- START MAIN -------------------//
    cout << "Enter the number of scores: "; // Ask USER to enter number of scores
    cin >> num_scores;                      

    score = new float[num_scores];	        // allocation of the array. 
    scoreSize = num_scores;

    if(score == nullptr)                    // Make sure everything worked.
    {
        cout << "\aError allocating memory!\n";
        return 1;
    }

    for(pos = 0; pos < num_scores; pos++)
    {
        cout << "Please enter a score" << endl;     // Prompt USER to enter scores, individually.
        cin >> score[pos];                          // Read scores into different positions in array
        total += score[pos];                        // Add the new number to total.
    }
    
    avg = total / (static_cast<float>(num_scores));   // Cast num_score and compute average
    
    cout << "The average of the scores is " << avg << endl;
    
    sort(score, num_scores);	                        // Call to the function.

    cout << "\nHere are the scores in ascending order";
    for(pos = 0; pos < num_scores; pos++)
    {
        cout << endl << score[pos];                 // Print out all of the elements.
    }
    cout << endl;

    cout << "Please input an id number to be searched" << endl;
    cin >> id;
    indexOf(score, num_scores, id);

    delete[] score;

    return 0;
    //------ END MAIN --------------//
}

//------------ Functions --------------------------//

/**
 * @brief Method will sort the array elements from least to greatest using the INSERTION-SORT
 * algorithm.
 * 
 * @param score 
 * @param num_scores 
 */
void sort(float* score, int num_scores)
{    
    int j = 0;                                      // Holds location of current element.
    float temp;                                 // Holds value to be swapped.
    for(int i = 0; i < num_scores; i++)
    {
        j = i;                                  // Set j to the next position to be evaluated. 
        while(j > 0 && score[j-1] > score[j])
        {
            temp = score[j];                    // Store value, so as not to prevent data leak.
            score[j] = score[j-1];              // Change current element's value to the one on the "left"
            score[j-1] = temp;                  // Change "left" element's value to temp.
            j--;                                // Make element on the "left" the next one to compare in WHILE-LOOP.
        }
    }
}

/**
 * @brief This method will traverse through a dynamic array, searching for a value. If the value is found,
 * the method will immediately infrom the USER the array contains the value, and promptly return. If the
 * value is not found, the entire array will have been traversed, but then will inform the USER the array
 * does not contain the value.
 * 
 * @param score pointer to the dynamic array to be searched.
 * @param size size of dynamic array.
 * @param id value to search for.
 */
void indexOf(float* score, int size, float id)
{
    for(int i = 0; i < size; i++)
    {
        if(score[i] == id) 
        {
            cout << "\n" << id << " is in the array." << endl;
            return;
        }
    }
    cout << "\n" << id << " is not in the array." << endl;
    return;
}