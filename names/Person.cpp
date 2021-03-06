#include <iostream>
#include <array>
using namespace std;

string vowels="aeiou";

string testNames [5] = {
  " anam12222",
  " name2",
  " ffffaaname4",
  " ssssnamee3",
  " tttname2"
};

struct Person
{
  string name;
  int nameLen;
  int numvowels;
};


int NumberOfVowels(string &name)
{
  int i1;
  int i2;
  int v=0;
  for (i1 = 0 ; i1 < name.size(); i1++)
    {
      for (i2 = 0; i2 < vowels.size(); i2++)
	{
	  if(name[i1] == vowels[i2]) {
	    v++;
	    i2 = vowels.size();
	  }
	}
    }
  return v;
}

void Input(int &max, struct Person p [])
{
  string name;
  cout << vowels<< " size " << vowels.size() << endl;
  //  
  int idx = 0;
   do
    {
      cout << "enter name " <<endl;
      cin >> name;
      cout	   << name<< " size " << name.size() << endl;
      cout << "name "
	   << name<< " size " << name.size()
	   << endl;
      p->name = name;
      p->nameLen = name.size();
      p->numvowels = NumberOfVowels(name);
      p++;
      idx++;
    } while (idx < max);
  
}
void InputTest(int &max, struct Person p [])
{
  string name;
  cout << vowels<< " size " << vowels.size() << endl;
  int idx = 0;
   do
    {
      cout << "enter name " <<endl;
      name = testNames[idx];
      cout	   << name<< " size " << name.size() << endl;
      cout << "name "
	   << name<< " size " << name.size()
	   << endl;
      p->name = name;
      p->nameLen = name.size();
      p->numvowels = NumberOfVowels(name);
      idx++;
      p++;
    } while (idx < max);
  
}

void Swap(Person*p)
{

  Person ptmp;
  ptmp = p[0];
  p[0] = p[1];
  p[1] = ptmp;

}

void SortLength(int idx, Person *p )
{
  int swapCount = 0;
  Person *px;
  do {
    px = p;
    swapCount = 0;
    for (int i = 0; i < idx-1; i++)
      {
	if (px->nameLen < (px+1)->nameLen)
	  {
            Swap(px);
	    swapCount++;
	  }
	px++;
      }
    
  } while (swapCount > 0);
}

void SortVowels(int idx, Person *p)
{
  int swapCount = 0;
  Person *px;
  do {
    px=p;
    swapCount = 0;
    for (int i = 0; i < idx-1; i++)
      {
	cout << "SortVowels i "<< i<< " p->name ["<< p->name;
	cout     << "]" << " p1->name [" << (p+1)->name << "] " << endl;  
	if (px->numvowels < (px+1)->numvowels)
	  {
            Swap(px);
	    swapCount++;
	  }
	px++;
      }
    
  } while (swapCount > 0);

}


void OutputDisplay(Person *p, int num)
{
  int i;
  for (i = 0; i< num; i++)
    {
      cout << " idx " << i
	   << " name ["<< p->name <<"]" 
	   << " len " << p->nameLen
	   << " vowels " << p->numvowels
	   << endl;
      p++;
    }
}

int main()
{
  Person p[5];

  int idx = 5;

  //Input(idx, p);
  InputTest(idx, p);
  
  cout
    << " names size " <<  32 
    << " names entered " <<  idx << endl;
  //  for (int i = 0; i<idx; i++)
  // {
  //  names_len[i] = names[i];
  //  names_vow[i] = names[i];
  //}

  cout << " before len sort" << endl;
  OutputDisplay(p, 5);
  //cout << " after swap" << endl;
  //Swap(p);
  //OutputDisplay(p, 5);

  //return 0;


  SortLength(5,p);
  cout << " after len sort" << endl;
  OutputDisplay(p, 5);

  SortVowels(5,p);
  cout << " after vowel sort" << endl; 

  OutputDisplay(p, 5);

  //avowsort(idx,p);
  
  return 0;
}
