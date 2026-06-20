#include <iostream>
#include <limits>
#include <fstream>
#include <string>

using namespace std;

// ==========================================
// CLASS EXAMPLES (1 - 5)
// ==========================================

// Example 1: Console failure test
void checknumber(){
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if (cin.fail()) {
        cout << "Error! Mismatched data type!" << endl;
    } else {
        cout << "Entered number = " << num << endl;
    }
    cin.clear();
    cin.ignore(10000, '\n');
    cout << " - - - - - - - END OF FUNCTION - - - - - - -" << endl;
}

// Example 2: Validate a data type 
float validatenumber(){
    float n;
    while (true) {
        cout << "Enter a float number: ";
        if (!(cin >> n)) {
            cout << "Invalid data type!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        } else {
            break;
        }
    }
    return n;
}

// Example 3: Input and output files 
void iofiles(){
    ifstream fin;
    fin.open("samplefile.txt");

    if (!fin.is_open()) {
        cout << "Could not open samplefile.txt (Make sure it exists!)" << endl;
        return;
    }

    string line;
    int linecounter = 1;
    while (getline(fin, line)) {
        cout << "Line " << linecounter << "= \t" << line << endl;
        linecounter++;
    }
    fin.close();
}

// Example 4: Write file 
void writefile(){
    ofstream fout;
    fout.open("outputfile.txt");

    fout << "Good Morning !" << endl;
    for (int n = 3; n > 0; n--) {
        fout << n << endl;
    }
    fout << "End of file" << endl;

    fout.close();
}

// Example 5: Appending data to an existing file 
void appendfile(string filename){
    ofstream fout;
    fout.open(filename, ios::app);
    fout << "Destiny Hicks" << endl; // Appends your name to the file
    fout.close();
}


// ==========================================
// ASSIGNMENT EXERCISES (1 & 2)
// ==========================================

// LAB EXERCISE 1: Calculator with Validation
double performOperation(double num1, double num2) {
    char op;
    bool isValid = false;
    double result = 0.0;

    while (!isValid) {
        cout << "Enter an operator (+, -, *, /, %): ";
        cin >> op;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input stream. Please try again.\n";
            continue;
        }

        switch (op) {
            case '+':
                result = num1 + num2;
                isValid = true;
                break;
            case '-':
                result = num1 - num2;
                isValid = true;
                break;
            case '*':
                result = num1 * num2;
                isValid = true;
                break;
            case '/':
                if (num2 == 0) {
                    cout << "Error: Division by zero is not allowed.\n";
                } else {
                    result = num1 / num2;
                    isValid = true;
                }
                break;
            case '%':
                if (static_cast<int>(num2) == 0) {
                    cout << "Error: Division by zero in modulus.\n";
                } else {
                    result = static_cast<int>(num1) % static_cast<int>(num2);
                    isValid = true;
                }
                break;
            default:
                cout << "Incorrect symbol entered. ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
        }
    }
    return result;
}

// LAB EXERCISE 2 - Part A: Create and Write a new file
void createAndWriteFile() {
    ofstream outFile("data_user.txt");
    if (outFile.is_open()) {
        outFile << "This is my output file – Destiny Hicks.\n";
        outFile.close(); // Closed properly
        cout << "File 'data_user.txt' successfully created with your name." << endl;
    } else {
        cerr << "Error creating data_user.txt" << endl;
    }
}

// LAB EXERCISE 2 - Part B: Append text to an existing file
void appendToUserFile(string message) {
    ofstream outFile("data_user.txt", ios::app);
    if (outFile.is_open()) {
        outFile << message << "\n";
        outFile.close(); // Closed properly
        cout << "Message appended to 'data_user.txt'." << endl;
    } else {
        cerr << "Error appending to data_user.txt" << endl;
    }
}

// LAB EXERCISE 2 - Part C: Create/Overwrite custom file with custom text
void overwriteUserFile(string fileName, string text) {
    ofstream outFile(fileName);
    if (outFile.is_open()) {
        outFile << text << "\n";
        outFile.close(); // Closed properly
        cout << "File '" << fileName << "' successfully managed and overwritten." << endl;
    } else {
        cerr << "Error writing to " << fileName << endl;
    }
}