#include "Header.h"
#include "console.h"
#include "course.h"
#include "login.h"
#include "staff.h"
#include "student.h"
#include "Dk_mon.h"
#include"Semester.h"
#include "Menu.h"
int main()
{
	ListLop dsl;
	List_GV dsgv;
	dsgv.pHead = NULL;
	dsl.n = 0;
	ListSV* p = new ListSV;
	//xu_ly_menu_student();
	FixConsoleWindow();
	resizeConsole(1200, 600);
	ReadFileClass(dsl);
	ReadFileStudent(dsl);
	Read_File_DSGV(dsgv);
	UpdateCSV(dsl);
	MenuSV(dsl, p, dsgv);
	//ListSV* temp = DangNhapSV(dsl);
	//cout << temp->info.Class << endl << temp->info.DateOfBirth << endl;
	//int c = AfterLoginSV(dsl, p);
	//int x;
	//ViewListOfCourse(x);
	//updateCourse();
	//UpdateStudent();
	///ViewListOfStudentInClass(dsl);
	//ViewListOfClass(dsl);
	//UpdateStudent();
	return 0;
}