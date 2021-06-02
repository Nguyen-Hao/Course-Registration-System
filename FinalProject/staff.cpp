#include "staff.h"
#include "Header.h"

void CreateNewClass(ListLop& ds)
{
	ofstream f;
	f.open(FILEDSLOP, ios::app);
	Lop c;
	cout << "Nhap ma lop: "; cin.get(c.Ma, 16, '\n');
	f << c.Ma << endl;
	cin.ignore();
	cout << "Nhap ten lop: "; cin.get(c.Ten, 36, '\n');
	f << c.Ten << endl;
	cin.ignore();
	cout << "Nhap nien khoa: "; cin.get(c.NienKhoa, 10, '\n');
	f << c.NienKhoa << endl;
	c.pHead = NULL;
	cin.ignore();
	ds.l[ds.n] = c;
	ds.n++;
	f.close();
}