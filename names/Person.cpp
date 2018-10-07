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

void Input(int &idx, struct Person p [])
{
  string name;
  cout << vowels<< " size " << vowels.size() << endl;
  //  
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
      idx++;
    } while (idx < 5);
  
}
void InputTest(int &idx, struct Person p [])
{
  string name;
  cout << vowels<< " size " << vowels.size() << endl;
  //  
   do
    {
      cout << "enter name " <<endl;
      name = testNames[idx];
      cout	   << name<< " size " << name.size() << endl;
      cout << "name "
	   << name<< " size " << name.size()
	   << endl;
      p[idx].name = name;
      p[idx].nameLen = name.size();
      p[idx].numvowels = NumberOfVowels(name);
      idx++;
    } while (idx < 5);
  
}

void Swap(int &idx, struct Person p [] )
{
  Person ptmp;
  ptmp = p[idx];
  p[idx] = p[idx+1];
  p[idx+1] = ptmp;
}

void SortLength(int &idx, struct Person p [] )
{
  int swapCount = 0;
  do {
    swapCount = 0;
    for (int i = 0; i < idx-1; i++)
      {
	if (p[i].nameLen < p[i+1].nameLen)
	  {
            Swap(i,p);
	    swapCount++;
	  }
      }
    
  } while (swapCount > 0);
}

void SortVowels(int &idx, struct Person p [] )
{
  int swapCount = 0;
  do {
    swapCount = 0;
    for (int i = 0; i < idx-1; i++)
      {
	if (p[i].numvowels < p[i+1].numvowels)
	  {
            Swap(i,p);
	    swapCount++;
	  }
      }
    
  } while (swapCount > 0);

}


void OutputDisplay(struct Person p [], int num)
{
  int i;
  for (i = 0; i< num; i++)
    {
      cout << " idx " << i
	   << " name ["<< p[i].name <<"]" 
	   << " len " << p[i].nameLen
	   << " vowels " << p[i].numvowels
	   << endl;
    }
}

int main()
{
  struct Person p[5];

  int idx = 0;

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
  OutputDisplay(p, idx);


  //  SortLength(idx,p);
  //cout << " after len sort" << endl;

  OutputDisplay(p, idx);
  SortVowels(idx,p);
  cout << " after vowel sort" << endl; 

  OutputDisplay(p, idx);

  //avowsort(idx,p);
  
  return 0;
}
