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
    char ats;
    cout << "Jei norite atlikti programos veikimo greicio analize spauskite T (taip), jei nenorite spauskite N (ne). ";
    cin >> ats;
    if (ats == 't' || ats == 'T')
    {
        testas();
    }
    else
    {
        int sz;
        string pav;
        char ats1;
        cout << "Jei norite atsitiktinai sugeneruoti studentu faila spauskite T (taip), jei nenorite spauskite N (ne). ";
        cin >> ats1;
        if (ats1 == 't' || ats1 == 'T')
        {
            cout << "Iveskite failo pavadinima ir dydi (t.y. studentu skaiciu)  : ";
            cin >> pav >> sz;
            create_file(pav, sz);
        }
        else 
        { 
            uzpildymas(); 
        }
    }
}
