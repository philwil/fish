#include <iostream>
#include <array>
using namespace std;

string vowels="aeiou";

struct Person
{
  string name;
  int nvs;
  int len;
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

void Input(int &idx, int &done, struct aName an [])
{
  string name;
  cout << vowels<< " size " << vowels.size() << endl;
  cout << "enter name (q to quit)" <<endl;
  cin >> name;
  cout	   << name<< " size " << name.size() << endl;
  if((idx < 32) && (name != "q"))
    {
      cout << "name "
	   << name<< " size " << name.size()
	   << " vowels " << getvowels(name)
	   << endl;
      an[idx].name = name;
      an[idx].len = name.size();
      an[idx].nvs = NumberofVowels(name);
      idx++;
    }
  else
    {
      done = 1;
    }
  
}

void Swap(int &idx, struct Person p [] )
{
  Person ptmp;
  ptmp = p[idx];
  p[idx] = p[idx+1];
  p[i+1] = ptmp;
}

void SortLength(int &idx, struct Person p [] )
{
  int swapCount = 0;
  aName at;
  do {
    swapCount = 0;
    for (int i = 0; i < idx-1; i++)
      {
	if (p[i].len > p[i+1].len)
	  {
            Swap(i,p);
	    swapCount++;
	  }
      }
    
  } while (swapCount > 0);
}

void SortVowels(int &idx, struct Person p [])
{
}

void OutputDisplay(struct Person p [], int num)
{
  int i;
  for (i = 0; i< num; i++)
    {
      cout << " idx " << i<< " name ["<< p[i].name <<"]" << endl;
    }
}

int main()
{
  struct Person p[32];

  int idx = 0;
  int done = 0;
  while (!done)
    {
      Input(idx, done, p);
    }
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

  alensort(idx,an);
  cout << " after len sort" << endl;

  show_names(an, idx);

  avowsort(idx,an);
  
  return 0;
}
