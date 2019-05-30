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
        // cout<<"minP: "<<minP<<" num: "<<num<<" pow(2, minP): "<<pow(2, minP)<<endl;
    }
    return minP - 1;
}

int getNumArray (int numArray[], int number, int num)
{
    for (int i = 0; i < num; i++)
    {
        numArray[i] = 0;
    }
    while (number > 0)
    {
    int value = minimumPower(number);
    numArray [value] = 1;
    number -= pow(2, value);
    // cout<<"Value: "<<value<<" num1: "<<number<<endl;
    }
    for (int i = 0; i < num; i++)
    {
        // cout<<"numArray[i]: "<<numArray[i]<<" i: "<<i<<endl;
    }
}

int checkArray (int array[], int num) // returns 1 if array is all 0 (returns 1 if every element is 0)
{
    int result = 1;
    for (int i = 0; i < num; i++)
    {
        if (array [i] > 0)
        {
            return 0;
        }
    }
    return result;
}

void leftShiftArray (int array[], int num)
{
    for (int i = num-1; i > 0; i--)
    {
        array[i] = array[i-1];
    }
    array[0] = 0;
}

void rightShiftArray (int array[], int num)
{
    for (int i = 0; i < num-1; i++)
    {
        array[i] = array[i+1];
    }
    array[num-1] = 0;
}

void printArray (int array[], int num)
{
    for (int i = 0; i < num; i++)
    {
        cout<<"Array[i]: "<<array[i]<<" i: "<<i<<endl;
    }
}

void printArray2 (int array[], int num)
{
    int firstNumber = 1;
    for (int i = 0; i < num; i++)
    {
        if (array[i] > 0)
        {
            if (firstNumber == 0)
            {
                cout<<" + ";
            }
            else
            {
                firstNumber = 0;
            }
            cout<<"2^"<<i<<" ";
        }
    }
    cout<<endl;
}
int clearArray (int array[], int num)
{
    for (int i = 0; i < num; i++)
    {
        array[i] = 0; // to clear the array
    }
}

void addArray (int resultArray[], int array1[], int array2[], int num)
{
    int carry = 0;
    for (int i = 0; i < num; i++)
    {
        resultArray[i] = array1[i] + array2[i] + carry;
        if (resultArray[i] > 1)
        {
            resultArray[i] -= 2;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
    }
}

void addArray2 (int resultArray[], int array1[], int num)
{
    int carry = 0;
    int aNum = 0;
    for (int i = 0; i < num; i++)
    {
        aNum = resultArray[i];
        resultArray[i] = array1[i] + aNum + carry;
        if (resultArray[i] > 1)
        {
            resultArray[i] -= 2;
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
    int num = 16;
    int done = 0;
    clearArray(resultArray, num);
    while (!done)
    {
    cout<<"Enter Number 1: "<<endl;
    cin>>num1;
    // cout<<"Enter Number 2: "<<endl;
    // cin>>num2;
    getNumArray(numArray1, num1, num);
    cout<<"Num1: "<<num1<<" ";
    printArray2(numArray1, num);
    addArray2(resultArray, numArray1, num);
    // getNumArray(numArray2, num2, num);
    // cout<<"Num2: "<<num2<<" ";
    // printArray2(numArray2, num);
    // addArray(resultArray, numArray1,numArray2, num);
    // cout<<"Num1 + Num2 = "<<num1 + num2<<" "<<endl;
    printArray2(resultArray, num);
    cout<<endl<<endl;
    }
    return 0;
    /*
    rightShiftArray(numArray2, num);
    int count = 0;
    printArray2(numArray2, num);
    int val = (checkArray(numArray2, num));
    clearArray(resultArray, num);
    // cout<<"Value 1: "<<val<<endl;
    resultArray[0] = 1;
    printArray2(resultArray, num);
    leftShiftArray(resultArray, num); // printing array after test
    printArray2(resultArray, num);
    val = (checkArray(resultArray, num));
    // cout<<"Value 2 : "<<val<<endl;
    // cout<<"After test"<<endl;
    while (checkArray(resultArray, num) == 0)
    {
        leftShiftArray(resultArray, num);
        count++;
    }
    // cout<<"right shift count: "<<count<<endl;
    clearArray(resultArray, num);
    addArray(resultArray, numArray2, numArray1, num);
    printArray2(resultArray, num);
    while (checkArray(numArray2, num) == 0)
    {
        rightShiftArray(numArray2, num);
        printArray2(numArray2, num);
        count++;
    }
    // cout<<"count: "<<count<<endl;
    */
}
