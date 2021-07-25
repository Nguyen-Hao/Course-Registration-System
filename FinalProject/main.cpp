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
	SchoolYear s;
	// ông chỉnh menu chỗ này xíu luôn.
	//cin.ignore();
	s = present("SchoolYear.txt");
	//taoDLgia(s); 
	TextColor(224);
	ListLop dsl;	dsl.n = 0;
	ListGV dsgv;	dsgv.pHead = NULL;
	SinhVien sv;
	GiaoVien gv;
	int choice;
	ListCourses dsmon = ReadListCourses(s);
	ReadFileClass(dsl, s);
	ReadFileStudent(dsl, s);
	Read_File_DSGV(dsgv, s);
	UpdateCSV(dsl, s);
	UpdateStudent(s);
	Menu(dsl, dsgv, dsmon, sv, gv, choice, s);
	return 0;
}
