#pragma once
#include "Header.h"

struct List_Sv // list
{
	ListSV* pHead; // node
	ListSV* pTail;
};
ListSV* Create_Node_Sv(SinhVien sv);
void Create_List_Sv(List_Sv& dssv);
int xulyluachon(int soluachon);
int chon_tai_khoan();
int xulyluachon(int soluachon)
{
	int luachon;
	bool kt;
	do
	{
		cout << "moi ban chon: ";
		cin >> luachon;
		kt = cin.fail();
		if (kt == false && (luachon > 0 && luachon <= soluachon))
		{
			break;
		}
		cin.clear();
		cin.ignore();
	} while (true);
	return luachon;
}

int chon_tai_khoan()
{
	cout << "ban la giao vien hay hoc sinh?" << endl;
	cout << "1. giao vien" << endl;
	cout << "2. hoc sinh" << endl;
	cout << "3. thoat" << endl;
	int a = xulyluachon(3);
	return a;
}