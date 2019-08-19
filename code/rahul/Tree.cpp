// tree stuff
/* C++ program for special order traversal */
#include <bits/stdc++.h> 
using namespace std; 
  
/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct Node 
{ 
    int data;
    int count;
    Node *left, *right;
    int ylevel;  // really depth
    int xlevel;  // side to side
    char side;
    int pdata;
}; 
  
/* Helper function that allocates a new node with the 
given data and NULL left and right pointers. */
Node* newNode(int data) 
{ 
    Node* node = new Node; 
    node->data = data; 
    node->right = node->left = NULL;
    node->count++;
    node->ylevel = 0;
    node->xlevel = 0;
    node->side = ' ';
    node->pdata = 0;
    return node; 
} 
Node *addRightNode(Node *root, Node *item);
Node *addLeftNode(Node *root, Node *item);


Node *addNode(Node *root, Node *item)
{
  if (item->data < root->data) {
    root = addLeftNode(root,item);
  }
  else if (item->data > root->data) {
    root = addRightNode(root,item);
  }
  else {
    root->count++;
  }
  return root;
}

Node *addLeftNode(Node *root, Node *item)
{
  if(root->left == NULL) {
    item->side='L';
    item->pdata=root->data;
    root->left = item;
    item->xlevel = root->xlevel-1;
    item->ylevel = root->ylevel+1;

    return root;
  }
  else {
    item->xlevel = root->xlevel-1;
    item->ylevel = root->ylevel+1;
    return addNode(root->left, item);
  }
}

Node *addRightNode(Node *root, Node *item)
{
  if(root->right == NULL) {
    item->side='R';
    item->pdata=root->data;
    root->right = item;
    //item->xlevel+=2;
    item->xlevel = root->xlevel+1;
    item->ylevel = root->ylevel+1;

    return root;
  }
  else {
    //item->xlevel+=2;
    item->xlevel = root->xlevel+1;
    item->ylevel = root->ylevel+1;
    return addNode(root->right, item);
  }
}

Node *insertNode(Node *root, int data)
{
  Node *item = newNode(data);
  if(root == NULL) {
    return item;
  }
  item->ylevel = root->ylevel+1;
  addNode(root, item);
  return root;
}



void printSpecificLevelOrderUtil(Node* root, stack<Node*> &s) 
{ 
    if (root == NULL) 
        return; 
  
    // Create a queue and enqueue left and right 
    // children of root 
    queue<Node*> q; 
  
    q.push(root->left); 
    q.push(root->right); 
  
    // We process two nodes at a time, so we 
    // need two variables to store two front 
    // items of queue 
    Node *first = NULL, *second = NULL; 
  
    // traversal loop 
    while (!q.empty()) 
    { 
        // Pop two items from queue 
        first = q.front(); 
        q.pop(); 
        second = q.front(); 
        q.pop(); 
  
        // Push first and second node's children 
        // in reverse order 
        s.push(second->left); 
        s.push(first->right); 
        s.push(second->right); 
        s.push(first->left); 
  
        // If first and second have grandchildren, 
        // enqueue them in specific order 
        if (first->left->left != NULL) 
        { 
            q.push(first->right); 
            q.push(second->left); 
            q.push(first->left); 
            q.push(second->right); 
        } 
    } 
} 

void GetNodeStack(Node *root, stack<Node *>&s)
{
  if (root == NULL) return;
  s.push(root);
  GetNodeStack(root->left, s);
  GetNodeStack(root->right, s);
  return;
}
  

/* Given a perfect binary tree, print its nodes in 
specific level order */
void printSpecificLevelOrder(Node* root) 
{ 
    //create a stack and push root 
    stack<Node*> s; 
  
    //Push level 1 and level 2 nodes in stack 
    s.push(root); 
  
    // Since it is perfect Binary Tree, right is 
    // not checked 
    if (root->left != NULL) 
    { 
        s.push(root->right); 
        s.push(root->left); 
    } 
  
    // Do anything more if there are nodes at next 
    // level in given perfect Binary Tree 
    if (root->left->left != NULL) 
        printSpecificLevelOrderUtil(root, s); 
  
    // Finally pop all Nodes from stack and prints 
    // them. 
    while (!s.empty()) 
    { 
        cout << s.top()->data << " "; 
        s.pop(); 
    } 
} 

void PrintNodeStack(Node* root,stack<Node *>&s)
{
      while (!s.empty()) 
    {
      int yl =s.top()->ylevel;
      int xl =s.top()->xlevel;
      cout
	<< "P[" << s.top()->pdata<<"] "
	<< "S[" << s.top()->side<<"] "
	<< "YL[" << yl<<"] "
	<< "XL[" << xl <<"] "
	   << s.top()->data << "\n"; 
        s.pop(); 
    } 
}

/*
                   x
                  l r

l0                   x
l1                 l   r
l2                l r l r
*/

/* Driver program to test above functions*/
int main() 
{ 
  stack<Node *>s;
  // Perfect Binary Tree of Height 4
  Node *root = NULL;
    //Node* root = newNode(1); 
  root=insertNode(root, 5);
  root=insertNode(root, 2);
  root=insertNode(root, 1);
  root=insertNode(root, 3);
  root=insertNode(root, 4);
  root=insertNode(root, 10);

  GetNodeStack(root, s);
  PrintNodeStack(root, s);
  

    //root->left = newNode(2); 
    //root->right = newNode(3); 

    
    /* root->left->left  = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left  = newNode(6); 
    root->right->right = newNode(7); 
  
    root->left->left->left  = newNode(8); 
    root->left->left->right  = newNode(9); 
    root->left->right->left  = newNode(10); 
    root->left->right->right  = newNode(11); 
    root->right->left->left  = newNode(12); 
    root->right->left->right  = newNode(13); 
    root->right->right->left  = newNode(14); 
    root->right->right->right  = newNode(15); 
  
    root->left->left->left->left  = newNode(16); 
    root->left->left->left->right  = newNode(17); 
    root->left->left->right->left  = newNode(18); 
    root->left->left->right->right  = newNode(19); 
    root->left->right->left->left  = newNode(20); 
    root->left->right->left->right  = newNode(21); 
    root->left->right->right->left  = newNode(22); 
    root->left->right->right->right  = newNode(23); 
    root->right->left->left->left  = newNode(24); 
    root->right->left->left->right  = newNode(25); 
    root->right->left->right->left  = newNode(26); 
    root->right->left->right->right  = newNode(27); 
    root->right->right->left->left  = newNode(28); 
    root->right->right->left->right  = newNode(29); 
    root->right->right->right->left  = newNode(30); 
    root->right->right->right->right  = newNode(31); 
    */
    //cout << "Specific Level Order traversal of binary "
    //     "tree is \n"; 
    //printSpecificLevelOrder(root); 
    //cout << endl;
    
    return 0; 
} 
