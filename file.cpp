#include "file.h"

using std::cout;
using std::left;
using std::setw;
using std::endl;
using std::fixed;
using std::setprecision;
using std::string;
using std::to_string;
using std::ofstream;
using std::ifstream;
using std::vector;

// failo kurimas

void file(int kiekis)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1., 10.);
    double gal_rand;

    string pav = "studentai" + to_string(kiekis) + ".txt"; //pav - failo pavadinimas
    ofstream outfile(pav);
    outfile << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis" << endl;
    for (int i = 1; i <= kiekis; i++)
    {
        gal_rand = dist(mt);
        outfile << setw(20) << left << "Vardas" + to_string(i) << setw(20) << left << "Pavarde" + to_string(i)
            << setw(20) << fixed << setprecision(2) << left << gal_rand << endl;
    }
}