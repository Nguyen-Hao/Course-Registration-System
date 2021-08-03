#include"Header.h"
#include"course.h"
#include "console.h"
#include "SchoolYear.h"
void InitListSemester(listSemester& l)
{
	l.head = NULL;
	l.tail = NULL;
}

void readListSemester(listSemester& l, const SchoolYear&Y)
{
	InitListSemester(l);
	fstream file;
	file.open(Y.sesmester, ios::in);
	NodeSemester* ptr;
	while (!file.eof())
	{
		ptr = new NodeSemester;
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
		if (isTimeIn(time, begin, end)==0)
		{
			return p->semes.name;
			break;
		}
	}
	return 1;
}


bool CreateSemester(semester& sesmes, const SchoolYear& Y, listSemester&l)
{
	bool f = true;
	if (l.tail == NULL)
	{
		l.tail = new NodeSemester;
		l.tail->semes.name = 0;
		int n = YearPresent();
		string s = to_string(n) + '-' + to_string(n + 1);
		strcpy_s(l.tail->semes.schoolyear, 11, s.c_str());
	}
	sesmes.name = l.tail->semes.name + 1;
	if (sesmes.name > 3)
	{
		string c = "Da tao du 3 ky cua nam hoc " + string(l.tail->semes.schoolyear) + ". Ban can tao nam hoc moi truoc!";
		int x = 60, y = 25,i,csize=c.size()+3;
		TextColor(207);
		gotoxy(x, y); for (i = 0; i <= csize; ++i) cout << " ";
		gotoxy(x, y + 1); for (i = 0; i <= csize; ++i) cout << " ";
		gotoxy(x, y + 2); for (i = 0; i <= csize; ++i) cout << " ";
		gotoxy(x + 3, y + 1); cout << c;
		TextColor(224);
		return false;
	}
	gotoxy(102, 9); cout << (l.tail->semes.name % 3 + 1);
	strcpy_s(sesmes.schoolyear, 11, l.tail->semes.schoolyear);
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
	if (!isDate(sesmes.end.ngay, sesmes.end.thang, sesmes.end.nam)) {
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
	file.close();
	file.open(to_string(sesmes.name) + Y.ListCourses);
	file.close();
	file.open(to_string(sesmes.name) + Y.StudentOfSubject);
	file.close();
	file.open(to_string(sesmes.name) + Y.TimeDKHP);
	file.close();
	return true;
}