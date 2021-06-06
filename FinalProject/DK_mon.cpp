#include "login.h"
#include "course.h"
#include "Dk_mon.h"
//
void delete_node(ListSV*& phead, ListSV* node)
{
	if (strcmp(phead->info.ID, node->info.ID) == 0)
	{
		phead = phead->pNext;
	}
	else
	{
		ListSV* p = phead;
		while (p->pNext != NULL && strcmp(p->pNext->info.ID, node->info.ID) != 0)
		{
			p = p->pNext;
		}
		if (p->pNext == NULL)
		{
			if (strcmp(p->info.ID, node->info.ID) != 0)
			{
				p = NULL;
			}
		}
		else
		{
			p->pNext = p->pNext->pNext;
		}
	}

}
ListLop Load_list_lop()
{
	ListLop listlop;
	listlop.n = 0;
	ifstream input_file;
	input_file.open("DSLop.txt");
	int i = 0;
	while (!input_file.eof())
	{
		input_file.getline(listlop.l[i].Ma, 10);
		input_file.getline(listlop.l[i].Ten, 50);
		input_file.getline(listlop.l[i].NienKhoa, 10);
		i++;
	}
	listlop.n = i;
	input_file.close();
	return listlop;
}
int print_list_lop(ListLop listlop)
{
	system("cls");
	cout << "danh sach cac mon dang ky" << endl;
	for (int i = 0; i < listlop.n; i++)
	{
		cout << i + 1 << ". " << listlop.l[i].Ma << " - " << listlop.l[i].Ten << " - " << listlop.l[i].NienKhoa << endl;
	}
	cout << listlop.n + 1 << ". quay lai." << endl;
	int a = xulyluachon(listlop.n + 1);
	return a;
}
void dang_ky_mon(ListLop& listlop, ListSV* student, danhsachdangkymon& dsdkmon)
{
	while (true)
	{
		int luachon = print_list_lop(listlop);
		if (luachon == listlop.n + 1) // lua chon n + 1 la quay lai
		{
			break;
		}
		else
		{
			if (dsdkmon.n < 5) // dk du 5 mon la thoat
			{
				// kiem tra co trung mon da dang ky hay ko
				bool KT = true;
				for (int i = 0; i <= dsdkmon.n; i++)
				{
					if (strcmp(dsdkmon.dsdk_mon[i].Ma, listlop.l[luachon - 1].Ma) == 0)   // do luachon tính từ 1 mà mảng tính từ 0 nên luachon phải trừ 1
					{
						KT = false;
						cout << "Mon nay da dang ky. Vui long dang ky mon khac!" << endl;
						system("pause");
						break;
					}
				}
				if (KT == true)
				{
					// dang ky mon
					// them vao danh sach lop
					if (listlop.l[luachon - 1].pHead == NULL)
					{
						listlop.l[luachon - 1].pHead = student;
					}
					else
					{
						ListSV* ptr = listlop.l[luachon - 1].pHead;
						while (ptr->pNext != NULL)
						{
							ptr = ptr->pNext;
						}
						ptr->pNext = student;
					}

					//
					// them vao danh sach mon dang ky
					strcpy_s(dsdkmon.dsdk_mon[dsdkmon.n].Ma, listlop.l[luachon - 1].Ma);
					strcpy_s(dsdkmon.dsdk_mon[dsdkmon.n].NienKhoa, listlop.l[luachon - 1].NienKhoa);
					strcpy_s(dsdkmon.dsdk_mon[dsdkmon.n].Ten, listlop.l[luachon - 1].Ten);
					dsdkmon.n++;

					cout << "da dang ky mon thanh con" << endl;
					system("pause");
				}
			}
			else
			{
				cout << "da dang ky toi da 5 mon. Khong the dang ky them nua" << endl;
				system("pause");
				break;
			}
		}
	}
}
void xuat_dsdk_mon(danhsachdangkymon dsdk_mon)
{
	system("cls");
	cout << "danh sach mon da dang ky." << endl;
	if (dsdk_mon.n == 0)
	{
		cout << "danh sach rong" << endl;
	}
	else
	{
		for (int i = 0; i < dsdk_mon.n; i++)
		{
			cout << i + 1 << ". " << dsdk_mon.dsdk_mon[i].Ma << " - " << dsdk_mon.dsdk_mon[i].Ten << " - " << dsdk_mon.dsdk_mon[i].NienKhoa << endl;
		}
	}
	cout << "nhan phim bat ki de quay laI." << endl;
	system("pause");
}
void xoa_mon(danhsachdangkymon& dsdk_mon, int luachon, ListLop& listlop, ListSV* student)
{
	for (int i = 0; i < listlop.n; i++) // xoa trong list lop
	{
		if (strcmp(listlop.l[i].Ma, dsdk_mon.dsdk_mon[luachon - 1].Ma) == 0)
		{
			ListSV* p = listlop.l[i].pHead;
			/*while (p->pNext != NULL && strcmp(p->info.ID, student->info.ID) != 0)
			{
				p = p->pNext;
			}*/
			delete_node(listlop.l[i].pHead, student);
		}
	}
	// xoa trong dsdk mon
	for (int i = 0; i < dsdk_mon.n; i++) // xoa trong list lop
	{
		if (strcmp(dsdk_mon.dsdk_mon[i].Ma, dsdk_mon.dsdk_mon[luachon - 1].Ma) == 0)
		{
			if (i != dsdk_mon.n)
			{
				for (int j = i; j < dsdk_mon.n - 1; j++)
				{
					dsdk_mon.dsdk_mon[i] = dsdk_mon.dsdk_mon[i + 1];
				}
			}

		}
	}
	dsdk_mon.n--;
}
void xoa_mon_dang_ky(danhsachdangkymon& dsdk_mon, ListLop& listlop, ListSV* student)
{
	system("cls");
	cout << "danh sach mon da dang ky." << endl;
	if (dsdk_mon.n == 0)
	{
		cout << "danh sach rong" << endl;
		cout << "nhan phim bat ki de quay laI." << endl;
		system("pause");
	}
	else
	{
		for (int i = 0; i < dsdk_mon.n; i++)
		{
			cout << i + 1 << ". " << dsdk_mon.dsdk_mon[i].Ma << " - " << dsdk_mon.dsdk_mon[i].Ten << " - " << dsdk_mon.dsdk_mon[i].NienKhoa << endl;
		}
		cout << "chon mon xoa. ";
		int luachon = xulyluachon(dsdk_mon.n);
		xoa_mon(dsdk_mon, luachon, listlop, student);
		cout << "ban da xoa thanh cong." << endl;
		system("pause");
	}
}
int Menu_Student(ListSV* student)
{
	system("cls");
	cout << "Xin Chao " << student->info.LastName << endl;
	cout << "1. Dang ky khoa hoc." << endl;
	cout << "2. xoa khoa hoc da dang ky." << endl;
	cout << "3. xem danh sach khoa hoc da dang ky." << endl;
	cout << "4. thoat." << endl;
	int a = xulyluachon(4);
	return a;
}
void init_list_lop(ListLop& listlop)
{
	for (int i = 0; i < listlop.n; i++)
	{
		listlop.l[i].pHead = NULL;
	}
}
void xu_ly_menu_student()
{
	ListLop listlop = Load_list_lop();
	init_list_lop(listlop);
	danhsachdangkymon dsdk_mon;
	dsdk_mon.n = 0;
	system("cls");
	ListSV* student = xu_ly_menu_dang_nhap();
	while (true)
	{
		int luachon = Menu_Student(student);
		if (luachon == 4)
		{
			exit(0);
		}
		else if (luachon == 1)
		{
			dang_ky_mon(listlop, student, dsdk_mon);
		}
		else if (luachon == 2)
		{
			xoa_mon_dang_ky(dsdk_mon, listlop, student);
		}
		else if (luachon == 3)
		{
			xuat_dsdk_mon(dsdk_mon);
		}
	}
}