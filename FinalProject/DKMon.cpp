#include"Header.h"
#include"course.h"
#include"SchoolYear.h"
#include"console.h"
#include "Semester.h"
#include <string>

void Copy(NodeCourse*& p, NodeCourse* p1)
{
	p->course = p1->course;
	p->next = NULL;
}

void AddList(ListCourses& result, ListCourses l, char id[10])
{
	NodeCourse* temp = l.head,*ptr;
	while (temp != NULL)
	{
		if (temp->course.ID==id)
		{
			ptr = new NodeCourse;
			Copy(ptr, temp);
			ptr->next = NULL;
			if (result.head == NULL)
				result.head = ptr;
			else
			{
				ptr->next = result.head;
				result.head = ptr;
			}
		}
		temp = temp->next;
	}
}

bool CheckCourses(const ListCourses& l, string c)
{
	NodeCourse* temp = l.head;
	while (temp != NULL)
	{
		if (temp->course.ID==c)
			return true;
		temp = temp->next;
	}
	return false;
}
int countNodeCourses(const ListCourses& l)
{
	int i = 0;
	NodeCourse* ptr = l.head;
	while (ptr != NULL)
	{
		i++;
		ptr = ptr->next;
	}
	return i;
}
ListCourses courseOfStudent(const ListCourses& l, const SinhVien& sv, int se, const SchoolYear&Y)
{
	ListCourses result;
	initListCourses(result);
	fstream file;
	file.open(to_string(se)+Y.StudentOfSubject, ios::in);
	char ch[10] = "\0", CH[10] = "\n";
	file.getline(ch, 10);
	SinhVien s;
	int i;
	while (!file.eof())
	{
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
				for (i = 0; i < 3; i++)
				{
					file >> s.begin[i];
				}
				file.ignore();
				file >> s.YearStudent;
				file.ignore();
				file >> s.Semester;
				file.ignore();
				if (s.ID == sv.ID)
					AddList(result, l, ch);
			}
		}
		strcpy_s(ch, 10, CH);
		strcpy_s(CH, 10, "\n");
	}
	file.close();
	return result;
}
NodeCourse* FindCourses(const ListCourses& l, char id[10])
{
	NodeCourse* ptr = l.head;
	while (ptr != NULL)
	{
		if (ptr->course.ID==id)
			return ptr;
		ptr = ptr->next;
	}
	return NULL;
}
bool CheckSameTime(const ListCourses& l, NodeCourse* ptr)
{
	NodeCourse* temp = l.head;
	while (temp != NULL)
	{
		if (temp->course.Session1.thu == ptr->course.Session1.thu)
		{
			if (temp->course.Session1.shift == ptr->course.Session1.shift)
					return true;
		}
		else if (temp->course.Session2.thu == ptr->course.Session2.thu)
		{
			if (temp->course.Session2.shift == ptr->course.Session2.shift)
					return true;
		}
		temp = temp->next;
	}
	return false;
}
Time* ReadTimeRegistration(const SchoolYear& Y)
{
	Time* a = new Time[2];
	int se;
	ifstream ifs;
	ifs.open( Y.TimeDKHP);
	if (!ifs.is_open())
	{
		cout << "Chua co phien dang ky hoc phan!" << endl;
		return NULL;
	}
	else
	{ 
		while (!ifs.eof())
		{
			ifs >> se >> a[0].day >> a[0].month >> a[0].year >> a[0].hour >> a[0].minute >> a[0].second
				>> a[1].day >> a[1].month >> a[1].year >> a[1].hour >> a[1].minute >> a[1].second;
		}
	}
	return a;
}
void CoursesRegistration(ListCourses l, SinhVien S, int se, const SchoolYear&Y, string &c, bool &f)
{
	Time t = getTime();
	Time* arrTime = ReadTimeRegistration(Y);	
	char check = isTimeIn(t, arrTime[0], arrTime[1]);
	if (check != 0)
	{
		if (check == 1) cout << "Da qua";
		else if (check == -1) cout << "Chua den";
		cout << " thoi gian dang ky hoc phan!" << endl;
		cout << setfill(' ') << setw(70);
		cout << "Thoi gian dang ky hoc phan tu ";
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
		return;
	}
	ListCourses temp = courseOfStudent(l, S, se, Y);
	gotoxy(0, 32);
	f = true;	
	ViewListOfCourse(l, se, Y);
	if (countNodeCourses(temp) == 5) {
		c = "Da dang ki du 5 mon";
		f = false;
	}
	else
	{
		char id[10]="\0";
		cout << "nhap id mon can dang ki: ";
		string ID;
		getline(cin, ID);
		strcpy_s(id , ID.c_str());
		NodeCourse* ptr = FindCourses(l, id);
		if (CheckCourses(l, id) == false) {
			c = "Khong ton tai ma mon hoc";
			f = false;
		}
		else
		{
			if (CheckSameTime(temp, ptr) == true) {
				c = "Trung lich hoc";
				f = false;
			}
			else
			{
				SinhVien s;
				fstream file, file1;
				string link1=to_string(se) + Y.StudentOfSubject;
				file.open(link1, ios::in);
				file1.open("temp.txt", ios::out);
				char ch[10] = "\0", CH[10] = "\n";
				file.getline(ch, 10);
				while (!file.eof())
				{
					file1 << ch << endl;
					if (strcmp(ch, id) == 0)
					{
						file1 << S.Class << endl;
						file1 << S.ID << endl;
						file1 << S.pass << endl;
						file1 << S.FirstName << endl;
						file1 << S.LastName << endl;
						file1 << S.Gender << endl;
						file1 << S.DateOfBirth << endl;
						file1 << S.SocialID << endl;
						file1 << S.begin[0] << " " << S.begin[1] << " " << S.begin[2] << endl;
						file1 << S.YearStudent << endl;
						file1 << S.Semester << endl;
					}
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
							for (int i = 0; i < 3; i++)
							{
								file >> s.begin[i];
							}
							file.ignore();
							file >> s.YearStudent;
							file.ignore();
							file >> s.Semester;
							file.ignore();
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
					strcpy_s(ch, 10, CH);
					strcpy_s(CH, 10, "\n");
				}
				file.close();
				file1.close();
				remove(link1.c_str());
				rename("temp.txt", link1.c_str());
				c = "Dang ki thanh cong";
			}
		}
	}
}

int daDangKy(Course a, const SchoolYear Y, int se, ListCourses l)
{
	int count = 0;
	ifstream file;
	file.open(to_string(se) + Y.StudentOfSubject);
	string s;
	bool check = false;
	while (!check)
	{
		getline(file, s);
		check = CheckCourses(l, s) && s == a.ID;
	}
	getline(file, s);
	int i,x;
	while (true)
	{
		getline(file, s);
		getline(file, s);
		getline(file, s);
		getline(file, s);
		getline(file, s);
		getline(file, s);
		getline(file, s);
		for (i = 0; i < 3; i++)
		{
			file >> x;
		}
		file.ignore();
		file >> x;
		file.ignore();
		file >> x;
		file.ignore();
		++count;
		getline(file, s);
		if (CheckCourses(l, s) || s == "" || file.eof()) break;
	}
	file.close();
	return count;
}