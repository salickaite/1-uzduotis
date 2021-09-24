#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <cstdlib>
using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::setw;
using std::setprecision;
using std::left;

struct studentas {
    string vardas, pavarde;
    int* pazymiai;
    int nd;
    int egzaminas;
    double galutinis;
};

double median(int *pazymiai, int egzaminas, int nd);

int main() {
    int studentu_sk = 0;
    int pazSum = 0;
    int pazKiekis = 0;
    int pazymys = 0;
    int gen = 0;
    string ivestis;
    cout << "Iveskite studentu skaiciu :" << endl;
    cin >> studentu_sk;

    while (studentu_sk <= 0 || cin.fail())
    {
        cin.clear();
        cout << "Netinkamas skaicius. Bandykite dar karta" << endl;
        cin.ignore(256, '\n');
        cin >> studentu_sk;
    }

    studentas *grupe = new studentas[studentu_sk];

    for (int i = 0; i < studentu_sk; i++)
    {
        cout << "Iveskite " << i + 1 << "-o studento varda ir pavarde:" << endl;
        cin >> grupe[i].vardas >> grupe[i].pavarde;
        cout << "Iveskite namu darbu skaiciu:" << endl;
        cin >> grupe[i].nd;

        while (grupe[i].nd <= 0 || cin.fail())
        {
            cin.clear();
            cout << "Netinkamas skaicius. Bandykite dar karta" << endl;
            cin.ignore(256, '\n');
            cin >> grupe[i].nd;
        }

        grupe[i].pazymiai = (int*)malloc(sizeof(int) * grupe[i].nd);

        cout << "Iveskite 1 jei norite sugeneruoti namu darbu pazymius " << i+1 << " studentui, jei norite ivesti pazymius patys paspauskite +" << endl;
        cin >> ivestis;

        if (ivestis == "1") 
        {
            gen = grupe[i].nd;
            cout << "Sugeneruoti skaiciai:" << endl;
            for(int j = 0; j < gen; j++ )
            {   
                pazymys = (rand() % 10) + 1;
                grupe[i].pazymiai[j] = pazymys;
                cout << pazymys << endl;
                pazSum += pazymys;
            }
            pazKiekis = gen;
            pazymys = -1;
        }
        else
        {
            cout << "Iveskite " << i+1 <<"-o studento namu darbu pazymius, kai baigsite paspauskite +:" << endl; //tada vartotojas egzamino pazymi pats tures suvest
            cin >> pazymys;

            for(int k = 0; pazKiekis < grupe[i].nd; k++)
            {
                if (pazymys >= 1 && pazymys <= 10) {
                    grupe[i].pazymiai[k] = pazymys;
                    pazSum += pazymys;
                    pazKiekis += 1;
                }
                else {
                    cin.clear();
                    cout << "Neteisingas ivedimas. " << endl;
                    cin.ignore(256, '\n');
                }
                cin >> pazymys;
            }
        }
        cout << "Iveskite 1 jei norite sugeneruoti egzamino pazymi " << i+1 << " studentui, jei norite ivesti pazymius patys paspauskite +" << endl;
        cin >> ivestis;
        if (ivestis == "1")
        {   
            pazymys = (rand() % 10) + 1;
            grupe[i].egzaminas = pazymys;
            cout << "Sugeneruotas pazymys:\n" << grupe[i].egzaminas << endl;
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

        grupe[i].galutinis = 0.4 * ((double)pazSum / (double)pazKiekis) + 0.6 * grupe[i].egzaminas;
        pazymys = 0;
        pazSum = 0;
        pazKiekis = 0;
    }
    double mediana = 0;
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

        for (int m = 0; m < studentu_sk; m++) 
        {
            mediana = median(grupe[m].pazymiai, grupe[m].egzaminas, grupe[m].nd);
            cout << left << setw(20) << grupe[m].vardas << left << setw(20) << grupe[m].pavarde;
            cout << left << setw(25) << mediana << endl;
        }
    }
    else if (pas == "v" || pas == "V")
    {
        cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" 
             << left << setw(20) << "Galutinis (Vid.)" << endl;
            cout << "-----------------------------------------------------" << endl;

        for (int v = 0; v < studentu_sk; v++) 
        {
            cout << left << setw(20) << grupe[v].vardas << left << setw(20) << grupe[v].pavarde;
            cout << left << setw(25) << std::setprecision(3) << grupe[v].galutinis << endl;
        }
    }
}

double median(int *pazymiai, int egzaminas, int nd)
{
    int* laikinas = new int[nd + 1];

    for (int i = 0; i < nd; i++)
    {
        laikinas[i] = pazymiai[i];
    }
    laikinas[nd] = egzaminas;
    int ilgis = nd+1;
    std::sort(laikinas, laikinas + (nd+1));    

    if (ilgis % 2 == 0) {
        return (laikinas[ilgis / 2] + laikinas[(ilgis / 2) - 1]) / 2.;
    }
    else {
        return laikinas[ilgis / 2];
    }
}
