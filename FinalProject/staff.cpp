#include "staff.h"
#include "Header.h"
#include "student.h"
#include "console.h"
#include "student.h"
#include "course.h"
#include "Semester.h"
#include "DKMon.h"
#include "SchoolYear.h"

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
void CreateNewClass(ListLop& ds,const SchoolYear&Y)
{
	ofstream f;
	f.open(Y.DSLop, ios::app);
	Lop c;
	cout << "Nhap ma lop: "; getline(cin, c.Ma);
	f << c.Ma << endl;
	cout << "Nhap ten lop: "; getline(cin, c.Ten);
	f << c.Ten << endl;
	cout << "Nhap nien khoa: "; getline(cin, c.NienKhoa);
	f << c.NienKhoa << endl;
	c.pHead = NULL;
	ds.l[ds.n] = c;
	ds.n++;
	f.close();
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
		gotoxy(70, 9);
		cout << "Ngay nhap hoc: (dd mm yyyy)"; for (int i = 0; i < 3; i++) cin >> sv.begin[i];
		gotoxy(70, 10);
		cout << "Nhap ID sinh vien: "; getline(cin, sv.ID);
		gotoxy(70, 11);
		cout << "Nhap ho: "; getline(cin, sv.FirstName);
		gotoxy(70, 12);
		cout << "Nhap ten: "; getline(cin, sv.LastName);
		gotoxy(70, 13);
		cout << "Nhap gioi tinh: "; getline(cin, sv.Gender);
		gotoxy(70, 14);
		cout << "Nhap ngay sinh (dd/mm/yyyy): "; getline(cin, sv.DateOfBirth);
		gotoxy(70, 15);
		cout << "Nhap Social ID: "; getline(cin, sv.SocialID);
		if (KT == -1)
			STTLop = 0;
		else STTLop = KT;
		sv.YearStudent = 1;
		sv.Semester = 1;
		sv.pass = Pass;
		AddTailStudent(dsl.l[STTLop].pHead, sv);
	}
	else
	{
		cout << "Khong tim thay lop " << c << endl;
		cout << "Vui long nhap lai..." << endl;
	}
}
void ReadFileDSGV(ListGV& dsgv, const SchoolYear& Y)
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
		if (strlen(gv.ID) == 0) break;
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
void writeFileTeacher(ListGV dsgv, const SchoolYear& Y)
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

int Checkcourses(ListCourses dsl, char a[10])
{
	NodeCourse* p = dsl.head;
	int i = 0;
	for (p; p != NULL; p = p->next)
	{
		if (p->course.ID==a)
			if (i == 0) return -1; 
			else return i;
		i++;
	}
	return 0; 
}
void UpdateCSV(ListLop& ds, const SchoolYear& Y)
{
	ofstream file;
	file.open(Y.DSSinhVien, ios_base::app);
	for (int i = 0;i < ds.n; i++) {
		ifstream f1;
		f1.open(string(ds.l[i].Ma) + "_" + Y.Filecsv, ios::in | ios::out);
		string line = "", word;
		getline(f1, line);
		int ViTriLop = 0;
		while (f1.is_open())
		{
			getline(f1, line);
			if (line.size() == 0) break;
			stringstream s(line);
			vector<string> row;
			while (getline(s, word, ','))
			{
				row.push_back(word);
			}
			SinhVien sv;
			sv.Class= ds.l[i].Ma;
			sv.ID= row[1];
			sv.FirstName = row[2];
			sv.LastName = row[3];
			sv.Gender = row[4];
			sv.DateOfBirth = row[5];
			sv.SocialID = row[6];
			char Pass[10] = "123456";
			sv.pass = Pass;
			sv.Semester = 1;
			sv.YearStudent = 1;
			sv.begin[0] = 5; sv.begin[1] = 10; sv.begin[2] = 2020; // gan co dinh
			bool flat = true;
			for (ListSV* k = ds.l[i].pHead; k != NULL; k = k->pNext)
				if (k->info.ID == sv.ID && k->info.FirstName == sv.FirstName && k->info.LastName == sv.LastName && k->info.SocialID == sv.SocialID && k->info.ID == sv.ID && k->info.Gender == sv.Gender)
					flat = false;
			if (flat == true) AddTailStudent(ds.l[i].pHead, sv);
		}
		f1.close();
	}
	file.close();
	WriteFileStudent(ds, Y);
}

void UpdateStudent(const SchoolYear& Y)
{
	Time temp = getTime();
	fstream file, file1;
	file.open(Y.DSSinhVien, ios::in);
	file1.open("list.txt", ios::out);
	while (!file.eof())
	{
		SinhVien temp1;
		getline(file,temp1.Class);
		getline(file, temp1.ID);
		getline(file, temp1.pass);
		getline(file, temp1.FirstName);
		getline(file, temp1.LastName);
		getline(file, temp1.Gender);
		getline(file, temp1.DateOfBirth);
		getline(file, temp1.SocialID);
		for (int i = 0; i < 3; i++)
			file >> temp1.begin[i];
		file.get();
		file >> temp1.YearStudent;
		file.get();
		file >> temp1.Semester;
		file.get();
		if (temp1.Class=="") break;
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
ListSV* findStudentOfCourses(const ListCourses& l, string mamon, const SchoolYear& Y)
{
	ListSV* lsv = NULL;
	fstream file;
	listSemester li;
	InitListSemester(li);
	int se = getSemester(li, Y);
	file.open(to_string(se) + Y.StudentOfSubject, ios::in);
	string s;
	while (getline(file, s))
	{
		if (s==mamon)
		{
			getline(file, s);
			while (true)
			{
				SinhVien sv;
				sv.Class=s;
				getline(file, s);	sv.ID=s;
				getline(file, s);	sv.pass = s;
				getline(file, s);	sv.FirstName = s;
				getline(file, s);	sv.LastName = s;
				getline(file, s);	sv.Gender = s;
				getline(file, s);	sv.DateOfBirth = s;
				getline(file, s);	sv.SocialID = s;
				for (int i = 0; i < 3; i++) file >> sv.begin[i];
				file >> sv.YearStudent;
				file >> sv.Semester;
				AddTailStudent(lsv, sv);
				file.ignore();
				getline(file, s);
				if (CheckCourses(l, s) == true || s.size() == 0) break;
			}
			break;
		}
	}
	file.close();
	return lsv;
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
	gotoxy(20, 26);
	cout << "Nhap ma lop: ";
	int ViTriLop;
	string Malop;
	int STT = 1;
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
	system("cls");
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
void ViewListOfStudentIncourses(const SchoolYear& Y)
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
	ListSV* Lsv_Of_Courses = findStudentOfCourses(ds, Mamon, Y);
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

void ExportListStudentInCourseToEnterScore(ListCourses dsm, const SchoolYear& Y)
{
	cin.ignore();
	ListCourses ds = ReadListCourses(Y);
	ViewListOfCourse(Y);
	for (NodeCourse* p = dsm.head; p != NULL; p = p->next) {
		ListSV* Lsv_Of_Courses = findStudentOfCourses(ds, p->course.ID, Y);
		ListSV* k = Lsv_Of_Courses;
		if (Lsv_Of_Courses != NULL) {
			int count = 0;
			DiemMonHoc a;
			a.Final = a.MidTerm = a.Other = a.Total = 0.0;
			string mamon = p->course.ID;
			int t = YearPresent();
			listSemester l;
			InitListSemester(l);
			int se = getSemester(l, Y);
			string link = "ScoreBoard" + to_string(t) + "_" + to_string(t + 1) + "_" + to_string(se) + "_" + mamon + ".csv";
			ifstream fileCheck(link);
			if (!fileCheck.is_open()) {
				ofstream file(link);
				file << "STT,ID,First Name,Last Name,Total Mark, Final Mark, Midterm Mark, Other Mark" << endl;
				for (k; k != NULL; k = k->pNext)
				{
					count++;
					file << count << "," << k->info.ID << "," << k->info.FirstName << ","
						<< k->info.LastName << "," << a.Total << "," << a.Final << "," << a.MidTerm << "," << a.Other << endl;
				}
				file.close();
			}
			fileCheck.close();
		}
	}
}

void ViewScoreBoardOfACourse(ListCourses dsmon, const SchoolYear& Y)
{
	int t = YearPresent();
	string s, word, mamon;
	cout << "Nhap ma mon: "; 
	getline(cin, mamon);
	int STT = 1;
	listSemester l;
	InitListSemester(l);
	int se = getSemester(l, Y);
	string link = "ScoreBoard" + to_string(t) + "_" + to_string(t + 1) + "_" + to_string(se) + "_" + mamon + ".csv";
	ifstream fin(link);
	if (!fin.is_open())
	{
		cout << "Khong ton tai ma mon " << mamon << endl;
		return;
	}
	else
	{
		NodeCourse* k = dsmon.head;
		for (k; k != NULL;k = k->next)
		{
			if (k->course.ID==mamon)
				break;
		}
		system("cls");
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
void updateAStudentResult(const SchoolYear& Y)
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
	ListSV* Lsv_Of_Courses = findStudentOfCourses(ds, Mamon, Y);
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
	for (ListSV* i = k; i != NULL; i = i->pNext)
	{
		if (i->info.ID== ID)
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
	int t = YearPresent();
	listSemester l;
	InitListSemester(l);
	int se = getSemester(l, Y);
	string link = "ScoreBoard" + to_string(t - 1) + "_" + to_string(t) + "_" + to_string(se) + "_" + mamon + ".csv";
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
		getline(file, k->info.ID, ',');				file.get();
		getline(file, k->info.FirstName, ',');		file.get();
		getline(file, k->info.LastName, ',');		file.get();
		file >> a.Total;
		file.ignore();
		file >> a.Final;
		file.ignore();
		file >> a.MidTerm;
		file.ignore();
		file >> a.Other;
		if (k->info.ID== ID)
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
	rename("tam.csv", link.c_str());
}
void ViewScoreOfAClass(ListLop dsl, ListCourses dsm, const SchoolYear& Y)
{
	listSemester l;
	InitListSemester(l);
	int se = getSemester(l, Y);
	int t = YearPresent();
	string malop;
	cout << "Nhap ma lop: "; getline(cin, malop);
	system("cls");
	ListCourses ds = ReadListCourses(Y);
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

	gotoxy(35, 3); cout << "\t\t---------------------------- " << malop << " ----------------------------";
	gotoxy(20, 4); cout << "+-----------------------------------------------------------------------------------------------------------------+" << endl;
	gotoxy(20, 5); cout << char(124) << "  " << setw(5) << left << "STT" << char(124) << "  " << setw(15) << left << "     MSSV" << char(124) << "  " << setw(20) << left << "         Ho" << char(124) << "  " << setw(20) << "   Ten" << char(124) << setw(30) << "          Mon hoc" << char(124) << setw(10) << "   Diem" << char(124) << endl;
	gotoxy(20, 6); cout << "+-----------------------------------------------------------------------------------------------------------------+" << endl;
	int STT = 1, n = 0;
	for (ListSV* k = dsl.l[VitriLop].pHead; k != NULL; k = k->pNext)
	{
		double TotalMark = 0;
		int SoChi = 0;
		bool flat = false;
		for (NodeCourse* p = dsm.head; p!= NULL; p = p->next)
		{
			ListSV* psv = findStudentOfCourses(dsm, p->course.ID, Y);
			for (psv; psv != NULL; psv = psv->pNext)
			{
				if (psv->info.ID==k->info.ID)
				{
					string link = "ScoreBoard" + to_string(t) + "_" + to_string(t + 1) + "_" + to_string(se) + "_" + string(p->course.ID) + ".csv";
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
							if (row[1]==k->info.ID)
							{
								SoChi += p->course.NumOfCredits;
								TotalMark += stoi(row[4]) * p->course.NumOfCredits;
								flat = true;
								gotoxy(20, 7 + n);
								cout << char(124) << "  " << setw(5) << left << STT++ << char(124) << "  " << setw(15) << left << row[1] << char(124) << "  " << setw(20) << left << row[2] << char(124) << "  " << setw(20) << row[3] << char(124) << setw(30) << p->course.Name << char(124) << setw(10) << row[4] << char(124) << endl;
								gotoxy(20, 7 + ++n + 1);
							}
						}
					}
					f.close();
				}
			}
		}
		if (flat == true) {

			TextColor(225);
			gotoxy(20, 7 + n++);
			cout << char(124) << "  " << setw(5) << left << "" << char(124) << "  " << setw(15) << left << k->info.ID << char(124) << "  " << setw(20) << left << k->info.FirstName << char(124) << "  " << setw(20) << k->info.LastName << char(124) << setw(30) << "GPA ki" << char(124) << setw(10) << (TotalMark / SoChi) * 1.0 << char(124) << endl;
		}
		else {
			gotoxy(20, 7 + n++);
			cout << char(124) << "  " << setw(5) << left << "" << char(124) << "  " << setw(15) << left << k->info.ID << char(124) << "  " << setw(20) << left << k->info.FirstName << char(124) << "  " << setw(20) << k->info.LastName << char(124) << setw(30) << "GPA ki" << char(124) << setw(10) << 0.0 << char(124) << endl;
			TextColor(224);
		}
		TextColor(224);
		gotoxy(20, 7 + n); cout << "+-----------------------------------------------------------------------------------------------------------------+" << endl;
		n++;
	}
}
DiemMonHoc ReadfileCSVScore(SinhVien S, const SchoolYear& Y, string mamon)
{
	int t = YearPresent();
	ifstream f1;
	listSemester l;
	InitListSemester(l);
	int se = getSemester(l, Y);
	string link = "ScoreBoard" + to_string(t - 1) + "_" + to_string(t) + "_" + to_string(se) + "_" + mamon + ".csv";
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

			string Mssv;
			Mssv=S.ID;
			getline(f1, line);
			if (line.size() == 0) break;
			stringstream s(line);
			vector<string> row;
			while (getline(s, word, ','))
			{
				row.push_back(word);
			}
			SinhVien sv;
			sv.ID=row[1];
			sv.FirstName=row[2];
			sv.LastName=row[3];
			score.Total = 1.0 * stoi(row[4].c_str());
			score.Final = 1.0 * stoi(row[5].c_str());
			score.MidTerm = 1.0 * stoi(row[6].c_str());
			score.Other = 1.0 * stoi(row[7].c_str());
			if (sv.ID==Mssv)
				break;
		}
	}
	f1.close();
	return score;
}