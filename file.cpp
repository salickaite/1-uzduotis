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

void file(int kiek)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1., 10.);
    double gal_rand;

    auto start_test = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::high_resolution_clock::now();

    string pav = "studentai" + to_string(kiek) + ".txt"; //pav - failo pavadinimas
    ofstream outfile(pav);
    outfile << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis" << endl;
    for (int i = 1; i <= kiek; i++)
    {
        gal_rand = dist(mt);
        outfile << setw(20) << left << "Vardas" + to_string(i) << setw(20) << left << "Pavarde" + to_string(i)
            << setw(20) << fixed << setprecision(2) << left << gal_rand << endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo su " << kiek << " studentu KURIMAS uztruko " << diff.count() << " s" << endl;
    vector<studentas> studentai;
    vector<studentas> kietiakai;
    vector<studentas> vargsiukai;

    studentas temp;
    string eil;
    auto start1 = std::chrono::high_resolution_clock::now();
    studentai.resize(kiek);
    ifstream openf("studentai" + to_string(kiek) + ".txt");
    try
    {
        if (openf.fail()) throw std::runtime_error("Nepavyko atidaryti txt failo.");
    }
    catch (std::runtime_error& e)
    {
        cout << e.what();
        exit(1);
    }
    getline(openf, eil);
    for (int i = 0; i < kiek; i++)
    {
        openf >> studentai[i].vardas >> studentai[i].pavarde >> studentai[i].gal_vid;
    }
    openf.close();
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff1 = end1 - start1;
    cout << "Failo is " << kiek << " studentu NUSKAITYMAS uztruko " << diff1.count() << " s" << endl;

    auto start2 = std::chrono::high_resolution_clock::now();
    kietiakai.reserve(0.6 * kiek);
    vargsiukai.reserve(0.6 * kiek);
    for (int i = 0; i < kiek; i++)
    {
        if (studentai[i].gal_vid < 5) vargsiukai.push_back(studentai[i]);
        else kietiakai.push_back(studentai[i]);
    }
    studentai.clear();
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff2 = end2 - start2;
    cout << kiek << " studentu RUSIAVIMAS i dvi grupes uztruko " << diff2.count() << " s" << endl;

    auto start3 = std::chrono::high_resolution_clock::now();
    string vargsiukai_pav = "vargsiukai" + to_string(kiek) + ".txt";
    string kietiakai_pav = "kietiakai" + to_string(kiek) + ".txt";
    ofstream outfile_varg(vargsiukai_pav);
    outfile_varg << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis" << endl;
    for (int j = 0; j < vargsiukai.size(); j++)
    {
        outfile_varg << setw(20) << left << vargsiukai[j].vardas << setw(20) << left << vargsiukai[j].pavarde
            << setw(20) << fixed << setprecision(2) << left << vargsiukai[j].gal_vid << endl;
    }
    vargsiukai.clear();
    auto end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff3 = end3 - start3;
    cout << kiek << " studentu surasymas i VARGSIUKU faila uztrko " << diff3.count() << " s" << endl;

    auto start4 = std::chrono::high_resolution_clock::now();
    ofstream outfile_kiet(kietiakai_pav);
    outfile_kiet << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis" << endl;
    for (int j = 0; j < kietiakai.size(); j++)
    {
        outfile_kiet << setw(20) << left << kietiakai[j].vardas << setw(20) << left << kietiakai[j].pavarde
            << setw(20) << fixed << setprecision(2) << kietiakai[j].gal_vid << endl;
    }
    kietiakai.clear();

    auto end4 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff4 = end4 - start4;
    cout << kiek << " studentu surasymas i KIETIAKU faila uztruko " << diff4.count() << " s" << endl;

    auto end_test = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> test_time = end_test - start_test;
    cout << kiek << " irasu TESTO LAIKAS " << test_time.count() << " s\n" << endl;
}