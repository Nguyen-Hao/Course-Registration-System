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
			copy(ptr ,temp);
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

bool ktra(ListCourses l,char c[10])
{
	NodeCourse* temp = l.head;
	while (temp!=NULL)
	{
		if (strcmp(temp->course.ID,c)==0)
			return true;
		temp = temp->next;
	}
	return false;
}

ListCourses courseOfStudent(ListCourses l, SinhVien sv)
{
	ListCourses result;
	initListCourses(result);
	fstream file;
	file.open("StudentOfSubject.txt", ios::in);
	char ch[10]="\0", CH[10] = "\0";
	file.getline(ch, 10);
	while (!file.eof())
	{
		while (ktra(l, CH) == false)
		{
			file.getline(CH, 10);
			if (ktra(l, CH) == true||strcmp(CH,"\0")==0) break;
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
		strcpy_s(CH, 10, "\0");
	}
	file.close();
	return result;
}


NodeCourse* find(ListCourses l, char id[10])
{
	NodeCourse* ptr = l.head;
	while (ptr!=NULL)
	{
		if (strcmp(ptr->course.ID, id) == 0)
			return ptr;
		ptr = ptr->next;
	}
	return NULL;
}
bool checkTrung(ListCourses l, NodeCourse* ptr)
{
	NodeCourse* temp = l.head;
	while (temp!=NULL)
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
void dangki(ListCourses& l, SinhVien S)
{
	l = ReadListCourses();
	ListCourses temp = courseOfStudent(l, S);
	char id[10];
	cout << "nhap id mon can dang ki: ";
	cin.get(id, 10, '\n');
	cin.ignore();
	NodeCourse* ptr = find(l, id);
	fstream file, file1;
	file.open("StudentOfSubject.txt", ios::in);
	file1.open("temp.txt", ios::out);
	if(checkTrung(temp,ptr))
		cout<<"phien gio hoc bi trung ";
	if (ktra(l, id) == false)
		cout << "khong co mon hoc";
	else
	{
		if (checkTrung(temp, ptr)==true)
			cout << "phien gio hoc bi trung ";
		else
		{
			char ch[10]="\0", CH[10] = "\0";
			file.getline(ch, 10);
			while (!file.eof())
			{
				file1 << ch << endl;
				if (strcmp(ch, id) == 0)
				{
					file1 << S.ID << endl;
					file1 << S.pass << endl;
					file1 << S.FirstName << endl;
					file1 << S.LastName << endl;
					file1 << S.Gender << endl;
					file1 << S.DateOfBirth << endl;
					file1 << S.SocialID << endl;
					for (int i = 0; i < 3; i++)
					{
						file1 << S.begin[i];
					}
					file1 << endl;
					file1 << S.YearStudent;
					file1 << endl;
					file1 << S.Semester;
					file1 << endl;
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
						file1 << s.ID << endl;
						file1 << s.pass << endl;
						file1 << s.FirstName << endl;
						file1 << s.LastName << endl;
						file1 << s.Gender << endl;
						file1 << s.DateOfBirth << endl;
						file1 << s.SocialID << endl;
						for (int i = 0; i < 3; i++)
						{
							file1 << s.begin[i];
						}
						file1 << endl;
						file1 << s.YearStudent;
						file1<<endl;
						file1 << s.Semester;
						file1 << endl;
					}
				}
				strcpy_s(ch, 10, CH);
				strcpy_s(CH, 10, "\0");
			}
		}
	}
	
	file.close();
	file1.close();
	remove("StudentOfSubject.txt");
	rename("temp.txt", "StudentOfSubject.txt");
}