// Advanced CS - Mr. Potter
// Enloe High School
// Grade: 10

#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

void sortStrings (string str1, string str2, string & result)
{
     result = "";
     for (int j = 0; j < str1.length(); j++)
     {
         // cout<<"J = "<<j<<" Str1 : "<<str1[j]<<endl; // Passing by value
         size_t pos = str2.find(str1[j]);
         // cout<<"pos "<<pos<<endl;
         if (pos <= str2.length())
         {
            result += str1[j];
            str2 = str2.substr(pos + 1);
            // cout<<"Result: "<<result<<endl;
            // cout<<"str2 "<<str2<<endl;
         }

     }
}
int main ()
{
    string str1, str2, str, result;
    ifstream infile;
    infile.open("acsl2.txt", ifstream::in);
    for (int i = 0; i < 5; i++)
    {
     getline (infile, str);
     cout<<"str "<<str<<endl;
     size_t pos = str.find(' ');
     cout<<"pos: "<<pos<<endl;
     str1 = str.substr(0, pos);
     str2 = str.substr(pos + 1);
     cout<<"String 1: "<<str1<<endl;
     cout<<"String 2: "<<str2<<endl;
     sortStrings (str1, str2, result);
     cout<<"Result: "<<result<<endl;
     unique(result.begin(), result.end());
     sort(result.begin(), result.end());
     result.erase( unique( result.begin(), result.end() ), result.end() );
     cout<<"Sorted result: "<<result<<endl;
     sortStrings(str2, str1, result);
     cout<<"Result: "<<result<<endl;
     unique(result.begin(), result.end());
     sort(result.begin(), result.end());
     result.erase( unique( result.begin(), result.end() ), result.end() );
     cout<<"Sorted result: "<<result<<endl;
    }
    infile.close();

    return 0;
}
