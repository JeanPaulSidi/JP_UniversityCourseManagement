#include "InPersonCourse.h"
#include <string>

InPersonCourse::InPersonCourse(string courseId, string courseName, string courseInstructor, int roomNumber) 
	: Course(courseId, courseName, courseInstructor)
{
	roomNumber_ = roomNumber;
}

int InPersonCourse::getRoomNumber()
{
	return roomNumber_;
}

string InPersonCourse::displayCourseInformation()
{
	string information = "";

	information += Course::displayCourseInformation();
	information += "Room Number: " + to_string(roomNumber_) + '\n';

	return information;
}
