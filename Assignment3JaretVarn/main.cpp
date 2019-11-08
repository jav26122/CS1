/*
  Pgm: ASSGN3-A  Name: Jaret Varn
  Date: 9/19/18
  Purpose: This assignment is to make sure that you know how to write a program that does basic input, output, flow of control and/or calculations.
*/


#include <iostream>
#include <string>

using namespace std;

int main()
{
    char YN = 'Y';
    while (YN == 'y' || YN == 'Y')
    {

        int x = 0;
        int y = 0;
        cout << "Enter the # of rows \n";
        cin >> x;
        if (!cin.fail() && x <= 75)
        {
            cout << "Enter the # of columns \n";
            cin >> y;
            if (!cin.fail() && x <= 75)
            {
                for (int i = 0; i < x; ++i)
                {
                    for (int j = 0; j < y; ++j)
                    {
                        cout << "X";
                    }
                    cout << endl;
                }
                cout << "Continue?  (Y/N) \n";
                cin >> YN;
            }
            else
            {
                std::cin.clear();
                std::cin.ignore();
                cout << "Invalid input \n \n";
            }
        }
        else
        {
            std::cin.clear();
            std::cin.ignore();
            cout << "Invalid input \n \n";
        }
    }
    return 0;
}
