
/*
  Pgm: ASSGN5-A  Name: Jaret Varn
  Date: 10/29/18
  Purpose: This assignment is to make sure that you know how to write a program that uses files and file processing.

*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
using std::ifstream;
using std::ofstream;

float readfile(ifstream &, std::string &, int, float &, std::string &, ofstream &); // declaration of function to handle the files

int main()
{
    ifstream input;
    ofstream output;
    string farmName;
    int num;
    string item;
    float price;
    input.open("ASSGN6-A.txt");
    output.open("Output.txt");
    if (input.is_open())
    {
        float result = readfile(input, farmName, num, price, item, output); // if the file opens successfully, the readfile function is called
        cout << endl;
    }
    else
    {
        cout << "file not there" << endl; // error if the file isnt opened
    }
    return 0;
}
float readfile(ifstream &input, string &farmName, int num, float &price, string &item, ofstream &output)
{
    cout << setw(60) << cout.fill('=') << endl;
    cout << '=' << setfill(' ') << setw(40) << "FARMER'S MARKET INVENTORY" << setw(18) << '=' << endl;
    cout << setw(60) << cout.fill('=') << endl;
    cout << setfill(' ');
    while (!(getline(input, farmName, ',').eof())) // iterate through the file until the end of file bit
    {
        input >> num;
        input >> item;
        input >> price;
        float result = num * price;
        output << farmName << " " << num << " " << item << " " << price << " " << result <<endl; // writing the data to the output file
        cout << left << farmName;
        cout << right << setw(20) << num << " " << item << " @ " << price << " each totaling $" << result << setw(20); // displaying the information to cout
    }
}
