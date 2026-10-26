// address.cpp
#include <iostream>
#include "address.h"

Address::Address(){
  street = "";
  city = "";
  state = "";
  zip = "";
} // end constructor

void Address::init(std::string street, std::string city,
                   std::string state, std::string zip){
  this->street = street;
  this->city = city;
  this->state = state;
  this->zip = zip;
} // end init

void Address::printAddress(){
  std::cout << street << std::endl;
  std::cout << city << " " << state << ", " << zip << std::endl;
} // end printAddress
