#include <iostream>
#include <fstream>

using namespace std;


class Word {
public:

    Word(){
        prev = NULL;
        next = NULL;

    };


    ~Word();


    void show () {

        cout<<"Word is ["<<wd<<"]"<<endl;

    };

    string wd;
    Word*prev;
    Word*next;


};


Word*words = NULL;


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
    Word*w1 = words;   //Start the list
    Word*w = words;    //Iterator


    while (w) {
        myfile <<w->wd<<endl;
        w = w->next;
        if (w == w1) {
            w = NULL;
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

    if (words == NULL) {
        words = w;
        w->next = w;
        w->prev = w;
    } else {
        Word*head;
        Word*tail;
        head = words;
        tail = words->prev;
        w->next = head;
        w->prev = tail;
        tail->next = w; //head
        head->prev = w; //tail
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

    Word*w1 = words;   //Start the list
    Word*w = words;    //Iterator
    while (w) {
        w->show();
        w = w->next;
        if (w == w1) {
            w = NULL;
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
