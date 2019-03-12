// Cows 1
#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <cmath>

using namespace std;

class Cow
{
    public:
    char cowName [128];
    char cowColor [128];
    int cowWeight;
    Cow *next;
};

Cow cow [100];

Cow* findCow (char *name)
{
    Cow *cowp;
    cowp = cow;
do
{
    if (strcmp(name, cowp->cowName) == 0) // if ou don't find a match
    {
        return cowp;
    }
    cowp = cowp->next;
}
while (cowp);
// cowp will automatically be NULL
return cowp;
}

int main ()
{
    Cow *cowp;
    Cow *oldCowp = NULL;
    ifstream myfile;
    int done = 0; // used as a flag, done with it, not using it just now
    string str;
    cowp = cow;
    myfile.open("Cows1.txt", ifstream::in);
    if (myfile.is_open())
    {
    do
    {
    getline (myfile, str);
    if (str.length() > 0)
    {
        if (oldCowp != NULL)
        {
            oldCowp->next = cowp;
        }
    // cout<<"String read =  "<<str<<endl; // This could be anything (result, or whatever you are trying to find)
    sscanf(str.c_str(), "%s %s %d", cowp->cowName, cowp->cowColor, &cowp->cowWeight);
    cout<<"Cow Name: "<<cowp->cowName<<"      Cow Color: "<<cowp->cowColor<<"      Cow Weight: "<<cowp->cowWeight<<endl;
    cowp->next = NULL;
    oldCowp = cowp;
    cowp += 1;
    }
    }
    while (!myfile.eof() && !done);
    myfile.close();
    }
    cout<<"List of cows: "<<endl;
    cowp = cow;
do
{
    cout<<"Cow Name: "<<cowp->cowName<<"      Cow Color: "<<cowp->cowColor<<"      Cow Weight: "<<cowp->cowWeight<<endl;
    cowp = cowp->next;
}
while (cowp); // Because the line 5 has already moved you on to the next cow. you do not need -> next (to point to next)
cowp = findCow ((char*) "Bessy");
if (cowp != NULL)
{
        cout<<"Found Cow Name: "<<cowp->cowName<<"      Cow Color: "<<cowp->cowColor<<"      Cow Weight: "<<cowp->cowWeight<<endl;
}
}
