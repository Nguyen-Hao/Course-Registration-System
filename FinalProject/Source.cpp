#include "Header.h"

void ReadFileClass(ListLop& dsl)
{
	ifstream file;
	file.open(FILEDSLOP, ios_base::in);
	for (int i = 0; i < maxlop; i++)
	{
		dsl.l[i].Ma[0] = NULL;
		dsl.l[i].NienKhoa[0] = NULL;
		dsl.l[i].pHead = NULL;
		dsl.l[i].Ten[0] = NULL;
	}
	string c;
	while (file.good())
	{
		getline(file, c);
		strcpy_s(dsl.l[dsl.n].Ma, 50, c.c_str());
		getline(file, c);	strcpy_s(dsl.l[dsl.n].Ten, 50, c.c_str());
		getline(file, c);	strcpy_s(dsl.l[dsl.n].NienKhoa, 50, c.c_str());
		dsl.l[dsl.n].pHead = NULL;
		if (c.size() == 0) break;
		dsl.n++;
	}
	file.close();
}
//Hàm lấy thời gian hệ thống
Time getTime()
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	Time a;
	// các thành phần của cấu trúc tm struct
	a.year = 1900 + newtime.tm_year;
	a.month = 1 + newtime.tm_mon;
	a.day = newtime.tm_mday;
	a.hour = newtime.tm_hour;
	a.minute = newtime.tm_min;
	a.second = newtime.tm_sec;
	return a;
}