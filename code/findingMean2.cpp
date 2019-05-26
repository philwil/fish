#include <iostream>
#include <iomanip>
/*
Given a list of numbers, find the mean
Ask for Number of #s
*/
using namespace std;

int findMean (int sum, int num)
{
    int mean;
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
    int num;
    int value;
    int sum = 0;
    cout<<"How many numbers should be on the list?"<<endl;
    cin>>num;
    for (int i = 0; i < num; i++)
    {
        cout<<"Enter a value: "<<endl;
        cin>>value;
        sum = sum + value;
    }
    cout<<endl;
    cout<<"Sum = "<<sum<<endl;
    cout<<"Mean = "<<findMean(sum, num)<<endl;
}
