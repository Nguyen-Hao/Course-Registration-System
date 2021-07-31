#include "Header.h"
#include "console.h"
#include "course.h"
#include "staff.h"
#include "student.h"
#include "Semester.h"
#include "DKMon.h"
#include "SchoolYear.h"

int main()
{
	FixConsoleWindow();
	resizeConsole(1200, 600);
	SchoolYear y;
	y = present("SchoolYear.txt");
	//taoDLgia(y); 
	TextColor(224);
	ListLop dsl;	dsl.n = 0;
	ListGV dsgv;	dsgv.pHead = NULL;
	SinhVien sv;
	GiaoVien gv;
	int choice;
	ListCourses dsmon = ReadListCourses(y);
	ReadFileClass(dsl, y);
	ReadFileStudent(dsl, y);
	Read_File_DSGV(dsgv, y);
	UpdateStudent(y);
	UpdateCSV(dsl, y);
	//ViewScoreBoardOfACourse(dsmon, y);
	Menu(dsl, dsgv, dsmon, sv, gv, choice, y);
	//ViewListOfStudentInClass(dsl);
	//ViewScoreBoardOfACourse(dsmon, y);
	return 0;
}
