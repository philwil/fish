// FishTank Demo code

// Phil Wilsihre
// Version 0.1 09/18/2018

#include <iostream>
#include <malloc.h>
#include "myItem.h"
#include "myFish.h"

const int MAX_FISH = 16;
using namespace std;
//gallon is 0.133681 cubic feet,
#define GALLS_PER_CUFT 7.4805
struct FishTank : public MyItem {

  FishTank(): height (1.0), width(1.0), length(1.0), galls(0.0), num_fish(0){
    fishes = NULL;
    cout << "FishTank default constructor called " << endl;};

  FishTank(double h, double w, double d) :height (h), width(w)
					 , length(d), galls(0.0) , fishes(NULL), num_fish(0){
    cout << "FishTank initialized constructor called " << endl;};

  ~FishTank(){
    cout << "FishTank destructor called for name ["<< name<<"]" << endl;};

  double getVolume(void);
  double getGallons(double level);
  double addGallons(double galls);
  double getDepth(void);
  double getHeight(void){return height;};
  int addFish(string name);

private:
  double height;
  double width;
  double length;
  MyFish **fishes;
  int num_fish;
public:
  double depth;
  double galls;

};

double FishTank::getVolume(void)
{
  return (height * width * length)/(12*12*12);
}

double FishTank::getGallons(double level)
{
  double vol =(length * width * level)/(12*12*12);
  return vol  * GALLS_PER_CUFT;
}



double FishTank::addGallons(double g)
{
  double max = getGallons(height);
  if (galls+g > max)
    galls = max;
  else if (galls+g < 0)
    galls = 0;
  else
    galls += g;
  return galls;
}

double FishTank::getDepth(void)
{
  double  v = galls /GALLS_PER_CUFT;
  double a = (width * length)/(12*12);
  cout << " Vol = " << v <<" Cu ft"<< endl;
  cout << " area = " << a<<" Sq ft"<< endl;
  return v *12.0 /a;
}

int FishTank::addFish(string name)
{
  if(num_fish == 0)
    fishes = (MyFish **)malloc(sizeof(MyFish) * MAX_FISH);
  if(num_fish < MAX_FISH)
    { 
      fishes[num_fish] = new MyFish();
      fishes[num_fish]->setName(name);
      num_fish ++;
    }
  else
    {
      cout << " We got too many fishes" << endl;
    }
  return num_fish;

}

int main(int argc, char *arg[])
{
  FishTank ft(12.0,13.0,15.0);
  ft.setName("My Tank");
  cout << " Tank Volune is " << ft.getVolume() << "Cu FT"<< endl;
  cout << " Tank Full Gallons is " << ft.getGallons(ft.getHeight()) << endl;
  ft.addGallons(7.4);
  cout << " Tank Gallons is " << ft.galls << endl;
  cout << " Tank Depth " << ft.getDepth() << endl;
  ft.addFish("Herman");

}

