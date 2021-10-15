#include "print_student.h"

using std::cout;
using std::endl;
using std::setw;
using std::left;
using std::fixed;
using std::setprecision;

void print_student(std::vector<studentas> grupe, string type)
{
    std::sort(grupe.begin(), grupe.end(), compare_alphabet);
    cout << endl;
    if (type == "V" || type == "v")
    {
        cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis(vid.)" << endl;
        cout << "----------------------------------------------------------------" << endl;
        for (int i = 0; i < grupe.size(); i++)
        {
            cout << setw(20) << left << grupe[i].vardas << setw(20) << left << grupe[i].pavarde
                << setw(20) << fixed << setprecision(2) << left << grupe[i].gal_vid << endl;
        }
    }
    else if (type == "M" || type == "m")
    {
        cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis(med.)" << endl;
        cout << "----------------------------------------------------------------" << endl;
        for (int i = 0; i < grupe.size(); i++)
        {
            cout << setw(20) << left << grupe[i].vardas << setw(20) << left << grupe[i].pavarde
                << setw(20) << fixed << setprecision(2) << left << grupe[i].gal_med << endl;
        }
    }   
}