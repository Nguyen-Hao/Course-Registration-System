#include "console.h"
#include "Header.h"
#include "login.h"
#include "student.h"
#include <cctype>
#include <string>

string Menubegin[3] = { "1. Nhan vien - giang vien", "2. Sinh vien","3. Thoat" };
string AfterLogin[6] = { "1. Dang ky mon hoc", "2. Xem danh sach mon hoc dang ky", "3. Xoa mon hoc da dang ky", "4. Xem danh sach khoa hoc da dang ky", "5. Dang xuat" , "6. Thoat"};

void BackGround()
{
	TextColor(176);
	for (int j = 0;j < 6;j++)
		for (int i = 55;i <= 100;i++)
		{
			gotoxy(i, j); cout << " ";
		}
	gotoxy(56, 0); cout << "Truong: Dai Hoc Khoa Hoc Tu Nhien - DHQG.HCM";
	gotoxy(60, 4); cout << "Do an: PHAN MEM QUAN LI SINH VIEN";
	gotoxy(63, 1); cout << "Mon: Ky thuat lap trinh";
	gotoxy(65, 2); cout << "Lop: 20CTT3";
	TextColor(228);
}

void KhungHCN(int x, int y, int width, int length)
{
	gotoxy(x, y); for (int i = 0;i < width;i++) cout << char(196);
	for (int i = 0;i < length;i++)
	{
		gotoxy(x - 1, y + i + 1); cout << char(179);
		gotoxy(x + width, y + i + 1); cout << char(179);
	}
	gotoxy(x + width, y); cout << (char)191;
	gotoxy(x - 1, y + length + 1); cout << (char)192;
	gotoxy(x - 1, y); cout << (char)218;
	gotoxy(x + width, y + length + 1); cout << (char)217;
	gotoxy(x, y + length + 1); for (int i = 0;i < width;i++) cout << char(196);
}
void InfoTeam()
{
	TextColor(228);
	KhungHCN(105, 12, 55, 8);
	gotoxy(110, 14); cout << "Giang vien huong dan: ThS. Nguyen Le Hoang Dung";
	gotoxy(110, 15); cout << "SINH VIEN THUC HIEN: ";
	gotoxy(113, 16); cout << "1. To Tran Son Ba"; gotoxy(130, 16); cout << " - 20120431";
	gotoxy(113, 17); cout << "2. Le Cong Dat"; gotoxy(130, 17); cout << " - 20120434";
	gotoxy(113, 18); cout << "3. Nguyen Van Hao"; gotoxy(130, 18); cout << " - 20120470";
	gotoxy(113, 19); cout << "4. Le Kim Hieu"; gotoxy(130, 19); cout << " - 20120474";
}
char c;
int MenuFirst()
{
	int vitri = 0;
	while (true)
	{
		system("cls");
		TextColor(224);
		KhungHCN(128, 29, 10, 2);
		gotoxy(130, 30); cout << char(30) << ": UP";
		gotoxy(130, 31); cout << char(31) << ": DOWN";
		BackGround();
		InfoTeam();
		KhungHCN(8, 12, 22, 1);
		gotoxy(10, 13); cout << "DANG NHAP DANH CHO: ";
		int n = 0;
		for (int i = 0;i < 3;i++)
		{
			if (i == vitri)
			{
				gotoxy(12, 17 + i * 4); TextColor(160);
				n = strlen(Menubegin[i].c_str());
				for (int i = 0;i < n;i++)	cout << " ";
				gotoxy(12, 18 + i * 4);  cout << Menubegin[i];
				gotoxy(12, 19 + i * 4); for (int i = 0;i < n;i++)	cout << " ";
			}
			else
			{
				gotoxy(12, 17 + i * 4); TextColor(240);
				n = strlen(Menubegin[i].c_str());
				for (int i = 0;i < n;i++)	cout << " ";
				gotoxy(12, 18 + i * 4);  cout << Menubegin[i];
				gotoxy(12, 19 + i * 4); for (int i = 0;i < n;i++)	cout << " ";
			}
			TextColor(224);
		}
		c = GetKey();
		if (c == DOWN)
		{
			vitri += 1;
			if (vitri == 3) vitri = 0;
		}
		if (c == UP)
		{
			vitri -= 1;
			if (vitri == -1) vitri = 2;
		}
		if (c == ENTER)
			return vitri + 1;
	}
}

void HuongDan()
{
	KhungHCN(125, 27, 25, 5);
	gotoxy(130, 28); cout << "ESC: Back";
	gotoxy(130, 30); cout << "Enter: DOWN/Login";
	gotoxy(130, 29); cout << "Tab: UP/DOWN ";
	gotoxy(130, 31); cout << char(30) <<": UP";
	gotoxy(130, 32); cout << char(31) << ": DOWN";
}
void KhungDangNhap(int item)
{
	HuongDan();
	gotoxy(63, 11);
	if (item == 0) cout << "DANG NHAP - GIAO VIEN";
	else cout << "DANG NHAP - SINH VIEN";
	gotoxy(60, 9); for (int i = 20;i <= 50;i++) cout << char(196);
	gotoxy(60, 13); for (int i = 20;i <= 50;i++) cout << char(196);
	for (int i = 0;i < 3;i++)
	{
		gotoxy(60, 10 + i); cout << char(179);
		gotoxy(90, 10 + i); cout << char(179);
	}
	gotoxy(90, 9); cout << (char)191;
	gotoxy(60, 13); cout << (char)192;
	gotoxy(60, 9); cout << (char)218;
	gotoxy(90, 13); cout << (char)217;

	gotoxy(50, 16); cout << "Ten dang nhap: (Toi da 20 ky tu) ";
	KhungHCN(50, 17, 50, 2);

	gotoxy(50, 22); cout << "Mat khau: (Toi da 20 ky tu)";
	KhungHCN(50, 23, 50, 2);

}
void DangNhapThanhCong()
{
	TextColor(160); gotoxy(54, 28); for (int i = 0;i < 35;i++) cout << " ";
	gotoxy(54, 29); for (int i = 0;i < 35;i++) cout << " ";
	gotoxy(54, 30); for (int i = 0;i < 35;i++) cout << " ";
	gotoxy(57, 29); cout << "DANG NHAP THANH CONG ..";
	TextColor(224);
}
void DangNhapThatBai()
{
	TextColor(207); gotoxy(54, 28); for (int i = 0;i < 47;i++) cout << " ";
	gotoxy(54, 29); for (int i = 0;i < 47;i++) cout << " ";
	gotoxy(54, 30); for (int i = 0;i < 47;i++) cout << " ";
	gotoxy(57, 29); cout << "Ten tai khoan hoac mat khau khong dung..";
	TextColor(224);
}
ListSV* DangNhapSV(ListLop ds, List_GV dsgv)
{
ESCAPE: 
	int choice = MenuFirst();
	bool Login = false;
	
	ListSV* p = new ListSV;
	if (choice == 3)
	{
		gotoxy(0, 30);
		exit(0);
	}
	if (choice == 2)
	{
		while (Login == false)
		{
			bool user = false, pass = false;
			string User = "", Pass = "";
			system("cls");
			int i = 0, j = 0;
			char pre;
		USER:
			while (true)
			{
				BackGround();
				KhungDangNhap(1);
				gotoxy(55 + i++, 18);
				char c;
				c = GetKey();
				if (c == DOWN || c == '\t' || c == UP)
				{
					i--;
					goto PASS;
				}
				else if (c == LEFT || c == RIGHT) i--;
				//else if (c == DOWN && pass == true) i--;
				else if (c == BACKSPACE && User.size() == 0)
					i--;
				else if (c == BACKSPACE) {
					printf("\b ");
					i -= 2;
					if (i < 0) i = 0;
					gotoxy(55 + i, 18);
					if (!User.empty())
						User.erase(User.size() - 1);
				}
				else if (c == ESC)
				{
					goto ESCAPE;
				}
				else if (c != BACKSPACE && c != ENTER && User.size() == 20)
					i--;
				else if (c == ENTER)
				{
					i--;
					break;
				}
				else {
					User += c;
					cout << c;
				}
			}

		PASS:
			while (1) {
				gotoxy(55 + j++, 24);
				c = GetKey();
				if (c == ENTER) break;
				else if (c == UP || c == DOWN || c == '\t')
				{
					j--;
					goto USER;
				}
				else if (c == LEFT || c == RIGHT) j--;
				else if (c == BACKSPACE && Pass.size() == 0)	j--;
				else if (c == BACKSPACE)
				{
					printf("\b ");
					j -= 2;
					if (j < 0) j = 0;
					gotoxy(55 + j, 21);

					if (!Pass.empty())
						Pass.erase(Pass.size() - 1);
				}
				else if (c == ESC)
					goto ESCAPE;
				else if (c != BACKSPACE && c != ENTER && Pass.size() == 20)	
					j--;
				else
				{
					Pass += c;
					cout << "*";
				}
			}
			for (int i = 0;i < ds.n;i++)
				for (ListSV* k = ds.l[i].pHead; k != NULL;k = k->pNext)
				{
					if (strcmp(k->info.ID, User.c_str()) == 0 && strcmp(k->info.pass, Pass.c_str()) == 0)
					{
						Login = true;
						p = k;
						break;
					}
				}
			if (Login == true)
			{
				DangNhapThanhCong();
				Sleep(2000);
				break;
			}
			else
			{
				DangNhapThatBai();
				Sleep(2000);
			}
		}
	}
	if (choice == 1)
	{
		while (Login == false)
		{
			bool user = false, pass = false;
			string User = "", Pass = "";
			system("cls");
			int i = 0, j = 0;
			char pre;
		USERGV:
			while (true)
			{
				BackGround();
				KhungDangNhap(0);
				gotoxy(55 + i++, 18);
				char c;
				c = GetKey();
				if (c == DOWN || c == '\t' || c == UP )
				{
					i--;
					goto PASSGV;
				}
				else if (c == LEFT || c == RIGHT) i--;
				else if (c == BACKSPACE && User.size() == 0)
					i--;
				else if (c == BACKSPACE) 
				{
					printf("\b ");
					i -= 2;
					if (i < 0) i = 0;
					gotoxy(55 + i, 18);
					if (!User.empty())
						User.erase(User.size() - 1);
				}
				else if (c == ENTER)
				{
					user = true;
					break;
				}
				else if (c == ESC)
					goto ESCAPE;
				else if (c != BACKSPACE && c != ENTER && User.size() == 20)
					i--;
				else {
					User += c;
					cout << c;
				}
			}

		PASSGV:
			while (1) {
				gotoxy(55 + j++, 24);
				c = GetKey();
				if (c == ENTER) break;
				else if ((c == UP || c == DOWN || c == '\t'))
				{
					j--;
					goto USERGV;
				}
				else if (c == LEFT || c == RIGHT) j--;
				else if (c == BACKSPACE && Pass.size() == 0)
					j--;
				else if (c == BACKSPACE)
				{
					printf("\b ");
					j -= 2;
					if (j < 0) j = 0;
					gotoxy(55 + j, 21);

					if (!Pass.empty())
						Pass.erase(Pass.size() - 1);
				}
				else if (c == ESC)
				{
					goto ESCAPE;
				}
				else if (c != BACKSPACE && c != ENTER && Pass.size() == 20)
					j--;
				else
				{
					Pass += c;
					cout << "*";
				}
			}
			for (ListSV* k = dsgv.pHead; k != NULL; k = k->pNext)
			{
				if (strcmp(k->info.ID, User.c_str()) == 0 && strcmp(k->info.pass, Pass.c_str()) == 0)
				{
					Login = true;
					p = k;
					break;
				}
			}
			if (Login == true)
			{
				DangNhapThanhCong();
				Sleep(2000);
				break;
			}
			else
			{
				DangNhapThatBai();
				Sleep(2000);
			}
		}
	}
	return p;
}
char* TOUPPER(char* c)
{
	for (int i = 0;i < strlen(c);i++)
		toupper(c[i]);
	return c;
}
int AfterLoginSV(ListLop ds, ListSV*& p, List_GV dsgv)
{
	p = DangNhapSV(ds, dsgv);
	int vitri = 0;
	while (true)
	{
		system("cls");
		BackGround();
		_strupr_s(p->info.FirstName,50);
		_strupr_s(p->info.LastName,50);
		gotoxy(10, 34); cout << "Xin chao: " << p->info.FirstName << " " << p->info.LastName <<" - " << p->info.Class;
		int n = 0;
		for (int i = 0;i < 6;i++)
		{
			if (i == vitri)
			{
				gotoxy(12, 8 + i * 4); TextColor(160);
				n = strlen(AfterLogin[i].c_str());
				for (int i = 0;i < n;i++)	cout << " ";
				gotoxy(12, 9+ i * 4);  cout << AfterLogin[i];
				gotoxy(12, 10 + i * 4); for (int i = 0;i < n;i++)	cout << " ";
			}
			else
			{
				gotoxy(12, 8 + i * 4); TextColor(240);
				n = strlen(AfterLogin[i].c_str());
				for (int i = 0;i < n;i++)	cout << " ";
				gotoxy(12, 9 + i * 4);  cout << AfterLogin[i];
				gotoxy(12, 10 + i * 4); for (int i = 0;i < n;i++)	cout << " ";
			}
			TextColor(224);
		}
		c = GetKey();
		if (c == DOWN)
		{
			vitri += 1;
			if (vitri == 6) vitri = 0;
		}
		if (c == UP)
		{
			vitri -= 1;
			if (vitri == -1) vitri = 5;
		}
		if (c == ENTER)
			return vitri + 1;
	}
}
void MenuSV(ListLop ds, ListSV*& p, List_GV dsgv)
{
REPEAT:
	int choice = AfterLoginSV(ds,p,dsgv);
	while (choice !=6)
	{
		if (choice == 1) 
		{
			// Code Phan dang ky mon hoc
		}
		else if (choice == 2)
		{
			//Code phan xem danh sach mon hoc da dang ky
		}
		else if (choice == 3)
		{
			// code phan xoa mon hoc
		}
		else if (choice == 4)
		{
			// code phan xem danh sach mon hoc cua minh
		}
		else if (choice == 5)
		{
			goto REPEAT;
			break;
		}
	}
}