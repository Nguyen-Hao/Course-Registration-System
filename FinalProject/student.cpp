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
void viewScoreBoardOfStudent(SinhVien& S, const SchoolYear& Y)
{
	listSemester ls;
	InitListSemester(ls);
	int se = getSemester(ls, Y);
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
void PrintFileCSV(ListLop dsl, SchoolYear Y)
{
	for(int i=0;i< dsl.n; i++)
	{
		string nameFile = string(dsl.l[i].Ma) + "_" + Y.Filecsv ;
		ifstream fin(nameFile);
		if (!fin.is_open())
		{
			ofstream file;
			file.open(nameFile);
			file << "STT, ID, FirstName, LastName,Gender,DOB,SocialID";
			file.close();
		}
	}
}