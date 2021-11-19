#pragma once

#include "studentas.h"


#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <iostream>

#include <list>
#include <chrono>
#include <fstream>


using std::string;


bool compare_alphabet(struct studentas a, struct studentas b);

float mediana(std::vector<float> pazymiai);

void print_student(std::vector <studentas> grupe, string type);
