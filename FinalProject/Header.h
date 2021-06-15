#pragma once
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <sstream>
#include <string>
#define maxlop 50
#define maxsv 100
#define DOWN -80
#define UP -72
#define LEFT -75
#define RIGHT -77
#define ENTER 13
#define ESC 27
#define BACKSPACE 8
#define SPACE 32

#define FILEDSSV "DSSinhVien.txt"
#define FILEDSLOP "DSLop.txt"
#define FILECOURSES "ListCourses.txt"
#define FILECSV "Filecsv.csv"
#define FILETIMEDKHP "TimeDKHP.txt"
using namespace std;

struct Time
{
	int day;
	int month;
	int year;
	int hour;
	int minute;
	int second;
};

struct Date
{
	int ngay;
	int thang;
	int nam;
};
struct PhienGio
{
	char Thu[10];
	char Gio[10];
};

struct DiemMonHoc
{
	double MidTerm;
	double Final;
	double Other; // Qua Trinh
	double Total;
};
struct ListDiem
{
	DiemMonHoc data;
	ListDiem* pNext;
};
struct SinhVien
{
	char Class[10];
	char ID[10];
	char pass[20];
	char FirstName[50];
	char LastName[50];
	char Gender[10];
	char DateOfBirth[50];
	char SocialID[10];
	int begin[3];
	int YearStudent; // Năm nhập học
	int Semester;
};

struct ListSV
{
	SinhVien info;
	ListSV* pNext;
};

struct Lop
{
	char Ma[16];
	char Ten[30];
	char NienKhoa[10];
	int soluong;
	ListSV* pHead;
};
struct ListLop
{
	int n;						// so luong lop
	Lop l[maxlop];
};

struct Course
{
	int Sememster;				// 1/2/3
	char ID[20];
	char Name[50];				//Tên khóa học
	char TeacherName[50];		//Tên GV
	int NumOfCredits;			//số tín chỉ
	int MaxNumOfStudents = 50;
	PhienGio Session1;			//Buổi học 1
	PhienGio Session2;			//Buổi học 2
};
struct NodeCourse
{
	Course course;
	NodeCourse* next;
};
struct ListCourses
{
	NodeCourse* head;
};
struct semester
{
	int name;
	char schoolyear[11];
	Date begin;
	Date end;
	ListCourses lis;
};
void BackGround();
void InfoTeam();
void XYWordColor(int x, int y, string c, int color);
int MenuFirst();
void KhungDangNhap(int item);
void DangNhapThanhCong();
void DangNhapThatBai();
ListSV* DangNhapSV(ListLop ds);
int AfterLoginSV(ListLop ds, ListSV*& p);
void MenuSV(ListLop ds, ListSV*& p);




void ReadFileClass(ListLop& ds);

Time getTime();
bool isLeapYear(int nYear);
int sumOfDayInMonth(int nMonth, int nYear);
bool isDate(int nDay, int nMonth, int nYear);
bool isTime(int h, int m, int s);