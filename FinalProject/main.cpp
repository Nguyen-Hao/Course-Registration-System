#include "Header.h"
#include "console.h"
#include "course.h"
#include "login.h"
#include "staff.h"
#include "student.h"
int main()
{
	ListLop dsl;
	dsl.n = 0;
	FixConsoleWindow();
	resizeConsole(1400, 600);
	//CreateCourseRegistrationSession();
	//ReadFileClass(dsl);
	//ReadFileStudent(dsl);
	//UpdateCSV(dsl);
	//int x;
	//ViewListOfCourse(x);
	//updateCourse();
	UpdateStudent();
	return 0;
}