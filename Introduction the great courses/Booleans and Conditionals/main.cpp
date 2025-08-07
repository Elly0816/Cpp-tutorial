#include <iostream>


using namespace std;


int main (){


    cout<<"Enter your age: ";
    int age, discount;
    cin>>age;
    double price = 25.65;


    if(age>=18 && age <65){
        cout<<"You are not eligible for the discount because you are "<<age<<" years old"<<endl;
        cout<<"But our prices are so low that you will not notice"<<endl;
    } else {
        cout<<"You are eligible for the discount because you are "<<age<<" years old"<<endl;
        discount = 12;
        price =price*((double)discount/100);
    }
    cout<<"Your final price is "<<price<<endl;
    return 0;
}
 