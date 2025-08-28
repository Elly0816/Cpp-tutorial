/**
 * 
 * This file contains functions for calculating ages
 * 
 * 
 */

#include <iostream>
#include "utils.hpp"
#include <limits>
#include <iomanip>

using namespace std;


// This function returns the average value of n number of ages taken as input
int averageAge(){

    int sum_of_ages = 0, num_of_ages=0, curr_age;
    float avg_age = 0;

    cout<<"Enter the ages and we will calculate the average "<<endl;
    while(true){
        static int j=15;
        cout<<"Enter age #"<<num_of_ages+1<<" ";
        cin>>curr_age;
        if(cin.fail()||curr_age<0){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Quitting..."<<endl;
            break;
        }
        num_of_ages++;
        sum_of_ages+=curr_age;
        avg_age = (float)sum_of_ages/(float)num_of_ages;
        cout<<"\n\nNumber of ages: "<<num_of_ages<<"\nSum of ages: "<<sum_of_ages<<"\nAverage age: "<<fixed<<setprecision(2)<<avg_age<<"\n"<<endl;
        j++;
        cout<<"The value of j is: "<<j<<endl;
    }
    cout<<"\n\nNumber of ages: "<<num_of_ages<<"\nSum of ages: "<<sum_of_ages<<"\nAverage age: "<<fixed<<setprecision(2)<<avg_age<<"\n"<<endl;



    return 0;
}