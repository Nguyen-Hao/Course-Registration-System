#include "Header.h"

void ReadFileClass(ListLop& dsl, const SchoolYear&Y)
{
	ifstream file;
	file.open(Y.DSLop, ios_base::in);
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
		strcpy_s(dsl.l[dsl.n].Ma, 16, c.c_str());
		getline(file, c);	strcpy_s(dsl.l[dsl.n].Ten, 30, c.c_str());
		getline(file, c);	strcpy_s(dsl.l[dsl.n].NienKhoa, 10, c.c_str());
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
//Kiểm tra năm nhuận
bool isLeapYear(int nYear)
{
	if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0)
	{
		return true;
	}
	return false;
}

// Hàm trả về số ngày trong tháng thuộc năm cho trước
int sumOfDayInMonth(int nMonth, int nYear)
{
	int nNumOfDays;

	switch (nMonth)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		nNumOfDays = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		nNumOfDays = 30;
		break;
	case 2:
		if (isLeapYear(nYear))
		{
			nNumOfDays = 29;
		}
		else
		{
			nNumOfDays = 28;
		}
		break;
	}

	return nNumOfDays;
}

// Hàm kiểm tra ngày dd/mm/yyyy cho trước có phải là ngày hợp lệ
bool isDate(int nDay, int nMonth, int nYear)
{
	// Kiểm tra năm
	if (nYear < 0)
	{
		return false;
	}

	// Kiểm tra tháng
	if (nMonth < 1 || nMonth > 12)
	{
		return false;
	}

	// Kiểm tra ngày
	if (nDay < 1 || nDay > sumOfDayInMonth(nMonth, nYear))
	{
		return false;
	}

	return true; // Trả về trạng thái cuối cùng...
}

//Hàm kiểm tra giờ phút giây có hợp lệ hay không
bool isTime(int h, int m, int s)
{
	return ((h >= 0) && (h <= 23) && (m >= 0) && (m <= 59) && (s >= 0) && (s <= 59));
}