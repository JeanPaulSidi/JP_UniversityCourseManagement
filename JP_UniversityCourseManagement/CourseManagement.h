#pragma once
#include "Course.h"

class CourseManagement
{
	Course* pCourse_[5];
	int courseCounter_;
	int onLineCourseCounter_;
	int inPersonCourseCounter_;

public:
	CourseManagement();

private:
	void initializeDataMembers();

	void deAllocateMemory();

public:
	string addCourse(string courseID, string courseName, string courseInstructor, string platform);

	string addCourse(string courseID, string courseName, string courseInstructor, int roomNumber);

	string displayCoursesList();

	void terminateProgram();
};

