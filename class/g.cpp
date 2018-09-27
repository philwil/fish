

#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

using namespace std;

#if 0
void input(double &principle, double &rate, int &compound, double &goal)
{
    //double calculation (double principle, double rate, int compound, double goal, double amount)
    double exponent = compound * time;
    cout<<"Exponent: "<<exponent<<endl;
    double base = 1 + (rate/compound);
    cout<<"Base: "<<base<<endl;
    double value = amount * principle;
    return value;
}

output (double principle, double rate, int compound, double goal, double amount)
{
    int time = 1;
    double amount;
    vector <double> output;


}
// A = P(1+r/n)^(n*t)

//n = num times per year
//t = num years


// Compound Interest Formula: A = ( P(1 + (R/N) ) ^ (N*T) )
// pow ((P + P*(r/n)), (N*T)) 
int main ()
{
    double calculation;
    double rate;
    int compound;
    double goal;

    input (double principle, double rate, int compound, double goal)
cout<<rate;
output(double principle, double rate, int compound, double goal)


    return 0;
}
#endif

// inputs function

void inputs( double  &money, double &interest, double &goal, double &num) 
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

double acalc( double ans , double ival)
{
    ans = ans + (ans*ival);
    return ans;
}

int main(int args, char *argv[]){

  double money=0.0;
  double interest=0.0;
  int  year=10;
  double num;
  double goal;
  double result;
  double nt;
  double inter=0.0;
  double interv;
  vector <double> ansv;

  int z=0;
  double y;

  inputs(money, interest, goal, num) ;


  inter = interest;
  do {
    nt = year * num;
    result =  money * pow((1 + (inter/(100 *num))),(nt));
    inter += 0.1;
  } while (result < goal);
  interv = inter;


  inter = interest;
  y = year;
  do {
    nt = y * num;
    result =  money * pow((1 + (inter/(100 *num))),(nt));
    y += 0.1;
  } while (result < goal);

  //result = pow(3,2);
  cout<<"final result "<< result << "  " <<endl;
  cout<<"final interest "<< interv << "  " <<endl;
  cout<<"final years "<< y << "  " <<endl;
  //  cin>>goal;	
  double intx = interest/(100 * num);
  double ans = money;
  cout << " P " << money << endl;
  cout << " r " << interest << endl;
  cout << " n " << num << endl;
  cout << " Goal " << goal << endl;
  z = 0;
  int done = 0;
  do{
//    money = money + (money*(interest/(100 * num)));
    //cout <<" value "<< ans << endl;
    if ((z % 12) == 0)
	{
	  ansv.push_back(ans);
          cout <<" value "<< ans << " years " << z/num << "  " <<endl;
          if ( ans > goal) done = 1;
       }
    ans  = acalc(ans, intx); 

    z++;
    
//  }while (z/12<=(year) && (ans < goal));
  }while (!done);

if( ans> goal)
{
  cout << " Congrats you met goal and have " << ans-goal << " over" << endl;
}
else
{
  cout << " Sad you failed " << endl;

}
  //cout <<" value "<< ans << " years " << z/num << "  " <<endl;
  // do{
  //y=money+(money*interest/100);
  //C++;
    
  // }while (C<=year);
  
  cout<<" final cash " <<ans<< std::endl;
  

  //std::system("pause");
}
