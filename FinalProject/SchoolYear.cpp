#include"Header.h"
#include"SchoolYear.h"
#include"student.h"
#include"staff.h"
unsigned int YearPresent()
{
	fstream file;
	file.open(FILESCHOOLYEAR, ios::in);
	if (file.is_open())
	{
		unsigned int a = 0, b = 0;
		SchoolYear c;
		while (!file.eof())
		{
			file >> a >> b;
			file.ignore();
			getline(file, c.DSLop);
			getline(file, c.DSSinhVien);
			getline(file, c.ListCourses);
			getline(file, c.sesmester);
			getline(file, c.StudentOfSubject);
			getline(file, c.TimeDKHP);
		}
		file.close();
		return a;
	}
	else return 0;
}

void CreateSchoolYear(SchoolYear& S)
{
	unsigned int n = YearPresent();
	if (n == 0)
	{
		Time t = getTime();
		S.NameSchoolYear = to_string(t.year) + " " + to_string(t.year + 1);
		string temp1 = to_string(t.year) + "_" + to_string(t.year + 1) + ".txt";
		S.DSLop += temp1;
		S.DSSinhVien += temp1;
		S.ListCourses += temp1;
		S.sesmester += temp1;
		S.StudentOfSubject += temp1;
		S.TimeDKHP += temp1;
	}
	else
	{
		SchoolYear Y;
		string temp = to_string(n + 1) + " " + to_string(n + 2);
		string temp1 = to_string(n + 1) + "_" + to_string(n + 2) + ".txt";
		Y.NameSchoolYear = temp;
		Y.DSLop += temp1;
		Y.DSSinhVien += temp1;
		Y.ListCourses += temp1;
		Y.sesmester += temp1;
		Y.StudentOfSubject += temp1;
		Y.TimeDKHP += temp1;
		S = Y;
		SchoolYear y1 = SchoolYearPresent(FILESCHOOLYEAR);
		CopyData(y1.DSLop, Y.DSLop);
		CopyData(y1.DSSinhVien, Y.DSSinhVien);
		UpdateStudent(Y);
		ExportFileEmpty(Y.sesmester);
		ExportFileEmpty(Y.TimeDKHP);
	}
	fstream file;
	file.open(FILESCHOOLYEAR, ios::app);
	file << S.NameSchoolYear << endl;
	file << S.DSLop << endl;
	file << S.DSSinhVien << endl;
	file << S.ListCourses << endl;
	file << S.sesmester << endl;
	file << S.StudentOfSubject << endl;
	file << S.TimeDKHP << endl;
	file.close();
}


SchoolYear SchoolYearPresent(const string& S)
{
	fstream file;
	file.open(S, ios::in);
	SchoolYear c;
	if (file.is_open())
	{
		unsigned int a = 0, b = 0;
		
		while (!file.eof())
		{
			file >> a >> b;
			c.NameSchoolYear = to_string(a) + " " + to_string(b);
			file.ignore();
			getline(file, c.DSLop);
			getline(file, c.DSSinhVien);
			getline(file, c.ListCourses);
			getline(file, c.sesmester);
			getline(file, c.StudentOfSubject);
			getline(file, c.TimeDKHP);
		}
		return c;
	}
	return c;
	file.close();
}
void CopyData(const string& fileName1, const string& fileName2)
{
	fstream file1; 
	fstream file2;
	file1.open(fileName1, ios::in);
	if (file1.is_open())
	{
		file2.open(fileName2, ios::out);
		string a;
		getline(file1, a);
		while (!file1.eof())
		{
			file2 << a << endl;
			getline(file1, a);
		}
		file2.close();
	}
	file1.close();
}
void ExportFileEmpty(const string& str)
{
	fstream file;
	file.open(str, ios::out);
	file.close();
}