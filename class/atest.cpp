include <iostream>
#include <array>
using namespace std;

string vowels="aeiou";

struct aName
{
  aName(){};

  ~aName(){};
  string name;
  int nvs;
  int len;
};


int getvowels(string &name)
{
  int i1;
  int i2;
  int v=0;
  for (i1 = 0 ; i1 < name.size(); i1++)
    {
      for (i2 = 0; i2 < vowels.size(); i2++)
	{
	  if(name[i1] == vowels[i2]) v++;
	}
    }
  return v;
}
void getName(int &idx, int &done, array<aName, 32> &an)
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
      an[idx].nvs = getvowels(name);
      idx++;
    }
  else
    {
      done = 1;
    }
  
}

void alensort(int &idx,array<aName, 32> &an)
{
  int swap = 0;
  aName at;
  do {
    swap = 0;
    for (int i = 0; i < idx-1; i++)
      {
	if (an[i].len > an[i+1].len)
	  {
	    at = an[i];
	    an[i] = an[i+1];
	    an[i+1] = at;
	    swap++;
	  }
      }
    
  } while (swap > 0);
}

void avowsort(int &idx,array<aName, 32> &an)
{
}

int main()
{
  array<aName, 32> names;
  array<aName, 32> names_len;
  array<aName, 32> names_vow;

  int idx = 0;
  int done = 0;
  while (!done)
    {
      getName(idx, done, names);
    }
  cout
    << " names size " <<  names.size() 
    << " names entered " <<  idx << endl;
  for (int i = 0; i<idx; i++)
    {
      names_len[i] = names[i];
      names_vow[i] = names[i];
    }
  alensort(idx,names_len);
  avowsort(idx,names_len);
  
  return 0;
}
