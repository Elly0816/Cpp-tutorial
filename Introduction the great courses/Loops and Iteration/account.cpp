#include "utils.hpp"
#include <limits>//Allows us to use the numericlimits function
#include <iostream>
#include <iomanip>//Allows us to use the setprecision function

using namespace std;

int accountBalance(){
        int number_of_payments;
    float balance =1000, interest = 0.05, payment;


    cout<<"Enter the number of payments: ";
    while(true){
    
        cin>>number_of_payments;

        if(cin.fail()){//This checks if there was a failure with reading in the input to the variable
            /*
                There are various methods available in the cin class: .fail(), .good(), and .eof() are some of them.
            */
            cin.clear();// This clears any error messages
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            /**
             * This flushes the input buffer by ignoring a certain number of inputs (1st param) or until the delimiter(2nd param). 
             * numeric_limits<streamsize>::max() returns the maximum numeric value for the streamsize type
             * streamsize is just a signed integral type that holds the value of the size of the input stream
             * 
             */
            cout<<"Enter a valid number: ";
        }else {
            break;
        }
    }

    cout<<"How much in payment would you like to make: ";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(true){
        
        cin>>payment;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Enter a valid number for payment: ";
        } else {
            break;
        }
    }


    int i=0;
    while(balance > payment && i<number_of_payments){
        balance+=balance*interest;
        balance -= payment;
        cout<<"Your remaining balance after "<<i+1<<" payment(s) is: "<<fixed<<setprecision(2)<<balance<<endl;
        /**
         * 
         * The function setprecision() sets the precision of a number streamed into it
         * The function fixed() displays that floating point number in fixed notation instead of scientific notation
         * 
         */
        i++;
    }
    if(balance < payment){
        cout<<"Your balance is "<<balance<<". Top up your account to continue making payments!";
    }

    return 0;
}