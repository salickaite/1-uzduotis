#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <cstdlib>
using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::vector;
using std::setw;
using std::fixed;
using std::left;

struct studentas {
    string vardas, pavarde;
    vector<int> pazymiai;
    int egzaminas;
    double gal_v, gal_m;
};

double median(vector<int> pazymiai);

int main() {
    double studentu_sk = 0;
    int pazSum = 0;
    int pazKiekis = 0;
    int pazymys = 0;
    int gen = 0;
    double mediana = 0;
    string ivestis;
    vector<studentas> grupe;
    cout << "Iveskite studentu skaiciu :" << endl;
    cin >> studentu_sk;

    while (studentu_sk <= 0 || cin.fail()|| (int)studentu_sk != studentu_sk)
    {
        cin.clear();
        cout << "Netinkamas skaicius. Bandykite dar karta" << endl;
        cin.ignore(256, '\n');
        cin >> studentu_sk;
    }
    for (int i = 0; i < studentu_sk; i++)
    {
        cin.clear();
        grupe.push_back(studentas());
        cout << "Iveskite " << i + 1 << "-o studento varda ir pavarde:" << endl;
        cin >> grupe[i].vardas >> grupe[i].pavarde;
        cout << "Iveskite 1 jei norite sugeneruoti namu darbu pazymius " << i+1 << " studentui, jei norite ivesti pazymius patys paspauskite +" << endl;
        cin >> ivestis;
        if (ivestis == "1")
        {
            cout << "Iveskite namu darbu skaiciu:" << endl;
            cin >> gen;

            while (gen <= 0 || cin.fail())
            {
                cin.clear();
                cout << "Netinkamas skaicius. Bandykite dar karta" << endl;
                cin.ignore(256, '\n');
                cin >> gen;
            }
            cout << "Sugeneruoti skaiciai:" << endl;
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
            cout << "Iveskite " << i+1 <<" studento namu darbu pazymius (noredami baigti iveskite -1):" << endl;
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
                    cout << "Netinkamas skaicius. " << endl;
                    cin.ignore(256, '\n');
                }
                cin >> pazymys;
            }
        }
        cout << "Iveskite 1 jei norite sugeneruoti egzamino pazymi " << i+1 << " studentui, jei norite ivesti pazymi patys paspauskite +" << endl;
        cin >> ivestis;
        if (ivestis == "1")
        {
            pazymys = (rand() % 10) + 1;
            grupe[i].egzaminas = pazymys;
            cout << "Sugeneruotas pazymys:\n" << grupe[i].egzaminas << endl;
        }
        else
        {
            cout << "Iveskite " << i + 1 << "-o studento egazmino ivertinima: ";

            while (pazymys < 1 || pazymys > 10)
            {
                cin >> pazymys;

                if (pazymys >= 1 && pazymys <= 10) {
                    grupe[i].egzaminas = pazymys;
                }
                else
                {
                    cin.clear();
                    cout << "Netinkamas skaicius. " << endl;
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
    while (pas != "m" && pas != "v" && pas != "V" && pas != "M") {
        cout << "Netinkama ivestis. Pasirinkite M - mediana arba V - vidurkis" << endl;
        cin >> pas;
    }

    if (pas == "m" || pas == "M") {
        cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" 
             << left << setw(20) << "Galutinis (Med.)" << endl;
            cout << "-----------------------------------------------------" << endl;

        for (const auto& stud_nr : grupe) {
            cout << left << setw(20) << stud_nr.vardas << left << setw(20) << stud_nr.pavarde;
            cout << left << setw(25) << stud_nr.gal_m << endl;
        }
    }
    else if (pas == "v" || pas == "V")
    {
        cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" 
             << left << setw(20) << "Galutinis (Vid.)" << endl;
            cout << "-----------------------------------------------------" << endl;

        for (const auto& stud_nr : grupe) {
            cout << left << setw(20) << stud_nr.vardas << left << setw(20) << stud_nr.pavarde;
            cout << left << setw(25) << std::setprecision(3) << stud_nr.gal_v << endl;
        }
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
