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