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
void UpdateCSV(ListLop& ds)
{
	ifstream f1;
	f1.open(FILECSV, ios::in | ios::out);
	string line = "", word;
	int ViTriLop;
	ofstream file;
	file.open(FILEDSSV, ios_base::out);
	while (f1.good())
	{
		char MaLop[10];
		getline(f1, line);
		if (line.size() == 0) break;
		stringstream s(line);
		vector<string> row;
		while (getline(s, word, ','))
		{
			row.push_back(word);
		}
		strcpy_s(MaLop, 10, row[0].c_str());
		int KT = CheckClass(ds, MaLop, ds.n);
		if (KT != 0)
		{
			if (KT == -1)	ViTriLop = 0;
			else ViTriLop = KT;
		}
		SinhVien sv;
		strcpy_s(sv.ID, 10, row[2].c_str());
		strcpy_s(sv.FirstName, 50, row[3].c_str());
		strcpy_s(sv.LastName, 50, row[4].c_str());
		strcpy_s(sv.Gender, 10, row[5].c_str());
		strcpy_s(sv.DateOfBirth, 50, row[6].c_str());
		strcpy_s(sv.SocialID, 10, row[7].c_str());
		bool flat = true;
		for (ListSV* k = ds.l[ViTriLop].pHead; k != NULL; k = k->pNext)
			if (strcmp(k->info.ID, sv.ID) == 0 && strcmp(k->info.FirstName, sv.FirstName) == 0 && strcmp(k->info.LastName, sv.LastName) == 0 && strcmp(k->info.SocialID, sv.SocialID) == 0 && strcmp(k->info.ID, sv.ID) == 0 && strcmp(k->info.Gender, sv.Gender) == 0)
				flat = false;
		if (flat == true) AddTailStudent(ds.l[ViTriLop].pHead, sv);
	}
	WriteFileStudent(ds);
	file.close();
}
