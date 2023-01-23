#include <iostream>
#include <string>
#include <sstream>

#include "student.h"

using namespace std;

class Roster {
public:
	//functions
	void Parse(const string studentData[]);
	void Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void Remove(string studentID);
	void PrintAll();
	void PrintDaysInCourseLoop();
	void PrintAverageDaysInCourse(string tempID);
	void PrintInvalidEmails();
	void PrintByDegreeProgram(int degreeProgram);

	//class roster array for which to populate student
	Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };

	~Roster();
};
