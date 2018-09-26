
// Rohan Sachdev
// MoneyGrowth Code
// 9-24-2018
// Advanced CS - Potter 2018
// Program 2

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
void inputs( double  &money, double &interest, double &year, double &goal, double &num) 
{
  cout<<"Enter an amount to invest"<<endl;
  cin>>money;

  cout<<"Enter an annual interest rate"<<endl;
  cin>>interest;
  
  cout<<"Enter how many years you want calculated"<<endl;
  cin>>year;

  cout<<"Enter goal"<<endl;
  cin>>goal;

  cout<<"Enter compound factor"<<endl;
  cin>>num;
}

int main(int args, char *argv[]){

  double money=0.0;
  double interest=0.0;
  double inter=0.0;
  double year;
  double num;
  double goal;
  double result;
  double nt;

  int C=0;
  double y;
  inputs(money, interest, year, goal, num) ;


  inter = interest;
  do {
    nt = year * num;
    result =  money * pow((1 + (inter/(100 *num))),(nt));
    inter += 0.1;
  } while (result < goal);

  inter = interest;
  y = year;
  do {
    nt = y * num;
    result =  money * pow((1 + (inter/(100 *num))),(nt));
    y += 0.1;
  } while (result < goal);

  //result = pow(3,2);
  cout<<"final result "<< result << "  " <<endl;
  cout<<"final interest "<< inter << "  " <<endl;
  cout<<"final years "<< y << "  " <<endl;
  //  cin>>goal;

  do{
    money+=(money*(interest/(100 * num)));
    C++;
    
  }while (C<(year*num));

  // do{
  //y=money+(money*interest/100);
  //C++;
    
  // }while (C<=year);
  
  cout<<" final cash " <<money<< std::endl;
  

  //std::system("pause");
}
