/*  Modify the program below to display the output exactly as shown below.  You MUST use one
cout statement with a series of format specifiers
This program will be automatically graded to verify your output matches the output shown

Name        Age      IQ
----        ---     -----
Frodo        22     112.2
Sam          32      94.3
Bilbo       134     136.1
Pippin       12      86.2
Merry         8      42.3
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string floatToString(float num);

int main()
{
  string names[] = {"Frodo", "Sam", "Bilbo", "Pippin", "Merry"};
  int age[] = {22, 32, 134, 12, 8};
  float iq[] = {112.2, 94.34, 136.123, 86.2, 42.3};

  string printVals[21] = {"Name", "Age", "IQ ", "----", "---", "-----"};
  char iqChar[100];

  for (int i = 6, j = 0; i < 21; i += 3, j++)
  {
    printVals[i] = names[j];
    printVals[i + 1] = to_string(age[j]);
    //printVals[i + 2] = floatToString(iq[j]);
    //printVals[i + 2] = to_string(iq[j]);
    gcvt(iq[j], 4, &iqChar[0]);   // something is still wrong with this. decimal places wrong on sam's IQ  
    printVals[i + 2] = iqChar;

    
    //snprintf(iqChar, sizeof(iqChar), "%.2f", iq[j]);

  }
  cout << setprecision(1) << fixed;
  for (int i = 0; i < 21; i += 3)
  {
    cout << setw(12) << left << printVals[i] << setw(3) << right << printVals[i + 1] << setw(10) << right << setprecision(1) << printVals[i + 2] << endl;
  }

  return 0;
}

string floatToString(float num)
{
  string rv = "";
  int decimalPlacesMoved = 0;
  int integral = 0;

  while (num >= 1)
  {
    num /= 10;
    decimalPlacesMoved++;
  }

  int temp;
  while (decimalPlacesMoved > -1)
  {
    temp = num;
    rv += ((temp*1) + 48);
    decimalPlacesMoved--;
    num -= temp;
    num *= 10;
  }

  rv += ".";
  rv += (num + 48);

  return rv;
}