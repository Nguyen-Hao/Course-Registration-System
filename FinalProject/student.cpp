#include "student.h"
#include "Header.h"

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
	for (int i = 0;i < n;i++)
	{
		if (strcmp(dsl.l[i].Ma, a) == 0)
			if (i == 0) return -1; //neu dau tien thi tra ve -1 
			else return i;
	}
	return 0; // tra ve 0 khi khong tim thay
}
void AddStudent_Input(ListLop& dsl)
{
	cin.ignore();
	char c[10];
	SinhVien sv;
	cout << "Nhap ID lop: "; cin.get(c, 10, '\n');
	int STTLop;
	int KT = CheckClass(dsl, c, dsl.n);
	if (KT != 0)
	{
		cin.ignore();
		cout << "Nhap ID: "; cin.get(sv.ID, 10, '\n');
		cin.ignore();
		cout << "Nhap ho: "; cin.get(sv.FirstName, 50, '\n');
		cin.ignore();
		cout << "Nhap ten: "; cin.get(sv.LastName, 50, '\n');
		cin.ignore();
		cout << "Nhap gioi tinh: "; cin.get(sv.Gender, 10, '\n');
		cin.ignore();
		cout << "Nhap ngay sinh (dd/mm/yyyy): "; cin.get(sv.DateOfBirth, 50, '\n');
		cin.ignore();
		cout << "Nhap Social ID: "; cin.get(sv.SocialID, 10, '\n');
		if (KT == -1)
			STTLop = 0;
		else STTLop = KT;
		AddTailStudent(dsl.l[STTLop].pHead, sv);
	}
	else
	{
		cout << "Khong tim thay lop " << c << endl;
		cout << "Vui long nhap lai..." << endl;
	}
}
void WriteFileStudent(ListLop& dsl)
{
	ofstream file;
	file.open(FILEDSSV, ios::out);
	for (int i = 0; i < dsl.n; i++)
	{
		file << dsl.l[i].Ma << endl;
		for (ListSV* k = dsl.l[i].pHead; k != NULL; k = k->pNext)
			file << k->info.ID << endl << k->info.FirstName << endl << k->info.LastName << endl << k->info.Gender << endl << k->info.DateOfBirth << endl << k->info.SocialID << endl;
	}
}
void ReadFileStudent(ListLop& dsl)
{
	ifstream file;
	file.open(FILEDSSV, ios::in);
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
		if (KT != 0)
		{
			if (KT == -1)
				STTLop = 0;
			else STTLop = KT;
		}
		else
		{
			strcpy_s(sv.ID, 10, a);
			getline(file, s);	strcpy_s(sv.FirstName, 50, s.c_str());
			getline(file, s);	strcpy_s(sv.LastName, 50, s.c_str());
			getline(file, s);	strcpy_s(sv.Gender, 10, s.c_str());
			getline(file, s);	strcpy_s(sv.DateOfBirth, 50, s.c_str());
			getline(file, s);	strcpy_s(sv.SocialID, 10, s.c_str());
			AddTailStudent(dsl.l[STTLop].pHead, sv);
		}
	}
	file.close();
}
void ReadFileCSV(ListLop& ds)
{
	ifstream f1;
	f1.open("Source1.csv", ios::in | ios::out);
}