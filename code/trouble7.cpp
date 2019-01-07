/ Program: Trouble
// Trouble is a board game in which players compete to be the first to send 2 pieces around the board
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

// IMPORTANT NOTES FOR THURSDAY: (What Mr Potter said)
// In execute B1 at (2,2) hard-coded not inputted into the runner.
// All other pieces should be at home
// Run program, who's turn, pieces at right spot, dice roll
// At first, pieces are at home
// 7 pieces at home, and 1 at (2,2)

// (x, y, __, __)
// xcoor = x1;
// ycoor = y1;
// origx = x1;
// origy = y1;
COORD coord = { 0,0 }; // this is a global variable
									/*center of axis is set to the top left corner of the screen*/
int diceroll1 [16];
int diceroll2 [16];
int rolled = 0;
int maxRoll = 0;
int totalMax = 24;
int setUpRoll (int num, int n1, int n2)
{
if (num > maxRoll)
{
    maxRoll = num + 1;
}
diceroll1[num] = n1;
diceroll2[num] = n2;
return 0;
}
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
    string color;
    //char color; // color of the piece (does NOT change) (I changed to string )
    string piecenumber; // string display "Y1, Y2, etc" (does NOT change)
    int originalx; // the original x-position of the piece (does NOT change)
    int originaly; // the original y-position of the piece (does NOT change)
    int goalx; // the x-position of the goal entrance for particular color (does NOT change)
    int goaly; // the y-position of the goal entrance for particular color (does NOT change)
    int isHome;
    int totalMoves;
    int atGoal;
public:
    Piece (int x, int y, char c, int p /*d*/);
    Piece(){};
    int getx(){return xpos;}
    int gety(){return ypos;}
    string getc(){return color;}; // I changed this to string
    string getpname(){return piecenumber;};
    // int getd();
    void setx(int x){xpos = x;};
    void sety(int y){ypos = y;};
    // void setd();
    void piecedisplay(int newX, int newY);
    void piecemove(int d1, int d2, int diceX);
    int gethome(void){return isHome;};
    int start();
    int setAtGoal() {atGoal = 1;};
    int isAtHome();
    void setup(int x, int y, string c,string h);
            };

class Board {

private:
    Piece players[8];
    // void loadChanceCards(); // TBD
    int numberAtGoal [4] = {0,0,0,0};
    // Red, Blue, Green, Yellow
public:
    void boarddisplay(int dice1, int dice2, int p);
    Board();//{};// sets up board with the pieces
    // Note: I took {} away
    int roll(int &dice1, int &dice2); // rolls a die and returns a=numbers between 1-3
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

    Board::Board()
    {
         setUpRoll (0,1,2); // Roll 0 (1st roll)
         setUpRoll (1,3,3); // Roll 1 (2nd roll)
         srand(time(NULL));

         players[0].setup(1, 4, "Red", "R1");
         players[4].setup(1, 3, "Red", "R2");
         players[1].setup(2, 2, "Blue", "B1");
         players[5].setup(7, 1, "Blue", "B2");
         players[2].setup(9, 6, "Green", "G1");
         players[6].setup(9, 7, "Green", "G2");
         players[3].setup(4, 9, "Yellow", "Y1");
         players[7].setup(3, 9, "Yellow", "Y2");
    }
    Piece::Piece(int x, int y, char c, int p)
    {
        /*
        xpos = 0;
        originalx = 0;
        ypos = 0;
        originaly = 0;
        color = ' ';
        pieecenumber = 0;
        goalx = 5;
        goaly = 5;
        */
        xpos = x;
        ypos = y;
        color = c;
        p = p;
    }

    int Piece::start()
    {
        int diceX = 0;

        if (xpos == 1)
        {
            xpos = 2;
            diceX = 1; //diceX = 1 means that the home move counts
        }
        else if (xpos == 9)
        {
            xpos = 8;
            diceX = 1;

        }
        else if (ypos == 1)
        {
            ypos = 2;
            diceX = 1;

        }
        else if (ypos == 9)
        {
            ypos = 8;
            diceX = 1;
        }
        return diceX;
    }

    int Piece::isAtHome(void)
    {
        int diceX = 0;

        if (xpos == 1)
        {
            diceX = 1; //diceX = 1 means that the home move counts
        }
        else if (xpos == 9)
        {
            diceX = 1;
        }
        else if (ypos == 1)
        {
            diceX = 1;
        }
        else if (ypos == 9)
        {
            diceX = 1;
        }
        return diceX;
    }

    int Board::roll(int &dice1, int &dice2)
    {
        // Put dice roll in here and take it out of Board
        // Also put in Board class
        //while (ans == "p")
        dice1 = (rand() % 3) + 1 ;
        dice2 = (rand() % 3) + 1;
        // Return here for random rolls
        // return 0;

        // For fixed dice rolls
        gotoxy (10, 55);
        cout<<"Enter dice 1: ";
        cin>>dice1;
        cout<<"       Enter dice 2: ";
        cin>>dice2;
        return 0;
        dice1 = diceroll1[rolled];
        dice2 = diceroll2[rolled];
        if (rolled < maxRoll)
        rolled = rolled + 1;
        return 0;
    }

    void Board::boarddisplay(int dice1, int dice2, int p)
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
    int xpos = 5;
    int ypos = 5;
    gotoxy (2 + (xpos * 6), 3 + (ypos * 3));
    cout<<"GOAL";
    gotoxy (1, 39);

    cout<<"Move: "<<"Dice 1: "<<dice1<<" Dice 2: "<<dice2<<" Piece Moving: "<<players[p].getpname()<<" Color: "<<players[p].getc()<<" Sum: "<<(dice1 + dice2)<<" Same?: "<<(dice1 == dice2);

	for(int i = 0; i < 8; i++)
    {
            xpos = players[i].getx();
            ypos = players[i].gety();
            // gotoxy(players[i].getx(), players[i].gety());
            gotoxy (3 + (xpos * 6), 3 + (ypos * 3));
            cout<<players[i].getpname();
            gotoxy (1, 40  +i);
            cout<<"After --> Piece  "<< players[i].getpname()<<" X position: "<<xpos<<"   Y position: "<<" "<<ypos; //<<" Home: "<<players[i].gethome();
    }

    gotoxy(1, 50);
    cout<<"Press 'p' to move."<<endl;
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

	void Piece::piecemove(int d1, int d2, int diceX)
	{
	    int move;
	//    if ((d1 != d2) && (isHome == 1)) return;
	    if ((d1 == d2) && (isHome == 1)) // At home and, not on the board
            {
                isHome = 0; // Move onto the board
                // return; // maybe
            }
            if (atGoal == 1)
                return; // No more moves (at goal for that piece)
        move =  (d1 + d2) - diceX; // Counts start as one move
        totalMoves += move;
        if (totalMoves < totalMax)
        {
	    // gotoxy (3 + (xpos * 6), 3 + (ypos * 3));
	    // cout<<"  ";
	    if (xpos == 2) // This mean move y negatively
        {
            ypos = ypos - move;
            if (ypos < 2)
            {
                 move = 2 - ypos;// players[1].setupy(3);
                 ypos = 2;
                 xpos = xpos + move;
            }
        }
        else if (xpos == 8)
        {
            ypos = ypos + move;
            if (ypos > 8)
            {
                move = ypos - 8;
                ypos = 8;
                xpos = xpos - move;
            }
        }
        else if (ypos == 2)
        {
            xpos = xpos + move;
            if (xpos > 8)
            {
                move = xpos - 8;
                xpos = 8;
                ypos = ypos + move;
            }
        }
        else if (ypos == 8)
        {
            xpos = xpos - move;
            if (xpos < 2)
            {
                move = 2 - xpos;
                xpos = 2;
                ypos = ypos - move;
            }
        }
	}
	else // Moving towards goal (center)
    {
        // move = totalMoves - totalMax;
        if (totalMoves > totalMax + 4)
        {
            totalMoves -= 4;
            if (totalMoves == totalMax + 3)
            {
                cout<<"At GOAL"<<endl;
                atGoal = 1;
                xpos = 5;
                ypos = 5;
            }
            else // Are you at goal
            {
        if (xpos == 2) // This mean move y negatively
        {
            ypos = 2 + totalMoves - totalMax;
        }
        else if (xpos == 8)
        {
            ypos = 8 - totalMoves + totalMax;
        }
        else if (ypos == 2)
        {
            xpos = 2 + totalMoves - totalMax;
        }
        else if (ypos == 8)
        {
            xpos = 8 - totalMoves + totalMax;
        }
            }
	}
        // gotoxy (3 + (xpos * 6), 3 + (ypos * 3));
	    // cout<<color;
    }
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
/*
struct point
{
int x;
int y;
string name;
};
*/
// struct point p[8];

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
        //gotoxy(3 + (p[i].x*6), 3 + (p[i].y*3));
        //cout<<p[i].name;
    }
	int x;
	cin>>x;
}

    void Piece::setup(int x, int y, string c,string h)
    { // N
    xpos = x;
    ypos = y;
    isHome = 1;
    atGoal = 0;
    piecenumber = h;
    totalMoves = 0;
    color = c;
    }

    // Call dice roll in execute, but do dice roll in dice

	void Board::execute()
	{
    // For Dice Roll Part
    // Piece p(1, 3, 'r', 2);
    int pn;
    pn = 0; // B1 goes first

    // Board b;
    int dice1 = 0;
    int dice2 = 0;
    char size;
    string ans;
    string pieceSelect;
    int pnIndex = 0;
    int diceX;
    string moveSelect;
    //while (ans == "p")
    ans = "a";
    do  {
        boarddisplay(dice1, dice2, pn);
        cin>>ans;
        gotoxy(0, 48);
        cout<<" Would you like to move piece #1 or piece #2?";
        cin>>pieceSelect;
        if (pieceSelect == "1")
        {
            pn = pnIndex;
        }
        else if (pieceSelect == "2")
        {
            pn = pnIndex + 4;
        }
        else
        {
            cout<<"Error: Invalid Piecenumber."<<endl;
        }
        roll (dice1, dice2);
        // diceX = players[pn].start();
            gotoxy(0, 50);
        cout<<"D1: "<<dice1<<" D2: "<<dice2;
        diceX = 0;
        if (dice1 == dice2)
        {
            if (players[pn].isAtHome())
            {
                gotoxy(0, 51);
                cout<<"Move(m) or stay (s)?";
                cin>>moveSelect;
                if (moveSelect == "m")
                {
                    diceX = players[pn].start();
                }
            }

            // diceX = players[pn].start();

            //gotoxy(70, 10);
            //cout<<"Same";
        }

        /*
        else
        {
            diceX = 0; // Dice roll was not a double, stays/does not move off home
            // dice X = 1; // Double, moved off home
        }
        */

            // gotoxy (70, 15);
            //cout<<"Sum: "<<(dice1 + dice2);
            //gotoxy (70, 20);
            //cout<<"Answer = "<<ans;
            //gotoxy (70, 25);
            //cout<<"Before --> Piece X: "<<players[pn].getx()<<" Piece Y: "<<players[pn].gety();
            // p.piecemove(dice1, dice2);
            players[pn].piecemove(dice1, dice2, diceX);
            //cout<<"After --> Piece X: "<<players[pn].getx()<<" Piece Y: "<<players[pn].gety();

       //      pnIndex += 1; // This selects the next piece. (All player turns)
            if (pnIndex == 4) pnIndex = 0;
            gotoxy (40, 1);
            cout<<"After --> Piece X "<< pn<<" "<<players[pn].getx()<<" Piece Y: "<<" "<<players[pn].gety();

        }
        while (ans == "p");
        gotoxy(70, 45);
	}

int main ()
{
    // Note: (in general) Moving one block is not moving one pixel
    // This is the int main() that will be used in the final version of this program:
    {
    Board b;
    b.execute();
    return 0;
    }
}

    /*
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
        */
