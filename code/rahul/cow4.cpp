/* cow4
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

int g_clid = 1;
int g_cpid = 1;

class NumberList;

int writeToFile (string fileName, NumberList&nl) {
    ofstream myfile;
    myfile.open (fileName.c_str());
    myfile << "Writing this to a file.\n";
    myfile.close();
    return 0;
}





// this is where we do all the work
// actually not used at the moment
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
        if (pos != string::npos) {
            //Number*n = new Number();
            //n->setName("Barn");
            //n->setX(pos+1);
            //n->setY(row);
            //insertNumber (n);
            //Barn = n;
        }
        pos = line.find('R');
        if (pos != string::npos) {
            //Number*n = new Number();
            //n->setName("Rock");
            //n->setX(pos+1);
            //n->setY(row);
            //insertNumber (n);
            //Rock = n;

        }

        pos = line.find('L');
        if (pos != string::npos) {
            //Number*n = new Number();
            //n->setName("Lake");
            //n->setX(pos+1);
            //n->setY(row);
            //insertNumber (n);
            //Lake = n;
        }

    }

    return 0;

}



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
        id = g_clid++;

    };

    ~cowLink() {};
    double evalTarg(int tx, int ty);
    int id;
    int incX;
    int incY;
    int level;
    int value;
    double dist;
    cowPad * prev;
    cowPad * next;
    cowPad * addCowPad( cowPad * c);

};

// some class test code
int g_id = 1;
class Cow {
public:
  Cow() {
    next=NULL;
    name ="daisy";
    color = "blue";
    id = g_id++;
    cout << " Cow constructor id: "<< id
	 <<" name :" << name
	 << " color "<<color
	 << endl;
  }
  ~Cow() {
    cout << " Cow destructor id:" <<id
	 <<" name :" << name
	 << " color "<<color
      	 << endl;

  }
  virtual void showCow()
  {
    cout << " Cow showCow id: "<< id
	 <<" name :" << name
	 << " color "<<color
	 << endl;
  };
  Cow *next;
  string name;
  string color;
  int id;
};

class brownCow: public Cow {
public:
  brownCow() {
    color = "brown";
    cout << " brownCow constructor id: "<< id
	 <<" name :" << name
	 << " color "<<color
	 << endl;
  }
  ~brownCow() {
    cout << " brownCow destructor id:" <<id
	 <<" name :" << name
	 << " color "<<color
      	 << endl;
    
  }
 void showCow()
  {
    cout << " brownCow showCow id: "<< id
	 <<" name :" << name
	 << " color "<<color
	 << endl;
  };

};
class blackCow: public Cow {
public:
  blackCow() {
    color = "black";
    cout << " blackCow constructor id: "<< id
	 <<" name :" << name
	 << " color "<<color
	 << endl;
  }
  ~blackCow() {
    cout << " blackCow destructor id:" <<id
	 <<" name :" << name
	 << " color "<<color
      	 << endl;
    
  }
 void showCow()
  {
    cout << " blackCow showCow id: "<< id
	 <<" name :" << name
	 << " color "<<color
	 << endl;
  };

};

Cow * g_cows =  NULL;

void addCow( Cow * cow)
{
  //if(g_cows)
  // g_cows->next = cow;
  cow->next = g_cows;
  g_cows = cow; 
}

void showCows()
{
  cout << " Here are all the cows"<<endl;
  Cow * c = g_cows;
  while (c) {
    c->showCow();
    c = c->next;
  }
    
  
}

class cowPad {
public:

    cowPad( int xx = 0, int yy = 0) {
        //constructor called
        next = NULL;
	prev = NULL;
	
        N = NULL;//new cowLink(this, 0, -1);
        S = NULL;//new cowLink(this, 0, 1);
        E = NULL;//new cowLink(this, -1, 0);
        W = NULL;//new cowLink(this, 1, 0);
        x = xx;
        y = yy;
        //Nval = 99;
        //Sval = 99;
        //Eval = 99;
        //Wval = 99;
        level = 0;
        id = ++g_cpid;
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
    int id;

    cowPad *prev;
    cowPad *next;

    void setxy (int xn, int yn) {
        x = xn;
        y = yn;
    }

    void showPad () {
        cout<<"X is : "<<x<<" y is : "<<y<<endl;
	if (N || S) {
	  if (N)
	    cout<<"N->val is : "<<N->value;
	  if (S)
	    cout <<" S->val is : "<<S->value;
	  cout<<endl;
	}
	if (E || W) {
	  if (E)
	    cout<<"E->val is : "<<E->value;
	  if(W)
	    cout <<" W->val is : "<<W->value;
	  cout <<endl;
	}
    }


};

// run eval to an arbitrary target
double cowLink::evalTarg(int tx, int ty)
{
    double targ;
    int xx = prev->x + incX;
    int yy = prev->y + incY;
    targ=doubleDist(xx,tx,yy,ty);

};



double doubleDist( int x1, int x2, int y1, int y2)
{
    double d;
    d = sqrt(pow(x1-x2,2) + pow(y1-y2,2));
    return d;

}



int show_help() {
    cout<<"(h) help -> show this help"<<endl;
    cout<<"(l) lake -> add lake"<<endl;
    cout<<"(b) barn -> add barn"<<endl;
    cout<<"(r) rock -> add rock"<<endl;
    cout<<"(a) add -> add a cow pad"<<endl;
    cout<<"(e) eval -> eval links to dest"<<endl;
    cout<<"(s) show -> show cowpads"<<endl;
    cout<<"(p) picker -> run picker"<<endl;
    cout<<"(q) quit -> quit"<<endl;

}

#define MAX_LEVELS 32
cowPad * g_cp = NULL;
cowPad * g_pick = NULL;
cowPad * g_lake = NULL;
cowPad * g_barn = NULL;
cowPad * g_rock = NULL;
cowPad * g_levels[MAX_LEVELS];
cowPad * g_level = NULL;


cowPad*cowLink::addCowPad(cowPad * cp)
{
    cowPad *lp;
    next = new cowPad(prev->x + incX, prev->y + incY);
    next->level = prev->level+1;
    lp = g_levels[next->level];
    next->next = lp;
    g_levels[next->level]=next;

}



cowPad *add_cowpad()
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
    return cp;
}

cowPad * add_lake()
{
    cowPad * cp;
    cout<<"enter x location "<<endl;
    int x;
    cin>>x;
    cout<<"enter y location "<<endl;
    int y;
    cin>>y;
    cp = new cowPad(x,y);
    g_lake = cp;
    g_cp = g_lake;
    g_levels[0] = g_lake;
    g_lake->level = 0;
    return cp;
}

cowPad * add_barn()
{
    cowPad * cp;
    cout<<"enter x location "<<endl;
    int x;
    cin>>x;
    cout<<"enter y location "<<endl;
    int y;
    cin>>y;
    cp = new cowPad(x,y);
    g_barn = cp;
    return cp;
}

cowPad * add_rock()
{
    cowPad * cp;
    cout<<"enter x location "<<endl;
    int x;
    cin>>x;
    cout<<"enter y location "<<endl;
    int y;
    cin>>y;
    cp = new cowPad(x,y);
    g_rock = cp;
    return cp;
}

int set_level()
{
    cout<<"enter move level max(32) "<<endl;
    int x;
    cin>>x;
    if (x < MAX_LEVELS) g_level = g_levels[x];
    return x;

}

cowPad *picker();

// eval g_cp from this point to barn
int eval_cowpad ()
{
    cowPad *cp;
    cp = g_pick;
    if(!cp) {
        picker();
        cp=g_pick;
    }
    if(!cp) {
        cout << " picker found nothing" << endl;
        return 0;
    }
    double doubleDist( int x1, int x2, int y1, int y2);
    double e,w,n,s;
    string best = "";
    n = doubleDist(cp->x, g_barn->x, cp->y-1, g_barn->y);
    s = doubleDist(cp->x, g_barn->x, cp->y+1, g_barn->y);
    e = doubleDist(cp->x+1, g_barn->x, cp->y, g_barn->y);
    w = doubleDist(cp->x-1, g_barn->x, cp->y, g_barn->y);

    cout <<"dist North : " <<  n
         << endl;
    cout <<"dist South : " <<  s
         << endl;
    cout <<"dist East : " <<  e
         << endl;
    cout <<"dist West : " <<  w
         << endl;

    // disable things already evaluated
    if(cp->N) n = 100;
    if(cp->E) e = 100;
    if(cp->W) w = 100;
    if(cp->S) s = 100;
    best = "None";
    // simple test
    if ((cp->W == NULL) && (w<=n) && (w <= s) && (w <= e) ) {
        best = "West";
        cout << "adding cowpad " << best<<endl;
        cp->W = new cowLink(cp, -1, 0);
        cp->W->addCowPad(cp);
    }
    else if ((cp->E == NULL) && (e<=n) && (e <= s) && (e <= w) ) {
        best = "East";
        cout << "adding cowpad " << best<<endl;
        cp->E = new cowLink(cp, 1, 0);
        cp->E->addCowPad(cp);
    }
    else if ((cp->S == NULL) && (s<=n) && (s <=e) && (s <= w) ) {
        best = "South";
        cout << "adding cowpad " << best<<endl;
        cp->S = new cowLink(cp, 0, 1);
        cp->S->addCowPad(cp);

    }
    else if ((cp->N == NULL) && (n<=s) && (n <= e) && (n <= w) ) {
        best = "North";
        cout << "adding cowpad " << best<<endl;
        cp->N = new cowLink(cp, 0, -1);
        cp->N->addCowPad(cp);


    }
    cout <<"Best is : " << best << endl;
    cout <<"level : " << cp->level << endl;


}

cowPad *picker()
{
    cowPad *cp = NULL;
    //get the highest level with nodes left to allocate
    for (int i = 1 ; i <= MAX_LEVELS; i++) {
        cp = g_levels[MAX_LEVELS-i];
        if (cp) {
            while(cp) {
                if((!cp->N) ||(!cp->S)||(!cp->E)||(!cp->W)) {
                    cout << " found level : " << cp->level<<" node id: "<< cp->id << endl;
                    return cp;
                }

                cp = cp->next;
            }
        }
    }
    return cp;
}


int set_test()
{
    cowPad *cp = new cowPad(3,6);
    g_rock = cp;
    cp = new cowPad(3,3);
    g_barn = cp;

    cp = new cowPad(6,8);
    g_lake = cp;
    g_cp = g_lake;
    g_levels[0] = g_lake;
    g_lake->level = 0;

}

int run_picker()
{
    cowPad *cp = picker();
    g_pick = cp;
    return 0;
}

int show_cowpads()
{

    cowPad * cp = g_cp;
    if (g_lake) {
        cp = g_lake;
        cout<<"Lake  id:  "<< cp->id;
        cout<<"  x: "<< cp->x;
        cout<<" y: "<< cp->y << endl;
    }
    if (g_barn) {
        cp = g_barn;
        cout<<"Barn  id:  "<< cp->id;
        cout<<"  x: "<< cp->x;
        cout<<" y: "<< cp->y << endl;
    }
    if (g_rock) {
        cp = g_rock;
        cout<<"Rock  id:  "<< cp->id;
        cout<<"  x: "<< cp->x;
        cout<<" y: "<< cp->y << endl;
    }


    for (int i = 0 ; i < MAX_LEVELS; i++) {
        cp = g_levels[i];

        if (cp ) {
            cout << "level :" << i << endl;
        }

        while (cp) {
            cout<<"cp id:  "<< cp->id;
            cout<<"  x: "<< cp->x;
            cout<<" y: "<< cp->y << endl;

            cp = cp->next;
        }
    }

}

int main_loop(/*NumberList &nl*/) {

    string action;
    string fName;
    int done = 0;
    while (!done) {

        cout<<"What would you like to do? (h for help) "<<endl;
        cin>>action;

        if((action == "help") ||
                (action == "h")) {
            show_help();
        }
        else if((action == "quit") ||
                (action == "q")) {

            done = 1;
        }
        else if((action == "add") ||
                (action == "a")) {

            add_cowpad();
        }
        else if((action == "eval") ||
                (action == "e")) {

            eval_cowpad();
        }
        else if((action == "lake") ||
                (action == "l")) {

            add_lake();
        }
        else if((action == "barn") ||
                (action == "b")) {

            add_barn();
        }
        else if((action == "level") ||
                (action == "l")) {
            set_level();
        }
        else if((action == "rock") ||
                (action == "r")) {

            add_rock();
        }
        else if((action == "show") ||
                (action == "s")) {

            show_cowpads();
        }
        else if((action == "pick") ||
                (action == "p")) {

            run_picker();
        }
    }
    return 1;

}

int set_up_levels()
{
    for(int i = 0 ; i < MAX_LEVELS; i++) {
        g_levels[i] = NULL;
    }
    g_level = NULL;
    set_test();
}

int main() {

    int rc;
    string val;
    Cow cow;
    Cow *cowp;
    brownCow bcow;
    blackCow bkcow;
    cowp =&bcow;
    bcow.name = "belle";
    bkcow.name = "blackie";
    
    // show the base cow
    cow.showCow();
    // we use the overridden brown cow show even though its
    // a pointer to Cow
    cowp->showCow();

    addCow(&cow);
    addCow(&bcow);
    addCow(&bkcow);
    
    //NumberList nl;
    set_up_levels();

    main_loop(/*nl*/);

    showCows();
    return 0;

}
