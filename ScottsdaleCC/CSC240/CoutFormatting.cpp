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

int main() {
  string names[] = {"Frodo","Sam","Bilbo","Pippin","Merry"};
  int age[] = {22, 32, 134, 12, 8};
  float iq[] = {112.2, 94.34, 136.123, 86.2, 42.3 };
  string data = ""; // Stores formatted string
  
  
  string * namePtr = &names[0];
  int * agePtr = &age[0];
  float * iqPtr = &iq[0];
  
  
  for (int i = 0; i < 5; i++) {
     data = data + namePtr[i] + to_string(agePtr[i]) + to_string(iqPtr[i]) + "\n";
  }


  cout <<"Name"<< setw(8) << "Age" << setw(7) << "IQ\n"
    <<"----"<< setw(8) << "---" << setw(9) << "-----\n" 
    << data << endl;
  
  /*
  for (int i = 0; i < 5; i++) {
     cout <<  names[i] << age[i] << iq[i] << endl;
  }
*/
  
 return 0; 
}
