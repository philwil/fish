/* pump test code

 */


#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdint.h>

using namespace std;

#define PI 3.141

double sinTable[100];

class Pump {
public:
  Pump(){
    wHeight = 0.0;
    pumpon = 0;
    pumpcur = 0.0;
    
  }

  ~Pump(){
  }
  
  int showPump(void) {
    string pstate;
    if(pumpon) {
      pstate = " Running";
    } else {
      pstate = "Stopped";
    }
    cout << " Pump :" << pstate
      << " water level :"
      ;
    cout << wHeight;
    cout<< " Current : " << pumpcur
	<< endl;
    return 0;
  }
  
  int addWater ( double level) {
    wHeight += level;
  }
  
  int checkWater () {
    if(wHeight> 0.2) return 1 ;
    return 0;
  }
  double checkCurrent () {
    return pumpcur ;
  }
  
  int setPump (int on) {
    pumpon = on;
    return 0;
  }
  
  int runPump(double seconds) {
    while (seconds > 0.0) {
      seconds -= 0.1;
      if (pumpon) {
	wHeight -= 0.1;
      }
      if (wHeight < 0.0 ) {
	wHeight = 0.0;
      }
    
      if (wHeight > 0.1 ) {
	pumpcur = 2.0;
      } else {
	pumpcur = 0.0;
      }
    }
  }
    
  double wHeight;
  int pumpon;
  double pumpcur;
  
};

Pump * pump;

int fillTable( int num)
{
  for (int i = 0 ; i < num; i++) {
    sinTable[i] = sin( (2.0 * PI * i)/100.0);
  }
}

int writeFile(string fname)
{
  cout << " nothing to write"  << endl;
  return 0;
}

int readFile(string fName)
{
  
  fName += ".txt";
  fstream input(fName.c_str());
  cout << " running readFile [" << fName<<"]"<< endl ;
  string line;
  int row = 0;
  int idx = 0;
  
  while (getline (input, line)) {
    row++;
    cout <<" row :"<< row <<" data [" << line<<"]" << endl;
    
    idx = 0;
    size_t pos = 0;
	  
    pos = line.find('B');
    if (pos != string::npos){
      //Number*n = new Number();
      //    n->setName("Barn");
      //    n->setX(pos+1);
      //    n->setY(row);
      //    insertNumber (n);
      //    Barn = n;
    }

  }
  return 0;
}



int showList(void)
{
  int num = 100;
  fillTable(num);
  int i ;
  int val;
  for (i = 0 ; i < num; i++) {
    val = 40 + sinTable[i] * 40 ;
    for (int j = 0 ; j < val; j++) {   
      cout<<"#";
    }
    cout << endl;
  }
  return 0;
}


int main_help (void) {
  cout<<"(s)how  -- show current objects "<<endl;
  cout<<"(w)rite -- write current objects to file"<<endl;
  cout<<"(a)dd   -- add water to pump"<<endl;
  cout<<"(r)ead  -- read  objects from file"<<endl;
  cout<<"(t)urn  -- turn on / off pump"<<endl;
  cout<<"(d)ebug -- turn on / off debug"<<endl;
  cout<<"(q)uit  -- quit"<<endl;
  return 0;
}

int main_loop(void *nl) {

    string action;
    string fName;

    while (1) {

        cout<<"What would you like to do? (use help)"<<endl;
        cin>>action;

        if ((action == "help") 
	    || (action == "h")) {
	  //nl.
	  main_help();
	}else if ((action == "show") 
	    || (action == "s")) {
	  //nl.
	  pump->showPump();
	}else if ((action == "add")
		  || (action == "a")) {
	  cout<<"enter water level"<<endl;
	  double ps;
	  cin>>ps;
	  pump->addWater(ps);
	}
	else if ((action == "prun") 
		  || (action == "p")) {
	  cout<<"enter seconds"<<endl;
	  
	  double ps;
	  cin >> ps;
	  pump->runPump(ps);

	}else if ((action == "turn") 
	    || (action == "t")) {
	  cout<<"Enter on/off"<<endl;
	  string ps;
	  cin>>ps;
	  if( ps == "on" ) {
	    pump->setPump(1);
	  } else {
	    pump->setPump(0);
	  }

        }else if ((action == "write")
		  || (action == "w")) {

	  cout<<"Enter file name"<<endl;
	  cin>>fName;
	  //nl.
	  writeFile(fName);
            //writeToFile(fName, nl);
        }else if ((action == "read") 
		  || (action == "r")) {

	  cout<<"Enter file name"<<endl;
	  cin>>fName;
	  //nl.
	  readFile(fName);
	  //Path = findDist(nl, Barn, Lake, Rock);
        }else if ((action == "quit")
		  || (action == "q")) {
	  
	  return 0;
        }
    }

    return 0;
}


//int ma
int main() {
  pump = new Pump();
  
  //int rc;
  //string val;
  //NumberList nl;
    main_loop(NULL);

return 0;

}
