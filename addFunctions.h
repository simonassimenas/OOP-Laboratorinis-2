#pragma once
#include "mylib.h"

int randomSkaicius();
void failoGeneravimas();
void naudotojoIvestis(vector<Studentas>& grupe);
void pildymas(Studentas& temp);
void output_template();
void spausdinimas(Studentas& temp, string outputPasirinkimas);
bool regexPalyginimas(const Studentas& a, const Studentas& b);
bool getBoolInput();
bool isNumber(const string& str);
string getChoiceInput();
string getStringInput();
int gradeInput();
int autoGradeInput();
int threeInput();