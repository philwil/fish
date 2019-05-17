// Rohan Sachdev - 4A - Advanced CS - Enloe High School - Mr. Potter - 4-30-2019
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int pleft = 0;
int pright = 0;
// Get Division by 0 and negatives for a total of 10% more (5% each)
/*
Rubric ->
- 70%: +, -, *
- 5% for int division OR 10% for double division
- 5% for negative numbers
- 20% for 30 minutes add-on
----------->>>>>
Days to Possibly Check On:
1. Monday Lunch (Likely day to check on)
2. Tuesday Class (Hardest one)
3. Friday Lunch (Most likely day to check on)
*/
// Line 178 has cout<<"Data is:"<<data<<endl;
// Previous add-on operators: A on Thursday and B on Friday

// :passing an address when you do recursion, just like binary (binary code)
// 2 other possible operators:
// division to 3 decimal places
// ^ (carrot symbol for exponents)
// check left, physically called print, check right
// using recursion based on a memory address, but not the string
// 1st thing being passed is root, if root = NULL then root is str[0]
// Rules for an ETree: if data = operator, then place left, and place right automatically
// if lefts' side operator?: place left, place right
// basis of recursion: calling the same exact algorithm, with the same exact steps

/*
if (data == operator)
{
place left
if (left == operator)       // if (left side is operator?)
{
place left
place right
}
place right
if (right == operator)      // if (right side is operator?)
{
place left
place right
}
*/

class ENode
{
private:
    char data; // not int, we are dealing with characters (char)s
    ENode *right; // ListNode *next;
    ENode *left; // ListNode *next;

public:
    int value;
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

    ENode (string & str, int & index)
    {
        data = str[index];
        int setNeg = 1;
        if (str[index] == '(')
        {
            index += 1;
            if (str[index] == '-')
            {
                index += 1;
                setNeg = -1;
            }
            data = str[index];
            index += 1;
            if (str[index] == ')')
            {
                index += 1;
            }
        }
        else
        {
            index += 1;
        }
        cout<<"data "<<data<<endl;
        value = TurnIntoValue() * setNeg;
        cout<<"value "<<value<<endl;
    }

    char getValue () // getData
    {
        return (data); // not data, since data was the raw character (the  from the string, so setNeg was done on value)
    }

    void setValue (char newValue) // setData (char newData)
    {
        data = newValue;
        value = TurnIntoValue();
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
        public:
        void PrintAnswer(void); // New Method in ETree
        double Evaluate(ENode *n); // New Method in ETree
    };

    ENode *root = NULL; // Global Variable

    int ENode::isOperator (void)
    {
    int v = 0;
    if (data == '+')
    {
        v = 1; // returning v, which tells us it is an operator
    }
    else if (data == '-')
    {
        v = 1;
    }
    else if (data == '*')
    {
        v = 1;
    }
    else if (data == '/')
    {
        v = 1;
    }
    // else if (data == '^')
    // {
    //    v = 1;
    // }
    else
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
        // cout<<"Data is: "<<data<<endl;
        if (index >= str.length())
        return;
        if (isOperator()) // if operator incrementing index and adding new node
            // if not operator still need to increment index (present letter), so index += 1 anyways
        {
            ENode *l = new ENode(str, index); // Increments index by 1
            cout<<"Index 1: "<<index<<endl;
            setLeft(l);
            l->addNode(str, index); // recursive call
            cout<<"Index 2: "<<index<<endl;
            ENode *r = new ENode(str, index); // Increments index by 1
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
    cout<<"Choose 1, 2, 3, or 4 to ----> 1. insert, 2. print, 3. Evaluate, or 4. quit, respectively. : "<<endl;
    cin>>choice;
    if (choice == 1) // Insert
    {
        cout<<"Please input an expression to be inserted: "<<endl;
        cin>>word;
        cout<<endl;
        index = 0;
    if (! word.empty())
    {
    root = NULL; // eliminates the previous list
    root = new ENode(word, index);
    cout<<"Index = "<<index<<endl;
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
    else if (choice == 3) // Evaluate
    {
        ETree ET;
        double v = ET.Evaluate(root);
        cout<<setprecision(4)<<"Evaluate: "<<v<<endl;
        cout<<endl;
    }
    else if (choice == 4) // Quit
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

double ETree::Evaluate(ENode *n)
{
    double v = 0;
    if (n != NULL) // Don't break the program with bad input
    {
        if (n -> isOperator())
        {
            if (n->getValue() == '+')
            {
                double v1 = Evaluate(n->getLeft());
                double v2 = Evaluate (n->getRight());
                // cout<<"v1 = "<<v1<<" v2 = "<<v2<<endl;
                v = Evaluate(n->getLeft()) + Evaluate(n->getRight());
            }
            else if (n->getValue() == '-')
            {
                v = Evaluate(n->getLeft()) - Evaluate(n->getRight());
            }
            else if (n->getValue() == '*')
            {
                v = Evaluate(n->getLeft()) * Evaluate(n->getRight());
            }
            else if (n->getValue() == '/')
            {
                double divide = Evaluate(n->getRight());
                if (fabs(divide) > 0.0000000001)
                    {
                        double d = (double) Evaluate(n->getLeft()) / (double) divide;
                        // cout<<"d: "<<d<<endl;
                        v = d;
                    }
                else
                {
                    cout<<"Error: Division By Zero"<<endl;
                    v = 0;
                }
            }
           // else if (n->getValue() == '^')
          //  {
              //  double d = (double) pow((double) Evaluate(n->getLeft()), (double) Evaluate(n->getRight()));
              //  v = d;
            //}
        }
        else
        {
            v = (double) n->value; // Converting char (data) to number
        }
    }
    return v;
}
// Lines 147-150, 317 - 321 are for exponent (^)
int main ()
{
    ENode e;
    e.menu();
    return 0;
}
