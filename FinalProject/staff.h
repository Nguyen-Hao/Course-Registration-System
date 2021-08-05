#pragma once
#include "Header.h"
#include "student.h"

void CreateNewClass(ListLop& ds, const SchoolYear& Y, int& t);
void AddStudent_Input(ListLop& dsl, const SchoolYear& Y);
void ReadFileDSGV(ListGV& dsgv, const SchoolYear& Y);
void writeFileTeacher(ListGV dsgv, const SchoolYear& Y);
void UpdateCSV(ListLop& ds, const SchoolYear& Y);
void UpdateStudent(const SchoolYear& Y);
int ViewListOfClass(ListLop& ds);
void ViewListOfStudentInClass(ListLop& ds);
void ViewListOfStudentIncourses(ListCourses ds, int se, const SchoolYear& Y);
ListSV* findStudentOfCourses(const ListCourses& l, string mamon, int se, const SchoolYear& Y);
void ExportListStudentInCourseToEnterScore(ListCourses dsm, int se, const SchoolYear& Y);
void ViewScoreBoardOfACourse(ListCourses dsmon, int se, const SchoolYear& Y);
void updateAStudentResult(ListCourses ds, int se, const SchoolYear& Y);
void ViewScoreOfAClass(ListLop dsl, ListCourses dsm, int se, const SchoolYear& Y);
DiemMonHoc ReadfileCSVScore(const SinhVien& S, const SchoolYear& Y, int se, string mamon);
void PrintFileCSV(ListLop dsl, SchoolYear Y);
int CountNodeStudent(ListSV* phead);
int CountNodePage(int i);