#include "utils.hpp"
#include <ios>
#include <iostream>
#include <limits>
#include <vector>


using namespace std;

int getAges(){

    //Prompt user to keep entering ages, until they enter a negative number

    bool shouldContinue = true;
    vector<int> ages;

    cout<<"Keep entering ages, enter a negative number to stop"<<endl;
    while(shouldContinue){
        cout<<"Enter age: ";
        int age;
        cin>>age;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Enter a valid age!"<<endl;
            continue;
        }
        if(age>=0){
            ages.push_back(age);
        } else{
            shouldContinue = false;
        }
    }
    cout<<"The ages entered are:"<<endl;
    for(int i=0; i<ages.size(); i++){
        cout<<ages[i]<<endl;
    }
    return 0;
}


