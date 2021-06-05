#include "course.h"
#include "Header.h"
void initListCourses(ListCourses& list)
{
	list.head = NULL;
}

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

ListCourses ReadListCourses(int x)
{
	ListCourses temp;
	initListCourses(temp);
	ifstream file;
	file.open(FILECOURSES);
	while (!file.eof())
	{
		int temp1;
		file >> temp1;
		file.ignore();
		if (temp1 == x)
		{
			Course temp0;
			temp0.Sememster = temp1;
			file.getline(temp0.ID, 20);
			file.getline(temp0.Name, 50);
			file.getline(temp0.TeacherName, 50);
			file >> temp0.NumOfCredits;
			file.ignore();
			file >> temp0.MaxNumOfStudents;
			file.ignore();
			file.getline(temp0.Session1.Thu, 10);
			file.getline(temp0.Session1.Gio, 10);
			file.getline(temp0.Session2.Thu, 10);
			file.getline(temp0.Session2.Gio, 10);
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
			temp1 = 0;
		}
		else
		{
			Course temp0;
			temp0.Sememster = temp1;
			file.getline(temp0.ID, 20);
			file.getline(temp0.Name, 50);
			file.getline(temp0.TeacherName, 50);
			file >> temp0.NumOfCredits;
			file.ignore();
			file >> temp0.MaxNumOfStudents;
			file.ignore();
			file.getline(temp0.Session1.Thu, 10);
			file.getline(temp0.Session1.Gio, 10);
			file.getline(temp0.Session2.Thu, 10);
			file.getline(temp0.Session2.Gio, 10);
		}
	}
	return temp;
}

void ViewListOfCourse(int& x)
{
repeat:
	cout << "input credit: ";
	cin >> x;
	if (x <= 0 || x > 3)
	{
		cout << "credit is false!!" << endl;
		cout << "Do you want to repeat?? " << endl;
		cout << "1: yes, 2: no. ";
		int n;
		cin >> n;
		switch (n)
		{
		case 1:
		{
			goto repeat;
		}
		default:
			break;
		}
	}
	else {
		cout << setw(20) << left << "ID" << setw(50) << left << "Name of course";
		cout << setw(50) << left << "Teacher name" << setw(8) << left << "Credit";
		cout << setw(20) << "Number of student";
		cout << setw(10) << left << "Thu" << setw(10) << left << "Time";
		cout << setw(10) << left << "Thu" << setw(10) << left << "Time" << endl;
		ListCourses temp = ReadListCourses(x);
		NodeCourse* temp1 = temp.head;
		while (temp1 != NULL)
		{
			cout << setw(20) << left << temp1->course.ID << setw(50) << left << temp1->course.Name;
			cout << setw(50) << left << temp1->course.TeacherName << setw(8) << left << temp1->course.NumOfCredits;
			cout << setw(20) << temp1->course.MaxNumOfStudents;
			cout << setw(10) << left << temp1->course.Session1.Thu << setw(10) << left << temp1->course.Session1.Gio;
			cout << setw(10) << left << temp1->course.Session2.Thu << setw(10) << left << temp1->course.Session2.Gio << endl;
			temp1 = temp1->next;
		}
	}
}

void updateCourse()
{
	Course a, b;
	cout << "Nhap ID khoa hoc can update: ";
	cin.get(a.ID, 20, '\n');
	fstream file1, file2;
	file1.open(FILECOURSES, ios::in);
	file2.open("ListCourses1.txt", ios::out);
	while (!file1.eof())
	{
		file1 >> b.Sememster;
		file1.ignore();
		file1.getline(b.ID, 20);
		file1.getline(b.Name, 50);
		file1.getline(b.TeacherName, 50);
		file1 >> b.NumOfCredits;
		file1.ignore();
		file1 >> b.MaxNumOfStudents;
		file1.ignore();
		file1.getline(b.Session1.Thu, 10);
		file1.getline(b.Session1.Gio, 10);
		file1.getline(b.Session2.Thu, 10);
		file1.getline(b.Session2.Gio, 10);
		if (file1.eof()) break;
		if (strcmp(a.ID, b.ID) == 0)
		{
			cout << "Nhap thong tin can cap nhat" << endl;
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
			file2 << a.Sememster << endl;
			file2 << a.ID << endl;
			file2 << a.Name << endl;
			file2 << a.TeacherName << endl;
			file2 << a.NumOfCredits << endl;
			file2 << a.MaxNumOfStudents << endl;
			file2 << a.Session1.Thu << endl;
			file2 << a.Session1.Gio << endl;
			file2 << a.Session2.Thu << endl;
			file2 << a.Session2.Gio << endl;
		}
		else 
		{
			file2 << b.Sememster << endl;
			file2 << b.ID << endl;
			file2 << b.Name << endl;
			file2 << b.TeacherName << endl;
			file2 << b.NumOfCredits << endl;
			file2 << b.MaxNumOfStudents << endl;
			file2 << b.Session1.Thu << endl;
			file2 << b.Session1.Gio << endl;
			file2 << b.Session2.Thu << endl;
			file2 << b.Session2.Gio << endl;
		}
	}
	file1.close();
	file2.close();
	remove(FILECOURSES);
	rename("ListCourses1.txt", FILECOURSES);
}

//Tạo phiên đăng ký khóa học (ĐKHP)
void CreateCourseRegistrationSession()
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
	file.open(FILETIMEDKHP, ios::out);
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