// date.h
// takes a mm/dd/yyyy string and prints it out with the month name

#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
  private:
    std::string dateString;
    int month;
    int day;
    int year;

  public:
    Date();
    void init(std::string dateString);
    void printDate();
}; // end Date

#endif
