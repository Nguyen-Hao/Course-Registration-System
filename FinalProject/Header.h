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
#define maxlop 100
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
#define FILEDSGV "DsGiaoVien.txt"
#define FILEDSLOP "DSLop.txt"
#define FILECOURSES "ListCourses.txt"
#define FILECSV "Filecsv.csv"
#define FILETIMEDKHP "TimeDKHP.txt"
#define FILEDSSVMON "StudentOfSubject.txt"

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
	int thu;
	int gio;
	int phut;
};

struct SinhVien
{
	string Class;
	string ID;
	string pass;
	string FirstName;
	string LastName;
	string Gender;
	string DateOfBirth;
	string SocialID;
	int begin[3];
	int YearStudent;
	int Semester;
};

struct ListSV
{
	SinhVien info;
	ListSV* pNext=NULL;
};
struct DiemMonHoc
{
	double MidTerm;
	double Final;
	double Other; 
	double Total;
};
struct NodeDiem
{
	SinhVien info;
	DiemMonHoc data;
	NodeDiem* pNext=NULL;
};
struct ListDiem
{
	NodeDiem* head;
	NodeDiem* tail=NULL;
};
struct Lop
{
	string Ma;
	string Ten;
	string NienKhoa;
	int soluong;
	ListSV* pHead=NULL;
};
struct ListLop
{
	int n;
	Lop l[maxlop];
};

struct GiaoVien
{
	char ID[10];
	char pass[20];
	char FirstName[50];
	char LastName[50];
	char Gender[10];
	char DateOfBirth[50];
	char SocialID[10];
};
struct NodeGV
{
	GiaoVien info;
	NodeGV* pNext = NULL;
};
struct ListGV
{
	NodeGV* pHead = NULL;
};
struct Course
{
	int Sememster;		
	string ID;
	string Name;		
	string TeacherName;
	int NumOfCredits;	
	int MaxNumOfStudents = 50;
	PhienGio Session1;			
	PhienGio Session2;			
};
struct NodeCourse
{
	Course course;
	NodeCourse* next = NULL;
};
struct ListCourses
{
	NodeCourse* head = NULL;
};
struct semester
{
	int name;
	char schoolyear[11];
	int studentYear = 0;
	Date begin;
	Date end;
	ListCourses lis;
};
struct NodeSemester
{
	semester semes;
	NodeSemester* next = NULL;
};
struct listSemester
{
	NodeSemester* head = NULL;
	NodeSemester* tail = NULL;
};


struct SchoolYear
{
	string NameSchoolYear;
	string DSLop = "DSLop"; 
	string DSSinhVien = "DSSinhVien";
	string StudentOfSubject = "StudentOfSubject";  
	string TimeDKHP = "TimeDKHP";  
	string DsGiaoVien = "DsGiaoVien"; 
	string Filecsv = "DSSV"; 
	string ListCourses = "ListCourses"; 
	string sesmester = "sesmester";  
};


void ReadFileClass(ListLop& dsl, const SchoolYear& Y);
Time getTime();
bool isLeapYear(int nYear);
int sumOfDayInMonth(int nMonth, int nYear);
bool isDate(int nDay, int nMonth, int nYear);
bool isTime(int h, int m, int s);
char isTimeIn(Time t, Time begin, Time end);
void Information();
void Team();
int MenuHeader(); 
void SignInFrames(int item); 
void EffectSuccess(int x, int y, string c);
void EffectFailed(int x, int y, string c);
void CreateSemesterForm();
int SignIn(ListLop ds, ListGV dsgv, SinhVien& sv, GiaoVien& gv);
void ChangePasswordStudent(SinhVien& sv, ListLop& dsl, char newpass[], const SchoolYear& Y);
void MenuChangePasswordStudent(SinhVien& sv, ListLop& dsl, const SchoolYear& Y);
void ChangePasswordManager(GiaoVien& gv, ListGV& dsgv, char newpass[], const SchoolYear& Y);
void MenuChangePasswordManager(GiaoVien& gv, ListGV& dsgv, const SchoolYear& Y);
void MenuChildren(string s[], int& vitri, int size);
void Menu(ListLop ds, ListGV dsgv, ListCourses dsmon, SinhVien& sv, GiaoVien& gv, int& choice, int se, SchoolYear Y);
