#include "Header.h"
#include "console.h"
#include "course.h"
#include "login.h"
#include "staff.h"
#include "student.h"
#include "Dk_mon.h"
#include "Semester.h"
#include "DKMon.h"

int main()
{
	TextColor(224);
	ListLop dsl;	dsl.n = 0;
	ListGV dsgv;	dsgv.pHead = NULL;
	SinhVien sv;
	GiaoVien gv;
	int choice;
	ListCourses course = ReadListCourses();
	ReadFileClass(dsl);
	ReadFileStudent(dsl);
	Read_File_DSGV(dsgv);
	UpdateCSV(dsl);
	//updateAStudentResult();
	//string s;
	//cin >> s;
	//ViewScoreBoardOfACourse(course, s);
	char s[30] = "20CTT2";
	ViewScoreOfAClass(dsl, course, s);
	//export_list_student_in_a_course_to_csv();
	//ExportListStudentInCourseToEnterScore();
	//string s;
	//cin >> s;
	//system("cls");
	//ViewScoreBoardOfACourse(course, s);
	/*
	FixConsoleWindow();
	resizeConsole(1200, 600);
	ReadFileClass(dsl);
	ReadFileStudent(dsl);
	Read_File_DSGV(dsgv);
	UpdateCSV(dsl);
	AfterLogin(dsl, dsgv, course, sv, gv, choice);*/
	return 0;
}
