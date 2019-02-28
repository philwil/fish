#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <string>
#include <ctime> // To have a different sequence of random numbers each time

using namespace std;

COORD coord = { 0,0 }; // this is a global variable
void gotoxy(int x, int y)
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
/*
void run (int value)
{
    cout<<"Please enter an integer value with the power of 2: "<<value<<endl;

}
*/
void recursiveFunction (int value, int x , int y, int direction)
{
    gotoxy (x, y);
    cout<<"$";
    for (int i = 0; i < value;  i++) // i <= value + 1
    {
   // gotoxy(x, y);
   // cout<<"-";
    if (direction == 0)
    {
        x = x + 1; // right
    }
    else if (direction == 1)
    {
        y = y - 1; // up
    }
    else if (direction == 2)
    {
        x = x - 1; // left
    }
    else if (direction == 3)
    {
        y = y + 1; // down
    }
    gotoxy(x, y);
    cout<<"-";
    }
    if (direction == 0)
    {
        x = x + 1; // right
    }
    else if (direction == 1)
    {
        y = y - 1; // up
    }
    else if (direction == 2)
    {
        x = x - 1; // left
    }
    else if (direction == 3)
    {
        y = y + 1; // down
    }
// This is the recursive test; we stop when the value is less than or equal to 1 because one dash minimum
if (value > 1) // using this because we don't want to overwrite te last dash
{
    // Recurisve test passed
    recursiveFunction (value / 2, x, y, direction); // STRAIGHT THROUGH //  add 1 since already did i = 0 // for recursion
    int newDirection = direction + 1; // because counter-clockwise; goes right, p, left, down
    if (newDirection > 3)
    {
        newDirection = 0;
    }
    recursiveFunction (value / 2, x, y, newDirection); // COUNTER-CLOCKWISE //  add 1 since already did i = 0 // for recursion
    newDirection = direction - 1; // because clockwise; goes right, p, left, down
    if (newDirection < 0)
    {
        newDirection = 3;
    }
    recursiveFunction (value / 2, x, y, newDirection); // CLOCKWISE
    // straight through, counterclockwise, and clockwise for the same values of , y, and value (where $ sign is), but for different directions
}
else
{
    gotoxy (x, y); // display last value; the terminating value
    cout<<"$";
}
}
int main ()
{
    int value = 0;
    int x = 0;
    int y = 0;
    int direction = 0;
    cout<<"Please enter an integer value with the power of 2: "<<endl;
    cin>>value;
    cout<<"Input a starting (x, y) coordinates: "<<endl;
    cin>>x;
    cin>>y;
    recursiveFunction (value, x, y, direction);
    gotoxy (0, 40);
    return 0;
}
