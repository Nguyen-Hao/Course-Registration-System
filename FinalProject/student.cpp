#include "student.h"
#include "Header.h"
#include "console.h"
#include "Semester.h"
#include "DKMon.h"
#include "course.h"
#include "staff.h"
#include "SchoolYear.h"
#include <algorithm>
#include "Menu.h"

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
int CheckClass(ListLop dsl, string a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (dsl.l[i].Ma==a)
			if (i == 0) return -1; 
			else return i;
	}
	return 0; 
}
void WriteFileStudent(ListLop& dsl,const SchoolYear&Y)
{
	ofstream file;
	file.open(Y.DSSinhVien, ios::out);
	ListSV* k;
	for (int i = 0; i < dsl.n; ++i)
	{
		for (k = dsl.l[i].pHead; k != NULL; k = k->pNext)
		{
			file << dsl.l[i].Ma << endl;
			file << k->info.ID << endl << k->info.pass << endl; 
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
	int KT;
	while (!file.eof())
	{
		SinhVien sv;
		getline(file, s);
		if (s.size() == 0) break;
		KT = CheckClass(dsl, s, dsl.n);
		if (KT == -1) STTLop = 0;
		else STTLop = KT;
		sv.Class = s;
		getline(file, s);	sv.ID = s;
		getline(file, s);	sv.pass = s;
		getline(file, s);	sv.FirstName = s;
		getline(file, s);	sv.LastName = s;
		getline(file, s);	sv.Gender = s;
		getline(file, s);	sv.DateOfBirth = s;
		getline(file, s);	sv.SocialID = s;
		for (int i = 0; i < 3; i++) file >> sv.begin[i];
		file >> sv.YearStudent;
		file >> sv.Semester;
		file.ignore();
		AddTailStudent(dsl.l[STTLop].pHead, sv);
	}
	file.close();
}

bool checkSameData(const SchoolYear& Y, const SinhVien& S)
{
	bool t = false;
	fstream file;
	file.open(S.Class + "_Filecsv.csv", ios::in | ios::out);
	if(file.is_open())
	{
		while (!file.eof())
		{
			string a;
			SinhVien sv;
			getline(file, a, ',');
			getline(file, sv.ID, ','); 
			getline(file, sv.FirstName, ','); 
			getline(file, sv.LastName, ','); 
			getline(file, sv.Gender, ',');
			getline(file, sv.DateOfBirth, ',');
			getline(file, sv.SocialID, '\n'); 
			if (sv.ID == S.ID)
				t = true;
		}
		file.close();
	}
	return t;
}

void UpdateData(const SchoolYear& Y)
{
	fstream file, file1;
	file.open(Y.DSSinhVien, ios::in | ios::out);
	file1.open("temp.txt", ios::out);
	if (file.is_open())
	{
		SinhVien sv;
		while (!file.eof())
		{
			getline(file, sv.Class);
			getline(file, sv.ID);
			getline(file, sv.pass);
			getline(file, sv.FirstName);
			getline(file, sv.LastName);
			getline(file, sv.Gender);
			getline(file, sv.DateOfBirth);
			getline(file, sv.SocialID);
			file >> sv.begin[0] >> sv.begin[1] >> sv.begin[2];
			file >> sv.YearStudent;
			file >> sv.Semester;
			file.ignore();
			if (checkSameData(Y, sv))
			{
				file1 << sv.Class << endl;
				file1 << sv.ID << endl;
				file1 << sv.pass << endl;
				file1 << sv.FirstName << endl;
				file1 << sv.LastName << endl;
				file1 << sv.Gender << endl;
				file1 << sv.DateOfBirth << endl;
				file1 << sv.SocialID << endl;
				file1 << sv.begin[0] << " " << sv.begin[1] << " " << sv.begin[2] << endl;
				file1 << sv.YearStudent << endl;
				file1 << sv.Semester << endl;
			}
		}
		
	}
	file.close();
	file1.close();
	remove(Y.DSSinhVien.c_str());
	rename("temp.txt", Y.DSSinhVien.c_str());
}

void ViewEnrollCourses(ListCourses l, SinhVien& S, int se, string&e, bool&f,  const SchoolYear& Y)
{
	f = true;
	if (l.head == NULL)
	{
		e =  "Chua co khoa hoc nao";
		f = false;
		return;
	}
	ListCourses list = courseOfStudent(l, S, se, Y);
	gotoxy(0, 32);
	int STT = 1;
	if (list.head == NULL) {
		e = "Chua dang ki mon nao";
		f = false;
		return;
	}
	else
	{
		system("cls");
		gotoxy(45, 2); TextColor(164); cout << "DANH SACH MON HOC DA DANG KY - KI " << se << " - NAM HOC " << Y.NameSchoolYear;
		TextColor(224);
		gotoxy(15, 3); cout << "+----------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		gotoxy(15, 4); cout << char(124) << setw(5) << " STT " << char(124) << "  " << setw(10) << left << "Ma mon hoc" << char(124) << "  " << setw(30) << left << "Ten mon hoc" << char(124) << "  " << setw(25) << left << "Ten GV" << char(124) << "  " << setw(8) << left << "So TC" << char(124) << "  " << setw(15) << "So sinh vien" << char(124) << "  " << setw(25) << left << "       Lich hoc";
		gotoxy(158, 4); cout << char(124) << endl;
		gotoxy(15, 5); cout << "+----------------------------------------------------------------------------------------------------------------------------------------------+" << endl;

		NodeCourse* temp1 = list.head;
		while (temp1 != NULL)
		{
			gotoxy(15, 5 + STT); cout << char(124) << setw(5) << STT << char(124) << "  " << setw(10) << left << temp1->course.ID << char(124) << "  " << setw(30) << left << temp1->course.Name << char(124) << "  " << setw(25) << left << temp1->course.TeacherName << char(124) << "  " << setw(8) << left << temp1->course.NumOfCredits << char(124) << "  " << setw(15) << temp1->course.MaxNumOfStudents << char(124) << "  ";
			cout << "T" << temp1->course.Session1.thu << " - S" << temp1->course.Session1.shift << TimeShift(temp1->course.Session1.shift) << "  " << "T" << temp1->course.Session2.thu << " - S" << temp1->course.Session2.shift << TimeShift(temp1->course.Session2.shift);
			gotoxy(158, 5 + STT++); cout << char(124) << endl;
			temp1 = temp1->next;
		}
		gotoxy(15, 5 + STT); cout << "+----------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		gotoxy(15, 5 + STT + 1);

	}
}
void EraserEnrollCourses(SinhVien& S, ListCourses l,string &eff, bool& flat, int se,  const SchoolYear& Y)
{
	Time t = getTime();
	Time* arrTime = ReadTimeRegistration(Y);
	char check = isTimeIn(t, arrTime[0], arrTime[1]);
	if (check != 0)
	{
		if (check == 1) {
			eff = "Da qua thoi gian xoa hoc phan";
			cout << "Thoi gian dang ky da het tu ";
			cout << arrTime[0].hour << ":";
			if (arrTime[0].minute < 10) cout << "0";
			cout << arrTime[0].minute << ":";
			if (arrTime[0].second < 10) cout << "0";
			cout << arrTime[0].second;
			cout << " ngay " << arrTime[1].day << "/" << arrTime[1].month << "/" << arrTime[1].year;
		}
		else if (check == -1) {
			eff = "Chua den thoi gian xoa hoc phan";
			cout << "Thoi gian dang ky hoc phan bat dau luc ";
			cout << arrTime[0].hour << ":";
			if (arrTime[0].minute < 10) cout << "0";
			cout << arrTime[0].minute << ":";
			if (arrTime[0].second < 10) cout << "0";
			cout << arrTime[0].second;
			cout << " ngay " << arrTime[0].day << "/" << arrTime[0].month << "/" << arrTime[0].year << " den ";
			cout << arrTime[1].hour << ":";
			if (arrTime[1].minute < 10) cout << "0";
			cout << arrTime[1].minute << ":";
			if (arrTime[1].second < 10) cout << "0";
			cout << arrTime[1].second;
			cout << " ngay " << arrTime[1].day << "/" << arrTime[1].month << "/" << arrTime[1].year;
		}
		flat = false;
		return;
	}
	bool k;
	string e;
	ViewEnrollCourses(l, S, se, e, k, Y);
	if (!k) {
		flat = false;
		eff = e;
	}
	else {
		char id[10];
		flat = true;
		int i;
		Frames(45, 32, 30, 1);
		gotoxy(45, 31);
		cout << "Nhap ma mon can huy dang ky: ";
		string ID;
		gotoxy(47, 33);
		getline(cin, ID);
		strcpy_s(id, ID.c_str());
		if (CheckCourses(l, id) == false)
		{
			eff = "Khong ton tai ma mon hoc nay";
			flat = false;
		}
		else
		{
			ListCourses temp = courseOfStudent(l, S, se, Y);
			if (CheckCourses(temp, id) == false) {
				eff = "Sinh vien khong co dang ky ma mon hoc nay";
				flat = false;
			}
			else
			{
				SinhVien s;
				fstream file, file1;
				file.open(to_string(se) + Y.StudentOfSubject, ios::in);
				file1.open("temp.txt", ios::out);
				char ch[10] = "\0", CH[10] = "\n";
				file.getline(ch, 10);
				while (!file.eof())
				{
					file1 << ch << endl;
					while (CheckCourses(l, CH) == false)
					{
						file.getline(CH, 10);
						if (CheckCourses(l, CH) == true || strcmp(CH, "\0") == 0) break;
						else
						{
							s.Class = CH;
							getline(file, s.ID);
							getline(file, s.pass);
							getline(file, s.FirstName);
							getline(file, s.LastName);
							getline(file, s.Gender);
							getline(file, s.DateOfBirth);
							getline(file, s.SocialID);
							for (i = 0; i < 3; ++i)
							{
								file >> s.begin[i];
							}
							file.ignore();
							file >> s.YearStudent;
							file.ignore();
							file >> s.Semester;
							file.ignore();
							if (s.ID == S.ID && strcmp(ch, id) == 0)
								continue;
							else
							{
								file1 << s.Class << endl;
								file1 << s.ID << endl;
								file1 << s.pass << endl;
								file1 << s.FirstName << endl;
								file1 << s.LastName << endl;
								file1 << s.Gender << endl;
								file1 << s.DateOfBirth << endl;
								file1 << s.SocialID << endl;
								file1 << s.begin[0] << " " << s.begin[1] << " " << s.begin[2] << endl;
								file1 << s.YearStudent << endl;
								file1 << s.Semester << endl;
							}

						}
					}
					strcpy_s(ch, 10, CH);
					strcpy_s(CH, 10, "\n");
				}
				file.close();
				file1.close();
				remove((to_string(se) + Y.StudentOfSubject).c_str());
				rename("temp.txt", (to_string(se) + Y.StudentOfSubject).c_str());
			}
		}
	}
}
void viewScoreBoardOfStudent(const SinhVien& S, ListCourses l, string&e, bool &f, int se, const SchoolYear& Y)
{
	ListCourses list = courseOfStudent(l, S, se, Y);
	if (list.head == NULL) {
		e = "Chua dang ki mon nao!";
		f = false;
	}
	else
	{
		system("cls");
		f = true;
		gotoxy(45, 2); TextColor(164); cout << "BANG DIEM CUA TUNG HOC PHAN - KI " << se << " - NAM HOC " << Y.NameSchoolYear;
		TextColor(224);
		gotoxy(15, 5); cout << "+----------------------------------------------------------------------------------------------------------------+" << endl;
		gotoxy(15, 6); cout << char(124) << setw(5)<<" STT" << char(124) << "   " << setw(7) << left << "Ma MH" << char(124) << "  " << setw(40) << left << " Ten mon hoc" <<  char(124) << "  " << setw(10) << "  So TC" << char(124) << setw(10) << "Qua trinh" << char(124) << setw(10) << " Giua ky " << char(124) << setw(8) << " Cuoi ki" << char(124) << setw(8) << "Tong ket" << char(124) << endl;
		gotoxy(15, 7); cout << "+----------------------------------------------------------------------------------------------------------------+" << endl;
		NodeCourse* temp1 = list.head;
		int t = 1;
		DiemMonHoc score;
		while (temp1 != NULL)
		{
			score = ReadfileCSVScore(S, Y, se, temp1->course.ID);
			gotoxy(15, 7 + t);
			cout << char(124) << setw(5) << t <<char(124)<<" " << setw(9) << left << temp1->course.ID << char(124) << "  " << setw(40) << left << temp1->course.Name <<  char(124) << "  " << setw(10) << temp1->course.NumOfCredits << char(124) << setw(10) << score.Other << char(124) << setw(10) << score.MidTerm << char(124) << setw(8) << score.Final << char(124) << setw(8) << score.Total << char(124) << endl;
			temp1 = temp1->next;
			++t;
		}
		gotoxy(15, 7 + t); cout << "+----------------------------------------------------------------------------------------------------------------+" << endl;
	}
}