#include"Header.h"
#include"course.h"
void CreateSemester(semester& sesmes)
{
	cout << "input nam of semester: (1,2 or 3)";
	cin >> sesmes.name;
	cin.ignore();
	cout << "choose year for semester: ";
	cin.get(sesmes.schoolyear, 10, '\n');
	cin.ignore();
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