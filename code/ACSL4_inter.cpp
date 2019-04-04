// Rohan Sachdev
// 4 -2 - 2019
// Period 4(A) - Advanced CS
// ACSL Contest #4 - Intermediate Division: Prefix Evaluation
// Teacher: Mr. Potter
// Enloe High School

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

/*
Sample Input (Intermediate)
* + 4 5 - 3 1
@ - 8 9 7 6
+ > 8 * 2 7 9 6
- @ - 3 5 7 * 2 4 > * 4 6 * 3 7 * 9 3
* 7 - + 4 6 > 0 - 2 3 1
*/
int maxOf (int a, int b, int c)
{
        if (a > b)
        {
            if (a > c)
            {
                return a;
            }
            else
            {
                return c;
            }
        }
        else if (b > c)
        {
            return b;
        }
        else
        {
            return c;
        }
        return a;
}

int evaluate  (string &aStr)
{
    int value;
    while (aStr[0] == ' ')
    {
        aStr = aStr.substr(1, string::npos);
    }
    string bStr = aStr.substr(0, 2);
    // cout<<"bst: ["<<bStr<<"]"<<endl;
    if (aStr.length() > 1)
    {
        aStr = aStr.substr(2, string::npos);
    }
    if (bStr == "* ")
    {
        int a = evaluate(aStr);
        int b = evaluate(aStr);
        return a * b;
    }
    else if (bStr == "+ ")
    {
        // cout<<"Evaluating +"<<endl;
        int a = evaluate(aStr);
        int b = evaluate(aStr);
        // cout<<"a = "<<a<<" b = "<<b<<endl;
        return a + b;
    }
    else if (bStr == "- ")
    {
        int a = evaluate(aStr);
        int b = evaluate(aStr);
        return a - b;
    }
        else if (bStr == "@ ")
    {
        int a = evaluate(aStr);
        int b = evaluate(aStr);
        int c = evaluate(aStr);
        if (a > 0)
        {
            return b;
        }
        else
        {
            return c;
        }
    }
        else if (bStr == "> ")
    {
        int a = evaluate(aStr);
        int b = evaluate(aStr);
        int c = evaluate(aStr);
        return maxOf(a, b, c);
    }
    else // it must be a number
    {
        value = atoi(bStr.c_str());
    }
    return value;
}

int main ()
{
    string value;
    ifstream myfile;
    myfile.open("ACSL4.txt", ifstream::in); // //ACSL3SampleInputIntermediate.txt
    if (myfile.is_open())
    {
    do
    {
    getline (myfile, value);
    // cout<<"String read =  "<<value<<endl; // This could be anything (result, or whatever you are trying to find)
    //done = 1;
    int a = evaluate(value);
    cout<<"Result: "<<a<<endl;
    }
    while (!myfile.eof());
    myfile.close();
    }

    else
    {
        cout<<"Invalid Input: ERROR"<<endl;
    }
}
