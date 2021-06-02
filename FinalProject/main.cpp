#include "Header.h"
#include "console.h"
#include "course.h"
#include "login.h"
#include "staff.h"
#include "student.h"
int main()
{
	ListLop ds;
	ds.n = 0;
	FixConsoleWindow();
	resizeConsole(1000, 600);
	ReadFileClass(ds);
	ReadFileStudent(ds);
	system("pause");
	return 0;
}