// Rohan Sachdev - 4A - Advanced CS - Enloe High School - Mr. Potter - 4-30-2019
#include <iostream>
using namespace std;
int pleft = 0;
int pright = 0;

class ENode
{
private:
    char data; // not int, we are dealing with characters (char)s
    ENode *right; // ListNode *next;
    ENode *left; // ListNode *next;
    int value;

public:

    ENode (char d, char r = 0, char l= 0)// BNode (char d = 0) is a default argument // BNode *n = 0
    {
        data = d;
        if (r)
            right = new ENode(r);
        if (l)
            left = new ENode(l);
        if (isOperator())
        {
            value = TurnIntoValue();
        }
    }

    ENode ()  // Default Constructor
    {
        data;
        right = NULL;
        left = NULL;
    }

    char getValue () // getData
    {
        return (data);
    }

    void setValue (char newValue) // setData (char newData)
    {
        data = newValue;
    }

    ENode *getRight ()
    {
        return (right);
    }

    ENode *getLeft ()
    {
        return (left);
    }


    void setLeft (ENode *n)
    {
        left = n;
    }

    void setRight (ENode *n)
    {
        right = n;
    }

    void addNode (string & str, int & index);
    void print (ENode *indata);
    void menu();
    int isOperator();
    int TurnIntoValue();
    };

    class ETree
    {
        void PrintAnswer(void); // New Method in ETree
        void Evaluate(ENode *); // New Method in ETree
    };

    ENode *root = NULL; // Global Variable

    int ENode::isOperator (void)
    {
    int v = 0;
    if (data == '+')
    {
        v = 1;
    }
    else if (data == '-')
    {
        v = 1;
    }
    else if (data == '*')
    {
        v = 1;
    }
    return v;
    }

    int ENode::TurnIntoValue (void)
    {
        int v = 0;
        v = data - '0';
        return v;
    }

    void ENode::print (ENode *indata) // stats the same for ENode
    {
        if (indata->getLeft() != NULL) // if
        {
            pleft++;
            print(indata->getLeft()); // print  // getLeft, so we have a new root
        }
        cout<<indata->getValue(); // cout
        if (indata->getRight() != NULL) // if
        {
            pright++;
            print(indata->getRight()); // print // getRight != NULL, getLeft != NULL
        }
    };
// we add chars to this structure one at a time and we create a node from them and use a global index/counter to get next value
    void ENode::addNode (string & str, int & index)
    {
        cout<<"Data is: "<<data<<endl;
        if (index >= str.length())
        return;
        index += 1; // loop
        if (isOperator()) // if operator incrementing index and adding new node
            // if not operator still need to increment index (present letter), so index += 1 anyways
        {
            ENode *l = new ENode(str[index]); // Increments index by 1
            setLeft(l);
            l->addNode(str, index); // recursive call
            ENode *r = new ENode(str[index]); // Increments index by 1
            setRight(r);
            r->addNode(str, index); // recursive call
        }
    };

        /*
        old addNode
        if (newNode->getData() <= getData())
        {
            if (getLeft() == NULL)
            {
                setLeft(newNode); // "this" means actual object you're running right now
            }
            else
            {
                getLeft()->addNode(newNode);
            }
        }
            else
            {
            if (getRight() == NULL)
            {
                setRight(newNode); // "this" means actual object you're running right now
                // If nothing to the right, setRight (newNode)
            }
            else
            {
                getRight()->addNode(newNode); // if something to the right, repeat using getRight as root
            }
            }
            */

void ENode::menu ()
{
    int choice;
    int index = 0;
    string word;
    while (true) // while (! done)
    {
    cout<<"Choose 1, 2, or 3 to ----> 1. insert, 2. print, or 3. quit, respectively. : "<<endl;
    cin>>choice;
    if (choice == 1) // Insert
    {
        cout<<"Please input an expression to be inserted: "<<endl;
        cin>>word;
        cout<<endl;
    if (! word.empty())
    {
    root = NULL; // eliminates the previous list
    root = new ENode(word[0]);
    root -> addNode(word, index);
    }
    }
    else if (choice == 2) // Print
    {
    cout<<"Printing root: "<<root->getValue()<<endl;
    cout<<"print root left: "<<root->getLeft()->getValue()<<endl;
    cout<<"print root right: "<<root->getRight()->getValue()<<endl;
    if (root != NULL)
    {
    cout<<endl;
    root->print(root);
    cout<<endl;
    }
    }

    else if (choice == 3) // Quit
    {
        cout<<"Quit"<<endl;
        return;
    }
    }
    }

void ETree::PrintAnswer(void)
{
    if (root == NULL)
    {
        cout<<"No Tree = No Answer"<<endl;
    }
    else
    {
        Evaluate(root);
        cout<<"The answer is: "<<root->getValue()<<endl;
        cout<<"Done.";
    }
}

void ETree::Evaluate(ENode *n)
{
    return;
}

int main ()
{
    ENode e;
    e.menu();
    return 0;
}

