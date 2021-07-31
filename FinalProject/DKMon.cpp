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
	NodeCourse* temp = l.head;
	while (temp != NULL)
	{
		if (strcmp(temp->course.ID, id) == 0)
		{
			NodeCourse* ptr = new NodeCourse;
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
		if (strcmp(temp->course.ID, c.c_str()) == 0)
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
ListCourses courseOfStudent(const ListCourses& l, const SinhVien& sv,const SchoolYear&Y)
{
	ListCourses result;
	initListCourses(result);
	fstream file;
	listSemester li;
	InitListSemester(li);
	int se = getSemester(li, Y);
	file.open(to_string(se)+Y.StudentOfSubject, ios::in);
	char ch[10] = "\0", CH[10] = "\n";
	file.getline(ch, 10);
	while (!file.eof())
	{
		while (CheckCourses(l, CH) == false)
		{
			file.getline(CH, 10);
			if (CheckCourses(l, CH) == true || strcmp(CH, "\0") == 0) break;
			else
			{
				SinhVien s;
				strcpy_s(s.Class, 10, CH);
				file.getline(s.ID, 10);
				file.getline(s.pass, 20);
				file.getline(s.FirstName, 50);
				file.getline(s.LastName, 50);
				file.getline(s.Gender, 10);
				file.getline(s.DateOfBirth, 50);
				file.getline(s.SocialID, 10);
				for (int i = 0; i < 3; i++)
				{
					file >> s.begin[i];
				}
				file.ignore();
				file >> s.YearStudent;
				file.ignore();
				file >> s.Semester;
				file.ignore();
				if (strcmp(s.ID, sv.ID) == 0)
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
		if (strcmp(ptr->course.ID, id) == 0)
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
			if (temp->course.Session1.gio == ptr->course.Session1.gio)
				if (temp->course.Session1.phut == ptr->course.Session1.phut)
					return true;
		}
		else if (temp->course.Session1.thu == ptr->course.Session1.thu)
		{
			if (temp->course.Session1.gio == ptr->course.Session1.gio)
				if (temp->course.Session1.phut == ptr->course.Session1.phut)
					return true;
		}
		temp = temp->next;
	}
	return false;
}
void CoursesRegistration(ListCourses& l, SinhVien& S,const SchoolYear&Y, string &c, bool &f)
{
	Time t = getTime();
	ifstream ifs;
	listSemester li;
	InitListSemester(li);
	int se = getSemester(li, Y);
	ifs.open(to_string(se) + Y.TimeDKHP);
	Time begin, end;
	if (!ifs.is_open())
	{
		cout << "Chua co phien dang ky hoc phan!" << endl;
		return;
	}
	else
	{
		ifs >> begin.day >> begin.month >> begin.year >>begin.hour>>begin.minute>>begin.second
			>>end.day >> end.month >> end.year>>end.hour>>end.minute>>end.second;
		char check = isTimeIn(t, begin, end);
		if (check!=0)
		{
			if (check == 1) cout << "Da qua";
			else if (check == -1) cout << "Chua den";
			cout << " thoi gian dang ky hoc phan!" << endl;
			cout << "Thoi gian dang ky hoc phan tu ";
			cout << begin.hour << ":";
			if (begin.minute < 10) cout << "0";
			cout << begin.minute << ":";
			if (begin.second < 10) cout << "0";
			cout<< begin.second;
			cout << " ngay " << begin.day << "/" << begin.month << "/" << begin.year << " den ";
			cout << end.hour << ":";
			if (end.minute < 10) cout << "0";
			cout << end.minute << ":";
			if (end.second < 10) cout << "0";
			cout<< end.second;
			cout << " ngay " << end.day << "/" << end.month << "/" << end.year;
			return;
		}
	}
	ifs.close();
	l = ReadListCourses(Y);
	if (l.head == NULL)
	{
		cout << "Chua co khoa hoc nao!" << endl;
		return;
	}
	ListCourses temp = courseOfStudent(l, S,Y);
	gotoxy(0, 32);
	f = true;	
	ViewListOfCourse(Y);
	if (countNodeCourses(temp) == 5) {
		c = "Da dang ki du 5 mon";
		f = false;
	}
	else
	{
		char id[10];
		cout << "nhap id mon can dang ki: ";
		cin.get(id, 10, '\n');
		cin.ignore();
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
				fstream file, file1;
				file.open(to_string(se)+Y.StudentOfSubject, ios::in);
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
							SinhVien s;
							strcpy_s(s.Class, 10, CH);
							file.getline(s.ID, 10);
							file.getline(s.pass, 20);
							file.getline(s.FirstName, 50);
							file.getline(s.LastName, 50);
							file.getline(s.Gender, 10);
							file.getline(s.DateOfBirth, 50);
							file.getline(s.SocialID, 10);
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
				remove((to_string(se)+Y.StudentOfSubject).c_str());
				rename("temp.txt", (to_string(se)+Y.StudentOfSubject).c_str());
				c = "Dang ki thanh cong";
			}
			
		}
	}
}
void ViewEnrollCourses(SinhVien& S, const SchoolYear&Y)
{
	system("cls");
	ListCourses l = ReadListCourses(Y);
	if (l.head == NULL)
	{
		cout << "Chua dang ky mon nao!";
		return;
	}
	ListCourses list = courseOfStudent(l, S,Y);
	gotoxy(0, 32);
	int STT = 0;
	if (list.head == NULL)
		cout << "chua dang ki mon nao!" << endl;
	else
	{
		gotoxy(20, 3); cout << "+--------------------------------------------------------------------------------------------------------------------------------+" << endl;
		gotoxy(20, 4); cout << char(124) << "  " << setw(10) << left << "Ma mon hoc" << char(124) << "  " << setw(30) << left << "Ten mon hoc" << char(124) << "  " << setw(25) << left << "Ten GV" << char(124) << "  " << setw(8) << left << "So TC" << char(124) << "  " << setw(15) << "So sinh vien" << char(124) << "  " << setw(20) << left << "       Lich hoc";
		gotoxy(149, 4); cout << char(124) << endl;
		gotoxy(20, 5); cout << "+--------------------------------------------------------------------------------------------------------------------------------+" << endl;

		NodeCourse* temp1 = list.head;
		while (temp1 != NULL)
		{
			gotoxy(20, 6 + STT); cout << char(124) << "  " << setw(10) << left << temp1->course.ID << char(124) << "  " << setw(30) << left << temp1->course.Name << char(124) << "  " << setw(25) << left << temp1->course.TeacherName << char(124) << "  " << setw(8) << left << temp1->course.NumOfCredits << char(124) << "  " << setw(15) << temp1->course.MaxNumOfStudents << char(124) << "  ";
			cout << "T" << temp1->course.Session1.thu << " - " << temp1->course.Session1.gio << ":" << temp1->course.Session1.phut << "  " << "T" << temp1->course.Session2.thu << " - " << temp1->course.Session2.gio << ":" << temp1->course.Session2.phut;
			gotoxy(149, 6 + STT++); cout << char(124) << endl;
			temp1 = temp1->next;
		}
		gotoxy(20, 6 + STT); cout << "+--------------------------------------------------------------------------------------------------------------------------------+" << endl;
		gotoxy(15, 6 + STT + 1);

	}
}
void EraserEnrollCourses(SinhVien& S,const SchoolYear&Y, bool &f)
{
	Time t = getTime();
	ifstream ifs;
	listSemester li;
	InitListSemester(li);
	int se = getSemester(li, Y);
	ifs.open(to_string(se) + Y.TimeDKHP);
	Time begin, end;
	if (!ifs.is_open())
	{
		cout << "Chua co phien dang ky hoc phan!" << endl;
		return;
	}
	else
	{
		ifs >> begin.day >> begin.month >> begin.year >> begin.hour >> begin.minute >> begin.second
			>> end.day >> end.month >> end.year >> end.hour >> end.minute >> end.second;
		char check = isTimeIn(t, begin, end);
		if (check != 0)
		{
			if (check == 1) cout << "Da qua";
			else if (check == -1) cout << "Chua den";
			cout << " thoi gian dang ky hoc phan!" << endl;
			cout << "Thoi gian dang ky hoc phan tu ";
			cout << begin.hour << ":";
			if (begin.minute < 10) cout << "0";
			cout << begin.minute << ":";
			if (begin.second < 10) cout << "0";
			cout << begin.second;
			cout << " ngay " << begin.day << "/" << begin.month << "/" << begin.year << " den ";
			cout << end.hour << ":";
			if (end.minute < 10) cout << "0";
			cout << end.minute << ":";
			if (end.second < 10) cout << "0";
			cout << end.second;
			cout << " ngay " << end.day << "/" << end.month << "/" << end.year;
			return;
		}
	}
	ifs.close();
	ViewEnrollCourses(S, Y);
	char id[10];
	f = true;
	cout << "nhap id mon can huy dang ki: ";
	cin.get(id, 10, '\n');
	cin.ignore();
	ListCourses l = ReadListCourses(Y);
	if (CheckCourses(l, id) == false)
	{
		f = false;
	}
	else
	{
		ListCourses temp = courseOfStudent(l, S,Y);
		if (CheckCourses(temp, id) == false)
			f = false;
		else
		{
			fstream file, file1;
			listSemester li;
			InitListSemester(li);
			int se = getSemester(li, Y);
			file.open(to_string(se)+Y.StudentOfSubject, ios::in);
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
						SinhVien s;
						strcpy_s(s.Class, 10, CH);
						file.getline(s.ID, 10);
						file.getline(s.pass, 20);
						file.getline(s.FirstName, 50);
						file.getline(s.LastName, 50);
						file.getline(s.Gender, 10);
						file.getline(s.DateOfBirth, 50);
						file.getline(s.SocialID, 10);
						for (int i = 0; i < 3; i++)
						{
							file >> s.begin[i];
						}
						file.ignore();
						file >> s.YearStudent;
						file.ignore();
						file >> s.Semester;
						file.ignore();
						if (strcmp(s.ID, S.ID) == 0 && strcmp(ch, id) == 0)
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
			remove((to_string(se)+Y.StudentOfSubject).c_str());
			rename("temp.txt", (to_string(se)+Y.StudentOfSubject).c_str());
		}
	}
}