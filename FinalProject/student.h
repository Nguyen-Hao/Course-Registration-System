#pragma once
#include "Header.h"

void AddTailStudent(ListSV*& ds, SinhVien sv);
int CheckClass(ListLop dsl, char a[100], int n);
void AddStudent_Input(ListLop& dsl);
void WriteFileStudent(ListLop& dsl);
void ReadFileStudent(ListLop& dsl);
void UpdateCSV(ListLop& ds);
void UpdateStudent();
void ViewListOfClass(ListLop& ds);
void ViewListOfStudentInClass(ListLop& ds);