// Rohan
// Quadratic Equations Code Again 

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h> // for "sqrt" function
#include <stdlib.h> // for "abs" function
#include <stdio.h>
#include <fstream>

using namespace std;
// Passing in answers a, b, and c into rootsDescription
// string a = rootsDescription (answer);
string rootsDescription(int a, int b, int c, int D)
{
    string roots;
    double answer1 = ((-b) + (sqrt(D)) / (2 * a));
    double answer2 = ((-b) - (sqrt(D)) / (2 * a));
    cout<<"Answer 1: "<<answer1<<endl;
    cout<<"Answer 2: "<<answer2<<endl;
    roots.append("(-");
    roots.append(to_string(b));
    roots.append("+-sqrt(");
    roots.append(to_string(D));
    roots.append(")/ (2*");
    roots.append(to_string(a));
    roots.append(")");
    cout<<"Roots: "<<roots<<endl;
    return roots;
}
int discriminant(int a, int b, int c)
{
    int D;
    D = (b*b)-(4 * a * c);
    return D;
}

string numRoots(int D)
{
    string roots;
    if (D == 0)
    {
        roots = "This equation has 1 real root";
    }
    if (D > 0)
    {
        roots = "This equation has 2 real roots";
    }
    if (D < 0)
    {
        roots = "This equation has 2 imaginary roots";
    }
    return roots;
}

void runRoots(string equation)
{
    int a;
    int b;
    int c;
    cout<<"String equation: "<<equation<<endl;
    a = stoi (equation.substr(0, 1));
    b = stoi (equation.substr(3, 2));
    c = stoi (equation.substr(6, 2));
    int D = discriminant (a, b, c);
    cout<<"Discriminant: "<<D<<endl;
    string roots = numRoots (D);
    cout<<"Roots Description: "<<roots<<endl;
    string roots2 = rootsDescription (a, b, c, D);
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
    cout<<"c: "<<c<<endl;
    return;
}

int main ()
{ // Read in a string and extract a, b, an c (int) from it
    string aString = "3x2-7x+4";  // = 0
    string bString = "1x2+3x-21"; // < 0
    string cString = "1x2+7x-4";  // > 0
    runRoots (aString);
    runRoots (bString);
    runRoots (cString);
    return 0;
}
