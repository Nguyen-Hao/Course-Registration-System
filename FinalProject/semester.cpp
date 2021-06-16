#include"Header.h"
#include"course.h"
void init(listSemester& l)
{
	l.head = NULL;
	l.tail = NULL;
}
void CreateSemester(semester& sesmes)
{
	cout << "input nam of semester: (1,2 or 3)";
	cin >> sesmes.name;
	cin.ignore();
	cout << "choose year for semester: ";
	cin.get(sesmes.schoolyear, 10, '\n');
	cin.ignore();
	cout << "what year student? ";
	cin >> sesmes.studentYear;
	cout << "day/month/year begin:";
	cin >> sesmes.begin.ngay >> sesmes.begin.thang >> sesmes.begin.nam;
	cout << "day/month/year end:";
	cin >> sesmes.end.ngay >> sesmes.end.thang >> sesmes.end.nam;
	ofstream file;
	file.open("sesmester.txt");
	file << sesmes.name << endl;
	file << sesmes.schoolyear << endl;
	file << sesmes.begin.ngay << " " << sesmes.begin.thang << " " << sesmes.begin.nam << endl;
	file << sesmes.end.ngay << " " << sesmes.end.thang << " " << sesmes.end.nam << endl;
	sesmes.lis = ReadListCourses(sesmes.name);
}

void readListSemester(listSemester& l)
{
	init(l);
	fstream file;
	file.open("semester.txt", ios::in);
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
}