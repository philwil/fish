#include <iostream>
using namespace std;

class ListItem;
class List
{
public:
    void addItem(int num);
    void print();
    ListItem *first;
    public:
    List ()
    {
        first = NULL;
    }
};

class ListItem
{
    private:
    int value;
    ListItem *next;
    public:
    ListItem (int d, ListItem *n)
    {
        value = d;
        next = n;
    }
    int getValue(void){return value;};
    void setNext (ListItem *n);
    ListItem *getNext(void){return next;};
};

void ListItem::setNext(ListItem *n)
{
    next = n;
    return;
}

void List::addItem(int num)
{
    ListItem *li = new ListItem (num, NULL);
    if (first == NULL)
    {
        first = li;
        return;
    }
    else
    {
        li->setNext(first);
        first = li;
        return;
    }
}

void List::print(void)
{
    ListItem *li = first;
    while (li != NULL)
    {
        cout<<li->getValue()<<endl;
        li = li->getNext();
    }
}

int main ()
{
    List l;
    l.addItem(3);
    l.addItem(4);
    l.print();
    return 0;
}
