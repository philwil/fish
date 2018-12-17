/ ACSL Contest #1
// Intermediate Division - Digit Assembly
// Enloe High School
// Advanced CS - Mr. Potter
// Period 4A
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main ()
{
    int nlength; // inputlength
    unsigned long long val; // the sum //int was not working with 11 digits, so researched and came up with unsigned long long
    int nvalue; // inputvalue
    unsigned long long total; // total
    ifstream myfile;
    myfile.open("ACSL1SampleInput.txt");
    while (!myfile.eof()) // loop till the file ends
    {
        string nvalue;
        myfile>>nvalue>>nlength;
        //cout<<"nvalue: "<<nvalue<<endl;    //Shows steps
        //cout<<" nlength: "<<nlength<<endl; //Shows steps
        total = 0;
        int j;
        for (j = 0; j<=(nvalue.size() - nlength); j++)
        {
            val = 0;
            for (int i = j; i<(nlength + j); i++)
            {
                val = (val * 10) + (nvalue[i] - '0'); // moving up a decimal place, and converting from character to int
                // i is the character we are looking at, and j is the start of this block of characters
                // Subtracting '0' is 0x30 // turns the character '0' to an integer 0
            }
            //cout<<"Val = "<<val<<" J: "<<j<<endl; //Shows steps
            total += val;
        }
        cout<<"Value: "<<nvalue<<" Length:"<<nlength<<" Total: "<<total<<endl; // outputs answer
    }
        myfile.close();
}
