#include "funkcijos.h"
#include "laikmatis.h"
#include <numeric>

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


void pild(studentas& kint) {

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
    if (ivestis == 'a'|| ivestis == 'A') {
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

float mediana(vector<float> vec) {
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

void create_file(string name, float sk) {
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

//VEKTORIAI

void nuskaitymas_v(string read) {

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
        while (s >> k) 
        {
            tempas.nd.push_back(k);
        }

        tempas.egz = tempas.nd.back();
        tempas.nd.pop_back();

        sum = std::accumulate(tempas.nd.begin(), tempas.nd.end(), 0);

        vid = sum / tempas.nd.size();

        float med = mediana(tempas.nd);

        tempas.gal_vid = vid * 0.4 + 0.6 * tempas.egz;
        tempas.gal_med = med * 0.4 + 0.6 * tempas.egz;
        grupe_vec.push_back(tempas);

    }

}

void padalijimas_v(vector<studentas>& vec) 
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

void isvedimas_v(vector<studentas>& vec, string pav) 
{
    std::ofstream failas;
    failas.open(pav);
    failas << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis balas" << "\n";
    for (auto p : vec) 
    {

        failas << setw(20) << left << p.vardas << setw(20) << left << p.pavarde << setw(20) << left << p.gal_vid << "\n";
    }

    failas.close();
}


//LISTAI

void nuskaitymas_l(string read) 
{

    string eil;
    list<string> eilutes;

    ifstream failas(read);
    if (!failas) 
    {
        throw exception();
    }
    while (failas) 
    {
        if (!failas.eof()) 
        {
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
        while (s >> k) 
        {
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

void padalijimas_l(list<studentas>& lst) {

    for (auto p : lst) {
        if (p.gal_vid < 5) {
            vargsiukai_l.push_back(p);
        }
        else {
            kietiakai_l.push_back(p);
        }

    }

}

void isvedimas_l(list<studentas>& lst, string pav) 
{
    std::ofstream failas;
    failas.open(pav);
    failas << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis balas" << "\n";
    for (auto p : lst) {

        failas << setw(20) << left << p.vardas << setw(20) << left << p.pavarde << setw(20) << left << p.gal_vid << "\n";
    }

    failas.close();
}