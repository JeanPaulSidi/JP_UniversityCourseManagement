#pragma once
#include <iostream>
using namespace std;


class Course
{
private:
	string courseID_;
	string courseName_;
	string courseInstructor_;

public:
	Course(string courseID, string courseName, string courseInstructor);

public:
	string getCourseID();
	string getCourseName();
	string getCourseInstructor();

public:
	virtual string displayCourseInformation();

};

