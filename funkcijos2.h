#pragma once

#include "studentas.h"
#include "write.h"

#include <chrono>
#include <iostream>
#include <string>
#include <list>
#include <algorithm>


bool is_lower(const studentas& a, const studentas& b);

bool passed(studentas& s);

void vector_dal_1(std::vector<studentas>& studentai);

void vector_dal_2(std::vector<studentas>& studentai);

void list_dal_1(std::list<studentas>& studentai);

void list_dal_2(std::list<studentas>& studentai);