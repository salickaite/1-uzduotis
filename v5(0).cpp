#include "funkcijos.h"
#include <cstdio>
#include "laikmatis.h"

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;



int main()
{
    laikmatis t0;
    laikmatis t;

    int studentu_sk;
    cout << "Iveskite studentu skaiciu: ";
    cin >> studentu_sk;
    cout << studentu_sk << " studentu:" << "\n";
   
    cout << endl << "NAUDOJANT VEKTORIUS: " << endl << endl;


    t0.reset();
    t.reset();
    if (studentu_sk == 1000) { nuskaitymas_v("stud1000.txt"); }
    else if (studentu_sk == 10000) { nuskaitymas_v("stud10000.txt"); }
    else if (studentu_sk == 100000) { nuskaitymas_v("stud100000.txt"); }
    else if (studentu_sk == 1000000) { nuskaitymas_v("stud1000000.txt"); }
    else if (studentu_sk == 10000000) { nuskaitymas_v("stud10000000.txt"); }
    else {
        cout << "KLAIDA" << endl;
        exit(EXIT_FAILURE);
    }

    float t1_vec = t.elapsed();
    cout << "Duomenu NUSKAITYMAS truko: " << t1_vec << " s" << endl;

    t.reset();
    padalijimas_v(grupe_vec);
    float t2_vec = t.elapsed();
    float t0_vec = t0.elapsed();
    cout << "Studentu DALIJIMAS i vektorius uztruko: " << t2_vec << " s" << endl;
    cout << "Visas testo laikas: " << t0_vec << " s" << endl << endl;


    grupe_vec.clear();
    vargsiukai_l.clear();
    kietiakai_v.clear();

    cout << "NAUDOJANT LISTUS: " << endl << endl;
    
    if (studentu_sk == 1000) { nuskaitymas_l("stud1000.txt"); }
    else if (studentu_sk == 10000) { nuskaitymas_l("stud10000.txt"); }
    else if (studentu_sk == 100000) { nuskaitymas_l("stud100000.txt"); }
    else if (studentu_sk == 1000000) { nuskaitymas_l("stud1000000.txt"); }
    else if (studentu_sk == 10000000) { nuskaitymas_l("stud10000000.txt"); }
    else {
        cout << "KLAIDA" << endl;
        exit(EXIT_FAILURE);
    }
    float t1_lst = t.elapsed();
    cout << "Duomenu NUSKAITYMAS truko: " << t1_lst << " s" << endl;

    t.reset();
    padalijimas_l(grupe_lst);
    float t2_lst = t.elapsed();
    float t0_lst = t0.elapsed();
    cout << "Studentu DALIJIMAS i listus truko: " << t2_lst << " s" << endl;

    isvedimas_l(vargsiukai_l, "vargsiukai.txt");
    isvedimas_l(kietiakai_l, "kietiakai.txt");
    cout << "Visas testo laikas: " << t0_lst << " s" << endl;



    grupe_lst.clear();
    vargsiukai_l.clear();
    kietiakai_l.clear();
}
