#pragma once
#include"Header.h"
void InitListSemester(listSemester& l);
bool CreateSemester(semester& sesmes, const SchoolYear& Y);
void readListSemester(listSemester& l, const SchoolYear& Y);
int getSemester(listSemester l, const SchoolYear Y);