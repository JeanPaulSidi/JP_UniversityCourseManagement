#pragma once
#include "Course.h"

class OnLineCourse : public Course
{
private:
	string Platform_;

public:
	OnLineCourse(string courseID, string courseName, string courseInstructor, string platform);

public:
	string getPlatform();

public:
	string displayCourseInformation() override;

};

