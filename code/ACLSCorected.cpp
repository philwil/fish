// Rohan Sachdev
// Period 4A
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

void sortStringsRL (string str1, string str2, string & result)
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

void sortStringsLR (string str1, string str2, string & result)
{
     result = "";
     for (int j = str1.length() ; j >= 0; j--)
     {
         // cout<<"J = "<<j<<" Str1 : "<<str1[j]<<endl; // Passing by value
         size_t pos = str2.find(str1[j]);
         // cout<<"pos "<<pos<<endl;
         if (pos <= str2.length())
         {
            result += str1[j];
            str2 = str2.substr(0, pos);
            // cout<<"Result: "<<result<<endl;
            // cout<<"str2 "<<str2<<endl;
         }

     }
}

void findCommon (string str1, string str2, string str3, string str4, string & result)
{
    str1.erase( unique( str1.begin(), str1.end() ), str1.end());
    result = "";
    for (int i = 0; i < str1.length(); i++)
    {
        char charS = str1[i];
        if ((str2.find(charS) <= str2.length()) && (str3.find(charS) <= str3.length()) && (str4.find(charS) <= str4.length()))
        {
            result += charS;
        }
    }
}

int main ()
{
    string str1, str2, str, result, result1, result2, result3, result4;
    ifstream infile;
    infile.open("acsl2.txt", ifstream::in);
    for (int i = 0; i < 5; i++)
    {
     getline (infile, str);
     // cout<<"str "<<str<<endl;
     size_t pos = str.find(' ');
     // cout<<"pos: "<<pos<<endl;
     str1 = str.substr(0, pos);
     str2 = str.substr(pos + 1);
     // cout<<"String 1: "<<str1<<endl;
     // cout<<"String 2: "<<str2<<endl;
     sortStringsRL (str1, str2, result1);
     sortStringsLR (str1, str2, result2);
cout<<"Result 1: "<<result1<<endl;
       // unique(result1.begin(), result1.end());
       // sort(result.begin(), result.end());
       // result.erase( unique( result.begin(), result.end() ), result.end() );
cout<<"Result 2: "<<result2<<endl;
     // unique(result2.begin(), result2.end());

     // cout<<"Sorted result: "<<result<<endl;
     sortStringsRL (str2, str1, result3);
     sortStringsLR (str2, str1, result4);
// cout<<"Reverse Result: "<<result<<endl;
cout<<"Result 3: "<<result3<<endl;
      // unique(result3.begin(), result3.end());

cout<<"Result 4: "<<result4<<endl;
      // unique(result4.begin(), result4.end());
findCommon (result1, result2, result3, result4, result);
sort(result.begin(), result.end());
if (result.length() == 0)
{
    result = "NONE";
}
     // unique(result.begin(), result.end());
     // sort(result.begin(), result.end());
     // result.erase( unique( result.begin(), result.end() ), result.end() );
cout<<"Final Result: "<<result<<endl;
    }
    infile.close();

    return 0;
}
