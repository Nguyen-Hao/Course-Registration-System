#include"Header.h"
#include"course.h"
void copy(NodeCourse*& p, NodeCourse* p1)
{
	p->course = p1->course;
	p->next = NULL;
}
void themvaolist(ListCourses& result, ListCourses l, char id[10])
{

	NodeCourse* temp = l.head;
	while (temp != NULL)
	{
		if (strcmp(temp->course.ID, id) == 0)
		{
			NodeCourse* ptr = new NodeCourse;
			copy(ptr, temp);
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

bool ktra(const ListCourses& l, string c)
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
ListCourses courseOfStudent(const ListCourses& l, const SinhVien& sv)
{
	ListCourses result;
	initListCourses(result);
	fstream file;
	file.open("StudentOfSubject.txt", ios::in);
	char ch[10] = "\0", CH[10] = "\n";
	file.getline(ch, 10);
	while (!file.eof())
	{
		while (ktra(l, CH) == false)
		{
			file.getline(CH, 10);
			if (ktra(l, CH) == true || strcmp(CH, "\0") == 0) break;
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
					themvaolist(result, l, ch);

			}
		}
		strcpy_s(ch, 10, CH);
		strcpy_s(CH, 10, "\n");
	}
	file.close();
	return result;
}
NodeCourse* find(const ListCourses& l, char id[10])
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
bool checkTrung(const ListCourses& l, NodeCourse* ptr)
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
void dangki(ListCourses& l, SinhVien& S)
{
	l = ReadListCourses();
	ListCourses temp = courseOfStudent(l, S);
	if (countNodeCourses(temp) == 5)
		cout << "da dang ki du 5 mon!!!" << endl;
	else
	{
		char id[10];
		cout << "nhap id mon can dang ki: ";
		cin.get(id, 10, '\n');
		cin.ignore();
		NodeCourse* ptr = find(l, id);

		if (ktra(l, id) == false)
			cout << "khong co mon hoc";
		else
		{
			if (checkTrung(temp, ptr) == true)
				cout << "phien gio hoc bi trung ";
			else
			{
				fstream file, file1;
				file.open("StudentOfSubject.txt", ios::in);
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
					while (ktra(l, CH) == false)
					{
						file.getline(CH, 10);

						if (ktra(l, CH) == true || strcmp(CH, "\0") == 0) break;
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
				remove("StudentOfSubject.txt");
				rename("temp.txt", "StudentOfSubject.txt");
				cout << "dang ki thanh cong!!!" << endl;
			}
			
		}
	}
}
void view_Enrol_Course(SinhVien& S)
{
	ListCourses l = ReadListCourses();
	ListCourses list = courseOfStudent(l, S);
	if (list.head == NULL)
		cout << "chua dang ki mon nao!" << endl;
	else
	{
		cout << setw(10) << left << "ID" << setw(50) << left << "Name of course";
		cout << setw(50) << left << "Teacher name" << setw(8) << left << "Credit";
		cout << setw(20) << "Number of student";
		cout << setw(10) << left << "Thu" << setw(10) << left << "Time";
		cout << setw(10) << left << "Thu" << setw(10) << left << "Time" << endl;
		NodeCourse* temp1 = list.head;
		while (temp1 != NULL)
		{
			cout << setw(10) << left << temp1->course.ID << setw(50) << left << temp1->course.Name;
			cout << setw(50) << left << temp1->course.TeacherName << setw(8) << left << temp1->course.NumOfCredits;
			cout << setw(20) << temp1->course.MaxNumOfStudents;
			cout << setw(10) << left << temp1->course.Session1.thu << setw(2) << left << temp1->course.Session1.gio << ":" << setw(8) << temp1->course.Session1.phut;
			cout << setw(10) << left << temp1->course.Session2.thu << setw(2) << left << temp1->course.Session2.gio << ":" << temp1->course.Session2.phut << endl;
			temp1 = temp1->next;
		}
	}
}
void eraser_erol_course(SinhVien& S)
{
	char id[10];
	cout << "nhap id mon can huy dang ki: ";
	cin.get(id, 10, '\n');
	cin.ignore();
	ListCourses l = ReadListCourses();
	if (ktra(l, id) == false)
		cout << "id mon ban nhap khong ton tai" << endl;
	else
	{
		ListCourses temp = courseOfStudent(l, S);
		if (ktra(temp, id) == false)
			cout << "mon nay ban chua dang ki" << endl;
		else
		{
			fstream file, file1;
			file.open("StudentOfSubject.txt", ios::in);
			file1.open("temp.txt", ios::out);
			char ch[10] = "\0", CH[10] = "\n";
			file.getline(ch, 10);
			while (!file.eof())
			{
				file1 << ch << endl;
				while (ktra(l, CH) == false)
				{
					file.getline(CH, 10);
					if (ktra(l, CH) == true || strcmp(CH, "\0") == 0) break;
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
			remove("StudentOfSubject.txt");
			rename("temp.txt", "StudentOfSubject.txt");
			cout << "eraser thanh cong!!!" << endl;

		}
	}
}