/*
Destiny Hicks 
June 10, 2026
lab 13 : introduction to function
*/
#include <iostream>
#include "lab13_fuction_hicks.cpp"
using namespace std;
int main (){

cout<<"\n  - - - - - - - - - - Example 1: void fuction"<<endl;
printhi();
printhi();
printhi();

cout<<"\n  - - - - - - - - - - Example 2: void function with arguments"<<endl;
greeting("Peter");
string user = "Annie";
greeting(user);

cout<<"\n  - - - - - - - - - - Example 3: function that returns a value - - - - - - - -"<<endl;
int x = dbnumber(6);
cout<<x;

cout<<"\n  - - - - - - - - - - Example 4: function that returns the area of a rectangle - - - - "<<endl;
float a = arearectangle(2,2);
cout<<"Area rectangle = "<<a<<endl;



cout<<"\n  - - - - - - - - - - Example 5: function with alternative return value - - - "<<endl;
string r = checknumber(-2);
cout<<r<<endl;















    return 0;
}