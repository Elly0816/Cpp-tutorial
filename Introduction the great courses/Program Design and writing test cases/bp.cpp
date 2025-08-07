/**
 * 
 * This finction takes in the systolic and diastolic readings
 * 
 * It returns information back to the user as a string. 
 * 
 * The info returned depends on the reading given as input into the function
 * 
 * 
 */

#include <string>
#include "utils.h"

using namespace std;

string getMeasurement(int systolic, int diastolic){





    // Makes sure that the sys and dia inputs are above 0
    if(systolic == 0 || diastolic == 0){
        return "You are dead";
    }

    // Check for hypotensive bp levels systolic less and or equal to 90 and diastolic less than or equal to 60
    if(systolic<=90 && diastolic <=60){
        return "You have hypotension, your bp is too low!";
    }

    // Check for normal bp levels systolic less than 120 and diastolic less that 80
    if(systolic < 120 && diastolic < 80){
        return "Your bp is normal";
    }

    //Check for elevated bp levels systolic between 120 and 129 and diastolic less than 80
    if (systolic >= 120 && systolic <= 129 && diastolic<80){
        return "Your bp is elevated";
    }
    
    //Check for stage 1 hypertensive bp levels systolic between 130 and 139 and diastolic between 80 and 89
    if(systolic<=139 && systolic >= 130 || diastolic <=89 && diastolic >= 80){
        return "You're at stage 1 hypertension";
    }
    
    //Check for stage 2 hypertensive bp levels systolic between 140 and 180 and diastolic between 90 and 120
    if(systolic>=140 && systolic <= 180 || diastolic <= 120 && diastolic >= 90){
        return "You're at stage 2 hypertension";
        
    }

    //Default case if all else is false
    return "You're currently having a hypertensive crisis!\nVisit a medical professional!";
}