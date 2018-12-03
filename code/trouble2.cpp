// Program: Trouble
// Trouble is a board game in which players complete to be the first to send 2 pieces around the board
// Period 4(A)
// Enloe High School
// Class of 2021
// (SET UP IS CRUCIAL)
// The set-up is crucial
// Note: There should be 1 particular constructor and no default constructors
// Constructors should not display anything
// You can have a default constructor for piece if you wan to
// It is better to display board and then display piece
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <string>
#include <ctime> // TO have a different sequence of random numbers each time
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
    Piece (int x, int y, char c, int p /*d*/);
    Piece(){};
    int getx(){return xpos;}
    int gety(){return ypos;}
    char getc();
    string getpname();
    // int getd();
    void setx();
    void sety();
    // void setd();
    void piecedisplay(int newX, int newY);
    void piecemove(int move);
            };

    class Board {
private:
    Piece players[8];
    // void loadChanceCards(); // TBD
    int numberAtGoal [4] = {0,0,0,0};
    // Red, Blue, Green, Yellow
public:
    void boarddisplay();
    Board(){};// sets up board with the pieces
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

    Piece::Piece(int x, int y, char c, int p)
    {
        xpos = x;
        ypos = y;
        color = c;
        p = p;
    }
    void Board::boarddisplay()
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
	//gotoxy(3,3);
	//cout<<"R1";
	//int x;
	//cin>>x;
	}

	void Piece::piecedisplay(int oldX, int oldY)
	{
	    //gotoxy (oldX, oldY);
	    //cout<<"       ";
	    gotoxy (xpos, ypos);
	    cout<<color;
	    //xpos = newX;
	    //ypos = newY;
	}

	void Piece::piecemove(int move)
	{
	    gotoxy (3 + (xpos * 6), 3 + (ypos * 3));
	    cout<<"  ";
	    if (xpos == 1)
        {
            ypos = ypos - move;
            if (ypos < 1)
            {
                 move = -(ypos) + 1;
                 ypos = 1;
                 xpos = xpos + move;
            }
        }
        else if (xpos == 10)
        {
            ypos = ypos + move;
            if (ypos > 10)
            {
                move = ypos - 10;
                ypos = 10;
                xpos = xpos - move;
            }
        }
        else if (ypos == 1)
        {
            xpos = xpos + move;
            if (xpos > 10)
            {
                move = xpos - 10;
                xpos = 10;
                ypos = ypos + move;
            }
        }
        else if (ypos == 10)
        {
            xpos = xpos - move;
            if (xpos < 1)
            {
                move = 1 - xpos;
                xpos = 1;
                ypos = ypos - move;
            }
        }

	    gotoxy (3 + (xpos * 6), 3 + (ypos * 3));
	    cout<<color;
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
    // For Dice Roll Part
    Piece p(1, 3, 'r', 2);
    Board b;
    int dice1;
    int dice2;
    char size;
    string ans;
    srand(time(NULL));
     //while (ans == "p")
    ans = "a";
    b.boarddisplay();
    do  {
        cin>>ans;
        dice1 = (rand() % 3) + 1 ;
        dice2 = (rand() % 3) + 1;
        gotoxy(70, 5);
        cout<<"D1: "<<dice1<<" D2: "<<dice2;
        if (dice1 == dice2)
        {
            gotoxy(70, 10);
            cout<<"Same";
        }
            gotoxy (70, 15);
            cout<<"Sum: "<<(dice1 + dice2);
            gotoxy (70, 20);
            cout<<"Answer = "<<ans;
            gotoxy (70, 25);
            cout<<"Before --> Piece X: "<<p.getx()<<" Piece Y: "<<p.gety();
            p.piecemove(dice1 + dice2);
            gotoxy (70, 30);
            cout<<"After  --> Piece X: "<<p.getx()<<" Piece Y: "<<p.gety();

        }
        while (ans == "p");
        gotoxy(70, 45);
        return 0;
    }
