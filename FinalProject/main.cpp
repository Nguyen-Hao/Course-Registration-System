#include "Header.h"
#include "console.h"
#include "course.h"
#include "login.h"
#include "staff.h"
#include "student.h"
#include "Dk_mon.h"
int main()
{
	ListLop dsl;
	dsl.n = 0;
	xu_ly_menu_student();
	FixConsoleWindow();
	resizeConsole(1200, 600);
	ReadFileClass(dsl);
	ReadFileStudent(dsl);
	UpdateCSV(dsl);
	//int x;
	//ViewListOfCourse(x);
	//updateCourse();
	UpdateStudent();
	return 0;
}