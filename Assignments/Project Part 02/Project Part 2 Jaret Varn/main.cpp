/*
  Pgm: Project Part 02  Name: Jaret Varn
  Purpose: The purpose of this part of the project is to make sure that you know how to write a program that utilizes functional programming, and utilizes files and file processing as well as random number generation.


*/


#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <cctype>
#include <limits>


using namespace std;


    // speed constants  (MPH)
const int HELISPEED = 130,
    TURBOSPEED = 250,
    MIDSIZESPEED = 400,
    HEAVYSPEED = 550;
    // location distances  (NM)
const float CLE_ORD = 273.00f,
    ORD_JFK = 641.00f,
    DEN_JFK = 1409.00f,
    JFK_SFO = 2242.00f,
    JFK_MIA = 494.00f,
    DFW_CYYZ = 1041.00f;

void menu(int &flightNumber);
// Precondition: flightNumber is declared as an integer.
// Postcondition: The flight menu is displayed with the unique flightNumber ID.
string toUpper(string input);
// Precondition: The input is a string.
// Postcondition: The string is returned except converted to all capital letters.
int getMenuOption();
// Precondition: None
// Postcondition: Asks the user for their menu selection and then validates the data and returns it.
void getDestination(string &destinationOption);
// Precondition: destinationOption is defined as a string.
// Postcondition: Asks the user for their destination option and validates the data and assigns it to the destinationOption variable.
void getFlightID(int &flightNumber, fstream &log);
// Precondition: flightNumber is defined as an integer and the log is defined via fstream.
// Postcondition: A random number from 1-99999 is generated and then compared to all of the previous flightID's in the log file. If a duplicate flightID is created, then the function recursively calls itself to find a new flightID.
void getWindSpeed(short int &windSpeed);
// Precondition: windSpeed is defined as a short integer.
// Postcondition: Asks the user to enter a wind speed and validates that it is an integer from -100 to 100 and assigns it to the windSpeed variable.
void calculateTime(int &timeMinutes, int &timeHours, int &flightOption, string &destinationOption, short int &windSpeed);
// Precondition: All those variables are defined correctly.
// Postcondition: Calculates the time in minutes and hours based on the options decided by the user. The times are then assigned to the proper variables.
void writeFile(fstream &log, int &flightNumnber, int menuOption, int &timeMinutes, string &destinationOption, int &timeHours, string flightHaul);
// Precondition: The variables are defined.
// Postcondition: All of the appropriate data is written to the log file.
void getCategory(string &flightHaul, int &timeHours);
// Precondition: defined variables.
// Postcondition: This uses the hours to decide what category the flight is and then assigns that to the flightHaul string.
void displayLog(fstream &log);
// Precondition: defined fstream log.
// Postcondition: This displays all of the log data when requested by the user and proper password is given.

int main()
{
    srand(time(0)); // generate the seed for the rand() function
    bool quit = false;
    while (!quit) // control for when to end the program.
    {
        int flightNumber = 0;
        string destinationOption = "";
        short int windSpeed = 0;
        int timeMinutes = 0;
        int timeHours = 0;
        string flightHaul = "";
        fstream log;
        getFlightID(flightNumber, log);
        menu(flightNumber);
        int flightOption = getMenuOption();
        if (flightOption == 6) // user selects quit
        {
            quit = true;
        }
        else
        {
            if (flightOption == 5)
            {
                cout << "Enter password to view log file:\n";
                string password = "";
                cin >> password;
                if (!cin.fail() && password == "Not-telling")
                {
                    displayLog(log); // user gets password correct, continue with program and display the log info
                    cout << "\nPress any key to continue\n";
                    cin.get();
                    cin.get(); // I honestly have no clue why I need 2 cin.get()'s, but one of them doesn't work.
                }
                else
                {
                    cout << "SECURITY BREACH! PROGRAM ENDING..."; // password is wrong, program terminates.
                    quit = true;
                }
            }
            else
            {
                getDestination(destinationOption);
                getWindSpeed(windSpeed);
                calculateTime(timeMinutes, timeHours, flightOption, destinationOption, windSpeed);
                cout.precision(1);
                cout << endl << fixed << showpoint << "Your total flight time from " << destinationOption << " was: " << timeHours << " hours and " << timeMinutes << " minutes.\n"; // display the calculated time of the flight
                getCategory(flightHaul, timeHours);
                cout << flightHaul << endl; // display the category of the flight
                writeFile(log, flightNumber, flightOption, timeMinutes, destinationOption, timeHours, flightHaul); // write the data to the log file.
                cout << "\nPress any key to continue\n";
                cin.get();
                cin.get(); // I honestly have no clue why I need 2 cin.get()'s, but one of them doesn't work.
            }
        }
    }
}

string toUpper(string input)
{
    string output = "";
    for (int i=0; i < input.length(); ++i)
    {
        output += toupper(input[i]); // change each individual character of input to uppercase and add it to the output string
    }
    return output;
}


void menu(int &flightNumber)
{
    static int menuCount = 0; // counter for amount of times the menu is opened.
    ++menuCount;
    cout << setw(60) << cout.fill('_') << endl;
    cout.fill('-');
    cout << '|' << setw(58);
    cout << '|' << endl;
    cout.fill(' ');
    cout << '|' << setw(36) << "GRRT's Airlines" << setw(22) << '|' << endl;
    cout << '|' << setw(35) << "Activity System" << setw(23) << '|' << endl;
    cout << '|' << setw(31) << "Flight ID: ";
    cout << setiosflags(ios::right) << setw(5) << setfill('0') << flightNumber;
    cout << setiosflags(ios::right) << setfill(' ') << setw(22) << '|' << endl;
    cout.fill('_');
    cout << '|' << setw(58) << '|' << endl;
    cout.fill(' ');
    cout << '|' << setw(32) << "MAIN MENU" << setw(26) << '|' << endl;
    cout << '|' << setw(33) << "1) Helicopter" << setw(25) << '|' << endl;
    cout << '|' << setw(33) << "2) Turbo Prop" << setw(25) << '|' << endl;
    cout << '|' << setw(34) << "3) Midsize Jet" << setw(24) << '|' << endl;
    cout << '|' << setw(32) << "4) Heavy Jet" << setw(26) << '|' << endl;
    cout << '|' << setw(44) << "5) Print transaction log" << setw(14) << '|' << endl;
    cout << '|' << setw(27) << "6) Quit" << setw(31) << '|' << endl;
    cout.fill('_');
    cout << '|' << setw(58) << '|' << endl;
    cout << "Number of hits today is: ";
    cout << setiosflags(ios::right) << setw(5) << setfill('0') << menuCount << endl << endl;
    cout << setfill(' ');
}

void writeFile(fstream &log, int &flightNumber, int menuOption, int &timeMinutes, string &destinationOption, int &timeHours, string flightHaul)
{
    log.open("FlightLog.txt", ios::app);
    if (log.is_open())
    {
        time_t now = time(0);
        char* timeOf = ctime(&now);
        timeOf[25] = '\n'; // truncate the info
        // cout << "Wrote text to file: " << flightNumber << " " << menuOption << " " << timeMinutes << " " << destinationOption << " " << timeHours << "hours and " << timeMinutes << "minutes " << flightHaul << " " << timeOf << endl;     ( This was for testing the data to be written )
        log << flightNumber << " " << menuOption << " " << timeMinutes << " " << destinationOption << " " << timeHours << "hours and " << timeMinutes << "minutes " << flightHaul << " " << timeOf;
        log.close();
    }
    else
    {
        cout << "Error accessing log file\n";
    }
}

void displayLog(fstream &log)
{
    cout << "Printing log file...\n \n";
    cout << "Flight ID, type of flight, minutes, route, flight time, status, time in.\n";
    log.open("FlightLog.txt", ios::in);
    if (log.is_open())
    {
        log.clear();
        log.seekg(0, ios::beg);
        string logText;
        while (!(getline(log, logText).eof()))
        {
            cout << logText << endl;
        }
        log.clear();
        log.seekg(0, ios::end);
        log.close();
    }
    else
    {
        cout << "Error accessing log file\n";
    }
}

void getFlightID(int &flightNumber, fstream &log)
{
    flightNumber = rand() % 99999 + 1;
    bool repeatID = false;
    log.open("FlightLog.txt", ios::in);
    if (log.is_open())
    {
        int logID = 0;
        while (log >> logID)
        {
            log.ignore(numeric_limits<streamsize>::max(), '\n');
            if (flightNumber == logID) // check to make sure there are no duplicate flightID's
            {
                repeatID = true;
            }
        }
    }
    else
    {
        cout << "Error accessing log file\n";
    }
    if (repeatID == true)
    {
        getFlightID(flightNumber, log);
    }
}

void getCategory(string &flightHaul, int &timeHours)
{
    if (timeHours < 3)
    {
        flightHaul = "Short-haul flight";
    }
    else if (timeHours <= 6)
    {
        flightHaul = "Medium-haul flight";
    }
    else if (timeHours <= 12)
    {
        flightHaul = "Long-haul flight";
    }
    else
    {
        flightHaul = "Ultra long-haul flight";
    }
}

void calculateTime(int &timeMinutes, int &timeHours, int &flightOption, string &destinationOption, short int &windSpeed)
{
    float time;
    switch (flightOption)
    {
        case 1: // case for helicopter
            if (destinationOption == "CLE-ORD")
            {
                time = CLE_ORD / (HELISPEED + windSpeed);
            }
            else if (destinationOption == "ORD-JFK")
            {
                time = ORD_JFK / (HELISPEED + windSpeed);
            }
            else if (destinationOption == "DEN-JFK")
            {
                time = DEN_JFK / (HELISPEED + windSpeed);
            }
            else if (destinationOption == "JFK-SFO")
            {
                time = JFK_SFO / (HELISPEED + windSpeed);
            }
            else if (destinationOption == "JFK-MIA")
            {
                time = JFK_MIA / (HELISPEED + windSpeed);
            }
            else
            {
                time = DFW_CYYZ / (HELISPEED + windSpeed);
            }
            break;
        case 2: // case for turbo jet
            if (destinationOption == "CLE-ORD")
            {
                time = CLE_ORD / (TURBOSPEED + windSpeed);
            }
            else if (destinationOption == "ORD-JFK")
            {
                time = ORD_JFK / (TURBOSPEED + windSpeed);
            }
            else if (destinationOption == "DEN-JFK")
            {
                time = DEN_JFK / (TURBOSPEED + windSpeed);
            }
            else if (destinationOption == "JFK-SFO")
            {
                time = JFK_SFO / (TURBOSPEED + windSpeed);
            }
            else if (destinationOption == "JFK-MIA")
            {
                time = JFK_MIA / (TURBOSPEED + windSpeed);
            }
            else
            {
                time = DFW_CYYZ / (TURBOSPEED + windSpeed);
            }
            break;
        case 3: // case for midsize jet
            if (destinationOption == "CLE-ORD")
            {
                time = CLE_ORD / (MIDSIZESPEED + windSpeed);
            }
            else if (destinationOption == "ORD-JFK")
            {
                time = ORD_JFK / (MIDSIZESPEED + windSpeed);
            }
            else if (destinationOption == "DEN-JFK")
            {
                time = DEN_JFK / (MIDSIZESPEED + windSpeed);
            }
            else if (destinationOption == "JFK-SFO")
            {
                time = JFK_SFO / (MIDSIZESPEED + windSpeed);
            }
            else if (destinationOption == "JFK-MIA")
            {
                time = JFK_MIA / (MIDSIZESPEED + windSpeed);
            }
            else
            {
                time = DFW_CYYZ / (MIDSIZESPEED + windSpeed);
            }
            break;
        case 4: // case for heavy jet
            if (destinationOption == "CLE-ORD")
            {
                time = CLE_ORD / (HEAVYSPEED + windSpeed);
            }
            else if (destinationOption == "ORD-JFK")
            {
                time = ORD_JFK / (HEAVYSPEED + windSpeed);
            }
            else if (destinationOption == "DEN-JFK")
            {
                time = DEN_JFK / (HEAVYSPEED + windSpeed);
            }
            else if (destinationOption == "JFK-SFO")
            {
                time = JFK_SFO / (HEAVYSPEED + windSpeed);
            }
            else if (destinationOption == "JFK-MIA")
            {
                time = JFK_MIA / (HEAVYSPEED + windSpeed);
            }
            else
            {
                time = DFW_CYYZ / (HEAVYSPEED + windSpeed);
            }
            break;
    }
    timeHours = time; // get the integer part of time
    float timeMinutesFloat = time - timeHours; // get the fractional part of the time
    timeMinutes = timeMinutesFloat * 60; // convert fractional part of hours to minutes
}

void getWindSpeed(short int &windSpeed)
{
    cout << "Enter the wind speed (negative for tail wind): ";
    cin >> windSpeed;
    while (cin.fail() || windSpeed < -100 || windSpeed > 100)
    {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Invalid option, Speed must be -100 to 100.\n";
        cin >> windSpeed;
    }
}

void getDestination(string &destinationOption)
{
    cout << "Enter your start and ending destination (such as CLE-ORD): ";
    cin >> destinationOption;
    destinationOption = toUpper(destinationOption); // this eliminates the need to have all uppercase inputs. Just for ease of use.
    while (cin.fail() || (destinationOption != "CLE-ORD" && destinationOption != "DEN-JFK" && destinationOption != "JFK-SFO" && destinationOption != "JFK-MIA" && destinationOption != "DFW-CYYZ"))
    {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Invalid option, try again.\n";
        cin >> destinationOption;
        destinationOption = toUpper(destinationOption);
    }
}

int getMenuOption()
{
    cout << "Enter the type of flight that you wish to use, or quit to exit: ";
    int flightOption;
    cin >> flightOption;
    while (cin.fail() || flightOption > 6 || flightOption < 1)
    {
        cout << "Invalid option, try again.\n";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> flightOption;
    }
    return flightOption;
}
