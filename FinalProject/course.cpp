#include "course.h"
#include "Header.h"
#include "SchoolYear.h"
#include "console.h"
#include <string>
#include <string.h>
#include "Semester.h"
#include "DKMon.h"
void initListCourses(ListCourses& list)
{
	list.head = NULL;
}

void createNewCourse(int semester, const SchoolYear& Y)
{
	fstream file;
	file.open(to_string(semester)+Y.ListCourses, ios::app);
	Course a;
	a.Sememster = semester;
	cout << "Nhap ID khoa hoc: ";
	getline(cin, a.ID);
	cout << "Nhap ten khoa hoc: ";
	getline(cin, a.Name);
	cout << "Nhap ten giao vien: ";
	getline(cin, a.TeacherName);
	cout << "Nhap so tin chi: ";
	cin >> a.NumOfCredits;
	cout << "Nhap so luong sinh vien toi da: ";
	cin >> a.MaxNumOfStudents;
	cout << "Nhap buoi hoc thu 1: ";
	do
	{
		cout << "Thu (2-8): ";
		cin >> a.Session1.thu;
	} while (a.Session1.thu < 2 || a.Session1.thu > 8);
	do
	{
		cout << "Gio: ";
		cin >> a.Session1.gio;
		cout << "Phut: ";
		cin >> a.Session1.phut;
	} while (!isTime(a.Session1.gio, a.Session1.phut, 0));
	cout << "Nhap buoi hoc thu 2: ";
	do
	{
		cout << "Thu (2-8): ";
		cin >> a.Session2.thu;
	} while (a.Session2.thu < 2 || a.Session2.thu > 8);
	do
	{
		cout << "Gio: ";
		cin >> a.Session2.gio;
		cout << "Phut: ";
		cin >> a.Session2.phut;
	} while (!isTime(a.Session2.gio, a.Session2.phut, 0));
	cin.ignore();
	ofstream g;
	g.open(to_string(semester)+Y.StudentOfSubject, ios::app);
	g << a.ID << endl;
	g.close();
	file << a.Sememster << endl;
	file << a.ID << endl;
	file << a.Name << endl;
	file << a.TeacherName << endl;
	file << a.NumOfCredits << endl;
	file << a.MaxNumOfStudents << endl;
	file << a.Session1.thu << endl;
	file << a.Session1.gio << endl;
	file << a.Session1.phut << endl;
	file << a.Session2.thu << endl;
	file << a.Session2.gio << endl;
	file << a.Session2.phut << endl;
	file.close();
}
void AddTailListCourse(ListCourses& l, Course co)
{
	NodeCourse* p = new NodeCourse;
	p->course = co;
	p->next = NULL;
	if (l.head == NULL)
		l.head = p;
	else
	{
		NodeCourse* k = l.head;
		while (k->next != NULL)
			k = k->next;
		k->next = p;
	}
}
ListCourses ReadListCourses(int se, const SchoolYear& Y)
{
	ListCourses temp;
	initListCourses(temp);
	ifstream file;
	file.open(to_string(se)+Y.ListCourses);
	Course temp0;
	while (file >> temp0.Sememster)
	{
		file.ignore();
		getline(file, temp0.ID);
		getline(file, temp0.Name);
		getline(file, temp0.TeacherName);
		file >> temp0.NumOfCredits;
		file >> temp0.MaxNumOfStudents;
		file >> temp0.Session1.thu;
		file >> temp0.Session1.gio;
		file >> temp0.Session1.phut;
		file >> temp0.Session2.thu;
		file >> temp0.Session2.gio;
		file >> temp0.Session2.phut;
		AddTailListCourse(temp, temp0);
	}
	file.close();
	return temp;
}

void ViewListOfCourse(int se, const SchoolYear& Y)
{
	ifstream f;
	f.open(to_string(se)+Y.ListCourses);
	f.seekg(0, ios::end);
	int i = f.tellg();
	f.close();
	int STT = 0;
	if (i == 0)
	{
		cout << "Chua co khoa hoc nao trong danh sach" << endl;
	}
	else
	{
		gotoxy(20, 3); cout << "+--------------------------------------------------------------------------------------------------------------------------------+" << endl;
		gotoxy(20, 4); cout << char(124) << "  " << setw(10) << left << "Ma mon hoc" << char(124) << "  " << setw(30) << left << "Ten mon hoc" << char(124) << "  " << setw(25) << left << "Ten GV" << char(124) << "  " << setw(8) << left << "So TC" << char(124) << "  " << setw(15) << "Da dang ky" << char(124) << "  " << setw(20) << left << "       Lich hoc";
		gotoxy(149, 4); cout << char(124) << endl;
		gotoxy(20, 5); cout << "+--------------------------------------------------------------------------------------------------------------------------------+" << endl;
		ListCourses temp = ReadListCourses(se, Y);
		NodeCourse* temp1 = temp.head;
		while (temp1 != NULL)
		{
			gotoxy(20, 6 + STT); cout << char(124) << "  " << setw(10) << left << temp1->course.ID << char(124) << "  " << setw(30) << left << temp1->course.Name << char(124) << "  " << setw(25) << left << temp1->course.TeacherName << char(124) << "  " << setw(8) << left << temp1->course.NumOfCredits << char(124) << "  " << setw(3) << daDangKy(temp1->course, Y, se, temp) << " " << "/" << " " << setw(9) << temp1->course.MaxNumOfStudents << char(124) << "  ";
			cout << "T" << temp1->course.Session1.thu << " - " << temp1->course.Session1.gio << ":" << temp1->course.Session1.phut << "  " << "T" << temp1->course.Session2.thu << " - " << temp1->course.Session2.gio << ":" << temp1->course.Session2.phut;
			gotoxy(149, 6 + STT++); cout << char(124) << endl;
			temp1 = temp1->next;
		}
		gotoxy(20, 6 + STT); cout << "+--------------------------------------------------------------------------------------------------------------------------------+" << endl;
		gotoxy(15, 6 + STT + 1);
	}
}

void updateCourse(int se, const SchoolYear& Y)
{
	ViewListOfCourse(se, Y);
	Course a, b;
	cout << "Nhap ID khoa hoc can update: ";
	getline(cin, a.ID);
	fstream file1, file2;
	file1.open(to_string(se)+Y.ListCourses, ios::in);
	file2.open("ListCourses1.txt", ios::out);
	while (!file1.eof())
	{
		file1 >> b.Sememster;
		file1.ignore();
		getline(file1, b.ID);
		getline(file1, b.Name);
		getline(file1, b.TeacherName);
		file1 >> b.NumOfCredits;
		file1.ignore();
		file1 >> b.MaxNumOfStudents;
		file1.ignore();
		file1 >> b.Session1.thu >> b.Session1.gio >> b.Session1.phut;
		file1 >> b.Session2.thu >> b.Session2.gio >> b.Session2.phut;
		file1.ignore();
		if (file1.eof()) break;
		if (a.ID==b.ID)
		{
			cout << "Nhap thong tin can cap nhat" << endl;
			a.Sememster = se;
			cout << "Nhap ID khoa hoc: ";
			getline(cin, a.ID);
			cout << "Nhap ten khoa hoc: ";
			getline(cin, a.Name);
			cout << "Nhap ten giao vien: ";
			getline(cin,a.TeacherName);
			cout << "Nhap so tin chi: ";
			cin >> a.NumOfCredits;
			cout << "Nhap so luong sinh vien toi da: ";
			cin >> a.MaxNumOfStudents;
			cin.ignore();
			cout << "Nhap buoi hoc thu 1: ";
			cout << "Thu: ";
			do
			{
				cout << "Thu: ";
				cin >> a.Session1.thu;
			} while (a.Session1.thu < 2 || a.Session1.thu > 8);
			do
			{
				cout << "Gio: ";
				cin >> a.Session1.gio;
				cout << "Phut: ";
				cin >> a.Session1.phut;
			} while (!isTime(a.Session1.gio, a.Session1.phut, 0));
			cout << "Nhap buoi hoc thu 2: ";
			cout << "Thu: ";
			do
			{
				cout << "Thu: ";
				cin >> a.Session2.thu;
			} while (a.Session2.thu < 2 || a.Session2.thu > 8);
			do
			{
				cout << "Gio: ";
				cin >> a.Session2.gio;
				cout << "Phut: ";
				cin >> a.Session2.phut;
			} while (!isTime(a.Session2.gio, a.Session2.phut, 0));
			file2 << a.Sememster << endl;
			file2 << a.ID << endl;
			file2 << a.Name << endl;
			file2 << a.TeacherName << endl;
			file2 << a.NumOfCredits << endl;
			file2 << a.MaxNumOfStudents << endl;
			file2 << a.Session1.thu << endl;
			file2 << a.Session1.gio << endl;
			file2 << a.Session1.phut << endl;
			file2 << a.Session2.thu << endl;
			file2 << a.Session2.gio << endl;
			file2 << a.Session2.phut << endl;
		}
		else
		{
			file2 << b.Sememster << endl;
			file2 << b.ID << endl;
			file2 << b.Name << endl;
			file2 << b.TeacherName << endl;
			file2 << b.NumOfCredits << endl;
			file2 << b.MaxNumOfStudents << endl;
			file2 << b.Session1.thu << endl;
			file2 << b.Session1.gio << endl;
			file2 << b.Session1.phut << endl;
			file2 << b.Session2.thu << endl;
			file2 << b.Session2.gio << endl;
			file2 << b.Session2.phut << endl;
		}
	}
	file1.close();
	file2.close();
	remove((to_string(se)+Y.ListCourses).c_str());
	rename("ListCourses1.txt", (to_string(se)+Y.ListCourses).c_str());
}

void CreateCourseRegistrationSession(int se, const SchoolYear& Y)
{
	Time a;
	cout << "Nhap thoi gian bat dau: " << endl;
	cout << "Ngay: ";
	cin >> a.day;
	cout << "Thang: ";
	cin >> a.month;
	cout << "Nam: ";
	cin >> a.year;
	while (!isDate(a.day, a.month, a.year))
	{
		cout << "Ngay thang nam khong hop le! Moi nhap lai: " << endl;
		cout << "Nhap thoi gian bat dau: " << endl;
		cout << "Ngay: ";
		cin >> a.day;
		cout << "Thang: ";
		cin >> a.month;
		cout << "Nam: ";
		cin >> a.year;
	}
	cout << "Gio: ";
	cin >> a.hour;
	cout << "Phut: ";
	cin >> a.minute;
	cout << "Giay: ";
	cin >> a.second;
	while (!isTime(a.hour, a.minute, a.second))
	{
		cout << "Gio phut giay khong hop le! Moi nhap lai: " << endl;
		cout << "Gio: ";
		cin >> a.hour;
		cout << "Phut: ";
		cin >> a.minute;
		cout << "Giay: ";
		cin >> a.second;
	}
	fstream file;
	file.open(to_string(se)+Y.TimeDKHP, ios::out);
	file << a.day << " " << a.month << " " << a.year
		<< " " << a.hour << " " << a.minute << " " << a.second << " ";
	cout << "Nhap thoi gian ket thuc: " << endl;
	cout << "Ngay: ";
	cin >> a.day;
	cout << "Thang: ";
	cin >> a.month;
	cout << "Nam: ";
	cin >> a.year;
	while (!isDate(a.day, a.month, a.year))
	{
		cout << "Ngay thang nam khong hop le! Moi nhap lai: " << endl;
		cout << "Nhap thoi gian bat dau: " << endl;
		cout << "Ngay: ";
		cin >> a.day;
		cout << "Thang: ";
		cin >> a.month;
		cout << "Nam: ";
		cin >> a.year;
	}
	cout << "Gio: ";
	cin >> a.hour;
	cout << "Phut: ";
	cin >> a.minute;
	cout << "Giay: ";
	cin >> a.second;
	while (!isTime(a.hour, a.minute, a.second))
	{
		cout << "Gio phut giay khong hop le! Moi nhap lai: " << endl;
		cout << "Gio: ";
		cin >> a.hour;
		cout << "Phut: ";
		cin >> a.minute;
		cout << "Giay: ";
		cin >> a.second;
	}
	file << a.day << " " << a.month << " " << a.year
		<< " " << a.hour << " " << a.minute << " " << a.second << " ";
	file.close();
}
void deleteCourse(int se, const SchoolYear& Y)
{
	ViewListOfCourse(se, Y);
	Course a, b;
	cout << "Nhap ID khoa hoc muon xoa: ";
	getline(cin, a.ID);
	fstream file1, file2;
	file1.open(to_string(se)+Y.ListCourses, ios::in);
	file2.open("ListCourses1.txt", ios::out);
	while (!file1.eof())
	{
		file1 >> b.Sememster;
		file1.ignore();
		getline(file1, b.ID);
		getline(file1, b.Name);
		getline(file1, b.TeacherName);
		file1 >> b.NumOfCredits;
		file1 >> b.MaxNumOfStudents;
		file1 >> b.Session1.thu >> b.Session1.gio >> b.Session1.phut;
		file1 >> b.Session2.thu >> b.Session2.gio >> b.Session2.phut;
		if (file1.eof()) break;
		if (a.ID != b.ID)
		{
			file2 << b.Sememster << endl;
			file2 << b.ID << endl;
			file2 << b.Name << endl;
			file2 << b.TeacherName << endl;
			file2 << b.NumOfCredits << endl;
			file2 << b.MaxNumOfStudents << endl;
			file2 << b.Session1.thu << endl;
			file2 << b.Session1.gio << endl;
			file2 << b.Session1.phut << endl;
			file2 << b.Session2.thu << endl;
			file2 << b.Session2.gio << endl;
			file2 << b.Session2.phut << endl;
		}
	}
	file1.close();
	file2.close();
	remove((to_string(se)+Y.ListCourses).c_str());
	rename("ListCourses1.txt", (to_string(se)+Y.ListCourses).c_str());
}
