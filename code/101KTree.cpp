// Rohan Sachdev
// Period 4A - Advanced CS
// Enloe High School - Mr. Potter
// 5-20-2019 (Due On: 5-21-2019)

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
    KNode ()    // Default Constructor
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
      if (word[idx] == '(')
      {
        idx++;
if (word[idx] == '-')
    {
 setneg = -1;
 idx++;
}
while (word[idx] != ',')
    {
 x= x * 10;
 x += (word[idx] - '0');
 idx++;
}
x = x * setneg;
setneg = 1;
idx++;
if (word[idx] == '-')
    {
 setneg = -1;
 idx++;
}

while (word[idx] != ')')
    {
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
    }

    void setRight (KNode *n, char coord)
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
        // cout<<"Right coord: "<<right->getcoordInCharge()<<endl;
    }

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
            cout<<" ("<<indata->getXcoor()<<","<<indata->getYcoor()<<")"; // cout
            // cout<<"coordincharge: "<<indata->getcoordInCharge()<<" ("<<indata->getXcoor()<<","<<indata->getYcoor()<<")"; // cout
        }
        // cout<<"("<<indata->getXcoor()<<","<<indata->getYcoor()<<")"; // cout
        if (indata->getRight() != NULL) // if
        {
            pright++;
            print(indata->getRight(), option); // print // getRight != NULL, getLeft != NULL
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
        // cout<<"(newNode->getYcoor(): "<<newNode->getYcoor()<<" getYcoor()): "<<getYcoor()<<endl;
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
        cout<<"The following three lines are the coordinates based on the 1. NORMAL BTREE, then 2. XCOOR priority, then 3. YCOOR priority:"<<endl;
        for (option = 1; option <= 3; option++)
        {
        cout<<endl;
        root->print(root, option);
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
    }
}

int main ()
{
    KNode k;
    k.menu();
    return 0;
}
