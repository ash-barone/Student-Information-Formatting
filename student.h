#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

#include "degree.h"

using namespace std;
 
class Student {
      public:
          //accessors
		  string GetStudentId();
          string GetFirstName();
		  string GetLastName();
		  string GetEmailAddress();
		  int GetAge();
		  int* GetDaysInCourse();

		  //mutator
		  void SetStudentId(string);
		  void SetFirstName(string);
		  void SetLastName(string);
		  void SetEmailAddress(string);
		  void SetAge(int);
		  void SetDaysInCourse(int[3]);
		  void SetDegreeProgram(DegreeProgram);

		  //other functions
		  virtual void Print();
		  virtual DegreeProgram GetDegreeProgram();

		  //constructor
		  Student(string, string, string, string, int, int[3], DegreeProgram);

      private:
		  //only used in Student functions
	      string emailAddress, firstName, lastName, studentId;
		  int age, daysInCourse[3];
          DegreeProgram degreeProgram;
		  
		 

			
};
#endif
