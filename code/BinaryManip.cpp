// Binary Manipulation
// 3-31-2019

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <math.h>

using namespace std;

int minimumPower (int num)
{
    // Looking for maximum power of 2 that a number can use, then next
    // Keep incrementing maxP until 2^(maxP) is greater than the number
    int minP = 0; // minimum power is equal to 0
    while (pow(2, minP) <= num)
    {
        minP += 1; // incrementing the power by 1
        cout<<"minP: "<<minP<<" num: "<<num<<" pow(2, minP): "<<pow(2, minP)<<endl;
    }
    return minP - 1;
}

int getNumArray (int numArray[], int number)
{
    for (int i = 0; i < 16; i++)
    {
        numArray[i] = 0;
    }
    while (number > 0)
    {
    int value = minimumPower(number);
    numArray [value] = 1;
    number -= pow(2, value);
    cout<<"Value: "<<value<<" num1: "<<number<<endl;
    }
    for (int i = 0; i < 16; i++)
    {
        cout<<"numArray[i]: "<<numArray[i]<<" i: "<<i<<endl;
    }
}

int checkArray (int array[]) // returns 1 if array is all 0 (returns 1 if every element is 0)
{
    int result = 1;
    for (int i = 0; i < 16; i++)
    {
        if (array [i] > 0)
        {
            return 0;
        }
    }
    return result;
}

void leftShiftArray (int array[])
{
    for (int i = 15; i > 0; i--)
    {
        array[i] = array[i-1];
    }
    array[0] = 0;
}

void rightShiftArray (int array[])
{
    for (int i = 0; i < 16; i++)
    {
        array[i] = array[i+1];
    }
    array[15] = 0;
}

void printArray (int array[])
{
    for (int i = 0; i < 16; i++)
    {
        cout<<"Array[i]: "<<array[i]<<" i: "<<i<<endl;
    }
}

int clearArray (int array[])
{
    for (int i = 0; i < 16; i++)
    {
        array[i] = 0; // to clear the array
    }
}

void addArray (int resultArray[], int array1[], int array2[])
{
    int carry = 0;
    for (int i = 0; i < 16; i++)
    {
        resultArray[i] = array1[i] + array2[i] + carry;
        if (resultArray[i] > 1)
        {
            resultArray -= 2;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
    }
}

int main ()
{
    int num1;
    int num2;
    int numArray1 [16]; // array since it has 16 possible values or powers of 2 to use, limits the power to 64K or 2^16
    int numArray2 [16];
    int resultArray [16]; // numArray1 * numArray2
    cout<<"Enter Number 1: "<<endl;
    cin>>num1;
    cout<<"Enter Number 2: "<<endl;
    cin>>num2;
    getNumArray(numArray1, num1);
    getNumArray(numArray2, num2);
    rightShiftArray(numArray2);
    int count = 0;
    printArray(numArray2);
    int val = (checkArray(numArray2));
    clearArray(resultArray);
    cout<<"val: "<<val<<endl;
    resultArray[0] = 1;
    printArray(resultArray);
    leftShiftArray(resultArray); // printing array after test
    printArray(resultArray);
    val = (checkArray(resultArray));
    cout<<"val: "<<val<<endl;
    cout<<"After test"<<endl;
    while (checkArray(resultArray) == 0)
    {
        leftShiftArray(resultArray);
        count++;
    }
    cout<<"right shift count: "<<count<<endl;
    clearArray(resultArray);
    addArray(resultArray, numArray2, numArray1);
    printArray(resultArray);
    while (checkArray(numArray2) == 0)
    {
        rightShiftArray(numArray2);
        printArray(numArray2);
        count++;
    }
    cout<<"count: "<<count<<endl;
    return 0;
}
