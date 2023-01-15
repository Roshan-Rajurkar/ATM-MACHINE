#include <iostream> //input-output
#include <conio.h>  // getch() - to hold the screan
#include <string>   // for string functionality

using namespace std;

/*
    Mini Project - ATM  (features)
        -> Check Balance
        -> Cash withdraw
        -> User Details
        -> Update Mobile no.
*/

class atm
{ // class atm

private: // private member variables
    long int account_No;
    string name;
    int PIN;
    double balance;
    string mobile_No;

public: // (features provide by ATM machine)
    // setData function is setting the data into private member variables
    void setData(long int ac_No, string ac_Name, int ac_Password, double ac_balance, string ac_mobile)
    {
        account_No = ac_No; // assigning formal value of arguments to respective variables
        name = ac_Name;
        PIN = ac_Password;
        balance = ac_balance;
        mobile_No = ac_mobile;
    }

    // getName function is returning the user's name
    string getName()
    {
        return name;
    }

    // getPIN function is returning the user's PIN
    int getPIN()
    {
        return PIN;
    }

    // getAccountNo function is returning the user's PIN
    int getAccountNo()
    {
        return account_No;
    }

    // getBalance() function is returning the user's bank balance
    double getBalance()
    {
        return balance;
    }

    // getMobileNo function is returning the mobile number of the user
    string getMobileNo()
    {
        return mobile_No;
    }

    // setMobileNo function is updating the user mobile no.
    void setMobileNo(string mob_prev, string mob_new)
    {
        if (mob_prev == mobile_No)
        {
            mobile_No = mob_new;
            // matches
            cout << endl
                 << "Successfully Update Mobile no.";
            getch(); // hold the screen
        }
        else
        {
            cout << "\nIncorrect !!!! Old Mobile Number." << endl;
            getch();
        }
    }

    // cashWithDraw() function to withDraw cash from ATM
    void cashWithDraw(double amount)
    {
        if (amount > 0 && amount < balance) // check enter amount validity
        {
            balance -= amount; // updating the balance remaining after withdraw
            cout << "\nPlease Collect Your cash." << endl;
            cout << "Available balance : " << balance << endl;
            getch(); // hold the screen until you press any key
        }

        else // if (amount > 0 && amount < balance) -> fails
        {
            cout << "\nInvalid Input or Insufficient Balance." << endl;
            getch(); // hold the screen until you press any key
        }
    }
};

// Driver Code
int main()
{
    int choice = 0, enterPIN;
    long int enterAccountNo;

    system("cls");

    // created User (object)
    atm user1;
    // set User detail (into object)   (setting default data)
    user1.setData(1234567, "Roshan", 1234, 4000, "8767198087");

    // loop run infinite as ATM machine Which never sleeps
    do
    {
        system("cls"); // clearing screen

        cout << "\n*----WELCOME TO ATM----*" << endl;
        cout << "Enter your Account Number : " << endl; // asking user for account number
        cin >> enterAccountNo;

        cout << "Enter PIN : " << endl; // asking user for PIN(password)
        cin >> enterPIN;

        // check whether the user is exist or not by referring user details
        if (enterAccountNo == user1.getAccountNo() && enterPIN == user1.getPIN())
        {
            do
            {
                double amount = 0;                 // initially amount is nill
                string old_mobileNo, new_mobileNo; // details for updating mobile number feature

                system("cls");

                // user interface
                cout << "\n**** Welcome to ATM ****" << endl;
                cout << "Select Options" << endl;
                cout << "1. Check Balance." << endl;
                cout << "2. Cash withdraw." << endl;
                cout << "3. Show User Details." << endl;
                cout << "4. Update Mobile no." << endl;
                cout << "5. Exit." << endl;
                cin >> choice; // taking user's choice

                switch (choice) // switch condition according to the choice
                {

                case 1: // if user press 1
                    cout << "\nYour Bank balance is : " << user1.getBalance() << endl;
                    // getBalance is printing users balance;
                    getch();
                    break;

                case 2: // if user press 2
                    cout << "\nEnter the amount : ";
                    cin >> amount;              // getting amount to withdraw
                    user1.cashWithDraw(amount); // calling cashWithDraw function and passing withDraw amount to it.
                    break;

                case 3: // if user press 3
                    cout << endl
                         << "Account holder details" << endl;
                    cout << "Name          : " << user1.getName() << endl; // getting user details
                    cout << "Account No.   : " << user1.getAccountNo() << endl;
                    cout << "PIN           : " << user1.getPIN() << endl;
                    cout << "Mobile Number : " << user1.getMobileNo() << endl;
                    cout << "Bank balance  : " << user1.getBalance() << endl;
                    cout << "----------------------------------------" << endl;
                    getch();
                    break;

                case 4:
                    cout << "Enter Old Mobile number : ";
                    cin >> old_mobileNo; // getting old number

                    cout << "Enter New Mobile number : ";
                    cin >> new_mobileNo; // getting new mobile number

                    user1.setMobileNo(old_mobileNo, new_mobileNo); // setMobileNo is update the mobile number

                    cout << "\nUpdated Mobile Number is " << user1.getMobileNo() << endl;
                    break;

                case 5:      // if user press 5
                    system("cls");
                    exit(0); // exit application
                    break;
                default: // handle invalid user input
                    break;
                }
            } while (1);
        }

    } while (1); // condition is always true and loop is running infinite times

    return 0;
}