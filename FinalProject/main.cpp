#include "Header.h"
#include "console.h"
#include "course.h"
#include "login.h"
#include "staff.h"
#include "student.h"
int main()
{
	FixConsoleWindow();
	resizeConsole(1400, 600);
	//int x;
	//ViewListOfCourse(x);
	updateCourse();
	return 0;
}