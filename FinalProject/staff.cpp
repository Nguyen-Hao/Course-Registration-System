#include "staff.h"
#include "Header.h"
#include "student.h"
#include "console.h"
#include "student.h"
#include "course.h"
#include "Semester.h"
#include "DKMon.h"
#include "SchoolYear.h"
#include <algorithm>
#include "Menu.h"

ListSV* Create_Node_Sv(SinhVien sv)
{
	ListSV* a = new ListSV;
	a->info = sv;
	a->pNext = NULL;
	return a;
}
NodeGV* CreateNodeGV(GiaoVien gv)
{
	NodeGV* a = new NodeGV;
	a->info = gv;
	a->pNext = NULL;
	return a;
}
void AddTailGV(ListGV& dsgv, GiaoVien gv)
{
	NodeGV* p = CreateNodeGV(gv);
	if (dsgv.pHead == NULL)
		dsgv.pHead = p;
	else
	{
		NodeGV* k = dsgv.pHead;
		while (k->pNext != NULL)
			k = k->pNext;
		k->pNext = p;
	}
}

void CreateNewClass(ListLop& ds, const SchoolYear& Y, int& t)
{
	t = 0;
	ofstream f;
	f.open(Y.DSLop, ios::app);
	Lop c;
	gotoxy(102, 9); getline(cin, c.Ma);
	gotoxy(102, 13); getline(cin, c.Ten);
	gotoxy(102, 17); getline(cin, c.NienKhoa);
	if (CheckClass(ds, c.Ma, ds.n) == 0)
	{
		f << c.Ma << endl;
		f << c.Ten << endl;
		f << c.NienKhoa << endl;
		c.pHead = NULL;
		ds.l[ds.n] = c;
		++ds.n;
		t = 1;
		fstream file;
		string s = c.Ma + "_" + "Filecsv.csv";
		file.open(s, ios::out);
		file << "STT, ID, FirstName, LastName,Gender,DOB,SocialID" << endl;
		file.close();
	}
	f.close();
}

bool CheckStudent(const SchoolYear& Y, const string& a)
{
	fstream file;
	file.open(Y.DSSinhVien);
	if (file.is_open())
	{
		while (!file.eof())
		{
			SinhVien sv;
			getline(file, sv.Class);
			getline(file, sv.ID);
			getline(file, sv.pass);
			getline(file, sv.FirstName);
			getline(file, sv.LastName);
			getline(file, sv.Gender);
			getline(file, sv.DateOfBirth);
			getline(file, sv.SocialID);
			file >> sv.begin[0] >> sv.begin[1] >> sv.begin[2];		file.ignore();
			file >> sv.YearStudent;									file.ignore();
			file >> sv.Semester;									file.ignore();
			if (sv.ID == a) return true;
		}
		return false;
	}
	else return false;
}

void AddStudent_Input(ListLop& dsl, const SchoolYear& Y)
{
	string c;
	string Pass = "123456";
	SinhVien sv;
	Frames(105, 5, 50, 1);
	gotoxy(70, 6);
	cout << "Nhap ID lop: ";
	gotoxy(108, 6); getline(cin, c);
	sv.Class = c;
	int STTLop, i;
	int KT = CheckClass(dsl, c, dsl.n);
	if (KT != 0)
	{
		if (KT != 0)
		{
			gotoxy(70, 9); cout << "Ngay nhap hoc "; Frames(105, 8, 10, 1); gotoxy(116, 9); cout << "/"; Frames(118, 8, 10, 1); gotoxy(129, 9); cout << "/"; Frames(131, 8, 10, 1);
			gotoxy(107, 9); cin >> sv.begin[0];
			gotoxy(120, 9); cin >> sv.begin[1];
			gotoxy(133, 9); cin >> sv.begin[2];
			Frames(105, 11, 50, 1);
			cin.ignore();
			gotoxy(70, 12);
			cout << "Nhap ID sinh vien: ";
			gotoxy(108, 12);
			getline(cin, sv.ID);
			Frames(105, 14, 50, 1);
			gotoxy(70, 15);
			cout << "Nhap ho: "; gotoxy(108, 15); getline(cin, sv.FirstName);
			Frames(105, 17, 50, 1);
			gotoxy(70, 18);
			cout << "Nhap ten: "; gotoxy(108, 18); getline(cin, sv.LastName);
			Frames(105, 20, 50, 1);
			gotoxy(70, 21);
			cout << "Nhap gioi tinh (Nam / Nu): "; gotoxy(108, 21); getline(cin, sv.Gender);
			Frames(105, 23, 50, 1);
			gotoxy(70, 24);
			cout << "Nhap ngay sinh (dd/mm/yyyy): "; gotoxy(108, 24); getline(cin, sv.DateOfBirth);
			Frames(105, 23, 50, 1);
			gotoxy(70, 24);
			cout << "Nhap Social ID: "; gotoxy(108, 24); getline(cin, sv.SocialID);
			if (KT == -1)
				STTLop = 0;
			else STTLop = KT;
			sv.YearStudent = 1;
			sv.Semester = 1;
			sv.pass = Pass;
			if (!CheckStudent(Y, sv.ID))
			{
				AddTailStudent(dsl.l[STTLop].pHead, sv);
				fstream file;
				file.open(string(dsl.l[STTLop].Ma) + "_" + FILECSV + ".csv", ios::in);
				string s[7];
				int STT = 0;
				getline(file, s[0]);
				while (!file.eof())
				{
					for (int i = 0; i < 6; ++i) getline(file, s[i], ',');
					getline(file, s[6]);
					if (s[0] != "") STT = stoi(s[0]);
				}
				file.close();
				file.open(string(dsl.l[STTLop].Ma) + "_" + FILECSV + ".csv", ios::app);
				file << STT + 1 << "," << sv.ID << "," << sv.FirstName << "," << sv.LastName << "," << sv.Gender << ","
					<< sv.DateOfBirth << "," << sv.SocialID << endl;
				file.close();
				file.open(Y.DSSinhVien, ios::app);
				file << sv.Class << endl;
				file << sv.ID << endl;
				file << sv.pass << endl;
				file << sv.FirstName << endl;
				file << sv.LastName << endl;
				file << sv.Gender << endl;
				file << sv.DateOfBirth << endl;
				file << sv.SocialID << endl;
				file << sv.begin[0] << " " << sv.begin[1] << " " << sv.begin[2] << endl;
				file << sv.YearStudent << endl;
				file << sv.Semester << endl;
				file.close();
			}
			else EffectFailed(70, 26, "ID Sinh vien da ton tai!");
		}
		else
		{
			EffectFailed(70, 26, "Khong tim thay lop. Vui long nhap lai...");
		}
	}
}
void ReadFileDSGV(ListGV& dsgv, const SchoolYear& Y)
{
	dsgv.pHead = NULL;
	ifstream file;
	file.open(FILEDSGV);
	if (file.fail())
	{
		EffectFailed(70, 26, "Failed to open this file!");
		exit(0);
	}
	GiaoVien gv;
	while (!file.eof())
	{
		file.clear();
		getline(file, gv.ID);
		if (gv.ID.length() == 0) break;
		getline(file, gv.pass);
		getline(file, gv.FirstName);
		getline(file, gv.LastName);
		getline(file, gv.Gender);
		getline(file, gv.DateOfBirth);
		getline(file, gv.SocialID);
		AddTailGV(dsgv, gv);
	}
	file.close();
}
void writeFileTeacher(ListGV dsgv, const SchoolYear& Y)
{
	ofstream file;
	file.open(FILEDSGV);
	if (file.fail())
	{
		EffectFailed(70, 26, "Failed to open this file!");
		exit(0);
	}
	NodeGV* p = dsgv.pHead;
	while (p != NULL)
	{
		file << p->info.ID << endl << p->info.pass << endl << p->info.FirstName << endl << p->info.LastName << endl;
		file << p->info.Gender << endl << p->info.DateOfBirth << endl << p->info.SocialID << endl;
		p = p->pNext;
	}
	file.close();
}

void writeFileCSVTeacher(ListGV dsgv)
{
	ofstream file("DsGiaoVien.csv");
	file << "STT,ID,Password,First Name,Last Name,Gender,Date of Birth,Social ID" << endl;
	NodeGV* p = dsgv.pHead;
	int stt = 0;
	while (p != NULL)
	{
		++stt;
		file << stt<<","<<p->info.ID << "," << p->info.pass << "," << p->info.FirstName << "," << p->info.LastName << ",";
		file << p->info.Gender << "," << p->info.DateOfBirth << "," << p->info.SocialID << endl;
		p = p->pNext;
	}
	file.close();
}

int Checkcourses(ListCourses dsl, string a)
{
	NodeCourse* p = dsl.head;
	int i = 0;
	for (p; p != NULL; p = p->next)
	{
		if (p->course.ID == a)
			if (i == 0) return -1;
			else return i;
		i++;
	}
	return 0;
}
void UpdateCSV(ListLop& ds, const SchoolYear& Y)
{
	Time t = getTime();
	ofstream file;
	file.open(Y.DSSinhVien, ios_base::app);
	int ViTriLop;
	vector<string> row;
	SinhVien sv;
	ifstream f1;
	ListSV* k;
	for (int i = 0; i < ds.n; ++i)
	{
		f1.open(string(ds.l[i].Ma) + "_" + FILECSV + ".csv", ios::in | ios::out);
		string line = "", word;
		getline(f1, line);
		ViTriLop = 0;
		while (f1.is_open())
		{
			getline(f1, line);
			if (line.size() == 0) break;
			stringstream s(line);
			row = {};
			while (getline(s, word, ','))
			{
				row.push_back(word);
			}
			sv.Class = ds.l[i].Ma;
			sv.ID = row[1];
			sv.FirstName = row[2];
			sv.LastName = row[3];
			sv.Gender = row[4];
			sv.DateOfBirth = row[5];
			sv.SocialID = row[6];
			sv.pass = "123456";
			sv.Semester = 1;
			sv.YearStudent = 1;
			sv.begin[0] = t.day; sv.begin[1] = t.month; sv.begin[2] = t.year; // gan co dinh
			if (!CheckStudent(Y, sv.ID))
			{
				file << sv.Class << endl;
				file << sv.ID << endl << sv.pass << endl;
				file << sv.FirstName << endl << sv.LastName << endl << sv.Gender << endl << sv.DateOfBirth << endl << sv.SocialID << endl;
				file << sv.begin[0] << " " << sv.begin[1] << " " << sv.begin[2] << " " << endl << sv.YearStudent << endl << sv.Semester << endl;
			}
		}
		f1.close();
	}
	file.close();
}

void UpdateStudent(const SchoolYear& Y)
{
	Time temp = getTime();
	fstream file, file1;
	file.open(Y.DSSinhVien, ios::in);
	file1.open("list.txt", ios::out);
	SinhVien temp1;
	int i;
	while (!file.eof())
	{
		getline(file, temp1.Class);
		getline(file, temp1.ID);
		getline(file, temp1.pass);
		getline(file, temp1.FirstName);
		getline(file, temp1.LastName);
		getline(file, temp1.Gender);
		getline(file, temp1.DateOfBirth);
		getline(file, temp1.SocialID);
		for (i = 0; i < 3; ++i)
			file >> temp1.begin[i];
		file.get();
		file >> temp1.YearStudent;
		file.get();
		file >> temp1.Semester;
		file.get();
		if (temp1.Class == "") break;
		else
		{
			file1 << temp1.Class << endl;
			file1 << temp1.ID << endl;
			file1 << temp1.pass << endl;
			file1 << temp1.FirstName << endl;
			file1 << temp1.LastName << endl;
			file1 << temp1.Gender << endl;
			file1 << temp1.DateOfBirth << endl;
			file1 << temp1.SocialID << endl;
			file1 << temp1.begin[0] << " " << temp1.begin[1] << " " << temp1.begin[2] << endl;
			if (temp.year - temp1.begin[2] == 1)
			{
				if ((temp.month == temp1.begin[1] && temp.day >= temp1.begin[0]) || (temp.month > temp1.begin[1]))
					temp1.YearStudent = 2;
			}
			else if (temp.year - temp1.begin[2] > 1)
			{
				if (temp.month < temp1.begin[1])
					temp1.YearStudent = temp.year - temp1.begin[2] - 1;
				else if (temp.month >= temp1.begin[1])
					temp1.YearStudent = temp.year - temp1.begin[2];
			}
			else temp1.YearStudent = 1;
			if (temp1.YearStudent > 6)
			{
				file1 << 7 << endl;
			}
			else
				file1 << temp1.YearStudent << endl;
			file1 << temp1.Semester << endl;

		}
	}
	file.close();
	file1.close();
	remove(Y.DSSinhVien.c_str());
	rename("list.txt", Y.DSSinhVien.c_str());
}
ListSV* findStudentOfCourses(const ListCourses& l, string mamon, int se, const SchoolYear& Y)
{
	ListSV* lsv = NULL;
	fstream file;
	file.open(to_string(se) + Y.StudentOfSubject, ios::in);
	string s;
	SinhVien sv;
	int i;
	while (getline(file, s))
	{
		if (s == mamon)
		{
			getline(file, s);
			while (true)
			{
				sv.Class = s;
				getline(file, sv.ID);
				getline(file, sv.pass);
				getline(file, sv.FirstName);
				getline(file, sv.LastName);
				getline(file, sv.Gender);
				getline(file, sv.DateOfBirth);
				getline(file, sv.SocialID);
				for (i = 0; i < 3; ++i) file >> sv.begin[i];
				file >> sv.YearStudent;
				file >> sv.Semester;
				AddTailStudent(lsv, sv);
				file.ignore();
				getline(file, s);
				if (CheckCourses(l, s) || s.size() == 0) break;
			}
			break;
		}
	}
	file.close();
	return lsv;
}
int ViewListOfClass(ListLop& ds)
{
	char key;
	int vitri = 0;
	int numberofPage = CountNodePage(ds.n);
	int page = 1, STT, count, i;
	while (true)
	{
		STT = 15 * (page - 1);
		count = 0;
		system("cls");
		FormMenu2();
		gotoxy(55, 2); TextColor(164); cout << " DANH SACH LOP HOC ";
		TextColor(224);\
		gotoxy(20, 4); cout << "+---------------------------------------------------------------------------------+" << endl;
		gotoxy(20, 5); cout << char(124) << "  " << setw(5) << left << " STT " << char(124) << "  " << setw(15) << left << "   Ma lop   " << char(124) << "  " << setw(40) << left << "                  Ten lop " << char(124) << "  " << setw(10) << left << "Nam hoc" << char(124) << endl;
		gotoxy(20, 6); cout << "+---------------------------------------------------------------------------------+" << endl;
		for (i = 0; i < 15; ++i)
		{
			if (STT + i >= ds.n) break;
			if (sizeof(ds.l[i + STT].Ten) == 0) break;
			count = i + 1;
			gotoxy(20, 7 + i);
			cout << char(124) << "  " << setw(5) << left << STT + i + 1 << char(124) << "  " << setw(15) << left << ds.l[i + STT].Ma << char(124) << "  " << setw(40) << left << ds.l[i + STT].Ten << char(124) << "  " << setw(10) << left << ds.l[i + STT].NienKhoa << char(124);
		}
		gotoxy(20, 7 + count); cout << "+---------------------------------------------------------------------------------+";
		gotoxy(15, 7 + count + 1);
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
		else if (vitri == 1)
		{
			if (page == numberofPage) continue;
			else
				++page;
		}
	}
}
int CountNodeStudent(ListSV* phead)
{
	ListSV* p = phead;
	int i = 0;
	while (p != NULL)
	{
		++i;
		p = p->pNext;
	}
	return i;
}
int CountNodePage(int i)
{
	int page = i / 15 + 1;
	if (i % 15 == 0)
		return page - 1;
	return page;
}
void ViewListOfStudentInClass(ListLop& ds)
{
	Frames(45, 32, 30, 1);
	gotoxy(45, 31);
	cout << "Nhap ma lop: ";
	int ViTriLop;
	string Malop;
	int STT = 1;
	gotoxy(48, 33);
	getline(cin, Malop);
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
	//
	char key;
	char arrowleft = 27;
	char arrowright = 26;
	int vitri = 0;
	int numberofstudent = CountNodeStudent(ds.l[ViTriLop].pHead);
	int numberofPage = CountNodePage(numberofstudent);
	int page = 1, i, j, count;
	ListSV* k;
	while (true)
	{
		k = ds.l[ViTriLop].pHead;
		STT = 15 * (page - 1);
		for (i = 1; i < page; ++i)
		{
			for (j = 0; j < 15; ++j)
			{
				k = k->pNext;
			}
		}
		count = 0;
		system("cls");
		gotoxy(50, 2); TextColor(164); cout << "DANH SACH SINH VIEN LOP " << ds.l[ViTriLop].Ma;
		TextColor(224);
		FormMenu3();
		gotoxy(20, 4); cout << "+--------------------------------------------------------------------------------------------------------------+" << endl;
		gotoxy(20, 5); cout << char(124) << "  " << setw(5) << left << "STT" << char(124) << "  " << setw(15) << left << "   MSSV   " << char(124) << "  " << setw(20) << left << " Ho " << char(124) << "  " << setw(20) << " Ten" << char(124) << "  " << setw(10) << left << "Gioi tinh" << char(124) << "  " << setw(10) << "Ngay sinh" << char(124) << "  " << setw(10) << left << "CMND/CCCD" << endl;
		gotoxy(20, 6); cout << "+--------------------------------------------------------------------------------------------------------------+" << endl;
		for (i = 0; i < 15; ++i)
		{
			if (k == NULL) break;
			count = i + 1;
			gotoxy(20, 7 + i);
			cout << char(124) << "  " << setw(5) << left << i + STT + 1 << char(124) << "  " << setw(15) << left << k->info.ID << char(124) << "  " << setw(20) << left << k->info.FirstName << char(124) << "  " << setw(20) << k->info.LastName << char(124) << "  " << setw(10) << left << k->info.Gender << char(124) << "  " << setw(10) << k->info.DateOfBirth << char(124) << "  " << setw(10) << left << k->info.SocialID << char(124);
			k = k->pNext;
		}
		gotoxy(20, 7 + count); cout << "+--------------------------------------------------------------------------------------------------------------+" << endl;
		gotoxy(15, 7 + count + 1);
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
			return;
			break;
		}
		if (vitri == 0 /*&& key == ENTER*/)
		{
			if (page == 1) continue;
			else
				--page;
		}
		if (vitri == 1/* && key == ENTER*/)
		{
			if (page == numberofPage) continue;
			else
				++page;
		}
	}
}

void ViewListOfStudentIncourses(ListCourses ds, int se, const SchoolYear& Y)
{
	string str;
	bool f;
	ViewListOfCourse(ds, se,str,f, Y);
	Frames(45, 32, 30, 1);
	gotoxy(45, 31);
	cout << "Nhap ma mon: ";
	int n = countNodeCourses(ds);
	int ViTrimon;
	string Mamon;
	int STT = 1;
	gotoxy(48, 33);
	getline(cin, Mamon);
	int KT = Checkcourses(ds, Mamon);
	if (KT == 0) {
		cout << "Khong ton tai ma mon " << Mamon << endl;
		return;
	}
	else if (KT == -1) ViTrimon = 0;
	else ViTrimon = KT;
	NodeCourse* p = ds.head;
	int i;
	for (i = 0; i < ViTrimon; ++i)
	{
		p = p->next;
	}
	ListSV* Lsv_Of_Courses = findStudentOfCourses(ds, Mamon, se, Y);
	ListSV* k = Lsv_Of_Courses;
	if (Lsv_Of_Courses == NULL) {
		cout << "Chua co sinh vien nao trong mon" << endl;
		return;
	}
	//
	char key;
	int vitri = 0;
	int numberofstudent = CountNodeStudent(Lsv_Of_Courses);
	int numberofPage = CountNodePage(numberofstudent);
	int page = 1,count,j;
	//gotoxy(40, 2); 
	while (true)
	{
		k = Lsv_Of_Courses;
		STT = 15 * (page - 1);
		for (i = 1; i < page; ++i)
		{
			for (j = 0; j < 15; ++j)
			{
				k = k->pNext;
			}
		}
		count = 0;
		system("cls");
		FormMenu3();
		transform(p->course.Name.begin(), p->course.Name.end(), p->course.Name.begin(), toupper);
		gotoxy(25, 2); TextColor(164); cout << "DANH SACH SINH VIEN DANG KY MON " << p->course.Name << " - KI " << se << " - Nam hoc " << Y.NameSchoolYear;
		TextColor(224);
		gotoxy(20, 5); cout << "+--------------------------------------------------------------------------------------------------------------+" << endl;
		gotoxy(20, 6); cout << char(124) << "  " << setw(5) << left << "STT" << char(124) << "  " << setw(15) << left << "   MSSV   " << char(124) << "  " << setw(20) << left << " Ho " << char(124) << "  " << setw(20) << " Ten" << char(124) << "  " << setw(10) << left << "Gioi tinh" << char(124) << "  " << setw(10) << "Ngay sinh" << char(124) << "  " << setw(10) << left << "CMND/CCCD" << char(124);
		gotoxy(20, 7); cout << "+--------------------------------------------------------------------------------------------------------------+" << endl;
		for (i = 0; i < 15; ++i)
		{
			if (k == NULL) break;
			count = i + 1;
			gotoxy(20, 8 + i);
			cout << char(124) << "  " << setw(5) << left << STT + i + 1 << char(124) << "  " << setw(15) << left << k->info.ID << char(124) << "  " << setw(20) << left << k->info.FirstName << char(124) << "  " << setw(20) << k->info.LastName << char(124) << "  " << setw(10) << left << k->info.Gender << char(124) << "  " << setw(10) << k->info.DateOfBirth << char(124) << "  " << setw(10) << left << k->info.SocialID << char(124);
			k = k->pNext;
		}
		gotoxy(20, 7 + count); cout << "+--------------------------------------------------------------------------------------------------------------+" << endl;
		gotoxy(0, 7 + count + 1);
		gotoxy(60, 28); cout << page << "/" << numberofPage;
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
			return;
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

void ExportListStudentInCourseToEnterScore(ListCourses dsm, int se, const SchoolYear& Y)
{
	ListSV* Lsv_Of_Courses, * k;
	int count;
	DiemMonHoc a;
	int t = YearPresent();
	string mamon, link;
	ifstream fileCheck;
	ofstream file;
	for (NodeCourse* p = dsm.head; p != NULL; p = p->next)
	{
		Lsv_Of_Courses = findStudentOfCourses(dsm, p->course.ID, se, Y);
		k = Lsv_Of_Courses;
		if (Lsv_Of_Courses != NULL)
		{
			count = 0;
			a.Final = a.MidTerm = a.Other = a.Total = 0.0;
			mamon = p->course.ID;
			link = "ScoreBoard" + to_string(t) + "_" + to_string(t + 1) + "_" + to_string(se) + "_" + mamon + ".csv";
			fileCheck.open(link);
			if (!fileCheck.is_open())
			{
				file.open(link);
				file << "STT,ID,First Name,Last Name,Total Mark, Final Mark, Midterm Mark, Other Mark" << endl;
				while (k != NULL)
				{
					count++;
					file << count << "," << k->info.ID << "," << k->info.FirstName << ","
						<< k->info.LastName << "," << a.Total << "," << a.Final << "," << a.MidTerm << "," << a.Other << endl;
					k = k->pNext;
				}
				file.close();
			}
			fileCheck.close();
		}
	}
}

void ViewScoreBoardOfACourse(ListCourses dsmon, int se, const SchoolYear& Y)
{
	int t = YearPresent();
	string s, word, mamon;
	Frames(45, 32, 30, 1);
	gotoxy(45, 31);
	cout << "Nhap ma mon: ";
	gotoxy(48, 33);
	getline(cin, mamon);
	string link = "ScoreBoard" + to_string(t) + "_" + to_string(t + 1) + "_" + to_string(se) + "_" + mamon + ".csv";
	ifstream fin;
	fin.open(link);
	if (!fin.is_open())
	{
		cout << "chua co bang diem " << mamon << endl;
		return;
	}
	getline(fin, s);
	int numberofstudent = 0;
	while (!fin.eof())
	{
		getline(fin, s);
		if (s.size() == 0) break;
		numberofstudent++;
	}
	//
	NodeCourse* p = dsmon.head;
	for (p; p != NULL; p = p->next)
	{
		if (p->course.ID == mamon)
			break;
	}
	fin.close();
	//

	char key;
	int vitri = 0;
	int page = 1, STT, i, j, count;
	int numberofPage = CountNodePage(numberofstudent);
	vector<string> row;
	while (true)
	{
		ifstream fin;
		fin.open(link);
		getline(fin, s);
		STT = 15 * (page - 1);
		for (i = 1; i < page; ++i)
		{
			for (j = 0; j < 15; ++j)
			{
				getline(fin, s);
			}
		}
		count = 0;
		system("cls");
		FormMenu3();
		transform(p->course.Name.begin(), p->course.Name.end(), p->course.Name.begin(), toupper);
		gotoxy(45, 2); TextColor(164); cout << "BANG DIEM TONG KET MON " << p->course.Name << " - KI " << se << " - Nam hoc " << Y.NameSchoolYear;
		TextColor(224);
		gotoxy(20, 5); cout << "+-------------------------------------------------------------------------------------------------------------------+" << endl;
		gotoxy(20, 6); cout << char(124) << "  " << setw(5) << left << "STT" << char(124) << "  " << setw(15) << left << "     MSSV" << char(124) << "  " << setw(20) << left << "         Ho" << char(124) << "  " << setw(20) << "        Ten" << char(124) << setw(10) << " Tong ket" << char(124) << setw(10) << " Cuoi ki" << char(124) << setw(10) << " Giua ki" << char(124) << setw(10) << "Qua trinh" << char(124) << endl;
		gotoxy(20, 7); cout << "+-------------------------------------------------------------------------------------------------------------------+" << endl;
		for (i = 0; i < 15; ++i)
		{
			count = i + 1;
			getline(fin, s);
			if (s.size() == 0)
			{
				count--;
				break;
			}
			stringstream si(s);
			row = {};
			while (getline(si, word, ','))
			{
				row.push_back(word);
			}
			gotoxy(20, 8 + i);
			cout << char(124) << "  " << setw(5) << left << i + STT + 1 << char(124) << "  " << setw(15) << left << row[1] << char(124) << "  " << setw(20) << left << row[2] << char(124) << "  " << setw(20) << row[3] << char(124) << setw(10) << row[4] << char(124) << setw(10) << row[5] << char(124) << setw(10) << row[6] << char(124) << setw(10) << row[7] << char(124) << endl;
			if (fin.eof())
			{
				--count;
				break;
			}
		}
		gotoxy(20, 8 + count); cout << "+-------------------------------------------------------------------------------------------------------------------+" << endl;
		gotoxy(0, 8 + count + 1);
		gotoxy(70, 28); cout << page << "/" << numberofPage;
		fin.close();
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
			return;
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
void updateAStudentResult(ListCourses ds, int se, const SchoolYear& Y)
{
	string str;
	bool f;
	ViewListOfCourse(ds, se, str, f, Y);
	Frames(45, 29, 30, 1);
	Frames(45, 33, 30, 1);
	Frames(45, 37, 7, 1);
	Frames(60, 37, 7, 1);
	Frames(75, 37, 7, 1);
	Frames(90, 37, 7, 1);
	gotoxy(37, 30);
	cout << "Ma mon:";
	gotoxy(31, 34);
	cout << "ID Sinh Vien:";
	gotoxy(44, 36);
	cout << "Total mark";
	gotoxy(58, 36);
	cout << "Final mark";
	gotoxy(73, 36);
	cout << "Midterm mark";
	gotoxy(88, 36);
	cout << "Other mark";
	int n = countNodeCourses(ds);
	int ViTrimon;
	char Mamon[50];
	int STT = 1;
	cin.ignore();
	gotoxy(45, 30);
	cin.get(Mamon, 50, '\n');
	int KT = Checkcourses(ds, Mamon);
	if (KT == 0) {
		EffectFailed(80, 13, "Khong ton tai ma mon!");
		return;
	}
	else if (KT == -1) ViTrimon = 0;
	else ViTrimon = KT;
	NodeCourse* p = ds.head;
	for (int i = 0; i < ViTrimon; ++i)
	{
		p = p->next;
	}
	ListSV* Lsv_Of_Courses = findStudentOfCourses(ds, Mamon, se, Y);
	ListSV* k = Lsv_Of_Courses;
	if (Lsv_Of_Courses == NULL) {
		EffectFailed(80, 13, "Chua co sinh vien nao trong mon");
		return;
	}
	char ID[10];
	cin.ignore();
	gotoxy(45, 34);
	cin.get(ID, 10, '\n');
	bool check = false;
	for (ListSV* i = k; i != NULL; i = i->pNext)
	{
		if (i->info.ID == ID)
		{
			check = true;
			break;
		}
	}
	if (!check)
	{
		EffectFailed(50, 24, "Khong ton tai sinh vien nay trong khoa hoc!");
		return;
	}
	ifstream file;
	ofstream file1;
	int count = 0;
	string mamon = Mamon;
	int t = YearPresent();
	string link = "ScoreBoard" + to_string(t) + "_" + to_string(t + 1) + "_" + to_string(se) + "_" + mamon + ".csv";
	file.open(link);
	if (!file.is_open())
	{
		EffectFailed(50, 24, "Bang diem khoa hoc nay chua duoc nhap!");
		return;
	}
	file1.open("tam.csv");
	file1 << "STT,ID,First Name,Last Name,Total Mark, Final Mark, Midterm Mark, Other Mark" << endl;
	string s;
	getline(file, s);
	DiemMonHoc a;
	for (k; k != NULL; k = k->pNext)
	{
		file >> count;
		file.get();
		getline(file, k->info.ID, ',');
		getline(file, k->info.FirstName, ',');
		getline(file, k->info.LastName, ',');
		file >> a.Total;
		file.get();
		file >> a.Final;
		file.get();
		file >> a.MidTerm;
		file.get();
		file >> a.Other;
		if (k->info.ID == ID)
		{
			gotoxy(46, 38);
			cin >> a.Total;
			gotoxy(61, 38);
			cin >> a.Final;
			gotoxy(76, 38);
			cin >> a.MidTerm;
			gotoxy(91, 38);
			cin >> a.Other;
		}
		file1 << count << "," << k->info.ID << "," << k->info.FirstName << ","
			<< k->info.LastName << "," << a.Total << "," << a.Final << "," << a.MidTerm << "," << a.Other << endl;
	}
	EffectSuccess(50, 24, "Da cap nhat");
	file.close();
	file1.close();
	remove(link.c_str());
	rename("tam.csv", link.c_str());
}
void ViewScoreOfAClass(ListLop dsl, ListCourses dsm, int se, const SchoolYear& Y)
{
	int t = YearPresent();
	string malop;
	Frames(45, 32, 30, 1);
	gotoxy(45, 31);
	cout << "Nhap ma lop: ";
	gotoxy(48, 33);
	getline(cin, malop);
	system("cls");
	ListCourses ds = ReadListCourses(se, Y);
	int VitriLop;
	int KT = CheckClass(dsl, malop, dsl.n);
	if (KT == 0)
	{
		cout << "Khong ton tai ma lop " << malop << endl;
		return;
	}
	if (KT == -1) VitriLop = 0;
	else
		VitriLop = KT;
	char key;
	int vitri = 0, n = 0;
	int numberofstudent = CountNodeStudent(dsl.l[VitriLop].pHead);
	int numberofPage = CountNodePage2(numberofstudent);
	int page = 1;
	while (true)
	{
		ListSV* k = dsl.l[VitriLop].pHead;
		int STT = 3 * (page - 1);
		for (int i = 1; i < page; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				k = k->pNext;
			}
		}
		int count = 0;
		int i = 0;
		system("cls");
		FormMenu3();
		gotoxy(45, 2); TextColor(164); cout << "BANG DIEM TONG KET LOP " << malop << " - KI " << se << " - Nam hoc " << Y.NameSchoolYear;
		TextColor(224);
		gotoxy(20, 4); cout << "+-------------------------------------------------------------------------------------------------------------+" << endl;
		gotoxy(20, 5); cout << char(124) << "  " << setw(4) << left << "STT" << char(124) << "  " << setw(14) << left << "     MSSV" << char(124) << "  " << setw(19) << left << "         Ho" << char(124) << "  " << setw(19) << "   Ten" << char(124) << setw(30) << "          Mon hoc" << char(124) << setw(10) << "   Diem" << char(124) << endl;
		gotoxy(20, 6); cout << "+-------------------------------------------------------------------------------------------------------------+" << endl;
		for (int j = 0; j < 3; j++)
		{
			if (k == NULL) break;
			double TotalMark = 0;
			int SoChi = 0;
			bool flat = false;
			for (NodeCourse* p = dsm.head; p->next != NULL; p = p->next)
			{
				ListSV* psv = findStudentOfCourses(dsm, p->course.ID, se, Y);
				for (psv; psv != NULL; psv = psv->pNext)
				{
					if (psv->info.ID == k->info.ID)
					{
						string link = "ScoreBoard" + to_string(t) + "_" + to_string(t + 1) + "_" + to_string(se) + "_" + string(p->course.ID) + ".csv";
						ifstream f(link);
						if (f.is_open()) {
							string s[8];
							getline(f, s[0]);
							while (!f.eof())
							{
								for (int i = 0; i < 7; i++) getline(f, s[i], ',');
								getline(f, s[7]);
								if (s[0] == "") break;
								if (s[1] == k->info.ID)
								{
									count++;
									SoChi += p->course.NumOfCredits;
									TotalMark += stoi(s[4]) * p->course.NumOfCredits;
									flat = true;
									gotoxy(20, 6 + count + 2 * j);
									cout << char(124) << " " << setw(5) << left << "" << char(124) << " " << setw(15) << left << s[1] << char(124) << " " << setw(20) << left << s[2] << char(124) << " " << setw(20) << s[3] << char(124) << setw(30) << p->course.Name << char(124) << setw(10) << s[4] << char(124) << endl; gotoxy(20, 7 + ++n + 1);
								}
							}
						}
						f.close();
					}
				}
			}
			i = count + 1;
			if (flat == true) {
				TextColor(225);
				gotoxy(20, 6 + i + 2 * j);
				i++;
				cout << char(124) << " " << setw(5) << left << STT+1 << char(124) << " " << setw(15) << left << k->info.ID << char(124) << " " << setw(20) << left << k->info.FirstName << char(124) << " " << setw(20) << k->info.LastName << char(124) << setw(30) << "GPA ki" << char(124) << setw(10) << (TotalMark / SoChi) * 1.0 << char(124) << endl;
			}
			else {
				gotoxy(20, 6 + i + 2 * j);
				i++;
				cout << char(124) << " " << setw(5) << left << STT+1 << char(124) << " " << setw(15) << left << k->info.ID << char(124) << " " << setw(20) << left << k->info.FirstName << char(124) << " " << setw(20) << k->info.LastName << char(124) << setw(30) << "GPA ki" << char(124) << setw(10) << 0.0 << char(124) << endl;
				TextColor(224);
			}
			STT += 1;
			TextColor(224);
			gotoxy(20, 6 + i + 2 * j); cout << "+-------------------------------------------------------------------------------------------------------------+" << endl;
			i++;
			k = k->pNext;
			gotoxy(0, 0);
		}
		gotoxy(50, 28); cout << page << "/" << numberofPage;
		key = GetKey();
		if (key == LEFT)// sang trai
		{
			vitri = 0;
		}
		if (key == RIGHT) // sang phai
		{
			vitri = 1;
		}
		if (key == ESC) // thoat vong lap
		{
			return;
		}
		if (vitri == 0)
		{
			if (page == 1) continue;
			else
				page--;
		}
		if (vitri == 1)
		{
			if (page == numberofPage) continue;
			else
				page++;
		}
	}
}
DiemMonHoc ReadfileCSVScore(const SinhVien& S, const SchoolYear& Y, int se, string mamon)
{
	int t = YearPresent();
	fstream f1;
	string link = "ScoreBoard" + to_string(t) + "_" + to_string(t + 1) + "_" + to_string(se) + "_" + mamon + ".csv";
	f1.open(link, ios::in);
	DiemMonHoc score;
	if (f1.is_open())
	{
		string line, word;
		vector<string> row;
		string ID;
		while (!f1.eof())
		{
			line = ""; word = "";
			getline(f1, line);
			if (line.size() == 0) break;
			stringstream s(line);
			row = {};
			while (getline(s, word, ','))
				row.push_back(word);
			ID = row[1];
			if (ID == S.ID)
			{
				score.Total = stod(row[4]);
				score.Final = stod(row[5]);
				score.MidTerm = stod(row[6]);
				score.Other = stod(row[7]);
				break;
			}

		}
	}
	f1.close();
	return score;
}
void PrintFileCSV(ListLop dsl, SchoolYear Y)
{
	string nameFile;
	ifstream fin;
	ofstream file;
	for (int i = 0; i < dsl.n; ++i)
	{
		nameFile = string(dsl.l[i].Ma) + "_" + FILECSV + ".csv";
		fin.open(nameFile);
		if (!fin.is_open())
		{
			file.open(nameFile);
			file << "STT, ID, FirstName, LastName,Gender,DOB,SocialID";
			file.close();
		}
	}
}
void updateDSGV()
{
	ifstream fileCSV("DsGiaoVien.csv");
	ofstream fileTXT(FILEDSGV);
	string s[8];
	getline(fileCSV, s[0]);
	while (!fileCSV.eof())
	{
		for (int i = 0; i < 7; i++)
			getline(fileCSV, s[i], ',');
		getline(fileCSV, s[7]);
		if (!s[0].empty())
		{
			fileTXT << s[1] << endl << s[2] <<endl<< s[3] <<endl<< s[4] << endl<<s[5] <<endl<< s[6]<<endl << s[7] << endl;
		}
	}
	fileCSV.close();
	fileTXT.close();
}