#pragma once
#include"Header.h"

void copy(NodeCourse*& p, NodeCourse* p1);
void themvaolist(ListCourses& result, ListCourses l, char id[10]);
bool ktra(const ListCourses& l, string c);
int countNodeCourses(const ListCourses& l);
ListCourses courseOfStudent(const ListCourses& l, const SinhVien& sv);
NodeCourse* find(const ListCourses& l, char id[10]);
bool checkTrung(const ListCourses& l, NodeCourse* ptr);
void dangki(ListCourses& l,SinhVien& S);
void view_Enrol_Course(SinhVien& S);
void eraser_erol_course(SinhVien& S);
