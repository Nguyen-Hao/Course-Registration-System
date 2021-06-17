#pragma once
#include"Header.h"

bool ktra(ListCourses& l, char c[10]);
ListCourses courseOfStudent(ListCourses l, SinhVien sv);
void themvaolist(ListCourses& result, ListCourses l, char id[10]);
NodeCourse* find(ListCourses l, char id[10]);
bool checkTrung(ListCourses l, NodeCourse* ptr);
void dangki(ListCourses& l, SinhVien S);
