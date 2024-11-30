#include "OnLineCourse.h"

OnLineCourse::OnLineCourse(string courseID, string courseName, string courseInstructor, string platform) 
	: Course(courseID, courseName, courseInstructor)
{
	Platform_ = platform;
}

string OnLineCourse::getPlatform()
{
	return Platform_;
}

string OnLineCourse::displayCourseInformation()
{
	string information = "";

	information += Course::displayCourseInformation();
	information += "Platform: " + Platform_ + '\n';

	return information;
}
