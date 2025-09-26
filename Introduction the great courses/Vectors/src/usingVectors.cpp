#include "utils.hpp"

using namespace std;

int usingVectors(void)
{
    vector<int> v;
    vector<float> temps;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    int len = v.size();
    for (int i = 0; i < len; i++)
    {
        cout << "The item at position " << i << " is: " << v[i] << endl;
    }

    return 0;
}