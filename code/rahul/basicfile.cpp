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
        string cell[24];
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

#if 0
int addNumber(NumberList &nl) {

    Number*n = new Number();

    long int Number;
    cout<<"Enter first number"<<endl;
    cin>>Number;
    n->setNumber1(Number);

    if (Number > 0) {
        cout<<"Enter second number"<<endl;
        cin>>Number;
        n->setNumber2(Number);

        }

    n->setNumber3(n->addNumbers());

    cout<<"The sum of " <<n->Number1<< " and " <<n->Number2<< " is "<<n->Number3<< endl;
    nl.insertNumber (n);


    return 0;

}

#endif

Number * findDist(NumberList &nl, Number * B, Number *L, Number * R)
{
  Number *n = new Number();
  n->setName("Result");
  n->setX(L->getX() - B->getX());
  n->setY(L->getY() - B->getY());
  nl.insertNumber (n);
  return n;
  
}

int main_loop(NumberList &nl) {

    string action;
    string fName;

    while (1) {

        cout<<"What would you like to do? Show, File, Read, Debug, Quit"<<endl;
        cin>>action;

        if (action == "show") {
            nl.showNumberList();
        }else if (action == "file") {
            cout<<"Enter file name"<<endl;
            cin>>fName;
            nl.showNumberList(fName);
            //writeToFile(fName, nl);
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




int main() {

    int rc;
    string val;
    NumberList nl;
    main_loop(nl);

return 0;

}
