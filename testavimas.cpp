#include "testavimas.h"
#include "studentas.h"

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
using std::list;

// VEKTORIAI

void v_write(vector<studentas>& v, string pav)
{
	ofstream outfile(pav);
	outfile << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis" << endl;
	for (studentas s : v)
	{
		outfile << left << setw(20) << s.vardas << left << setw(20) << s.pavarde << left << setw(20) << s.gal_vid << endl;
	}
}

void vector_t(int kiek)
{
	cout << endl;
	cout << "VECTOR REZULTATAI: " << endl;
	auto start1 = std::chrono::high_resolution_clock::now();
	studentas temp;

	vector<studentas> studentai;

	studentai.resize(kiek);
	string eil;
	ifstream openf("studentai" + to_string(kiek) + ".txt");
	try
	{
		if (openf.fail()) throw std::runtime_error("Nepavyko atidaryti failo");
	}
	catch (std::runtime_error& e)
	{
		cout << e.what();
		exit(1);
	}
	
	getline(openf, eil);
	for (int i = 0; i < kiek; i++)
	{
		openf >> temp.vardas >> temp.pavarde >> temp.gal_vid;
		studentai.push_back(temp);
	}
	openf.close();
	auto end1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff1 = end1 - start1;
	cout << "Failo su " << kiek << " studentu NUSKAITYMAS uztruko " << diff1.count() << " s" << endl;

	auto start2 = std::chrono::high_resolution_clock::now();
	vector<studentas> kietiakai;
	vector<studentas> vargsiukai;

	kietiakai.reserve(0.6 * kiek);
	vargsiukai.reserve(0.6 * kiek);
	for (studentas& st : studentai)
	{
		if (st.gal_vid < 5)
		{
			vargsiukai.push_back(st);
		}
		else kietiakai.push_back(st);
	}

	studentai.clear();
	auto end2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff2 = end2 - start2;
	cout << kiek << " studentu RUSIAVIMAS i dvi grupes uztruko " << diff2.count() << " s" << endl;

	string kietiakai_pav = "v_kietiakai" + to_string(kiek) + ".txt";
	v_write(kietiakai, kietiakai_pav);
	kietiakai.clear();

	string vargsiukai_pav = "v_vargsiukai" + to_string(kiek) + ".txt";
	v_write(vargsiukai, vargsiukai_pav);
	vargsiukai.clear();
}

// LIST'AI

void l_write(list<studentas>& l, string pav)
{
	ofstream outfile(pav);
	outfile << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis" << endl;
	for (studentas s : l)
	{
		outfile << left << setw(20) << s.vardas << left << setw(20) << s.pavarde << left << setw(20) << s.gal_vid << endl;
	}
}

void list_t(int kiek)
{
	cout << endl;
	cout << "LIST REZULTATAI: " << endl;
	auto start1 = std::chrono::high_resolution_clock::now();
	studentas temp;
	
	list<studentas> studentai;
	list<studentas>::iterator iter;
	iter = studentai.begin();
	string eil;
	string pav1, pav2;
	int kietiaku_kiek = 0, vargsiuku_kiek = 0;

	ifstream openf("studentai" + to_string(kiek) + ".txt");

	try
	{
		if (openf.fail()) throw std::runtime_error("Nepavyko atidaryti failo");
	}
	catch (std::runtime_error& e)
	{
		cout << e.what();
		exit(1);
	}

	getline(openf, eil);
	for (int i = 0; i < kiek; i++)
	{
		openf >> temp.vardas >> temp.pavarde >> temp.gal_vid;
		studentai.push_back(temp);
	}

	openf.close();
	auto end1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff1 = end1 - start1;
	cout << "Failo su " << kiek << " studentu NUSKAITYMAS uztruko " << diff1.count() << " s" << endl;


	auto start2 = std::chrono::high_resolution_clock::now();

	list<studentas> kietiakai;
	list<studentas> vargsiukai;

	list<studentas>::iterator kietiakai_iter;
	list<studentas>::iterator vargsiukai_iter;

	kietiakai_iter = kietiakai.begin();
	vargsiukai_iter = vargsiukai.begin();

	for (studentas& st : studentai)
	{
		if (st.gal_vid < 5)
		{
			vargsiukai.push_back(st);
		}
		else kietiakai.push_back(st);
	}

	studentai.clear();
	auto end2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff2 = end2 - start2;
	cout << kiek << " studentu RUSIAVIMAS i dvi grupes uztruko " << diff2.count() << " s" << endl; 

	string kietiakai_pav = "l_kietiakai" + to_string(kiek) + ".txt";
	l_write(kietiakai, kietiakai_pav);

	string vargsiukai_pav = "l_vargsiukai" + to_string(kiek) + ".txt";
	l_write(vargsiukai, vargsiukai_pav);
}
