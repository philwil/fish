#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <string>

using namespace std;

class Number{
public:
  Number(){};
  ~Number(){};
  Number(const Number &n) {
    cout << " copy constructor called " << endl;
    Number1 = n.Number1;
    Number2 = n.Number2;
    Number3 = n.Number3;
  }
  
  void setNumber1(long int n){
    Number1 = n;
  };
  void setNumber2(long int n){
    Number2 = n;
  };
  void setNumber3(long int n){
    Number3 = n;
  };
  long int addNumbers() {
    return Number1 + Number2;
}

  void showNumber() {
    cout<<"Number 1 is : "<<Number1<<" Number 2 is : "<<Number2<<endl;
  }
  
  long int Number1;
  long int Number2;
  long int Number3;
};

class NumberList{
public:
NumberList(){
    numCount = 0;
    cout<<"New Number List"<<endl;
};
~NumberList(){};

void insertNumber (Number num) {
    n[numCount] = num;
    if (numCount < 100) {

    cout<<"Add 1 to Number Count "<<numCount<<endl;
    numCount += 1;
    cout<<"After add 1 to Number Count "<<numCount<<endl;
    }
    cout<<"Number Count : "<<numCount<<endl;

}

void showNumberList () {

    for (int i = 0; i < numCount; i++) {
        cout<<"Position " <<i<< " is";
        n [i].showNumber();
    }

}

Number n [100];
int numCount;



};

int main_loop(NumberList &nl) {

    Number n;

    long int Number;
  cout<<"Enter first number"<<endl;
  cin>>Number;
  n.setNumber1(Number);

  if (Number > 0) {
  cout<<"Enter second number"<<endl;
  cin>>Number;
  n.setNumber2(Number);
if (n.addNumbers() == 1000) {
    return 0;
}

  n.setNumber3(n.addNumbers());

  cout<<"The sum of " <<n.Number1<< " and " <<n.Number2<< " is "<<n.Number3<< endl;
  nl.insertNumber (n);
  }
return n.Number1;
}

int main() {
int rc;
string val;
NumberList nl;
    do{
    rc = main_loop(nl);
    }while (rc > 0);
cout<<"input string to show"<<endl;
cin>>val;
    nl.showNumberList();

return 0;

}
