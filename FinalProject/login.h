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
