// Fibonacci Series Code

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

using namespace std;

int recursiveFunction(int a, int b, int max)
{
    int c; // this is the value that we are calculating
    max = max - 1; // keeping a count of the recursions
    c = a + b; // actual function that we are solving for
    cout<<"C =  "<<c<<endl;
    // Recursive Test
    if (max > 1) // recurse because max is greater than 1
    {
        c = recursiveFunction(b, c, max);
    }
    return c;
}

int main ()
{
    int max;
    int a = 1;
    int b = 1;
    int c;
    cout<<"Enter max: "<<endl;
    cin>>max;
    c = recursiveFunction(a, b, max);
    cout<<"Series: "<<c<<endl;

    return 0;
}
