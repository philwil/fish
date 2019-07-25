/* Lists demo
 */

#include <iostream>
#include <fstream>

using namespace std;


class List {
public:

  List(){
    prev = NULL;
    next = NULL;
    
  };
  
  
  ~List();
  
  void addList(List **h, List*l);
  
  
    List*prev;
    List*next;
    void *item;


};

void List::addList(List **h, List*l) {

    if (*h == NULL) {
        *h = l;
        l->next = l;
        l->prev = l;
    } else {
        List*head;
        List*tail;
        head = *h;
        tail = head->prev;
        l->next = head;
        l->prev = tail;
        tail->next = l; //head
        head->prev = l; //tail
    }
}


class Word {
public:

    Word(){
      wd = "";
    };


    ~Word();


    void show () {

        cout<<"Word is ["<<wd<<"]"<<endl;

    };

  List *list;
    string wd;

};



List *words = NULL;


Word*makeWord () {

    string input;
    Word*w;
    cout<<"Enter word"<<endl;
    cin>>input;
    w = new Word();
    w->wd = input;

    return w;
}


int writeToFile () {
    string fName;
    cout<<"Enter file name"<<endl;
    cin>>fName;
    fName += ".txt";
    ofstream myfile;

    myfile.open (fName.c_str());
    List*l1 = words;   //Start the list
    List*l = words;    //Iterator
    Word * w;

    while (l) {
      w = (Word *)l->item;
        myfile <<w->wd<<endl;
        l = l->next;
        if (l == l1) {
            l = NULL;
        }
    }


    myfile.close();
    return 0;
}


void addWord (Word*w);


int readFile() {
    string fName;
    cout<<"Enter file name"<<endl;
    cin>>fName;
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
        Word*w = new Word();
        w->wd = line;
        addWord(w);
        idx = 0;
        size_t pos = 0;

        pos = line.find('B');
        if (pos != string::npos){
            //Number*n = new Number();
            //n->setName("Barn");
            //n->setX(pos+1);
            //n->setY(row);
            //insertNumber (n);
            //Barn = n;
        }

        pos = line.find('R');

        if (pos != string::npos){
            //Number*n = new Number();
            //n->setName("Rock");
            //n->setX(pos+1);
            //n->setY(row);
            //insertNumber (n);
            //Rock = n;

        }

        pos = line.find('L');

        if (pos != string::npos){
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

void addWord(Word*w) {
    List *l = new List();
    l->item = w;
    
    if (words == NULL) {
        words = l;
        l->next = l;
        l->prev = l;
    } else {
        List*head;
        List*tail;
        head = words;
        tail = head->prev;
        l->next = head;
        l->prev = tail;
        tail->next = l; //head
        head->prev = l; //tail
    }
}

void addWord () {
    Word*w = makeWord();
    addWord(w);
}

void showWord () {
/*
    if (words == NULL) {
        cout<<"There are no words"<<endl;
    }
*/
  Word * w;
    List*l1 = words;   //Start the list
    List*l = words;    //Iterator
    while (l) {
      w = (Word *)l->item;
        w->show();
        l = l->next;
        if (l == l1) {
            l = NULL;
        }
    }
}

void showHelp () {
    cout<<"(h) or help"<<" show help"<<endl;
    cout<<"(q) or quit"<<" quit"<<endl;
    cout<<"(w) or word"<<" write to file"<<endl;
    cout<<"(a) or add"<<" add a word"<<endl;
    cout<<"(s) or show"<<" show a word"<<endl;
    cout<<"(r) or read"<<" read a file"<<endl;
}

int mainLoop() {
    while (1) {
        cout<<"What do you want to do?"<<" Press h for help"<<endl;
        string input;
        cin>>input;
        if ((input == "h") || (input == "help")) {
            showHelp();
        } else if (input == "w") {
            writeToFile();
        } else if (input == "a") {
            addWord();
        } else if (input == "s") {
            showWord();
        }else if (input == "r") {
            readFile();
        }else if (input == "q") {
            return 0;
        }
    }
}

int main() {
    mainLoop();
    return 0;

}
