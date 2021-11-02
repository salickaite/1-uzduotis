#pragma once

#include <string>
#include <vector>
#include "funkcijos.h"
using std::string;

struct studentas
{
    string vardas, pavarde;
    int ndKiekis;
    std::vector <float> nd;
    float egz;
    float gal_vid, gal_med;
};