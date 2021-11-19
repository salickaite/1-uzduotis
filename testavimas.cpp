#include "testavimas.h"


using std::cout;
using std::cin;
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

void vector_t(int kiekis)
{
	int skaic;
	cout << endl;
	cout << "VECTOR REZULTATAI: " << endl;
	auto start1 = std::chrono::high_resolution_clock::now();

	vector<studentas> studentai;

	studentai.resize(kiekis);
	string eil;
	ifstream openf("studentai" + to_string(kiekis) + ".txt");
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

	for (auto& i : studentai)
	{
		openf >> i.vardas >> i.pavarde >> i.gal_vid;
	}
	openf.close();
	auto end1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff1 = end1 - start1;
	cout << "Failo su " << kiekis << " studentu NUSKAITYMAS uztruko " << diff1.count() << " s" << endl;

	cout << "Pasirinkite dalijimo strategija: 1 arba 2: ";
	cin >> skaic;
	do {
		try {
			if (skaic != 1 && skaic != 2) throw std::runtime_error("Neatpazinta komanda");
		}
		catch (std::runtime_error& e) {
			cout << e.what() << endl;
			cin.clear();
			cout << "Bandykite is naujo ";
			cin >> skaic;
		}
	} while (skaic != 1 && skaic != 2);
	if (skaic == 1) vector_dal_1(studentai);
	if (skaic == 2) vector_dal_2(studentai);
}

// LIST'AI

void list_t(int kiekis)
{
	int skaic;
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

	ifstream openf("studentai" + to_string(kiekis) + ".txt");

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
	for (int i = 0; i < kiekis; i++)
	{
		openf >> temp.vardas >> temp.pavarde >> temp.gal_vid;
		studentai.push_back(temp);
	}

	openf.close();
	auto end1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff1 = end1 - start1;
	cout << "Failo su " << kiekis << " studentu NUSKAITYMAS uztruko " << diff1.count() << " s" << endl;

	cout << "Pasirinkite dalijimo strategija: 1 arba 2: ";
	cin >> skaic;
	do {
		try {
			if (skaic != 1 && skaic != 2) throw std::runtime_error("Neatpazinta komanda");
		}
		catch (std::runtime_error& e) {
			cout << e.what() << endl;
			cin.clear();
			cout << "Bandykite is naujo ";
			cin >> skaic;
		}
	} while (skaic != 1 && skaic != 2);
	if (skaic == 1) list_dal_1(studentai);
	if (skaic == 2) list_dal_2(studentai);

}