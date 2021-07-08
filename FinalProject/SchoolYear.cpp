#include"Header.h"
#include"SchoolYear.h"

unsigned int nam()
{
	fstream file;
	file.open(FILESCHOOLYEAR, ios::in);
	if (file.is_open())
	{
		unsigned int a = 0, b = 0;
		file >> a;
		file >> b;
		file.ignore();
		while (!file.eof())
		{
			SchoolYear c;
			getline(file, c.DsGiaoVien);
			getline(file, c.DSLop);
			getline(file, c.DSSinhVien);
			getline(file, c.Filecsv);
			getline(file, c.ListCourses);
			getline(file, c.sesmester);
			getline(file, c.StudentOfSubject);
			getline(file, c.TimeDKHP);
			file >> a >> b;
			file.ignore();
		}
		file.close();
		return b;
	}
	else return 0;
}

void CreateSchoolYear(SchoolYear& S)
{
	unsigned int n = nam();
	if (n == 0)
	{
		cout << "nhap nam hoc: (ex:2020)  ";
		Time t = getTime();
		S.NameSchoolYear = to_string(t.year) + " " + to_string(t.year + 1);
		string temp1 = to_string(t.year) + "_" + to_string(t.year + 1) + ".txt";
		S.DsGiaoVien += temp1;
		S.DSLop += temp1;
		S.DSSinhVien += temp1;
		S.Filecsv += to_string(t.year) + "_" + to_string(t.year + 1) + ".csv";
		S.ListCourses += temp1;
		S.sesmester += temp1;
		S.StudentOfSubject += temp1;
		S.TimeDKHP += temp1;
	}
	else
	{
		string temp = to_string(n) + " " + to_string(n + 1);
		string temp1 = to_string(n) + "_" + to_string(n + 1) + ".txt";
		S.NameSchoolYear = temp;
		S.DsGiaoVien += temp1;
		S.DSLop += temp1;
		S.DSSinhVien += temp1;
		S.Filecsv += to_string(n) + "_" + to_string(n + 1) + ".csv";
		S.ListCourses += temp1;
		S.sesmester += temp1;
		S.StudentOfSubject += temp1;
		S.TimeDKHP += temp1;
	}
	fstream file;
	file.open(FILESCHOOLYEAR, ios::app);
	file << S.NameSchoolYear << endl;
	file << S.DsGiaoVien << endl;
	file << S.DSLop << endl;
	file << S.DSSinhVien << endl;
	file << S.Filecsv << endl;
	file << S.ListCourses << endl;
	file << S.sesmester << endl;
	file << S.StudentOfSubject << endl;
	file << S.TimeDKHP << endl;
	file.close();
}


SchoolYear present()
{
	fstream file;
	file.open(FILESCHOOLYEAR, ios::in);
	if (file.is_open())
	{
		unsigned int a = 0, b = 0;
		file >> a;
		file >> b;
		SchoolYear c;
		c.NameSchoolYear = to_string(a) + " " + to_string(b);
		file.ignore();
		while (!file.eof())
		{
			getline(file, c.DsGiaoVien);
			getline(file, c.DSLop);
			getline(file, c.DSSinhVien);
			getline(file, c.Filecsv);
			getline(file, c.ListCourses);
			getline(file, c.sesmester);
			getline(file, c.StudentOfSubject);
			getline(file, c.TimeDKHP);
			file >> a >> b;
			file.ignore();
		}
		return c;
	}
	file.close();
}