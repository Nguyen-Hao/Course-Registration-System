#include "console.h"
#include "Header.h"
#include "student.h"
#include "Semester.h"
#include "staff.h"
#include "DKMon.h"
#include "SchoolYear.h"
#include "course.h"
#include <cctype>
#include <string>
#include<algorithm>

string Menubegin[] = { " 1. Giao vien", " 2. Hoc sinh"," 3. Thoat" };
string MenuSV[] = { " 1. Dang ky hoc phan", " 2. Ket qua DKHP", " 3. Xoa hoc phan da dang ky", " 4. Tra cuu ket qua hoc tap", " 5. Doi mat khau" ," 6. Dang xuat" , " 7. Thoat" };
string MenuGV1[] = { " 1. Tao nam hoc moi", " 2. Tao ki moi", " 3. Tao lop hoc moi" };
string MenuGV2[] = { " 1. Them sinh vien nam nhat vao lop", " 2. Tao phien DKHP", " 3. Them khoa hoc"," 4. Xuat file nhap DSSV tung lop", " 5. Xoa khoa hoc" ," 6. Cap nhat khoa hoc", " 7. Cap nhat diem trong khoa hoc" };
string MenuGV3[] = { " 1. Danh sach lop", " 2. Danh sach sinh vien trong lop", " 3. Danh sach khoa hoc"," 4. Danh sach SV trong khoa hoc", " 5. Xem bang diem trong khoa hoc", " 6. Xem bang diem trong lop"," 7. Xuat CSV File bang diem SV trong khoa hoc de nhap diem"};
string MenuGV[] = { " 1. Tao moi", " 2. Nhap thong tin", " 3. Tra cuu " ," 4. Doi mat khau", " 5. Dang xuat", " 6.Thoat"};

void Information()
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

void Frames(int x, int y, int width, int length)
{
	int i;
	gotoxy(x, y); for (i = 0; i < width; ++i) cout << char(196);
	for (i = 0; i < length; ++i)
	{
		gotoxy(x - 1, y + i + 1); cout << char(179);
		gotoxy(x + width, y + i + 1); cout << char(179);
	}
	gotoxy(x + width, y); cout << (char)191;
	gotoxy(x - 1, y + length + 1); cout << (char)192;
	gotoxy(x - 1, y); cout << (char)218;
	gotoxy(x + width, y + length + 1); cout << (char)217;
	gotoxy(x, y + length + 1); for (i = 0; i < width; ++i) cout << char(196);
}
void CleanForm(int x, int y, int width, int length)
{
	for (int i = 0; i <= length + 1; i++)
	{
		gotoxy(x - 1, y + i);
		for (int j = 0; j <= width + 1; j++)
			cout << " ";
	}
}
void Team()
{
	TextColor(228);
	Frames(105, 12, 55, 8);
	gotoxy(110, 14); cout << "Giang vien huong dan: ThS. Nguyen Le Hoang Dung";
	gotoxy(110, 15); cout << "SINH VIEN THUC HIEN: ";
	gotoxy(113, 16); cout << "1. To Tran Son Ba"; gotoxy(130, 16); cout << " - 20120431";
	gotoxy(113, 17); cout << "2. Le Cong Dat"; gotoxy(130, 17); cout << " - 20120454";
	gotoxy(113, 18); cout << "3. Nguyen Van Hao"; gotoxy(130, 18); cout << " - 20120470";
	gotoxy(113, 19); cout << "4. Le Kim Hieu"; gotoxy(130, 19); cout << " - 20120474";
}
char c, d;
int MenuHeader()
{
	int vitri = 0,n,k,i,j;
	while (true)
	{
		system("cls");
		TextColor(224);
		Frames(138, 29, 10, 2);
		gotoxy(140, 30); cout << char(30) << ": UP";
		gotoxy(140, 31); cout << char(31) << ": DOWN";
		Information();
		Team();
		Frames(8, 12, 22, 1);
		gotoxy(10, 13); cout << "DANG NHAP DANH CHO: ";
		n = 0;
		for (i = 0; i < 3; ++i)
		{
			k = Menubegin[i].length();
			if (k > n) n = k;
		}
		for (i = 0; i < 3; ++i)
		{
			if (i == vitri)
			{
				TextColor(160);
				gotoxy(12, 17 + i * 4); for (j = 0; j <= n; ++j)	cout << " ";
				gotoxy(12, 18 + i * 4); for (j = 0; j <= n; ++j)	cout << " ";
				gotoxy(12, 18 + i * 4);  cout << Menubegin[i];
				gotoxy(12, 19 + i * 4); for (j = 0; j <= n; ++j)	cout << " ";
			}
			else
			{
				TextColor(240);
				gotoxy(12, 17 + i * 4); for (int j = 0; j <= n; j++)	cout << " ";
				gotoxy(12, 18 + i * 4); for (int j = 0; j <= n; j++)	cout << " ";
				gotoxy(12, 18 + i * 4);  cout << Menubegin[i];
				gotoxy(12, 19 + i * 4); for (int j = 0; j <= n; j++)	cout << " ";
			}
			TextColor(224);
		}
		c = GetKey();
		switch (c)
		{
		case DOWN:
				vitri += 1;
				if (vitri == 3) vitri = 0;
				break;
		case UP:
				vitri -= 1;
				if (vitri == -1) vitri = 2;
				break;
		case ENTER:
				return vitri + 1;
				break;
		}
	}
}
void Instruction()
{
	TextColor(224);
	Frames(125, 27, 25, 5);
	gotoxy(130, 28); cout << "ESC: Back";
	gotoxy(130, 30); cout << "Enter: DOWN/Login";
	gotoxy(130, 29); cout << "Tab: UP/DOWN ";
	gotoxy(130, 31); cout << char(30) << ": UP";
	gotoxy(130, 32); cout << char(31) << ": DOWN";
	TextColor(228);
}
void SignInFrames(int item)
{
	Instruction();
	gotoxy(63, 11);
	if (item == 0) cout << "DANG NHAP - GIAO VIEN";
	else cout << "DANG NHAP - SINH VIEN";
	Frames(60, 9, 30, 3);
	gotoxy(50, 16); cout << "Ten dang nhap: (Toi da 20 ky tu) ";
	Frames(50, 17, 50, 2);

	gotoxy(50, 22); cout << "Mat khau: (Toi da 20 ky tu)";
	Frames(50, 23, 50, 2);

}
int EffectAgree(int x, int y, string c)
{
	string yes = "   Co  ";
	string no = " Khong ";
	int yessize = yes.size() + 3, csize = c.size() + 3, i;
	TextColor(240);
	gotoxy(x, y); for (i = 0; i <= csize; ++i) cout << " ";
	gotoxy(x, y + 1); for (i = 0; i <= csize; ++i) cout << " ";
	gotoxy(x, y + 2); for (i = 0; i <= csize; ++i) cout << " ";
	gotoxy(x + 3, y + 1); cout << c;
	gotoxy(x, y + 3); for (i = 0; i <= csize; ++i) cout << " ";
	gotoxy(x, y + 4); for (i = 0; i <= csize ; ++i) cout << " ";
	gotoxy(x, y + 5); for (i = 0; i <= csize ; ++i) cout << " ";
	gotoxy(x, y + 6); for (i = 0; i <= csize ; ++i) cout << " ";
	gotoxy(x, y + 7); for (i = 0; i <= csize ; ++i) cout << " ";
	gotoxy(x, y + 8); for (i = 0; i <= csize ; ++i) cout << " ";
	gotoxy(x, y + 9); for (i = 0; i <= csize ; ++i) cout << " ";
	//
	int a = (c.size() - yes.size()) / 2;
	TextColor(160);
	gotoxy(x + a - 3, y + 5); for (i = 0; i < yessize; ++i) cout << " ";
	gotoxy(x + a - 3, y + 6); for (i = 0; i < yessize; ++i) cout << " ";
	gotoxy(x + a - 3, y + 7); for (i = 0; i < yessize; ++i) cout << " ";
	gotoxy(x + a - 3, y + 6); cout << yes;
	//
	TextColor(224);
	gotoxy(x + a + yessize, y + 5); for (i = 0; i < yessize; ++i) cout << " ";
	gotoxy(x + a + yessize, y + 6); for (i = 0; i < yessize; ++i) cout << " ";
	gotoxy(x + a + yessize, y + 7); for (i = 0; i < yessize; ++i) cout << " ";
	gotoxy(x + a + yessize, y + 6); cout << no;
	int vitri = 0;
	char key;
	while (true)
	{
		key = GetKey();
		if (key == LEFT)
		{
			vitri += 1;
			if (vitri == 2) vitri = 0;
		}
		if (key == RIGHT)
		{
			vitri -= 1;
			if (vitri == -1) vitri = 1;
		}
		if (vitri == 0)
		{
			TextColor(160);
			gotoxy(x + a - 3, y + 5); for (i = 0; i < yessize; ++i) cout << " ";
			gotoxy(x + a - 3, y + 6); for (i = 0; i < yessize; ++i) cout << " ";
			gotoxy(x + a - 3, y + 7); for (i = 0; i < yessize; ++i) cout << " ";
			gotoxy(x + a - 3, y + 6); cout << yes;
			//
			TextColor(224);
			gotoxy(x + a + yessize, y + 5); for (i = 0; i < yessize; ++i) cout << " ";
			gotoxy(x + a + yessize, y + 6); for (i = 0; i < yessize ; ++i) cout << " ";
			gotoxy(x + a + yessize, y + 7); for (i = 0; i < yessize ; ++i) cout << " ";
			gotoxy(x + a + yessize+2, y + 6); cout << no;
		}
		else if (vitri == 1)
		{
			TextColor(224);
			gotoxy(x + a - 3, y + 5); for (i = 0; i < yessize; ++i) cout << " ";
			gotoxy(x + a - 3, y + 6); for (i = 0; i < yessize; ++i) cout << " ";
			gotoxy(x + a - 3, y + 7); for (i = 0; i < yessize; ++i) cout << " ";
			gotoxy(x + a - 3, y + 6); cout << yes;
			//
			TextColor(160);
			gotoxy(x + a + yessize, y + 5); for (i = 0; i < yessize ; i++) cout << " ";
			gotoxy(x + a + yessize, y + 6); for (i = 0; i < yessize ; i++) cout << " ";
			gotoxy(x + a + yessize, y + 7); for (i = 0; i < yessize ; i++) cout << " ";
			gotoxy(x + a + yessize, y + 6); cout << no;
		}
		if (key == ENTER && vitri == 1)
		{
			TextColor(224);
			return 0;
		}
		else if (key == ENTER && vitri == 0)
		{
			TextColor(224);
			return 1;
		}

	}
}
void ClearEffectAgree(int x, int y, string c)
{
	TextColor(224);
	int i, csize = c.size() + 3;
	gotoxy(x, y); for (i = 0; i <= csize; ++i) cout << " ";
	gotoxy(x, y + 1); for (i = 0; i <= csize; ++i) cout << " ";
	gotoxy(x, y + 2); for (i = 0; i <= csize; ++i) cout << " ";
	gotoxy(x, y + 3); for (i = 0; i <= csize; ++i) cout << " ";
	gotoxy(x, y + 4); for (i = 0; i <= csize; ++i) cout << " ";
	gotoxy(x, y + 5); for (i = 0; i <= csize; ++i) cout << " ";
	gotoxy(x, y + 6); for (i = 0; i <= csize; ++i) cout << " ";
	gotoxy(x, y + 7); for (i = 0; i <= csize; ++i) cout << " ";
	gotoxy(x, y + 8); for (i = 0; i <= csize; ++i) cout << " ";
	gotoxy(x, y + 9); for (i = 0; i <= csize; ++i) cout << " ";
}
void EffectSuccess(int x, int y, string c)
{
	TextColor(160);
	int i, csize = c.size() + 3;
	gotoxy(x, y); for (i = 0; i <= csize; ++i) cout << " ";
	gotoxy(x, y + 1); for (i = 0; i <= csize ; ++i) cout << " ";
	gotoxy(x, y + 2); for (i = 0; i <= csize; ++i) cout << " ";
	gotoxy(x + 2, y + 1); cout << c;
	TextColor(224);
}
void EffectFailed(int x, int y, string c)
{
	TextColor(207);
	int i, csize = c.size() + 3;
	gotoxy(x, y); for (i = 0; i <= csize; ++i) cout << " ";
	gotoxy(x, y + 1); for (i = 0; i <= csize; ++i) cout << " ";
	gotoxy(x, y + 2); for (i = 0; i <= csize; ++i) cout << " ";
	gotoxy(x + 2, y + 1); cout << c;
	TextColor(224);
}
void cleanEffectFailed(int x, int y, string c)
{
	TextColor(224);
	for (int i = 0; i < 4; i++)
	{
		gotoxy(x, y + i);
		for (int j = 0; j < c.size() + 4; j++) cout << " ";
	}
}
void CreateSemesterForm()
{
	TextColor(224);
	gotoxy(75, 9); cout << "Ki: "; Frames(100, 8, 10, 1); // khung nhap ki 
	gotoxy(75, 13); cout << "Nam hoc: "; Frames(100, 12, 15, 1);// nam
	gotoxy(75, 17); cout << "Ngay bat dau: "; Frames(100, 16, 10, 1); gotoxy(111, 17); cout << "/"; Frames(113, 16, 10, 1); gotoxy(124, 17); cout << "/"; Frames(126, 16, 10, 1);
	gotoxy(75, 21); cout << "Ngay ket thuc: "; Frames(100, 20, 10, 1); gotoxy(111, 21); cout << "/"; Frames(113, 20, 10, 1); gotoxy(124, 21); cout << "/"; Frames(126, 20, 10, 1);
	TextColor(228);
}
void CreateClassForm()
{
	TextColor(224);
	gotoxy(75, 9); cout << "Ma lop: "; Frames(100, 8, 15, 1);
	gotoxy(75, 13); cout << "Ten lop: "; Frames(100, 12, 30, 1);
	gotoxy(75, 17); cout << "Khoa: "; Frames(100, 16, 10, 1);
	TextColor(228);
}
void CreateSignInForm()
{
	TextColor(224);
	gotoxy(80, 9); cout << "Nhap mat khau cu: ";
	Frames(80, 10, 50, 1);
	gotoxy(80, 14); cout << "Nhap mat khau moi:";
	Frames(80, 15, 50, 1);
	gotoxy(80, 19); cout << "Nhap lai mat khau moi ";
	Frames(80, 20, 50, 1);
}

int SignIn(ListLop ds, ListGV dsgv, SinhVien& sv, GiaoVien& gv)
{
ESCAPE:
	int choice = MenuHeader();
	bool Login = false;
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
			char pre = NULL;
		USER:
			while (true)
			{
				Information();
				SignInFrames(1);
				gotoxy(55 + i++, 18);
				char c;
				c = GetKey();
				if (c == DOWN || c == '\t' || c == UP)
				{
					i--;
					goto PASS;
				}
				else if (c == LEFT || c == RIGHT) i--;
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
					if (k->info.ID == User && k->info.pass == Pass)
					{
						Login = true;
						sv = k->info;
						break;
					}
				}
			if (Login == true)
			{
				EffectSuccess(54, 28, "Dang nhap thanh cong ");
				Sleep(2000);
				break;
			}
			else
			{
				EffectFailed(54, 28, "Ten tai khoan hoac mat khau khong dung ");
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
			char pre = NULL;
		USERGV:
			while (true)
			{
				Information();
				SignInFrames(0);
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
					i--;
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
					--j;
				else
				{
					Pass += c;
					cout << "*";
				}
			}
			for (NodeGV* k = dsgv.pHead; k != NULL; k = k->pNext)
			{
				if (k->info.ID == User && k->info.pass == Pass)
				{
					Login = true;
					gv = k->info;
					break;
				}
			}
			if (Login == true)
			{
				EffectSuccess(54, 28, "Dang nhap thanh cong ");
				Sleep(2000);
				break;
			}
			else
			{
				EffectFailed(54, 28, "Ten tai khoan hoac mat khau khong dung ");
				Sleep(2000);
			}
		}
	}
	return choice;
}

void ChangePasswordStudent(SinhVien& sv, ListLop& dsl, string newpass, const SchoolYear& Y)
{
	sv.pass = newpass;
	for (int i = 0; i < dsl.n; ++i)
	{
		for (ListSV* p = dsl.l[i].pHead; p != NULL; p = p->pNext)
		{
			if (sv.ID == p->info.ID)
			{
				p->info.pass = sv.pass;
				break;
			}
		}
	}
	WriteFileStudent(dsl, Y);
}
bool MenuChangePasswordStudent(SinhVien& sv, ListLop& dsl, string& eff, const SchoolYear& Y)
{
	CreateSignInForm();
	string oldpass = "", newpass = "", newpassAgain = "";
	int i = 0, j = 0;
	char pre = NULL;
	OLDPASS:
		j = 0;
		while (1) {
			gotoxy(83 + j++, 11);
			c = GetKey();
			if (c == ENTER) break;
			else if (c == UP)
			{
				j--;
				goto NEWPASSAGAIN;
			}
			else if (c == DOWN)
			{
				j--;
				goto NEWPASS;
			}
			else if (c == LEFT || c == RIGHT) j--;
			else if (c == BACKSPACE && oldpass.size() == 0)
				j--;
			else if (c == BACKSPACE)
			{
				printf("\b ");
				j -= 2;
				if (j < 0) j = 0;
				gotoxy(83 + j, 11);

				if (!oldpass.empty())
					oldpass.erase(oldpass.size() - 1);
			}
			else if (c == ESC)
			{
				eff = "Thoat";
				return false;
			}
			else if (c != BACKSPACE && c != ENTER && oldpass.size() == 20)
				--j;
			else
			{
				oldpass += c;
				cout << "*";
			}
		}
	NEWPASS:
		j = 0;
		while (1) {
			gotoxy(83 + j++, 16);
			c = GetKey();
			if (c == ENTER) break;
			else if (c == UP)
			{
				j--;
				goto OLDPASS;
			}
			else if (c == DOWN)
			{
				j--;
				goto NEWPASSAGAIN;
			}
			else if (c == LEFT || c == RIGHT) j--;
			else if (c == BACKSPACE && newpass.size() == 0)
				j--;
			else if (c == BACKSPACE)
			{
				printf("\b ");
				j -= 2;
				if (j < 0) j = 0;
				gotoxy(83 + j, 16);

				if (!newpass.empty())
					newpass.erase(newpass.size() - 1);
			}
			else if (c == ESC)
			{
				eff = "Thoat";
				return false;
			}
			else if (c != BACKSPACE && c != ENTER && newpass.size() == 20)
				--j;
			else
			{
				newpass += c;
				cout << "*";
			}
		}
	NEWPASSAGAIN:
		j = 0;
		while (1) {
			gotoxy(83 + j++, 21);
			c = GetKey();
			if (c == ENTER) break;
			else if (c == UP)
			{
				j--;
				goto NEWPASS;
			}
			else if (c == DOWN)
			{
				j--;
				goto OLDPASS;
			}
			else if (c == LEFT || c == RIGHT) j--;
			else if (c == BACKSPACE && newpassAgain.size() == 0)
				j--;
			else if (c == BACKSPACE)
			{
				printf("\b ");
				j -= 2;
				if (j < 0) j = 0;
				gotoxy(83 + j, 21);

				if (!newpassAgain.empty())
					newpassAgain.erase(newpassAgain.size() - 1);
			}
			else if (c == ESC)
			{
				eff = "Thoat";
				return false;
			}
			else if (c != BACKSPACE && c != ENTER && newpassAgain.size() == 20)
				--j;
			else
			{
				newpassAgain += c;
				cout << "*";
			}
		}
	if (newpass.empty())
	{
		eff =  "Mat Khau khong duoc de trong!" ;
	}
	else if (sv.pass != oldpass)
	{
		eff = "Mat Khau sai!";
		return false;
	}
	else if (newpass != newpassAgain)
	{
		eff = "Mat Khau khong khop!";
	}
	else
	{
		ChangePasswordStudent(sv, dsl, newpass, Y);
		eff =  "Doi mat khau thanh cong!";
		return true;
	}
	return false;
}
void ChangePasswordManager(GiaoVien& gv, ListGV& dsgv, string newpass, const SchoolYear& Y)
{
	gv.pass = newpass;
	for (NodeGV* p = dsgv.pHead; p != NULL; p = p->pNext)
	{
		if (gv.ID == p->info.ID)
		{
			p->info.pass = gv.pass;
			break;
		}
	}
	writeFileTeacher(dsgv, Y);
	writeFileCSVTeacher(dsgv);
}
void FormMenu()
{
	Frames(138, 29, 18, 4);
	gotoxy(140, 30); cout << "ESC : QUAY LAI";
	gotoxy(140, 31); cout << "ENTER : CHON";
	gotoxy(140, 32); cout << char(30) << ": LEN";
	gotoxy(140, 33); cout << char(31) << ": XUONG";
}
void FormMenu2()
{
	Frames(128, 29, 25, 4);
	gotoxy(130, 30); cout << "ESC : QUAY LAI";
	gotoxy(130, 31); cout << "ENTER : NHAP DU LIEU";
	gotoxy(130, 32); cout << char(17) << ": SANG TRAI";
	gotoxy(130, 33); cout << char(16) << ": SANG PHAI";
}
void FormMenu3()
{
	Frames(128, 31, 25, 3);
	gotoxy(130, 32); cout << "ESC : QUAY LAI";
	gotoxy(130, 33); cout << char(17) << ": SANG TRAI";
	gotoxy(130, 34); cout << char(16) << ": SANG PHAI";
}
bool MenuChangePasswordManager(GiaoVien& gv, ListGV& dsgv, string& e, const SchoolYear& Y)
{
	CreateSignInForm();
	string oldpass = "", newpass = "", newpassAgain = "";
	int i = 0, j = 0;
	char pre = NULL;
	OLDPASS:
		j = 0;
		while (1) {
			gotoxy(83 + j++, 11);
			c = GetKey();
			if (c == ENTER) break;
			else if (c == UP)
			{
				j--;
				goto NEWPASSAGAIN;
			}
			else if (c == DOWN)
			{
				j--;
				goto NEWPASS;
			}
			else if (c == LEFT || c == RIGHT) j--;
			else if (c == BACKSPACE && oldpass.size() == 0)
				j--;
			else if (c == BACKSPACE)
			{
				printf("\b ");
				j -= 2;
				if (j < 0) j = 0;
				gotoxy(83 + j, 11);

				if (!oldpass.empty())
					oldpass.erase(oldpass.size() - 1);
			}
			else if (c == ESC)
			{
				e = "Thoat";
				return false;
			}
			else if (c != BACKSPACE && c != ENTER && oldpass.size() == 20)
				--j;
			else
			{
				oldpass += c;
				cout << "*";
			}
		}
	NEWPASS:
		j = 0;
		while (1) {
			gotoxy(83 + j++, 16);
			c = GetKey();
			if (c == ENTER) break;
			else if (c == UP)
			{
				j--;
				goto OLDPASS;
			}
			else if (c == DOWN)
			{
				j--;
				goto NEWPASSAGAIN;
			}
			else if (c == LEFT || c == RIGHT) j--;
			else if (c == BACKSPACE && newpass.size() == 0)
				j--;
			else if (c == BACKSPACE)
			{
				printf("\b ");
				j -= 2;
				if (j < 0) j = 0;
				gotoxy(83 + j, 16);

				if (!newpass.empty())
					newpass.erase(newpass.size() - 1);
			}
			else if (c == ESC)
			{
				e = "Thoat";
				return false;
			}
			else if (c != BACKSPACE && c != ENTER && newpass.size() == 20)
				--j;
			else
			{
				newpass += c;
				cout << "*";
			}
		}
	NEWPASSAGAIN:
		j = 0;
		while (1) {
			gotoxy(83 + j++, 21);
			c = GetKey();
			if (c == ENTER) break;
			else if (c == UP)
			{
				j--;
				goto NEWPASS;
			}
			else if (c == DOWN)
			{
				j--;
				goto OLDPASS;
			}
			else if (c == LEFT || c == RIGHT) j--;
			else if (c == BACKSPACE && newpassAgain.size() == 0)
				j--;
			else if (c == BACKSPACE)
			{
				printf("\b ");
				j -= 2;
				if (j < 0) j = 0;
				gotoxy(83 + j, 21);

				if (!newpassAgain.empty())
					newpassAgain.erase(newpassAgain.size() - 1);
			}
			else if (c == ESC)
			{
				e = "Thoat";
				return false;
			}
			else if (c != BACKSPACE && c != ENTER && newpassAgain.size() == 20)
				--j;
			else
			{
				newpassAgain += c;
				cout << "*";
			}
		}
	if (newpass.empty())
	{
		e = "Mat Khau khong duoc de trong ";
	}
	else if (gv.pass != oldpass)
	{
		e = "Mat Khau sai ";
	}
	else if (newpass != newpassAgain)
	{
		e = "Mat Khau khong khop ";
	}
	else
	{
		ChangePasswordManager(gv, dsgv, newpass, Y);
		e = "Doi mat khau thanh cong ";
		return true;
	}
	return false;
}
void MenuChildren(string s[], int& vitri, int size)
{
	int n = 0,i,k,j;
	for (i = 0; i < size; ++i)
	{
		k = s[i].length();
		if (k > n) n = k;
	}
	for (i = 0; i < size; ++i)
	{
		if (i == vitri)
		{
			TextColor(160);
			gotoxy(26, 8 + i * 4); for (j = 0; j <= n; ++j)	cout << " ";
			gotoxy(26, 9 + i * 4); for (j = 0; j <= n; ++j)	cout << " ";
			gotoxy(26, 9 + i * 4); cout << s[i];
			gotoxy(26, 10 + i * 4); for (j = 0; j <= n; ++j)	cout << " ";
		}
		else
		{
			TextColor(240);
			gotoxy(26, 8 + i * 4); for (j = 0; j <= n; ++j)	cout << " ";
			gotoxy(26, 9 + i * 4); for (j = 0; j <= n; ++j)	cout << " ";
			gotoxy(26, 9 + i * 4); cout << s[i];
			gotoxy(26, 10 + i * 4); for (j = 0; j <= n; ++j)	cout << " ";
		}
		TextColor(224);
	}
}
void Menu(ListLop ds, ListGV dsgv, ListCourses dsmon, SinhVien& sv, GiaoVien& gv, int& choice, int& se, SchoolYear& Y, listSemester&l)
{
HOME:
	string ef;
	bool fl;
	choice = SignIn(ds, dsgv, sv, gv);
	int vitri = 0,n,i,k,j;
	semester s;
	switch (choice)
	{
		case 2:
			while (true)
			{
			REPEATSV:
				system("cls");
				FormMenu();
				transform(sv.FirstName.begin(), sv.FirstName.end(), sv.FirstName.begin(), toupper);
				transform(sv.LastName.begin(), sv.LastName.end(), sv.LastName.begin(), toupper);
				gotoxy(4, 5); 
				se == -1 ?
					cout << "Ki: " << '_' << " - Nam hoc: " << Y.NameSchoolYear
					: cout << "Ki: " << se << " - Nam hoc: " << Y.NameSchoolYear;
				gotoxy(4, 6); cout << "Xin chao : " << sv.FirstName << " " << sv.LastName << " - " << sv.Class;
				n = 0;
				for (i = 0; i < 7; ++i)
				{
					k = MenuSV[i].length();
					if (k > n) n = k;
				}
				for (i = 0; i < 7; ++i)
				{
					if (i == vitri)
					{
						TextColor(160);
						gotoxy(4, 8 + i * 4); for (j = 0; j <= n; ++j)	cout << " ";
						gotoxy(4, 9 + i * 4); for (j = 0; j <= n; ++j)	cout << " ";
						gotoxy(4, 9 + i * 4); cout << MenuSV[i];
						gotoxy(4, 10 + i * 4); for (j = 0; j <= n; ++j)	cout << " ";
					}
					else
					{
						TextColor(240);
						gotoxy(4, 8 + i * 4); for (j = 0; j <= n; ++j)	cout << " ";
						gotoxy(4, 9 + i * 4); for (j = 0; j <= n; ++j)	cout << " ";
						gotoxy(4, 9 + i * 4); cout << MenuSV[i];
						gotoxy(4, 10 + i * 4); for (j = 0; j <= n; ++j)	cout << " ";
					}
					TextColor(224);
				}
				c = GetKey();
				switch (c)
				{
				case DOWN:
						vitri += 1;
						if (vitri == 7) vitri = 0;
						break;
				case UP:
						vitri -= 1;
						if (vitri == -1) vitri = 6;
						break;
				case ENTER:
						int c = vitri + 1;
						while (true)
						{
							string s;
							bool f;
							switch (c)
							{
							case 1: 
									
									if (dsmon.head == NULL) {
									EffectFailed(80,13,"Chua co khoa hoc nao");
									}
									else {
										gotoxy(60, 9);
										CoursesRegistration(dsmon, sv, se, Y, s, f);
										if (f) {
											EffectSuccess(55, 30, s); 
										}
										else {
											EffectFailed(80, 13, s);
										}
									}
									gotoxy(40, 34);
									system("pause");
									goto REPEATSV;
									break;
							
							case 2: {
								gotoxy(60, 9);
								ViewEnrollCourses(dsmon, sv, se, s, f, Y);
								if (!f) EffectFailed(80, 13, s);
								gotoxy(60, 32);
								system("pause");
								goto REPEATSV;
								break;
							}
							
							case 3: {
								gotoxy(60, 9);
								EraserEnrollCourses(sv, dsmon,s, f, se, Y);
								if (f) EffectSuccess(50, 25, "Xoa thanh cong ");
								else EffectFailed(80, 13, s);
								gotoxy(60, 32);
								system("pause");
								goto REPEATSV;
								break;
							}
							case 4: {
								viewScoreBoardOfStudent(sv, dsmon, s, f, se, Y);
								if (!f) EffectFailed(80, 13, s);
								gotoxy(60, 32);
								system("pause");
								goto REPEATSV;
								break;
							}
							case 5: {
								bool Check = MenuChangePasswordStudent(sv, ds, s, Y);
								if (Check) EffectSuccess(80, 26, s);
								else EffectFailed(80, 26, s);
								gotoxy(75, 30); system("pause");
								goto REPEATSV;
								break;
							}
							case 6:
									goto HOME;
									break;
							case 7:
									exit(1);
									break;
							}
						break;
					}
				}
			}
			break;
		case 1:
			while (true)
			{
			REPEATGV:
				system("cls");
				FormMenu();
				transform(gv.FirstName.begin(), gv.FirstName.end(), gv.FirstName.begin(), toupper);
				transform(gv.LastName.begin(), gv.LastName.end(), gv.LastName.begin(), toupper);
				gotoxy(4, 5);
				/*
				if (se == -1) {
					cout << "Ki: " << '_' << " - Nam hoc: " << Y.NameSchoolYear << "   ";
					TextColor(228);
					if (se == -1) cout << "(Can tao ki moi truoc khi su dung)";
					TextColor(224);
				}*/
				cout << "Ki: " << se << " - Nam hoc: " << Y.NameSchoolYear;
				gotoxy(4, 6); cout << "Xin chao Thay/Co: " << gv.FirstName << " " << gv.LastName;
				int n = 0, i, k, j;
				for (i = 0; i < 6; ++i)
				{
					k = MenuGV[i].length();
					if (k > n) n = k;
				}
				for (i = 0; i < 6; i++)
				{
					if (i == vitri)
					{
						TextColor(160);
						gotoxy(4, 8 + i * 4); for (j = 0; j <= n; ++j)	cout << " ";
						gotoxy(4, 9 + i * 4); for (j = 0; j <= n; ++j)	cout << " ";
						gotoxy(4, 9 + i * 4);  cout << MenuGV[i];
						gotoxy(4, 10 + i * 4); for (j = 0; j <= n; ++j)	cout << " ";
					}
					else
					{
						TextColor(240);
						gotoxy(4, 8 + i * 4); for (j=0; j <= n; ++j)	cout << " ";
						gotoxy(4, 9 + i * 4); for (j = 0; j <= n; ++j)	cout << " ";
						gotoxy(4, 9 + i * 4);  cout << MenuGV[i];
						gotoxy(4, 10 + i * 4); for (j = 0; j <= n; ++j)	cout << " ";
					}
					TextColor(224);
				}
				c = GetKey();
				switch (c)
				{
				case DOWN:
						vitri += 1;
						if (vitri == 6) vitri = 0;
						break;
				case UP:
						vitri -= 1;
						if (vitri == -1) vitri = 5;
						break;
				case ENTER:
						int c = vitri + 1;
						int vitricon;
						switch (c)
						{
						case 1:
								vitricon = 0;
								while (true)
								{
									MenuChildren(MenuGV1, vitricon, 3);
									d = GetKey();
									switch (d)
									{
									case DOWN:
										vitricon += 1;
										if (vitricon == 3) vitricon = 0;
										break;
									case UP:
										vitricon -= 1;
										if (vitricon == -1) vitricon = 2;
										break;
									case ESC:
										goto REPEATGV;
										break;
									case ENTER:
										int choice;
										string c;
										switch (vitricon)
										{
										case 0:
											c = " Ban co muon tao nam hoc moi khong? ";
											choice = EffectAgree(70, 10, c);
											if (choice == 1)
											{
												CleanForm(70, 10, 50, 8);
												CreateSchoolYear(Y);
												Y = SchoolYearPresent("SchoolYear.txt");
												InitListSemester(l);
												readListSemester(l, Y);
												se = getSemester(l, Y);
											}
											gotoxy(70, 32); system("pause");
											goto REPEATGV;
											break;
										case 1:
											c = " Ban co muon tao hoc ki moi khong? ";
											choice = EffectAgree(70, 10, c);
											if (choice == 1)
											{
												CleanForm(138, 29, 18, 4);
												ClearEffectAgree(70, 10, c);
												CreateSemesterForm();
												bool f = CreateSemester(s, Y, l);
												if (f == true) {
													EffectSuccess(90, 28, "Tao thanh cong ");
													InitListSemester(l);
													readListSemester(l, Y);
													se = getSemester(l, Y);
												}
												else EffectFailed(90, 28, "Tao that bai ");
											}
											gotoxy(70, 32); system("pause");
											goto REPEATGV;
											break;
										case 2:
											c = " Ban co muon tao lop hoc moi khong? ";
											choice = EffectAgree(70, 10, c);
											if (choice == 1)
											{
												int z;
												ClearEffectAgree(70, 10, c);
												CreateClassForm();
												CreateNewClass(ds, Y, z);
												if(z==1)
												EffectSuccess(90, 28, "Tao thanh cong ");
												else EffectFailed(90, 28, "Tao that bai ");
											}
											gotoxy(70, 32); system("pause");
											goto REPEATGV;
											break;
										}
										break;
									}
								}
								break;
						case 3:
								vitricon = 0;
								while (true)
								{
									MenuChildren(MenuGV3, vitricon, 7);
									d = GetKey();
									switch (d)
									{
									case DOWN:
											vitricon += 1;
											if (vitricon == 7) vitricon = 0;
											break;
									case UP:
											vitricon -= 1;
											if (vitricon == -1) vitricon = 6;
											break;
									case ESC:
											goto REPEATGV;
											break;
									case ENTER:
										switch (vitricon)
										{
										case 0:
												system("cls");
												ViewListOfClass(ds);
												gotoxy(5, 32); system("pause");
												goto REPEATGV;
												break;
										case 2:
												system("cls");
												ViewListOfCourse(dsmon, se, ef, fl, Y);
												gotoxy(30, 1); system("pause");
												goto REPEATGV;
												break;
										case 1:
												system("cls");
												choice = ViewListOfClass(ds);
												if(choice == 1)
													ViewListOfStudentInClass(ds);
												gotoxy(30, 1); system("pause");
												goto REPEATGV;
												break;
										case 3:
												system("cls");
												ViewListOfStudentIncourses(dsmon, se, Y);
												gotoxy(30, 1); system("pause");
												goto REPEATGV;
												break;
										case 4:
												system("cls");
												choice = ViewListOfCourse(dsmon, se, ef, fl, Y);
												if (fl == true && choice == 1)
													ViewScoreBoardOfACourse(dsmon, se, Y);
												else EffectFailed(80, 13, "Chua co khoa hoc nao");
												gotoxy(30, 1); system("pause");
												goto REPEATGV;
												break;
										case 5:
												system("cls");
												choice = ViewListOfClass(ds);
												if (choice == 1)
													ViewScoreOfAClass(ds, dsmon, se, Y);
												gotoxy(30, 1); system("pause");
												goto REPEATGV;
												break;
										case 6:
												ExportListStudentInCourseToEnterScore(dsmon, se, Y);
												EffectSuccess(90, 28, "Tao file thanh cong ");
												gotoxy(30, 1); system("pause");
												goto REPEATGV;
												break;
										}
										break;
										break;
									}
								}
								break;
						case 2:
							vitricon = 0;
							while (true)
							{
								MenuChildren(MenuGV2, vitricon, 7);
								d = GetKey();
								switch (d)
								{
								case DOWN:
									vitricon += 1;
									if (vitricon == 7) vitricon = 0;
									break;
								case UP:
									vitricon -= 1;
									if (vitricon == -1) vitricon = 6;
									break;
								case ESC:
									goto REPEATGV;
									break;
								case ENTER:
									string c;
									int choice;
									switch (vitricon)
									{
									case 0:
										AddStudent_Input(ds, Y);
										gotoxy(70, 32); system("pause");
										goto REPEATGV;
										break;
									case 1:
										CreateCourseRegistrationSession(se, Y);
										gotoxy(70, 32); system("pause");
										goto REPEATGV;
										break;
									case 2:
										createNewCourse(dsmon, se, Y);
										gotoxy(70, 32); system("pause");
										goto REPEATGV;
										break;
									case 4:
										deleteCourse(dsmon, se, Y);
										gotoxy(70, 32); system("pause");
										goto REPEATGV;
										break;
									case 3:
										c = " Ban co muon xuat file csv khong? ";
										choice = EffectAgree(70, 10, c);
										if (choice == 1)
										{
											ClearEffectAgree(70, 10, c);
											PrintFileCSV(ds, Y);
											EffectSuccess(90, 28, "Xuat file thanh cong ");
										}
										gotoxy(70, 32); system("pause");
										goto REPEATGV;
										break;
									case 5:
										updateCourse(dsmon, se, Y);
										gotoxy(70, 32); system("pause");
										goto REPEATGV;
										break;
									case 6:
										updateAStudentResult(dsmon, se, Y);
										gotoxy(30, 1); system("pause");
										goto REPEATGV;
										break;
									}
									break;
								}
							}
							break;
						case 4: {
							string effect;
							bool Check = MenuChangePasswordManager(gv, dsgv, effect, Y);
							if (Check) EffectSuccess(80, 25, effect);
							else EffectFailed(80, 25, effect);
							gotoxy(75, 30); system("pause");
							goto REPEATGV;
							break;
						}
						case 5:
								goto HOME;
								break;
						case 6:
								exit(1);
								break;
						}
					}
				}
				break;
			break;
	}
}