#include "console.h"
#include "Header.h"
#include "login.h"
#include "student.h"
#include "Semester.h"
#include "DKMon.h"
#include "course.h"
#include <cctype>
#include <string>

string Menubegin[3] = { "1. Nhan vien - giang vien", "2. Sinh vien","3. Thoat" };
string AfterLoginSV[6] = { "1. Dang ky mon hoc", "2. Xem danh sach mon hoc dang ky", "3. Xoa mon hoc da dang ky","4. Xem danh sach khoa hoc theo hoc", "5. Dang xuat" , "6. Thoat"};
string AfterLoginGV[6] = { "1. Tao nam hoc moi", "2. Tao ki moi", "3. Them sinh vien vao lop " ,"4. Dang Xuat", "5. Thoat","6. Tao mon hoc"};
string ThaoTac[4] = { "DANG NHAP THANH CONG..", "Ten tai khoan hoac mat khau khong dung..", "TAO THANH CONG", "TAO KHONG THANH CONG"};
void BackGround()
{
	TextColor(176);
	for (int j = 0; j < 6; j++)
		for (int i = 55; i <= 100; i++)
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
	gotoxy(x, y); for (int i = 0; i < width; i++) cout << char(196);
	for (int i = 0; i < length; i++)
	{
		gotoxy(x - 1, y + i + 1); cout << char(179);
		gotoxy(x + width, y + i + 1); cout << char(179);
	}
	gotoxy(x + width, y); cout << (char)191;
	gotoxy(x - 1, y + length + 1); cout << (char)192;
	gotoxy(x - 1, y); cout << (char)218;
	gotoxy(x + width, y + length + 1); cout << (char)217;
	gotoxy(x, y + length + 1); for (int i = 0; i < width; i++) cout << char(196);
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
		KhungHCN(138, 29, 10, 2);
		gotoxy(140, 30); cout << char(30) << ": UP";
		gotoxy(140, 31); cout << char(31) << ": DOWN";
		BackGround();
		InfoTeam();
		KhungHCN(8, 12, 22, 1);
		gotoxy(10, 13); cout << "DANG NHAP DANH CHO: ";
		int n = 0;
		for (int i = 0; i < 3; i++)
		{
			int k = strlen(Menubegin[i].c_str());
			if (k > n) n = k;
		}
		for (int i = 0;i < 3;i++)
		{
			if (i == vitri)
			{
				TextColor(160);
				gotoxy(12, 17 + i * 4); for (int i = 0;i <= n;i++)	cout << " ";
				gotoxy(12, 18 + i * 4); for (int i = 0;i <= n;i++)	cout << " ";
				gotoxy(12, 18 + i * 4);  cout << Menubegin[i];
				gotoxy(12, 19 + i * 4); for (int i = 0;i <= n;i++)	cout << " ";
			}
			else
			{
				TextColor(240);
				gotoxy(12, 17 + i * 4); for (int i = 0;i <= n;i++)	cout << " ";
				gotoxy(12, 18 + i * 4); for (int i = 0;i <= n;i++)	cout << " ";
				gotoxy(12, 18 + i * 4);  cout << Menubegin[i];
				gotoxy(12, 19 + i * 4); for (int i = 0;i <= n;i++)	cout << " ";
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
	TextColor(224);
	KhungHCN(125, 27, 25, 5);
	gotoxy(130, 28); cout << "ESC: Back";
	gotoxy(130, 30); cout << "Enter: DOWN/Login";
	gotoxy(130, 29); cout << "Tab: UP/DOWN ";
	gotoxy(130, 31); cout << char(30) << ": UP";
	gotoxy(130, 32); cout << char(31) << ": DOWN";
	TextColor(228);
}
void KhungDangNhap(int item)
{
	HuongDan();
	gotoxy(63, 11);
	if (item == 0) cout << "DANG NHAP - GIAO VIEN";
	else cout << "DANG NHAP - SINH VIEN";
	KhungHCN(60, 9, 30, 3);
	gotoxy(50, 16); cout << "Ten dang nhap: (Toi da 20 ky tu) ";
	KhungHCN(50, 17, 50, 2);

	gotoxy(50, 22); cout << "Mat khau: (Toi da 20 ky tu)";
	KhungHCN(50, 23, 50, 2);

}
void TaoThanhCong(int x, int y, string c)
{
	TextColor(160); 
	gotoxy(x, y); for (int i = 0;i <= c.size()+3;i++) cout << " ";
	gotoxy(x, y+1); for (int i = 0;i <= c.size()+3;i++) cout << " ";
	gotoxy(x, y+2); for (int i = 0;i <= c.size()+3;i++) cout << " ";
	gotoxy(x+3, y+1); cout << c;
	TextColor(224);
}
void TaoThatBai(int x, int y , string c)
{
	TextColor(207); 
	gotoxy(x, y); for (int i = 0;i <= c.size() +3 ;i++) cout << " ";
	gotoxy(x, y+1); for (int i = 0;i <= c.size() + 3;i++) cout << " ";
	gotoxy(x, y+2); for (int i = 0;i <= c.size()+3;i++) cout << " ";
	gotoxy(x+3, y+1); cout << c;
	TextColor(224);
}
void KhungTaoKiMoi()
{
	
	TextColor(224);
	gotoxy(75, 9); cout << "Ki: ";KhungHCN(100, 8, 10, 1); gotoxy(125, 9); cout << "Ex: 1,2,3";// khung nhap ki 
	gotoxy(75, 13); cout << "Nam hoc: "; KhungHCN(100, 12, 10, 1); gotoxy(125, 13); cout << "Ex: 2020, 2021";// nam
	gotoxy(75, 17); cout << "Cho sinh vien nam: "; KhungHCN(100, 16, 10, 1); gotoxy(125, 17); cout << "Ex: 1,2,3,4,5,6";// sinh vien nam ?
	gotoxy(75, 21); cout << "Ngay bat dau: "; KhungHCN(100, 20, 10, 1); gotoxy(111, 21); cout << "/"; KhungHCN(113, 20, 10, 1); gotoxy(124, 21); cout << "/"; KhungHCN(126, 20, 10, 1);
	gotoxy(75, 25); cout << "Ngay ket thuc: "; KhungHCN(100, 24, 10, 1); gotoxy(111, 25); cout << "/"; KhungHCN(113, 24, 10, 1); gotoxy(124, 25); cout << "/"; KhungHCN(126, 24, 10, 1);
	KhungHCN(130, 28, 30, 3);
	gotoxy(132, 30); cout << "ENTER: Fill Next-Create";
	TextColor(228);
}

int DangNhap(ListLop ds, ListGV dsgv, SinhVien& sv, GiaoVien& gv)
{
ESCAPE:
	int choice = MenuFirst();
	bool Login = false;
	//ListSV* p = new ListSV;
	if (choice == 3)
	{
		gotoxy(0, 30);
		exit(0);
	}
	if (choice == 2)
	{
		while (Login == false)
		{
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
			for (int i = 0; i < ds.n; i++)
				for (ListSV* k = ds.l[i].pHead; k != NULL; k = k->pNext)
				{
					if (strcmp(k->info.ID, User.c_str()) == 0 && strcmp(k->info.pass, Pass.c_str()) == 0)
					{
						Login = true;
						sv = k->info;
						break;
					}
				}
			if (Login == true)
			{
				TaoThanhCong(54, 28, ThaoTac[0]);
				Sleep(2000);
				break;
			}
			else
			{
				TaoThatBai(54, 28, ThaoTac[1]);
				Sleep(2000);
			}
		}
	}
	if (choice == 1)
	{
		while (Login == false)
		{
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
				if (c == DOWN || c == '\t' || c == UP)
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
			for (NodeGV* k = dsgv.pHead; k != NULL; k = k->pNext)
			{
				if (strcmp(k->info.ID, User.c_str()) == 0 && strcmp(k->info.pass, Pass.c_str()) == 0)
				{
					Login = true;
					gv = k->info;
					break;
				}
			}
			if (Login == true)
			{
				TaoThanhCong(54, 28, ThaoTac[0]);
				Sleep(2000);
				break;
			}
			else
			{
				TaoThatBai(54, 28, ThaoTac[1]);
				Sleep(2000);
			}
		}
	}
	return choice;
}

char* TOUPPER(char* c)
{
	for (int i = 0; i < strlen(c); i++)
		toupper(c[i]);
	return c;
}

void AfterLogin(ListLop ds, ListGV dsgv,ListCourses dsmon,  SinhVien& sv, GiaoVien& gv, int& choice)
{
HOME:
	choice = DangNhap(ds, dsgv , sv, gv);
	int vitri = 0;
	semester s;
	if (choice == 2) {
		while (true)
		{
REPEATSV:
			system("cls");
			BackGround();
			_strupr_s(sv.FirstName, 50);
			_strupr_s(sv.LastName, 50);
			gotoxy(10, 34); cout << "Xin chao: " << sv.FirstName << " " << sv.LastName << " - " << sv.Class;
			int n = 0;
			for (int i = 0; i < 6; i++)
			{
				int k = strlen(AfterLoginSV[i].c_str());
				if (k > n) n = k;
			}
			for (int i = 0;i < 6;i++)
			{
				if (i == vitri)
				{
					TextColor(160);
					gotoxy(12, 8 + i * 4); for (int i = 0;i <= n;i++)	cout << " ";
					gotoxy(12, 9 + i * 4); for (int i = 0;i <= n;i++)	cout << " ";
					gotoxy(12, 9 + i * 4); cout << AfterLoginSV[i];
					gotoxy(12, 10 + i * 4); for (int i = 0;i <= n;i++)	cout << " ";
				}
				else
				{
					TextColor(240);
					gotoxy(12, 8 + i * 4); for (int i = 0;i <= n;i++)	cout << " ";
					gotoxy(12, 9 + i * 4); for (int i = 0;i <= n;i++)	cout << " ";
					gotoxy(12, 9 + i * 4); cout << AfterLoginSV[i];
					gotoxy(12, 10 + i * 4); for (int i = 0;i <= n;i++)	cout << " ";
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
			{
				int c = vitri + 1;
				while (true)
				{
					if (c == 1)
					{
						gotoxy(60, 9);
						dangki(dsmon , sv);
						system("pause");
						goto REPEATSV;
					}
					else if (c == 2)
					{
						gotoxy(60, 9);
						view_Enrol_Course(sv);
						system("pause");
						goto REPEATSV;
					}
					else if (c == 3)
					{
						gotoxy(60, 9);
						eraser_erol_course(sv);
						system("pause");
						goto REPEATSV;
					}
					else if (c == 4)
					{
						gotoxy(60, 9);
						// code phan xem danh sach mon hoc cua minh
						view_Enrol_Course(sv);
						system("pause");
						goto REPEATSV;
					}
					else if (c == 5)
					{
						goto HOME;
					}
					else if (c == 6)
					{
						exit(1);
					}
				}
			}
		}
	}
	else if (choice == 1) // giao vien
	{
		while (true)
		{
REPEATGV:
			system("cls");
			BackGround();
			_strupr_s(gv.FirstName, 50);
			_strupr_s(gv.LastName, 50);
			gotoxy(10, 34); cout << "Xin chao Thay/Co: " << gv.FirstName << " " << gv.LastName;
			int n = 0;
			for (int i = 0; i < 5; i++)
			{
				int k = strlen(AfterLoginGV[i].c_str());
				if (k > n) n = k;
			}
			for (int i = 0;i < 6;i++)
			{
				if (i == vitri)
				{
					TextColor(160);
					gotoxy(12, 8 + i * 4); for (int i = 0;i <= n;i++)	cout << " ";
					gotoxy(12, 9 + i * 4); for (int i = 0;i <= n;i++)	cout << " ";
					gotoxy(12, 9 + i * 4);  cout << AfterLoginGV[i];
					gotoxy(12, 10 + i * 4); for (int i = 0;i <= n;i++)	cout << " ";
				}
				else
				{
					TextColor(240);
					gotoxy(12, 8 + i * 4); for (int i = 0;i <= n;i++)	cout << " ";
					gotoxy(12, 9 + i * 4); for (int i = 0;i <= n;i++)	cout << " ";
					gotoxy(12, 9 + i * 4);  cout << AfterLoginGV[i];
					gotoxy(12, 10 + i * 4); for (int i = 0;i <= n;i++)	cout << " ";
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
			{
				int c = vitri + 1;
				while (true)
				{
					if (c == 1) // tao mon hoc
					{
						gotoxy(60, 9);
						createNewCourse();
						gotoxy(70, 32); system("pause");
						goto REPEATGV;
					}
					else if (c == 2)
					{
						KhungTaoKiMoi();
						bool f = CreateSemester(s);
						if (f == true) TaoThanhCong(90, 28, ThaoTac[2]);
						else TaoThatBai(90, 28, ThaoTac[3]);
						gotoxy(70, 32); system("pause");
						goto REPEATGV;
					}
					else if (c == 3)
					{
						// code phan xoa mon hoc
						gotoxy(70, 32); system("pause");
						goto REPEATGV;
					}
					else if (c == 4)
					{
						goto HOME;
					}
					else if (c == 5)
					{
						exit(1);
					}
					else if (c == 6)
					{
						
						createNewCourse();
						gotoxy(70, 32); system("pause");
						goto REPEATGV;
					}
				}
			}
		}
	}
}
