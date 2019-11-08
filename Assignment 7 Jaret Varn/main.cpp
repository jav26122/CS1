
/*
  Pgm: ASSGN7-A  Name: Jaret Varn
  Date: 11/12/18
  Purpose: The purpose of this assignment is to make sure that you know how to write a program that uses sorting and arrays.

*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;




void processFile(ifstream &file, int (&items)[21], double (&priceTotal)[21], int &itemsTotal);
//Pre-condition: Properly defined variables and input file exists.
//Post-condition: Reads the input file and adds up the count and cost of each item.
void displayData(int (&items)[21], double (&priceTotal)[21], int &itemsTotal, string (&itemNames)[21]);
//Pre-condition: Properly calculated data and defined variables.
//Post-condition: Prints to console out the list of information from the file.

int main()
{
    string itemNames[21] = {"tomatoes", "cassavas", "coconuts", "taros", "artichokes", "crosns", "cucumbers", "carrots", "parsnips", "beets", "onions", "rhubarbs", "radishes", "pickles", "walnuts", "peanuts", "apples", "figs", "yams", "potatoes", "turnips"};
    int items[21] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int itemsTotal = 0;
    double priceTotal[21] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    ifstream file;
    processFile(file, items, priceTotal, itemsTotal);
    displayData(items, priceTotal, itemsTotal, itemNames);


    return 0;
}

void displayData(int (&items)[21], double (&priceTotal)[21], int &itemsTotal, string (&itemNames)[21])
{
    cout << "==============================================\n";
    cout << "=" << setw(35) << "FARMER'S MARKET INVENTORY" << setw(11) << "=\n";
    cout << "==============================================\n";
    for (int i=0; i < 20; ++i)
    {
        cout << fixed << setprecision(2) << itemNames[i] << ": " << setw(15) << items[i] << " items totaling $" << priceTotal[i] << setw(10) << endl;
    }
    cout << "\nThere were " << itemsTotal << " items contributed to this week's event.\n";
}

void processFile(ifstream &file, int (&items)[21], double (&priceTotal)[21], int &itemsTotal)
{
    file.open("ASSGN6-B.txt", ios::in);
    if (file.is_open())
    {
        string farmName, itemName;

        int itemCount = 0;
        double itemCost, costTotal = 0;
        while (!(getline(file, farmName,',').eof()))
        {
            file >> itemCount;
            file >> itemName;
            file >> itemCost;
            file >> costTotal;
            itemsTotal = itemsTotal + itemCount;
            int index;
            if (itemName == "tomatoes")
            {
                index = 0;
                items[index] += itemCount;
                priceTotal[index] += costTotal;
            }
            else if (itemName == "cassavas")
            {
                 index = 1;
                items[index] += itemCount;
                priceTotal[index] = priceTotal[index] + costTotal;
            }
            else if (itemName == "coconuts")
            {
                 index = 2;
                items[index] += itemCount;
                priceTotal[index] = priceTotal[index] + costTotal;
            }
            else if (itemName == "taros")
            {
                 index = 3;
                items[index] += itemCount;
                priceTotal[index] = priceTotal[index] + costTotal;
            }
            else if (itemName == "artichokes")
            {
                 index = 4;
                items[index] += itemCount;
                priceTotal[index] = priceTotal[index] + costTotal;
            }
            else if (itemName == "crosns")
            {
                 index = 5;
                items[index] += itemCount;
                priceTotal[index] = priceTotal[index] + costTotal;
            }
            else if (itemName == "cucumbers")
            {
                 index = 6;
                items[index] += itemCount;
                priceTotal[index] = priceTotal[index] + costTotal;
            }
            else if (itemName == "carrots")
            {
                 index = 7;
                items[index] += itemCount;
                priceTotal[index] = priceTotal[index] + costTotal;
            }
            else if (itemName == "parsnips")
            {
                 index = 8;
                items[index] += itemCount;
                priceTotal[index] = priceTotal[index] + costTotal;
            }
            else if (itemName == "beets")
            {
                 index = 9;
                items[index] += itemCount;
                priceTotal[index] = priceTotal[index] + costTotal;
            }
            else if (itemName == "onions")
            {
                 index = 10;
                items[index] += itemCount;
                priceTotal[index] = priceTotal[index] + costTotal;
            }
            else if (itemName == "rhubarbs")
            {
                 index = 11;
                items[index] += itemCount;
                priceTotal[index] = priceTotal[index] + costTotal;
            }
            else if (itemName == "radishes")
            {
                 index = 12;
                items[index] += itemCount;
                priceTotal[index] = priceTotal[index] + costTotal;
            }
            else if (itemName == "pickles")
            {
                 index = 13;
                items[index] += itemCount;
                priceTotal[index] = priceTotal[index] + costTotal;
            }
            else if (itemName == "walnuts")
            {
                 index = 14;
                items[index] += itemCount;
                priceTotal[index] = priceTotal[index] + costTotal;
            }
            else if (itemName == "peanuts")
            {
                 index = 15;
                items[index] += itemCount;
                priceTotal[index] = priceTotal[index] + costTotal;
            }
            else if (itemName == "apples")
            {
                 index = 16;
                items[index] += itemCount;
                priceTotal[index] = priceTotal[index] + costTotal;
            }
            else if (itemName == "figs")
            {
                 index = 17;
                items[index] += itemCount;
                priceTotal[index] = priceTotal[index] + costTotal;
            }
            else if (itemName == "yams")
            {
                 index = 18;
                items[index] += itemCount;
                priceTotal[index] = priceTotal[index] + costTotal;
            }
            else if (itemName == "potatoes")
            {
                 index = 19;
                items[index] += itemCount;
                priceTotal[index] = priceTotal[index] + costTotal;
            }
            else if (itemName == "turnips")
            {
                 index = 20;
                items[index] += itemCount;
                priceTotal[index] = priceTotal[index] + costTotal;
            }
        }
    }
    else
    {
        cout << "Error opening file.\n";
    }
}
