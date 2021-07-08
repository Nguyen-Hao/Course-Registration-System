#include "course.h"
#include "Header.h"
#include"SchoolYear.h"
void initListCourses(ListCourses& list)
{
	list.head = NULL;
}

void createNewCourse(const SchoolYear&Y )
{
	fstream file;
	file.open(Y.ListCourses, ios::app);
	Course a;
	cout << "Nhap hoc ky: ";
	cin >> a.Sememster;
	cin.ignore();
	cout << "Nhap ID khoa hoc: ";
	cin.get(a.ID, 10, '\n');
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
	cin.ignore();
	ofstream g;
	g.open(Y.StudentOfSubject, ios::app);
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
	file << a.Session2.phut<<endl;
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
ListCourses ReadListCourses(const SchoolYear& Y)
{
	ListCourses temp;
	initListCourses(temp);
	ifstream file;
	file.open(Y.ListCourses);
	Course temp0;
	while (file >> temp0.Sememster)
	{
		file.ignore();
		file.getline(temp0.ID, 10);
		file.getline(temp0.Name, 50);
		file.getline(temp0.TeacherName, 50);
		file >> temp0.NumOfCredits;
	//	file.ignore();
		file >> temp0.MaxNumOfStudents;
	//	file.ignore();
		file >> temp0.Session1.thu;
		//file.ignore();
		file >> temp0.Session1.gio;
		//file.ignore();
		file >> temp0.Session1.phut;
		//file.ignore();
		file >> temp0.Session2.thu;
		//file.ignore();
		file >> temp0.Session2.gio;
		//file.ignore();
		file >> temp0.Session2.phut;
		//file.ignore();
		/*{
			NodeCourse* temp2 = new NodeCourse;
			temp2->next = NULL;
			temp2->course = temp0;
			if (temp.head == NULL)
				temp.head = temp2;
			else
			{
				temp2->next = temp.head;
				temp.head = temp2;
			}
		}*/
		AddTailListCourse(temp, temp0);
	}
	return temp;
}

void ViewListOfCourse(const SchoolYear&Y)
{
	ifstream f;
	f.open(Y.ListCourses);
	f.seekg(0, ios::end);
	int i = f.tellg();
	f.close();
	if (i == 0)
	{
		cout << "Chua co khoa hoc nao trong danh sach" << endl;
	}
	else
	{
		cout << "   ";
		cout << setw(10) << left << "ID" << setw(50) << left << "Name of course";
		cout << setw(35) << left << "Teacher name" << setw(8) << left << "Credit";
		cout << setw(15) << "Number of student";
		cout << setw(10) << left << "Thu" << setw(10) << left << "Time";
		cout << setw(10) << left << "Thu" << setw(10) << left << "Time" << endl;
		ListCourses temp = ReadListCourses(Y);
		NodeCourse* temp1;
		if (temp.head != NULL) temp1 = temp.head->next;
		else temp1 = temp.head;
		while (temp1 != NULL)
		{
			cout << "   ";
			cout << setw(10) << left << temp1->course.ID << setw(50) << left << temp1->course.Name;
			cout << setw(35) << left << temp1->course.TeacherName << setw(8) << left << temp1->course.NumOfCredits;
			cout << setw(15) << temp1->course.MaxNumOfStudents;
			cout << setw(10) << left << temp1->course.Session1.thu << setw(2) << left << temp1->course.Session1.gio << ":" << setw(8) << temp1->course.Session1.phut;
			cout << setw(10) << left << temp1->course.Session2.thu << setw(2) << left << temp1->course.Session2.gio << ":" << temp1->course.Session2.phut << endl;
			temp1 = temp1->next;
		}
	}
}

void updateCourse(const SchoolYear&Y)
{
	ViewListOfCourse(Y);
	Course a, b;
	cout << "Nhap ID khoa hoc can update: ";
	cin.get(a.ID, 20, '\n');
	fstream file1, file2;
	file1.open(Y.ListCourses, ios::in);
	file2.open("ListCourses1.txt", ios::out);
	while (!file1.eof())
	{
		file1 >> b.Sememster;
		file1.ignore();
		file1.getline(b.ID, 10);
		file1.getline(b.Name, 50);
		file1.getline(b.TeacherName, 50);
		file1 >> b.NumOfCredits;
		file1.ignore();
		file1 >> b.MaxNumOfStudents;
		file1.ignore();
		file1 >> b.Session1.thu >> b.Session1.gio >> b.Session1.phut;
		file1 >> b.Session2.thu >> b.Session2.gio >> b.Session2.phut;
		file1.ignore();
		if (file1.eof()) break;
		if (strcmp(a.ID, b.ID) == 0)
		{
			cout << "Nhap thong tin can cap nhat" << endl;
			cout << "Nhap hoc ky: ";
			cin >> a.Sememster;
			cin.ignore();
			cout << "Nhap ID khoa hoc: ";
			cin.get(a.ID, 10, '\n');
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
	remove((char*)&Y.ListCourses);
	rename("ListCourses1.txt", (char*)&Y.ListCourses);
}

//Tạo phiên đăng ký khóa học (ĐKHP)
void CreateCourseRegistrationSession(const SchoolYear&Y)
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
	file.open(Y.TimeDKHP, ios::out);
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
void deleteCourse(const SchoolYear& Y)
{
	ViewListOfCourse(Y);
	Course a, b;
	cout << "Nhap ID khoa hoc muon xoa: ";
	cin.get(a.ID, 20, '\n');
	fstream file1, file2;
	file1.open(Y.ListCourses, ios::in);
	file2.open("ListCourses1.txt", ios::out);
	while (!file1.eof())
	{
		file1 >> b.Sememster;
		file1.ignore();
		file1.getline(b.ID, 10);
		file1.getline(b.Name, 50);
		file1.getline(b.TeacherName, 50);
		file1 >> b.NumOfCredits;
		file1.ignore();
		file1 >> b.MaxNumOfStudents;
		file1.ignore();
		file1 >> b.Session1.thu >> b.Session1.gio >> b.Session1.phut;
		file1 >> b.Session2.thu >> b.Session2.gio >> b.Session2.phut;
		file1.ignore();
		if (file1.eof()) break;
		if (strcmp(a.ID, b.ID) == 0)
		{

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
	remove((char*)&Y.ListCourses);
	rename("ListCourses1.txt", (char*)&Y.ListCourses);
}
