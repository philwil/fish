// My Item class

#ifndef __MYITEM_H
#define __MYITEM_H

#include <string>
#include <iostream>

struct MyItem {

  MyItem(){
    std::cout << "MyItem constructor called " << std::endl;};
  ~MyItem(){
    std::cout << "MyItem destructor called name [" << name << "]" << std::endl;};
  void setName(std::string n) {
    name = n;};

  
  std::string name;
  int ident;

};

#endif
