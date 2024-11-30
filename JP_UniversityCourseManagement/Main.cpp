#include <iostream>
#include <conio.h>
#include <string>
#include "CourseManagement.h"

using namespace std;


void displayIntroduction()
{

	cout << "*************************************************" << endl;
	cout << "*                                               *" << endl;
	cout << "*                                               *" << endl;
	cout << "*          UNISERSITY COURSE MANAGEMENT         *" << endl;
	cout << "*                                               *" << endl;
	cout << "*                                               *" << endl;
	cout << "*************************************************" << endl;
	cout << endl;
	cout << endl;
	cout << "Press any key to start the program... ";

	_getch();
	system("cls");

}

void displayMenu()
{
	cout << "What would you like to do?" << endl;
	cout << endl;
	cout << "1. Add OnLine Course" << endl;
	cout << "2. Add InPerson Course" << endl;
	cout << "3. Display Enrolled Courses " << endl;
	cout << "4. Exit" << endl;
	cout << endl;
}

int getMenuChoice()
{
	int choice;

	cout << "Enter your choice: ";
	cin >> choice;

	while (cin.fail() || choice < 1 || choice > 4)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << endl;
		cout << "Invalid input; Please enter whole number between  1 and 4: ";
		cin >> choice;
	}

	return choice;
}

void returnToMenu()
{
	cout << endl;
	cout << "Press any key to return to the menu... ";
	_getch();
	system("cls");

}

void getNewCourseInformation(string* pcourseID, string* pcourseName, string* pcourseInstructor, string* pPlatform) 
{
	cout << "Adding new OnLine Course..." << endl;
	cout << endl;
	cout << "Enter the Course ID: ";
	cin.ignore(INT_MAX, '\n');
	getline(cin, *pcourseID);
	cout << "Enter the Course Name: ";
	getline(cin, *pcourseName);
	cout << "Enter the Course Instructor: ";
	getline(cin, *pcourseInstructor);
	cout << "Enter the Course Platform: ";
	getline(cin, *pPlatform);
}

void getNewCourseInformation(string* pcourseID, string* pcourseName, string* pcourseInstructor, int* pRoomNumber) 
{
	cout << "Adding new InPerson Course..." << endl;
	cout << endl;
	cout << "Enter the Course ID: ";
	cin.ignore(INT_MAX, '\n');
	getline(cin, *pcourseID);
	cout << "Enter the Course Name: ";
	getline(cin, *pcourseName);
	cout << "Enter the Course Instructor: ";
	getline(cin, *pcourseInstructor);

	cout << "Enter the Room Number: ";
	cin >> *pRoomNumber;

	while (cin.fail() || *pRoomNumber <= 0)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << endl;
		cout << "Invalid input. Please try again. " << endl;
		cout << "Room Number: ";
		cin >> *pRoomNumber;
	}
}

int main() 
{
	string courseID = "";
	string courseName = "";
	string courseInstructor = "";
	string platform = "";
	int roomNumber = 0;

	int MenuChoice;
	string message = "";
	string list = "";

	while (true)
	{
		displayIntroduction();

		CourseManagement courseManager;

		cout << "Welcome back!" << endl;

		do
		{
			displayMenu();
			MenuChoice = getMenuChoice();

			switch (MenuChoice)
			{
			case 1:
				system("cls");
				getNewCourseInformation(&courseID, &courseName, &courseInstructor, &platform);
				message = courseManager.addCourse(courseID, courseName, courseInstructor, platform);
				cout << endl;
				cout << message << endl;
				returnToMenu();
				break;

			case 2:
				system("cls");
				getNewCourseInformation(&courseID, &courseName, &courseInstructor, &roomNumber);
				message = courseManager.addCourse(courseID, courseName, courseInstructor, roomNumber);
				cout << endl;
				cout << message << endl;
				returnToMenu();
				break;

			case 3:
				system("cls");
				list = courseManager.displayCoursesList();

				if (list == "")
				{
					cout << "You are not enrolled. Start adding courses." << endl;
				}
				else
				{
					cout << list << endl;
				}

				returnToMenu();
				break;

			case 4:
				courseManager.terminateProgram();
				system("cls");
				break;

			default:
				break;
			}

		} while (MenuChoice != 4);

	}

	return 0;
}