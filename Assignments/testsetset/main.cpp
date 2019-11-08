#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
    const int NUM_AIRCRAFTS = 4;
    int *test[NUM_AIRCRAFTS][3] = {nullptr};
    for (int i=0; i < NUM_AIRCRAFTS; ++i)
    {
        test[i][1] = new int[2];
        test[i][2] = new int[4];
        test[i][3] = new int[6];
    }

    test[1][1][50] = 11111111;
    test[1][2][4] = 44444444;
    cout << test[1][1][0] << endl << test[1][1][50] << endl << test[1][2][4];

    // test[AIRCRAFTTYPE][FLIGHT#/SPEED/DEST][#OFAIRCRAFT]

}
