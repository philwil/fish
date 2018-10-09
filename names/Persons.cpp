#include <iostream>
#include <array>

//g++  -g -std=c++11 -o g Persons.cpp
using namespace std;

string vowels="aeiou";

string testNames [5] = {
  " anam12222",
  " nam2",
  " ffffaaname4",
  " ssssnameea3",
  " tttname2222"
};

struct Persons
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

void Input(int &max, Persons p [5])
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
void InputTest(int &max, Persons p [5])
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

void Swap(Persons p [])
{
  Persons ptmp;
  ptmp = p[0];
  p[0] = p[1];
  p[1] = ptmp;

}

void SortLength(int max, Persons p [5])
{
  int swapCount = 0;
  Persons *px;
  do {
    px = p;
    swapCount = 0;
    for (int i = 0; i < max-1; i++)
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

void SortVowels(int &max, Persons p [5])
{
  int swapCount = 0;
  Persons *px;
  do {
    px=p;
    swapCount = 0;
    for (int i = 0; i < max-1; i++)
      {
	//cout << "SortVowels i "<< i<< " p->name ["<< p->name;
	//cout     << "]" << " p1->name [" << (p+1)->name << "] " << endl;  
	if ((px->numvowels < (px+1)->numvowels) ||
	    (( px->numvowels == (px+1)->numvowels) && (px->nameLen < (px+1)->nameLen)))
	  {
            Swap(px);
	    swapCount++;
	  }
	px++;
      }
    
  } while (swapCount > 0);

}


void OutputDisplay(int &max, Persons p [])
{
  int i;
  for (i = 0; i< max; i++)
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
  Persons p[5];

  int max = 5;

  //Input(idx, p);
  InputTest(max, p);
  
  cout
    //<< " names size " <<  32 
    << " names entered " <<  max << endl;
  //  for (int i = 0; i<idx; i++)
  // {
  //  names_len[i] = names[i];
  //  names_vow[i] = names[i];
  //}

  cout << " before len sort" << endl;
  OutputDisplay(max,p);
  //cout << " after swap" << endl;
  //Swap(p);
  //OutputDisplay(max,p);

  //return 0;


  //SortLength(max,p);
  //cout << " after len sort" << endl;
  //OutputDisplay(max,p);

  SortVowels(max,p);
  cout << " after vowel sort" << endl; 

  OutputDisplay(max,p);

  //avowsort(idx,p);
  
  return 0;
}
