#pragma once
#include "Header.h"
#include "course.h"
struct monhoc
{
	char Ma[16];
	char Ten[30];
	char NienKhoa[10];
};
struct danhsachdangkymon
{
	monhoc dsdk_mon[5];
	int n;
};