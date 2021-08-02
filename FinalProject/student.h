#pragma once
#include "Header.h"

void AddTailStudent(ListSV*& ds, SinhVien sv); 
int CheckClass(ListLop dsl, string a, int n); 
void AddStudent_Input(ListLop& dsl, const SchoolYear& Y); 
void WriteFileStudent(ListLop& dsl, const SchoolYear& Y);
void ReadFileStudent(ListLop& dsl, const SchoolYear& Y); 
void viewScoreBoardOfStudent(const SinhVien& S, ListCourses l, int se, const SchoolYear& Y);
