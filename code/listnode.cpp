// Rohan Sachdev
// Period 4A - Advanced CS
// Enloe High School - Mr. Potter
// 3 - 14 -2019
// Pi Day
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
        void print ();
};

void List::insertValue(int a, NULL)
{
    // LiatNode * add-on = newListnode (x, NULL);
    ListNode current = first;
    int length = 1;
    if (first == NULL)
    {
        first = address
    }
    for (int j = 0; j<length; j++)
    {

    }
}

void List::menu()
{
    int choice;
    int value;
    cout<<"1.) Insert a value."<<endl;
    cout<<"2.) Print list"<<endl;
    cout<<"3.) Quit"<<endl;
    cout<<"Please choose one of the choices."<<endl;
    cin>>choice;
    if (choice == 1)
    {
        cout<<"Please input a value for the list: "<<endl;
        cin>>value;
        insertValue(num);
        cout<<endl;
        menu();
    }
    else if (choice == 2)
    {

    }
}

void List::print()
{

    ListNode *temp = first; // temp is an address, and temp is assigned to first, it is fist
    // And then we assign first to NULL
    temp = new ListNode(5, NULL); // Creates a box, which starts our race // the word new is the creation
    cout<<temp<<endl; // outputs the address of temp
    cout<<temp->getData()<<endl; // outputs temp's data, (prints out 5 since it's 5)
    cout<<temp->getNext()<<endl; // Address of next door neighbor of temp
    temp->setNext(new ListNode(4, NULL)); // ListNodes are addresses // How do we get 4? Possibly temp->getNext()
    // the parameter for setNext is an address
    // (new ListNode (4, NULL)) is passing the address of a box
    cout<<temp<<endl;
    cout<<temp->getData()<<endl; // Spits out value
    cout<<temp->getNext()<<endl; // Spits out next address
    cout<<temp->getNext()->getData()<<endl; // Next address; value = ? (what is the value?)
    ListNode *oops = new ListNode(10, NULL);
    cout<<oops->getData()<<endl;
    temp->getNext()->setNext(oops);
    temp->getNext()->getNext()->setNext(temp->getNext());
    temp->setNext(oops); // if oops value is > than next's value
    // if the value of oops is > than the value of first and the value of oops is < 400 how can i talk about 400
    // first's get next door neighbors data
    cout<<temp->getData()<<endl;
    cout<<temp->getNext()->getData()<<endl;
    cout<<temp->getNext()->getNext()->getData()<<endl;
    // NULL will signify that I am at the end
    // this next line will reassign my temps next door neighbor's next
    //temp->getNext()->setNext(oops);
    // cout<<temp->getNext()->getnext()->getData()<<endl;
    // The only time you don't compare is when the ifrst = NULL
    //cout<<oops->getData()<<endl; // order of operations is huge in LinkLists // thi swas there before
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
