// student.cpp
#include <iostream>
#include <sstream>
#include "student.h"

Student::Student(){
  firstName = "";
  lastName = "";
  address = new Address();
  birthDate = new Date();
  gradDate = new Date();
  creditHours = 0;
} // end constructor

Student::~Student(){
  // these were made with new in the constructor so delete them here or they leak
  delete address;
  delete birthDate;
  delete gradDate;
} // end destructor

void Student::init(std::string studentString){
  std::stringstream ss(studentString);
  std::string street, city, state, zip;
  std::string sBirth, sGrad, sCredits;

  std::getline(ss, firstName, ',');
  std::getline(ss, lastName, ',');
  std::getline(ss, street, ',');
  std::getline(ss, city, ',');
  std::getline(ss, state, ',');
  std::getline(ss, zip, ',');
  std::getline(ss, sBirth, ',');
  std::getline(ss, sGrad, ',');
  std::getline(ss, sCredits);

  address->init(street, city, state, zip);
  birthDate->init(sBirth);
  gradDate->init(sGrad);
  creditHours = std::stoi(sCredits);
} // end init

void Student::printStudent(){
  std::cout << firstName << " " << lastName << std::endl;
  address->printAddress();
  std::cout << "DOB: ";
  birthDate->printDate();
  std::cout << "Grad: ";
  gradDate->printDate();
  std::cout << "Credits: " << creditHours << std::endl;
  std::cout << "____________________________________" << std::endl;
} // end printStudent

std::string Student::getLastFirst(){
  return lastName + ", " + firstName;
} // end getLastFirst

std::string Student::getFirstName(){
  return firstName;
} // end getFirstName

std::string Student::getLastName(){
  return lastName;
} // end getLastName

int Student::getCreditHours(){
  return creditHours;
} // end getCreditHours
