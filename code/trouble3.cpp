// Program: Trouble
// Trouble is a board game in which players complete to be the first to send 2 pieces around the board
// Period 4(A)
// Enloe High School
// Class of 2021
// (SET UP IS CRUCIAL)
// The set-up is crucial
// Note: There should be 1 particular constructor and no default constructors
// Constructors should not display anything
// You can have a default constructor for piece if you want to
// It is better to display board and then display piece
#include <iostream>
//#include <windows.h>
#include <stdlib.h>
#include <string>
#include <ctime> // TO have a different sequence of random numbers each time
using namespace std;

#ifdef USE_WINDOWS
COORD coord = { 0,0 }; // this is a global variable
									/*center of axis is set to the top left corner of the screen*/
void gotoxy(int x, int y)
{
  //        printf("%c[%d;%dH",0x1b,x,y);
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
#else
void gotoxy(int y, int x)
{
          printf("%c[%d;%dH",0x1b,x,y);
	  //	coord.X = x;
	  //coord.Y = y;
	  //SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
#endif


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
  char getc(){return color;}
  string getn(){return piecenumber;}
  string getpname();
  // int getd();
  void init(int x, int y, string c){
    xpos = 0;
    ypos = 0;
    initx=x;
    inity=y;
    piecenumber = c;
    got1 = 0;
    got2 = 0;
    got3 = 0;
    play = 0;
  };
  
  void setXY(int x, int y) {
    xpos = x;
    ypos = y;
  };
  
  void setC(char c){color = c;};
  // void setd();
  void piecemove(int n, int d1, int d2);
  int got1;
  int got2;
  int got3;
  int play;
  int initx;
  int inity;
  
};

class Board {
private:
  Piece players[8];
  // void loadChanceCards(); // TBD
  int numberAtGoal [4] = {0,0,0,0};
  // Red, Blue, Green, Yellow
public:
  void boarddisplay();
  void movepiece(int n, int d1, int d2);
  void initplayer(int n, int d1, int d2, string c);
  void setplayer(int n, int d1, int d2);
  void getXY(int n, int &d1, int &d2);
  void setXY(int n, int d1, int d2);
  void setC(int n, char c);
  void getC(int n, char &c);
  
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

int Board::roll(void)
{
  int r=(rand() % 3) + 1 ;
  return r;
}

Piece::Piece(int x, int y, char c, int p)
{
  xpos = x;
  ypos = y;
  color = c;
  p = p;
}

void Board::movepiece(int n, int d1, int d2)
{
  Piece *np = &players[n];
  np->piecemove(n,d1, d2);
}


void Board::setC(int n, char c)
{
  Piece *np = &players[n];
  np->setC(c);

}
void Board::getXY(int n, int &d1, int &d2)
{
  Piece *np = &players[n];
  d1 = np->getx();
  d2=  np->gety();
}

void Board::setXY(int n, int d1, int d2)
{
  Piece *np = &players[n];
  np->setXY(d1, d2);
}



void Board::getC(int n, char &c)
{
  Piece *np = &players[n];
  c = np->getc();

}

void Board::initplayer(int n, int x, int y, string c)
{
  Piece *np = &players[n];
  np->init(x,y,c);
}

void Board::setplayer(int n, int x, int y)
{
  Piece *np = &players[n];
  np->setXY(x,y);
}

void Board::boarddisplay()
{
  //system("CLS");
  system("clear");
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
  for (int i = 0 ; i < 8; i++)
    {
      Piece *p = &players[i];
      if (p->getx() > 0 )
	{
	  //	  gotoxy (3 + (p->getx() * 1), 1 + (p->gety() * 1));
	  gotoxy (3 + ((p->getx()-1) * 6), 3 + ((p->gety()-1) * 3));
	  cout<<p->getn();
	}
    }
}


void Piece::piecemove(int n, int d1 , int d2)
{
  if (d1 == d2)
    {
      if(play == 0)
	{
	  if (d1 == 1) got1 = 1;
	  if (d1 == 2) got2 = 1;
	  if (d1 == 3) got3 = 1;
	  if ((got1 + got2 + got3) == 3 )
	    {
	      play = 1;
	      xpos = initx;
	      ypos = inity;
	    }
	}
    }
  int move = d1 + d2;
  //  gotoxy (3 + (xpos * 6), 3 + (ypos * 3));
  cout<<"player ["<< n<<"]  move ["<< move<<"] from x,y ["<<xpos<<","<<ypos<<"]";
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
	  //	  move = ypos - 10;
	  xpos = xpos - ypos + 10;
	  ypos = 10;
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
  cout<<" to x,y ["<<xpos<<","<<ypos<<"]" << endl;
  
  //gotoxy (3 + (xpos * 6), 3 + (ypos * 3));
  //cout<<color;
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

int main ()
{
    // For Dice Roll Part
    //Piece p(1, 3, 'r', 2);
    Board b;
    int dice1;
    int dice2;
    char size;
    string ans;
    srand(time(NULL));
     //while (ans == "p")
    ans = "a";
    int mnum = 1;
    int player = 0;
    b.initplayer(0, 1, 5, "R1");
    b.initplayer(1, 1, 5, "R2");
    b.initplayer(2, 5, 1, "G1");
    b.initplayer(3, 5, 1, "G2");
    b.initplayer(4, 10, 5, "Y1");
    b.initplayer(5, 10, 5, "Y2");
    b.initplayer(6, 5, 10, "B1");
    b.initplayer(7, 5, 10, "B2");

    //b.boarddisplay();
    int play;
    int xpos;
    int ypos;
    cout << " Enter player xpos ypos ";    
    do  {
      

      cin>>play;
      cin>>xpos;
      cin>>ypos;
      cout << endl;
      cout << " player "<< play << " xpos " <<xpos<<" ypos " << ypos << endl;
      b.setplayer(play, xpos, ypos);
      b.boarddisplay();
      
    } while (play >= 0);
    return 0;

    do  {
        cin>>ans;
        dice1 = b.roll();
        dice2 = b.roll();
	
	int oldx, oldy;
	int newx, newy;
	
        //gotoxy(60, 5);
        //cout<<" D1: "<<dice1<<" D2: "<<dice2 << "  ";
        if (dice1 == dice2)
        {
	  //gotoxy(70, 10);
          //  cout<<"Same";
        }
	//gotoxy (70, 15);
	//cout<<" Sum: "<< (dice1 + dice2);
	//gotoxy (70, 20);
	//cout<<"  Answer = ["<<ans << " ]"<< endl;

	//gotoxy (70, 25);
	//oldx = b.getX(0);
	//b.getXY(0, oldx, oldy);
	  //cout<<" Before --> Piece X: "<<p.getx()<<" Y: "<<p.gety();
	b.movepiece(player++, dice1, dice2);
	if (player >= 8) player = 0;
	
	//b.boarddisplay();
	//p.piecemove(dice1, dice2);
	//gotoxy (65, 30);
	//b.getXY(0, newx, newy);

	//cout<<"  move " << mnum <<" Before --> Piece X: "<<oldx<<" Y: "<<oldy<< endl;
       	//cout<<"                 After  --> Piece X: "<<newx<<" Y: "<<newy << endl;
	mnum++;
    }
    while (ans == "p");
    //gotoxy(70, 45);
    return 0;
}
