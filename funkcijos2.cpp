#include "funkcijos2.h"

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::list;

bool is_lower(const studentas& a, const studentas& b)
{
    return a.gal_vid < b.gal_vid;
}

bool passed(studentas& s)
{
    return s.gal_vid >= 5;
}

void vector_dal_1(std::vector<studentas>& studentai)
{
    int kiek = studentai.size();
    vector<studentas> kietiakai;
    vector<studentas> vargsiukai;

    kietiakai.reserve(0.6 * kiek);
    vargsiukai.reserve(0.6 * kiek);

    auto start2 = std::chrono::high_resolution_clock::now();
    for (studentas& stud : studentai)
    {
        if (stud.gal_vid < 5)
        {
            vargsiukai.push_back(stud);
        }
        else
            kietiakai.push_back(stud);
    }
    studentai.clear();

    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff2 = end2 - start2;
    cout << kiek << " studentu, 1-a strategija RUSIAVIMAS i dvi grupes truko " << diff2.count() << " s" << endl;

    string vargsiukai_pav = "v1_vargsiukai" + to_string(kiek) + ".txt";
    v_write(vargsiukai, vargsiukai_pav);
    vargsiukai.clear();

    string kietiakai_pav = "v1_kietiakai" + to_string(kiek) + ".txt";
    v_write(kietiakai, kietiakai_pav);
    kietiakai.clear();
}

void vector_dal_2(std::vector<studentas>& studentai)
{
    int kiekis = studentai.size();
    vector<studentas> vargsiukai;
    vargsiukai.reserve(0.6 * kiekis);
    std::sort(studentai.begin(), studentai.end(), is_lower);

    auto start2 = std::chrono::high_resolution_clock::now();
    vector<studentas>::iterator ite = std::find_if(studentai.begin(), studentai.end(), passed);
    vargsiukai = vector<studentas>(studentai.begin(), ite);
    vector<studentas>::iterator ite1 = studentai.begin();
    studentai.erase(studentai.begin(), ite);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff2 = end2 - start2;
    cout << kiekis << " studentu, 2-a strategija RUSIAVIMAS i dvi grupes truko " << diff2.count() << " s" << endl;

    string vargsiukai_pav = "v2_vargsiukai" + to_string(kiekis) + ".txt";
    v_write(vargsiukai, vargsiukai_pav);
    vargsiukai.clear();

    string kietiakai_pav = "v2_kietiakai" + to_string(kiekis) + ".txt";
    v_write(studentai, kietiakai_pav);
    studentai.clear();
}

void list_dal_1(std::list<studentas>& studentai)
{
    int kiekis = studentai.size();

    list<studentas> kietiakai;
    list<studentas> vargsiukai;

    auto start2 = std::chrono::high_resolution_clock::now();

    for (studentas& stud : studentai)
    {
        if (stud.gal_vid < 5)
        {
            vargsiukai.push_back(stud);
        }
        else
            kietiakai.push_back(stud);
    }

    studentai.clear();

    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff2 = end2 - start2;
    cout << kiekis << " studentu, 1-a strategija RUSIAVIMAS i dvi grupes truko " << diff2.count() << " s" << endl;

    string vargsiukai_pav = "l1_vargsiukai" + to_string(kiekis) + ".txt";
    l_write(vargsiukai, vargsiukai_pav);
    vargsiukai.clear();

    string kietiakai_pav = "l1_kietiakai" + to_string(kiekis) + ".txt";
    l_write(kietiakai, kietiakai_pav);
    kietiakai.clear();
}

void list_dal_2(std::list<studentas>& studentai)
{
    int kiekis = studentai.size();

    list<studentas> vargsiukai;
    studentai.sort(is_lower);

    auto start2 = std::chrono::high_resolution_clock::now();
    list<studentas>::iterator it = std::find_if(studentai.begin(), studentai.end(), passed);
    vargsiukai = list<studentas>(studentai.begin(), it);
    studentai.erase(studentai.begin(), it);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff2 = end2 - start2;
    cout << kiekis << " studentu, 2-a strategija RUSIAVIMAS i dvi grupes truko " << diff2.count() << " s" << endl;

    string vargsiukai_pav = "l2_vargsiukai" + to_string(kiekis) + ".txt";
    l_write(vargsiukai, vargsiukai_pav);
    vargsiukai.clear();

    string kietiakai_pav = "l2_kietiakai" + to_string(kiekis) + ".txt";
    l_write(studentai, kietiakai_pav);
    studentai.clear();
}

