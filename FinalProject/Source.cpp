#include "Header.h"

void ReadFileClass(ListLop& dsl, const SchoolYear&Y)
{
	ifstream file;
	file.open(Y.DSLop, ios_base::in);
	for (int i = 0; i < maxlop; ++i)
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
		if (c.size() == 0) break;
		dsl.l[dsl.n].Ma=c;
		getline(file, dsl.l[dsl.n].Ten);
		getline(file, dsl.l[dsl.n].NienKhoa);
		dsl.l[dsl.n].pHead = NULL;
		++dsl.n;
	}
	file.close();
}
Time getTime()
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	Time a;
	a.year = 1900 + newtime.tm_year;
	a.month = 1 + newtime.tm_mon;
	a.day = newtime.tm_mday;
	a.hour = newtime.tm_hour;
	a.minute = newtime.tm_min;
	a.second = newtime.tm_sec;
	return a;
}
bool isLeapYear(int nYear)
{
	if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0)
	{
		return true;
	}
	return false;
}

int sumOfDayInMonth(int nMonth, int nYear)
{
	int nNumOfDays=0;

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

bool isDate(int nDay, int nMonth, int nYear)
{
	if (nYear < 1900)
	{
		return false;
	}
	if (nMonth < 1 || nMonth > 12)
	{
		return false;
	}

	if (nDay < 1 || nDay > sumOfDayInMonth(nMonth, nYear))
	{
		return false;
	}
	return true;
}

bool isTime(int h, int m, int s)
{
	return ((h >= 0) && (h <= 23) && (m >= 0) && (m <= 59) && (s >= 0) && (s <= 59));
}

char isTimeIn(Time t, Time begin, Time end)
{
	if (begin.year > t.year) return -1;
	else if (begin.year == t.year)
	{
		if (begin.month > t.month) return -1;
		else if (begin.month == t.month)
		{
			if (begin.day > t.day) return -1;
			else if (begin.day == t.day)
			{
				if (begin.hour > t.hour) return -1;
				else if (begin.hour == t.hour)
				{
					if (begin.minute > t.minute) return -1;
					else if (begin.minute == t.minute)
					{
						if (begin.second > t.second) return -1;
					}
				}
			}
		}
	}
	if (end.year < t.year) return 1;
	else if (end.year == t.year)
	{
		if (end.month < t.month) return 1;
		else if (end.month == t.month)
		{
			if (end.day < t.day) return 1;
			else if (end.day == t.day)
			{
				if (end.hour < t.hour) return 1;
				else if (end.hour == t.hour)
				{
					if (end.minute < t.minute) return 1;
					else if (end.minute == t.minute)
					{
						if (end.second < t.second) return 1;
					}
				}
			}
		}
	}
	return 0;
}