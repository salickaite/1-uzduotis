#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <stdlib.h> 
#include <stdio.h> 
#include <iterator>
using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::vector;
using std::setw;
using std::fixed;
using std::left;
using std::ifstream;
using std::ws;
using std::stringstream;
using std::distance;
using std::istream_iterator;
using std::setprecision;

struct studentas {
    string vardas, pavarde;
    vector<int> pazymiai;
    int egzaminas{};
    double gal_v{}, gal_m{};
};

double median(vector<int> pazymiai);
void read_from_file(vector<studentas>& reiksme, int* pazKiekis);
void print(vector<studentas>  reiksme);

unsigned int count_words(string const& str)
{
    stringstream stream(str);
    return distance(istream_iterator <string>(stream), istream_iterator <string>());
}

bool compare(studentas& studentasA, studentas& studentasB)
{
    return studentasA.vardas < studentasB.vardas;
}

int main() {
    double studentu_sk = 0;
    int pazSum = 0;
    int pazKiekis = 0;
    int pazymys = 0;
    int gen = 0;
    string input_type;
    double mediana = 0;
    string ivestis;
    vector<studentas> grupe;

    cout << "Iveskite F, jeigu duomenis norite nuskaitysite is failo\nIveskite P, jeigu duomenis ivesite patys" << endl;
    cin >> input_type;

    while (input_type != "f" && input_type != "F" && input_type != "p" && input_type != "p")
    {
        cout << "Ivedete netinkama reiksme. Pasirinkite f - failas arba p - patys" << endl;
        cin >> input_type;
    }
    if (input_type == "f" || input_type == "F")
    {
        read_from_file(grupe, &pazKiekis);
        sort(grupe.begin(), grupe.end(), compare);
        print(grupe);
    }
    else if (input_type == "p" || input_type == "P")
    {
        cout << "Iveskite studentu skaiciu :" << endl;
        cin >> studentu_sk;

        while (studentu_sk <= 0 || cin.fail() || (int)studentu_sk != studentu_sk)
        {
            cin.clear();
            cout << "Netinkamas skaicius. Bandykite dar karta: " << endl;
            cin.ignore(256, '\n');
            cin >> studentu_sk;
        }
        for (int i = 0; i < studentu_sk; i++)
        {
            cin.clear();
            grupe.push_back(studentas());
            cout << "Iveskite " << i + 1 << "-o studento varda ir pavarde:" << endl;
            cin >> grupe[i].vardas >> grupe[i].pavarde;
            cout << "Iveskite 1 jei norite sugeneruoti pazymius " << i+1 << " studentui, jei norite ivesti pazymius patys paspauskite +" << endl;
            cin >> ivestis;
            if (ivestis == "1")
            {
                cout << "Iveskite namu darbu skaiciu: " << endl;
                cin >> gen;

                while (gen <= 0 || cin.fail())
                {
                    cin.clear();
                    cout << "Netinkamas ivedimas. Bandykite dar karta. " << endl;
                    cin.ignore(256, '\n');
                    cin >> gen;
                }
                cout << "Namu darbu sugeneruoti pazymiai:" << endl;
                for (int j = 0; j < gen; j++)
                {
                    pazymys = (rand() % 10) + 1;
                    grupe[i].pazymiai.push_back(pazymys);
                    cout << pazymys << endl;
                    pazSum += pazymys;
                }
                pazKiekis = gen;
                pazymys = -1;
            }
            else
            {
                cout << "Iveskite " << i+1 << "-o studento pazymius, kai suvesite visus pazymius iveskite -1:" << endl;
                cin >> pazymys;

                while (pazymys != -1)
                {
                    if (pazymys >= 1 && pazymys <= 10) {
                        grupe[i].pazymiai.push_back(pazymys);
                        pazSum += pazymys;
                        pazKiekis += 1;
                    }
                    else {
                        cin.clear();
                        cout << "Netinkamas pazymys. " << endl;
                        cin.ignore(256, '\n');
                    }
                    cin >> pazymys;
                }
            }
            cout << "Iveskite 1 jei norite sugeneruoti egzaminu pazymi " << i+1 << " studentui, jei norite ivesti pazymius patys spauskite +" << endl;
            cin >> ivestis;
            if (ivestis == "1")
            {
                pazymys = (rand() % 10) + 1;
                grupe[i].egzaminas = pazymys;
                cout << "Sugeneruotas egzamino ivertinimas:\n" << grupe[i].egzaminas << endl;
            }
            else
            {
                cout << "Iveskite " << i + 1 << "-o studento egazmino pazymi: ";

                while (pazymys < 1 || pazymys > 10)
                {
                    cin >> pazymys;

                    if (pazymys >= 1 && pazymys <= 10) {
                        grupe[i].egzaminas = pazymys;
                    }
                    else
                    {
                        cin.clear(); 
                        cout << "Neteisingas ivedimas. " << endl;
                        cin.ignore(256, '\n');
                    }
                }
            }
            if (pazKiekis == 0) pazKiekis = 1;

            grupe[i].gal_v = 0.4 * ((double)pazSum / (double)pazKiekis) + 0.6 * grupe[i].egzaminas;
            grupe[i].gal_m = 0.4 * (median(grupe[i].pazymiai)) + 0.6 * grupe[i].egzaminas;
            pazymys = 0;
            pazSum = 0;
            pazKiekis = 0;
        }
        string pas;
        cout << "Iveskite, M jei galutini pazymi norite matyti su mediana, V jei su vidurkiu" << endl;
        cin >> pas;
        while (pas != "m" && pas != "v" && pas != "V" && pas != "M")
        {
            cout << "Netinkama ivestis. Pasirinkite M - mediana arba V - vidurkis" << endl;
            cin >> pas;
        }

        if (pas == "m" || pas == "M") {
            cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" 
                 << left << setw(20) << "Galutinis (Med.)" << endl;
            cout << "----------------------------------------------" << endl;

            for (const auto& stud_nr : grupe) {
                cout << left << setw(20) << stud_nr.vardas << left << setw(20) << stud_nr.pavarde;
                cout << left << setw(20) << stud_nr.gal_m << endl;
            }
        }
        else if (pas == "v" || pas == "V")
        {
            cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" 
                 << left << setw(20) << "galutinisVidurkis (Vid.)" << endl;
            cout << "----------------------------------------------" << endl;

            for (const auto& stud_nr : grupe) {
                cout << left << setw(20) << stud_nr.vardas << left << setw(20) << stud_nr.pavarde;
                cout << left << setw(20) << setprecision(3) << stud_nr.gal_v << endl;
            }
        }
    }
    return 0;
}



void read_from_file(vector<studentas>& reiksme, int* pazKiekis)
{
    int stud = 0;
    int laikinas;
    string failas;
    ifstream fileRead;
    int suma = 0;
    string pas;
    fileRead.open("kursiokai.txt");

    cout << "Iveskite M jei norite, kad galutinis pazymis butu su mediana, jeigu su vidurkiu - V" << endl;
    cin >> pas;
    while (pas != "m" && pas != "v" && pas != "V" && pas != "M")
    {
        cout << "Buvo ivesta netinkama reiksme. Pasirinkite m - mediana arba v - vidurkis" << endl;
        cin >> pas;
    }

    if (fileRead.fail())
    {
        cout << "Nepavyko atidaryti failo";
        exit(EXIT_FAILURE);
    }

    if (fileRead.is_open())
    {
        getline(fileRead >> ws, failas);
        *pazKiekis = count_words(failas) - 3;

        while (fileRead)
        {
            reiksme.resize(reiksme.size() + 1);
            fileRead >> reiksme.at(stud).vardas;
            if (fileRead.eof())
            {
                reiksme.pop_back();
                break;
            }
            fileRead >> reiksme.at(stud).pavarde;

            for (int i = 0; i < *pazKiekis; i++)
            {
                fileRead >> laikinas;
                suma += laikinas;
                reiksme.at(stud).pazymiai.push_back(laikinas);
            }
            fileRead >> reiksme.at(stud).egzaminas;
            if (pas == "m" || pas == "M")
            {
                reiksme.at(stud).gal_m = 0.4 * median(reiksme.at(stud).pazymiai) + 0.6 * reiksme.at(stud).egzaminas;
            }
            else if (pas == "v" || pas == "V")
            {
                reiksme.at(stud).gal_v = 0.4 * suma / *pazKiekis + 0.6 * reiksme.at(stud).egzaminas;
            }
            suma = 0;
            stud++;
        }
    }
}

void print(vector<studentas> reiksme)
{
    std::ofstream output;
    output.open("rezultatai1.txt");
    output << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" 
           <<left << setw(20) << "Galutinis (vid.) / Galutinis (med.)" << endl;
    output << "----------------------------------------------------------------------" << endl;
    for (int i = 0; i < reiksme.size(); i++)
    {
        output << left << setw(20) << reiksme[i].vardas << left << setw(20) << reiksme[i].pavarde 
               << left << setw(20) << std::setprecision(3) << left << reiksme[i].gal_v << left << reiksme[i].gal_m << endl;
    }
}

double median(vector<int> pazymiai)
{
    int ilgis = pazymiai.size();

    if (ilgis == 0) {
        throw std::domain_error("negalima skaiciuoti medianos tusciam vektoriui");
    }
    sort(pazymiai.begin(), pazymiai.end());

    if (ilgis % 2 == 0) {
        return (pazymiai[ilgis / 2] + pazymiai[(ilgis / 2) - 1]) / 2.;
    }
    else {
        return pazymiai[ilgis / 2];
    }
}
