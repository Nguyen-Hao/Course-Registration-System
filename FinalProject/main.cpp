#include "Header.h"
#include "console.h"
#include "course.h"
#include "staff.h"
#include "student.h"
#include "Semester.h"
#include "DKMon.h"
#include "SchoolYear.h"
#include "Menu.h"

int main()
{
	FixConsoleWindow();
	resizeConsole(1200, 650);
	TextColor(224);
	SchoolYear y = SchoolYearPresent("SchoolYear.txt"); 
	listSemester l;
	InitListSemester(l);
	readListSemester(l, y);
	int se = getSemester(l, y);
	ListLop dsl;	dsl.n = 0;
	ListGV dsgv;	dsgv.pHead = NULL;
	SinhVien sv;
	GiaoVien gv;
	int choice;
	ListCourses dsmon = ReadListCourses(se, y);
	ReadFileClass(dsl, y);
	ReadFileStudent(dsl, y);
	ReadFileDSGV(dsgv, y);
	UpdateStudent(y);
	UpdateCSV(dsl, y);
	Menu(dsl, dsgv, dsmon, sv, gv, choice, se, y, l);
	system("pause");
	return 0;
}
