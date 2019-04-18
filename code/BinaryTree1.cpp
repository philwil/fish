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
    BNode (char d)
    {
        data = d;
        right = NULL;
        left = NULL;
    }

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

    void addNode (BNode *root, BNode *newNode)
    {
        if (newNode->getData() <= root->getData())
        {
            if (root->getLeft() == NULL)
            {
                root->setLeft(newNode); // "this" means actual object you're running right now
            }
            else {
                    addNode(root->getLeft(), newNode);
                 }
        }
            else
            {
            if (root->getRight() == NULL)
            {
                root->setRight(newNode); // "this" means actual object you're running right now
            }
            else
            {
                addNode(root->getRight(), newNode);
            }
            }
    };

void printNode (BNode *root, void *indata)
{
    if (root->getLeft() != NULL) // if
        printNode(root->getLeft(), indata); // print
    cout<<root->getData(); // cout
    if (root->getRight() != NULL) // if
        printNode(root->getRight(), indata); // print
};
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

// Global Variable
BNode *root = NULL;

void menu ()
{
    // 1 2 3 or 4 to insert print delete or quit
    // for i = 0, i > -1, i++
    string word;
    while (true) // while (! done)
    {
    cout<<"Enter a word (quit to stop): "<<endl;
    cin>>word;
    if (word == "quit")
    {
        return;
    }
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
        root->addNode(root, n);
    }
    }
    root->printNode(root, NULL);
    cout<<endl;
    root = NULL;
    }
    return;
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
    //l.print(); // prints the values; doesn't sort things
    menu();
    return 0;
}
