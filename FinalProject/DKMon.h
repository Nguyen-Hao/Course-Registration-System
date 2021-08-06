#pragma once
#include "Header.h"

void Copy(NodeCourse*& p, NodeCourse* p1);
void AddList(ListCourses& result, ListCourses l, char id[10]);
bool CheckCourses(const ListCourses& l, string c);
int countNodeCourses(const ListCourses& l);
ListCourses courseOfStudent(const ListCourses& l, const SinhVien& sv, int se, const SchoolYear& Y);
NodeCourse* FindCourses(const ListCourses& l, char id[10]);
bool CheckSameTime(const ListCourses& l, NodeCourse* ptr);
void CoursesRegistration(ListCourses l, SinhVien S, int se, const SchoolYear& Y, string& c, bool& f);
int daDangKy(Course a, const SchoolYear Y, int se, ListCourses l);
Time* ReadTimeRegistration(const SchoolYear& Y);
bool checkNumber(const SchoolYear& Y, const string& S);
int NumberMaxStudent(const SchoolYear& Y, const string& S, int se, const ListCourses& l);
