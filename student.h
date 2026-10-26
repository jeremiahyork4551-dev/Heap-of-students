// student.h
// student has an address and two dates

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "address.h"
#include "date.h"

class Student {
  private:
    std::string firstName;
    std::string lastName;
    Address* address;
    Date* birthDate;
    Date* gradDate;
    int creditHours;

  public:
    Student();
    ~Student();
    void init(std::string studentString);
    void printStudent();
    std::string getLastFirst();
    std::string getFirstName();
    std::string getLastName();
    int getCreditHours();
}; // end Student

#endif
