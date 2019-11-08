#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

char *Min(char *c1, char *c2, char *c3)
{
	char *r = c1;
	if (strcmp(c2, c1) < 0)
	{
		r = c2;
	}
	if (strcmp(c3, c2) < 0)
	{
		r = c3;
	}
	return r;
}



int main()
{
    cout << Min("b", "a", "c") << endl;
    return 0;
}
