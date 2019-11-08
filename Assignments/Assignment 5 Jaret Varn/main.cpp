/*
  Pgm: ASSGN5-A  Name: Jaret Varn
  Date: 10/12/18
  Purpose: This assignment is to make sure that you know how to write a program that contains functions and that does basic input, output, flow of control and/or calculations.

*/


#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

const float AARONACCURACY = 1.0/3;
const float BOBACCURACY = 0.5;
const float CHARLIEACCURACY = 1.0;
const int NUMDUELS = 1000;
void shoot(bool &targetAlive, double accuracy);
int startDuel();

int main()
{
    srand(time(0));
    int aaronWins = 0;
    int bobWins = 0;
    int charlieWins = 0;
    for (int i=1; i < NUMDUELS; ++i)
    {
        int winner = startDuel();
        if (winner == 1)
        {
            ++aaronWins;
        }
        else if (winner == 2)
        {
            ++bobWins;
        }
        else
        {
            ++charlieWins;
        }
    }
    cout << "Using the strategy of shooting at the best shooter alive: \n";
    cout << "Aaron's win %: " << static_cast<float>(aaronWins) / NUMDUELS << endl;
    cout << "Bob's win %: " << static_cast<float>(bobWins) / NUMDUELS << endl;
    cout << "Charlie's win %: " << static_cast<float>(charlieWins) / NUMDUELS << endl;
    return 0;
}


void shoot(bool &targetAlive, double accuracy)
{
    int chance = rand() % 100;
    float chanceFraction = chance / 100.0;
    if (chanceFraction < accuracy)
    {
        targetAlive = false;
    }
}
int startDuel()
{
    bool aaronAlive = true;
    bool bobAlive = true;
    bool charlieAlive = true;
    int currentTarget = 0;
    while ((aaronAlive && bobAlive) || (bobAlive && charlieAlive) || (charlieAlive && aaronAlive))
    {
        if (aaronAlive && bobAlive && charlieAlive) // if all 3 players are still alive
        {
            shoot(charlieAlive, AARONACCURACY); // aaron shoots at charlie
            if (charlieAlive)
            {
                shoot(charlieAlive, BOBACCURACY); // bob shoots at charlie
            }
            else
            {
                shoot(aaronAlive, BOBACCURACY); // if charlie isn't alive, bob shoots at aaron
                if (!aaronAlive)
                {
                    return 2; // if bob hits aaron, bob wins
                    break;
                }
            }
            if (charlieAlive)
            {
                if (bobAlive)
                {
                    shoot(bobAlive, CHARLIEACCURACY); // charlie shoots bob
                }
                else
                {
                    shoot(aaronAlive, CHARLIEACCURACY); // if bob isn't alive, charlie shoots aaron
                }
            }
        }
        else if (aaronAlive && bobAlive)
        {
            shoot(bobAlive, AARONACCURACY); // aaron shoots bob
            if (bobAlive)
            {
                shoot(aaronAlive, BOBACCURACY); // if bob is still alive, he shoots aaron, otherwise aaron wins.
                if (!aaronAlive)
                {
                    return 2; // if bob hits aaron, bob wins
                    break;
                }
            }
            else
            {
                return 1;
                break;
            }
        }
        else if (bobAlive && charlieAlive)
        {
            shoot(charlieAlive, BOBACCURACY); // bob shoots charlie
            if (charlieAlive)
            {
                shoot(bobAlive, CHARLIEACCURACY); // if charlie is alive, charlie shoots bob and charlie wins
                if (!bobAlive) // sort of redundant since charlie never misses.
                {
                    return 3;
                    break;
                }
            }
            else
            {
                return 2; // if bob hits charlie, bob wins
                break;
            }
        }
        else if (aaronAlive && charlieAlive)
        {
            shoot(charlieAlive, AARONACCURACY); // aaron shoots charlie
            if (charlieAlive)
            {
                shoot(aaronAlive, CHARLIEACCURACY); // if charlie is still alive, charlie wins. otherwise aaron wins
                if (!aaronAlive) // again, charlie never misses, but this is for clarity
                {
                    return 3;
                    break;
                }
            }
            else
            {
                return 1;
                break;
            }
        }
    }
}
