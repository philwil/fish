#include <iostream>
#include <iomanip>
#include <math.h>
#include <string.h>
#include<bits/stdc++.h>
/*
Given a list of numbers, find the mean
Don't Ask for Number of #s
*/
using namespace std;

double findSD (double value[], int num)
{
    double sum = 0.0;
    double SD = 0.0;
    if (num == 0)
    {
        return 0.0;
    }
    for (int i = 0; i < num; i++)
    {
        sum = sum + value[i];
    }
    double mean = sum / num;
    cout<<"num: "<<num<<" sum "<<sum<<" mean "<<mean<<endl;
    for (int i = 0; i < num; i++)
    {
        SD = SD + ((value[i] - mean)*(value[i] - mean));
    }
    SD = (sqrt(SD)) / num;
    return SD;
}

double findMean (double sum, int num)
{
    double mean;
    if (num == 0)
    {
        cout<<"Invalid input"<<endl;
        return 0;
    }
    mean = sum / num;
    return mean;
}

int main ()
{
    int num = 0;
    double value[256];
    double sum = 0;
    double mean;
    double SD;
    do
    {
    cout<<"Enter a value: "<<endl;
    cin>>value[num];
    if (value[num] > 0)
    {
        sum = sum + value[num];
        num += 1;
    }
    cout<<endl;
    }
    while (value[num] > 0);
    cout<<"Sum = "<<sum<<endl;
    mean = findMean(sum, num);
    cout<<"Mean = "<<(double)mean<<endl;
    SD = findSD(value, num);
    cout<<"Standard Deviation: "<<SD<<endl;
}

