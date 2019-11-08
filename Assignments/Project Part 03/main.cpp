/*
  Pgm: Project Part 03  Name: Jaret Varn
  Purpose: The purpose of this part of the project is to make sure that you know how to write a program that utilizes arrays and array processing, and pointers.


  NOTE: Since I spent a good amount of time on this project I took the liberty to make a few small improvements to ease the use/testing of this project.
  1: Destination names can be entered as any variation of lower/uppercase and still work.
  2: Destinations can be entered as enumerated numbers and work (see #3)
  3: Option 8 added which lists all possible destinations and numbers corresponding to each one.
  4: Constant arrays for holding aircraft names, destination names, and constant value for number of destinations.

*/


#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <cctype>
#include <limits>


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
    // Number of routes
const int DESTINATIONS = 6;
    // Capacity of airline
const int HELICOPTER_SIZE = 19,
    TURBO_PROP_SIZE = 15,
    MIDSIZE_JET_SIZE = 24,
    HEAVY_JET_SIZE = 33;
    //Aircraft types available
const int NUM_AIRCRAFTS = 4;

// Array holding the aircraft sizes
const int AIRCRAFT_SIZES[NUM_AIRCRAFTS] = { HELICOPTER_SIZE, TURBO_PROP_SIZE, MIDSIZE_JET_SIZE, HEAVY_JET_SIZE };
// Array holding the aircraft names
const std::string AIRCRAFT_NAMES[NUM_AIRCRAFTS] = {"Helicopter", "Turbo Prop", "Midsize Jet", "Heavy Jet"};
// Array holding the destination names
const std::string DESTINATION_NAMES[DESTINATIONS] = {"CLE-ORD", "ORD-JFK", "DEN-JFK", "JFK-SFO", "JFK-MIA", "DFW-CYYZ"};

void menu(int &flightNumber);
// Precondition: flightNumber is declared as an integer.
// Postcondition: The flight menu is displayed with the unique flightNumber ID.
std::string toUpper(std::string input);
// Precondition: The input is a std::string.
// Postcondition: The std::string is returned except converted to all capital letters.
int getMenuOption();
// Precondition: None
// Postcondition: Asks the user for their menu selection and then validates the data and returns it.
void getDestination(std::string &destinationOption);
// Precondition: destinationOption is defined as a std::string.
// Postcondition: Asks the user for their destination option and validates the data and assigns it to the destinationOption variable.
void getFlightID(int &flightNumber, std::fstream &log);
// Precondition: flightNumber is defined as an integer and the log is defined via std::fstream.
// Postcondition: A random number from 1-99999 is generated and then compared to all of the previous flightID's in the log file. If a duplicate flightID is created, then the function recursively calls itself to find a new flightID.
void getWindSpeed(short int &windSpeed);
// Precondition: windSpeed is defined as a short integer.
// Postcondition: Asks the user to enter a wind speed and validates that it is an integer from -100 to 100 and assigns it to the windSpeed variable.
void calculateTime(int &timeMinutes, int &timeHours, int &flightOption, std::string &destinationOption, short int &windSpeed);
// Precondition: All those variables are defined correctly.
// Postcondition: Calculates the time in minutes and hours based on the options decided by the user. The times are then assigned to the proper variables.
void writeFile(std::fstream &log, int &flightNumnber, int menuOption, int &timeMinutes, std::string &destinationOption, int &timeHours, std::string flightHaul);
// Precondition: The variables are defined.
// Postcondition: All of the appropriate data is written to the log file.
void getCategory(std::string &flightHaul, int &timeHours);
// Precondition: defined variables.
// Postcondition: This uses the hours to decide what category the flight is and then assigns that to the flightHaul std::string.
void displayLog(std::fstream &log);
// Precondition: defined std::fstream log.
// Postcondition: This displays all of the log data when requested by the user and proper password is given.
void updateArray(int &flightOption, int *ptrs[NUM_AIRCRAFTS][4], int &flightNumber, short int &windSpeed, std::string &destinationOption, int &destinationEnum);
// Updates the arrays of flight information.

int getDestinationEnum(std::string &destinationOption);
// Converts the string version of destinations to corresponding numbers.

void printAircraftUsage(int *ptrs[NUM_AIRCRAFTS][4]);
// Displays the amount of aircrafts in use and total number of aircrafts.

void sortByFlightNum(int *ptrs[NUM_AIRCRAFTS][4]);
// Sorts the flight info arrays by flight numbers so that they can then be searched using the binary sort searchArray.

void searchArray(int *ptrs[NUM_AIRCRAFTS][4], int searchNumber);
// A binary search that searches the array of flight numbers for the user inputted flight number.

void listDestinations();
// Displays the destination options and their corresponding numbers.

int getFlightNumberSearch();
// Input validation for the user inputted flight number to search for.

int main()
{
    srand(time(0)); // generate the seed for the rand() function

    //array initialization
    int *ptrs[NUM_AIRCRAFTS][4] = {nullptr};
    for (int i=0; i < NUM_AIRCRAFTS; ++i)
    {
        ptrs[i][0] = new int[AIRCRAFT_SIZES[i]]; // Flight numbers
        ptrs[i][1] = new int[AIRCRAFT_SIZES[i]]; // Wind speeds
        ptrs[i][2] = new int[AIRCRAFT_SIZES[i]]; // Destinations
        ptrs[i][3] = new int; // Current number of flights in use
        *ptrs[i][3] = 0;
        for (int j=0; j < AIRCRAFT_SIZES[i]; ++j)
        {
            ptrs[i][0][j] = 0;
            ptrs[i][1][j] = 0;
            ptrs[i][2][j] = 0;
        }
    }
    // this format has a multidimensional array of pointers that goes to the array of flight data.
    // ptrs[FlightType][Flight#, windSpeed, Destination, current#flightsInUse]

    bool quit = false;
    while (!quit) // control for when to end the program.
    {
        int flightNumber = 0;
        int destinationEnum = 0;
        std::string destinationOption = "";
        short int windSpeed = 0;
        int timeMinutes = 0;
        int timeHours = 0;
        std::string flightHaul = "";
        std::fstream log;
        getFlightID(flightNumber, log);
        menu(flightNumber);
        int flightOption = getMenuOption();
        if (flightOption == 9) // user selects quit
        {
            quit = true;
        }
        else if (flightOption == 5)
        {
            std::cout << "Enter password to view log file:\n";
            std::string password = "";
            std::cin >> password;
            if (!std::cin.fail() && password == "Not-telling") // Plain text password ;)
            {
                displayLog(log); // user gets password correct, continue with program and display the log info
            }
            else
            {
                std::cout << "SECURITY BREACH! PROGRAM ENDING..."; // password is wrong, program terminates.
                quit = true;
            }
        }
        else if (flightOption == 6)
        {
            printAircraftUsage(ptrs);
        }
        else if (flightOption == 7)
        {
            searchArray(ptrs, getFlightNumberSearch());
        }
        else if (flightOption == 8)
        {
            listDestinations();
        }
        else
        {
            getDestination(destinationOption);
            destinationEnum = getDestinationEnum(destinationOption);
            getWindSpeed(windSpeed);
            updateArray(flightOption, ptrs, flightNumber, windSpeed, destinationOption, destinationEnum);
            sortByFlightNum(ptrs);
            calculateTime(timeMinutes, timeHours, flightOption, destinationOption, windSpeed);
            std::cout.precision(1);
            std::cout << std::endl << std::fixed << std::showpoint << "Your total flight time from " << destinationOption << " was: " << timeHours << " hours and " << timeMinutes << " minutes.\n"; // display the calculated time of the flight
            getCategory(flightHaul, timeHours);
            std::cout << flightHaul << std::endl; // display the category of the flight
            writeFile(log, flightNumber, flightOption, timeMinutes, destinationOption, timeHours, flightHaul); // write the data to the log file.
        }
        if (!quit)
        {
            std::cout << std::endl << "\nPress any key to continue\n";
            std::cin.get();
            std::cin.get();
        }
    }
}

void listDestinations()
{
    for (int i=0; i < DESTINATIONS; ++i)
    {
        std::cout << i + 1 << ") " << DESTINATION_NAMES[i] << std::endl;
    }
    std::cout << "(Numbers 1-" << DESTINATIONS << " may also be used for routes)\n";
}

int getFlightNumberSearch()
{
    int FlightNumber;
    std::cout << "Enter the flight number you want to search for: ";
    std::cin >> FlightNumber;
    while (std::cin.fail() || FlightNumber < 0 || FlightNumber > 100000)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid option, flight numbers are from 0 - 100000\n";
        std::cin >> FlightNumber;
    }
    return FlightNumber;
}


void searchArray(int *ptrs[NUM_AIRCRAFTS][4], int searchNumber)
{
    bool found2 = false;
    for (int i=0; i < NUM_AIRCRAFTS; ++i) // Nested loop is required for multiple aircrafts.
    {
        for (int j=0; j < AIRCRAFT_SIZES[i]; ++i)
        {
            int first = 0;
            int last = AIRCRAFT_SIZES[i] - 1;
            int middle;
            int position = -1;
            bool found = false;

            while (!found && first <= last)
            {
                middle = (first + last) / 2;
                if (ptrs[i][0][middle] == searchNumber)
                {
                    found = true;
                    position = middle;
                }
                else if (ptrs[i][0][middle] > searchNumber)
                {
                    last = middle - 1;
                }
                else
                {
                    first = middle + 1;
                }
            }

            if (position != -1 && searchNumber != 0) // we found a matching flight number. Need to make sure it isn't 0 because all the arrays are initialized to 0.
            {
                int foundDestination = ptrs[i][2][position];
                //std::cout << foundDestination << std::endl;
                std::cout << "Flight " << std::setw(5) << std::setfill('0') << searchNumber;
                std::cout << std::setfill(' ') << " is taking a " << AIRCRAFT_NAMES[i] << " for the route of " << DESTINATION_NAMES[ foundDestination ] << std::endl;
                found2 = true;
            }
        }
    }
    if (!found2)
    {
        std::cout << "That flight is not active in the system.\n";
    }
}



void sortByFlightNum(int *ptrs[NUM_AIRCRAFTS][4])
{

    for (int i=0; i < NUM_AIRCRAFTS; ++i) // sort each of the aircrafttype arrays
    {
        for (int j=0; j < (AIRCRAFT_SIZES[i] - 1); ++j)
        {
            int startIndex = j;
            int startElement0 = ptrs[i][0][j]; // flight numbers
            int startElement1 = ptrs[i][1][j]; // speeds
            int startElement2 = ptrs[i][2][j]; // destinations
            for (int k=j + 1; k < AIRCRAFT_SIZES[i]; ++k)
            {
                if (ptrs[i][0][k]  < startElement0)
                {
                    startElement0 = ptrs[i][0][k];
                    startElement1 = ptrs[i][1][k];
                    startElement2 = ptrs[i][2][k];
                    startIndex = k;
                }
            }
            // flight numbers, wind speeds, and destinations need to be sorted together to keep them parallel
            ptrs[i][0][startIndex] = ptrs[i][0][j];
            ptrs[i][0][j] = startElement0;

            ptrs[i][1][startIndex] = ptrs[i][1][j];
            ptrs[i][1][j] = startElement1;

            ptrs[i][2][startIndex] = ptrs[i][2][j];
            ptrs[i][2][j] = startElement2;

        }
    }
}


void printAircraftUsage(int *ptrs[NUM_AIRCRAFTS][4])
{
    std::cout << std::endl << AIRCRAFT_NAMES[0] << "s in use/total:      " << *ptrs[0][3] << "  /  " << AIRCRAFT_SIZES[0];
    std::cout << std::endl << AIRCRAFT_NAMES[1] << "s in use/total:      " << *ptrs[1][3] << "  /  " << AIRCRAFT_SIZES[1];
    std::cout << std::endl << AIRCRAFT_NAMES[2] << "s in use/total:     " << *ptrs[2][3] << "  /  " << AIRCRAFT_SIZES[2];
    std::cout << std::endl << AIRCRAFT_NAMES[3] << "s in use/total:       " << *ptrs[3][3] << "  /  " << AIRCRAFT_SIZES[3];
}

void updateArray(int &flightOption, int *ptrs[NUM_AIRCRAFTS][4], int &flightNumber, short int &windSpeed, std::string &destinationOption, int &destinationEnum)
{
    int currentFlights = *ptrs[flightOption - 1][3];
    if (currentFlights >= AIRCRAFT_SIZES[flightOption - 1])
    {
        *ptrs[flightOption - 1][3] = 1;
        std::cout << "Max number of " << AIRCRAFT_NAMES[flightOption - 1] << " restarting array to 0.";
    }
    else
    {
        ++*ptrs[flightOption - 1][3]; // Adds one to the value of the integer holding the number of flights in use corresponding to the flightOption.
    }
    currentFlights = *ptrs[flightOption - 1][3];
    ptrs[flightOption - 1][0][currentFlights] = flightNumber;
    //std::cout << "Set pointer [" << flightOption << "][0] to " << flightNumber << std::endl;
    ptrs[flightOption - 1][1][currentFlights] = windSpeed;
    //std::cout << "Set pointer [" << flightOption << "][1] to " << windSpeed << std::endl;
    ptrs[flightOption - 1][2][currentFlights] = destinationEnum;
    //std::cout << "Set pointer [" << flightOption << "][2] to " << destinationEnum << std::endl;
}

int getDestinationEnum(std::string &destinationOption)
{
    for (int i = 0; i < DESTINATIONS; ++i)
    {
        if (destinationOption == DESTINATION_NAMES[i])
        {
            return i;
        }
    }
    /* Optimized this old chunk to use the destinations array
    if (destinationOption == "CLE-ORD")
    {
        return 0;
    }
    else if (destinationOption == "ORD-JFK")
    {
        return 1;
    }
    else if (destinationOption == "DEN-JFK")
    {
        return 2;
    }
    else if (destinationOption == "JFK-SFO")
    {
        return 3;
    }
    else if (destinationOption == "JFK-MIA")
    {
        return 4;
    }
    else if (destinationOption == "DFW-CYYZ")
    {
        return 5;
    } */
}

std::string toUpper(std::string input)
{
    std::string output = "";
    for (int i=0; i < input.length(); ++i)
    {
        output += toupper(input[i]); // change each individual character of input to uppercase and add it to the output std::string
    }
    return output;
}


void menu(int &flightNumber)
{
    static int menuCount = 0; // counter for amount of times the menu is opened.
    ++menuCount;
    std::cout << std::setw(60) << std::cout.fill('_') << std::endl;
    std::cout.fill('-');
    std::cout << '|' << std::setw(58);
    std::cout << '|' << std::endl;
    std::cout.fill(' ');
    std::cout << '|' << std::setw(36) << "Jaret's Airlines" << std::setw(22) << '|' << std::endl;
    std::cout << '|' << std::setw(35) << "Activity System" << std::setw(23) << '|' << std::endl;
    std::cout << '|' << std::setw(31) << "Flight ID: ";
    std::cout << setiosflags(std::ios::right) << std::setw(5) << std::setfill('0') << flightNumber;
    std::cout << setiosflags(std::ios::right) << std::setfill(' ') << std::setw(22) << '|' << std::endl;
    std::cout.fill('_');
    std::cout << '|' << std::setw(58) << '|' << std::endl;
    std::cout.fill(' ');
    std::cout << '|' << std::setw(32) << "MAIN MENU" << std::setw(26) << '|' << std::endl;
    std::cout << '|' << std::setw(33) << "1) Helicopter" << std::setw(25) << '|' << std::endl;
    std::cout << '|' << std::setw(33) << "2) Turbo Prop" << std::setw(25) << '|' << std::endl;
    std::cout << '|' << std::setw(34) << "3) Midsize Jet" << std::setw(24) << '|' << std::endl;
    std::cout << '|' << std::setw(32) << "4) Heavy Jet" << std::setw(26) << '|' << std::endl;
    std::cout << '|' << std::setw(44) << "5) Print transaction log" << std::setw(14) << '|' << std::endl;
    std::cout << '|' << std::setw(43) << "6) Print aircraft usage" << std::setw(15) << '|' << std::endl;
    std::cout << '|' << std::setw(42) << "7) Search for a flight" << std::setw(16) << '|' << std::endl;
    std::cout << '|' << std::setw(34) << "8) List routes" << std::setw(24) << '|' << std::endl;
    std::cout << '|' << std::setw(27) << "9) Quit" << std::setw(31) << '|' << std::endl;
    std::cout.fill('_');
    std::cout << '|' << std::setw(58) << '|' << std::endl;
    std::cout << "Number of hits today is: ";
    std::cout << setiosflags(std::ios::right) << std::setw(5) << std::setfill('0') << menuCount << std::endl << std::endl;
    std::cout << std::setfill(' ');
}

void writeFile(std::fstream &log, int &flightNumber, int menuOption, int &timeMinutes, std::string &destinationOption, int &timeHours, std::string flightHaul)
{
    log.open("FlightLog.txt", std::ios::app);
    if (log.is_open())
    {
        time_t now = time(0);
        char* timeOf = ctime(&now);
        timeOf[25] = '\n'; // truncate the info
        // std::cout << "Wrote text to file: " << flightNumber << " " << menuOption << " " << timeMinutes << " " << destinationOption << " " << timeHours << "hours and " << timeMinutes << "minutes " << flightHaul << " " << timeOf << std::endl;     ( This was for testing the data to be written )
        log << std::setfill('0') << std::setw(5) << flightNumber;
        log << std::setfill(' ') << " " << menuOption << ":" << AIRCRAFT_NAMES[menuOption - 1] << " " << timeMinutes << " " << destinationOption << " " << timeHours << "hours and " << timeMinutes << "minutes " << flightHaul << " " << timeOf;
        log.close();
    }
    else
    {
        std::cout << "Error accessing log file\n";
        log.close();
    }
}

void displayLog(std::fstream &log)
{
    std::cout << "Printing log file...\n \n";
    std::cout << "Flight ID  |  type of flight |  minutes |  route |  flight time |  status |  time in.\n";
    log.open("FlightLog.txt", std::ios::in);
    if (log.is_open())
    {
        log.clear();
        log.seekg(0, std::ios::beg);
        std::string logText;
        while (!(getline(log, logText).eof()))
        {
            std::cout << logText << std::endl;
        }
        log.clear();
        log.seekg(0, std::ios::end);
        log.close();
    }
    else
    {
        std::cout << "Error accessing log file\n";
        log.close();
    }
}

void getFlightID(int &flightNumber, std::fstream &log)
{
    flightNumber = rand() % 99999 + 1;
    bool repeatID = false;
    log.open("FlightLog.txt", std::ios::in);
    if (log.is_open())
    {
        int logID = 0;
        while (log >> logID)
        {
            log.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (flightNumber == logID) // check to make sure there are no duplicate flightID's
            {
                repeatID = true;
                std::cout << "Duplicate flight ID generated. Finding a new flight ID...\n";
            }
        }
    }
    else
    {
        std::cout << "Error accessing log file or first time running. Log will be created after first flight.\n";
    }
    if (repeatID == true)
    {
        getFlightID(flightNumber, log); // recursively get a new flightID if the flightID has already been used.
    }
    log.close();
}

void getCategory(std::string &flightHaul, int &timeHours)
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

void calculateTime(int &timeMinutes, int &timeHours, int &flightOption, std::string &destinationOption, short int &windSpeed)
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
    std::cout << "Enter the wind speed (negative for tail wind): ";
    std::cin >> windSpeed;
    while (std::cin.fail() || windSpeed < -100 || windSpeed > 100)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid option, Speed must be -100 to 100.\n";
        std::cin >> windSpeed;
    }
}


void getDestination(std::string &destinationOption)
{
    std::cout << "Enter your start and ending destination (such as CLE-ORD): ";
    std::cin >> destinationOption;
    destinationOption = toUpper(destinationOption); // this eliminates the need to have all uppercase inputs. Just for ease of use.
    while (std::cin.fail() || (destinationOption != "CLE-ORD" && destinationOption != "ORD-JFK" && destinationOption != "DEN-JFK" && destinationOption != "JFK-SFO" && destinationOption != "JFK-MIA" && destinationOption != "DFW-CYYZ") )
    {
        bool enumeratedDestination = false;                    // this little part also allows destinations to be entered as numbers from 1-6
        bool isNumber = true;
        for (int i=0; i < destinationOption.length(); ++i) // Need to check if the destinationOption string has any non-digit characters, otherwise stoi will have problems.
        {
            if (!std::isdigit(destinationOption[i]))
            {
                isNumber = false;
            }
        }
        if (isNumber)
        {
            int destinationNumber = std::stoi(destinationOption); // Converts the destinationOption string to an integer to compare against the enumerated destinations.
            if (destinationNumber > 0 && (destinationNumber < DESTINATIONS + 1) )
            {
                for (int i=1; i < DESTINATIONS + 1; ++i)
                {
                    if (destinationNumber == i)
                    {
                        destinationOption = DESTINATION_NAMES[i - 1];
                        enumeratedDestination = true;
                    }
                }
            }
        }
        if (!enumeratedDestination) // User inputted something that isn't a valid destination string and also isn't an enumerated destination.
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid option, try again.\n";
            std::cin >> destinationOption;
            destinationOption = toUpper(destinationOption);
        }
    }
}

int getMenuOption()
{
    std::cout << "Enter the type of flight that you wish to use, or quit to exit: ";
    int flightOption;
    std::cin >> flightOption;
    while (std::cin.fail() || flightOption > 9 || flightOption < 1)
    {
        std::cout << "Invalid option, try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> flightOption;
    }
    return flightOption;
}
