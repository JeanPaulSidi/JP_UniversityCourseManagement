#include "Course.h"

Course::Course(string courseID, string courseName, string courseInstructor)
{
	courseID_ = courseID;
	courseName_ = courseName;
	courseInstructor_ = courseInstructor;
}

string Course::getCourseID()
{
	return courseID_;
}

string Course::getCourseName()
{
	return courseName_;
}

string Course::getCourseInstructor()
{
	return courseInstructor_;
}

string Course::displayCourseInformation()
{
	string information = "";

	information += "ID: " + courseID_ + '\n';
	information += "Name: " + courseName_ + '\n';
	information += "Instructor: " + courseInstructor_ + '\n';

	return information;
}
