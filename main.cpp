#include <iostream>
#include <cstdlib>
#include <string>

#include "roster.h"
#include "student.h"


using namespace std;

int main() {
	Roster classRoster;

	const string studentData[5] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Ashley,Barone,abaro20@wgu.edu,27,19,21,31,SOFTWARE"
	};
	// test line // cout << studentData[1];

	//printing course title, prog lang used, WGU student id, my name
	cout << "C867 Scripting and Programming Applications" << endl;
	cout << "C++ Project" << endl;
	cout << "002660549" << endl;
	cout << "Ashley Barone" << endl;
	cout << endl << endl;

	//parse studentData array
	classRoster.Parse(studentData);

	//print all studentData
	classRoster.PrintAll();

	//parse then print invalid emails
	classRoster.PrintInvalidEmails();

	//loop through all students then print average days in course for each 
	classRoster.PrintDaysInCourseLoop();
	//classRoster.PrintAverageDaysInCourse("A3"); //this works but must loop as above

	//print all students by degree program specified
	classRoster.PrintByDegreeProgram(2);
	 
	//remove a student, print, then check to see that it has been removed for sure
	classRoster.Remove("A3");
	classRoster.PrintAll();
	classRoster.Remove("A3");

	return 0;
}
