#include "Header.h"
#include "console.h"
#include "course.h"
#include "login.h"
#include "staff.h"
#include "student.h"
#include "Semester.h"
#include "DKMon.h"
#include "SchoolYear.h"

int main()
{
	SchoolYear s;
	// ông chỉnh menu chỗ này xíu luôn.
	int n;
	cout << "nhap n: ";
	cin >> n;
	cin.ignore();
	s = present("SchoolYear.txt");
	if (n == 0) // tạo dữ liệu giả để test nhanh
		taoDLgia(s);
	else
		exportFileToImport(s); //tao file sau đó thực hiện nhập
	// 
	TextColor(224);
	ListLop dsl;	dsl.n = 0;
	ListGV dsgv;	dsgv.pHead = NULL;
	SinhVien sv;
	GiaoVien gv;
	int choice;
	ListCourses course = ReadListCourses(s);
	ReadFileClass(dsl, s);
	ReadFileStudent(dsl, s);
	Read_File_DSGV(dsgv, s);
	UpdateCSV(dsl, s);
	AfterLogin(dsl, dsgv, course, sv, gv, choice, s);
	return 0;
}
