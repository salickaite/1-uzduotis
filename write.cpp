#include "write.h"

using std::vector;
using std::string;
using std::ofstream;
using std::left;
using std::setprecision;
using std::setw;
using std::list;
using std::endl;

void v_write(vector<studentas>& v, string pav)
{
	ofstream outfile(pav);
	outfile << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis" << endl;
	for (studentas s : v)
	{
		outfile << left << setw(20) << s.vardas << left << setw(20) << s.pavarde << left << setw(20) << s.gal_vid << endl;
	}
}

void l_write(list<studentas>& l, string pav)
{
	ofstream outfile(pav);
	outfile << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis" << endl;
	for (studentas s : l)
	{
		outfile << left << setw(20) << s.vardas << left << setw(20) << s.pavarde << left << setw(20) << s.gal_vid << endl;
	}
}