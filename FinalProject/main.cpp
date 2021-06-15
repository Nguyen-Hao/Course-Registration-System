#include "Header.h"
#include "console.h"
#include "course.h"
#include "login.h"
#include "staff.h"
#include "student.h"
#include "Dk_mon.h"
int main()
{
	TextColor(224);
	ListLop dsl;
	dsl.n = 0;
	ListSV* p = new ListSV;
	//xu_ly_menu_student();
	FixConsoleWindow();
	resizeConsole(1200, 600);
	ReadFileClass(dsl);
	ReadFileStudent(dsl);
	UpdateCSV(dsl);
	//ListSV* temp = DangNhapSV(dsl);
	//cout << temp->info.Class << endl << temp->info.DateOfBirth << endl;
	//int c = AfterLoginSV(dsl, p);
	MenuSV(dsl, p);
	//int x;
	//ViewListOfCourse(x);
	//updateCourse();
	//UpdateStudent();
	//ViewListOfStudentInClass(dsl);
	//ViewListOfClass(dsl);
	return 0;
}