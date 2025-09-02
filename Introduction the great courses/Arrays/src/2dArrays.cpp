#include "utils.hpp"
#define INNER 3
#define OUTER 5

/**
 * NOTE
 * With regard to segfault, you might not always get them when accessing array indices that are out of bounds
 * Sometimes, you would just get a garbage value when trying to access sucn array indices.
 * But if you go far enough out of bounds, then you will get a segfault
 *
 *
 */
using namespace std;

int xdArrays()
{
    int multiArr[OUTER][INNER];

    for (int i = 0; i < OUTER; i++)
    {
        for (int j = 0; j < INNER; j++)
        {
            // multiArr[i][j] = i * j;
            multiArr[i][j] = 0;
        }
    }
    // This could give back garbage values
    //  cout << "This should not be accessable: " << multiArr[3][5] << endl;
    multiArr[2][1] = 53;
    multiArr[4][2] = 53;

    int arr[5];
    // The line below should give a segfault at runtime
    //  cout << arr[5000000000000000] << "<- should not be accessable!" << endl;

    for (int i = 0; i < OUTER; i++)
    {
        for (int j = 0; j < INNER; j++)
        {
            cout << "The value at array position[" << i << "][" << j << "] is " << multiArr[i][j] << endl;
        }
    }

    return 0;
}