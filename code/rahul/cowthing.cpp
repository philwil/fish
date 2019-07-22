/* basicfile
 *  read a file containing
 * locate the coords of B R and L
..........
..........
..........
..B.......
..........
.....R....
..........
..........
.....L....
..........
 */

#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;



int g_debug = 0;

int g_id = 1;

class NumberList;

int writeToFile (string fileName, NumberList&nl) {
  ofstream myfile;
  myfile.open (fileName.c_str());
  myfile << "Writing this to a file.\n";
  myfile.close();
  return 0;
}




class Number{
    public:

    Number(){

        next = NULL;
id = ++g_id;

        if (g_debug) {
             cout<<"Constructor called"<<endl;
        }

    };
    ~Number(){

        if (g_debug) {
             cout<<"Destructor called"<<endl;
        }
    };

    /* new code */
  Number(const Number &n) {

    if (g_debug) {
             cout<<"Copy constructor called"<<endl;
        }

    x = n.x;
    y = n.y;
  }
    /* end of new code */

    void setX(long int n){
        x = n;
    };
    void setY(long int n){
        y = n;
    };

    void setName(string n){
    name = n;
    };

    void setX(string n){
      x = atoi(n.c_str());
    };
    void setY(string n){
      y = atoi(n.c_str());
    };
  long int getX(){
    return x;
  };
  long int getY(){
    return y;
  };


    void showNumber() {
      cout<<id<<","<< name << "," << x<<","<<y<<endl;
    }
    void showHeader() {
        cout<<" ID, "<<"name,"<<"x, "<<" y "<<endl;
    }
    void showNumber(ofstream &myfile) {
      myfile<<id<<","<< name << "," << x<<","<<y<<endl;
    }
    void showHeader(ofstream &myfile) {
        myfile<<" ID, "<<"name,"<<"x, "<<" y "<<endl;

    }

    string name;
    long int x;
    long int y;

    Number*next;
    int id;
};

Number * Rock = NULL;
Number * Barn = NULL;
Number * Lake = NULL;
Number * Path = NULL;


class NumberList{
        public:

    NumberList(){

        numCount = 0;
        n = NULL;

        if (g_debug) {
        cout<<"New Number List"<<endl;
        }

    };

    ~NumberList(){};

    void insertNumber (Number *num) {

        numCount += 1;

       if (n != NULL) {
            num -> next = n;
       }

        n = num;

        if (g_debug) {
            cout<<"Number Count : "<<numCount<<endl;
        }

    }


    void showNumberList () {

        int i = 0;
        Number*nn = n;

        while (nn) {

            if (nn == n) {
                nn -> showHeader();
            }

            cout<<"object " <<i++<< " is :";
            nn -> showNumber();
            nn = nn -> next;
        }


    }

  // this is where we do all the work
  int readFile(string fName) {

        fName += ".txt";
        fstream input(fName.c_str());
cout << " running readFile [" << fName<<"]"<< endl ;
        //string cell[24];
        string line;
int row = 0;
int idx = 0;

        while (getline (input, line)) {
 row++;
 cout <<" line is [" << line<<"]" << endl;

 idx = 0;
 size_t pos = 0;

 pos = line.find('B');
 if (pos != string::npos){
   Number*n = new Number();
   n->setName("Barn");
   n->setX(pos+1);
   n->setY(row);
   insertNumber (n);
   Barn = n;
 }
 pos = line.find('R');
 if (pos != string::npos){
   Number*n = new Number();
   n->setName("Rock");
   n->setX(pos+1);
   n->setY(row);
   insertNumber (n);
   Rock = n;

 }

 pos = line.find('L');
 if (pos != string::npos){
   Number*n = new Number();
   n->setName("Lake");
   n->setX(pos+1);
   n->setY(row);
   insertNumber (n);
   Lake = n;
 }

        }

    return 0;

}


    void showNumberList (string fName) {

        int i = 0;
        fName+= ".csv";
          ofstream myfile;
            myfile.open (fName.c_str());
            //myfile << "Writing this to a file.\n";


        Number*nn = n;

        while (nn) {

            if (nn == n) {
                nn -> showHeader(myfile);
            }

            myfile<<i++<< " , ";
            nn -> showNumber(myfile);
            nn = nn -> next;
        }

            myfile.close();

    }

    Number *n;
    int numCount;



};

double doubleDist( int x1, int x2, int y1, int y2);

class cowPad;
// a cow link is a link between cowpads
// dist is dist to the target for the next cowPad
// level is the move we are on
// value is the supposed value of this link ie do the low ones first
// incX/incY are the modifications to the
// prev cowPad to the next one
// so create a cowPad and then create cowlinks for each direction

class cowLink {
public:  
  cowLink(cowPad *a, int x , int y) {
    level=0;
    prev = a;
    next = NULL;
    dist = 0.0;
    value = 99;
    incX= x;
    incY= y;
    
  };
  
  ~cowLink() {};
  double evalTarg(int tx, int ty);

  int incX;
  int incY;
  int level;
  int value;
  double dist;
  cowPad * prev;
  cowPad * next;
  
  
  
};

class cowPad {
public:

  cowPad( int xx = 0, int yy = 0) {
        //constructor called
        next = NULL;
        N = new cowLink(this, 0, -1);
        S = new cowLink(this, 0, 1);
        E = new cowLink(this, -1, 0);
        W = new cowLink(this, 1, 0);
        x = xx;
        y = yy;
        //Nval = 99;
        //Sval = 99;
        //Eval = 99;
        //Wval = 99;
        level = 0;
    };

    ~cowPad() {
        //destructor called
    };

    cowLink * N; //North
    cowLink * S; //South
    cowLink * E; //East
    cowLink * W; //West

    int x;
    int y;
    int level;

    cowPad *next;

    void setxy (int xn, int yn) {
        x = xn;
        y = yn;
    }

  void evalN (int xgoal, int ygoal);
  void evalS (int xgoal, int ygoal);
  void evalE (int xgoal, int ygoal);
  void evalW (int xgoal, int ygoal);



    void showPad () {
        cout<<"X is : "<<x<<" y is : "<<y<<endl;
        cout<<"N->val is : "<<N->value<<" S->val is : "<<S->value<<endl;
        cout<<"E->val is : "<<E->value<<" W->val is : "<<W->value<<endl;
    }


};



double cowLink::evalTarg(int tx, int ty)
{
  double targ;
  int xx = prev->x + incX;
  int yy = prev->y + incY;
  targ=doubleDist(xx,tx,yy,ty);
  
};

void cowPad::evalN (int xgoal, int ygoal){

  if (ygoal > y) {
    N->value = 99;
  } else {
    N->value = 0;
  }
}

void cowPad::evalS (int xgoal, int ygoal){
  
  if (ygoal > y) {
    S->value = 0;
  } else {
    S->value = 99;
  }
}

void cowPad::evalE (int xgoal, int ygoal){

  if (xgoal > x) {
    E->value = 99;
  } else {
    E->value = 0;
  }
}

void cowPad::evalW (int xgoal, int ygoal){
  
  if (xgoal > x) {
    W->value = 0;
  } else {
    W->value = 99;
  }
}

double doubleDist( int x1, int x2, int y1, int y2)
{
  double d;
  d = sqrt(pow(x1-x2,2) + pow(y1-y2,2));
  return d;
  
}

Number * findDist(NumberList &nl, Number * B, Number * L, Number * R)
{
  Number *n = new Number();
  n->setName("Result");
  n->setX(L->getX() - B->getX());
  n->setY(L->getY() - B->getY());
  nl.insertNumber (n);
  return n;

}



int cmain_loop(NumberList &nl) {

    string action;
    string fName;

    while (1) {

        cout<<"What would you like to do? Show, File, Pad, Read, Debug, Quit"<<endl;
        cin>>action;

        if (action == "show") {
            nl.showNumberList();
        }else if (action == "file") {
            cout<<"Enter file name"<<endl;
            cin>>fName;
            nl.showNumberList(fName);
            //writeToFile(fName, nl);
        }else if (action == "pad") {
            cout<<"Enter x"<<endl;
            int x;
            cin>>x;
            cout<<"Enter y"<<endl;
            int y;
            cin>>y;
            cowPad * cp = new cowPad();
            cp -> setxy(x,y);
            cp -> evalN(Lake -> getX(), Lake -> getY());
            cp -> evalS(Lake -> getX(), Lake -> getY());
            cp -> evalE(Lake -> getX(), Lake -> getY());
            cp -> evalW(Lake -> getX(), Lake -> getY());
            cp -> showPad();
        }else if (action == "read") {
            cout<<"Enter file name"<<endl;
            cin>>fName;
            nl.readFile(fName);
            Path = findDist(nl, Barn, Lake, Rock);
        }else if (action == "quit") {
            return 0;
        }
    }

    return 0;
}


int show_help() {
  cout<<"(h) help -> show this help"<<endl;
  cout<<"(a) add -> add a cow pad"<<endl;
  cout<<"(e) eval -> eval links to dest"<<endl;
  cout<<"(s) show -> show cowpads"<<endl;
  cout<<"(t) target -> set target dest"<<endl;
  cout<<"(q) quit -> quit"<<endl;

}

cowPad * g_cp = NULL;

int add_cowpad()
{
  cowPad * cp;
  cout<<"enter x location "<<endl;
  int x;
  cin>>x;
  cout<<"enter y location "<<endl;
  int y;
  cin>>y;
  cp = new cowPad(x,y);
  if(g_cp == NULL) {
    cp->next = NULL;
  } else {
    cp->next=g_cp;
  }
  g_cp = cp;

}

int show_cowpads()
{
  
  cowPad * cp = g_cp;
  while (cp) {
    cout<<"cp x  "<< cp->x;
    cout<<" cp y  "<< cp->y << endl;

    cp = cp->next;
  }

}

int main_loop(NumberList &nl) {

    string action;
    string fName;
    int done = 0;
    while (!done) {

        cout<<"What would you like to do? (h for help) "<<endl;
        cin>>action;

        if((action == "help") ||
	   (action == "h")){
	  show_help();
	}
	else if((action == "quit") ||
	   (action == "q")){

	  done = 1;
	}
	else if((action == "add") ||
	   (action == "a")){

	  add_cowpad();
	}
	else if((action == "show") ||
	   (action == "s")){

	  show_cowpads();
	}
    }
    return 1;
    
}

int main() {

    int rc;
    string val;
    NumberList nl;
    main_loop(nl);

return 0;

}
