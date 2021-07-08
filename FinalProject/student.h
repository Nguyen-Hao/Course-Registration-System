#pragma once
#include "Header.h"

void AddTailStudent(ListSV*& ds, SinhVien sv);
int CheckClass(ListLop dsl, char a[100], int n);
void AddStudent_Input(ListLop& dsl);
void WriteFileStudent(ListLop& dsl, const SchoolYear& Y);
void ReadFileStudent(ListLop& dsl, const SchoolYear& Y);
void Read_File_DSGV(ListGV& dsgv, const SchoolYear& Y);
void writeFileTeacher(ListGV dsgv, const SchoolYear& Y);
void UpdateCSV(ListLop& ds, const SchoolYear& Y);
void UpdateStudent(const SchoolYear& Y);
void ViewListOfClass(ListLop& ds);
void ViewListOfStudentInClass(ListLop& ds);
ListSV* findStudentOfCourses(const ListCourses& l, char mamon[50], const SchoolYear& Y);
void ViewListOfStudentIncourses(const SchoolYear& Y);
void export_list_student_in_a_course_to_csv(const SchoolYear& Y);
void ExportListStudentInCourseToEnterScore(const SchoolYear& Y);
void ViewScoreBoardOfACourse(ListCourses dsmon, string mamon);
void updateAStudentResult(const SchoolYear& Y);
void ViewScoreOfAClass(ListLop dsl, ListCourses dsm, char malop[50], const SchoolYear& Y);