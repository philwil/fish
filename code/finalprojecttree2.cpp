
// look for the new knode (string word) constructor
// Rohan Sachdev
// Period 4A - Advanced CS
// Enloe High School - Mr. Potter
// 5-20-2019 (Due On: 5-21-2019)

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

int pleft = 0;
int pright = 0;

class KNode
{
private:
    char coordInCharge; // not int, we are dealing with characters (char)s
    int xcoor;
    int ycoor;
    KNode *right;
    KNode *left;

public:
    // Default Constructor
    KNode ()
    {
        coordInCharge = 'X';
        xcoor = 0;
        ycoor = 0;
        right = NULL;
        left = NULL;
    }

    KNode (int x, int y)
    {
        xcoor = x;
        ycoor = y;
        right = NULL;
        left = NULL;
    }

    KNode (string word)
    {
      int idx=0;
      int idxmax=word.length();
      int x = 0;
      int y = 0;
      int setneg = 1;
      if (word[idx] == '(') {
	idx++;
	if (word[idx] == '-') {
	  setneg = -1;
	  idx++;
	}
	while (word[idx] != ',') {
	  x= x * 10;
	  x += (word[idx] - '0');
	  idx++;
	}
	x = x * setneg;
	setneg = 1;
	idx++;
	if (word[idx] == '-') {
	  setneg = -1;
	  idx++;
	}
	
	while (word[idx] != ')') {
	  y = y * 10;
	  y += (word[idx] - '0');
	  idx++;
	}
	y = y * setneg;
	xcoor = x;
	ycoor = y;
	right = NULL;
	left = NULL;
      }
    }
  
    char getcoordInCharge()
    {
        return (coordInCharge);
    }

    void setcoordInCharge (char newData)
    {
        coordInCharge = newData;
    }

    KNode *getRight ()
    {
        return (right);
    }

    KNode *getLeft ()
    {
        return (left);
    }

    void setLeft (KNode *n, char coord)
    {
        cout<<"setLeft coord: "<<coord<<endl;
        left = n;
        if (coord == 'X')
        {
            left->setcoordInCharge('Y');
        }
        else
        {
            left->setcoordInCharge('X');
        }
    }

    void setRight (KNode *n, char coord)
    {
        cout<<"setRight coord: "<<coord<<endl;
        right = n;
        if (coord == 'Y')
        {
            right->setcoordInCharge('X');
        }
        else
        {
            right->setcoordInCharge('Y');
        }
        cout<<"Right coord: "<<right->getcoordInCharge()<<endl;
    }
    /*
    KNode (char d, KNode *KRight = NULL, KNode *KLeft = NULL)// BNode (char d = 0) is a default argument // BNode *n = 0
    {
        data = d;
        right = KRight;
        left = KLeft;
    }
    */
    void addNode (KNode *newNode);
    void print (KNode *indata, int option);
    int getXcoor();
    int getYcoor();
    void menu();
    // void potter();
    };

    // Global Variable
    KNode *root = NULL;

    int KNode::getXcoor()
    {
        return xcoor;
    }

    int KNode::getYcoor()

    {
        return ycoor;
    }

    void KNode::print (KNode *indata, int option)
    {
        if (indata->getLeft() != NULL) // if
        {
            pleft++;
            print(indata->getLeft(), option); // print  // getLeft, so we have a new root
        }
        if ((option == 1) || ((option == 2) && (indata->getcoordInCharge() == 'X')) || ((option == 3) && (indata->getcoordInCharge() == 'Y')))
        {
            cout<<"coordincharge: "<<indata->getcoordInCharge()<<" ("<<indata->getXcoor()<<","<<indata->getYcoor()<<")"; // cout
        }
        // cout<<"("<<indata->getXcoor()<<","<<indata->getYcoor()<<")"; // cout
        if (indata->getRight() != NULL) // if
        {
            pright++;
            print(indata->getRight(), option); // print // getRight != NULL, getLeft != NULL
        }
    };

    /*
    void BNode::potter() {
cout<<endl<<endl<<"Potter Test"<<endl;
cout<<"root: "<<root->getData()<<endl;
cout<<"rootsLeft Address: "<<root->getLeft()<<endl;
cout<<"rootsRight Value: "<<root->getRight()->getData()<<endl;
cout<<endl<<endl<<"check left count: "<<pleft<<endl<<"check right count: "<<pright<<endl<<endl;
cout<<"Insane Random Value: "<<root->getRight()->getLeft()->getLeft()->getLeft()->getLeft()->getData()<<endl;
cout<<"Insane address Value: ";
if (root->getLeft()->getRight() == NULL){
cout<<"Its just NULL"<<endl;
root->getLeft()->setRight(new BNode ('#', NULL, NULL));  //<---- May need to change "Bnode"
pleft = 0;
pright = 0;
print(root);
cout<<endl<<endl<<"check left count: "<<pleft<<endl<<"check right count: "<<pright<<endl<<endl;
cout<<endl;
}
else{
cout<<"Nothing Happens"<<endl;}
cout<<endl<<"DONE";
}
    */

    void KNode::addNode (KNode *newNode)
    {
        if (getcoordInCharge() == 'X')
        {
        cout<<" (newNode->getXcoor(): "<<newNode->getXcoor()<<" getXcoor()): "<<getXcoor()<<endl;
        if (newNode->getXcoor() > getXcoor())
        {
            if (getRight() == NULL)
            {
                setRight(newNode, getcoordInCharge()); // "this" means actual object you're running right now
            }
            else
            {
                getRight()->addNode(newNode);
            }
        }
        else
        {
            if (getLeft() == NULL)
            {
                setLeft(newNode, getcoordInCharge());
            }
            else
            {
                getLeft()->addNode(newNode);
            }
        }
        }
        else
        {
        cout<<"(newNode->getYcoor(): "<<newNode->getYcoor()<<" getYcoor()): "<<getYcoor()<<endl;
            if (newNode->getYcoor() > getYcoor())
            {
                if (getRight() == NULL)
                {
                setRight(newNode, getcoordInCharge()); // "this" means actual object you're running right now
                // If nothing to the right, setRight (newNode)
                }
                else
                {
                getRight()->addNode(newNode); // if something to the right, repeat using getRight as root
                }
            }
            else
            {
                if (getLeft() == NULL)
                {
                    setLeft(newNode, getcoordInCharge());
                }
                else
                {
                    getLeft()->addNode(newNode);
                }
            }
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


void KNode::menu ()
{
    // 1, 2, or 3 to insert, print, or quit
    // for i = 0, i > -1, i++
    int choice;
    string word;
    int xcoor;
    int ycoor;
    char coord;
    while (true) // while (! done)
    {
    cout<<"Choose 1, 2, or 3 to -> 1. Insert a new coordinate , 2. Print the tree, or 3. Exit the program, respectively. : "<<endl;
    cin>>choice;
    if (choice == 1)
    {
        // Insert a new coordinate
        cout<<"Please input a coordinate: (x,y)"<<endl;
        cin>>word;
        //cout<<"Please input a Y coordinate: "<<endl;
        //cin>>ycoor;
        if (root == NULL)
        {
            cout<<"Please input the coordinate to set priority to for the root node - either 'X' or 'Y'"<<endl;
            cin>>coord;
            root = new KNode(word);
            root->setcoordInCharge(coord);
        }
        else
        {
            root->addNode(new KNode(word));
        }
    /*
    if (word == "quit")
    {
        return;
    }
    */
    // if (! word.empty())
    // {
    // root = NULL; // eliminates the previous list
    // for (int i = 0; i < word.length(); i++)
    // {
    // KNode *n;
    // n = new BNode(word[i]);
    // n = new KNode (word[i]);
    // This should have  1 parameter
    // first parameter
    // if (root == NULL)
    // {
    //     root = n;
    // }
    // else
    // {
    //     root->addNode(n);
    // }
    // }
    // }
    }

    else if (choice == 2)
    {
        int option;
        //cout<<"Select print option: "<<endl;
        //cout<<"1) Print the coordinates based on the normal binary tree algorithm: "<<endl;
        //cout<<"2) Print the coordinates based on the normal Binary Tree that only have x-coordinate priority"<<endl;
        //cout<<"3) TBD"<<endl;
        //cin>>option;
    // Print the Tree
    if (root != NULL)
    {
      for (option = 1 ; option <= 3; option++) {
	cout<<endl;
	root->print(root, option);
	// potter();
	cout<<endl;
      }
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
        // Quit: Exit The Program
        cout<<"-----QUIT: Exit The Program-----"<<endl;
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
    KNode k; // the b is just a dummy object to get to the menu function
    // With the default constructor, don't need anything after BNode b; also don't set particular constructor = 0
    // BNode or Bnode / getValue or getData
    k.menu();
    return 0;
    // 208, 128, 88
}
