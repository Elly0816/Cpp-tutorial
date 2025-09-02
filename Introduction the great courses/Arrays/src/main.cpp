/**
 * Introduction to Arrays in C++
 *
 */
#include "utils.hpp"
#include "numeric"
#include <iomanip>
using namespace std;

int main()
{

    xdArrays();
    // string days[] = {"Sun", "Mon", "Tue", "Wed", "Thur", "Fri", "Sat"};

    // // Get the number of days to get values for
    // int numberOfDays = readNumberOfDays();

    // if (numberOfDays < 0)
    // {
    //     cout << "There are no days to calculate average for!";
    //     return 0;
    // }

    // // Get the temps for each day
    // vector temps = avgTemp(numberOfDays);

    // // Get the average of the values
    // float avg = accumulate(temps.begin(), temps.end(), 0.0) / temps.size();
    // for (int i = 0; i < temps.size(); i++)
    // {
    //     int index = getIndex(i, sizeof(days) / sizeof(string));
    //     cout << "The current index is: " << index << endl;
    //     cout << "The temp on " << (days[index]) << " is " << temps[i] << "\n"
    //          << endl;
    // }
    // cout << "The average of all the temps is: " << fixed << setprecision(2) << avg << "\n";

    // // Get days with temps that are greater than the average
    // cout << "The day(s) with temps that are more than the average are:\n";
    // for (int i = 0; i < temps.size(); i++)
    // {
    //     int index = getIndex(i, sizeof(days) / sizeof(string));
    //     if (temps[i] > avg)
    //     {
    //         cout << days[index] << " with a temp of " << temps.at(i) << endl;
    //     }
    // }

    return 0;
}