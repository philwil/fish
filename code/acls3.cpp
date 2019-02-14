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
    Piece(){};
    init(char n, int x1, int x2, int x3);
    char n;
    int x1;
    int x2;
    int x3;
};

Piece::init(char nx, int x1x, int x2x, int x3x)
{
    n = nx;
    x1 = x1x;
    x2 = x2x;
    x3 = x3x;
}

class Board
{
    public:
    Board(int rx, int cx, int sx, int nx, int n1x, int n2x, int n3x, int n4x, int n5x);
    int r;
    int c;
    Piece pieces [10];
    int numPieces;
    int s;
    int n;
    int n1;
    int n2;
    int n3;
    int n4;
    int n5;
    int addPieceLR (Piece & p);
    int addPieceRL (Piece & p);
    int finish;
    int blockedX (int x);
    int blockedY (int x);
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
int Board::blockedX (int x)
{
    for (int i = 0; i < x; i++)
    {
        if ((s+i) == (n1))
            return 1;

        if ((s+i) == (n2))
            return 1;

        if ((s+i) == (n3))
            return 1;

        if ((s+i) == (n4))
            return 1;

        if ((s+i) == (n5))
            return 1;
    }
    return 0;
}

int Board::blockedY (int x)
{
    for (int i = 0; i < x; i++)
    {
        if (s + (i*c) == (n1))
            return 1;

        if (s + (i*c) == (n2))
            return 1;

        if (s + (i*c) == (n3))
            return 1;

        if (s + (i*c) == (n4))
            return 1;

        if (s + (i*c) == (n5))
            return 1;
    }
    return 0;
}
int Board::addPieceLR (Piece & p)
    {
    int x;
    int maxY;
    int y;
    y = (s-1) / c;
    maxY = (y+1) * c;
    cout<<"y: "<<y<<endl;
    x = p.x1;
    if (blockedX(p.x1 + 1))
        return -1;

    if ((x+s) > maxY)
    {
        x = -1;
        return x;
    }
    if (blockedY(p.x2))
        return -1;

    x += p.x2*c;
    maxY += p.x2*c;
    if ((x+s) > maxY)
    {
        x = -1;
        return x;
    }
    if (blockedX(p.x3 + 1))
        return -1;

    x += p.x3;
    if ((x+s) > maxY)
    {
        x = -1;
        return x;
    }
    if ((x+s) > (r*c))
    {
        x = -1;
    }
    if ((x + s) == maxY)
    {
        cout<<"x: "<<x<<" s: "<<s<<" maxY: "<<maxY<<endl;
        finish = 1;
    }
    return x;
    }

    int Board::addPieceRL (Piece & p)
    {
    int x;
    int maxY;
    int y;
    y = (s-1) / c;
    maxY = (y+1) * c;
    cout<<"y: "<<y<<endl;
    x = p.x1;
    if ((x+s) > maxY)
    {
        x = -1;
        return x;
    }
    x += p.x2*r;
    maxY += p.x2*c;
    if ((x+s) > maxY)
    {
        x = -1;
        return x;
    }
    x += p.x3;
    if ((x+s) > maxY)
    {
        x = -1;
        return x;
    }
    if ((x+s) > (r*c))
    {
        x = -1;
    }
    return x;
    }

    Piece pieces [3];

int runGame(int r, int c, int s, int n, int n1, int n2, int n3, int n4, int n5)
{
    int x;
    int i;
    int j;
    cout<<"Run game"<<endl;
    Board b (r, c, s, n, n1, n2, n3, n4 ,n5);
    // b.s = (c - 1);
    // b.n1 = (c-1);
    j = 0;
    for (i = 0; i < 10; i++)
    {
    x = b.addPieceLR(pieces[j]);
    if (x < 0)
    {
        cout<<"You cannot use this piece."<<endl;
    }
    else
    {
        s += x+1;
        b.pieces[b.numPieces] = pieces[j];
        b.numPieces++;
        if (b.finish)
        {
            cout<<"Result = ";
            for (i = 0; i < b.numPieces; i++)
        {
            cout<<b.pieces[i].n;
        }
            cout<<endl;
            return 0;
        }
    }
    j = j + 1;
    if (j >= 3)
    {
        j = 0;
    }
    x += s;
    cout<<"Piece "<<pieces[2].n<<" x: "<<x<<" s: "<<s<<endl;
    cout<<"Board done "<<b.finish<<endl;
}
}
int main ()
{
    string str;
    ifstream myfile;
    pieces[0].init('A', 2, 0, 0);
    pieces[1].init('B', 0, 1, 1);
    pieces[2].init('C', 1, 2, 0);
    myfile.open("ACSL3SampleInputIntermediate.txt", ifstream::in);
    if (myfile.is_open())
    {
    int r, c, s, n, n1, n2, n3, n4, n5;
    do
    {
    getline (myfile, str);
    cout<<"String read =  "<<str<<endl; // This could be anything (result, or whatever you are trying to find)
    sscanf(str.c_str(), "%d %d %d %d %d %d %d %d %d", &r, &c, &s, &n, &n1, &n2, &n3, &n4, &n5);
    cout<<"r: "<<r<<" c: "<<c<<" s: "<<s<<" n: "<<n<<" n1: "<<n1<<" n2: "<<n2<<endl;
    runGame (r, c, s, n, n1, n2, n3, n4, n5);
    }
    while (!myfile.eof());
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
