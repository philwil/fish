#include <iostream>
#include <iomanip>
#include <math.h>
#include <string.h>
#include<bits/stdc++.h>
// Create a binary tree with left and right nodes
// This time add count of children and depth
using namespace std;

class BNode
{
    private:

    char data;
    BNode *right;
    BNode *left;
    int depth;
    int cCount;
    public:

    BNode (char d)
    {
        data = d;
        right = NULL;
        left = NULL;
        cCount = 0;
        depth = 0;
    }

    BNode *getLeft ()
    {
        return left;
    }

    BNode *getRight ()
    {
        return right;
    }

    void setLeft (BNode *n)
    {
        if (left == NULL)
        {
            cCount += 1;
        }
        left = n;
    }

    void setRight (BNode *n)
    {
        if (right == NULL)
        {
            cCount += 1;
        }
        right = n;
    }

    void setData (char d) // not returning anything, just printing out the data (char)
    {
        data = d;
    }

    char getData () // returning the data; not setting it
    {
        return data;
    }
};

BNode *addBNode (BNode *root, BNode *newNode)
{
    if (root == NULL)
    {
        return newNode;
    }
    if (root->getData() > newNode->getData())
    {
        // go to left if we can
        if (root->getLeft() == NULL) // if nothing is to the left of root
        {
            root->setLeft(newNode); // set newNode to the left
        }
        else
        {
            addBNode (root->getLeft(), newNode);
        }
    }
    else
    {
        if (root->getRight() == NULL)
        {
            root ->setRight(newNode);
        }
        else
        {
            addBNode (root->getRight(), newNode);
        }
    }
    return root;
}

void printBNode (BNode *root)
{
    // Print out left nodes, right nodes, and data
    if (root == NULL)
    {
        return;
    }
    printBNode(root->getLeft());
    cout<<root->getData();
    printBNode (root->getRight());
}
BNode *root = NULL;
int main ()
{
    BNode *node1;
    BNode *node2;
    node1 = new BNode('b');
    node2 = new BNode('a');
    root = addBNode(root, node1);
    root = addBNode(root, node2);
    printBNode(root);
    return 0;
}

