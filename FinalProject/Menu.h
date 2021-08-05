#pragma once
#include "console.h"
#include "Header.h"

void Information();
void Frames(int x, int y, int width, int length);
void Team();
int MenuHeader();
void Instruction();
void SignInFrames(int item);
int EffectAgree(int x, int y, string c);
void ClearEffectAgree(int x, int y, string c);
void EffectSuccess(int x, int y, string c);
void EffectFailed(int x, int y, string c);
void CreateSemesterForm();
int SignIn(ListLop ds, ListGV dsgv, SinhVien& sv, GiaoVien& gv);
char* TOUPPER(char* c);
void ChangePasswordStudent(SinhVien& sv, ListLop& dsl, string newpass, const SchoolYear& Y);
void MenuChangePasswordStudent(SinhVien& sv, ListLop& dsl, const SchoolYear& Y);
void ChangePasswordManager(GiaoVien& gv, ListGV& dsgv, string newpass, const SchoolYear& Y);
void MenuChangePasswordManager(GiaoVien& gv, ListGV& dsgv, const SchoolYear& Y);
void MenuChildren(string s[], int& vitri, int size);
void Menu(ListLop ds, ListGV dsgv, ListCourses dsmon, SinhVien& sv, GiaoVien& gv, int& choice, int se, SchoolYear Y, listSemester& l);
void CreateSignInForm();
void CleanForm(int x, int y, int width, int length);
void FormMenu();
void FormMenu2();
void FormMenu3();