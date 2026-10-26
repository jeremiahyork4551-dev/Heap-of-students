// date.cpp
#include <iostream>
#include <sstream>
#include "date.h"

Date::Date(){
  dateString = "";
  month = 0;
  day = 0;
  year = 0;
} // end constructor

void Date::init(std::string dateString){
  this->dateString = dateString;

  std::stringstream ss(dateString);
  std::string sMonth, sDay, sYear;

  std::getline(ss, sMonth, '/');
  std::getline(ss, sDay, '/');
  std::getline(ss, sYear);

  month = std::stoi(sMonth);
  day = std::stoi(sDay);
  year = std::stoi(sYear);
} // end init

void Date::printDate(){
  const std::string months[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
  };

  if (month < 1 || month > 12){
    std::cout << "Invalid date: " << dateString << std::endl;
  } else {
    std::cout << months[month - 1] << " " << day << ", " << year << std::endl;
  } // end if
} // end printDate
