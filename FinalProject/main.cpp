#include "Header.h"
#include "console.h"
#include "course.h"
#include "login.h"
#include "staff.h"
#include "student.h"
#include "Dk_mon.h"
#include"Semester.h"
#include"DKMon.h"
int main()
{
	//ListLop dsl;
	//ListGV dsgv;
	//dsgv.pHead = NULL;
	//dsl.n = 0;
	//ListSV* p = new ListSV;
	//xu_ly_menu_student();
	//FixConsoleWindow();
	//resizeConsole(1200, 600);
	//ReadFileClass(dsl);
	//ReadFileStudent(dsl);
	//Read_File_DSGV(dsgv);
	//UpdateCSV(dsl);
	//MenuSV(dsl, p, dsgv);
	//int x;
	//ListLop dsl;			// Dung xoa cai nay khi chay chuong trinh
	//dsl.n = 0;				// Dung xoa cai nay khi chay chuong trinh
	//ListSV* p = new ListSV;	// Dung xoa cai nay khi chay chuong trinh
	//xu_ly_menu_student();
	//FixConsoleWindow();		// Dung xoa cai nay khi chay chuong trinh
	//resizeConsole(1200, 600);// Dung xoa cai nay khi chay chuong trinh
	//ReadFileClass(dsl);		// Dung xoa cai nay khi chay chuong trinh
	//ReadFileStudent(dsl);	// Dung xoa cai nay khi chay chuong trinh
	//UpdateCSV(dsl);			// Dung xoa cai nay khi chay chuong trinh
	//MenuSV(dsl, p);			// ham de chay menu
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
	ListCourses l;
	initListCourses(l);
	SinhVien S;
	fstream file;
	file.open("Text.txt", ios::in);
	file.getline(S.Class, 10);
	file.getline(S.ID, 10);
	file.getline(S.pass, 20);
	file.getline(S.FirstName, 20);
	file.getline(S.LastName, 20);
	file.getline(S.Gender, 20);
	file.getline(S.DateOfBirth, 20);
	file.getline(S.SocialID, 20);
	for (int i = 0; i < 3; i++)
	{
		file >> S.begin[i];
	}
	file.ignore();
	file >> S.YearStudent;
	file.ignore();
	file >> S.Semester;
	file.ignore();
	file.close();
	dangki(l, S);
	//view_Enrol_Course(S);
	//ViewListOfCourse();
	//eraser_erol_course(S);
	return 0;
}