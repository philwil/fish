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

string sortStringsRL (string str1, string str2, string &result)
{
     result = "";
     for (int j = str1.length() ; j >= 0; j--)
       //     for (int j = 0; j < str1.length(); j++)
     {
         // cout<<"J = "<<j<<" Str1 : "<<str1[j]<<endl; // Passing by value
         size_t pos = str2.find_last_of(str1[j]);
         // cout<<"pos "<<pos<<endl;
         if (pos <= str2.length())
         {
            result += str1[j];
            str2 = str2.substr(0, pos);
            // cout<<"Result: "<<result<<endl;
            // cout<<"str2 "<<str2<<endl;
         }

     }
     return str2;
}

string sortStringsLR (string str1, string str2, string & result)
{
     result = "";
     //     for (int j = str1.length() ; j >= 0; j--)
     for (int j = 0; j < str1.length(); j++)
     {
         // cout<<"J = "<<j<<" Str1 : "<<str1[j]<<endl; // Passing by value
         size_t pos = str2.find(str1[j]);
         // cout<<"pos "<<pos<<endl;
         if (pos <= str2.length())
         {
            result += str1[j];
            str2 = str2.substr(pos+1);
            // cout<<"Result: "<<result<<endl;
            // cout<<"str2 "<<str2<<endl;
         }

     }
     return str2;
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
    string strt1 = "5";
    string strt2 = "123456789";
    string rt1 = "";
    string rt2 = "";
    string res1 = "";
    string res2 = "";

    strt1 = "54";
    strt2 = "123456789";
    res1 = sortStringsRL (strt1, strt2, rt1);
    // RTL 4 is found leaves 123 then 5 is not found  
    strt1 = "54";
    strt2 = "123456789";
    res2 = sortStringsLR (strt1, strt2, rt2);
    // LTR 5 is found leaves 6789 then 4 is not found

    cout<<"1 result RL "<<rt1<< " res1 " << res1<< " rt1 " << rt1 << endl;
    cout<<"1 result LR "<<rt2<<" res2 " << res2 << " rt2 " << rt2 << endl;

    strt1 = "45";
    strt2 = "123456789";
    res1 = sortStringsRL (strt1, strt2, rt1);
    // RTL 5 is found leaves 1234 then 4 is found leave 123  
    strt1 = "45";
    strt2 = "123456789";
    res2 = sortStringsLR (strt1, strt2, rt2);
    // LTR 4 is found leaves 56789 then 5 is found leaves 6789

    cout<<"2 result RL "<<rt1<< " res1 " << res1<< " rt1 " << rt1 << endl;
    cout<<"2 result LR "<<rt2<<" res2 " << res2 << " rt2 " << rt2 << endl;

    //return 0;
    
    infile.open("test2.txt", ifstream::in);
    for (int i = 0; i < 5; i++)
    {
     getline (infile, str);
     // cout<<"str "<<str<<endl;
     size_t pos = str.find(' ');
     // cout<<"pos: "<<pos<<endl;
     str1 = str.substr(0, pos);
     str2 = str.substr(pos + 1);
     cout<<"String 1: "<<str1<<endl;
     cout<<"String 2: "<<str2<<endl;
     sortStringsRL (str1, str2, result1);
     sortStringsLR (str1, str2, result2);
cout<<"Result 1 RL: "<<result1<<endl;
       // unique(result1.begin(), result1.end());
       // sort(result.begin(), result.end());
       // result.erase( unique( result.begin(), result.end() ), result.end() );
cout<<"Result 2 LR: "<<result2<<endl;
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
     result.erase( unique( result.begin(), result.end() ), result.end() );
cout<<"Final Result: "<<result<<endl;
    }
    infile.close();

    return 0;
}
