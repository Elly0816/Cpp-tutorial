/**
 *
 * This program calculates the average temp over a few days
 *
 */

#include "utils.hpp"
using namespace std;

vector<float> avgTemp(int days)
{
    vector<float> temps(days);
    // Continuously read temp inputs
    for (int i = 0; i < days; i++)
    {
        cout << "Enter temp " << (i + 1) << " of " << days << ": ";
        float val;
        while (true)
        {
            cin >> val;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter a valid float or int! ";
            }
            else
            {

                break;
            }
        }
        temps[i] = val;
    }
    return temps;
}