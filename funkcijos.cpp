#include "funkcijos.h"
#include "laikmatis.h"
#include <numeric>

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream> 
#include <random>
#include <numeric>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::left;
using std::setprecision;
using std::sort;
using std::getline;
using std::vector;
using std::ifstream;
using std::stringstream;
using std::exception;

vector<studentas> grupe_vec;
vector<studentas> vargsiukai_v;
vector<studentas> kietiakai_v;

list<studentas> grupe_lst;
list<studentas> vargsiukai_l;
list<studentas> kietiakai_l;


void pild(studentas& kint)
{

    float sum = 0, vid = 0, n, med;
    int count = 0;

    cout << "Iveskite studento varda ir pavarde: ";
    cin >> kint.vardas >> kint.pavarde;

    cout << "Jei norite, kad studentu pazymiai butu generuojami AUTOMATISKAI spauskite \"A\".\n Jei norite pazymius suvesti PATYS spauskite \"P\".";
    char ivestis;
    cin >> ivestis;
    while (cin.fail() || (ivestis != 'a' && ivestis != 'A' && ivestis != 'p' && ivestis != 'P')) {
        cout << "Netinkamai ivesta komanda. Pasirinkite A (automatiskai) arba P (patys). " << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> ivestis;
    }
    if (ivestis == 'a' || ivestis == 'A') {
        cout << "Iveskite pazymiu skaiciu: ";
        int sk;

        tikrinimas(sk);
        for (int i = 0; i < sk; i++) {
            int x = rand() % 10 + 1;
            kint.nd.push_back(x);
            sum += kint.nd[i];
        }
        kint.egz = rand() % 10 + 1;
        cout << "Jei norite, kad galutinis pazymys butu pateiktas su VIDURKIU iveskite \"V\".\n Jei su MEDIANA iveskite \"M\".  ";
        cin >> kint.skaiciavimas;
        while (cin.fail() || (kint.skaiciavimas != 'v' && kint.skaiciavimas != 'V' && kint.skaiciavimas != 'm' && kint.skaiciavimas != 'M')) {
            cout << "Netinkamai ivesta komanda. Pasirinkite V (vidurkis) arba M (mediana)" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> kint.skaiciavimas;
        }
        vid = sum / sk;
        med = mediana(kint.nd);
        kint.gal_vid = vid * 0.4 + 0.6 * kint.egz;
        kint.gal_med = med * 0.4 + 0.6 * kint.egz;

    }
    else if (ivestis == 'p' || ivestis == 'P')
    {
        cout << "Iveskite namu darbu pazymius (kai baigsite, iveskite bet kokia raide): " << endl;
        while (cin >> n) {
            kint.nd.push_back(n);
            sum += n;
            count++;
        }


        while (count == 0) {
            cout << "Netinkamai ivesta komanda. Iveskite bent 1 pazymi. " << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            while (cin >> n) {
                kint.nd.push_back(n);
                sum += n;
                count++;
            }
        }

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


        cout << "Iveskite egzamino pazymi: ";

        tikrinimas(kint.egz);

        cout << "Jei norite, kad galutinis pazymys butu pateiktas su VIDURKIU iveskite \"V\".\n Jei su MEDIANA iveskite \"M\".  ";
        cin >> kint.skaiciavimas;
        while (cin.fail() || (kint.skaiciavimas != 'v' && kint.skaiciavimas != 'V' && kint.skaiciavimas != 'm' && kint.skaiciavimas != 'M')) {
            cout << "Netinkamai ivesta komanda. Pasirinkite V (vidurkis) arba M (mediana)" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> kint.skaiciavimas;
        }

        vid = sum / count;
        med = mediana(kint.nd);

        kint.gal_vid = vid * 0.4 + 0.6 * kint.egz;
        kint.gal_med = med * 0.4 + 0.6 * kint.egz;
    }
}

void printas(studentas& kin)
{

    if (kin.skaiciavimas == 'v' || kin.skaiciavimas == 'V')
    {
        cout << setw(20) << left << kin.vardas << setw(20) << left << kin.pavarde << setw(20) << left << setprecision(3) << kin.gal_vid << endl;
    }
    else
        cout << setw(20) << left << kin.vardas << setw(20) << left << kin.pavarde << setw(20) << left << setprecision(3) << kin.gal_med << endl;
}

float mediana(vector<float> vec)
{
    typedef vector<float>::size_type vecSize;
    vecSize size = vec.size();
    if (size == 0)
        throw std::domain_error("Netinkama ivestis. Negalima skaiciuoti medianos tusciame vektoriuje. ");
    sort(vec.begin(), vec.end());
    vecSize vid = size / 2;
    return size % 2 == 0 ? (vec[vid] + vec[vid - 1]) / 2 : vec[vid];
}

bool compare_final(studentas& a, studentas& b)
{
    return a.gal_vid > b.gal_vid;
}

void print_student(studentas& stud)
{
    cout << setw(20) << left << stud.vardas << setw(20) << left << stud.pavarde << setw(20) << left << setprecision(3) << stud.gal_vid << setw(20) << left << setprecision(3) << stud.gal_med << endl;
}

void tikrinimas(int& a) {
    cin >> a;
    do {
        try {
            if (cin.fail()) { throw std::runtime_error("Netinkamai ivesta komanda. \n"); }
        }
        catch (const std::runtime_error& e) {
            cout << e.what();
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Bandykite dar karta: ";
            cin >> a;
        }

    } while (cin.fail() == true);
}

void create_file(string name, float sk)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 10);

    std::ofstream failas;
    failas.open(name);

    for (int i = 1; i < sk + 1; i++) {
        int nd1 = dist(mt);
        int nd2 = dist(mt);
        int nd3 = dist(mt);
        int nd4 = dist(mt);
        int nd5 = dist(mt);
        int egz = dist(mt);
        failas << "Vardas" << i << "    Pavarde" << i << "        " << setw(10) << left << nd1 << setw(10) << left << nd2 << setw(10) << left << nd3 << setw(10) << left << nd4 << setw(10) << left << nd5 << setw(10) << left << egz << endl;
    }
    failas.close();

}

bool func(studentas st) {
    return st.gal_vid < 5;

}

bool passed(studentas st) {
    return st.gal_vid >= 5;

}



//VEKTORIAI
void nuskaitymas_v(string read)
{

    string eil;
    vector<string> eilutes;

    ifstream failas(read);
    if (!failas) {
        throw exception();
    }
    while (failas) {
        if (!failas.eof()) {
            std::getline(failas, eil);
            eilutes.push_back(eil);

        }
        else break;

    }
    failas.close();

    eilutes.pop_back();


    for (auto eil : eilutes) {
        stringstream s(eil);
        studentas tempas;
        float sum, vid;
        s >> tempas.vardas >> tempas.pavarde;
        int k;
        while (s >> k) {
            tempas.nd.push_back(k);

        }

        tempas.egz = tempas.nd.back();
        tempas.nd.pop_back();

        sum = std::accumulate(tempas.nd.begin(), tempas.nd.end(), 0);

        vid = sum / tempas.nd.size();

        float med = mediana(tempas.nd);



        tempas.gal_vid = 0.4 * vid + 0.6 * tempas.egz;
        tempas.gal_med = med * 0.4 + 0.6 * tempas.egz;
        grupe_vec.push_back(tempas);


    }



}

void padalijimas_v1(vector<studentas>& vec)
{
    for (auto p : vec) {
        if (p.gal_vid < 5) {
            vargsiukai_v.push_back(p);
        }
        else {
            kietiakai_v.push_back(p);
        }
    }
}

void padalijimas_v2(vector<studentas>& vec)
{

    for (studentas p : vec) {
        if (p.gal_vid < 5) {
            vargsiukai_v.push_back(p);

        }
    }
    vec.erase(remove_if(vec.begin(), vec.end(), func), vec.end());
}


void padalijimas_v3(vector<studentas>& vec)
{
    std::partition(vec.begin(), vec.end(), passed);

    vector<studentas>::iterator it = std::partition_point(vec.begin(), vec.end(), passed);
    for (/*it*/; it != vec.end(); it++)
    {
        vargsiukai_v.push_back(*it);
    }

    vec.erase(std::partition_point(vec.begin(), vec.end(), passed), vec.end());
}

void isvedimas_v(vector<studentas>& vec, string pav) {
    std::ofstream failas;
    failas.open(pav);
    failas << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis balas" << "\n";
    for (auto p : vec) {

        failas << setw(20) << left << p.vardas << setw(20) << left << p.pavarde << setw(20) << left << p.gal_vid << "\n";
    }

    failas.close();
}


//LISTAI:

void nuskaitymas_l(string read)
{
    string eil;
    vector<string> eilutes;

    ifstream failas(read);
    if (!failas)
    {
        throw exception();
    }
    while (failas)
    {
        if (!failas.eof()) {
            std::getline(failas, eil);
            eilutes.push_back(eil);

        }
        else break;
    }
    failas.close();

    eilutes.pop_back();

    for (auto eil : eilutes)
    {
        stringstream s(eil);
        studentas tempas;
        float sum, vid;
        s >> tempas.vardas >> tempas.pavarde;
        int k;
        while (s >> k) {
            tempas.nd.push_back(k);

        }

        tempas.egz = tempas.nd.back();
        tempas.nd.pop_back();


        sum = std::accumulate(tempas.nd.begin(), tempas.nd.end(), 0);


        vid = sum / tempas.nd.size();

        float med = mediana(tempas.nd);



        tempas.gal_vid = vid * 0.4 + 0.6 * tempas.egz;
        tempas.gal_med = med * 0.4 + 0.6 * tempas.egz;
        grupe_lst.push_back(tempas);


    }



}
void padalijimas_l1(list<studentas>& lst)
{

    for (auto p : lst) {
        if (p.gal_vid < 5)
        {
            vargsiukai_l.push_back(p);
        }
        else
        {
            kietiakai_l.push_back(p);
        }

    }

}

void padalijimas_l2(list<studentas>& lst)
{

    for (studentas p : lst) {
        if (p.gal_vid < 5)
        {
            vargsiukai_l.push_back(p);

        }
    }
    lst.erase(remove_if(lst.begin(), lst.end(), func), lst.end());
}

void isvedimas_l(list<studentas>& lst, string pav) {
    std::ofstream failas;
    failas.open(pav);
    failas << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis balas" << "\n";
    for (auto p : lst)
    {
        failas << setw(20) << left << p.vardas << setw(20) << left << p.pavarde << setw(20) << left << p.gal_vid << "\n";
    }

    failas.close();
}

void testas() {
    cout << "NAUDOJANT VEKTORIUS:" << endl << endl;

    nuskaitymas_v("stud100000.txt");
    Timer t;
    padalijimas_v1(grupe_vec);
    float t1 = t.elapsed();
    cout << "Padalijimas 1 budu uztruko: " << t1 << " s" << endl;

    kietiakai_v.clear();
    vargsiukai_v.clear();

    t.reset();
    padalijimas_v2(grupe_vec);
    float t2 = t.elapsed();
    cout << "Padalijimas 2 budu uztruko: " << t2 << " s" << endl;
    //cout << "Santykis t1/t2: " << t1 / t2 << endl << endl;

    //system("pause");
    cout << endl;
    //************************************************************************************


    cout << "NAUDOJANT LISTUS:" << endl << endl;

    nuskaitymas_l("stud100000.txt");
    t.reset();
    padalijimas_l1(grupe_lst);
    t1 = t.elapsed();
    cout << "Padalijimas 1 budu uztruko: " << t1 << " s" << endl;

    kietiakai_l.clear();
    vargsiukai_l.clear();

    t.reset();
    padalijimas_l2(grupe_lst);
    t2 = t.elapsed();
    cout << "Padalijimas 2 budu uztruko: " << t2 << " s" << endl;
    //cout << "Santykis t1/t2: " << t1 / t2 << endl << endl;

    //system("pause");
    cout << endl;
    //*************************************************************************************


    nuskaitymas_v("stud100000.txt");
    t.reset();

    padalijimas_v1(grupe_vec);
    t1 = t.elapsed();
    kietiakai_v.clear();
    vargsiukai_v.clear();
    t.reset();

    padalijimas_v2(grupe_vec);
    t2 = t.elapsed();
    grupe_vec.clear();
    kietiakai_v.clear();
    vargsiukai_v.clear();
    nuskaitymas_v("stud100000.txt");
    t.reset();

    padalijimas_v3(grupe_vec);


    float t3 = t.elapsed();



    cout << "Padalijimas 1 budu uztruko: " << t1 << " s" << endl;
    cout << "Padalijimas 2 budu uztruko: " << t2 << " s" << endl;
    cout << "Padalijimas 3 budu uztruko: " << t3 << " s" << endl;

    //cout << "Santykis t1/t3: " << t1 / t3 << endl;
    //cout << "Santykis t2/t3: " << t2 / t3 << endl;
}


void uzpildymas() {
    int k;
    char answ, g;
    string fileName;
    studentas temp_student;
    float vid, med;


    cout << "Jei norite duomenis nuskaityti is failo iveskite T (taip) arbe N (ne): ";
    cin >> answ;
    if (answ == 't' || answ == 'T')
    {
        cout << "Iveskite failo pavadinima: ";
        cin >> fileName;

        try {
            nuskaitymas_v(fileName);
        }


        catch (std::exception& e) {
            cout << "Failas neegzistuoja! Patikrinkite failo varda ir meginkite is naujo..." << endl;
            exit(EXIT_FAILURE);

        }
        char ats2;
        cout << "Jei norite studentus padalinti i 2 grupes ir isvesti i 2 failus spauskite T (taip) arba N (ne): " << endl;
        cin >> ats2;
        if (ats2 == 't' || ats2 == 'T') 
        {
            padalijimas_v2(grupe_vec);
            isvedimas_v(grupe_vec, "kietiakai.txt");
            isvedimas_v(vargsiukai_v, "vargsiukai.txt");
        }
        else {
            cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis(Vid.)/Galutinis(Med.)" << endl;
            for (auto p : grupe_vec) { printas(p); }
        }


    }
    else 
    {
        cout << "Iveskite studentu skaiciu: ";

        tikrinimas(k);
        for (int i = 0; i < k; i++) {
            studentas temp;
            pild(temp);
            grupe_vec.push_back(temp);
        }
        char ats3;
        cout << "Ar norite studentus padalinti i 2 grupes ir isvesti i 2 failus? Jei taip, iveskite 't', jei ne - iveskite 'n': " << endl;
        cin >> ats3;
        if (ats3 == 't' || ats3 == 'T') 
        {
            padalijimas_v2(grupe_vec);
            isvedimas_v(grupe_vec, "kietiakai.txt");
            isvedimas_v(vargsiukai_v, "vargsiukai.txt");
        }
        else {
            cout << "\n" << endl;
            cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis(Vid.)/Galutinis(Med.)" << endl;
            for (auto p : grupe_vec)
                printas(p);
        }
    }


}