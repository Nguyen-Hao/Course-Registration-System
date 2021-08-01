#pragma once
#include"Header.h"

#define FILESCHOOLYEAR "SchoolYear.txt"

unsigned int YearPresent();
void CreateSchoolYear(SchoolYear& S);
SchoolYear SchoolYearPresent(const string& S);
void CopyData(const string& fileName1, const string& fileName2);
void ExportFileEmpty(const string& str);