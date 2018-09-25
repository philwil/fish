// My Item class

#ifndef __MYFISH_H
#define __MYFISH_H

#include <string>
#include <iostream>

static int g_fish_ident = 0;
struct MyFish {

  MyFish() {
    std::cout << "MyFish constructor called " << std::endl;
    ident = g_fish_ident++;};
  MyFish(std::string fname) {
    std::cout << "MyFish constructor called  name [" 
	      << fname 
	      << "] ptr "<< this << std::endl;
    name = fname;
    ident = g_fish_ident++;};

  ~MyFish(){
    std::cout << "MyFish destructor called name [" << name << "]" 
	      << " Id " << ident
	      << " ptr " << this
	      << std::endl;};

  void setName(std::string fname){ name = fname;};
  void setType(std::string ftype){ type = ftype;};
  std::string getName(){ return name;};
  
  std::string name;
  std::string type;
  int ident;
  double weight;
  double age;

};

#endif
