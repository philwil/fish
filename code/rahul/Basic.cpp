
#include <iostream>
#include <fstream>
using namespace std;


int writeToFile (string fileName/*, NumberList&nl*/) {
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
        for (int i = 0 ; i < line.length() ; i++) {
	  int num = (int) line[i];
	  cout << ":"<<line[i]<<":" << num << endl; 
	}
        //idx = 0;
        //size_t pos = 0;
        //pos = line.find('L');
        //if (pos != string::npos) {
            //cowPad*c = new cowPad();
            //c->setName("Lake");
            //c->setX(pos+1);
            //c->setY(row);
            ////insertNumber (n);
            //g_lake = c;
        //}
    }
    return 0;
}


int show_help() {
    cout<<"(h) help -> show this help"<<endl;
    cout<<"(r) read -> read a file"<<endl;
    cout<<"(q) quit -> quit"<<endl;
    return 0;
}

int read_file() {
  string fname;
  cout << " Enter File name : ";
  cin >>fname;
  readFile(fname);
  return 0;
}
  

int main_loop() {

    string action;
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
        else if((action == "read") ||
                (action == "r")) {

	  read_file();
        }
    }
    return 1;

}


int main() {


    main_loop();


    return 0;

}
