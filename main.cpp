// main.cpp
// loads students from students.csv into a vector of Student pointers
// and lets the user print, search, and sort them from a menu

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "date.h"
#include "address.h"
#include "student.h"

void loadStudents(std::vector<Student*>& students);
void printStudents(std::vector<Student*>& students);
void showStudentNames(std::vector<Student*>& students);
void findStudent(std::vector<Student*>& students);
void delStudents(std::vector<Student*>& students);
std::string menu();

// sorting (blackbelt)
bool compareLastName(Student* a, Student* b);
bool compareFirstName(Student* a, Student* b);
bool compareCredits(Student* a, Student* b);

int main(){
  std::vector<Student*> students;
  loadStudents(students);

  bool keepGoing = true;
  while (keepGoing){
    std::string choice = menu();

    if (choice == "0"){
      keepGoing = false;
    } else if (choice == "1"){
      showStudentNames(students);
    } else if (choice == "2"){
      printStudents(students);
    } else if (choice == "3"){
      findStudent(students);
    } else if (choice == "4"){
      std::sort(students.begin(), students.end(), compareLastName);
    } else if (choice == "5"){
      std::sort(students.begin(), students.end(), compareFirstName);
    } else if (choice == "6"){
      std::sort(students.begin(), students.end(), compareCredits);
    } else {
      std::cout << "Invalid choice, please try again." << std::endl;
    } // end if
  } // end while

  delStudents(students);
  return 0;
} // end main

void loadStudents(std::vector<Student*>& students){
  std::ifstream inFile("students.csv");
  if (!inFile.is_open()){
    std::cout << "Could not open students.csv" << std::endl;
    return;
  } // end if

  std::string line;
  while (std::getline(inFile, line)){
    // skip blank lines (like a trailing newline at the end of the file)
    if (line.empty() || line == "\r"){
      continue;
    } // end if
    Student* student = new Student();
    student->init(line);
    students.push_back(student);
  } // end while

  inFile.close();
} // end loadStudents

void printStudents(std::vector<Student*>& students){
  for (Student* student : students){
    student->printStudent();
  } // end for
} // end printStudents

void showStudentNames(std::vector<Student*>& students){
  for (Student* student : students){
    std::cout << student->getLastFirst() << std::endl;
  } // end for
} // end showStudentNames

void findStudent(std::vector<Student*>& students){
  std::string search;
  std::cout << "last name of student: ";
  std::getline(std::cin, search);

  bool found = false;
  for (Student* student : students){
    // find returns npos when the search string is not in the last name
    if (student->getLastName().find(search) != std::string::npos){
      student->printStudent();
      found = true;
    } // end if
  } // end for

  if (!found){
    std::cout << "No students found matching \"" << search << "\"" << std::endl;
  } // end if
} // end findStudent

void delStudents(std::vector<Student*>& students){
  for (Student* student : students){
    delete student;
  } // end for
  students.clear();
} // end delStudents

std::string menu(){
  std::string choice;
  std::cout << std::endl;
  std::cout << "0) quit" << std::endl;
  std::cout << "1) print all student names" << std::endl;
  std::cout << "2) print all student data" << std::endl;
  std::cout << "3) find a student" << std::endl;
  std::cout << "4) sort by last name" << std::endl;
  std::cout << "5) sort by first name" << std::endl;
  std::cout << "6) sort by credit hours" << std::endl;
  std::cout << std::endl;
  std::cout << "please choose 0-6: ";
  // if input ends (ctrl-D), treat it as quit so the loop doesn't run forever
  if (!std::getline(std::cin, choice)){
    choice = "0";
  } // end if
  return choice;
} // end menu

bool compareLastName(Student* a, Student* b){
  return a->getLastName() < b->getLastName();
} // end compareLastName

bool compareFirstName(Student* a, Student* b){
  return a->getFirstName() < b->getFirstName();
} // end compareFirstName

bool compareCredits(Student* a, Student* b){
  // descending, so most credit hours comes first
  return a->getCreditHours() > b->getCreditHours();
} // end compareCredits
