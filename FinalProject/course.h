#pragma once
#include"Header.h"

void createNewCourse(int semester, const SchoolYear& Y);
void initListCourses(ListCourses& list);
ListCourses ReadListCourses(int se, const SchoolYear& Y);
void ViewListOfCourse(int se, const SchoolYear& Y);
void updateCourse(int se, const SchoolYear& Y);
void CreateCourseRegistrationSession(int se, const SchoolYear& Y);
void deleteCourse(int se, const SchoolYear& Y);
