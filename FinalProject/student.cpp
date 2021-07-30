#include "student.h"
#include "Header.h"
#include "console.h"
#include "Semester.h"
#include "DKMon.h"
#include "course.h"
#include "staff.h"
#include "SchoolYear.h"

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
	for (int i = 0; i < n; i++)
	{
		if (strcmp(dsl.l[i].Ma, a) == 0)
			if (i == 0) return -1; //neu dau tien thi tra ve -1 
			else return i;
	}
	return 0; // tra ve 0 khi khong tim thay
}
void AddStudent_Input(ListLop& dsl)
{
	char c[10];
	char Pass[10] = "123456";
	SinhVien sv;
	gotoxy(70, 8);
	cout << "Nhap ID lop: "; cin.get(c, 10, '\n');
	int STTLop;
	int KT = CheckClass(dsl, c, dsl.n);
	if (KT != 0)
	{
		cin.ignore();
		gotoxy(70, 9);
		cout << "Ngay nhap hoc: (dd mm yyyy)"; for (int i = 0; i < 3; i++) cin >> sv.begin[i];
		cin.ignore();
		gotoxy(70, 10);
		cout << "Nhap ID sinh vien: "; cin.get(sv.ID, 10, '\n');
		cin.ignore();
		gotoxy(70, 11);
		cout << "Nhap ho: "; cin.get(sv.FirstName, 50, '\n');
		cin.ignore();
		gotoxy(70, 12);
		cout << "Nhap ten: "; cin.get(sv.LastName, 50, '\n');
		cin.ignore();
		gotoxy(70, 13);
		cout << "Nhap gioi tinh: "; cin.get(sv.Gender, 10, '\n');
		cin.ignore();
		gotoxy(70, 14);
		cout << "Nhap ngay sinh (dd/mm/yyyy): "; cin.get(sv.DateOfBirth, 50, '\n');
		cin.ignore();
		gotoxy(70, 15);
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
void WriteFileStudent(ListLop& dsl,const SchoolYear&Y)
{
	ofstream file;
	file.open(Y.DSSinhVien, ios::out);
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
	file.close();
}
void ReadFileStudent(ListLop& dsl, const SchoolYear&Y)
{
	ifstream file;
	file.open(Y.DSSinhVien, ios::in);
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
		for (int i = 0; i < 3; i++) file >> sv.begin[i];
		file >> sv.YearStudent;
		file >> sv.Semester;
		AddTailStudent(dsl.l[STTLop].pHead, sv);
	}
	file.close();
}

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
void Read_File_DSGV(ListGV&dsgv, const SchoolYear&Y)
{
	dsgv.pHead = NULL;
	ifstream file;
	file.open(Y.DsGiaoVien);
	if (file.fail())
	{
		cout << "Failed to open this file!" << endl;
		exit(0);
	}
	while (!file.eof())
	{
		GiaoVien gv;
		file.clear();
		file.getline(gv.ID, 10);
		file.getline(gv.pass, 20);
		file.getline(gv.FirstName, 20);
		file.getline(gv.LastName, 20);
		file.getline(gv.Gender, 20);
		file.getline(gv.DateOfBirth, 20);
		file.getline(gv.SocialID, 20);
		AddTailGV(dsgv, gv);
	}
	file.close();
}
void writeFileTeacher(ListGV dsgv, const SchoolYear&Y)
{
	ofstream file;
	file.open(Y.DsGiaoVien);
	if (file.fail())
	{
		cout << "Failed to open this file!" << endl;
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
//
//
void UpdateCSV(ListLop& ds,const SchoolYear&Y)
{
	ifstream f1;
	f1.open(Y.Filecsv, ios::in | ios::out);
	string line = "", word;
	int ViTriLop;
	ofstream file;
	file.open(Y.DSSinhVien, ios_base::out);
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
	WriteFileStudent(ds,Y);
	file.close();
	f1.close();
}

void UpdateStudent(const SchoolYear&Y)
{
	Time temp = getTime();

	fstream file, file1;
	file.open(Y.DSSinhVien, ios::in);
	file1.open("list.txt", ios::out);
	while (!file.eof())
	{
		SinhVien temp1;
		file.getline(temp1.Class, 10);
		file.getline(temp1.ID, 10);
		file.getline(temp1.pass, 20);
		file.getline(temp1.FirstName, 50);
		file.getline(temp1.LastName, 50);
		file.getline(temp1.Gender, 10);
		file.getline(temp1.DateOfBirth, 50);
		file.getline(temp1.SocialID, 10);
		for (int i = 0; i < 3; i++)
			file >> temp1.begin[i];
		file.get();
		file >> temp1.YearStudent;
		file.get();
		file >> temp1.Semester;
		file.get();
		if (strcmp(temp1.Class, "") == 0) break;
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
			}//sinh vien có yearStudent=7 la sinh vien da ra truong
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
void ViewListOfClass(ListLop& ds)
{
	gotoxy(20, 4); cout << "+---------------------------------------------------------------------------------+" << endl;
	gotoxy(20, 5); cout << char(124) << "  " << setw(5) << left << " STT " << char(124) << "  " << setw(15) << left << "   Ma lop   " << char(124) << "  " << setw(40) << left << "                  Ten lop " << char(124) << "  " << setw(10) << left << "Nam hoc" << char(124) << endl;
	gotoxy(20, 6); cout << "+---------------------------------------------------------------------------------+" << endl;

	for (int i = 0; i < ds.n; i++)
	{
		gotoxy(20, 7 + i);
		cout << char(124) << "  " << setw(5) << left << i + 1 << char(124) << "  " << setw(15) << left << ds.l[i].Ma << char(124) << "  " << setw(40) << left << ds.l[i].Ten << char(124) << "  " << setw(10) << left << ds.l[i].NienKhoa << char(124);
	}
	gotoxy(20, 7 + ds.n); cout << "+---------------------------------------------------------------------------------+" << endl;
}
void ViewListOfStudentInClass(ListLop& ds)
{
	gotoxy(10, 3);
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
	gotoxy(35, 3); cout << "---------------------------- " << ds.l[ViTriLop].Ma << " ----------------------------";
	gotoxy(20, 4); cout << "+--------------------------------------------------------------------------------------------------------------+" << endl;
	gotoxy(20, 5); cout << char(124) << "  " << setw(5) << left << "STT" << char(124) << "  " << setw(15) << left << "   MSSV   " << char(124) << "  " << setw(20) << left << " Ho " << char(124) << "  " << setw(20) << " Ten" << char(124) << "  " << setw(10) << left << "Gioi tinh" << char(124) << "  " << setw(10) << "Ngay sinh" << char(124) << "  " << setw(10) << left << "CMND/CCCD" << endl;
	gotoxy(20, 6); cout << "+--------------------------------------------------------------------------------------------------------------+" << endl;
	for (ListSV* k = ds.l[ViTriLop].pHead; k != NULL; k = k->pNext) {
		gotoxy(20, 6 + STT);
		cout << char(124) << "  " << setw(5) << left << STT++ << char(124) << "  " << setw(15) << left << k->info.ID << char(124) << "  " << setw(20) << left << k->info.FirstName << char(124) << "  " << setw(20) << k->info.LastName << char(124) << "  " << setw(10) << left << k->info.Gender << char(124) << "  " << setw(10) << k->info.DateOfBirth << char(124) << "  " << setw(10) << left << k->info.SocialID << char(124);
	}
	gotoxy(20, 6 + STT); cout << "+--------------------------------------------------------------------------------------------------------------+" << endl;
	gotoxy(15, 6 + STT + 1);
}
///
//
//

//
//
int Checkcourses(ListCourses dsl, char a[10])
{
	NodeCourse* p = dsl.head;
	int i = 0;
	for (p; p != NULL; p = p->next)
	{
		if (strcmp(p->course.ID, a) == 0)
			if (i == 0) return -1; //neu dau tien thi tra ve -1 
			else return i;
		i++;
	}
	return 0; // tra ve 0 khi khong tim thay
}
//

ListSV* findStudentOfCourses(const ListCourses& l, char mamon[50],const SchoolYear&Y)
{
	ListSV* lsv = NULL;
	fstream file;
	listSemester li;
	init(li);
	int se = getSemester(li, Y);
	file.open(to_string(se)+Y.StudentOfSubject, ios::in);
	string s;
	while (getline(file, s))
	{
		if (strcmp(s.c_str(), mamon) == 0)
		{
			getline(file, s);
			while (true) 
			{
				SinhVien sv;
				strcpy_s(sv.Class, 10, s.c_str());
				getline(file, s);	strcpy_s(sv.ID, 10, s.c_str());
				getline(file, s);	strcpy_s(sv.pass, 20, s.c_str());
				getline(file, s);	strcpy_s(sv.FirstName, 50, s.c_str());
				getline(file, s);	strcpy_s(sv.LastName, 50, s.c_str());
				getline(file, s);	strcpy_s(sv.Gender, 10, s.c_str());
				getline(file, s);	strcpy_s(sv.DateOfBirth, 50, s.c_str());
				getline(file, s);	strcpy_s(sv.SocialID, 10, s.c_str());
				for (int i = 0; i < 3; i++) file >> sv.begin[i];
				file >> sv.YearStudent; 
				file >> sv.Semester; 
				AddTailStudent(lsv, sv);
				file.ignore();
				getline(file, s); 
				if(ktra(l,s) == true || s.size() == 0) break;
			}
			break;
		}
	}
	file.close();
	return lsv;
}
//
void export_list_student_in_a_course_to_csv(const SchoolYear&Y)
{
	cin.ignore();
	ListCourses ds = ReadListCourses(Y);
	ViewListOfCourse(Y);
	cout << "Nhap ma mon: ";
	int n = countNodeCourses(ds);
	int ViTrimon;
	char Mamon[50];
	int STT = 1;
	cin.get(Mamon, 50, '\n');
	int KT = Checkcourses(ds, Mamon);
	if (KT == 0) {
		cout << "Khong ton tai ma mon " << Mamon << endl;
		return;
	}
	else if (KT == -1) ViTrimon = 0;
	else ViTrimon = KT;
	NodeCourse* p = ds.head;
	for (int i = 0; i < ViTrimon; i++)
	{
		p = p->next;
	}
	ListSV* Lsv_Of_Courses = findStudentOfCourses(ds, Mamon,Y);
	ListSV* k = Lsv_Of_Courses;
	if (Lsv_Of_Courses == NULL) {
		cout << "Chua co sinh vien nao trong mon" << endl;
		return;
	}
	ofstream file;
	int count=0;
	string mamon = Mamon;
	listSemester l;
	init(l);
	int se = getSemester(l, Y);
	int t = nam();
	string link = "DSSV_" + mamon + "_"+to_string(se)+"_"+to_string(n-1)+"_"+to_string(n)+".csv";
	file.open(link);
	file << "STT,ID,First Name,Last Name" << endl;
	for (k; k != NULL; k = k->pNext)
	{
		count++;
		file << count << "," << k->info.ID << "," << k->info.FirstName << "," << k->info.LastName << endl;
	}
	file.close();
}
//
void ViewListOfStudentIncourses(const SchoolYear&Y)
{
	ListCourses ds = ReadListCourses(Y);
	ViewListOfCourse(Y);
	cout << "Nhap ma mon: ";
	int n = countNodeCourses(ds);
	int ViTrimon;
	char Mamon[50];
	int STT = 1;
	cin.get(Mamon, 50, '\n');
	int KT = Checkcourses(ds, Mamon);
	if (KT == 0) {
		cout << "Khong ton tai ma mon " << Mamon << endl;
		return;
	}
	else if (KT == -1) ViTrimon = 0;
	else ViTrimon = KT;
	NodeCourse* p = ds.head;
	for (int i = 0; i < ViTrimon; i++)
	{
		p = p->next;
	}
	ListSV* Lsv_Of_Courses = findStudentOfCourses(ds, Mamon,Y);
	ListSV* k = Lsv_Of_Courses;
	if (Lsv_Of_Courses == NULL) {
		cout << "Chua co sinh vien nao trong mon" << endl;
		return;
	}
	system("cls");
	gotoxy(10, 3); cout << "---------------------------- " << p->course.Name << " ----------------------------";
	gotoxy(5, 5); cout << "+--------------------------------=-----------------------------------------------------------------------------+" << endl;
	gotoxy(5, 6); cout << char(124) << "  " << setw(5) << left << "STT" << char(124) << "  " << setw(15) << left << "   MSSV   " << char(124) << "  " << setw(20) << left << " Ho " << char(124) << "  " << setw(20) << " Ten" << char(124) << "  " << setw(10) << left << "Gioi tinh" << char(124) << "  " << setw(10) << "Ngay sinh" << char(124) << "  " << setw(10) << left << "CMND/CCCD" << endl;
	gotoxy(5, 7); cout << "+--------------------------------------------------------------------------------------------------------------+" << endl;
	for (k; k != NULL; k = k->pNext) {
		gotoxy(5, 7 + STT);
		cout << char(124) << "  " << setw(5) << left << STT++ << char(124) << "  " << setw(15) << left << k->info.ID << char(124) << "  " << setw(20) << left << k->info.FirstName << char(124) << "  " << setw(20) << k->info.LastName << char(124) << "  " << setw(10) << left << k->info.Gender << char(124) << "  " << setw(10) << k->info.DateOfBirth << char(124) << "  " << setw(10) << left << k->info.SocialID << char(124);
	}
	gotoxy(5, 7 + STT); cout << "+--------------------------------------------------------------------------------------------------------------+" << endl;
	gotoxy(0, 7 + STT + 1);
}

void ExportListStudentInCourseToEnterScore(const SchoolYear&Y)
{
	cin.ignore();
	ListCourses ds = ReadListCourses(Y);
	ViewListOfCourse(Y);
	cout << "Nhap ma mon: ";
	int n = countNodeCourses(ds);
	int ViTrimon;
	char Mamon[50];
	int STT = 1;
	cin.get(Mamon, 50, '\n');
	int KT = Checkcourses(ds, Mamon);
	if (KT == 0) {
		cout << "Khong ton tai ma mon " << Mamon << endl;
		return;
	}
	else if (KT == -1) ViTrimon = 0;
	else ViTrimon = KT;
	NodeCourse* p = ds.head;
	for (int i = 0; i <= ViTrimon; i++)
	{
		p = p->next;
	}
	ListSV* Lsv_Of_Courses = findStudentOfCourses(ds, Mamon,Y);
	ListSV* k = Lsv_Of_Courses;
	if (Lsv_Of_Courses == NULL) {
		cout << "Chua co sinh vien nao trong mon" << endl;
		return;
	}
	ofstream file;
	int count = 0;
	DiemMonHoc a;
	a.Final = a.MidTerm = a.Other = a.Total = 0.0;
	string mamon = Mamon;
	int t = nam();
	listSemester l;
	init(l);
	int se = getSemester(l, Y);
	string link = "ScoreBoard" + to_string(t - 1) + "_" + to_string(t) + "_" +to_string(se)+"_"+ mamon + ".csv";
	file.open(link);
	file << "STT,ID,First Name,Last Name,Total Mark, Final Mark, Midterm Mark, Other Mark" << endl;
	for (k; k != NULL; k = k->pNext)
	{
		count++;
		file << count << "," << k->info.ID << "," << k->info.FirstName << "," 
			<< k->info.LastName << ","<<a.Total<<","<<a.Final<<","<<a.MidTerm<<","<<a.Other<<endl;
	}
	file.close();
}

void ViewScoreBoardOfACourse(ListCourses dsmon, const SchoolYear&Y)
{
	int t = nam();
	string s, word, mamon;
	cout << "Nhap ma mon: "; cin >> mamon;
	int STT = 1;
	listSemester l;
	init(l);
	int se = getSemester(l, Y);
	string link = "ScoreBoard" + to_string(t - 1) + "_" + to_string(t) + "_" + to_string(se)+"_"+mamon + ".csv";
	ifstream fin(link);
	if (!fin.is_open())
	{
		cout << "Khong ton tai ma mon " << mamon  << endl;
		return;
	}
	else
	{
		NodeCourse* k = dsmon.head;
		for (k; k != NULL;k = k->next)
		{
			if (strcmp(k->course.ID, mamon.c_str()) == 0)
				break;
		}
		getline(fin, s);
		gotoxy(10, 3); cout << "\t\t---------------------------- " << k->course.Name << " ----------------------------";
		gotoxy(5, 5); cout << "+-------------------------------------------------------------------------------------------------------------------+" << endl;
		gotoxy(5, 6); cout << char(124) << "  " << setw(5) << left << "STT" << char(124) << "  " << setw(15) << left << "     MSSV" << char(124) << "  " << setw(20) << left << "         Ho" << char(124) << "  " << setw(20) << "        Ten" << char(124) << setw(10) << "  Total" << char(124) << setw(10) << "  Final" << char(124) << setw(10) << "  Midterm" << char(124) << setw(10) << "  Other" << char(124) << endl;
		gotoxy(5, 7); cout << "+-------------------------------------------------------------------------------------------------------------------+" << endl;
		while (!fin.eof())
		{
			getline(fin, s);
			if (s.size() == 0) break;
			stringstream si(s);
			vector<string> row;
			while (getline(si, word, ','))
			{
				row.push_back(word);
			}
			gotoxy(5, 7 + STT);
			cout << char(124) << "  " << setw(5) << left << STT++ << char(124) << "  " << setw(15) << left << row[1] << char(124) << "  " << setw(20) << left << row[2] << char(124) << "  " << setw(20) << row[3] << char(124) << setw(10) << row[4] << char(124) << setw(10) << row[5] << char(124) << setw(10) << row[6] << char(124) << setw(10) << row[7] << char(124) << endl;
			gotoxy(5, 7 + STT); cout << "+-------------------------------------------------------------------------------------------------------------------+" << endl;
			gotoxy(0, 7 + STT + 1);
		}
	}
}
void updateAStudentResult(const SchoolYear&Y)
{
	cin.ignore();
	ListCourses ds = ReadListCourses(Y);
	ViewListOfCourse(Y);
	cout << "Nhap ma mon: ";
	int n = countNodeCourses(ds);
	int ViTrimon;
	char Mamon[50];
	int STT = 1;
	cin.get(Mamon, 50, '\n');
	int KT = Checkcourses(ds, Mamon);
	if (KT == 0) {
		cout << "Khong ton tai ma mon " << Mamon << endl;
		return;
	}
	else if (KT == -1) ViTrimon = 0;
	else ViTrimon = KT;
	NodeCourse* p = ds.head;
	for (int i = 0; i < ViTrimon; i++)
	{
		p = p->next;
	}
	ListSV* Lsv_Of_Courses = findStudentOfCourses(ds, Mamon,Y);
	ListSV* k = Lsv_Of_Courses;
	if (Lsv_Of_Courses == NULL) {
		cout << "Chua co sinh vien nao trong mon" << endl;
		return;
	}
	char ID[10];
	cin.ignore();
	cout << "Nhap ID sinh vien: ";
	cin.get(ID, 10, '\n');
	bool check = false;
	for (ListSV*i=k; i != NULL; i = i->pNext)
	{
		if (strcmp(i->info.ID, ID) == 0)
		{
			check = true;
			break;
		}
	}
	if (!check)
	{
		cout << "Khong ton tai sinh vien nay trong khoa hoc!" << endl;
		return;
	}
	ifstream file;
	ofstream file1;
	int count = 0;
	string mamon = Mamon;
	int t = nam();
	listSemester l;
	init(l);
	int se = getSemester(l, Y);
	string link = "ScoreBoard" + to_string(t - 1) + "_" + to_string(t) + "_" + to_string(se)+"_"+mamon + ".csv";
	file.open(link);
	if (!file.is_open())
	{
		cout << "Bang diem khoa hoc nay chua duoc nhap!" << endl;
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
		file.ignore();
		file.get(k->info.ID, strlen(k->info.ID)+1, ',');
		file.ignore();
		file.get(k->info.FirstName, strlen(k->info.FirstName)+1, ',');
		file.ignore();
		file.get(k->info.LastName, strlen(k->info.LastName)+1, ',');
		file.ignore();
		file >> a.Total;
		file.ignore();
		file >> a.Final;
		file.ignore();
		file >> a.MidTerm;
		file.ignore();
		file>> a.Other;
		if (strcmp(k->info.ID, ID) == 0)
		{
			cout << "Nhap diem cap nhat:" << endl;
			cout << "Total mark: ";
			cin >> a.Total;
			cout << "Final mark: ";
			cin >> a.Final;
			cout << "Midterm mark: ";
			cin >> a.MidTerm;
			cout << "Other mark: ";
			cin >> a.Other;
		}
		file1 << count << "," << k->info.ID << "," << k->info.FirstName << ","
			<< k->info.LastName << "," << a.Total << "," << a.Final << "," << a.MidTerm << "," << a.Other << endl;
	}
	file.close();
	file1.close();
	remove(link.c_str());
	rename("tam.csv",link.c_str());
}
void ViewScoreOfAClass(ListLop dsl, ListCourses dsm,const SchoolYear&Y)
{
	int t = nam();
	cin.ignore();
	char malop[50];
	cout << "Nhap ma lop: "; cin.get(malop, 50, '\n');
	ListCourses ds = ReadListCourses(Y);
	bool flat = false;
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
	NodeCourse* p = ds.head;
	for (int i = 0; i < VitriLop; i++)
	{
		p = p->next;
	}
	gotoxy(35, 3); cout << "\t\t---------------------------- " << malop << " ----------------------------";
	gotoxy(20, 4); cout << "+-------------------------------------------------------------------------------------------------------+" << endl;
	gotoxy(20, 5); cout << char(124) << "  " << setw(5) << left << "STT" << char(124) << "  " << setw(15) << left << "     MSSV" << char(124) << "  " << setw(20) << left << "         Ho" << char(124) << "  " << setw(10) << "   Ten" << char(124) << setw(30) << "          Mon hoc" << char(124) << setw(10) << "   Diem" << char(124) << endl;
	gotoxy(20, 6); cout << "+-------------------------------------------------------------------------------------------------------+" << endl;
	int STT = 1, n = 1;
	for (ListSV* k = dsl.l[VitriLop].pHead; k != NULL; k = k->pNext)
	{
		double TotalMark = 0;
		int SoChi = 0;
		for (NodeCourse* p = dsm.head;p->next != NULL; p = p->next)
		{
			ListSV* psv = findStudentOfCourses(dsm, p->course.ID,Y);
			for (psv; psv != NULL;psv = psv->pNext)
			{
				if (strcmp(psv->info.ID, k->info.ID))
				{
					listSemester l;
					init(l);
					int se = getSemester(l, Y);
					string link = "ScoreBoard" + to_string(t-1) + "_" + to_string(t) + "_" + to_string(se)+"_"+string(p->course.ID) + ".csv";
					ifstream f(link);
					if (f.is_open()) {
						string s;
						getline(f, s);
						while (f.good())
						{
							getline(f, s);
							if (s.size() == 0) break;
							stringstream ss(s);
							vector<string> row;
							while (getline(ss, s, ','))
							{
								row.push_back(s);
							}
							if (strcmp(row[1].c_str(), k->info.ID) == 0)
							{
								SoChi += p->course.NumOfCredits;
								TotalMark += stoi(row[4]) * p->course.NumOfCredits;
								flat = true;
								gotoxy(20, 7 + n);
								cout << char(124) << "  " << setw(5) << left << STT++ << char(124) << "  " << setw(15) << left << row[1] << char(124) << "  " << setw(20) << left << row[2] << char(124) << "  " << setw(10) << row[3] << char(124) << setw(30) << p->course.Name << char(124) << setw(10) << row[4] << char(124) << endl;
								gotoxy(20, 7 + ++n + 1);
							}
						}
					}
					f.close();
				}
			}
		}
		TextColor(79);
		gotoxy(20, 7 + n++); cout << "+-------------------------------------------- GPA ki: " <<setw(5)<< TotalMark / SoChi * 1.0 <<"+--------------------------------------------+" <<endl;
		TextColor(224);
	}
}

DiemMonHoc ReadfileCSVScore(SinhVien S, const SchoolYear& Y, char* mamon)
{
	int t = nam();
	ifstream f1;
	listSemester l;
	init(l);
	int se = getSemester(l, Y);
	string link = "ScoreBoard" + to_string(t-1) + "_" + to_string(t) + "_" +to_string(se)+"_"+ mamon + ".csv";
	f1.open(link, ios::in | ios::out);
	string line = "", word;
	DiemMonHoc score;
	score.Final = 0;
	score.MidTerm = 0;
	score.Other = 0;
	score.Total = 0;
	if (f1.is_open())
	{
		while (!f1.eof())
		{

			char Mssv[10];
			strcpy_s(Mssv, S.ID);
			getline(f1, line);
			if (line.size() == 0) break;
			stringstream s(line);
			vector<string> row;
			while (getline(s, word, ','))
			{
				row.push_back(word);
			}
			SinhVien sv;
			strcpy_s(sv.ID, 10, row[1].c_str());
			strcpy_s(sv.FirstName, 50, row[2].c_str());
			strcpy_s(sv.LastName, 50, row[3].c_str());
			score.Total = 1.0 * stoi(row[4].c_str());
			score.Final = 1.0 * stoi(row[5].c_str());
			score.MidTerm = 1.0 * stoi(row[6].c_str());
			score.Other = 1.0 * stoi(row[7].c_str());
			if (strcmp(sv.ID, Mssv) == 0)
				break;
		}
	}
	f1.close();
	return score;
}

void viewScoreBoardOfStudent(SinhVien& S, const SchoolYear& Y)
{
	ListCourses l = ReadListCourses(Y);
	ListCourses list = courseOfStudent(l, S, Y);
	if (list.head == NULL)
		cout << "chua dang ki mon nao!" << endl;
	else
	{
		cout << setw(10) << left << "ID" << setw(50) << left << "Name of course";
		cout << setw(50) << left << "Teacher name" << setw(8) << left << "Credit";
		cout << setw(20) << "Score orther";
		cout << setw(10) << left << "Score middle" << setw(10) << left << "Score Final";
		cout << setw(10) << left << "Score total" << endl;
		NodeCourse* temp1 = list.head;
		while (temp1 != NULL)
		{
			DiemMonHoc score = ReadfileCSVScore(S, Y, temp1->course.ID);
			cout << setw(10) << left << temp1->course.ID << setw(50) << left << temp1->course.Name;
			cout << setw(50) << left << temp1->course.TeacherName << setw(8) << left << temp1->course.NumOfCredits;
			cout << setw(20) << score.Other;
			cout << setw(10) << left << score.MidTerm << setw(10) << left << score.Final << left << setw(10) << score.Total << endl;
			temp1 = temp1->next;
		}
	}
}