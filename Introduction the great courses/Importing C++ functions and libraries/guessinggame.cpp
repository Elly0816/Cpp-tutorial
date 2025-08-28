// /**
//  *
//  *
//  * This file contains a function for the implementation of a guessing game
//  */

#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include <limits>
#include "utils.hpp"

using namespace std;

int guessingGame()
{
    // Generate a random number from 1 to 100
    srand(time(0)); // Seed for random number generation is current time
    int number = (rand() % 100) + 1;

    int input;
    // Keep asking the user for input
    cout << "This is a guessing game\nGuess a number from 1 to 100" << endl;
    while (true)
    {
        // Keep track of how many guesses the user makes
        static int guesses = 0;
        cout << "Enter a number: ";
        cin >> input;
        // Break out of the loop if reading the input fails
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Quitting..." << endl;
            break;
        }
        guesses++;
        if (number == input)
        {
            // Congratulate the user and show them how long it took to make the correct guess
            cout << "\nCongratulations, you've guessed " << number << " in " << guesses << " tries." << endl;
            break;
        }
        else
        {
            string higherOrLower = (input > number) ? " Too high " : " Too low ";
            cout << higherOrLower << "\nTry again\n"
                 << endl;
        }
    }
    return 0;
}
