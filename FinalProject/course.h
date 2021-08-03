#pragma once
#include"Header.h"

void createNewCourse(int semester, const SchoolYear& Y);
void initListCourses(ListCourses& list);
ListCourses ReadListCourses(int se, const SchoolYear& Y);
int ViewListOfCourse(ListCourses temp, int se, const SchoolYear& Y);
void updateCourse(ListCourses l, int se, const SchoolYear& Y);
void CreateCourseRegistrationSession(int se, const SchoolYear& Y);
void deleteCourse(ListCourses l, int se, const SchoolYear& Y);
string TimeShift(int shift);
int CountNodeCourse(NodeCourse* phead);
int CountNodePage2(int n);