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

void sortLines (string strA, string strB, string & result)
{
    size_t pos, pos2;
    string str, str1, str2, str3;

     result = "";
     str = strA;
     do
     {
     pos = str.find(' ');
     cout<<"pos: "<<pos<<endl;
     str1 = str.substr(0, pos);
     str2 = str.substr(pos + 1);
     cout<<"String 1: "<<str1<<endl;
     cout<<"String 2: "<<str2<<endl;
     pos2 = strB.find(str1);
     if (pos2 <= strB.length())
     {
     str3 = strB.substr(0, pos2);
     str3 += strB.substr(pos2 + str1.length());
     strB = str3;
     result = result + str1;
     result = result + " ";
     cout<<"Second string result "<<result<<" Str b: "<<strB<<" : "<<endl;
     }
     // cout<<"String 1: "<<str1<<endl;
     // cout<<"String 2: "<<str2<<endl;
     str = str2;
     }
     while (pos < strA.length());
     result = result.substr(0, result.length() - 1);
     // }
     // while (pos < str.length());
     // cout<<"Second string result "<<result<<endl;
}
int main ()
{
    string  str, strA, strB, strC, result, result1, result2;
    ifstream infile;
    size_t pos;  // size_t: The size of a string character
    size_t pos2; // size_t: The size of a string character
    infile.open("acsl2senior.txt", ifstream::in);
    for (int i = 0; i < 5; i++)
    {
     getline (infile, strA);
     getline (infile, strB);
     getline (infile, strC);
     cout<<"strA "<<strA<<" strB "<<strB<<endl;
     sortLines(strA, strB, result);
     sortLines (strB, strA, result1);
     sortStrings (result, result1, result2);
     cout<<"Result 2: "<<result2<<endl;

     /*
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
     */
    }
    cout<<"Sorted result: "<<result<<endl;
    infile.close();

    return 0;
}
