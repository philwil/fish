
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

/* generate a random floating point number from min to max */
double randfrom(double min, double max)
{
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}


void InputTestDouble(int &max,  double p [] )
{
    double randomNumber;
    srand(time(NULL));

  string name;
  //cout << vowels<< " size " << vowels.size() << endl;
  int idx = 0;
   do
    {
      //cout << "enter name " <<endl;
      //cin >> name;
      randomNumber = randfrom(0.000, 1.000);;
      //name = testNames[idx];
      //cout	   << name<< " size " << name.size() << endl;
      cout << "random number "
	   << randomNumber
	   << endl;
      p[idx] = randomNumber;
    ;
      idx++;
      //p++;
    } while (idx < max);
cout << " End of input" << endl<<endl;

}


void InputTestInt(int &max,  int p [] )
{
    int randomNumber;
    srand(time(NULL));

  string name;
  //cout << vowels<< " size " << vowels.size() << endl;
  int idx = 0;
   do
    {
      //cout << "enter name " <<endl;
      //cin >> name;
      randomNumber = rand()%300000;
      //name = testNames[idx];
      //cout	   << name<< " size " << name.size() << endl;
      cout << "random number "
	   << randomNumber
	   << endl;
      p[idx] = randomNumber;
    ;
      idx++;
      //p++;
    } while (idx < max);
cout << " End of input" << endl<<endl;

}


void InputTestChar(int &max,  char p [] )
{
    char randomChar;
    srand(time(NULL));

  string name;
  //cout << vowels<< " size " << vowels.size() << endl;
  int idx = 0;
   do
    {
      //cout << "enter name " <<endl;
      //cin >> name;
      randomChar = rand()%255;
      //name = testNames[idx];
      //cout	   << name<< " size " << name.size() << endl;
      cout << "random char "
	   << randomChar
	   << endl;
      p[idx] = randomChar;
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


void SwapInt(int idx, int p [])
{
  int ptmp;
  ptmp = p[idx];
  p[idx] = p[idx+1];
  p[idx+1] = ptmp;

}

void SwapDouble(int idx, double p [])
{
  double ptmp;
  ptmp = p[idx];
  p[idx] = p[idx+1];
  p[idx+1] = ptmp;

}

void SwapChar(int idx, char p [])
{
  char ptmp;
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



void ISort(int &max, int p [] )
{
  int swapCount;
  do {
    swapCount = 0;
    for (int i = 0; i < max-1; i++)
      {
	if (p[i] > p[i+1])
	  {
        SwapInt(i, p);
	    swapCount++;
	  }
      }

  } while (swapCount > 0);
}




void DSort(int &max, double p [] )
{
  double swapCount;
  do {
    swapCount = 0;
    for (int i = 0; i < max-1; i++)
      {
	if (p[i] > p[i+1])
	  {
            SwapDouble(i, p);
	    swapCount++;
	  }
      }

  } while (swapCount > 0);
}




void CSort(int &max, char p [] )
{
  int swapCount;
  do {
    swapCount = 0;
    for (int i = 0; i < max-1; i++)
      {
	if (p[i] > p[i+1])
	  {
            SwapChar(i, p);
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
  cout<<endl;
  cout <<setw(10)<< "  name " << "      length " <<"      vowels " << endl;

  for (i = 0; i< max; i++)
    {
      cout << setw(15)
            //<< " idx " << i
	   //<< " name ["
           << p[i].name <<" "
	   << "    "
           << p[i].nameLen
	   << "        " << p[i].numvowels
	   << endl;
      //p++;
    }
}

void OutputDisplayInt(int &max, int p [])
{
  int i;
  cout<<endl;
 // cout <<setw(10)<< "  name " << "      length " <<"      vowels " << endl;

  for (i = 0; i< max; i++)
    {
      cout << setw(15)
            //<< " idx " << i
	   //<< " name ["
           << p[i] <<" "

	   << endl;
      //p++;
    }
}


void OutputDisplayDouble(int &max, double p [])
{
  int i;
  cout<<endl;
 // cout <<setw(10)<< "  name " << "      length " <<"      vowels " << endl;

  for (i = 0; i< max; i++)
    {
      cout << setw(15)
            //<< " idx " << i
	   //<< " name ["
           << p[i] <<" "

	   << endl;
      //p++;
    }
}




void OutputDisplayChar(int &max, char p [])
{
  int i;
  cout<<endl;
 // cout <<setw(10)<< "  name " << "      length " <<"      vowels " << endl;

  for (i = 0; i< max; i++)
    {
      cout << setw(15)
            //<< " idx " << i
	   //<< " name ["
           << p[i] <<" "

	   << endl;
      //p++;
    }
}




int main()
{

    int intAry[10];
    char charAry[10];
    double doubleAry[10];
    int max = 10;


  InputTestInt(max, intAry);
  ISort(max,intAry);

  OutputDisplayInt(max, intAry);
  InputTestChar(max, charAry);
  CSort(max,charAry);
  OutputDisplayChar(max, charAry);
  InputTestDouble(max, doubleAry);
  DSort(max,doubleAry);
  OutputDisplayDouble(max, doubleAry);

  return 0;
