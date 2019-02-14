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
    int init(char n, int x1, int x2, int x3);
    char n;
    int x1;
    int x2;
    int x3;
};

int Piece::init(char nx, int x1x, int x2x, int x3x)
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
    int pieces [10];
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
	return 1;
      cout<< " ... its not n1  "<< n1 << endl;
      
      if (sx + (i*c) == (n2))
	return 1;
      cout<< " ... its not n2  "<< n2 << endl;
      
      if (sx + (i*c) == (n3))
	return 1;
      cout<< " ... its not n3  "<< n3 << endl;
      
      if (sx + (i*c) == (n4))
	return 1;
      cout<< " ... its not n4  "<< n4 << endl;
      
      if (sx + (i*c) == (n5))
            return 1;
      cout<< " ... its not n5  "<< n5 << endl;

    }
  return 0;
}

int Board::addPieceLR (Piece &p)
{
  int x;
  int maxY;
  int y;
  int sx;
  
  y = (s-1) / c;
  maxY = (y+1) * c;
  cout<<"row: "<<y+1 << " end of row: " << maxY <<endl;

  //cout<<"y: "<<y<<endl;
  sx = s;
  x = p.x1;
  if (blockedX(sx,p.x1 + 1))
    {
      cout<< " Blocked X1 "<< endl;
      return -1;
    }
  if ((x+s) > maxY)
    {
      return -1;
    }
  sx =  x+s;
  if (blockedY(sx, p.x2))
    {
      cout<< " Blocked Y "<< endl;
      return -1;
    }
  x += p.x2*c;
  maxY += p.x2*c;
  sx =  x+s;

  if ((x+s) > maxY)
    {
      x = -1;
      return x;
    }
  if (blockedX(sx, p.x3 + 1))
    {
      cout<< " Blocked X2 "<< endl;
      return -1;
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
  if ((x + s) == maxY)
    {
      cout<<"x: "<<x<<" s: "<<s<<" maxY: "<<maxY<<endl;
      finish = 1;
    }
  return x;
}

int Board::addPieceRL (Piece &p)
{
  int x;
  int minY;
  int y;
  int sx;
  
  y = (s-1) / c;
  minY = (y+1) * c;
  minY -= c;
  minY += 1;
  
  cout<<"addPieceRL row: "<<y+1 << " beginning  of row: " << minY <<endl;

  //cout<<"y: "<<y<<endl;
  sx = s;
  x = p.x3;
  if(p.x3 > 0 )
    {
      cout<<"Checking Blocked X from  "<<sx-p.x3-1 << " num " << p.x3+1 <<endl;
      
      if (blockedX(sx-p.x3-1, p.x3 + 1))
	{
	  cout<< " Blocked X2 "<< endl;
	  return -1;
	}
      if ((s-x) < minY)
	{
	  return -1;
	}
      sx =  s-x;
    }
  if(p.x2 > 0 )
    {
      cout<<"Checking Blocked Y from  "<< sx - (c *p.x2) << " num " << p.x2 <<endl;
      
      if (blockedY(sx - (c *p.x2), p.x2))
	{
	  cout<< " Blocked Y "<< endl;
	  return -1;
	}
      x += p.x2*c;
      minY -= p.x2*c;
      sx =  s-x;
      
      if ((s-x) < minY)
	{
	  return -1;
	}
    }
if(p.x1 > 0 )
  {
    
    cout<<"Checking Blocked X from  "<<sx-(p.x1+1) << " num " << p.x1 <<endl;
    
    if (blockedX(sx-(p.x1+1), p.x1 ))
      {
	cout<< " Blocked X1 "<< endl;
	return -1;
      }
    
    x += p.x1;
    if ((s - x) < minY)
      {
	cout<< " Blocked X Min s: "<< s << " x: " << x
	    << " minY : " << minY<< endl;

	return -1;
      }
    if ((s-x) < 0)
      {
	cout<< " Blocked X Min s: "<< s << " x: " << x
	    << endl;
	return -1;

      }
  }
 if ((s-x) == minY)
   {
     cout<<"x: "<<x<<" s: "<<s<<" minY: "<<minY<<endl;
     finish = 1;
   }
  return x;
}

#if 0
//int Board::addPieceRL (Piece & p)
{
  int x;
  int maxY;
  int y;
  y = (s-1) / c;
  maxY = (y+1) * c;
  cout<<"row: "<<y+1 << " end of row: " << maxY <<endl;
  x = p.x1;
  if ((x+s) > maxY)
    {
      return -1;
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
#endif

Piece pieces [3];

int runGame(int r, int c, int s, int n, int n1, int n2, int n3, int n4, int n5)
{
    int x;
    int i;
    int j;
    int olds;
    int dir = 0;  // LR
    int div =  s/c;
    if((div * c) == s ) dir = 1;
    
    cout<<"Run game start s: " << s
	<< " div *c : " << div *c
	<< " dir : " << dir
	<<endl;
    
    Board b (r, c, s, n, n1, n2, n3, n4 ,n5);
    // b.s = (c - 1);
    // b.n1 = (c-1);
    j = 0;
    for (i = 0; i < 10; i++)
    {
      cout << "Checking piece " << pieces[j].n
	   << " S is: " << b.s
	   << endl;
      if (dir == 0 )
	x = b.addPieceLR(pieces[j]);
      else
	x = b.addPieceRL(pieces[j]);
	
      if (x < 0)
	{
	  cout<<"You cannot use piece " << pieces[j].n << endl; 
	}
      else
	{
	  //if (dir == 1 ) x = -x;

	  olds=b.s;
	  
	  if(dir == 0)
	    b.s += x+1;
	  else
	    b.s -= (x+2);
	    
	  cout<<"Used piece " << pieces[j].n << " x is " << x
	      << " s moved from  "<< olds<< " to "<< b.s<< endl; 

	  b.pieces[b.numPieces] = j;
	  b.numPieces++;
	  if (b.finish)
	    {
	      cout << endl;
	      cout << endl;
	      cout << endl;
	      cout<<">>>>Result = ";
	      for (i = 0; i < b.numPieces; i++)
		{
		  cout<<pieces[b.pieces[i]].n;
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
    myfile.open("ACSL3SampleInputIntermediate.txt", ifstream::in);
    if (myfile.is_open())
    {
    int r, c, s, n, n1, n2, n3, n4, n5;
    do
    {
    getline (myfile, str);
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
