#ifndef _HEADER_H_
#define _HEADER_H_
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

using namespace std;

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

#endif // ! _HEADER_H_

void ReadFileClass(ListLop& ds);
