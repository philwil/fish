#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


int g_debug = 0;

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

    Number1 = n.Number1;
    Number2 = n.Number2;
    Number3 = n.Number3;
  }
    /* end of new code */

    void setNumber1(long int n){
        Number1 = n;
    };
    void setNumber2(long int n){
        Number2 = n;
    };
    void setNumber3(long int n){
    Number3 = n;
    };

    long int addNumbers() {
    return Number1 + Number2;
    }

    void showNumber() {
        cout<<" "<<Number1<<" "<<Number2<<" "<<Number3<<endl;
    }
    void showHeader() {
        cout<<" Position : "<<"Number 1 : "<<" Number 2 : "<<" Sum : "<<endl;
    }
    void showNumber(ofstream &myfile) {
        myfile<<" "<<Number1<<", "<<Number2<<", "<<Number3<<endl;
    }
    void showHeader(ofstream &myfile) {
        myfile<<" Number 1, "<<" Number 2, "<<" Sum "<<endl;
    }


    long int Number1;
    long int Number2;
    long int Number3;
    Number*next;
};

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

            cout<<"Position " <<i++<< " is";
            nn -> showNumber();
            nn = nn -> next;
        }


    }

    int readFile(string fName) {

        fName += ".csv";
        fstream input(fName.c_str());
        string cell[3];
    int idx = 0;

        while (getline (input, cell[idx], ',')) {

            if(cell[idx].find("\n") == string :: npos) {
                cout<<"Cell = ["<<cell[idx]<<"]"<<endl; idx+=1;
            }else {
                cout<<"Found cr in ["<<cell[idx]<<"]"<<endl;
                size_t pos = cell[idx].find("\n");

                string ctemp = cell[idx];
                string cell[idx] = ctemp.substr(0,pos);

                cout<<"Found number "<<" cell[0] : "<<cell[0]<<" cell[1] : "<<cell[1]<<" cell[2] : "<<cell[2]<<endl;
                idx = 0;
                cell[idx] = ctemp.substr(pos+1); idx+=1;

                /*
                std::string str2 = str.substr (3,5);     // "think"

                std::size_t pos = str.find("live");      // position of "live" in str

                std::string str3 = str.substr (pos);     // get from "live" to the end

                std::cout << str2 << ' ' << str3 << '\n';
                */
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


int main_loop(NumberList &nl) {

    string action;
    string fName;

    while (1) {

        cout<<"What would you like to do? Add, Show, File, Read, Debug, Quit"<<endl;
        cin>>action;

        if (action == "add") {
            addNumber(nl);
        }else if (action == "show") {
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
