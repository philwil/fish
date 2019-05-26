// Rohan Sachdev
// Period 4A - Advanced CS
// Enloe High School - Mr. Potter
// 5-20-2019 (Due On: 5-21-2019)
// Line 160, Line 178, Line 196, and Line 207 are recursions
#include <iostream>
// Lines 162, 173, 183, 196, 206, 219, 229, and 241 are recursion
using namespace std;

int pleft = 0;
int pright = 0;
int pMax = 0; // Depth

class KNode
{
private:
    char coordInCharge; // not int, we are dealing with characters (char)s
    int xcoor;
    int ycoor;
    KNode *right;
    KNode *left;

public:
    int depth;
    KNode ()    // Default Constructor
    {
        coordInCharge = 'X';
        xcoor = 0;
        ycoor = 0;
        right = NULL;
        left = NULL;
        depth = 0;
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
      int idxmax = word.length();
      int x = 0;
      int y = 0;
      int setneg = 1; // setneg: to detect a negative sign
      if (word[idx] == '(')
      {
        idx++;
if (word[idx] == '-')
    {
 setneg = -1; // negative detected; set to -1
 idx++;
}
while (word[idx] != ',')
    {
 x= x * 10;
 x += (word[idx] - '0');
 idx++;
}
x = x * setneg; // using setneg to set it negative if '-' is detected
setneg = 1;
idx++;
if (word[idx] == '-')
    {
 setneg = -1;
 idx++;
}

while (word[idx] != ')')
    {
 y = y * 10; // 12 = (1*10) + 2    // 123 = (((1*10)+(2))*10) + 3
 y += (word[idx] - '0');
 idx++;
}
        y = y * setneg; // because it is a constructor
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

    void setLeft (KNode *n, char coord, int d)
    {
        // cout<<"setLeft coord: "<<coord<<endl;
        left = n;
        if (coord == 'X')
        {
            left->setcoordInCharge('Y');
        }
        else
        {
            left->setcoordInCharge('X');
        }
        left->setDepth(d+1);
    }

    void setRight (KNode *n, char coord, int d)
    {
        // cout<<"setRight coord: "<<coord<<endl;
        right = n;
        if (coord == 'Y')
        {
            right->setcoordInCharge('X');
        }
        else
        {
            right->setcoordInCharge('Y');
        }
            right->setDepth(d+1);
        // cout<<"Right coord: "<<right->getcoordInCharge()<<endl;
    }

    void addNode (KNode *newNode);
    void printNormal (KNode *indata);
    void printXPriority (KNode *indata);
    void printOneChildOnly (KNode *indata);
    void printYPriority (KNode *indata);
    int getXcoor();
    int getYcoor();
    int getDepth();
    void setDepth(int);
    int countChildren();
    void printChildren(KNode *indata);
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

    void KNode::setDepth(int d)
    {
        depth = d;
    }

    int KNode::getDepth()
    {
        return depth;
    }

    int KNode::countChildren()
    {
        int children = 0;
        if (getLeft() != NULL)
        {
            children += 1;
            children += getLeft()->countChildren();
        }
        if (getRight() != NULL)
        {
            children += 1;
            children += getRight()->countChildren();
        }
        return children;
    }


    void KNode::printChildren (KNode *indata)
    {
        if (indata->getLeft() != NULL) // if
        {
            pleft++;
            printChildren(indata->getLeft()); // This is a recursion because the function is calling itself
            // print  // getLeft, so we have a new root
        }

        cout<<" ("<<indata->getXcoor()<<","<<indata->getYcoor()<<")"; // cout
        // cout<<"coordincharge: "<<indata->getcoordInCharge()<<" ("<<indata->getXcoor()<<","<<indata->getYcoor()<<")"; // cout
        cout<<"Children: "<<indata->countChildren()<<endl;
        // cout<<"("<<indata->getXcoor()<<","<<indata->getYcoor()<<")"; // cout
        if (indata->getRight() != NULL) // if
        {
            pright++;
            printChildren(indata->getRight()); // This is a recursion because the function is calling itself
            // print // getRight != NULL, getLeft != NULL
        }
    };

    void KNode::printNormal (KNode *indata)
    {
        if (indata->getLeft() != NULL) // if
        {
            pleft++;
            printNormal(indata->getLeft()); // This is a recursion because the function is calling itself
            // print  // getLeft, so we have a new root
        }

        cout<<" ("<<indata->getXcoor()<<","<<indata->getYcoor()<<")"; // cout
        // cout<<"coordincharge: "<<indata->getcoordInCharge()<<" ("<<indata->getXcoor()<<","<<indata->getYcoor()<<")"; // cout

        // cout<<"("<<indata->getXcoor()<<","<<indata->getYcoor()<<")"; // cout
        if (indata->getRight() != NULL) // if
        {
            pright++;
            printNormal(indata->getRight()); // This is a recursion because the function is calling itself
            // print // getRight != NULL, getLeft != NULL
        }
    };

    void KNode::printXPriority (KNode *indata)
    {
        if (indata->getLeft() != NULL) // if
        {
            if (indata->getLeft()->getcoordInCharge() == 'X')
                pleft++;
            printXPriority(indata->getLeft()); // This is a recursion because the function is calling itself
            // print  // getLeft, so we have a new root
        }

        if(indata->getcoordInCharge() == 'X')
        {
            cout<<" ("<<indata->getXcoor()<<","<<indata->getYcoor()<<")"; // cout
            // cout<<"coordincharge: "<<indata->getcoordInCharge()<<" ("<<indata->getXcoor()<<","<<indata->getYcoor()<<")"; // cout
        }
        // cout<<"("<<indata->getXcoor()<<","<<indata->getYcoor()<<")"; // cout
        if (indata->getRight() != NULL) // if
        {
            if (indata->getRight()->getcoordInCharge() == 'X')
                pright++;
            printXPriority(indata->getRight()); // This is a recursion because the function is calling itself
            // print // getRight != NULL, getLeft != NULL
        }
    };

    void KNode::printOneChildOnly (KNode *indata)
    {
        if (indata->getLeft() != NULL) // if
        {
            if (indata->getLeft()->getLeft() == NULL || indata->getLeft()->getRight() == NULL)
                pleft++;
            printOneChildOnly(indata->getLeft()); // This is a recursion because the function is calling itself
            // print  // getLeft, so we have a new root
        }
        if (indata->getLeft() == NULL || indata->getRight() == NULL)
        {
            cout<<" ("<<indata->getXcoor()<<","<<indata->getYcoor()<<")"; // cout
            // cout<<"coordincharge: "<<indata->getcoordInCharge()<<" ("<<indata->getXcoor()<<","<<indata->getYcoor()<<")"; // cout
            // cout<<"("<<indata->getXcoor()<<","<<indata->getYcoor()<<")"; // cout
        }

        if (indata->getRight() != NULL) // if
        {
            if (indata->getRight()->getLeft() == NULL || indata->getRight()->getRight() == NULL)
                pright++;
            printOneChildOnly(indata->getRight()); // This is a recursion because the function is calling itself
            // print // getRight != NULL, getLeft != NULL
        }
    };

    void KNode::printYPriority (KNode *indata)
    {
        if (indata->getLeft() != NULL) // if
        {
            if (indata->getLeft()->getcoordInCharge() == 'Y')
            pleft++;
            printYPriority(indata->getLeft()); // This is a recursion because the function is calling itself
            // print  // getLeft, so we have a new root
        }
        if(indata->getcoordInCharge() == 'Y')
        {
            cout<<" ("<<indata->getXcoor()<<","<<indata->getYcoor()<<")"; // cout
            // cout<<"coordincharge: "<<indata->getcoordInCharge()<<" ("<<indata->getXcoor()<<","<<indata->getYcoor()<<")"; // cout
        }
        // cout<<"("<<indata->getXcoor()<<","<<indata->getYcoor()<<")"; // cout
        if (indata->getRight() != NULL) // if
        {
            if (indata->getRight()->getcoordInCharge() == 'Y')
                pright++;
            printYPriority(indata->getRight()); // This is a recursion because the function is calling itself
            // print // getRight != NULL, getLeft != NULL
        }
    };

    void KNode::addNode (KNode *newNode)
    {
        if (getcoordInCharge() == 'X')
        {
        // cout<<" (newNode->getXcoor(): "<<newNode->getXcoor()<<" getXcoor()): "<<getXcoor()<<endl;
        if (newNode->getXcoor() > getXcoor())
        {
            if (getRight() == NULL)
            {
                setRight(newNode, getcoordInCharge(), getDepth()); // "this" means actual object you're running right now
            }
            else
            {
                getRight()->addNode(newNode); // Recursion because calling addNode from within addNode
            }
        }
        else
        {
            if (getLeft() == NULL)
            {
                setLeft(newNode, getcoordInCharge(), getDepth());
            }
            else
            {
                getLeft()->addNode(newNode); // Recursion because calling addNode from within addNode
            }
        }
        }
        else
        {
        // cout<<"(newNode->getYcoor(): "<<newNode->getYcoor()<<" getYcoor()): "<<getYcoor()<<endl;
            if (newNode->getYcoor() > getYcoor())
            {
                if (getRight() == NULL)
                {
                setRight(newNode, getcoordInCharge(), getDepth()); // "this" means actual object you're running right now
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
                    setLeft(newNode, getcoordInCharge(), getDepth());
                }
                else
                {
                    getLeft()->addNode(newNode);
                }
            }
        }
    }

void KNode::menu ()
{
    // 1, 2, or 3 to insert, print, or quit
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
        cout<<"Please input a coordinate in the form (x,y): "<<endl;
        cin>>word;
        //  cout<<"Please einput an X coordinate: "<<endl;
        //  cin>>xcoor;
        //  cout<<"Please input a Y coordinate: "<<endl;
        //  cin>>ycoor;
        if (root == NULL)
        {
            cout<<"Please input the coordinate to set priority to for the root node (either 'X' or 'Y')"<<endl;
            cin>>coord;
            root = new KNode(word);
            root->setcoordInCharge(coord);
        }
        else
        {
            root->addNode(new KNode(word));
        }
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
        cout<<"The following three lines are the coordinates based on the 1. NORMAL BTREE, then 2. XCOOR priority, then 3. Only One Child, then 4. YCOOR priority: "<<endl;
        for (option = 1; option <= 4; option++)
        {
        cout<<endl;
        if (option == 1)
        {
            pleft = 0;
            pright = 0;
            cout<<"Normal Binary Tree: "<<endl;
            root->printNormal(root);
            if (pleft > pright)
                pMax = pleft;
            else
                pMax = pright;
            cout<<endl;
            cout<<"Depth = "<<pMax<<endl;
            cout<<"pleft: "<<pleft<<" pright: "<<pright<<endl;
            cout<<"Children: "<<root->countChildren()<<endl;
            cout<<"Print Children: "<<endl;
            root->printChildren(root);
        }
        else if (option == 2)
        {
            pleft = 0;
            pright = 0;
            cout<<"XCOOR Priority: "<<endl;
            root->printXPriority(root);
            if (pleft > pright)
                pMax = pleft;
            else
                pMax = pright;
            cout<<endl;
            cout<<"Depth = "<<pMax<<endl;
            cout<<"pleft: "<<pleft<<" pright: "<<pright<<endl;
            cout<<"Children: "<<root->countChildren()<<endl;
        }
        else if (option == 3)
        {
            pleft = 0;
            pright = 0;
            cout<<"Only One Child: "<<endl;
            root->printOneChildOnly(root);
            if (pleft > pright)
                pMax = pleft;
            else
                pMax = pright;
            cout<<endl;
            cout<<"Depth = "<<pMax<<endl;
            cout<<"pleft: "<<pleft<<" pright: "<<pright<<endl;
            cout<<"Children: "<<root->countChildren()<<endl;
        }
        else if (option == 4)
        {
            pleft = 0;
            pright = 0;
            cout<<"YCOOR Priority: "<<endl;
            root->printYPriority(root);
            if (pleft > pright)
                pMax = pleft;
            else
                pMax = pright;
            cout<<endl;
            cout<<"Depth = "<<pMax<<endl;
            cout<<"pleft: "<<pleft<<" pright: "<<pright<<endl;
            cout<<"Children: "<<root->countChildren()<<endl;
        }
        cout<<endl;
        }
    }
    }

    else if (choice == 3)
    {
        // Quit: Exit The Program
        cout<<"-----QUIT: Exit The Program-----"<<endl;
        return;
    }

    else if (choice == 4)
    {
        // Depth
        cout<<"Depth = "<<endl;
    }
    }
}

int main ()
{
    KNode k;
    k.menu();
    return 0;
}
