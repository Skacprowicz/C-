#include <iostream>
using namespace std;

class SavingsAccount
{
    public:
        SavingsAccount();                                   // Default constructor.
        SavingsAccount(int bills, int change);              // Make account with bills amound of dollar and change amount of cents.
        void deposit(int bills, int change);          // Deopsit money.
        void withdrawl(int bills, int change);    // Withdrawl money.
        void showCurrentBalance() const;                    // Print balance.
    private:
        int dollars;
        int cents;
};

int main()
{
    /*
    SavingsAccount bank1(200, 50);
    bank1.showCurrentBalance();
    bank1.deposit(40, 50);
    bank1.showCurrentBalance();
    bank1.withdrawl(100, 98);
    bank1.showCurrentBalance();
    */

    // Exercise 2
    bool depositAsk = true, withdrawlAsk = true;
    int bills = 0, cents = 0;
    string userInput = "";
    cout << "Please input the initial dollars" << endl;
    cin >> bills;
    cout << "\nPlease intput the initial cents" << endl;
    cin >> cents;
    SavingsAccount bank1(bills, cents);

    while(depositAsk)
    {
        cout << "\nWould you like to make a deposit? Y or y for yes" << endl;
        cin >> userInput;
        if(userInput == "Y" || userInput == "y")
        { 
            cout << "\n\tPlease input the dollars to be deposited" << endl;
            cin >> bills;
            cout << "\n\tPlease input the cents to be deposited" << endl;
            cin >> cents;
            bank1.deposit(bills, cents);    
        }
        else
        {                  
            depositAsk = false; 
            continue;    
        }
        
    }

    while(withdrawlAsk)
    {
        cout << "\nWould you like to make a withdrawl? Y or y for yes" << endl;
        cin >> userInput;
        if(userInput == "Y" || userInput == "y")
        { 
            cout << "\n\tPlease input the dollars to be withdrawn" << endl;
            cin >> bills;
            cout << "\n\tPlease input the cents to be withdrawn" << endl;
            cin >> cents;
            bank1.withdrawl(bills, cents); 
        }
        else
        {             
            withdrawlAsk = false; 
            continue;          
        }
        
    }
    bank1.showCurrentBalance();


    cout << "The following displays the status of the non-user generated SavingsAccount object." << endl;
    SavingsAccount bank2(42, 47);
    cout << "Object \"bank2\" instantiated with a balance of:" << endl;
    bank2.showCurrentBalance();
    bank2.deposit(7,53);
    cout << "\"bank2\" after a deposit of $7.53: " << endl;
    bank2.showCurrentBalance();
    bank2.withdrawl(7, 158);
    cout << "\"bank2\" after a withdrawl of $7 and 158¢: " << endl;
    bank2.showCurrentBalance();
    return 0;
}

//---------- MEMBER FUNCTIONS ------------//
SavingsAccount::SavingsAccount()
{
    this->cents = 0;
    this->dollars = 0;
}
SavingsAccount::SavingsAccount(int bills, int change)
{    
    this->dollars = bills;
    this->cents = change;   

    if(this->cents > 99)
    {
        int changeToDollars = (change / 100);
        this->dollars += changeToDollars;
        this->cents = (this->cents % 100); 
    }   
}   

void SavingsAccount::deposit(int bills, int change)  
{
    int changeToDollars = (change / 100);
    int changeToCents = (change % 100);
    this->cents += changeToCents;
    this->dollars += (bills + changeToDollars);

    if(this->cents > 99)
    {
        changeToDollars = (this->cents / 100);
        this->dollars += changeToDollars;
        this->cents = (this->cents % 100);
    }
}

void SavingsAccount::withdrawl(int bills, int change)
{
    /*    
    int changeToDollars = (change / 100);
    int changeToCents = (change % 100);

    this->dollars -= (changeToDollars + bills);
    this->cents -= (changeToCents);

    if(this->cents < 0)
    {
        this->cents = (100 - this->cents);
    }
    */
    
    this->dollars -= bills;
    this->cents -= change;

    if(this->cents < 0)
    {
        int changeToDollars = (this->cents / 100);
        int changeToCents = (this->cents % 100);
        this->dollars -= (abs(changeToDollars) + 1);
        this->cents = (100 + changeToCents);
    }
}

void SavingsAccount::showCurrentBalance() const
{
    cout << "Dollars = " << this->dollars << "\t cents = " << this->cents << "." << endl;
}                