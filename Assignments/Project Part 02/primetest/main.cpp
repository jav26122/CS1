#include <iostream>
#include <math.h>
#include <time.h>


int main()
{
    int start = 0;
    int numprimes = 0;
    int e = 10000000;
    int lastprime;
    time_t starttime = time(0);
    for (int i=1; i <= e; ++i)
    {
        bool p = false;
        for (int j=2; j <= sqrt(i) + 1; ++j)
        {
            if (i % j == 0)
            {
                p = true;
                break;
            }
        }
        if (!p)
        {
            lastprime = i;
            ++numprimes;
        }
    }
    double duration = difftime(time(0), start);
    std::cout << "Found " << numprimes << " primes between " << start << " and " << e << " in " << difftime(time(0), starttime) << " seconds.\n";
    std::cout << lastprime;
}
