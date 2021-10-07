#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <time.h>
#include <numeric>
#include <fstream>
#include <sstream> 

using std::cout;
using std::cin;
using std::string;
using std::setw;
using std::endl;
using std::setprecision;
using std::left;
using std::sort;
using std::vector;
using std::accumulate;
using std::fixed;
using std::ifstream;
using std::getline;
using std::stringstream;

struct studentas
{
    string vardas, pavarde;
    int ndKiekis;
    vector <float> nd;
    float egz;
    float gal_vid, gal_med;
};

void print_student(vector <studentas> grupe, string type);
float mediana(vector<float> pazymiai);
bool compare_alphabet(studentas a, studentas b);

int main()
{
    srand(time(NULL));
    float vid, med;
    string ivestis, gal_ivestis, read_type;
    studentas temp_student;
    vector <studentas> grupe;

    cout << "Jei norite duomenis nuskaityti is FAILO spauskite F.\nJei norite ivesti ranka, spauskite R. ";
    cin >> read_type;
    while (read_type != "F" && read_type != "f" && read_type != "R" && read_type != "r")
    {
        cout << "Netinkama ivestis. Bandykite dar karta: ";
        cin >> read_type;
    }
    if (read_type == "F" || read_type == "f")
    {
        int rows = 0, cols = 0;
        float temp_paz;
        string eil, item;
        ifstream open_f("kursiokai.txt");
        if (open_f.fail())
        {
            cout << "Nepavyko atidaryti failo.";
            return 0;
        }
        while (open_f)
        {
            if (!open_f.eof())
            {
                getline(open_f, eil);
                rows++;
                if (rows == 1)
                {
                    stringstream ss(eil);
                    while (ss >> item) cols++;
                }
                open_f >> temp_student.vardas >> temp_student.pavarde;
                temp_student.nd.reserve(cols - 3);
                for (int j = 0; j < cols - 3; j++)
                {
                    open_f >> temp_paz;
                    if (temp_paz < 1 || temp_paz > 10)
                    {
                        cout << "Pazymiai turi buti nuo 1 iki 10. Patikrinkite faile esancius duomenis.";
                        return 0;
                    }
                    else temp_student.nd.push_back(temp_paz);
                }
                open_f >> temp_student.egz;
                vid = accumulate(temp_student.nd.begin(), temp_student.nd.end(), 0.0) / temp_student.nd.size();
                temp_student.gal_vid = 0.4 * vid + 0.6 * temp_student.egz;
                med = mediana(temp_student.nd);
                temp_student.gal_med = 0.4 * med + 0.6 * temp_student.egz;
                grupe.push_back(temp_student);
                temp_student.nd.clear();

            }
            else break;
        }

        open_f.close();
    }
    if (read_type == "R" || read_type == "r")
    {
        int studentu_sk, x;
        float laik_paz;
        cout << "Iveskite studentu skaiciu: ";
        cin >> studentu_sk;
        while (studentu_sk < 0)
        {
            cout << "Netinkamas skaicius. Bandykite dar karta:  ";
            cin >> studentu_sk;
        }
        grupe.reserve(studentu_sk);

        cout << "Jei norite, kad studentu pazymiai butu generuojami AUTOMATISKAI spauskite \"A\".\n Jei norite pazymius suvesti PATYS spauskite \"P\".";
        cin >> ivestis;
        while (ivestis != "A" && ivestis != "a" && ivestis != "P" && ivestis != "p")
        {
            cout << "Netinkamas simbolis. Bandykite dar karta.  ";
            cin >> ivestis;
        }

        for (int i = 0; i < studentu_sk; i++)
        {
            cout << "Iveskite " << i + 1 << " -o studento varda ir pavarde : ";
            cin >> temp_student.vardas >> temp_student.pavarde;

            if (ivestis == "A" || ivestis == "a")
            {
                cout << "Iveskite " << i + 1 << " -o studento namu darbu kieki : ";
                cin >> x;
                while (x <= 0)
                {
                    cout << "Namu darbu kiekis negali buti 0. Bandykite dar karta. ";
                    cin >> x;
                }
                temp_student.nd.reserve(x);
                for (int j = 0; j < x; j++)
                {
                    temp_student.nd.push_back(rand() % 10 + 1);
                }
                temp_student.egz = rand() % 10 + 1;
                vid = accumulate(temp_student.nd.begin(), temp_student.nd.end(), 0.0) / temp_student.nd.size();
                temp_student.gal_vid = 0.4 * vid + 0.6 * temp_student.egz;
                med = mediana(temp_student.nd);
                temp_student.gal_med = 0.4 * med + 0.6 * temp_student.egz;
            }
            else if (ivestis == "P" || ivestis == "p")
            {
                cout << "Iveskite namu darbu pazymius: ";
                while (cin >> laik_paz)
                {
                    if (laik_paz < 1 || laik_paz > 10)
                    {
                        cout << "Pazymys turi buti nuo 1 iki 10. Bandykite dar karta: ";
                    }
                    else { temp_student.nd.push_back(laik_paz); };

                }
                if (temp_student.nd.empty())
                {
                    cout << "Privaloma ivesti namu darbu pazymius. Bandykite dar karta.";
                    return 1; 
                }
                cin.clear();
                cin.ignore(10000, '\n');

                cout << "Iveskite " << i + 1 << "-o studento egzamino pazymi : ";
                cin >> temp_student.egz;
                while (temp_student.egz < 1 || temp_student.egz > 10)
                {
                    cout << "Egzamino pazymys turi buti nuo 1 iki 10. Bandykite dar karta: ";
                    cin >> temp_student.egz;
                }
                vid = accumulate(temp_student.nd.begin(), temp_student.nd.end(), 0.0) / temp_student.nd.size();
                temp_student.gal_vid = 0.4 * vid + 0.6 * temp_student.egz;
                med = mediana(temp_student.nd);
                temp_student.gal_med = 0.4 * med + 0.6 * temp_student.egz;
            }

            grupe.push_back(temp_student);
            temp_student.nd.clear();

        }
    }
        
    cout << "Jei norite, kad galutinis pazymys butu pateiktas su VIDURKIU iveskite \"V\".\n Jei su MEDIANA iveskite \"M\". ";
    cin >> gal_ivestis;
    while (gal_ivestis != "V" && gal_ivestis != "v" && gal_ivestis != "M" && gal_ivestis != "m")
    {
        cout << "Netinkamas simbolis. Bandykite dar karta: ";
        cin >> gal_ivestis;
    }

    print_student(grupe, gal_ivestis);
    
}

void print_student(vector<studentas> grupe, string type)
{
    sort(grupe.begin(), grupe.end(), compare_alphabet);
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

float mediana(vector <float> pazymiai)
{
    float median;
    int n = pazymiai.size();
    sort(pazymiai.begin(), pazymiai.end());
    if (n % 2 == 0) median = (pazymiai[n / 2] + pazymiai[n / 2 + 1]) / 2.0;
    else median = pazymiai[n / 2];
    return median;
}



bool compare_alphabet(studentas a, studentas b)
{
    if (a.pavarde != b.pavarde) return a.pavarde < b.pavarde;
    else return a.vardas < b.vardas;
}
