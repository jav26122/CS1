/*
  Pgm: ASSGN4-A  Name: Jaret Varn
  Date: 10/6/18
  Purpose: The purpose of this assignment is to make sure that you know how to
  write a program that contains functions that meet specific requirements.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <limits>


using namespace std;

int getUserChoice()
{
    cout << "Select your choice:\n";
    cout << "1) Rock\n2) Paper\n3) Scissors\n4) Lizard\n5) Spock\n";
    int userChoice;
    cin >> userChoice;
    while (cin.fail() || userChoice < 1 || userChoice > 5)
    {
        cout << "Invalid option, try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> userChoice;
    }
    return userChoice;
}

int getComputerChoice()
{
    return rand() % 5 + 1;
}

string displayChoice(int choice)
{
    if (choice == 1)
    {
        cout << "Rock";
        return "Rock";
    }
    else if (choice == 2)
    {
        cout << "Paper";
        return "Paper";
    }
    else if (choice == 3)
    {
        cout << "Scissors";
        return "Scissors";
    }
    else if (choice == 4)
    {
        cout << "Lizard";
        return "Lizard";
    }
    else
    {
        cout << "Spock";
        return "Spock";
    }
}

string determineWinner(int userChoice, int computerChoice)
{
    switch(userChoice)
    {
        case 1 : // user rock
            switch(computerChoice)
            {
                case 1 : // computer rock
                    return "Tie";
                    break;
                case 2 : // computer paper
                    return "Computer Wins";
                    break;
                case 3 : // computer scissors
                    return "User Wins";
                    break;
                case 4 : // computer lizard
                    return "User Wins";
                    break;
                case 5 : // computer spock
                    return "Computer Wins";
                    break;
            }
        break;
        case 2 : // user paper
            switch(computerChoice)
            {
                case 1 : // computer rock
                    return "User Wins";
                    break;
                case 2 : // computer paper
                    return "Tie";
                    break;
                case 3 : // computer scissors
                    return "Computer Wins";
                    break;
                case 4 : // computer lizard
                    return "Computer Wins";
                    break;
                case 5 : // computer spock
                    return "User Wins";
                    break;
            }
        break;
        case 3 : // user scissors
            switch(computerChoice)
            {
                case 1 : // computer rock
                    return "Computer Wins";
                    break;
                case 2 : // computer paper
                    return "User Wins";
                    break;
                case 3 : // computer scissors
                    return "Tie";
                    break;
                case 4 : // computer lizard
                    return "User Wins";
                    break;
                case 5 : // computer spock
                    return "Computer Wins";
                    break;
            }
        break;
        case 4 : // user lizard
            switch(computerChoice)
            {
                case 1 : // computer rock
                    return "Computer Wins";
                    break;
                case 2 : // computer paper
                    return "User Wins";
                    break;
                case 3 : // computer scissors
                    return "Computer Wins";
                    break;
                case 4 : // computer lizard
                    return "Tie";
                    break;
                case 5 : // computer spock
                    return "User Wins";
                    break;
            }
        break;
        case 5 : // user spock
            switch(computerChoice)
            {
                case 1 : // computer rock
                    return "User Wins";
                    break;
                case 2 : // computer paper
                    return "Computer Wins";
                    break;
                case 3 : // computer scissors
                    return "User Wins";
                    break;
                case 4 : // computer lizard
                    return "Computer Wins";
                    break;
                case 5 : // computer spock
                    return "Tie";
                    break;
            }
        break;
    }

}


int main()
{
    srand(time(0));
    bool tied = true;
    while (tied == true)
    {
        int computerChoice = getComputerChoice();
        int userChoice = getUserChoice();
        cout << "You selected ";
        displayChoice(userChoice);
        cout << " and the computer chose ";
        displayChoice(computerChoice);
        string winner = determineWinner(userChoice, computerChoice);
        if (winner == "Computer Wins")
        {
            cout << "\nThe computer wins\n";
            tied = false;
        }
        else if (winner == "User Wins")
        {
            cout << "\nYou win!\n";
            tied = false;
        }
        else
        {
            cout << "\nIt's a tie! Play again to determine the winner.\n";
        }
    }

}
