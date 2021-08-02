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
string MenuGV2[] = { " 1. Them sinh vien nam nhat vao lop", " 2. Tao phien DKHP", " 3. Them khoa hoc"," 4. Xuat file nhap DSSV tung lop", " 5. Xoa khoa hoc" };
string MenuGV3[] = { " 1. Danh sach lop", " 2. Danh sach sinh vien trong lop", " 3. Danh sach khoa hoc"," 4. Danh sach SV trong khoa hoc", " 5. Xem bang diem trong khoa hoc", " 6. Xem bang diem trong lop"," 7. Xuat CSV File bang diem SV trong khoa hoc"};
string MenuGV[] = { " 1. Tao moi", " 2. Nhap thong tin", " 3. Tra cuu " ," 4. Doi mat khau", " 5. Dang xuat", " 6.Thoat"};
string ThaoTac[] = { " Dang nhap thanh cong", " Ten tai khoan hoac mat khau chua dung", " Tao thanh cong", " Tao that bai", "Huy thanh cong", "Huy that bai"};

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
	int vitri = 0;
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
		int n = 0;
		for (int i = 0; i < 3; i++)
		{
			int k = Menubegin[i].length();
			if (k > n) n = k;
		}
		for (int i = 0; i < 3; i++)
		{
			if (i == vitri)
			{
				TextColor(160);
				gotoxy(12, 17 + i * 4); for (int i = 0; i <= n; i++)	cout << " ";
				gotoxy(12, 18 + i * 4); for (int i = 0; i <= n; i++)	cout << " ";
				gotoxy(12, 18 + i * 4);  cout << Menubegin[i];
				gotoxy(12, 19 + i * 4); for (int i = 0; i <= n; i++)	cout << " ";
			}
			else
			{
				TextColor(240);
				gotoxy(12, 17 + i * 4); for (int i = 0; i <= n; i++)	cout << " ";
				gotoxy(12, 18 + i * 4); for (int i = 0; i <= n; i++)	cout << " ";
				gotoxy(12, 18 + i * 4);  cout << Menubegin[i];
				gotoxy(12, 19 + i * 4); for (int i = 0; i <= n; i++)	cout << " ";
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
	TextColor(240);
	gotoxy(x, y); for (int i = 0; i <= c.size() + 3; i++) cout << " ";
	gotoxy(x, y + 1); for (int i = 0; i <= c.size() + 3; i++) cout << " ";
	gotoxy(x, y + 2); for (int i = 0; i <= c.size() + 3; i++) cout << " ";
	gotoxy(x + 3, y + 1); cout << c;
	gotoxy(x, y + 3); for (int i = 0; i <= c.size() + 3; i++) cout << " ";
	gotoxy(x, y + 4); for (int i = 0; i <= c.size() + 3; i++) cout << " ";
	gotoxy(x, y + 5); for (int i = 0; i <= c.size() + 3; i++) cout << " ";
	gotoxy(x, y + 6); for (int i = 0; i <= c.size() + 3; i++) cout << " ";
	gotoxy(x, y + 7); for (int i = 0; i <= c.size() + 3; i++) cout << " ";
	gotoxy(x, y + 8); for (int i = 0; i <= c.size() + 3; i++) cout << " ";
	gotoxy(x, y + 9); for (int i = 0; i <= c.size() + 3; i++) cout << " ";
	//
	int a = (c.size() - yes.size()) / 2;
	TextColor(160);
	gotoxy(x + a - 3, y + 5); for (int i = 0; i < yes.size() + 3; i++) cout << " ";
	gotoxy(x + a - 3, y + 6); for (int i = 0; i < yes.size() + 3; i++) cout << " ";
	gotoxy(x + a - 3, y + 7); for (int i = 0; i < yes.size() + 3; i++) cout << " ";
	gotoxy(x + a - 3, y + 6); cout << yes;
	//
	TextColor(224);
	gotoxy(x + a + yes.size() + 3, y + 5); for (int i = 0; i < yes.size() + 3; i++) cout << " ";
	gotoxy(x + a + yes.size() + 3, y + 6); for (int i = 0; i < yes.size() + 3; i++) cout << " ";
	gotoxy(x + a + yes.size() + 3, y + 7); for (int i = 0; i < yes.size() + 3; i++) cout << " ";
	gotoxy(x + a + yes.size() + 3, y + 6); cout << no;
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
			gotoxy(x + a - 3, y + 5); for (int i = 0; i < yes.size() + 3; i++) cout << " ";
			gotoxy(x + a - 3, y + 6); for (int i = 0; i < yes.size() + 3; i++) cout << " ";
			gotoxy(x + a - 3, y + 7); for (int i = 0; i < yes.size() + 3; i++) cout << " ";
			gotoxy(x + a - 3, y + 6); cout << yes;
			//
			TextColor(224);
			gotoxy(x + a + yes.size() + 3, y + 5); for (int i = 0; i < yes.size() + 3; i++) cout << " ";
			gotoxy(x + a + yes.size() + 3, y + 6); for (int i = 0; i < yes.size() + 3; i++) cout << " ";
			gotoxy(x + a + yes.size() + 3, y + 7); for (int i = 0; i < yes.size() + 3; i++) cout << " ";
			gotoxy(x + a + yes.size() + 5, y + 6); cout << no;
		}
		else if (vitri == 1)
		{
			TextColor(224);
			gotoxy(x + a - 3, y + 5); for (int i = 0; i < yes.size() + 3; i++) cout << " ";
			gotoxy(x + a - 3, y + 6); for (int i = 0; i < yes.size() + 3; i++) cout << " ";
			gotoxy(x + a - 3, y + 7); for (int i = 0; i < yes.size() + 3; i++) cout << " ";
			gotoxy(x + a - 3, y + 6); cout << yes;
			//
			TextColor(160);
			gotoxy(x + a + yes.size() + 3, y + 5); for (int i = 0; i < yes.size() + 3; i++) cout << " ";
			gotoxy(x + a + yes.size() + 3, y + 6); for (int i = 0; i < yes.size() + 3; i++) cout << " ";
			gotoxy(x + a + yes.size() + 3, y + 7); for (int i = 0; i < yes.size() + 3; i++) cout << " ";
			gotoxy(x + a + yes.size() + 3, y + 6); cout << no;
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
	gotoxy(x, y); for (int i = 0; i <= c.size() + 3; i++) cout << " ";
	gotoxy(x, y + 1); for (int i = 0; i <= c.size() + 3; i++) cout << " ";
	gotoxy(x, y + 2); for (int i = 0; i <= c.size() + 3; i++) cout << " ";
	gotoxy(x, y + 3); for (int i = 0; i <= c.size() + 3; i++) cout << " ";
	gotoxy(x, y + 4); for (int i = 0; i <= c.size() + 3; i++) cout << " ";
	gotoxy(x, y + 5); for (int i = 0; i <= c.size() + 3; i++) cout << " ";
	gotoxy(x, y + 6); for (int i = 0; i <= c.size() + 3; i++) cout << " ";
	gotoxy(x, y + 7); for (int i = 0; i <= c.size() + 3; i++) cout << " ";
	gotoxy(x, y + 8); for (int i = 0; i <= c.size() + 3; i++) cout << " ";
	gotoxy(x, y + 9); for (int i = 0; i <= c.size() + 3; i++) cout << " ";
}
void EffectSuccess(int x, int y, string c)
{
	TextColor(160);
	gotoxy(x, y); for (int i = 0; i <= c.size() + 3; i++) cout << " ";
	gotoxy(x, y + 1); for (int i = 0; i <= c.size() + 3; i++) cout << " ";
	gotoxy(x, y + 2); for (int i = 0; i <= c.size() + 3; i++) cout << " ";
	gotoxy(x + 3, y + 1); cout << c;
	TextColor(224);
}
void EffectFailed(int x, int y, string c)
{
	TextColor(207);
	gotoxy(x, y); for (int i = 0; i <= c.size() + 3; i++) cout << " ";
	gotoxy(x, y + 1); for (int i = 0; i <= c.size() + 3; i++) cout << " ";
	gotoxy(x, y + 2); for (int i = 0; i <= c.size() + 3; i++) cout << " ";
	gotoxy(x + 3, y + 1); cout << c;
	TextColor(224);
}
void CreateSemesterForm()
{
	TextColor(224);
	gotoxy(75, 9); cout << "Ki: "; Frames(100, 8, 10, 1); // khung nhap ki 
	gotoxy(75, 13); cout << "Nam hoc: "; Frames(100, 12, 15, 1);// nam
	gotoxy(75, 17); cout << "Ngay bat dau: "; Frames(100, 16, 10, 1); gotoxy(111, 17); cout << "/"; Frames(113, 16, 10, 1); gotoxy(124, 17); cout << "/"; Frames(126, 16, 10, 1);
	gotoxy(75, 21); cout << "Ngay ket thuc: "; Frames(100, 20, 10, 1); gotoxy(111, 21); cout << "/"; Frames(113, 20, 10, 1); gotoxy(124, 20); cout << "/"; Frames(126, 20, 10, 1);
	Frames(130, 28, 30, 3);
	gotoxy(132, 30); cout << "ENTER: Fill Next-Create";
	TextColor(228);
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
				EffectSuccess(54, 28, ThaoTac[0]);
				Sleep(2000);
				break;
			}
			else
			{
				EffectFailed(54, 28, ThaoTac[1]);
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
					j--;
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
				EffectSuccess(54, 28, ThaoTac[0]);
				Sleep(2000);
				break;
			}
			else
			{
				EffectFailed(54, 28, ThaoTac[1]);
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
void ChangePasswordStudent(SinhVien& sv, ListLop& dsl, char newpass[], const SchoolYear& Y)
{
	sv.pass = newpass;
	for (int i = 0; i < dsl.n; i++)
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
void MenuChangePasswordStudent(SinhVien& sv, ListLop& dsl, const SchoolYear& Y)
{
	char oldpass[30];
	char newpass[30];
	char newpassAgain[30];
	gotoxy(30, 15); cout << "Nhap mat khau: "; cin.getline(oldpass, 30);
	gotoxy(30, 17); cout << "Nhap mat khau moi: "; cin.getline(newpass, 30);
	gotoxy(30, 19); cout << "Nhap lai mat khau moi: "; cin.getline(newpassAgain, 30);
	if (sv.pass != oldpass)
	{
		gotoxy(30, 25); cout << "Mat Khau sai!" << endl;
		gotoxy(30, 26); system("pause");
	}
	else if (strcmp(newpass, newpassAgain) != 0)
	{
		gotoxy(30, 25); cout << "Mat Khau khong khop!" << endl;
		gotoxy(30, 26); system("pause");
	}
	else
	{
		ChangePasswordStudent(sv, dsl, newpass, Y);
		gotoxy(30, 25); cout << "Doi mat khau thanh cong!" << endl;
		gotoxy(30, 26); system("pause");
	}
}
void ChangePasswordManager(GiaoVien& gv, ListGV& dsgv, char newpass[], const SchoolYear& Y)
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
}
void MenuChangePasswordManager(GiaoVien& gv, ListGV& dsgv, const SchoolYear& Y)
{
	char oldpass[30];
	char newpass[30];
	char newpassAgain[30];
	gotoxy(26, 15); cout << "Nhap mat khau: "; cin.getline(oldpass, 30);
	gotoxy(26, 17); cout << "Nhap mat khau moi: "; cin.getline(newpass, 30);
	gotoxy(26, 19); cout << "Nhap lai mat khau moi: "; cin.getline(newpassAgain, 30);
	if (gv.pass != oldpass)
	{
		gotoxy(26, 25); cout << "Mat Khau sai!" << endl;
		gotoxy(26, 26); system("pause");
	}
	else if (strcmp(newpass, newpassAgain) != 0)
	{
		gotoxy(26, 25); cout << "Mat Khau khong khop!" << endl;
		gotoxy(26, 26); system("pause");
	}
	else
	{
		ChangePasswordManager(gv, dsgv, newpass, Y);
		gotoxy(26, 25); cout << "Doi mat khau thanh cong!" << endl;
		gotoxy(26, 26); system("pause");
	}
}
void MenuChildren(string s[], int& vitri, int size)
{
	int n = 0;
	for (int i = 0; i < size; i++)
	{
		int k = s[i].length();
		if (k > n) n = k;
	}
	for (int i = 0; i < size; i++)
	{
		if (i == vitri)
		{
			TextColor(160);
			gotoxy(26, 8 + i * 4); for (int i = 0; i <= n; i++)	cout << " ";
			gotoxy(26, 9 + i * 4); for (int i = 0; i <= n; i++)	cout << " ";
			gotoxy(26, 9 + i * 4); cout << s[i];
			gotoxy(26, 10 + i * 4); for (int i = 0; i <= n; i++)	cout << " ";
		}
		else
		{
			TextColor(240);
			gotoxy(26, 8 + i * 4); for (int i = 0; i <= n; i++)	cout << " ";
			gotoxy(26, 9 + i * 4); for (int i = 0; i <= n; i++)	cout << " ";
			gotoxy(26, 9 + i * 4); cout << s[i];
			gotoxy(26, 10 + i * 4); for (int i = 0; i <= n; i++)	cout << " ";
		}
		TextColor(224);
	}
}
void Menu(ListLop ds, ListGV dsgv, ListCourses dsmon, SinhVien& sv, GiaoVien& gv, int& choice, int se, SchoolYear Y)
{
HOME:
	choice = SignIn(ds, dsgv, sv, gv);
	int vitri = 0;
	semester s;
	if (choice == 2) {
		while (true)
		{
		REPEATSV:
			system("cls");
			transform(sv.FirstName.begin(), sv.FirstName.end(), sv.FirstName.begin(), toupper);
			transform(sv.LastName.begin(), sv.LastName.end(), sv.LastName.begin(), toupper);
			gotoxy(4, 6); cout << "Xin chao : " << sv.FirstName << " " << sv.LastName << " - " << sv.Class;
			int n = 0;
			for (int i = 0; i < 7; i++)
			{
				int k = MenuSV[i].length();
				if (k > n) n = k;
			}
			for (int i = 0; i < 7; i++)
			{
				if (i == vitri)
				{
					TextColor(160);
					gotoxy(4, 8 + i * 4); for (int i = 0; i <= n; i++)	cout << " ";
					gotoxy(4, 9 + i * 4); for (int i = 0; i <= n; i++)	cout << " ";
					gotoxy(4, 9 + i * 4); cout << MenuSV[i];
					gotoxy(4, 10 + i * 4); for (int i = 0; i <= n; i++)	cout << " ";
				}
				else
				{
					TextColor(240);
					gotoxy(4, 8 + i * 4); for (int i = 0; i <= n; i++)	cout << " ";
					gotoxy(4, 9 + i * 4); for (int i = 0; i <= n; i++)	cout << " ";
					gotoxy(4, 9 + i * 4); cout << MenuSV[i];
					gotoxy(4, 10 + i * 4); for (int i = 0; i <= n; i++)	cout << " ";
				}
				TextColor(224);
			}
			c = GetKey();
			if (c == DOWN)
			{
				vitri += 1;
				if (vitri == 7) vitri = 0;
			}
			if (c == UP)
			{
				vitri -= 1;
				if (vitri == -1) vitri = 6;
			}
			if (c == ENTER)
			{
				int c = vitri + 1;
				while (true)
				{
					if (c == 1)
					{
						bool f;
						system("cls");
						gotoxy(60, 9);
						string s;
						CoursesRegistration(dsmon, sv, se, Y, s, f);
						if (f) EffectSuccess(55, 15, s);
						else EffectFailed(55, 15, s);
						f = false;
						gotoxy(20, 20);
						system("pause");
						goto REPEATSV;
					}
					else if (c == 2)
					{
						gotoxy(60, 9);
						ViewEnrollCourses(sv,se, Y);
						gotoxy(20, 20);
						system("pause");
						goto REPEATSV;
					}
					else if (c == 3)
					{
						bool f;
						system("cls");
						gotoxy(60, 9);
						EraserEnrollCourses(sv, dsmon, se, Y, f);
						if (f) EffectSuccess(55, 15, ThaoTac[4]);
						else EffectFailed(55, 15, "Xoa Khong thanh cong");
						gotoxy(20, 20);
						system("pause");
						goto REPEATSV;
					}
					else if (c == 4)
					{
						system("cls");
						viewScoreBoardOfStudent(sv,dsmon,se, Y);
						gotoxy(20, 20);
						system("pause");
						goto REPEATSV;
					}
					else if (c == 5)
					{
						MenuChangePasswordStudent(sv, ds, Y);
						goto REPEATSV;
					}
					else if (c == 6)
					{
						goto HOME;
					}
					else if (c == 7)
					{
						exit(1);
					}
				}
			}
		}
	}
	else if (choice == 1)
	{
		while (true)
		{
		REPEATGV:
			system("cls");
			transform(gv.FirstName.begin(), gv.FirstName.end(), gv.FirstName.begin(), toupper);
			transform(gv.LastName.begin(), gv.LastName.end(), gv.LastName.begin(), toupper);
			gotoxy(4, 6); cout << "Xin chao Thay/Co: " << gv.FirstName << " " << gv.LastName;
			int n = 0;
			for (int i = 0; i < 6; i++)
			{
				int k = MenuGV[i].length();
				if (k > n) n = k;
			}
			for (int i = 0; i < 6; i++)
			{
				if (i == vitri)
				{
					TextColor(160);
					gotoxy(4, 8 + i * 4); for (int i = 0; i <= n; i++)	cout << " ";
					gotoxy(4, 9 + i * 4); for (int i = 0; i <= n; i++)	cout << " ";
					gotoxy(4, 9 + i * 4);  cout << MenuGV[i];
					gotoxy(4, 10 + i * 4); for (int i = 0; i <= n; i++)	cout << " ";
				}
				else
				{
					TextColor(240);
					gotoxy(4, 8 + i * 4); for (int i = 0; i <= n; i++)	cout << " ";
					gotoxy(4, 9 + i * 4); for (int i = 0; i <= n; i++)	cout << " ";
					gotoxy(4, 9 + i * 4);  cout << MenuGV[i];
					gotoxy(4, 10 + i * 4); for (int i = 0; i <= n; i++)	cout << " ";
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
				if (c == 1) {
					int vitricon = 0;
					while (true)
					{
						MenuChildren(MenuGV1, vitricon, 3);
						d = GetKey();
						if (d == DOWN)
						{
							vitricon += 1;
							if (vitricon == 3) vitricon = 0;
						}
						if (d == UP)
						{
							vitricon -= 1;
							if (vitricon == -1) vitricon = 2;
						}
						if (d == ESC)
						{
							goto REPEATGV;
						}
						if (d == ENTER)
						{
							if (vitricon == 0)
							{
								string c = " Ban co muon tao nam hoc moi khong? ";
								int choice = EffectAgree(70, 10, c);
								if (choice == 1)
								{
									CreateSchoolYear(Y);
									EffectSuccess(90, 28, ThaoTac[2]);
								}
								gotoxy(70, 32); system("pause");
								goto REPEATGV;
							}
							else if (vitricon == 1)
							{
								string c = " Ban co muon tao hoc ki moi khong? ";
								int choice = EffectAgree(70, 10, c);
								if (choice == 1)
								{
									ClearEffectAgree(70, 10, c);
									CreateSemesterForm();
									bool f = CreateSemester(s, Y);
									if (f == true) EffectSuccess(90, 28, ThaoTac[2]);
									else EffectFailed(90, 28, ThaoTac[3]);
								}
								gotoxy(70, 32); system("pause");
								goto REPEATGV;
							}
							else if (vitricon == 2)
							{
								string c = " Ban co muon tao lop hoc moi khong? ";
								int choice = EffectAgree(70, 10, c);
								if (choice == 1)
								{
									ClearEffectAgree(70, 10, c);
									CreateNewClass(ds, Y);
									EffectSuccess(90, 28, ThaoTac[2]);
								}
								gotoxy(70, 32); system("pause");
								goto REPEATGV;
							}
						}
					}
				}
				else if (c == 3)
				{
					int vitricon = 0;
					while (true)
					{
						MenuChildren(MenuGV3, vitricon, 7);
						d = GetKey();
						if (d == DOWN)
						{
							vitricon += 1;
							if (vitricon == 7) vitricon = 0;
						}
						if (d == UP)
						{
							vitricon -= 1;
							if (vitricon == -1) vitricon = 6;
						}
						if (d == ESC)
						{
							goto REPEATGV;
						}
						if (d == ENTER)
						{
							if (vitricon == 0)
							{
								system("cls");
								ViewListOfClass(ds);
								gotoxy(5, 32); system("pause");
								goto REPEATGV;
							}
							else if (vitricon == 2)
							{
								system("cls");
								ViewListOfCourse(dsmon, se,Y);
								gotoxy(30, 1); system("pause");
								goto REPEATGV;
							}
							else if (vitricon == 1)
							{
								system("cls");
								ViewListOfClass(ds);
								ViewListOfStudentInClass(ds);
								gotoxy(30, 1); system("pause");
								goto REPEATGV;
							}
							else if (vitricon == 3)
							{
								system("cls");
								ViewListOfStudentIncourses(dsmon, se ,Y);
								gotoxy(30, 1); system("pause");
								goto REPEATGV;
							}
							else if (vitricon == 4)
							{
								system("cls");
								ViewListOfCourse(dsmon, se,Y);
								ViewScoreBoardOfACourse(dsmon,se, Y);
								gotoxy(30, 1); system("pause");
								goto REPEATGV;
							}
							else if (vitricon == 5)
							{
								system("cls");
								ViewListOfClass(ds);
								ViewScoreOfAClass(ds, dsmon,se, Y);
								gotoxy(30, 1); system("pause");
								goto REPEATGV;
							}
							else if (vitricon == 6)
							{
								ExportListStudentInCourseToEnterScore(dsmon,se , Y);
								EffectSuccess(90, 28, ThaoTac[2]);
								gotoxy(30, 1); system("pause");
								goto REPEATGV;
							}
						}
					}
				}
				else if (c == 2)
				{
					int vitricon = 0;
					while (true)
					{
						MenuChildren(MenuGV2, vitricon, 5);
						d = GetKey();
						if (d == DOWN)
						{
							vitricon += 1;
							if (vitricon == 5) vitricon = 0;
						}
						if (d == UP)
						{
							vitricon -= 1;
							if (vitricon == -1) vitricon = 4;
						}
						if (d == ESC)
						{
							goto REPEATGV;
						}
						if (d == ENTER)
						{
							if (vitricon == 0)
							{
								AddStudent_Input(ds, Y);
								gotoxy(70, 32); system("pause");
								goto REPEATGV;
							}
							else if (vitricon == 1)
							{
								CreateCourseRegistrationSession(se, Y);
								gotoxy(70, 32); system("pause");
								goto REPEATGV;
							}
							else if (vitricon == 2)
							{
								createNewCourse(se, Y);
								gotoxy(70, 32); system("pause");
								goto REPEATGV;
							}
							else if (vitricon == 4)
							{
								deleteCourse(dsmon, se, Y);
								EffectSuccess(55, 10, ThaoTac[4]);
								gotoxy(70, 32); system("pause");
								goto REPEATGV;
							}
							else if (vitricon == 3)
							{
								string c = " Ban co muon xuat file csv khong? ";
								int choice = EffectAgree(70, 10, c);
								if (choice == 1)
								{
									ClearEffectAgree(70, 10, c);
									PrintFileCSV(ds, Y);
									EffectSuccess(90, 28, ThaoTac[2]);
								}
								gotoxy(70, 32); system("pause");
								goto REPEATGV;
							}
						}
					}
				}
				else if (c == 4)
				{
					MenuChangePasswordManager(gv, dsgv, Y);
					goto REPEATGV;
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