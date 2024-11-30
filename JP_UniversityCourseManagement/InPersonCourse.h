#pragma once
#include "Course.h"

class InPersonCourse : public Course
{
private:
	int roomNumber_;

public:
	InPersonCourse(string courseId, string courseName, string courseInstructor, int roomNumber);

public:
	int getRoomNumber();

public:
	string displayCourseInformation() override;
};

