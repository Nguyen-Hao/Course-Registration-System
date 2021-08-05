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

#define FILEDSGV "DsGiaoVien.txt"
#define FILECSV "Filecsv"

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
	int shift;
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
	int YearStudent=0;
	int Semester=0;
	int begin[3];
};

struct ListSV
{
	SinhVien info;
	ListSV* pNext=NULL;
};
struct DiemMonHoc
{
	double MidTerm=0;
	double Final=0;
	double Other=0; 
	double Total=0;
};
struct NodeDiem
{
	SinhVien info;
	DiemMonHoc data;
	NodeDiem* pNext = NULL;
};
struct ListDiem
{
	NodeDiem* head = NULL;
	NodeDiem* tail = NULL;
};
struct Lop
{
	string Ma;
	string Ten;
	string NienKhoa;
	ListSV* pHead=NULL;
	int soluong = 0;
};
struct ListLop
{
	Lop l[maxlop];
	int n;
};

struct GiaoVien
{
	string ID;
	string pass;
	string FirstName;
	string LastName;
	string Gender;
	string DateOfBirth;
	string SocialID;
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
	string ID;
	string Name;		
	string TeacherName;
	PhienGio Session1;			
	PhienGio Session2;		
	int Sememster;
	int NumOfCredits;
	int MaxNumOfStudents = 50;
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
	Date begin;
	Date end;
	ListCourses lis;
	char schoolyear[11];
	int studentYear = 0;
	int name;
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
