#include <iostream>
#include <iomanip>
#include <array>

//g++  -g -std=c++11 -o g Persons.cpp
using namespace std;

string vowels="aeiou";

string testNames [5] = {
  "anam12222",
  "nam2",
  "ffffaaname4",
  "ssssnameea3",
  "tttname2222"
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

void Input(int &max, Persons p [])
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
      p[idx].name = name;
      p[idx].nameLen = name.size();
      p[idx].numvowels = NumberOfVowels(name);
      //p++;
      idx++;
    } while (idx < max);
cout << " End of input" << endl<<endl;

}

void InputTest(int &max, Persons p [] )
{
  string name;
  //cout << vowels<< " size " << vowels.size() << endl;
  int idx = 0;
   do
    {
      cout << "enter name " <<endl;
      //cin >> name;
      name = testNames[idx];
      //cout	   << name<< " size " << name.size() << endl;
      cout << "name "
	   << name << " size " << name.size()
	   << endl;
      p[idx].name = name;
      p[idx].nameLen = name.size();
      p[idx].numvowels = NumberOfVowels(name);
      idx++;
      //p++;
    } while (idx < max);
cout << " End of input" << endl<<endl;

}

void Swap(int idx, Persons p [])
{
  Persons ptmp;
  ptmp = p[idx];
  p[idx] = p[idx+1];
  p[idx+1] = ptmp;

}

void SortLength(int &max, Persons p [] )
{
  int swapCount;
  do {
    swapCount = 0;
    for (int i = 0; i < max-1; i++)
      {
	if (p[i].nameLen < p[i+1].nameLen)
	  {
            Swap(i, p);
	    swapCount++;
	  }
      }
    
  } while (swapCount > 0);
}

void SortVowels(int &max, Persons p [])
{
  int swapCount;
  do {
    swapCount = 0;
    for (int i = 0; i < max-1; i++)
      {
	//cout << "SortVowels i "<< i<< " p->name ["<< p->name;
	//cout     << "]" << " p1->name [" << (p+1)->name << "] " << endl;  
	if (
             (p[i].numvowels < p[i+1].numvowels) ||
	    (( p[i].numvowels == p[i+1].numvowels) 
                  && (p[i].nameLen < p[i+1].nameLen)))
	  {
            Swap(i, p);
	    swapCount++;
	  }
      }
    
  } while (swapCount > 0);

}

void OutputDisplay(int &max, Persons p [])
{
  int i;
  cout <<setw(10)<< " name " << " length " <<" vowels " << endl;

  for (i = 0; i< max; i++)
    {
      cout << setw(10)
            //<< " idx " << i
	   //<< " name ["
           << p[i].name <<" " 
	   //<< " len " 
           << p[i].nameLen
	   << "  " << p[i].numvowels
	   << endl;
      //p++;
    }
}

int main()
{
  Persons p[5];

  int max = 5;

  Input(max, p);
  //OutputDisplay(max, p);
  //InputTest(max, p);
  SortLength(max,p);
  OutputDisplay(max, p);
  SortVowels(max,p);
  OutputDisplay(max, p);
  return 0;
  
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
  //SortLength(max,p);

  //return 0;


  //cout << " after len sort" << endl;
  //OutputDisplay(max,p);

  //SortVowels(max,p);
  cout << " after vowel sort" << endl; 

  OutputDisplay(max,p);

  //avowsort(idx,p);
  
  return 0;
}
