#include "course.h"
#include "Header.h"
#include "SchoolYear.h"
#include "console.h"
#include <string>
#include <string.h>
#include "Semester.h"
#include "staff.h"
#include "DKMon.h"
#include "Menu.h"
void initListCourses(ListCourses& list)
{
	list.head = NULL;
}

void createNewCourse(ListCourses& l, int semester, const SchoolYear& Y)
{
	cin.ignore();
	fstream file;
	file.open(to_string(semester) + Y.ListCourses, ios::app);
	Course a;
	a.Sememster = semester;
	gotoxy(70, 3);
	cout << "Nhap ID khoa hoc: ";
	Frames(70, 4, 25, 1);
	gotoxy(73, 5);
	getline(cin, a.ID);
	gotoxy(100, 3);
	cout << "Nhap ten khoa hoc: ";
	Frames(100, 4, 40, 1);
	gotoxy(103, 5);
	getline(cin, a.Name);
	gotoxy(70, 7);
	cout << "Nhap ten giao vien: ";
	Frames(70, 8, 70, 1);
	gotoxy(75, 9);
	getline(cin, a.TeacherName);
	gotoxy(70, 11);
	cout << "Nhap so tin chi: ";
	Frames(70, 12, 25, 1);
	gotoxy(75, 13);
	cin >> a.NumOfCredits;
	gotoxy(100, 11);
	cout << "Nhap so luong sinh vien toi da: ";
	Frames(100, 12, 40, 1);
	gotoxy(105, 13);
	cin >> a.MaxNumOfStudents;
	gotoxy(90, 15);
	cout << "Nhap buoi hoc thu 1: ";
	do
	{
		CleanForm(70, 17, 25, 1);
		CleanForm(100, 17, 40, 1);
		cleanEffectFailed(75, 28, " Nhap sai du lieu!");
		gotoxy(70, 16);
		cout << "Thu (2-8): ";
		Frames(70, 17, 25, 1);
		gotoxy(75, 18);
		cin >> a.Session1.thu;
		gotoxy(100, 16);
		cout << "Nhap ca hoc(1-4): ";
		Frames(100, 17, 40, 1);
		gotoxy(103, 18);
		cin >> a.Session1.shift;
		if (a.Session1.thu < 2 || a.Session1.thu > 8 || a.Session1.shift < 1 || a.Session1.shift > 4)
		{
			EffectFailed(75, 28, " Nhap sai du lieu!");
			gotoxy(75, 30);
			system("pause");
		}
	} while (a.Session1.thu < 2 || a.Session1.thu > 8 || a.Session1.shift < 1 || a.Session1.shift > 4);
	gotoxy(90, 21);
	cout << "Nhap buoi hoc thu 2: ";
	do
	{
		CleanForm(70, 23, 25, 1);
		CleanForm(100, 23, 40, 1);
		cleanEffectFailed(75, 28, " Nhap sai du lieu!");
		gotoxy(70, 22);
		cout << "Thu (2-8): ";
		Frames(70, 23, 25, 1);
		gotoxy(75, 24);
		cin >> a.Session2.thu;
		gotoxy(100, 22);
		cout << "Nhap ca hoc(1-4): ";
		Frames(100, 23, 40, 1);
		gotoxy(103, 24);
		cin >> a.Session2.shift;
		if (a.Session2.thu < 2 || a.Session2.thu > 8 || a.Session2.shift < 1 || a.Session2.shift > 4)
		{
			EffectFailed(75, 28, " Nhap sai du lieu!");
			gotoxy(75, 30);
			system("pause");
		}
	} while (a.Session2.thu < 2 || a.Session2.thu > 8 || a.Session2.shift < 1 || a.Session2.shift > 4);
	cin.ignore();
	bool KT = CheckCourses(l, a.ID);
	if (KT == true) return;
	AddTailListCourse(l, a);
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
	file << a.Session1.shift << endl;
	file << a.Session2.thu << endl;
	file << a.Session2.shift << endl;
	file.close();
}
void AddTailListCourse(ListCourses& l, Course co)
{
	NodeCourse* p = new NodeCourse,*k;
	p->course = co;
	p->next = NULL;
	if (l.head == NULL)
		l.head = p;
	else
	{
		k = l.head;
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
		file >> temp0.Session1.shift;
		file >> temp0.Session2.thu;
		file >> temp0.Session2.shift;
		AddTailListCourse(temp, temp0);
	}
	file.close();
	return temp;
}
string TimeShift(int shift)
{
	string time;
	switch (shift)
	{
	case 1: time = "(07:30)"; break;
	case 2: time = "(09:30)"; break;
	case 3: time = "(13:30)"; break;
	case 4: time = "(15:30)"; break;
	}
	return time;
}
int CountNodeCourse(NodeCourse* phead)
{
	NodeCourse* p = phead;
	int i = 0;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}
int CountNodePage2(int i)
{
	int page = i / 3 + 1;
	if (i % 3 == 0)
		return page - 1;
	return page;
}
int ViewListOfCourse(ListCourses temp, int se, string& e, bool& fl, const SchoolYear& Y)
{
	ifstream f;
	f.open(to_string(se) + Y.ListCourses);
	f.seekg(0, ios::end);
	int x = f.tellg();
	f.close();
	if (x == 0)
	{
		e = "Chua co khoa hoc nao trong danh sach";
		fl = false;
	}
	else
	{
		system("cls");
		fl = true;
		NodeCourse* temp1;
		char key;
		int vitri = 0, i, j;
		int numberofstudent = CountNodeCourse(temp.head);
		int numberofPage = CountNodePage(numberofstudent), page = 1, count;
		while (true)
		{

			temp1 = temp.head;
			int STT = 15 * (page - 1);
			for (i = 1; i < page; i++)
			{
				for (j = 0; j < 15; j++)
				{
					temp1 = temp1->next;
				}
			}
			count = 0;
			system("cls");
			FormMenu2();
			gotoxy(40, 2); TextColor(164); cout << "DANH SACH MON HOC MO KI " << se << " - Nam hoc " << Y.NameSchoolYear;
			TextColor(224);
			gotoxy(15, 3); cout << "+----------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
			gotoxy(15, 4); cout << char(124) << setw(5) << " STT" << char(124) << setw(13) << left << "  Ma mon hoc" << char(124) << setw(31) << left << "       Ten mon hoc" << char(124) << setw(26) << "     Ten GV" << char(124) << setw(9) << left << "   So TC" << char(124) << setw(16) << "  Da dang ky" << char(124) << "  " << setw(20) << left << "     Lich hoc";
			gotoxy(158, 4); cout << char(124) << endl;
			gotoxy(15, 5); cout << "+----------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
			for (i = 0; i < 15; i++)
			{
				if (temp1 == NULL) break;
				count = i + 1;
				gotoxy(15, 6 + i);
				cout << char(124) << setw(5) << STT++ + 1 << char(124) << " " << setw(12) << left << temp1->course.ID << char(124) << " " << setw(30) << left << temp1->course.Name << char(124) << " " << setw(25) << left << temp1->course.TeacherName << char(124) << " " << setw(8) << left << temp1->course.NumOfCredits << char(124) << " " << setw(3) << daDangKy(temp1->course, Y, se, temp) << " " << "/" << " " << setw(9) << temp1->course.MaxNumOfStudents << char(124) << " ";
				cout << "T" << temp1->course.Session1.thu << " - " << "S" << temp1->course.Session1.shift << TimeShift(temp1->course.Session1.shift) << "  " << "T" << temp1->course.Session2.thu << " - " << "S" << temp1->course.Session2.shift << TimeShift(temp1->course.Session2.shift);
				gotoxy(158, 6 + i); cout << char(124) << endl;
				temp1 = temp1->next;
			}
			gotoxy(15, 6 + count); cout << "+----------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
			gotoxy(15, 6 + count + 1);
			gotoxy(50, 28); cout << page << "/" << numberofPage;
			key = GetKey();
			switch (key)
			{
			case LEFT:// sang trai
				vitri = 0;
				break;
			case RIGHT: // sang phai
				vitri = 1;
				break;
			case ESC: // thoat vong lap
				return 0;
				break;
			case ENTER:
				return 1;
				break;
			}
			if (vitri == 0)
			{
				if (page == 1) continue;
				else
					--page;
			}
			if (vitri == 1)
			{
				if (page == numberofPage) continue;
				else
					++page;
			}
		}
	}
}


void updateCourse(ListCourses& l, int se, const SchoolYear& Y)
{
	string str;
	bool f;
	int c = ViewListOfCourse(l, se,str,f, Y);
	Course a, b;
	gotoxy(40, 29);
	cout << "Nhap ma khoa hoc can update: ";
	Frames(40, 30, 30, 1);
	gotoxy(43, 31);
	getline(cin, a.ID);
	fstream file1, file2;
	string link1 = to_string(se) + Y.ListCourses,
		link2 = "ListCourses1.txt";
	file1.open(link1, ios::in);
	file2.open(link2, ios::out);
	while (!file1.eof())
	{
		file1 >> b.Sememster;
		file1.ignore();
		getline(file1, b.ID);
		getline(file1, b.Name);
		getline(file1, b.TeacherName);
		file1 >> b.NumOfCredits;
		file1 >> b.MaxNumOfStudents;
		file1 >> b.Session1.thu >> b.Session1.shift;
		file1 >> b.Session2.thu >> b.Session2.shift;
		file1.ignore();
		if (file1.eof()) break;
		a.Sememster = b.Sememster;
		if (a.ID == b.ID)
		{
			system("cls");
			Frames(40, 1, 70, 3);
			gotoxy(55, 3); cout << "CAP NHAP THONG TIN KHOA HOC " << b.ID;
			Frames(40, 7, 25, 1);
			Frames(70, 7, 40, 1);
			Frames(40, 11, 70, 1);
			Frames(40, 15, 25, 1);
			Frames(40, 20, 25, 1);
			Frames(70, 20, 40, 1);
			Frames(40, 26, 25, 1);
			Frames(70, 26, 40, 1);
			Frames(70, 15, 40, 1);
			gotoxy(40, 6);
			cout << "Nhap ID khoa hoc: ";
			gotoxy(70, 6);
			cout << "Nhap ten khoa hoc: ";
			gotoxy(40, 10);
			cout << "Nhap ten giao vien: ";
			gotoxy(40, 14);
			cout << "Nhap so tin chi: ";
			gotoxy(70, 14);
			cout << "Nhap so luong sinh vien toi da: ";
			gotoxy(60, 18);
			cout << "Nhap buoi hoc thu 1: ";
			gotoxy(40, 19);
			cout << "Thu (2-8): ";
			gotoxy(70, 19);
			cout << "Nhap ca hoc(1-4): ";
			gotoxy(60, 24);
			cout << "Nhap buoi hoc thu 2: ";
			gotoxy(40, 25);
			cout << "Thu (2-8): ";
			gotoxy(70, 25);
			cout << "Nhap ca hoc(1-4): ";
			gotoxy(43, 8);
			getline(cin, a.ID);
			gotoxy(73, 8);
			getline(cin, a.Name);
			gotoxy(45, 12);
			getline(cin, a.TeacherName);
			do
			{
				CleanForm(40, 15, 25, 1);
				cleanEffectFailed(60, 31, "       Nhap sai du lieu!      ");
				Frames(40, 15, 25, 1);
				gotoxy(45, 16);
				cin >> a.NumOfCredits;
				if (cin.fail())
				{
					EffectFailed(60, 31, "       Nhap sai du lieu!      ");
					gotoxy(60, 34);
					system("pause");
					cin.clear();
					cin.ignore();
				}
				else
					break;
			} while (true);
			do
			{
				CleanForm(70, 15, 40, 1);
				cleanEffectFailed(60, 31, "       Nhap sai du lieu!      ");
				Frames(70, 15, 40, 1);
				gotoxy(75, 16);
				cin >> a.MaxNumOfStudents;
				if (cin.fail())
				{
					EffectFailed(60, 31, "       Nhap sai du lieu!      ");
					gotoxy(60, 34);
					system("pause");
					cin.clear();
					cin.ignore();
				}
				else
					break;
			} while (true);

			do
			{
				CleanForm(40, 20, 25, 1);
				CleanForm(70, 20, 40, 1);
				cleanEffectFailed(60, 31, "       Nhap sai du lieu!      ");
				Frames(40, 20, 25, 1);
				Frames(70, 20, 40, 1);
				gotoxy(45, 21);
				cin >> a.Session1.thu;
				gotoxy(73, 21);
				cin >> a.Session1.shift;
				if (a.Session1.thu < 2 || a.Session1.thu > 8 || a.Session1.shift < 1 || a.Session1.shift > 4)
				{
					EffectFailed(60, 31, "       Nhap sai du lieu!      ");
					gotoxy(60, 34);
					system("pause");
					cin.clear();
					cin.ignore();
				}
			} while (a.Session1.thu < 2 || a.Session1.thu > 8 || a.Session1.shift < 1 || a.Session1.shift > 4);
			do
			{
				CleanForm(40, 26, 25, 1);
				CleanForm(70, 26, 40, 1);
				cleanEffectFailed(60, 31, "       Nhap sai du lieu!      ");
				Frames(40, 26, 25, 1);
				Frames(70, 26, 40, 1);

				gotoxy(45, 27);
				cin >> a.Session2.thu;
				gotoxy(73, 27);
				cin >> a.Session2.shift;
				if (a.Session2.thu < 2 || a.Session2.thu > 8 || a.Session2.shift < 1 || a.Session2.shift > 4)
				{
					EffectFailed(60, 31, "       Nhap sai du lieu!      ");
					gotoxy(60, 34);
					system("pause");
					cin.clear();
					cin.ignore();
				}
			} while (a.Session2.thu < 2 || a.Session2.thu > 8 || a.Session2.shift < 1 || a.Session2.shift > 4);
			file2 << a.Sememster << endl;
			file2 << a.ID << endl;
			file2 << a.Name << endl;
			file2 << a.TeacherName << endl;
			file2 << a.NumOfCredits << endl;
			file2 << a.MaxNumOfStudents << endl;
			file2 << a.Session1.thu << endl << a.Session1.shift << endl;
			file2 << a.Session2.thu << endl << a.Session2.shift << endl;
			ifstream file3(to_string(se) + Y.StudentOfSubject);
			ofstream file4("temp.txt");
			string s;
			while (!file3.eof())
			{
				getline(file3, s);
				if (s == b.ID)
				{
					file4 << a.ID << endl;
				}
				else
				{
					file4 << s << endl;
				}
			}
			file3.close();
			file4.close();
			remove((to_string(se) + Y.StudentOfSubject).c_str());
			rename("temp.txt", (to_string(se) + Y.StudentOfSubject).c_str());
		}
		else {
			file2 << b.Sememster << endl;
			file2 << b.ID << endl;
			file2 << b.Name << endl;
			file2 << b.TeacherName << endl;
			file2 << b.NumOfCredits << endl;
			file2 << b.MaxNumOfStudents << endl;
			file2 << b.Session1.thu << endl << b.Session1.shift << endl;
			file2 << b.Session2.thu << endl << b.Session2.shift << endl;
		}
	}
	file1.close();
	file2.close();
	remove(link1.c_str());
	rename(link2.c_str(), link1.c_str());
	l = ReadListCourses(se, Y);
	EffectSuccess(75, 28, "Cap nhap thanh cong");
}

void CreateCourseRegistrationSession(int se, const SchoolYear& Y)
{
	Time start, end;
	gotoxy(80, 10); cout << "Nhap ngay bat dau:";
	Frames(110, 9, 10, 1); gotoxy(121, 10); cout << "/"; Frames(123, 9, 10, 1); gotoxy(134, 10); cout << "/"; Frames(136, 9, 10, 1);
	gotoxy(111, 10); cin >> start.day;
	gotoxy(124, 10); cin >> start.month;
	gotoxy(138, 10); cin >> start.year;
	if (!isDate(start.day, start.month, start.year)) {
		EffectFailed(75, 26, "Ngay thang nam khong hop le!");
		gotoxy(75, 29);
		return;
	}
	gotoxy(80, 14); cout << "Nhap thoi gian mo DKHP:";
	Frames(110, 13, 10, 1); gotoxy(121, 14); cout << ":"; Frames(123, 13, 10, 1); gotoxy(134, 14); cout << ":"; Frames(136, 13, 10, 1);
	gotoxy(111, 14); cin >> start.hour;
	gotoxy(124, 14); cin >> start.minute;
	gotoxy(138, 14); cin >> start.second;
	if (!isTime(start.hour, start.minute, start.second))
	{
		EffectFailed(75, 26, "Gio phut giay khong hop le!");
		gotoxy(75, 29);
		return;
	}
	gotoxy(80, 18); cout << "Nhap ngay ket thuc:";
	Frames(110, 17, 10, 1); gotoxy(121, 18); cout << "/"; Frames(123, 17, 10, 1); gotoxy(134, 18); cout << "/"; Frames(136, 17, 10, 1);
	gotoxy(111, 18); cin >> end.day;
	gotoxy(124, 18); cin >> end.month;
	gotoxy(138, 18); cin >> end.year;
	if (!isDate(end.day, end.month, end.year))
	{
		EffectFailed(75, 26, "Ngay thang nam khong hop le!");
		gotoxy(75, 29);
		return;
	}
	gotoxy(80, 21); cout << "Nhap gio ket thuc:";
	Frames(110, 21, 10, 1); gotoxy(121, 22); cout << ":"; Frames(123, 21, 10, 1); gotoxy(134, 22); cout << ":"; Frames(136, 21, 10, 1);
	gotoxy(111, 22); cin >> end.hour;
	gotoxy(124, 22); cin >> end.minute;
	gotoxy(138, 22); cin >> end.second;
	if (!isTime(end.hour, end.minute, end.second))
	{
		EffectFailed(75, 26, "Gio phut giay khong hop le!");
		gotoxy(75, 29);
		return;
	}
	fstream file;
	file.open(Y.TimeDKHP, ios::app);
	file << se << " " << start.day << " " << start.month << " " << start.year
		<< " " << start.hour << " " << start.minute << " " << start.second << " ";
	file << end.day << " " << end.month << " " << end.year
		<< " " << end.hour << " " << end.minute << " " << end.second << " " << endl;
	file.close();
}
void deleteCourse(ListCourses& l, int se, const SchoolYear& Y)
{
	string str;
	bool f;
	ViewListOfCourse(l, se, str, f, Y);
	Course a, b;
	gotoxy(40, 31);
	cout << "Nhap ID khoa hoc muon xoa: ";
	Frames(70, 30, 30, 1);
	gotoxy(73, 31);
	getline(cin, a.ID);
	if (!CheckCourses(l, a.ID)) {

		EffectFailed(75, 26, "Khong ton tai ma mon do");
		return;
	}
	fstream file1, file2;
	string link1 = to_string(se) + Y.ListCourses,
		link2 = "ListCourses1.txt";
	file1.open(link1, ios::in);
	file2.open(link2, ios::out);
	while (!file1.eof())
	{
		file1 >> b.Sememster;
		file1.ignore();
		getline(file1, b.ID);
		getline(file1, b.Name);
		getline(file1, b.TeacherName);
		file1 >> b.NumOfCredits;
		file1 >> b.MaxNumOfStudents;
		file1 >> b.Session1.thu >> b.Session1.shift;
		file1 >> b.Session2.thu >> b.Session2.shift;
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
			file2 << b.Session1.shift << endl;
			file2 << b.Session2.thu << endl;
			file2 << b.Session2.shift << endl;
		}
	}
	file1.close();
	file2.close();
	remove(link1.c_str());
	rename(link2.c_str(), link1.c_str());
	l = ReadListCourses(se, Y);
	EffectSuccess(75, 26, "Xoa thanh cong ");
}
