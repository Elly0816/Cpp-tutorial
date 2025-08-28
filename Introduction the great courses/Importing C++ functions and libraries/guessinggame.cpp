/**
 *
 *
 * This file contains a function for the implementation of a guessing game
 */
#include <ctime>
#include <cmath>
#include <iostream>
#include "utils.hpp"
#include <cstdlib>

using namespace std;

int guessingGame()
{
    bool shouldPlay = true;

    srand(time(0));
    int number = (rand() % 100) + 1;
    // int number = 25;
    int guesses = 0;
    while (shouldPlay)
    {
        int input;
        cout << "Guess a number from 1 to 100: ";
        cin >> input;
        if (cin.fail())
        {
            cin.clear();                                         // clear the error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear the buffer
            // cout<<"invalid number"<<endl;
            shouldPlay = false;
            cout << "Quitting..." << endl;
            break;
        }
        guesses++;
        if (input == number)
        {
            cout << "Well done, you guessed " << number << " right in " << guesses << " guesses" << endl;
            shouldPlay = false;
            break;
        }
        string highOrLow = (input > number) ? "too high" : "too low";
        cout << "Wrong guess!\nYour guess was " << highOrLow << ".\nTry again" << endl;
    }

    return 0;
}