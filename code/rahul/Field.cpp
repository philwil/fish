
#include <iostream>
#include <fstream>
using namespace std;
class Field;
class Line;
class Char {
public:
  Char() {
    c  = ' ';
    next = NULL;
    prev = NULL;
  };
  ~Char() {};
  
  int append(Line *l, Char *cp);
  
  Char * next;
  Char * prev;
  char c;

};


class Line {
public:
  Line() {
    line = "";
    chars = NULL;
    next = NULL;
    prev = NULL;
  };
  ~Line() {};
  int addChars(string lc);
  int append(Field *f, Line *lp);
  Char * getChar(int num);
  
  Line * next;
  Line * prev;
  Char * chars;
  string line;
};


class Field {
public:
  Field(){
    lines = NULL;
  };
  ~Field(){};
  Line *lines;
  int showLine(int num);
  Line * getLine(int num);
  int addLine(string l) {
    Line * lp;
    lp = new Line();
    lp->line = l;
    lp->addChars(l);

    lines->append(this, lp);   
      
  };
  
};


int Field::showLine(int num) {
  Line * l = getLine(num);
  if(l)
    cout << " Line [" <<l->line<<"]" << endl;
  return 0;
};


Line * Field::getLine(int num) {
  Line * l;
  if (lines == NULL) {
    cout<< "no lines try read " << endl;
    return NULL;
  }
  l = lines;
  while (num) {
    l = l->next;
    if (l == lines) {
      cout << " Number too large" << endl;
      return NULL;
    }
    num--;
  }

  return l;
};

Char * Line::getChar(int num) {
  Char * cp;
  if (chars == NULL) {
    cout<< "no chars try read " << endl;
    return NULL;
  }
  cp = chars;
  while (num) {
    cp = cp->next;
    if (cp == chars) {
      cout << " Number too large" << endl;
      return NULL;
    }
    num--;
  }

  return cp;
};


int Char::append(Line *l, Char *cp) {
  if ( l->chars == NULL) {
    cp->next = cp;
    cp->prev = cp;
    l->chars = cp;
  } else {
    Char * head = l->chars;
    Char * tail = l->chars->prev;
    cp->next = head;
    cp->prev = tail;
    tail->next = cp;
    head->prev = cp;
  }
  return 0;  
};

int Line::addChars(string lc) {
  for (int i = 0 ; i < lc.length(); i++) {
    Char *cp = new Char();
    cp->c = lc[i];
    chars->append(this, cp);     
    
  }
  return 0;  
    
};

int Line::append(Field *f, Line *lp) {
  if ( f->lines == NULL) {
    lp->next = lp;
    lp->prev = lp;
    f->lines = lp;
  } else {
    Line * head = f->lines;
    Line * tail = f->lines->prev;
    lp->next = head;
    lp->prev = tail;
    tail->next = lp;
    head->prev = lp;
  }
  return 0;  
    
};


Field g_f;

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
	g_f.addLine(line);
	
        //for (int i = 0 ; i < line.length() ; i++) {
	//  int num = (int) line[i];
	//  cout << ":"<<line[i]<<":" << num << endl; 
	//}
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
    cout<<"(s) show -> show a line"<<endl;
    cout<<"(c) char -> show a char"<<endl;
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
  
int show_line() {
  int num;
  cout << " Enter Line Number : ";
  cin >>num;
  g_f.showLine(num);
  return 0;
}

int show_char() {
  int num;
  cout << " Enter Line Number : ";
  cin >>num;
  Line *l = g_f.getLine(num);
  if (l) {
    cout << " Enter Char Number : ";
    cin >>num;
    Char *c = l->getChar(num);
    if (c) {
      cout << "Char [" << c->c << "]"<< endl;
      
    }
  }
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
        else if((action == "show") ||
                (action == "s")) {

	  show_line();
        }
        else if((action == "char") ||
                (action == "c")) {

	  show_char();
        }
    }
    return 1;

}


int main() {


    main_loop();


    return 0;

}
