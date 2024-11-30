#include "CourseManagement.h"
#include "OnLineCourse.h"
#include "InPersonCourse.h"
#include <string>


void CourseManagement::initializeDataMembers()
{
	courseCounter_ = 0;
	onLineCourseCounter_ = 0;
	inPersonCourseCounter_ = 0;

	for (int i = 0; i < size(pCourse_); i++)
	{
		pCourse_[i] = nullptr;
	}
}

CourseManagement::CourseManagement()
{
	initializeDataMembers();
}

void CourseManagement::deAllocateMemory()
{
	for (int i = 0; i < courseCounter_; i++)
	{
		delete pCourse_[i];
		pCourse_[i] = nullptr;
	}
}

string CourseManagement::addCourse(string courseID, string courseName, string courseInstructor, string platform)
{
	string message = "";

	if (courseCounter_ == size(pCourse_))
	{
		message = "Sorry, you have reached the limit of " + to_string(size(pCourse_)) + " courses.";
	}
	else
	{
		pCourse_[courseCounter_] = new OnLineCourse(courseID, courseName, courseInstructor, platform);
		courseCounter_++;
		onLineCourseCounter_++;
		message = "Course added successfully.";
	}

	return message;
}

string CourseManagement::addCourse(string courseID, string courseName, string courseInstructor, int roomNumber)
{
	string message = "";

	if (courseCounter_ == size(pCourse_))
	{
		message = "Sorry, you have reached the limit of " + to_string(size(pCourse_)) + " courses.";
	}
	else
	{
		pCourse_[courseCounter_] = new InPersonCourse(courseID, courseName, courseInstructor, roomNumber);
		courseCounter_++;
		inPersonCourseCounter_++;
		message = "Course added successfully.";
	}
	return message;
}

string CourseManagement::displayCoursesList()
{
	string list;

	if (courseCounter_ == 0)
	{
		list = "";
	}
	else
	{
		list += "************************* ENROLLED COURSES (" + to_string(courseCounter_) 
			                         + ")" + " *********************\n\n";

		list += "OnLine (" + to_string(onLineCourseCounter_) + ")" + '\n';
		list += "InPerson (" + to_string(inPersonCourseCounter_) + ")" + '\n';
		list += "\n\n";

		for (int i = 0; i < courseCounter_; i++)
		{
			list += "   Course" + to_string(i + 1) + ":" + '\n';

			list += pCourse_[i]->displayCourseInformation();
			list += "\n\n";
		}
		list += "********************************************************************\n";
	}

	return list;
}

void CourseManagement::terminateProgram()
{
	deAllocateMemory();
}
