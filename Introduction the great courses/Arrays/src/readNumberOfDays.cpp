#include "utils.hpp"

using namespace std;

int readNumberOfDays()
{

    cout << "Enter the number of days you want to insert values for: ";
    int days;
    while (true)
    {
        cin >> days;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter a valid integer! ";
        }
        else if (days < 0)
        {
            return -1;
        }
        else
        {
            return days;
        }
    }
}