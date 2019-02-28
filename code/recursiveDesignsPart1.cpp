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
void func (int value, int x , int y, int direction)
{
    gotoxy(x, y);
    cout<<"$";
    for (int i = 0; i < value;  i++) //i <= value + 1
    {
    //gotoxy()
    cout<<"-";
    }
if (value > 1)
func (value / 2, x + value + 1, y, direction); //  add 1 since already did i = 0
else
    cout<<"$";
}
// */

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
    func (value, x, y, direction);
    return 0;
}
