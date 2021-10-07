#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <time.h>
#include <numeric>

using std::cout;
using std::cin;
using std::string;
using std::setw;
using std::endl;
using std::setprecision;
using std::left;
using std::sort;
using std::fixed;

struct studentas 
{
    string vardas, pavarde;
    int ndKiekis;
    float *nd;
    float egz;
    float gal_vid, gal_med;
};

void print_student(studentas grupe[], int sk, string type);
float mediana(float pazymiai[], int size);

int main()
{
    srand(time(NULL));
    
    cout << "Iveskite studentu skaiciu: ";
    int studentu_sk, x, ndKiekis=1;
    float suma=0.;
    string ivestis, gal_ivestis;
    cin >> studentu_sk;
    while (studentu_sk <= 0)
    {
        cout << "Netinkamas skaicius. Bandykite dar karta: ";
        cin >> studentu_sk;
    }
    studentas *grupe = new studentas[studentu_sk];
    cout << "Jei norite, kad studentu pazymiai butu generuojami AUTOMATISKAI spauskite \"A\".\n Jei norite pazymius suvesti PATYS spauskite \"P\".";
    cin >> ivestis;
    while (ivestis != "A" && ivestis != "a" && ivestis != "P" && ivestis != "p")
    {
        cout << "Netinkamas simbolis. Bandykite dar karta. ";
        cin >> ivestis;
    }
    
    cout << "Jei norite, kad galutinis pazymys butu pateiktas su VIDURKIU iveskite \"V\".\n Jei su MEDIANA iveskite \"M\".";
    cin >> gal_ivestis;
    while (gal_ivestis != "V" && gal_ivestis != "v" && gal_ivestis != "M" && gal_ivestis != "m")
    {
        cout << "Netinkamas simbolis. Bandykite dar karta: ";
        cin >> gal_ivestis;
    }
    
    for (int i = 0; i < studentu_sk; i++)
    {
        cout << "Iveskite " << i + 1 << " -o studento varda ir pavarde : ";
        cin >> grupe[i].vardas >> grupe[i].pavarde;

        
        suma = 0;
        
        if (ivestis == "A" || ivestis == "a")
        {
            cout << "Iveskite " << i + 1 << " -o studento namu darbu kieki : ";
            cin >> x;
            while (x <= 0)
            {
                cout << "Netinkama ivestis. Bandykite dar karta: ";
                cin >> x;
            }
            grupe[i].nd = new float[x];
            for (int j = 0; j < x; j++) 
            { 
                grupe[i].nd[j] = rand() % 10 + 1; 
                suma += grupe[i].nd[j];
            }
            grupe[i].egz = rand() % 10 + 1;
            grupe[i].gal_vid = 0.4 * suma / float(x) + 0.6 * grupe[i].egz;
            grupe[i].gal_med = 0.4 * mediana(grupe[i].nd, x) + 0.6 * grupe[i].egz;
        }
        else if (ivestis == "P" || ivestis == "p") 
        {
            grupe[i].nd = new float[ndKiekis];
            cout << "Iveskite " << i + 1 << " -o studento namu darbu pazymius. Kai baigsite iveskite -1: ";
            for (int k = 0; k < ndKiekis; k++)
            {
                
                cin >> grupe[i].nd[k];
                if (grupe[i].nd[k] == -1) break;
                while (grupe[i].nd[k] < 1 || grupe[i].nd[k] > 10)
                {
                    cout << "Pazymys turi buti nuo 1 iki 10. Bandykite dar karta: ";
                    cin >> grupe[i].nd[k];
                }
                
                float* temp = new float[ndKiekis + 1];
                for (int j = 0; j < ndKiekis; j++)
                {
                    temp[j] = grupe[i].nd[j];
                }
                delete[](grupe[i].nd);
                ndKiekis += 1;
                grupe[i].nd = new float[ndKiekis];
                for (int j = 0; j < ndKiekis; j++)
                {
                   grupe[i].nd[j] = temp[j];
                }
                delete[](temp);
            }
            for (int z = 0; z < ndKiekis; z++)
            {
                suma += grupe[i].nd[z];
            }
            cout << "Iveskite " << i + 1 << "-o studento egzamino pazymi : ";
            cin >> grupe[i].egz;
            while (grupe[i].egz < 1 || grupe[i].egz > 10)
            {
                cout << "Egzamino pazymys turi buti nuo 1 iki 10. Bandykite dar karta: ";
                cin >> grupe[i].egz;
            }
            grupe[i].gal_vid = 0.4 * suma / float(ndKiekis) + 0.6 * grupe[i].egz;
            grupe[i].gal_med = 0.4 * mediana(grupe[i].nd, ndKiekis) + 0.6 * grupe[i].egz;
        }
        delete[] grupe[i].nd;
    }
    
    print_student(grupe, studentu_sk, gal_ivestis);
    delete[] grupe;
}

void print_student(studentas grupe[], int sk, string type)
{
    cout << endl;
    if (type == "V" || type == "v")
    {
        cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis(vid.)" << endl;
        cout << "----------------------------------------------------------------" << endl;
        for (int i = 0; i < sk; i++)
        {
            cout << setw(20) << left << grupe[i].vardas << setw(20) << left << grupe[i].pavarde
                << setw(20) << fixed << setprecision(2) << left << grupe[i].gal_vid << endl;
        }
    }
    else if (type == "M" || type == "m")
    {
        cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis(med.)" << endl;
        cout << "----------------------------------------------------------------" << endl;
        for (int i = 0; i < sk; i++)
        {
            cout << setw(20) << left << grupe[i].vardas << setw(20) << left << grupe[i].pavarde
                << setw(20) << fixed << setprecision(2) << left << grupe[i].gal_med << endl;
        }
    }
   
}

float mediana(float pazymiai[], int size)
{
    float median;
    sort(pazymiai, pazymiai + size);
    if (size % 2 == 0) median = (pazymiai[size / 2] + pazymiai[size / 2 + 1]) / 2.0;
    else median = pazymiai[size / 2];
    return median;

}
