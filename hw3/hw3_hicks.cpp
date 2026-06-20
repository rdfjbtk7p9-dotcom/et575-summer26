/*
Destiny Hicks
Lottery Simulation
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 5;

// Function prototypes
void winningDigits(int winning[]);
void userTicket(int ticket[]);
bool hasDuplicate(int arr[]);
void checkDuplicates(int winning[], int ticket[]);
int checkWinner(int winning[], int ticket[]);
void printResult(int winning[], int ticket[], int matches);

int main()
{
    srand(time(0));

    int winning[SIZE];
    int ticket[SIZE];

    winningDigits(winning);
    userTicket(ticket);

    checkDuplicates(winning, ticket);

    int matches = checkWinner(winning, ticket);

    printResult(winning, ticket, matches);

    return 0;
}

// Generate winning digits
void winningDigits(int winning[])
{
    for (int i = 0; i < SIZE; i++)
    {
        winning[i] = rand() % 19 + 1;
    }
}

// Get user's ticket numbers
void userTicket(int ticket[])
{
    cout << "Enter 5 numbers between 1 and 19:\n";

    for (int i = 0; i < SIZE; i++)
    {
        do
        {
            cout << "Number " << i + 1 << ": ";
            cin >> ticket[i];

        } while (ticket[i] < 1 || ticket[i] > 19);
    }
}

// Check for duplicates in an array
bool hasDuplicate(int arr[])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if (arr[i] == arr[j])
            {
                return true;
            }
        }
    }
    return false;
}

// Make sure neither array has duplicates
void checkDuplicates(int winning[], int ticket[])
{
    while (hasDuplicate(winning))
    {
        winningDigits(winning);
    }

    while (hasDuplicate(ticket))
    {
        cout << "\nDuplicate number found in your ticket.\n";
        cout << "Please enter all 5 numbers again:\n";

        userTicket(ticket);
    }
}

// Compare corresponding positions
int checkWinner(int winning[], int ticket[])
{
    int matches = 0;

    for (int i = 0; i < SIZE; i++)
    {
        if (winning[i] == ticket[i])
        {
            matches++;
        }
    }

    return matches;
}

// Print results
void printResult(int winning[], int ticket[], int matches)
{
    cout << "\nWinning digits = ";

    for (int i = 0; i < SIZE; i++)
    {
        cout << winning[i] << "\t";
    }

    cout << "\nUser ticket =    ";

    for (int i = 0; i < SIZE; i++)
    {
        cout << ticket[i] << "\t";
    }

    cout << "\nMatch numbers = " << matches << endl;
}