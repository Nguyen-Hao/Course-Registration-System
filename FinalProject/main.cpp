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
<<<<<<< HEAD
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
	int x;
=======
	ListLop dsl;			// Dung xoa cai nay khi chay chuong trinh
	dsl.n = 0;				// Dung xoa cai nay khi chay chuong trinh
	ListSV* p = new ListSV;	// Dung xoa cai nay khi chay chuong trinh
	//xu_ly_menu_student();
	FixConsoleWindow();		// Dung xoa cai nay khi chay chuong trinh
	resizeConsole(1200, 600);// Dung xoa cai nay khi chay chuong trinh
	ReadFileClass(dsl);		// Dung xoa cai nay khi chay chuong trinh
	ReadFileStudent(dsl);	// Dung xoa cai nay khi chay chuong trinh
	UpdateCSV(dsl);			// Dung xoa cai nay khi chay chuong trinh
	MenuSV(dsl, p);			// ham de chay menu
	//ListSV* temp = DangNhapSV(dsl);
	//cout << temp->info.Class << endl << temp->info.DateOfBirth << endl;
	//int c = AfterLoginSV(dsl, p);
	//int x;
>>>>>>> 491374b42da0783b0968438f10e0b073c869e24b
	//ViewListOfCourse(x);
	//updateCourse();
	//UpdateStudent();
	///ViewListOfStudentInClass(dsl);
	//ViewListOfClass(dsl);
	//UpdateStudent();
	return 0;
}