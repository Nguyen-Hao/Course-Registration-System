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
List_Sv doc_file_Dssv_TXT(string namefile)
{
	List_Sv dssv;
	Create_List_Sv(dssv);

	//ListSV* b = dssv.pHead;

	ifstream file;
	file.open(namefile);
	if (file.fail())
	{
		cout << "Failed to open this file!" << endl;
	}
	while (!file.eof())
	{
		SinhVien sv;
		file.clear();
		file.getline(sv.Class, 20);
		file.getline(sv.ID, 20);
		file.getline(sv.pass, 20);
		file.getline(sv.FirstName, 20);
		file.getline(sv.LastName, 20);
		file.getline(sv.Gender, 20);
		file.getline(sv.DateOfBirth, 20);
		file.getline(sv.SocialID, 20);
		ListSV* a;
		a = Create_Node_Sv(sv);
		if (dssv.pHead == NULL)
		{
			dssv.pHead = a;
			dssv.pTail = a;
		}
		else
		{
			dssv.pTail->pNext = a;
			dssv.pTail = a;
		}
		//file.get(dot, 3, 27);
		/*for(int i=0;i<dsl.n;i++)
			for (ListSV* p = dsl.l[i].pHead; p != NULL;p = p->pNext)
			{
				char dot[3];
				SinhVien sv;
				strcpy_s(sv.ID, 10, p->info.ID);
				strcpy_s(sv.DateOfBirth, 50, p->info.DateOfBirth);
				strcpy_s(sv.FirstName, 50, p->info.FirstName);
				strcpy_s(sv.Gender, 10, p->info.Gender);
				strcpy_s(sv.LastName, 50, p->info.LastName);
				strcpy_s(sv.SocialID, 10, p->info.SocialID);
				strcpy_s(sv.pass, 20, p->info.pass);
				ListSV* a;
				a = Create_Node_Sv(sv);
				if (b == NULL)
				{
					b = a;
					dssv.pHead = a;
					dssv.pTail = a;
				}
				else
				{
					dssv.pTail->pNext = a;
					dssv.pTail = a;
				}
			}


		/*if (strcmp(dot, ".") == 1)
		{
			continue;
		}*/
	}
	file.close();
	return dssv;
}

ListSV* dang_nhap(string namefile)
{

	char Tk[20], Mk[20];


	List_Sv dssv = doc_file_Dssv_TXT(namefile);
	ListSV* p = new ListSV;
	do
	{
		bool Kt_dang_nhap = false;
		system("cls");
		cin.clear();
		cin.ignore();
		cout << "Dang nhap" << endl;
		cout << "nhap tai khoan: ";
		cin.getline(Tk, 20);

		cout << "nhap mat khau: ";
		cin.getline(Mk, 20);

		p = dssv.pHead;
		if (p == NULL)
		{
			cout << "p NULL" << endl;
			system("pause");
		}

		while (p != NULL)
		{
			if (strcmp(Tk, p->info.ID) == 0 && strcmp(Mk, p->info.pass) == 0)
			{
				Kt_dang_nhap = true;
				break;
			}
			else
			{
				Kt_dang_nhap = false;
			}

			p = p->pNext;
		}
		if (Kt_dang_nhap)
		{
			cout << "Dang nhap thanh cong!" << endl;
			system("pause");
			break;
		}
		else
		{
			cout << "Ban da nhap sai tai khoan hoac mat khau. Vui long nhap lai." << endl;
			system("pause");
		}

	} while (true);

	return p;

}
ListSV* xu_ly_menu_dang_nhap()
{
	int a = chon_tai_khoan();
	ListSV* node = new ListSV;
	if (a == 3)
	{
		exit;
	}
	else if (a == 1)
	{
		node = dang_nhap("DSGiaoVien.txt");
	}
	else if (a == 2)
	{
		node = dang_nhap("DSSinhVien.txt");
	}
	return node;
}