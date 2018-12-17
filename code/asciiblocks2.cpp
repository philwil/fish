/ 12-14-2018
// ACSL Contest #1
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
    unsigned long long val; // the sum
    int nvalue; // inputvalue
    unsigned long long total; // total
    ifstream myfile;
    myfile.open("ACSL1SampleInputSenior.txt");
    while (!myfile.eof()) // loop till the file ends
    {
        string nvalue;
        myfile>>nvalue>>nlength;
        while ((nvalue.size() % nlength) != 0) // add extra 0s to the end of the block if necessary until the mod becomes 0, so that there is an integer # of blocks (no remainder)
        {
            nvalue += '0';
        }
        //cout<<"nvalue: "<<nvalue<<endl;    //Shows steps
        //cout<<" nlength: "<<nlength<<endl; //Shows steps
        total = 0;
        int j;
    for (j = 0; j<=(nvalue.size() - nlength); j+=nlength) // instead of incrementing by 1, increment by the block size
    {
            val = 0;
    for (int i = j; i<(nlength + j); i++)
    {
            val = (val * 10) + (nvalue[i] - '0'); // moving up a decimal place, and converting from character to int
            // Subtracting '0' is 0x30 // turns the character '0' to an integer 0
    }
    //cout<<"Val = "<<val<<" J: "<<j<<endl; //Shows steps
    total += val;
    }
cout<<"Value: "<<nvalue<<" Length:"<<nlength<<" Total: "<<total<<endl; // outputs answer
    }
            myfile.close();
}
