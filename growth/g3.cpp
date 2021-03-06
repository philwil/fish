

#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

using namespace std;


// A = P(1+r/n)^(n*t)

//n = num times per year
//t = num years


// Compound Interest Formula: A = ( P(1 + (R/N) ) ^ (N*T) )
// pow ((P + P*(r/n)), (N*T)) 

// inputs function

void inputs(double  &money, double &interest, double &goal, int &num) 
{
  cout<<"Enter an amount to invest"<<endl;
  cin>>money;

  cout<<"Enter an annual interest rate"<<endl;
  cin>>interest;
  
  //cout<<"Enter how many years you want calculated"<<endl;
  //cin>>year;

  cout<<"Enter goal"<<endl;
  cin>>goal;

  cout<<"Enter compound factor"<<endl;
  cin>>num;
}

void acalc(double &ans, double ival)
{
    ans = ans + (ans*ival);
    return;
}

double acalc(double &ans, double &interest, double &time, int n, double &goal, vector <double> &ansv)
{
  int t = 0;
  do {
    if((t % n) == 0)
      {
	ansv.push_back(ans);
      }
    ans = ans + ans * interest/(100 * n); 
    t++;
    
  } while (ans < goal);
  
  time = t/n;
  return ans;
}

void output(double ans, double goal, double money, double interest,int num, vector <double> &ansv)

{
  cout << " P " << money << endl;
  cout << " r " << interest << endl;
  cout << " n " << num << endl;
  cout << " Goal " << goal << endl;
  //vector <double>::iterator ansi;
  int z = 0;

  //  for (ansi = ansv->begin(); ansi < ansv->end(); ++ansi)
  for (int i = 0; i<ansv.size(); i++)
    {
      cout<<"  year  "
	//<< setw(2) 
	  << z <<
	" value " << setprecision(5) <<ansv.at(i)<< std::endl;
      z++;
    }

  if( ans> goal)
    {
      cout << " Congrats you met goal and have " << ans-goal << " over" << endl;
    }
  else
    {
      cout << " Sad you failed " << endl;
    }




  cout<<" final cash " <<ans<< std::endl;
}

int main(int args, char *argv[]){

  double money=0.0;
  double interest=0.0;
  int  year=10;
  int num;
  double goal;
  double result;
  double nt;
  double inter=0.0;
  double interv;
  vector <double> ansv;

  int z=0;
  double y;
  double time;
  inputs(money, interest, goal, num) ;
  double ans = money;
  acalc(ans,  interest, time, num, goal, ansv);
  //  cin>>goal;	
  //  double intx = interest/(100 * num);

  
  output(ans, goal, money, interest, num, ansv);
  return 0;

}
