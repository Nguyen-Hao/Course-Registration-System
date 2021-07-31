#pragma once
#include "Header.h"
#include "student.h"

void CreateNewClass(ListLop& ds, const SchoolYear& Y);
void AddStudent_Input(ListLop& dsl);
void ReadFileDSGV(ListGV& dsgv, const SchoolYear& Y);
void writeFileTeacher(ListGV dsgv, const SchoolYear& Y);
void UpdateCSV(ListLop& ds, const SchoolYear& Y);
void UpdateStudent(const SchoolYear& Y);
void ViewListOfClass(ListLop& ds);
void ViewListOfStudentInClass(ListLop& ds);
void ViewListOfStudentIncourses(const SchoolYear& Y);
ListSV* findStudentOfCourses(const ListCourses& l, char mamon[50], const SchoolYear& Y);
void ExportListStudentInCourseToEnterScore(ListCourses dsm, const SchoolYear& Y);
void ViewScoreBoardOfACourse(ListCourses dsmon, const SchoolYear& Y);
void updateAStudentResult(const SchoolYear& Y);
void ViewScoreOfAClass(ListLop dsl, ListCourses dsm, const SchoolYear& Y);
DiemMonHoc ReadfileCSVScore(SinhVien S, const SchoolYear& Y, char* mamon);
void PrintFileCSV(ListLop dsl, SchoolYear Y);
