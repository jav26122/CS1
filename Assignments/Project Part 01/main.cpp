/*
  Pgm: Project Part 01  Name: Jaret Varn
  Purpose: The purpose of this part of the project is to make sure that you know how to write a program that declares and uses variable,
  does basic input and output, does calculations, output formatting, uses decision control structures, does iteration, data validation, and menu processing.


*/


#include <iostream>
#include <iomanip>


using namespace std;

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

void menu(int flightNumber);

int main()
{
    // speed constants  (MPH)


    bool quit = false;
    while (!quit)
    {
        /* control menu
        cout << setw(60) << cout.fill('_') << endl;
        cout.fill('-');
        cout << '|' << setw(58);
        cout << '|' << endl;
        cout.fill(' ');
        cout << '|' << setw(36) << "Jaret's Airlines" << setw(22) << '|' << endl;
        cout << '|' << setw(35) << "Activity System" << setw(23) << '|' << endl;
        cout.fill('_');
        cout << '|' << setw(58) << '|' << endl;
        cout.fill(' ');
        cout << '|' << setw(32) << "MAIN MENU" << setw(26) << '|' << endl;
        cout << '|' << setw(33) << "1) Helicopter" << setw(25) << '|' << endl;
        cout << '|' << setw(33) << "2) Turbo Prop" << setw(25) << '|' << endl;
        cout << '|' << setw(34) << "3) Midsize Jet" << setw(24) << '|' << endl;
        cout << '|' << setw(32) << "4) Heavy Jet" << setw(26) << '|' << endl;
        cout << '|' << setw(27) << "5) Quit" << setw(31) << '|' << endl;
        cout.fill('_');
        cout << '|' << setw(58) << '|' << endl;
        // user inputs and validation
        cout << "Enter the type of flight that you wish to use, or quit to exit: "; */

        menu(123);

        int flightOption = 0;
        cin >> flightOption;
        while (cin.fail() || flightOption > 5 || flightOption < 1)
        {
            cout << "Invalid option, try again.\n";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> flightOption;
        }
        if (flightOption == 5) // user selects quit
        {
            quit = true;
        }
        else
        {

            cout << "Enter your start and ending destination (such as CLE-ORD): ";
            string destinationOption;
            cin >> destinationOption;
            while (cin.fail() || (destinationOption != "CLE-ORD" && destinationOption != "DEN-JFK" && destinationOption != "JFK-SFO" && destinationOption != "JFK-MIA" && destinationOption != "DFW-CYYZ"))
            {
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "Invalid option, try again.\n";
                    cin >> destinationOption;
            }
            cout << "Enter the wind speed (negative for tail wind): ";
            short int windSpeed = 0;
            cin >> windSpeed;
            while (cin.fail() || windSpeed < -100 || windSpeed > 100)
            {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Invalid option, Speed must be -100 to 100.\n";
                cin >> windSpeed;
            }
            float time = 0.00;
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
            int timeHours = time; // get the integer part of time
            float timeMinutes = time - timeHours; // get the fractional part of the time
            int timeMinutesInt = timeMinutes * 60; // convert fractional part of hours to minutes
            cout.precision(1);
            cout << endl << fixed << showpoint << "Your total flight time from " << destinationOption << " was: " << timeHours << " hours and " << timeMinutesInt << " minutes.\n";
            if (time < 3)
            {
                cout << "Short-haul flight.\n";
            }
            else if (time <= 6)
            {
                cout << "Medium-haul flight.\n";
            }
            else if (time <= 12)
            {
                cout << "Long-haul flight.\n";
            }
            else
            {
                cout << "Ultra long-haul flight.\n";
            }
            cout << "\nPress any key to continue\n";
            cin.get();
            cin.get(); // I honestly have no clue why I need 2 cin.get()'s, but one of them doesn't work.
        }
    }
}


void menu(int flightNumber)
{
    static int menuCount = 0;
    ++menuCount;
    cout << setw(60) << cout.fill('_') << endl;
    cout.fill('-');
    cout << '|' << setw(58);
    cout << '|' << endl;
        cout.fill(' ');
    cout << '|' << setw(36) << "Jaret's Airlines" << setw(22) << '|' << endl;
    cout << '|' << setw(35) << "Activity System" << setw(23) << '|' << endl;
    cout << '|' << setw(32) << "Flight ID: " << flightNumber << setw(23) << '|' << endl;
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
    cout << "Number of hits today is: " << menuCount << endl << endl;
    //cout << "Enter the type of flight that you wish to use, or quit to exit: ";

}

int getMenuOption()
{

}
