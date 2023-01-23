#include <iostream>
#include <string>

#include "student.h"

using namespace std;

//accessor definitions
string Student::GetStudentId() {
	return studentId;
}

string Student::GetFirstName() {
	return firstName;
}

string Student::GetLastName() {
	return lastName;
}

string Student::GetEmailAddress() {
	return emailAddress;
}
int Student::GetAge() {
	return age;
}

int* Student::GetDaysInCourse() {
	return daysInCourse;
}

DegreeProgram Student::GetDegreeProgram() {
	return Student::degreeProgram; //FIXME: Student:: ?
}



//mutator definitions
void Student::SetStudentId(string tempStudentId) {
	studentId = tempStudentId;
}

void Student::SetFirstName(string tempFirstName) {
	firstName = tempFirstName;
}

void Student::SetLastName(string tempLastName) {
	lastName = tempLastName;
}

void Student::SetEmailAddress(string tempEmailAddress) {
	emailAddress = tempEmailAddress;
}

void Student::SetAge(int tempAge) {
	age = tempAge;
}

void Student::SetDaysInCourse(int* tempDaysInCourse) {
	for (int i = 0; i < 3; i++) {
		daysInCourse[i] = tempDaysInCourse[i];
	}
}

void Student::SetDegreeProgram(DegreeProgram tempDegreeProgram) {
	degreeProgram = tempDegreeProgram;
}


//constructor
Student::Student(string tempStudentId, string tempFirstName, string tempLastName, string tempEmailAddress, int tempAge, int tempDaysInCourse[3], DegreeProgram tempDegreeProgram)
{
	SetStudentId(tempStudentId);
	SetFirstName(tempFirstName);
	SetLastName(tempLastName);
	SetEmailAddress(tempEmailAddress);
	SetAge(tempAge);
	SetDaysInCourse(tempDaysInCourse);
	SetDegreeProgram(tempDegreeProgram);
}

//print each student
void Student::Print() {
	int* daysInCourse = GetDaysInCourse();

	cout << "Student ID: " << GetStudentId() << "\t";
	cout << "First Name: " << GetFirstName() << "\t";
	cout << "Last Name: " << GetLastName() << "\t";
	cout << "Age: " << GetAge() << "\t";
	cout << "Days in Course: (" << daysInCourse[0] << "," << daysInCourse[1] << "," << daysInCourse[2] << ")\t";
    cout << "Degree Program: ";
	switch (Student::GetDegreeProgram()) {
	     case 0: cout << "Security";
		         break;
	     case 1: cout << "Networking";
		         break;
	     case 2: cout << "Software";
		         break;
	}
	cout << endl;
}
