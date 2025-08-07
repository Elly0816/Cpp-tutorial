// Blood Pressure Analyzer program
//Last edited by Eleazar

#include <iostream>
#include "utils.h"
using namespace std;



int main(){


    // cout<<"Hello World"<<endl;

    //Declare variables to hold systolic and diastolic pb
    int sys,dia;

    //Read in Systolic BP
    cout<<"Enter systolic bp (The larger number): ";
    cin>>sys;
    // cout<<endl;
    
    //Read in Diastolic BP
    cout<<"Enter diastolic bp (The smaller number): ";
    cin>>dia;
    // cout<<endl;


    // string report = getMeasurement(sys, dia);

    // Returns a string telling the user what their bp is
    cout<<getMeasurement(sys, dia)<<endl;

    return 0;
}


