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
	ListGV dsgv;
	dsgv.pHead = NULL;
	dsl.n = 0;
	SinhVien sv;
	GiaoVien gv;
	//xu_ly_menu_student();
	FixConsoleWindow();
	resizeConsole(1200, 600);
	ReadFileClass(dsl);
	ReadFileStudent(dsl);
	Read_File_DSGV(dsgv);
	UpdateCSV(dsl);
	Menu(dsl,dsgv, sv, gv);
	return 0;
}