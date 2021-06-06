#include "login.h"
#include "Header.h"
ListSV* Create_Node_Sv(SinhVien sv)
{
	ListSV* a = new ListSV;
	a->info = sv;
	a->pNext = NULL;
	return a;
}
void Create_List_Sv(List_Sv& dssv)
{
	dssv.pHead = NULL;
	dssv.pTail = NULL;
}
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