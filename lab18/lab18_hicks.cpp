/*
Destiny Hicks 
June 17,18, 2026
lab 18: 

*/

#include <iostream>
#include <string>
#include "lab18_function_hicks.cpp" // Includes all updated functions above

using namespace std;

int main() {
    // ----------------------------------------
    // RUNNING CLASS EXAMPLES
    // ----------------------------------------
    cout << "\n - - - - - - example 1: console failure test" << endl;
    checknumber();

    cout << "\n - - - - - - example 2 : console failure test" << endl;
    float n = validatenumber();
    cout << "Returned Validated Float: " << n << endl;

    cout << "\n - - - - - - example 3: read file " << endl;
    iofiles();
    
    cout << "\n - - - - - - example 4: write file " << endl;
    writefile();

    cout << "\n - - - - - - example 5: append data into a file " << endl;
    string filename = "outputfile.txt";
    appendfile(filename);

    // ----------------------------------------
    // RUNNING ASSIGNMENT EXERCISES
    // ----------------------------------------
    cout << "\n - - - - - - Lab Exercise 1: Calculator - - - - - - -" << endl;
    double a = 12.0;
    double b = 4.0;
    cout << "Passing numbers: " << a << " and " << b << "\n";
    
    double finalResult = performOperation(a, b); 
    cout << "The final calculator result is: " << finalResult << "\n";


    cout << "\n - - - - - - Lab Exercise 2: File Management - - - - - - -" << endl;
    // Task A: Creates data_user.txt with "This is my output file – Destiny Hicks."
    createAndWriteFile();

    // Task B: Appends a dynamic message to data_user.txt
    appendToUserFile("This is a new line passed as an argument!");

    // Task C: Overwrites a custom file name with custom text
    overwriteUserFile("custom_overwrite.txt", "This text completely replaces what was inside this file.");

    // The ONLY exit statement for the whole application
    return 0; 
}
