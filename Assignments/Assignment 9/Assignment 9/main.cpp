
/*
  Pgm: ASSGN9-A  Name: Jaret Varn
  Date: 11/29/18
  Purpose: The purpose of this assignment is to help gauge your skills in writing small programs that involve pointers.
*/


#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>


using namespace std;

char *Reverse(char rstring[]);

int main()
{
    char str1[] = "time";
    char str2[] = "straw";
    char str3[] = "deliver";
    char str4[] = "star";
    char str5[] = "knits";

    cout << "The strings before reversing: " << endl;
    cout << str1 << " " << str2 << " " << str3 << " " << str4 << " " << str5 << " " << endl << endl;
    cout << "After reversing: " << endl;
    cout << Reverse(str1) << " " << Reverse(str2) << " " << Reverse(str3) << " " << Reverse(str4) << " " << Reverse(str5) << endl;
    return 0;
}



char *Reverse(char rstring[])
{
    int len = strlen(rstring);
    char *Front = &rstring[0];
    char *Back = &rstring[len-1];
    for (int i=0; i < len / 2; ++i)
    {
        char FirstChar = Front[0];
        *Front = *Back;
        *Back = FirstChar;
        Back--;
        Front++;
    }
    return rstring;
}
