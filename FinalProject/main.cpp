#include "Header.h"
#include "console.h"
#include "course.h"
#include "login.h"
#include "staff.h"
#include "student.h"
#include "Semester.h"
#include "DKMon.h"
#include "SchoolYear.h"

int main()
{
	
	SchoolYear s;
	CreateSchoolYear(s);
	cout << s.NameSchoolYear << endl;
	cout << s.DsGiaoVien << endl;
	cout << s.DSLop << endl;
	cout << s.DSSinhVien << endl;
	cout << s.Filecsv << endl;
	cout << s.ListCourses << endl;
	cout << s.sesmester << endl;
	cout << s.StudentOfSubject << endl;
	cout << s.TimeDKHP << endl;

	return 0;
}
