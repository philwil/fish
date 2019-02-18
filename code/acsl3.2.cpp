// Rohan Sachdev
// Enloe High School
// Mr. Potter - Advanced CS
// 2 - 12 - 2019
// ACSL 3 - Stretch
// Intermediate Division

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <cmath>

using namespace std;

class Piece
{
public:
    Piece() {};
    int init(char n, int x1, int x2, int x3);
    char n;
    int x1;
    int x2;
    int x3;
};

// this is the location of a piece
class Place
{
public:
    Place() {};
    int start;
    int blocked[20];
    int end;
    int piece;
    int markBlocked(void);
};

int Piece::init(char nx, int x1x, int x2x, int x3x)
{
    n = nx;
    x1 = x1x;
    x2 = x2x;
    x3 = x3x;
};

class Board
{
public:
    Board(int rx, int cx, int sx, int nx, int n1x, int n2x, int n3x, int n4x, int n5x);
    int r;
    int c;
    int pieces [24];
    Place places[24];
    int numPieces;
    int s;
    int n;
    int n1;
    int n2;
    int n3;
    int n4;
    int n5;
    int addPieceLR (int sx, Piece & p);
    int addPieceRL (int sx, Piece & p);
    int finish;
    int blockedX (int s, int x);
    int blockedY (int s,int x);
};

Board::Board(int rx, int cx, int sx, int nx, int n1x, int n2x, int n3x, int n4x, int n5x)
{
    r = rx;
    c = cx;
    s = sx;
    n = nx;
    n1 = n1x;
    n2 = n2x;
    n3 = n3x;
    n4 = n4x;
    n5 = n5x;
    numPieces = 0;
    finish = 0;
}

int Board::blockedX (int sx, int x)
{
    for (int i = 0; i < x; i++)
    {
        if ((sx+i) == (n1))
        {
            cout<< " ... blocked at n1  "<< n1 << endl;
            return 1;
        }

        if ((sx+i) == (n2))
        {
            cout<< " ... blocked at n2  "<< n2 << endl;
            return 1;
        }

        if ((sx+i) == (n3))
        {
            cout<< " ... blocked at n3  "<< n3 << endl;
            return 1;
        }

        if ((sx+i) == (n4))
        {
            cout<< " ... blocked at n4  "<< n4 << endl;
            return 1;
        }

        if ((sx+i) == (n5))
        {
            cout<< " ... blocked at n5  "<< n5 << endl;
            return 1;
        }

    }
    return 0;
}

int Board::blockedY (int sx, int x)
{
    cout<< " Checking Blocked Y "
        << " sx: "<<sx <<" x:"<< x<< endl;

    for (int i = 0; i < x; i++)
    {
        cout<< " Checking Blocked Y at i "<< i << " sx+ (i * c): "
            << sx+(i *c) << endl;

        if (sx + (i*c) == (n1))
        {
            cout<< " ... blocked at n1  "<< n1 << endl;
            return 1;
        }
        if (sx + (i*c) == (n2))
        {
            cout<< " ... blocked at n2  "<< n2 << endl;
            return 1;
        }
        if (sx + (i*c) == (n3))
        {
            cout<< " ... blocked at n3  "<< n3 << endl;
            return 1;
        }
        if (sx + (i*c) == (n4))
        {
            cout<< " ... blocked at n4  "<< n4 << endl;
            return 1;
        }
        if (sx + (i*c) == (n5))
        {
            cout<< " ... blocked at n5  "<< n5 << endl;
            return 1;
        }
    }
    return 0;
}
Piece pieces [3];
int Place::markBlocked()
{
    cout<<"markBlocked piece = "<<piece
	<<" x1 = "<<pieces[piece].x1
	<<" x2 = "<<pieces[piece].x2
	<<" x3 = "<<pieces[piece].x3
	<< endl;
}

int Board::addPieceLR (int st, Piece &p)
{
    int x;
    int maxY;
    int y;
    int sx;

    y = (st-1) / c;
    maxY = (y+1) * c;
    cout<<"row: "<<y+1 << " end of row: " << maxY <<endl;

    //cout<<"y: "<<y<<endl;
    sx = st;
    x = p.x1;
    if (blockedX(sx, p.x1 + 1)) //Check piece blocked including next start location
    {
        cout<< " Blocked X1 "<< endl;
        return -1;
    }
    if ((x+st) > maxY)
    {
        return -1; // Exceeded row size
    }
    sx =  st+x;
    if (blockedY(sx, p.x2))
    {
        cout<< " Blocked Y1"<< endl;
        return -1;
    }
    x += p.x2*c;
    maxY += p.x2*c;
    sx =  x+st;

    if ((x+st) > maxY)
    {
        x = -1;
        cout<<"Blocked Y2"<<endl;
        return x; // Exceeded row size
    }
    if (blockedX(sx, p.x3 + 1))
    {
        cout<< " Blocked X2 "<< endl;
        return -1;
    }

    x += p.x3;
    if ((x+st) > maxY)
    {
        x = -1; // Exceeded row size
        cout<<"Exceeded row size"<<endl;
        return x;
    }
    if ((x+st) > (r*c))
    {
        x = -1;
    }
    if ((x + st) == maxY)
    {
        cout<<"finish x: "<<x<<" s: "<< st <<" maxY: "<<maxY<<endl;
        finish = 1;
    }
    return x;
}

int Board::addPieceRL (int st, Piece &p)
{
    int x;
    int minY;
    int y;
    int sx;

    // we calculate back to the start of the piece and then use LR

    //cout<<"y: "<<y<<endl;
    sx = st - p.x3 -(p.x2 * c) -p.x1;
    y = (sx-1) / c;
    minY = (y+1) * c;
    minY -= c;
    minY += 1;

    cout<<"addPieceRL row: "<<y+1 << " beginning  of row: " << minY <<endl;
    cout<<"addPieceRL new sx: "<< sx << " beginning  of row: " << minY <<endl;
    if(sx < minY ) return -1;
    x = addPieceLR(sx, p);
    if (x == minY)
      {
        //finish = 1;
      }
    else
      {
        finish = 0;
      }
    cout << " x= "<<x 
	 << " minY= "<< minY 
	 << " finish 2 " << finish << endl;

    return x;
}

// Piece pieces [3];

int runGame(int r, int c, int s, int n, int n1, int n2, int n3, int n4, int n5)
{
    int x;
    int i;
    int ii;
    int j;
    int olds;
    int dir = 0;  // LR
    int div;
    if(c == 0) return 0;

    div =  s/c;
    if((div * c) == s ) dir = 1;


    cout<<"Run game start s: " << s
        << " div *c : " << div *c
        << " dir : " << dir
        <<endl;

    for ( i = 1; i <=r; i++)
      {
        cout << " row ["<<i<<"] " << 1+(i-1)*c <<" ....  "<< i*c << endl; 
      }

    Board b (r, c, s, n, n1, n2, n3, n4 ,n5);
    // b.s = (c - 1);
    // b.n1 = (c-1);
    j = 0;
    for (ii = 0; ii < 36; ii++)
    {
      cout << "Run " << ii <<" Checking piece " << pieces[j].n
	   << " S is: " << b.s
	   << endl;
        if (dir == 0 )
        {
            x = b.addPieceLR(b.s, pieces[j]);
        }
        else
        {
            x = b.addPieceRL(b.s, pieces[j]);
        }
        if (x < 0)
        {
            cout<<"You cannot use piece " << pieces[j].n 
		<< " b.finish " << b.finish
		<< endl;
        }
        else
        {
            //if (dir == 1 ) x = -x;

            olds=b.s;

            if(dir == 0)
            {
                b.s += x+1;
            }
            else
            {
                b.s -= (x+1);
                // check for row beginning
                for (i=0; i < b.r; i++)
                {
                    if (b.s == i*c)
                    {
                        b.finish = 1;
                        cout<<"Finished because b.s: "<<b.s
			    <<"  == i * c: "<<i * c<<endl;
                    }
                }
            }
            cout<<"Used piece " << pieces[j].n << " x is " << x
                << " s moved from  "<< olds<< " to "<< b.s
		<< " b.finish " << b.finish
		<< endl;

            b.pieces[b.numPieces] = j;
            b.places[b.numPieces].piece = j ;
            if(dir == 0)
            {
                b.places[b.numPieces].start=olds ;
                b.places[b.numPieces].end=b.s ;
            }
            else
            {
                b.places[b.numPieces].end=olds ;
                b.places[b.numPieces].start=b.s+1 ;
            }

            b.places[b.numPieces].markBlocked();
            b.numPieces++;

            if (b.finish)
            {
                cout << endl;
                cout << endl;
                cout << endl;
                cout<<">>>>Result = ";
                if(dir == 0)
                {
                    for (i = 0; i < b.numPieces; i++)
                    {
                        cout<<pieces[b.pieces[i]].n;
                    }
                }
                else
                {
                    for (i = b.numPieces-1; i>=0; i--)
                    {
                        cout<<pieces[b.pieces[i]].n;
                    }
                }
                cout<<endl;
                cout<<">>>>Places = ";

                if(dir == 0)
                {
                    for (i = 0; i < b.numPieces; i++)
                    {
                        cout << " Piece # "
                             <<b.places[i].piece
                             << " start "
                             <<b.places[i].start
                             << " end "
                             <<b.places[i].end
                             << endl;
                    }
                }
                else
                {

                    for (i = b.numPieces-1; i>=0; i--)
                    {
                        cout << " Piece # "
                             <<b.places[i].piece
                             << " start "
                             <<b.places[i].start
                             << " end "
                             <<b.places[i].end
                             << endl;
                    }
                }
                return 0;
            }
        }
        j = j + 1; //Increment the Piece number
        if (j >= 3)
        {
            j = 0;
        }
        //x += s;
        //cout<<"Piece "<<pieces[2].n<<" x: "<<x<<" s: "<<s<<endl;
        cout<<"Board done "<<b.finish<<endl;
    }
}
int main ()
{
    string str;
    ifstream myfile;
    int done = 0;
    pieces[0].init('A', 2, 0, 0);
    pieces[1].init('B', 0, 1, 1);
    pieces[2].init('C', 1, 2, 0);
    myfile.open("ACSL3IntermediateFile.txt", ifstream::in); // //ACSL3SampleInputIntermediate.txt
    if (myfile.is_open())
    {
        int r, c, s, n, n1, n2, n3, n4, n5;
        do
        {
            getline (myfile, str);

            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;

            cout<<"String read =  "<<str<<endl; // This could be anything (result, or whatever you are trying to find)
            r = c = s = n = 0;
            n1 = n2 = n3 = n4 = n5 =0;

            sscanf(str.c_str(), "%d %d %d %d %d %d %d %d %d", &r, &c, &s, &n, &n1, &n2, &n3, &n4, &n5);
            cout<<"r: "<<r<<" c: "<<c<<" s: "<<s<<" n: "<<n<<" n1: "<<n1<<" n2: "<<n2<<endl;
            runGame (r, c, s, n, n1, n2, n3, n4, n5);
            //done = 1;
        }
        while (!myfile.eof() && !done);
        myfile.close();
    }

    else
    {
        cout<<"Invalid Input: ERROR"<<endl;
    }
}
/*
cout<<" Please input the number of rows and columns , start // then how many blocks and then please list the blocks"<<endl;
// or, i think the next one is better
cout<<"Number of rows in grid: "<<endl;
cin>>r; // rows
cout<<"Number of columns in grid: "<<endl;
cin>>c; // columns
cout<<"Starting cell number for the first piece: "<<endl;
cin>>s; // starting
cout<<"Number of blocked cells: "<<endl;
cin>>n1; // # of blocked
cout<,"Cells that are designated as blocked: "<<endl;
cin>>n2 // # of designated in block
*/
// string letters;
// cin>>letters;
// cout<<letters<<endl;
// vector <int> blocks;
//int space = letter.find('');
//string str = letters.substr(0, space);
//letters.erase();


//Text FIle
//8 14 15 2 98 81
//5 12 60 2 15 48
//7 17 119 2 37 22
//6 13 52 2 23 35
//10 18 19 1 81
