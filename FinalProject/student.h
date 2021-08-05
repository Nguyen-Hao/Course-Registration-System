#pragma once
#include "Header.h"

void AddTailStudent(ListSV*& ds, SinhVien sv); 
int CheckClass(ListLop dsl, string a, int n); 
void AddStudent_Input(ListLop& dsl, const SchoolYear& Y); 
void WriteFileStudent(ListLop& dsl, const SchoolYear& Y);
void ReadFileStudent(ListLop& dsl, const SchoolYear& Y); 
void viewScoreBoardOfStudent(const SinhVien& S, ListCourses l, string& e, bool& f, int se, const SchoolYear& Y);
void ViewEnrollCourses(ListCourses l, SinhVien& S, int se, string& e, bool &f, const SchoolYear& Y);
void EraserEnrollCourses(SinhVien& S, ListCourses l, string& eff, bool& flat, int se, const SchoolYear& Y);
