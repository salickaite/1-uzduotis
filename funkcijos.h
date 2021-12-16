#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream> 
#include <random>
#include <numeric>
#include <list>

using std::string;
using std::vector;
using std::list;

struct studentas {
    string vardas, pavarde;
    vector<float> nd;
    int egz;
    float gal_vid;
    float gal_med;
    char skaiciavimas;

};

extern vector<studentas> grupe_vec;
extern vector<studentas> nabagai_v;
extern vector<studentas> protingi_v;

extern list<studentas> grupe_lst;
extern list<studentas> nabagai_l;
extern list<studentas> protingi_l;

void pild(studentas& kint);
void printas(studentas& kin);
float mediana(vector<float> vec);
bool compare_final(studentas& a, studentas& b);
void print_student(studentas& stud);
void tikrinimas(int& a);
void create_file(string name, float sk);

void nuskaitymas_v(string read);
void padalijimas_v1(vector<studentas>& vec);
void padalijimas_v2(vector<studentas>& vec);
void isvedimas_v(vector<studentas>& vec, string pav);

void padalijimas_v3(vector<studentas>& vec);

void nuskaitymas_l(string read);
void padalijimas_l1(list<studentas>& lst);
void padalijimas_l2(list<studentas>& lst);
void isvedimas_l(list<studentas>& lst, string pav);


bool func(studentas st);
bool passed(studentas st);

void testas();
void uzpildymas();