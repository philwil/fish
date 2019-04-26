// Rohan Sachdev
// Period 4A - Advanced CS
// Enloe High School - Mr. Potter
// 4-10-2019 (Due On 4-26-2019)

/*
Notes:
3 Simple Steps On How To Print A Binary Tree:
1.) Check Left
2.) Print
3.) Check Right
Keep on doing this when you encounter another letter in the string, and do this process for each node, using recursion
There should be no nexts like getNext or setNext, it is rights and lefts this time, NO NEXTS
It's easier to say "not nothing" there than something (when referring to things / letters to the left / right of a node
***Use RECURSION (Recursive Calls)***
**PRINT SHOULD HAVE A PARAMETER**
5 lines of code, 3 semicolons in the print
It is an if statement (checkleft)
Print must have a parameter
Print:
if statement
    recursive call;
cout<< ;
if statement
recursive call;
*/

#include <iostream>

using namespace std;

class BNode
{
private:
    char data; // not int, we are dealing with characters (char)s
    // ListNode *next;
    BNode *right;
    BNode *left;

public:
    BNode (char d = 0)// BNode (char d = 0) is a default argument
    {
        data = d;
        right = NULL;
        left = NULL;
    }

    // Default Constructor
    /*
    BNode ()
    {
        data = 0;
        right = NULL;
        left = NULL;
    }
    */

    char getData ()
    {
        return (data);
    }

    void setData (char newData)
    {
        data = newData;
    }

    BNode *getRight ()
    {
        return (right);
    }

    BNode *getLeft ()
    {
        return (left);
    }


    void setLeft (BNode *n)
    {
        left = n;
    }

    void setRight (BNode *n)
    {
        right = n;
    }

    void addNode (BNode *newNode);
    void printNode (void *indata);
    void menu();
    };

    // Global Variable
    BNode *root = NULL;

    void BNode::printNode (void *indata)
    {
        if (getLeft() != NULL) // if
            getLeft()->printNode(indata); // print  // getLeft, so we have a new root
        cout<<getData(); // cout
        if (getRight() != NULL) // if
            getRight()->printNode(indata); // print // getRight != NULL, getLeft != NULL
    };

    void BNode::addNode (BNode *newNode)
    {
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
/*
void print4Node (BNode *root, void *indata)
{
    if (root != NULL)
        {// if
        print4Node(root->getLeft(), indata); // print
        cout<<root->getData()<<endl; // cout
        print4Node(root->getRight(), indata);
        } // print
};
*/
};

void BNode::menu ()
{
    // 1, 2, or 3 to insert, print, or quit
    // for i = 0, i > -1, i++
    int choice;
    string word;
    while (true) // while (! done)
    {
    cout<<"Choose 1, 2, or 3 to ----> 1. insert, 2. print, or 3. quit, respectively. : "<<endl;
    //cin.getline(choice);
    cin >> choice;
    cin.ignore();
    if (choice == 1)
    {
        // Insert
        cout<<"Please input a word to be inserted: "<<endl;
        getline(cin,word);
        cout<<endl;
    /*
    if (word == "quit")
    {
        return;
    }
    */
    if (! word.empty())
    {
    root = NULL; // eliminates the previous list
    for (int i = 0; i < word.length(); i++)
    {
    BNode *n;
    n = new BNode(word[i]);
    if (root == NULL)
    {
        root = n;
    }
    else
    {
        root->addNode(n);
    }
    }
    }
    }

    else if (choice == 2)
    {
        // Print
    if (root != NULL)
    {
    cout<<endl;
    root->printNode(NULL);
    cout<<endl;
    }

    /*
    else
    {
        cout<<"Empty List"<<endl;
    }
`   */

    }

    else if (choice == 3)
    {
        // Quit
        cout<<"Quit"<<endl;
        return;
    }
    }
}

/*
void List::print() // Print should have a parameter
{
if ()
print (curr?);
cout<<current->getData();
if ()
print (curr?);
}
*/

int main ()
{
    // shesellseashellsdownbytheseashore
    //l.print(); // prints the values; doesn't sort things
    //cout<<print->getLeft()->getLeft()->getLeft()->getLeft()->getRight()<<endl;
    //List l;
    // l.menu();
    BNode b; // the b is just a dummy object to get to the menu function
    // With the default constructor, don't need anything after BNode b; also don't set particular constructor = 0
    b.menu();
    return 0;
}
