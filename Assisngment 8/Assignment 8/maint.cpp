/*
  Pgm: ASSGN8  Name: Jaret Varn
  Date: 11/26/18
  Purpose: The purpose of this assignment is to help gauge your skills in writing small programs that involve vectors and c-strings.

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


void readFile(ifstream &file, vector<string> &address, vector<string> &name, vector<int> &zip);
void writeFile(ofstream &outfile, vector<string> &address, vector<string> &name);


int main()
{
    ifstream file;
    ofstream outfile;
    vector<string> address, name;
    vector<int> zip;
    readFile(file, address, name, zip);
    for (int i=0; i < address.size(); ++i)
    {
        cout << "Name: " << name[i] << ", Address: " << address[i] << endl;
    }
    cout << "\n\nWithin zip code 90210 - 92014:\n\n";
    for (int i=0; i < address.size(); ++i)
    {
        if ( (zip[i] >= 90210) && (zip[i] <= 92014) )
        {
            cout << "Name: " << name[i] << ", Address: " << address[i] << endl;
        }
    }

}

void readFile(ifstream &file, vector<string> &address, vector<string> &name, vector<int> &zip)
{
    file.open("ASSGN8-B.xml", ios::in);
    if (file.is_open())
    {
        string line;
        int lineStart, lineEnd;
        while (!(getline(file, line).eof()))
        {
            lineStart = line.find("<name>");
            if (lineStart < string::npos)
            {
                lineStart = line.find(">");
                lineEnd = line.find("</name>");
                string nameTemp = line.substr(lineStart + 1, lineEnd - lineStart - 1);
                name.push_back(nameTemp);
            }
            lineStart = line.find("<street>");
            if (lineStart < string::npos)
            {
                lineStart = line.find(">");
                lineEnd = line.find("</street>");
                string streetTemp = line.substr(lineStart + 1, lineEnd - lineStart - 1);
                address.push_back(streetTemp);
            }
            lineStart = line.find("<zip>");
            if (lineStart < string::npos)
            {
                lineStart = line.find(">");
                lineEnd = line.find("</zip>");
                int zipTemp = stoi( line.substr(lineStart + 1, lineEnd - lineStart - 1) );
                zip.push_back(zipTemp);
            }
        }
    }
}
