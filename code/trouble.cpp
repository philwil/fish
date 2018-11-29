#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <string>

using namespace std;

COORD coord = { 0,0 }; // this is a global variable
									/*center of axis is set to the top left corner of the screen*/
void gotoxy(int x, int y)
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class Piece {

private:
    int xpos; // the current x-position of the piece (changes)
    int ypos; // the current y-position of the piece (changes)
    // int distanceTravelled; // the distance traveled
    char color; // color of the piece (does NOT change)
    string piecenumber; // string display "Y1, Y2, etc" (does NOT change)
    int originalx; // the original x-position of the piece (does NOT change)
    int originaly; // the original y-position of the piece (does NOT change)
    int goalx; // the x-position of the goal entrance for particular color (does NOT change)
    int goaly; // the y-position of the goal entrance for particular color (does NOT change)
public:
    Piece (int x, int y, int c, int p /*d*/);

    int getx();
    int gety();
    char getc();
    string getpname();
    // int getd();
    void setx();
    void sety();
    // void setd();
    void piecedisplay();
            };





    class Board {
private:
    Piece players[8];
    // void loadChanceCards(); // TBD
    int numberAtGoal [4] = {0,0,0,0};
    // Red, Blue, Green, Yellow
public:
    Board(); // sets up board with the pieces
    int roll(); // rolls a die and returns a=numbers between 1-3
    // void moveNormal();     // movement is counter-clockwise with the algorithm based on defined algorithm
    // void moveGoal();       // moves towards goal. Movement is only horizontal or vertical and half
    // void chance ();        // TBD
    // bool atLocation;       // Is there a piece at location that you are moving to
    void execute();
    // runs the game start, during, and end of game
    // -->>>>> THIS IS THE ONLY PART OUT OF TH 4 COMMENTS THAT NEEDS TO BE DONE: start - number of players, colors players selected, creates the board
    // during - LOOPED handles the switching of players and displays board
    // end - a player makes it to the goal with both pieces
    void display(); // displays the board and the pieces on the board
                };

    void Piece::piecedisplay()
	{
        system("CLS");
        gotoxy(1, 1);
        cout << "__________________________________________________________________" << endl;
        cout << "|     |     |     |     |     |     |     |     |     |     |     |" << endl;
        cout << "|     |     |     |     |     |     |     |     |     |     |     | 0" << endl;
        cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;

        for (int i = 0;i < 10;i++) {
		cout << "|     |     |     |     |     |     |     |     |     |     |     |" << endl;
		cout << "|     |     |     |     |     |     |     |     |     |     |     | " << i + 1 << endl;
		cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;
                                   }
	cout << "   0     1     2     3     4     5     6     7     8     9     10";
	gotoxy(3,3);
	cout<<"R1";
	int x;
	cin>>x;
	}
	//gotoxy(10, 20);
    	//cout << "Hello World!\n";
	//gotoxy(40, 0);
	//cout << "test me    column - 40,  row 0\n";
	//int xinput;
	//int yinput;
	//string stringinput;
	//cout << "Input x -coord \n";
	//cin >> xinput;
                                                // system("CLS");
	//cout << "input y-coord \n";
	//gotoxy(0, 0);
	//cin >> yinput;
	//cout << "input phrase \n";
	//cin>>stringinput;
	//gotoxy(xinput, yinput);
	//cout << stringinput;
	//cin >> stringinput;
                                                // return 0;
	// }


// Note: (in general) Moving one block is not moving one pixel
// This is the int main() that will be used in th final version of this program:
/*
int main ()
{
    board b;
    b.execute();
    return 0;
}
*/
// };
struct point
{
int x;
int y;
string name;

};
struct point p[8];
void piecedisplay(struct point p[], int n)
	{
	    int i;

        system("CLS");
        gotoxy(1, 1);
        cout << "__________________________________________________________________" << endl;
        cout << "|     |     |     |     |     |     |     |     |     |     |     |" << endl;
        cout << "|     |     |     |     |     |     |     |     |     |     |     | 0" << endl;
        cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;

        for (int i = 0;i < 10;i++) {
		cout << "|     |     |     |     |     |     |     |     |     |     |     |" << endl;
		cout << "|     |     |     |     |     |     |     |     |     |     |     | " << i + 1 << endl;
		cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;
                                   }
	cout << "   0     1     2     3     4     5     6     7     8     9     10";
	for (i = 0; i<n; i++)
    {
        gotoxy(3 + (p[i].x*6), 3 + (p[i].y*3));
        cout<<p[i].name;
    }
	int x;
	cin>>x;
	}

int main ()
{
    // Piece p(1, 2, 3, 2);
    string ans2;
    int c = 0;
    do
    {
    p[0].x = 0;
    p[0].y = 0;
    p[0].name = "P1";
    p[1].x = 1;
    p[1].y = 0;
    p[1].name = "P2";
    p[2].x = 0;
    p[2].y = 1;
    p[2].name = "P3";
    piecedisplay(p,3);
    cin>>ans2;
    c += 1;
    p[0].x += 1;
    }
while (c < 5);

    return 0;
    // For Dice Roll Part

    int dice1;
    int dice2;
    char size;
    string ans;
     //while (ans == "p")
    {
    do  {
        dice1 = (rand() % 3) + 1 ;
        dice2 = (rand() % 3) + 1;
        cout<<"D1: "<<dice1<<"D2: "<<dice2<<endl;
        if (dice1 == dice2)
        {
            cout<<"Same"<<endl;
        }
        cout<<"Sum: "<<(dice1 + dice2)<<endl;

            cout<<endl;
            cin>>ans;
        }
        while (ans == "p");
    }
    return 0;
    }
