#include "utils.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // usingVectors();
    // getAges();
    // vector<float> accounts(4, 100.00);
    // for(int i=0; i<accounts.size(); i++){
    //     cout<<accounts.at(i)<<" ";
    // }
    // cout<<endl;
    // accounts.at(2) = 24.5;
    // accounts.resize(6, 100.00);
    // for(int i=0; i<accounts.size(); i++){
    //     cout<<accounts[i]<<" ";
    // }
    // cout<<endl;
    // accounts.resize(5);
    // for(int i=0; i<accounts.size(); i++){
    //     cout<<accounts[i]<<" ";
    // }

    vector<int> a = {1,2,3};
    vector<int>b(3);
    b=a;
    for(int i=0; i<a.size(); i++){
        cout<<"value in a: "<<a.at(i)<<", value in b: "<<b.at(i)<<endl;
    }
    cout<<endl;
    cout<<"Hello World"<<endl;
    return 0;
}