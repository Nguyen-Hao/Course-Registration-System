#include "student.h"
#include "Header.h"
#include "console.h"
void AddTailStudent(ListSV*& ds, SinhVien sv)
{
	ListSV* s = new ListSV;
	s->info = sv;
	s->pNext = NULL;
	if (ds == NULL)
		ds = s;
	else
	{
		ListSV* k = ds;
		while (k->pNext != NULL)
			k = k->pNext;
		k->pNext = s;
	}
}
int CheckClass(ListLop dsl, char a[100], int n)
{
	for (int i = 0;i < n;i++)
	{
		if (strcmp(dsl.l[i].Ma, a) == 0)
			if (i == 0) return -1; //neu dau tien thi tra ve -1 
			else return i;
	}
	return 0; // tra ve 0 khi khong tim thay
}
void AddStudent_Input(ListLop& dsl)
{
	cin.ignore();
	char c[10];
	char Pass[10] = "123456";
	SinhVien sv;
	cout << "Nhap ID lop: "; cin.get(c, 10, '\n');
	int STTLop;
	int KT = CheckClass(dsl, c, dsl.n);
	if (KT != 0)
	{
		cin.ignore();
		cout << "Ngay nhap hoc: (dd mm yyyy)"; for (int i = 0;i < 3;i++) cin >> sv.begin[i];
		cin.ignore();
		cout << "Nhap ID: "; cin.get(sv.ID, 10, '\n');
		cin.ignore();
		cout << "Nhap ho: "; cin.get(sv.FirstName, 50, '\n');
		cin.ignore();
		cout << "Nhap ten: "; cin.get(sv.LastName, 50, '\n');
		cin.ignore();
		cout << "Nhap gioi tinh: "; cin.get(sv.Gender, 10, '\n');
		cin.ignore();
		cout << "Nhap ngay sinh (dd/mm/yyyy): "; cin.get(sv.DateOfBirth, 50, '\n');
		cin.ignore();
		cout << "Nhap Social ID: "; cin.get(sv.SocialID, 10, '\n');
		if (KT == -1)
			STTLop = 0;
		else STTLop = KT;
		sv.YearStudent = 1;
		sv.Semester = 1;
		strcpy_s(sv.pass, 10, Pass);
		AddTailStudent(dsl.l[STTLop].pHead, sv);
	}
	else
	{
		cout << "Khong tim thay lop " << c << endl;
		cout << "Vui long nhap lai..." << endl;
	}
}
void WriteFileStudent(ListLop& dsl)
{
	ofstream file;
	file.open(FILEDSSV, ios::out);
	for (int i = 0; i < dsl.n; i++)
	{
		for (ListSV* k = dsl.l[i].pHead; k != NULL; k = k->pNext) 
		{
			file << dsl.l[i].Ma << endl; // ten lop
			file << k->info.ID << endl << k->info.pass << endl; // id + pass
			file << k->info.FirstName << endl << k->info.LastName << endl << k->info.Gender << endl << k->info.DateOfBirth << endl << k->info.SocialID << endl;
			file << k->info.begin[0] << " " << k->info.begin[1] << " " << k->info.begin[2] << " " << endl << k->info.YearStudent << endl << k->info.Semester << endl;
		}
	}
}
void ReadFileStudent(ListLop& dsl)
{
	ifstream file;
	file.open(FILEDSSV, ios::in);
	string s;
	int STTLop;
	char a[10];
	while (!file.eof())
	{
		SinhVien sv;
		getline(file, s);
		if (s.size() == 0) break;
		strcpy_s(a, 10, s.c_str());
		int KT = CheckClass(dsl, a, dsl.n);
		if (KT == -1) STTLop = 0;
		else STTLop = KT;
		strcpy_s(sv.Class, 10, s.c_str());
		getline(file, s);	strcpy_s(sv.ID, 10, s.c_str());
		getline(file, s);	strcpy_s(sv.pass, 20, s.c_str());
		getline(file, s);	strcpy_s(sv.FirstName, 50, s.c_str());
		getline(file, s);	strcpy_s(sv.LastName, 50, s.c_str());
		getline(file, s);	strcpy_s(sv.Gender, 10, s.c_str());
		getline(file, s);	strcpy_s(sv.DateOfBirth, 50, s.c_str());
		getline(file, s);	strcpy_s(sv.SocialID, 10, s.c_str());
		for (int i = 0;i < 3;i++) file >> sv.begin[i];
		file >> sv.YearStudent; 
		file >> sv.Semester;
		AddTailStudent(dsl.l[STTLop].pHead, sv);
	}
	file.close();
}
void UpdateCSV(ListLop& ds)
{
	ifstream f1;
	f1.open(FILECSV, ios::in | ios::out);
	string line = "", word;
	int ViTriLop;
	ofstream file;
	file.open(FILEDSSV, ios_base::out);
	while (f1.good())
	{
		char MaLop[10];
		getline(f1, line);
		if (line.size() == 0) break;
		stringstream s(line);
		vector<string> row;
		while (getline(s, word, ','))
		{
			row.push_back(word);
		}
		strcpy_s(MaLop, 10, row[0].c_str());
		int KT = CheckClass(ds, MaLop, ds.n);
		if (KT == -1)	ViTriLop = 0;
		else ViTriLop = KT;
		SinhVien sv;
		strcpy_s(sv.Class, 10, MaLop);
		strcpy_s(sv.ID, 10, row[2].c_str());
		strcpy_s(sv.FirstName, 50, row[3].c_str());
		strcpy_s(sv.LastName, 50, row[4].c_str());
		strcpy_s(sv.Gender, 10, row[5].c_str());
		strcpy_s(sv.DateOfBirth, 50, row[6].c_str());
		strcpy_s(sv.SocialID, 10, row[7].c_str());
		char Pass[10] = "123456";
		strcpy_s(sv.pass, 10, Pass); // pass mac dinh
		sv.Semester = 1;
		sv.YearStudent = 1;
		sv.begin[0] = 5; sv.begin[1] = 10; sv.begin[2] = 2002;
		bool flat = true;
		for (ListSV* k = ds.l[ViTriLop].pHead; k != NULL; k = k->pNext)
			if (strcmp(k->info.ID, sv.ID) == 0 && strcmp(k->info.FirstName, sv.FirstName) == 0 && strcmp(k->info.LastName, sv.LastName) == 0 && strcmp(k->info.SocialID, sv.SocialID) == 0 && strcmp(k->info.ID, sv.ID) == 0 && strcmp(k->info.Gender, sv.Gender) == 0)
				flat = false;
		if (flat == true) AddTailStudent(ds.l[ViTriLop].pHead, sv);
	}
	WriteFileStudent(ds);
	file.close();
}

void UpdateStudent()
{
	Time temp = getTime();
	SinhVien temp1;
	fstream file, file1;
	file.open("ListYearStudent.txt", ios::in | ios::out);
	file1.open("list.txt", ios::out);
	while (!file.eof())
	{
		file.getline(temp1.Class, 10);
		file.getline(temp1.ID, 10);
		file.getline(temp1.FirstName, 50);
		file.getline(temp1.LastName, 50);
		file.getline(temp1.Gender, 10);
		file.getline(temp1.DateOfBirth, 50);
		for (int i = 0; i < 3; i++)
		{
			file >> temp1.begin[i];
		}
		file.ignore();
		file >> temp1.YearStudent;
		file.ignore();
		file.getline(temp1.SocialID, 10);
		file.ignore();
		file1 << temp1.Class << endl;
		file1 << temp1.ID << endl;
		file1 << temp1.FirstName << endl;
		file1 << temp1.LastName << endl;
		file1 << temp1.Gender << endl;
		file1 << temp1.DateOfBirth << endl;

		file1 << temp1.begin[0] << " " << temp1.begin[1] << " " << temp1.begin[2] << endl;
		if (((temp.day >= temp1.begin[0]) && (temp.month == temp1.begin[1]) &&
			(temp.year > temp1.begin[2])) ||
			((temp.year > temp1.begin[2]) && (temp.month > temp1.begin[1])))
		{
			int a = temp.year - temp1.begin[2];
			temp1.YearStudent = 1 + a;
			if (temp1.YearStudent > 6)
			{
				file1 << 7 << endl;
			}//sinh vien có yearStudent=7 la sinh vien da ra truong
			else
			{
				file1 << temp1.YearStudent << endl;
			}
		}
		else
		{
			file1 << temp1.YearStudent << endl;

		}
		file1 << temp1.SocialID << endl;

	}
	file.close();
	file1.close();
	remove("ListYearStudent.txt");
	rename("list.txt", "ListYearStudent.txt");
}
void ViewListOfClass(ListLop& ds)
{
	gotoxy(15, 5); cout << "+---------------------------------------------------------------------------------+" << endl;
	gotoxy(15, 6); cout << char(124) << "  " << setw(5) << left << " STT " << char(124) << "  " << setw(15) << left << "   Ma lop   " << char(124) << "  " << setw(40) << left << "                  Ten lop " << char(124) << "  " << setw(10) << left << "Nam hoc" << char(124) << endl;
	gotoxy(15, 7); cout << "+---------------------------------------------------------------------------------+" << endl;

	for (int i = 0;i < ds.n;i++)
	{
		gotoxy(15, 8 + i);
		cout << char(124) << "  " << setw(5) << left << i + 1 << char(124) << "  " << setw(15) << left << ds.l[i].Ma << char(124) << "  " << setw(40) << left << ds.l[i].Ten << char(124) << "  " << setw(10) << left << ds.l[i].NienKhoa << char(124);
	}
	gotoxy(15, 8 + ds.n); cout << "+---------------------------------------------------------------------------------+" << endl;
}
void ViewListOfStudentInClass(ListLop& ds)
{
	cout << "Nhap ma lop: ";
	int ViTriLop;
	char Malop[10];
	int STT = 1;
	cin.get(Malop, 10, '\n');
	int KT = CheckClass(ds, Malop, ds.n);
	if (KT == 0) {
		cout << "Khong ton tai ma lop " << Malop << endl;
		return;
	}
	else if (KT == -1) ViTriLop = 0;
	else ViTriLop = KT;
	if (ds.l[ViTriLop].pHead == NULL) {
		cout << "Chua co sinh vien nao trong lop" << endl;
		return;
	}
	gotoxy(10, 3);cout << "---------------------------- " << ds.l[ViTriLop].Ma << " ----------------------------";
	gotoxy(5, 5); cout << "+--------------------------------=-----------------------------------------------------------------------------+" << endl;
	gotoxy(5, 6); cout << char(124) << "  " << setw(5) << left << "STT" << char(124) << "  " << setw(15) << left << "   MSSV   " << char(124) << "  " << setw(20) << left << " Ho " << char(124) << "  " << setw(20) << " Ten" << char(124) << "  " << setw(10) << left << "Gioi tinh" << char(124) << "  " << setw(10) << "Ngay sinh" << char(124) << "  " << setw(10) << left << "CMND/CCCD" << endl;
	gotoxy(5, 7); cout << "+--------------------------------=-----------------------------------------------------------------------------+" << endl;
	for (ListSV* k = ds.l[ViTriLop].pHead;k != NULL; k = k->pNext) {
		gotoxy(5, 7 + STT);
		cout << char(124) << "  " << setw(5) << left << STT++ << char(124) << "  " << setw(15) << left << k->info.ID << char(124) << "  " << setw(20) << left << k->info.FirstName << char(124) << "  " << setw(20) << k->info.LastName << char(124) << "  " << setw(10) << left << k->info.Gender << char(124) << "  " << setw(10) << k->info.DateOfBirth << char(124) << "  " << setw(10) << left << k->info.SocialID << char(124);
	}
	gotoxy(5, 7 + STT); cout << "+--------------------=-----------------------------------------------------------------------------------------+" << endl;
	gotoxy(0, 7 + STT + 1);
}