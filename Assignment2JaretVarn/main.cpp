#include <iostream>

using namespace std;

int main()
{
    const int LH312 = 42;
    const int CAS41 = 44;
    const int KH133 = 38;

    while(true)
    {
        cout << "Select a class room # from the options. \n";
        cout << "1) Leigh Hall 213 \n";
        cout << "2) College of Arts and Sciences 41 \n";
        cout << "3) Kolbe Hall 133 \n";

        int userOption = 0;

        cin >> userOption;

        if(userOption != 1 && userOption != 2 && userOption != 3)
        {
            cout << "Invalid option, try again \n";
        }
        else
        {
            if(userOption == 1)
            {
                cout << "You have selected Leigh Hall 213. \n";
                cout << "Enter the number of people to attend the class. \n";
                int peopleAttending = 0;
                cin >> peopleAttending;
                if(peopleAttending <= LH312)
                {
                    int extraSpaces = LH312 - peopleAttending;
                    cout << "It is legal to hold the class. \n";
                    cout << extraSpaces << " additional people may attend. \n \n";
                }
                else
                {
                    cout << "This class cannot be held as planned. \n \n";
                }
            }
            else if(userOption == 2)
            {
                cout << "You have selected College of Arts and Sciences 41. \n";
                cout << "Enter the number of people to attend the class. \n";
                int peopleAttending = 0;
                cin >> peopleAttending;
                if(peopleAttending <= CAS41)
                {
                    int extraSpaces = CAS41 - peopleAttending;
                    cout << "It is legal to hold the class. \n";
                    cout << extraSpaces << " additional people may attend. \n \n";
                }
                else
                {
                    cout << "This class cannot be held as planned. \n \n";
                }
            }
            else if(userOption == 3)
            {
                cout << "You have selected Kolbe Hall 133. \n";
                cout << "Enter the number of people to attend the class. \n";
                int peopleAttending = 0;
                cin >> peopleAttending;
                if(peopleAttending <= KH133)
                {
                    int extraSpaces =  KH133 - peopleAttending;
                    cout << "It is legal to hold the class. \n";
                    cout << extraSpaces << " additional people may attend. \n \n";
                }
                else
                {
                    cout << "This class cannot be held as planned. \n \n";
                }
            }
        }
    }
    return 0;
}
