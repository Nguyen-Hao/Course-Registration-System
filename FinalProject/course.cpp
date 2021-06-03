#include "course.h"
#include "Header.h"

void createNewCourse()
{
	fstream file;
	file.open(FILECOURSES, ios::app);//Ghi tiếp 
	Course a;
	cout << "Nhap hoc ky: ";
	cin >> a.Sememster;
	cin.ignore();
	cout << "Nhap ID khoa hoc: ";
	cin.get(a.ID, 20, '\n');
	cin.ignore();
	cout << "Nhap ten khoa hoc: ";
	cin.get(a.Name, 50, '\n');
	cin.ignore();
	cout << "Nhap ten giao vien: ";
	cin.get(a.TeacherName, 50, '\n');
	cout << "Nhap so tin chi: ";
	cin >> a.NumOfCredits;
	cout << "Nhap so luong sinh vien toi da: ";
	cin >> a.MaxNumOfStudents;
	cin.ignore();
	cout << "Nhap buoi hoc thu 1: ";
	cout << "Thu: ";
	cin.get(a.Session1.Thu, 10, '\n');
	cout << "Gio: ";
	cin.ignore();
	cin.get(a.Session1.Gio, 10, '\n');
	cin.ignore();
	cout << "Nhap buoi hoc thu 2: ";
	cout << "Thu: ";
	cin.get(a.Session2.Thu, 10, '\n');
	cout << "Gio: ";
	cin.ignore();
	cin.get(a.Session2.Gio, 10, '\n');
	cin.ignore();
	file << a.Sememster << endl;
	file << a.ID << endl;
	file << a.Name << endl;
	file << a.TeacherName << endl;
	file << a.NumOfCredits << endl;
	file << a.MaxNumOfStudents << endl;
	file << a.Session1.Thu << endl;
	file << a.Session1.Gio << endl;
	file << a.Session2.Thu << endl;
	file << a.Session2.Gio << endl;
	file.close();
}