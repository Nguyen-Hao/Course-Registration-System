#pragma once
#include "Header.h"

void AddTailStudent(ListSV*& ds, SinhVien sv);
int CheckClass(ListLop dsl, char a[100], int n);
void AddStudent_Input(ListLop& dsl);
void WriteFileStudent(ListLop& dsl);
void ReadFileStudent(ListLop& dsl);
void Read_File_DSGV(ListGV& dsgv);
void writeFileTeacher(ListGV dsgv);
void UpdateCSV(ListLop& ds);
void UpdateStudent();
void ViewListOfClass(ListLop& ds);
void ViewListOfStudentInClass(ListLop& ds);
ListSV* findStudentOfCourses(const ListCourses& l, char mamon[50]);
void ViewListOfStudentIncourses();