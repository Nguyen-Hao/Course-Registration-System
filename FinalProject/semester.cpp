#include"Header.h"
#include"course.h"
#include "console.h"
void init(listSemester& l)
{
	l.head = NULL;
	l.tail = NULL;
}
bool CreateSemester(semester& sesmes, const SchoolYear&Y)
{
	bool f = true;
	gotoxy(102, 9); cin >> sesmes.name; 
	cin.ignore();
	gotoxy(102, 13); cin.get(sesmes.schoolyear, 10, '\n');
	cin.ignore();
	gotoxy(102, 17); cin >> sesmes.studentYear;
	gotoxy(102, 21); cin >> sesmes.begin.ngay;
	gotoxy(115, 21); cin >> sesmes.begin.thang;
	gotoxy(126, 21); cin >> sesmes.begin.nam;
	
	gotoxy(102, 25); cin >> sesmes.end.ngay;
	gotoxy(115, 25); cin >> sesmes.end.thang;
	gotoxy(126, 25); cin >> sesmes.end.nam;
	TextColor(234);
	gotoxy(112, 13); cout << "Right";
	if (sesmes.studentYear < 1 || sesmes.studentYear >= 7) {
		TextColor(228);
		gotoxy(112, 17); cout << "Wrong";
		f = false;
	}
	else 
	{
		TextColor(234);
		gotoxy(112, 17); cout << "Right";
	}
	if (sesmes.begin.ngay < 1 || sesmes.begin.ngay > 31 || sesmes.begin.thang < 1 || sesmes.begin.thang > 12 ) {
		TextColor(228);
		gotoxy(137, 21); 
		cout << "Wrong";
		f = false;
	}
	else
	{
		TextColor(234);
		gotoxy(137, 21); cout << "Right";
	}
	if (sesmes.name < 1 || sesmes.name > 3)
	{
		TextColor(228);
		gotoxy(112, 9); cout << "Wrong";
		f = false;
	}
	else
	{
		TextColor(234);
		gotoxy(112, 9); cout << "Right";
	}
	if (sesmes.end.ngay < 1 || sesmes.end.ngay > 31 || sesmes.end.thang < 1 || sesmes.end.thang > 12) {
		TextColor(228); gotoxy(137, 25); cout << "Wrong";
		f = false;
	}
	else
	{
		TextColor(234);
		gotoxy(137, 25); cout << "Right";
	}
	if (f == false) return false;
	TextColor(228);
	ofstream file;
	file.open(Y.sesmester, ios_base::app);
	file << sesmes.name << endl;
	file << sesmes.schoolyear << endl;
	file << sesmes.begin.ngay << " " << sesmes.begin.thang << " " << sesmes.begin.nam << endl;
	file << sesmes.end.ngay << " " << sesmes.end.thang << " " << sesmes.end.nam << endl;
	sesmes.lis = ReadListCourses(Y);
	file.close();
	return true;
}

void readListSemester(listSemester& l, const SchoolYear&Y)
{
	init(l);
	fstream file;
	file.open(Y.sesmester, ios::in);
	while (!file.eof())
	{
		NodeSemester* ptr = new NodeSemester;
		ptr->next = NULL;
		file >> ptr->semes.name;
		file.ignore();
		file.getline(ptr->semes.schoolyear, 11);
		file >> ptr->semes.studentYear;
		file.ignore();
		file >> (ptr->semes).begin.ngay >> ptr->semes.begin.thang >> ptr->semes.begin.nam;
		file.ignore();
		file >> (ptr->semes).end.ngay >> ptr->semes.end.thang >> ptr->semes.end.nam;
		file.ignore();
		if (l.head == NULL)
		{
			l.head = ptr;
			l.tail = ptr;
		}
		else
		{
			l.tail->next = ptr;
			l.tail = ptr;
		}
	}
	file.close();
}