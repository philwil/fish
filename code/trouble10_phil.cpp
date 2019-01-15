// Rohan Sachdev
// Advanced CS - Potter 2018
// 11-26-2018 to 01-15-2019
// For GOAL, use 24 and say if > than 24 then go towards goal, and coide the directions towards goalbased on the 4 directions of thee colors

// Things to be graded for GOAL 3:
// Goes to Goal
// Piece in goal cannot be selected once in the goal
// Opposing pieces allowed to be in the goal at the same time
// Loops the goal pathway until it ends up in the goal
// Winner is declared

// Also from scenario 2, it rounds goal corner

// Part 2: SETUP these bottom 2

// Number of players (1-4 players allowed (in line 599)
// Turns default constructor for Board (line 146)
// Rolling Doubles to move out of home base (line 400)
// Moving multiple pieces (piece 1 or piece 2) (Line 628)


// Chance spots in doChance implement and remove it for an extra 5 pts so total 10 pts (line 322)
// Sending someone home by landing on another person's piece (in doLand line 367)


// Program: Trouble
// Trouble is a board game in which players compete to be the first to send 2 pieces around the board
// Period 4(A)
// Enloe High School
// Class of 2021
// (SET UP IS CRUCIAL)
// Lines 237 and 238 should be uncommented for a fixed dice roll for hard-coding
// The set-up is crucial
// Note: There should be 1 particular constructor and no default constructors
// Constructors should not display anything
// You can have a default constructor for piece if you wan to
// It is better to display board and then display piece

#include <iostream>
#ifdef USE_WINDOWS
#include <windows.h>
#else
#include <stdio.h>

#endif
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
// Dice rolls at line 219
// (x, y, __, __)
// xcoor = x1;
// ycoor = y1;
// origx = x1;
// origy = y1;
#ifdef USE_WINDOWS
COORD coord = { 0,0 }; // this is a global variable
#endif
/* center of axis is set to the top left corner of the screen */
int diceroll1 [16];
int diceroll2 [16];
int rolled = 0;
int maxRoll = 0;
// int totalMax = 24;

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
#ifdef USE_WINDOWS
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#else
    printf("%c[%d;%dH",0x1b,y,x);
#endif
    
}

class Piece
{

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
    // int totalMoves;
    int atGoal;
    int xHome;
    int yHome;
public:
    Piece (int x, int y, char c, int p /*d*/);
    Piece() {};
    int getx() {
        return xpos;
    }
    int gety() {
        return ypos;
    }
    string getc() {
        return color;
    }; // I changed this to string
    string getpname() {
        return piecenumber;
    };
    // int getd();
    void setx(int x) {
        xpos = x;
    };
    void sety(int y) {
        ypos = y;
    };
    // void setd();
    void piecedisplay(int newX, int newY);
    void piecemove(int d1, int d2, int diceX);
    int gethome(void) {
        return isHome;
    };
    int start();
    int setAtGoal() {
        atGoal = 1;
    };
    int isAtHome();
    void setup(int x, int y, string c,string h, int total);
    int goHome(void);
    int setxy (int x, int y);
    int totalMax;
    int totalMoves;
    int setMove (int moves);
};

class Board
{

private:
    Piece players[8];
    Piece chances[4];
    // void loadChanceCards(); // TBD
    //int numberAtGoal [4] = {0,0,0,0}; //Took this line out
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
    int maxPlayers;
    string diceRoll;
    int doChance(int pn);
    int doLand(int pn);
};

Board::Board()
{
    setUpRoll (0,1,2); // Roll 0 (1st roll)
    setUpRoll (1,3,3); // Roll 1 (2nd roll)

    srand(time(NULL));
    /*
    players[0].setup(5, 8, "Blue", "B1"); // top
    players[4].setup(2, 2, "Blue", "B2");
    players[1].setup(8, 8, "Green", "G1"); // right
    players[5].setup(9, 7, "Green", "G2");
    players[2].setup(2, 8, "Yellow", "Y1"); // bottom
    players[6].setup(2, 7, "Yellow", "Y2");
    players[3].setup(4, 8, "Red", "R1"); // left
    players[7].setup(3, 8, "Red", "R2");
    */
    chances[0].setup(4, 2, "Chance", "C1", 0);
    chances[1].setup(8, 4, "Chance", "C2", 0);
    chances[2].setup(6, 8, "Chance", "C3", 0);
    chances[3].setup(2, 6, "Chance", "C4", 0);

    players[0].setup(6, 1, "Blue",   "B1", 24); // Change the y-coordinate of this point in order to change the moving piece's position
    players[4].setup(7, 1, "Blue",   "B2", 23);
    players[1].setup(9, 6, "Green",  "G1", 24);
    players[5].setup(9, 7, "Green",  "G2", 23);
    players[2].setup(4, 9, "Yellow", "Y1", 24);
    players[6].setup(3, 9, "Yellow", "Y2", 23);
    players[3].setup(1, 4, "Red",    "R1", 24); // This sets up home
    players[7].setup(1, 3, "Red",    "R2", 23);

    players[0].setMove(24); // top (blue)
    players[4].setMove(2);
    players[1].setMove(24); // right (green)
    players[5].setMove(2);
    players[2].setMove(24); // bottom (yellow)
    players[6].setMove(20);
    players[3].setMove(1); // left (red)
    players[7].setMove(1);

    /*
    players[4].set
    players[1].set// right
    players[5].set
    players[2].set // bottom
    players[6].set
    players[3].set// left
    players[7].set(
    */


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

int Piece::setMove (int moves)
{
    // totalMoves = 1;
    int toMove = 0; // The move but maximum 6 moves
    int moved = 0; // Total moves so far
    int diceX = 0;
    // The while loop calculates the number of moves left to do
    while (moved < moves)
    {
        diceX = 0;
        if (isAtHome())
        {
            diceX = start();
        }
        toMove = moves - moved; // Find how much left
        if (toMove > 6) // Limit to 6
        {
            toMove = 6;
        }
        piecemove(toMove, 0, diceX); // Combine the two dice into toMove
        moved += toMove; // Remembers total moves so far
    }
    totalMoves += 1;
    return 0;
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
    if (diceRoll == "r")
        return 0;
    // Return here for random rolls
    //return 0;

    // For fixed dice rolls
    gotoxy (10, 55);
    cout<<"Enter dice 1: ";
    cin>>dice1;
    cout<<"       Enter dice 2: ";
    cin>>dice2;

    // dice1 = 2;
    // dice2 = 2;
    gotoxy (10, 55);
    cout<<"                               "<<endl;
    cout<<"                               "<<endl;
    return 0;
    dice1 = diceroll1[rolled];
    dice2 = diceroll2[rolled];
    if (rolled < maxRoll)
        rolled = rolled + 1;
    return 0;
}

// gotoxy
void gotopiece(int xp, int yp)
{
  gotoxy(3 + (xp * 6), 3 + (yp * 3));
  return;
}

void Board::boarddisplay(int dice1, int dice2, int p)
{
#ifdef USE_WINDOWS
    system("CLS");
#else
    system("clear");
#endif
  
    
    gotoxy(1, 1);
    cout << "__________________________________________________________________" << endl;
    cout << "|     |     |     |     |     |     |     |     |     |     |     |" << endl;
    cout << "|     |     |     |     |     |     |     |     |     |     |     | 0" << endl;
    cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;

    for (int i = 0; i < 10; i++) {
        cout << "|     |     |     |     |     |     |     |     |     |     |     |" << endl;
        cout << "|     |     |     |     |     |     |     |     |     |     |     | " << i + 1 << endl;
        cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;
    }
    cout << "   0     1     2     3     4     5     6     7     8     9     10";
    int xpos = 5;
    int ypos = 5;
    gotoxy (2 + (xpos * 6), 3 + (ypos * 3));
    cout<<"GOAL";
    //gotopiece (0, 0);
    //cout<<"00";

    //gotopiece (1, 1);
    //cout<<"11";

    //gotopiece (2,2);
    //cout<<"22";

    ///exit(0);
    
    gotoxy(1, 50);
    cout<<"Move: "<<"Dice 1: "<<dice1<<" Dice 2: "<<dice2<<" Piece Moving: "<<players[p].getpname()<<" Color: "<<players[p].getc()<<" Sum: "<<(dice1 + dice2)<<" Same?: "<<(dice1 == dice2);

    for(int i = 0; i < (maxPlayers); i++)
    {
        xpos = players[i].getx();
        ypos = players[i].gety();
        // gotoxy(players[i].getx(), players[i].gety());
	gotopiece (xpos, ypos);
        //gotoxy (3 + (xpos * 6), 3 + (ypos * 3));
        cout<<players[i].getpname();
        gotoxy (1, 40 + i);
        cout<<"After --> Piece  "<< players[i].getpname()<<" X position: "<<xpos<<"   Y position: "<<" "<<ypos; //<<" Home: "<<players[i].gethome(
        xpos = players[i + 4].getx();
        ypos = players[i + 4].gety();
	gotopiece (xpos, ypos);
        //gotoxy (3 + (xpos * 6), 3 + (ypos * 3));
        cout<<players[i + 4].getpname();
        gotoxy (1, 40 + i + 4);
        cout<<"After --> Piece  "<< players[i + 4].getpname()<<" X position: "<<xpos<<"   Y position: "<<" "<<ypos; //<<" Home: "<<players[i].gethome();
    }
    for(int i = 0; i < 4; i++)
    {
        xpos = chances[i].getx();
        ypos = chances[i].gety();
        if (xpos != -1)
        {
            // gotoxy(players[i].getx(), players[i].gety());
            //gotoxy (3 + (xpos * 6), 3 + (ypos * 3));
	    gotopiece (xpos, ypos);
            cout<<chances[i].getpname();
        }
        // gotoxy (1, 40  +i);
        // cout<<"After --> Piece  "<< players[i].getpname()<<" X position: "<<xpos<<"   Y position: "<<" "<<ypos;
    }
    gotoxy(1, 51);
    cout<<"Press 'p' to move."<<endl;
    //gotoxy(3,3);
    //cout<<"R1";
    //int x;
    //cin>>x;
}

int Board::doChance(int pn)
{
    string n;
    int dice1;
    int dice2;
    for (int i=0; i<4; i++)
    {
        if (chances[i].getx() != -1)
        {
            if (players [pn].getx() == chances[i].getx() && players [pn].gety() == chances[i].gety())
            {
                gotoxy(10, 51);
                cout<<"Chance (c) or no thanks (n)";
                cin>>n;
                chances[i].setx(-1);
                if (n == "c")
                {
                    // chances[i].setx(-1);
                    // dice1 = (rand() % 3) + 1;
                    // dice2 = (rand() % 3) + 1;
                    roll (dice1, dice2);
                    if ((dice1 + dice2) == 2)
                    {
                        players[pn].goHome();
                        gotoxy(10, 52);
                        cout<<"Go home";
                    }
                    else if (((dice1 + dice2) == 3)|| ((dice1 + dice2) == 4))
                    {
                        gotoxy(10, 53);
                        cout<<"Nothing happened";
                    }
                    else if (((dice1 + dice2) == 5)|| ((dice1 + dice2) == 6))
                    {
                        players[pn].piecemove(3, 0, 0);
                        gotoxy(10, 54);
                        cout<<"You moved forward 3 spaces";
                    }
                }
            }
        }
    }
    return 0;
}

int Board::doLand(int pn)
{
    // int temp;
    for (int i=0; i<maxPlayers * 2; i++)
    {
        if (pn != i) // Note: This will also move our own to home
            // if (pn != i || pn != (i+4) || pn != (i-4)) this will not move your own piece back home of you land on it
        {
            // did we land on someone
            if ((players[pn].getx() == players[i].getx()) && (players[pn].gety() == players[i].gety()))
            {
                gotoxy(10, 55);
                // cout<<"You land on another player's piece."<<" i = "<<i<<" pn "<<pn<<" ix "
                // <<players[i].getx()<< " iy "<<players[i].gety()<<" px "<<players[pn].getx()<< " py "<<players[pn].gety();
                // cin>>temp;
                // if not at goal send home
                if (! ((players[i].getx() == 5) && (players[i].gety() == 5 )))
                    players[i].goHome();
                // we know i and pn are in the same location
                if (((players[pn].getx() == 5) && (players[pn].gety() == 5 )))
                {
                    if (i == (pn + 4) || i == (pn - 4))
                    {
                        // gotoxy(10, 58);
                        // cout<<"You win! Game over."; // <<" i "<<i<<" pn "<<pn<<" xpos = "<<players[i].getx();
                        return 1;
                        // cin>>temp;

                    }
                }

            }

        }
    }
    return 0;
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
    if (totalMoves < totalMax) // This is a normal move
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
    else // Moving towards goal (center) // Goal Move
    {
        // move = totalMoves - totalMax;
        gotoxy(1, 50);
        // int temp;
        // cout<<"Goal  Total moves:  "<<totalMoves<<" Total max:  "<<totalMax<<" X pos: "<<xpos<<" Y pos: "<<ypos;
        // cin>>temp;
        int goalMove = totalMoves - totalMax;
        int goalTurnX;
        int goalTurnY;
        goalMove = goalMove % 4; // Only 3 moves available
        if (xHome == 1)
        {
            goalTurnX = 2;
            goalTurnY = 5;
            xpos = goalTurnX + goalMove;
            ypos = goalTurnY;
        }
        else if (xHome == 9)
        {
            goalTurnX = 8;
            goalTurnY = 5;
            xpos = goalTurnX - goalMove;
            ypos = goalTurnY;
        }

        else if (yHome == 1)
        {
            goalTurnX = 5;
            goalTurnY = 2;
            xpos = goalTurnX;
            ypos = goalTurnY + goalMove;
        }

        else if (yHome == 9)
        {
            goalTurnX = 5;
            goalTurnY = 8;
            xpos = goalTurnX;
            ypos = goalTurnY - goalMove;
        }
        totalMoves = totalMax + goalMove;
    }
    if (totalMoves == totalMax + 3)
    {
        gotoxy(1, 37);
        cout<<"At GOAL";
        atGoal = 1;
        xpos = 5;
        ypos = 5;
    }
}

void piecedisplay(struct point p[], int n)
{
    int i;
    system("CLS");
    gotoxy(1, 1);
    cout << "__________________________________________________________________" << endl;
    cout << "|     |     |     |     |     |     |     |     |     |     |     |" << endl;
    cout << "|     |     |     |     |     |     |     |     |     |     |     | 0" << endl;
    cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;

    for (int i = 0; i < 10; i++) {
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

void Piece::setup(int x, int y, string c,string h, int total)
{   // N
    xpos = x;
    ypos = y;
    isHome = 1;
    atGoal = 0;
    piecenumber = h;
    totalMoves = 0;
    color = c;
    xHome = x;
    yHome = y;
    totalMax = total;
}

int Piece::goHome(void)
{
    totalMoves = 0;
    xpos = xHome;
    ypos = yHome;
    return 0;
}

// Chance Cards: Landing on a chance square
// Prompt a playr with a choice
// No thanks - nothing happens
// Chance - th computer will roll two more dice
// If sum = 5 or 6 player moves forwarrd  spaces
// If sum = 3 or 4 nothing happens
// If sum = 2 player moves home





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
    int win = 0;
    char size;
    string ans;
    string pieceSelect;
    int pnIndex = 0;
    int diceX;
    string moveSelect;
// int maxPlayers;

    gotoxy(1, 5);
    cout<<"How many players?";
    cin>>maxPlayers;
    if (maxPlayers <= 0 || maxPlayers > 4)
    {
        cout<<"Invalid number of players."<<endl;
        return;
    }

    cout<<"Manual (m) or Random (r) Dice Roll?";
    cin>>diceRoll;
    //while (ans == "p")
    ans = "a";
    do  {
        boarddisplay(dice1, dice2, pn);
        if (win == 1)
        {
            gotoxy(1, 58);
            cout<<"You win! Game over.";
            cin>>ans;
            ans = "q";

        }
        else
        {
            cin>>ans;
        }
        /*                          // THIS WILL ALLOW MANUAL AND RANDOM MOVES EACH TIME, PRESS M FOR MANUAL AND R FOR RANDOM
                if (ans == "m")     // THIS WILL ALLOW MOVES TO VARY
                {
                    diceRoll = "m";
                    ans = "p";
                }
                else
                {
                    diceRoll = "r";
                }
        */
// Moving multiple pieces (piece 1 or piece 2) Line
	gotoxy(1, 47);
	cout<<" Piece Moving: "<<players[pnIndex].getpname();
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
        if (players[pn].getx() == 5 && players[pn].gety() == 5)
        {
            cout<<"Piece already in goal"<<endl;
        }
        roll (dice1, dice2);
        // diceX = players[pn].start();
        gotoxy(0, 50);
        cout<<"D1: "<<dice1<<" D2: "<<dice2;
        diceX = 0;
        if (dice1 == dice2) // For rolling doubles
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
        doChance(pn);
        win = doLand(pn);
        //cout<<"After --> Piece X: "<<players[pn].getx()<<" Piece Y: "<<players[pn].gety();

        pnIndex += 1; // This selects the next piece. (All player turns)
        if (pnIndex == maxPlayers) pnIndex = 0;
        gotoxy (40, 1);
        cout<<"After --> Piece X "<< pn<<" "<<players[pn].getx()<<" Piece Y: "<<" "<<players[pn].gety();

    }
    while (ans == "p");
    gotoxy(70, 45);
}

int main ()
{
  #ifdef USE_WINDOWS
    system("CLS");
#else
    system("clear");
#endif

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
