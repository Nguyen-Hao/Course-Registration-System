#pragma once
#include"Header.h"

void createNewCourse(ListCourses& l, int semester, const SchoolYear& Y);
void initListCourses(ListCourses& list);
void AddTailListCourse(ListCourses& l, Course co);
ListCourses ReadListCourses(int se, const SchoolYear& Y);
int ViewListOfCourse(ListCourses temp, int se, string& e, bool& fl, const SchoolYear& Y);
void updateCourse(ListCourses& l, int se, const SchoolYear& Y);
void CreateCourseRegistrationSession(int se, const SchoolYear& Y);
void deleteCourse(ListCourses& l, int se, const SchoolYear& Y);
string TimeShift(int shift);
int CountNodeCourse(NodeCourse* phead);
int CountNodePage2(int n);