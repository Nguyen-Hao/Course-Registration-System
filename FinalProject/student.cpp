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
int CheckClass(ListLop dsl, string a, int n)
{
	for (int i = 0; i < n; i++)
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
	for (int i = 0; i < dsl.n; i++)
	{
		for (ListSV* k = dsl.l[i].pHead; k != NULL; k = k->pNext)
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
		AddTailStudent(dsl.l[STTLop].pHead, sv);
	}
	file.close();
}
void viewScoreBoardOfStudent(SinhVien& S, ListCourses l, int se, const SchoolYear& Y)
{
	ListCourses list = courseOfStudent(l, S, se, Y);
	if (list.head == NULL)
		cout << "chua dang ki mon nao!" << endl;
	else
	{
		gotoxy(5, 5); cout << "+---------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		gotoxy(5, 6); cout << char(124) << "   " << setw(7) << left << "ID" << char(124) << "  " << setw(40) << left << "     Name of course" << char(124) << "  " << setw(40) << left << "         Teacher name" << char(124) << "  " << setw(10) << "  Credit" << char(124) << setw(8) << "  Other" << char(124) << setw(10) << " MidTerm " << char(124) << setw(8) << "  Final" << char(124) << setw(8) << " Total" << char(124) << endl;
		gotoxy(5, 7); cout << "+---------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		NodeCourse* temp1 = list.head;
		int t = 1;
		while (temp1 != NULL)
		{
			DiemMonHoc score = ReadfileCSVScore(S, Y, se, temp1->course.ID);
			gotoxy(5, 7 + t);
			cout << char(124)<<" " << setw(9) << left << temp1->course.ID << char(124) << "  " << setw(40) << left << temp1->course.Name << char(124) << "  " << setw(40) << left << temp1->course.TeacherName << char(124) << "  " << setw(10) << temp1->course.NumOfCredits << char(124) << setw(8) << score.Other << char(124) << setw(10) << score.MidTerm << char(124) << setw(8) << score.Final << char(124) << setw(8) << score.Total << char(124) << endl;
			temp1 = temp1->next;
			t++;
		}
		gotoxy(5, 7 + t); cout << "+---------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
	}
}