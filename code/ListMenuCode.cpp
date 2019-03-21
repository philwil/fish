// Rohan Sachdev
// Period 4A - Advanced CS
// Enloe High School - Mr. Potter
// 3 - 22 - 2019 (Due Friday)

// 20 points for printing DONE (+20) Bonus: +10
// 20 points each for inserting in the middle, beginning, and end (DONE +60)
// Actually everything except "delete" = 90
// Delete is worth 10 points
// Delete is for beginning, middle, end, and even if it is not in the list // especially middle
// to me it looks like the list is like a stack in ASCENDING ORDER
// Like this:
/*
 1
 3
 5
 9
 */
#include <iostream>

using namespace std;

class ListNode
{
private:
    int data;
    ListNode *next;
public:
    ListNode (int d, ListNode *n)
    {
        data = d;
        next = n;
    }
    int getData ()
    {
        return (data);
    }
    void setData (int newData)
    {
        data = newData;
    }
    ListNode *getNext ()
    {
        return (next);
    }
    void setNext (ListNode *n)
    {
        next = n;
    }
};

class List
{
    private:
        ListNode *first;
        // ListNodes *first; // Not using an array of values, or a vector; we are using a LinkList
        // Also first is an address
    public:
        List ()
        {
            first = NULL;
        }
        void menu();
        void insertValue(int a);
        void Delete(int a);
        void print ();
};

void List::menu()
{
    // 1 2 3 or 4 to insert print delete or quit
    // for i = 0, i > -1, i++
    int choice;
    int value;
    int done = 0;
    while (! done)
    {

    // int deleter;
/*
    cout<<"1.) Insert a value."<<endl;
    cout<<"2.) Print list"<<endl;
    cout<<"3.) Quit"<<endl;
    cout<<"Please choose one of the choices."<<endl;
*/
cout<<"Choose 1, 2, 3, or 4 to ----> 1. insert, 2. print, 3. delete, or 4. quit, respectively. : "<<endl;
cin>>choice;
    if (choice == 1)
    {
        // Insert
        cout<<"Please input an integer for the list to be inserted: "<<endl;
        cin>>value;
        insertValue(value);
        cout<<endl;
    }
    else if (choice == 2)
    {
        // Print
        print();
    }
    else if (choice == 3)
    {
        // Delete
        cout<<"Please input an integer for the list to be deleted: "<<endl;
        cin>>value;
        Delete(value);
        cout<<endl;
    }
    else if (choice == 4)
    {
        // Quit
        done = 1;
        cout<<"Quit"<<endl;
    }
    }
}

void List::insertValue(int a)
{
    ListNode *ln = new ListNode (a, NULL);
    if (first == NULL) // empty list, nothing else in it, nothing to compare with
    {
        first = ln;
        return;
    }
    // something in the list, we have to find our place / spot
    // We are either first, last, or in the middle
    ListNode *lx = first; // lx is a pointer to a ListNode
    ListNode *last = NULL;
    while (lx && lx->getData() < a)
    {
        last = lx;
        lx = lx->getNext();
    }
    if (lx == first) // for inserting at beginning
    { // before the first
        first = ln;
        ln->setNext(lx);
        return;
    }
    if (lx == NULL) // for inserting at end
    { // after the last
        last->setNext(ln);
        return;
    }
    else // for inserting in middle
    {
        last->setNext(ln);
        ln->setNext(lx);
    }
// When we get here ln goes before lx
// Is my data in ln > lx.data (the data in first)?
}

void List::print()
{
   ListNode *current = first;
   cout<<"Printing Results: "<<endl;
   while (current)
   {
       cout<<"  "<<current->getData()<<endl;
       current = current->getNext();
   }
}

void List::Delete(int a)
{
    if (first == NULL) // this is why if I empty the list, it won't print out anything
    {
        return;
    }
    ListNode *lx = first; // lx is a pointer to a ListNode
    ListNode *last = NULL;
    while (lx && lx->getData() < a)
    {
        last = lx;
        lx = lx->getNext();
    }
    // The next 4 lines are to see where we are on the list
    /*
    if (lx != NULL)
     cout<<"Value at lx: "<<lx->getData()<<endl;
    else
        cout<<"lx = NULL"<<endl;
    */
if (lx != NULL)
{
    if (lx->getData() == a)
    {
        if (lx == first)
        {
            first = lx->getNext(); // To remove first, replace the first element
        }
        else
        {
            last->setNext(lx->getNext());
        }
    }
}
}

int main ()
{
    List l;
    //l.print(); // prints the values; doesn't sort things
    l.menu();
    // Menu
    // 1. Insert a value
    // 2. Print list
    // 3. Quit
    return 0;
}
