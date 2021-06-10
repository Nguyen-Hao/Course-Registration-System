#include "login.h"
#include "course.h"
#include "Dk_mon.h"
#include "student.h"
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
//
void ghi_file_dssv_trong_lop(ListLop listlop)
{
	ofstream file;
	file.open("Dssv_trong_lop_out.txt", ios::out);
	if (file.fail())
	{
		cout << "loi file" << endl;
		return;
	}
	int i = 0;
	while (i < listlop.n)
	{
		file << listlop.l[i].Ma << endl;
		file << listlop.l[i].Ten << endl;
		file << listlop.l[i].NienKhoa << endl;
		file << listlop.l[i].soluong << endl;
		ListSV* p = listlop.l[i].pHead;
		while (p != NULL)
		{
			file << p->info.ID << endl;
			file << p->info.pass << endl;
			file << p->info.FirstName << endl;
			file << p->info.LastName << endl;
			file << p->info.Gender << endl;
			file << p->info.DateOfBirth << endl;
			file << p->info.SocialID << endl;
			p = p->pNext;
		}
		i++;
	}
	file.close();
}

void init_list_lop(ListLop& listlop)
{
	for (int i = 0; i < listlop.n; i++)
	{
		listlop.l[i].pHead = NULL;
		listlop.l[i].soluong = 0;
	}
}
void load_sv_list_lop(ListLop& listlop)
{
	ifstream file;
	file.open("Dssv_trong_lop.txt");
	while (!file.eof())
	{
		char malop[16], nienkhoa[20], tenlop[50];
		char a[3];
		file.getline(malop, 16);
		file.getline(tenlop, 50);
		file.getline(nienkhoa, 20);
		
		int i;
		for (i = 0; i < listlop.n; i++)
		{
			if (strcmp(malop, listlop.l[i].Ma) == 0)
			{
				break;
			}
		}
		file.getline(a, 3);
		listlop.l[i].soluong = atoi(a);
		int j = 0;
		while (j < listlop.l[i].soluong)
		{
			SinhVien sv;
			file.clear();
			file.getline(sv.ID, 20);
			file.getline(sv.pass, 20);
			file.getline(sv.FirstName, 20);
			file.getline(sv.LastName, 20);
			file.getline(sv.Gender, 20);
			file.getline(sv.DateOfBirth, 20);
			file.getline(sv.SocialID, 20);
			ListSV* a;
			a = Create_Node_Sv(sv);
			if (listlop.l[i].pHead == NULL)
			{
				listlop.l[i].pHead = a;
			}
			else
			{
				ListSV* p = listlop.l[i].pHead;
				while (p->pNext != NULL)
				{
					p = p->pNext;
				}
				p->pNext = a;
			}
			j++;
		}
	}
	file.close();
}
void test(ListLop listlop)
{
	ofstream file;
	file.open("test.txt", ios::out);
	if (file.fail())
	{
		cout << "loi file" << endl;
		return;
	}
	int i = 0;
	while (i < listlop.n)
	{
		file << listlop.l[i].Ma << endl;
		file << listlop.l[i].Ten << endl;
		file << listlop.l[i].NienKhoa << endl;
		file << listlop.l[i].soluong << endl;
		ListSV* p = listlop.l[i].pHead;
		while (p != NULL)
		{
			file << p->info.ID << endl;
			file << p->info.pass << endl;
			file << p->info.FirstName << endl;
			file << p->info.LastName << endl;
			file << p->info.Gender << endl;
			file << p->info.DateOfBirth << endl;
			file << p->info.SocialID << endl;
			p = p->pNext;
		}
		i++;
	}
	file.close();
}
// cac thao tac co ban cua stack
void init_stack_list_dsdk_mon(list_dsdk_mon& list)
{
	list.capacity = 12;
	list.top = -1;
	list.arr = new danhsachdangkymon[list.capacity];
}
bool isEmpty(list_dsdk_mon s)
{
	if (s.top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool isFull(list_dsdk_mon s)
{
	if (s.top >= (s.capacity - 1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void push(list_dsdk_mon& s, danhsachdangkymon val)
{
	if (isEmpty(s) == true)
	{
		s.arr = new danhsachdangkymon[s.capacity];
	}
	if (isFull(s))
	{
		return;
	}
	else
	{
		++s.top;
		if (s.arr == NULL)
		{
			return;
		}
		s.arr[s.top] = val;
	}
}
void pop(list_dsdk_mon& s)
{
	if (isEmpty(s) == true)
	{
		cout << "Stack is empty. Underflow condition!" << endl;
	}
	else
	{
		s.top--;
	}
}
//
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
	listlop.n = i - 1;
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

void xuat_dsdk_mon(list_dsdk_mon list, danhsachdangkymon dsdk_mon)
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
					dsdk_mon.dsdk_mon[j] = dsdk_mon.dsdk_mon[j + 1];
				}
			}

		}
	}
	dsdk_mon.n--;
}
void xoa_mon_dang_ky(danhsachdangkymon& dsdk_mon, ListLop& listlop, ListSV* student)
{
	while (true)
	{
		system("cls");
		cout << "danh sach mon da dang ky." << endl;
		if (dsdk_mon.n == 0)
		{
			cout << "danh sach rong" << endl;
			cout << "nhan phim bat ki de quay laI." << endl;
			system("pause");
			break;
		}
		else
		{
			for (int i = 0; i < dsdk_mon.n; i++)
			{
				cout << i + 1 << ". " << dsdk_mon.dsdk_mon[i].Ma << " - " << dsdk_mon.dsdk_mon[i].Ten << " - " << dsdk_mon.dsdk_mon[i].NienKhoa << endl;
			}
			cout << dsdk_mon.n + 1 << ". quay lai." << endl;
			int luachon = xulyluachon(dsdk_mon.n + 1);
			if (luachon == dsdk_mon.n + 1)
			{
				break;
			}
			xoa_mon(dsdk_mon, luachon, listlop, student);
			ghi_file_dssv_trong_lop(listlop);
			cout << "ban da xoa thanh cong." << endl;
			system("pause");
		}
	}
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
					/*if (listlop.l[luachon - 1].pHead == NULL)
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
					}*/
					AddTailStudent(listlop.l[luachon - 1].pHead, student->info);
					//
					// them vao danh sach mon dang ky
					strcpy_s(dsdkmon.dsdk_mon[dsdkmon.n].Ma, listlop.l[luachon - 1].Ma);
					strcpy_s(dsdkmon.dsdk_mon[dsdkmon.n].NienKhoa, listlop.l[luachon - 1].NienKhoa);
					strcpy_s(dsdkmon.dsdk_mon[dsdkmon.n].Ten, listlop.l[luachon - 1].Ten);
					dsdkmon.n++;

					cout << "da dang ky mon thanh con" << endl;
					ghi_file_dssv_trong_lop(listlop);
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
void load_mon(ListLop listlop, list_dsdk_mon &dsdk_mon, ListSV* student)
{
	int namhoc = student->info.YearStudent;
	int hocki = 1;
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
void xu_ly_menu_student()
{
	ListLop listlop = Load_list_lop();
	init_list_lop(listlop);
	load_sv_list_lop(listlop);
	test(listlop);
	//
	list_dsdk_mon dsdk_mon;
	init_stack_list_dsdk_mon(dsdk_mon);
	if (isEmpty(dsdk_mon) == 1)
	{
		dsdk_mon.top++;
		dsdk_mon.arr[dsdk_mon.top].n = 0;
	}

	//
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
			dang_ky_mon(listlop, student, dsdk_mon.arr[dsdk_mon.top]);
		}
		else if (luachon == 2)
		{
			xoa_mon_dang_ky(dsdk_mon.arr[dsdk_mon.top], listlop, student);
		}
		else if (luachon == 3)
		{
			xuat_dsdk_mon(dsdk_mon, dsdk_mon.arr[dsdk_mon.top]);
		}
	}
}