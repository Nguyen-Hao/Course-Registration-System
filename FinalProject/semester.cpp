#include"Header.h"
#include"course.h"
#include "console.h"
#include "SchoolYear.h"
void init(listSemester& l)
{
	l.head = NULL;
	l.tail = NULL;
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
		file >> (ptr->semes).begin.ngay >> ptr->semes.begin.thang >> ptr->semes.begin.nam;
		file >> (ptr->semes).end.ngay >> ptr->semes.end.thang >> ptr->semes.end.nam;
		if (!file.eof())
		{
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
	}
	file.close();
}
int getSemester(listSemester l, const SchoolYear Y)
{
	int semester = 0;
	readListSemester(l, Y);
	Time time = getTime();
	Time begin, end;
	if (l.head == NULL) return 1;
	for (NodeSemester* p = l.head; p != NULL; p = p->next)
	{
		begin.day = p->semes.begin.ngay;
		begin.month = p->semes.begin.thang;
		begin.year = p->semes.begin.nam;
		end.day = p->semes.end.ngay;
		end.month = p->semes.end.thang;
		end.year = p->semes.end.nam;
		if (isTimeIn(time, begin, end))
		{
			return p->semes.name;
			break;
		}
	}
}

bool CreateSemester(semester& sesmes, const SchoolYear& Y)
{
	bool f = true;
	listSemester l;
	readListSemester(l, Y);
	if (l.tail == NULL)
	{
		l.tail = new NodeSemester;
		l.tail->semes.name = 0;
		int n=nam()-1;
		string s = to_string(n) + '-' + to_string(n + 1);
		strcpy_s(l.tail->semes.schoolyear, 11, s.c_str());
	}
	sesmes.name = l.tail->semes.name % 3 + 1;
	gotoxy(102, 9); cout << (l.tail->semes.name%3 + 1);
	if (l.tail->semes.name < 3) strcpy_s(sesmes.schoolyear,11,l.tail->semes.schoolyear);
	else
	{
		string s = "";
		for (int i = strlen(l.tail->semes.schoolyear); l.tail->semes.schoolyear[i]!='-'; i--)
		{
			s = l.tail->semes.schoolyear[i] + s;
		}
		int n = stoi(s, NULL, 10);
		s = to_string(n) + '-' + to_string(n + 1);
		strcpy_s(sesmes.schoolyear, 11, s.c_str());
	}
	gotoxy(102, 13); cout << sesmes.schoolyear;
	gotoxy(102, 17); cin >> sesmes.begin.ngay;
	gotoxy(115, 17); cin >> sesmes.begin.thang;
	gotoxy(126, 17); cin >> sesmes.begin.nam;

	gotoxy(102, 21); cin >> sesmes.end.ngay;
	gotoxy(115, 21); cin >> sesmes.end.thang;
	gotoxy(126, 21); cin >> sesmes.end.nam;
	TextColor(234);
	if (!isDate(sesmes.begin.ngay, sesmes.begin.thang, sesmes.begin.nam)) {
		TextColor(228);
		gotoxy(137, 17);
		cout << "Wrong";
		f = false;
	}
	else
	{
		TextColor(234);
		gotoxy(137, 17); cout << "Right";
	}
	if (!isDate(sesmes.end.ngay, sesmes.end.thang,sesmes.end.nam)) {
		TextColor(228); gotoxy(137, 21); cout << "Wrong";
		f = false;
	}
	else
	{
		TextColor(234);
		gotoxy(137, 21); cout << "Right";
	}
	if (f == false) return false;
	TextColor(228);
	ofstream file;
	file.open(Y.sesmester, ios::app);
	file << sesmes.name << endl;
	file << sesmes.schoolyear << endl;
	file << sesmes.begin.ngay << " " << sesmes.begin.thang << " " << sesmes.begin.nam << endl;
	file << sesmes.end.ngay << " " << sesmes.end.thang << " " << sesmes.end.nam << endl;
	sesmes.lis = ReadListCourses(Y);
	file.close();
	return true;
}