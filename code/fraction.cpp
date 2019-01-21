// Fraction Simplification Midterm (worth 40%)
// 1-17-2019

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <cmath>

using namespace std;

    int canSimplify (int num, int denom, int value)
    {
    int temp = num;
    temp = temp / value;
    temp = temp * value;
    int tempD = denom;
    tempD = tempD / value;
    tempD = tempD * value;
    if ((temp == num) && (tempD > 0) && (tempD == denom))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    }
    // Repeat simplify for as many times as we can for this value
    int doSimplify (int & num, int & denom, int value)
    {
    int canS;
    do
    {
    canS = canSimplify (num, denom, value);
    if (canS == 1)
    {
    num = num / value;
    denom = denom / value;
    }
    }
    while (canS == 1);
    }

int main ()
{
    int num1;
    int num2;
    int denom1;
    int denom2;
    int numAnswer;
    int denomAnswer;
    int canS;
    cout<<"Fraction 1 Numerator: ";
    cin>>num1;
    cout<<"Fraction 2 Numerator: ";
    cin>>num2;
    cout<<"Fraction 1 Denominator: ";
    cin>>denom1;
    cout<<"Fraction 2 Denominator: ";
    cin>>denom2;
    numAnswer = (num1 + num2);
    denomAnswer = (denom1);
    int values [] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 49, 57, 61}; // This is the factor that the numerator gets divided by
    int numVals = 18;
    int i;
    for (i = 0; (i < numVals) && (numAnswer >= values[i]); i++)
    {
    doSimplify(numAnswer, denomAnswer, values[i]);
    }
    cout<<"i = "<<i<<" Answer = "<<numAnswer<<" / "<<denomAnswer<<endl;
}
    /*
    doSimplify(numAnswer, denomAnswer, 2);
    doSimplify(numAnswer, denomAnswer, 3);
    doSimplify(numAnswer, denomAnswer, 5);
    doSimplify(numAnswer, denomAnswer, 7);
    doSimplify(numAnswer, denomAnswer, 11);
    doSimplify(numAnswer, denomAnswer, 13);
    doSimplify(numAnswer, denomAnswer, 17);
    doSimplify(numAnswer, denomAnswer, 19);
    */

    /*
    do
    {
    canS = canSimplify (numAnswer, denomAnswer, 2);
    if (canS == 1)
    {
    numAnswer = numAnswer / 2;
    denomAnswer = denomAnswer / 2;
    }
    }
    while (canS == 1);

    do
    {
    canS = canSimplify (numAnswer, denomAnswer, 3);
    if (canS == 1)
    {
    numAnswer = numAnswer / 3;
    denomAnswer = denomAnswer / 3;
    }
    }

    while (canS == 1);
    */
