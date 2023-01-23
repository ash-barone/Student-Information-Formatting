#include <iostream>
#include <string>
#include <sstream>

#include "roster.h"

using namespace std;

Student* classRosterArray[5];

//function definitions
//Roster classRoster; 

void Roster::Parse(const string studentData[]) {

	for (int i = 0; i < 5; ++i) {

		//search through studentData strings stopping at each comma to save the substring

		string tempString = studentData[i];// [i] ; //define each temp row to be parsed

		istringstream input(tempString); //sets the input var to be used in getline function and is the row to be parsed within the function

		string tempSubString;
		//sets a place for portion of tempString input to be stored once getline hits a comma and stops taking input for that iteration
		string tempStudentData[9]; //sets place holder for substring of student data to be passed to the student constructor for use in student object creation

		//getline function loop

		for (int j = 0; getline(input, tempSubString, ','); ++j) {
			//cout << j << endl;
			tempStudentData[j] = tempSubString;
			//cout << tempStudentData[j] << endl;

		}

		DegreeProgram studentDegree{};
		if (tempStudentData[8] == "SECURITY") {
			studentDegree = SECURITY;
		}
		else if (tempStudentData[8] == "NETWORK") {
			studentDegree = NETWORK;
		}
		else if (tempStudentData[8] == "SOFTWARE") {
			studentDegree = SOFTWARE;
		}

		//cout << tempStudentData[1] << endl;
		
		Add(tempStudentData[0], tempStudentData[1], tempStudentData[2], tempStudentData[3], std::stoi(tempStudentData[4]), std::stoi(tempStudentData[5]), std::stoi(tempStudentData[6]), std::stoi(tempStudentData[7]), studentDegree);

		
	}
	return;
}
void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

	//move 3 separate course days into single course days array
	int tempCourseDays[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	//cycle through classRosterArray of pointers assigning each position a new student object to point to
	for (int i = 0; i < 5; ++i) {
	    if (classRosterArray[i] == nullptr) {
		    classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, tempCourseDays, degreeProgram);
		    break; //without break john steals all the spots!
	    }
	}
}

void Roster::Remove(string studentIdToRemove) {
	bool removed = false;
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->GetStudentId() == studentIdToRemove) {
			classRosterArray[i] = nullptr;
			//delete classRosterArray[i];
			removed = true;
		}
		// test to see if pointer cleared // cout << classRosterArray[i] << endl;
	}
	if (removed == false) {
		cout << "Student with student ID: " << studentIdToRemove << " could not be found." << endl;
	}
}

void Roster::PrintAll() {
	
	for (int i = 0; i < 5; ++i) {
		Student* tempPtr = classRosterArray[i];
		//cout << tempPtr << endl; //to show pointer and whether it is null or not
		if (tempPtr != nullptr) {
			tempPtr->Print();
		}
		//cout << i << endl; // to show which position in classRosterArray is being printed
	}
	cout << endl;
}

void Roster::PrintDaysInCourseLoop() {
	for (int i = 0; i < 5; ++i) {
		Student* tempStudent = classRosterArray[i];
		if (tempStudent != nullptr) {
			string tempID = tempStudent->GetStudentId();
			PrintAverageDaysInCourse(tempID);
		}
	}
	cout << endl << endl;
}

void Roster::PrintAverageDaysInCourse(string tempID) {
	int averageDaysInCourse;
	for (int i = 0; i < 5; ++i) {
		if (tempID == classRosterArray[i]->GetStudentId()) {
			int* tempDaysInCourseArray = classRosterArray[i]->GetDaysInCourse();
			averageDaysInCourse = (tempDaysInCourseArray[0] + tempDaysInCourseArray[1] + tempDaysInCourseArray[2]) / 3;
			cout << "Average days in course for student with student id " << tempID << ": " << averageDaysInCourse << " days" << endl;
		}
	}
}

void Roster::PrintInvalidEmails() {
	for (int i = 0; i < 5; ++i) {
		string tempEmail = classRosterArray[i]->GetEmailAddress();
		
		//cout << tempEmail << endl; // prints all emails
		
		bool emailValid = false;
		
		if ((tempEmail.find("@") > 0) && (tempEmail.find("@") < 100) && (tempEmail.find(".") > 0) && (tempEmail.find(".") < 100)) {
			
			//cout << tempEmail.find("@")<< endl; TEST
			
			//cout << tempEmail << endl; TEST
			if (tempEmail.find(" ") > 0 && tempEmail.find(" ") < 100)  {
				
				//cout << tempEmail.find(" ") << endl; TEST
				
				//cout << tempEmail << endl; TEST
				
				emailValid = false;
			}
			else {
				emailValid = true;

			}
		}
		if (emailValid == false) {
			cout << "Invalid email: " << tempEmail << endl;
		}
	}
	cout << endl << endl;
}

void Roster::PrintByDegreeProgram(int degreeProgram) {
	for (int i = 0; i < 5; ++i) {
		switch (classRosterArray[i]->GetDegreeProgram()) {
		case 0:
			break;
		case 1:
			break;
		case 2: classRosterArray[i]->Print();
			break;
		}
		
	 }
	cout << endl << endl;
}

Roster::~Roster() {

}
