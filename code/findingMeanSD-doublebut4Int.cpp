// Find mean of any amount of numbers
// Ask for how many numbers (counter)
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int findMean(int num, int array[]) // calculate mean given numbers
{
    // cout<<"Enter a number of #s"<<endl;
    // cin>>num;
    int sum = 0;
    for (int i = 0; i < num; i++)
    {
        // cout<<"Enter a value: "<<endl;
        // cin>>array[i];
        sum += array[i];
    }
    // cout<<"Sum: "<<sum<<endl;
    int mean = sum / num;
    cout<<"Mean: "<<mean<<endl;
    // return sum;
    // cout<<"Line 22"<<endl;
    return mean;
}

double findSD (int num, int value[]) // find standard deviation, inputs an array of values and a number o elements in the array
{
    double sum = 0.0;
    double SD = 0.0;
    if (num == 0) // if no numbers on the list
    {
        return 0.0; // return 0.0 since returns double
    }
    for (int i = 0; i < num; i++) // Ex: 5 nums (0-4)
    {
        sum = sum + (double) value[i];
    }
    double mean = sum / num;
    // cout<<"num: "<<num<<" sum: "<<sum<<" mean: "<<mean<<endl;
    for (int i = 0; i < num; i++)
    {
        SD = SD + (((double) value[i] - mean)*((double) value[i] - mean));
    }
    SD = (sqrt(SD)) / num;
    cout<<"Standard Deviation: "<<SD<<endl;
    return SD;
}

int findMax(int num, int array[])
{
    int num1 = 0;
    int max = array[0];
    for (int i = 0; i < num; i++)
    {
        num1 = array[i];
        if (num1 > max)
        max = num1;
    }
    cout<<"Max: "<<max<<endl;
    return max;
}

int findMin(int num, int array[])
{
    int min = array[0];
    for (int i = 0; i < num; i++)
    {
        if (array[i] < min)
        min = array[i];
    }
    cout<<"Min: "<<min<<endl<<endl;
    return min;
}

int findSum(int num, int array[]) // calculate mean given numbers
{
    // cout<<"Enter a number of #s"<<endl;
    // cin>>num;

    int sum = 0;
    for (int i = 0; i < num; i++)
    {
        // cout<<"Enter a value: "<<endl;
        // cin>>array[i];
        sum += array[i];
    }
    cout<<"Sum: "<<sum<<endl;
    // mean = sum / num;
    // cout<<"Mean: "<<mean<<endl;
    return sum;
    // return mean;
}
int fillArray(int array[]) // puts numbers in the array
// put in some numbers and return size of the array
{
    int num;
    cout<<"Enter a number of #s"<<endl;
    cin>>num;
    for (int i = 0; i < num; i++)
    {
        cout<<"Enter a value: "<<endl;
        cin>>array[i];
    }
    return num;
}

int runTest ()
{
    int array1[256]; // creates the array

    // int array2[256];
    int num; // number of #s in array
    // while (1)
    {
        num = fillArray(array1); // set num to array
        findMean(num, array1); // finding mean
        // findMean(num, array2);
        findSD(num, array1);
        findSum(num, array1);
        findMax(num, array1); // finding max
        // findMax(num, array2);
        findMin(num, array1);
    }
    // return 0;
}

int main ()
{
    while (1)
    {
        runTest();
    }
    return 0;
}
