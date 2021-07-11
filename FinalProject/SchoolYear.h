#pragma once
#include"Header.h"

//FILECOURSE*
//FILETIMEDKHP    *
//FILEDSSVMON    *
//Semester.txt*
//FILEDSLop     *
//FILEDSSv      *
//FILEDSGV *
//FILECSV*

#define FILESCHOOLYEAR "SchoolYear.txt"




unsigned int nam();
void CreateSchoolYear(SchoolYear& S);
SchoolYear present(const string& S);
void inputDL(const string& fileName1, const string& fileName2);
void taoDLgia(const SchoolYear& Y);
void exportFileToImport(const SchoolYear& Y);