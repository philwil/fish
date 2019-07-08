/* pump test code

 */


#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;



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
  cout<<" nothing to show"<<endl;
  return 0;
}

int main_help (void) {
  cout<<"(s)how  -- show current objects "<<endl;
  cout<<"(w)rite -- write current objects to file"<<endl;
  cout<<"(r)ead  -- read  objects from file"<<endl;
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
	  showList();
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

  //int rc;
  //string val;
  //NumberList nl;
    main_loop(NULL);

return 0;

}
