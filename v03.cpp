#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <time.h>
#include <numeric>
#include <fstream>
#include <sstream> 
#include <random>
#include <chrono>
#include "studentas.h"
#include "mediana.h"
#include "compare_alphabet.h"
#include "print_student.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
using std::accumulate;
using std::ifstream;
using std::getline;
using std::stringstream;
using std::ofstream;
using std::to_string;


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
    /*if (read_type == "F" || read_type == "f")
    {
        int rows = 0, cols = 0;
        float temp_paz;
        string eil, item;
        ifstream open_f("kursiokai.txt");
        try
        {
          if (open_f.fail()) throw std::runtime_error("Nepavyko atidaryti nurodyto failo");
        }
        catch (std::runtime_error& e)
        {
          cout << e.what();
          exit(1);
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
                    try
                    {
                      if (temp_paz < 1 || temp_paz > 10) throw std::runtime_error("Namu darbu pazymiai turi buti nuo 1 iki 10. Patikrinkite txt faile esancius duomenis. ");
                    }
                    catch (std::runtime_error& e)
                    {
                      cout << e.what();
                      exit(1);
                    }
                    temp_student.nd.push_back(temp_paz);
                }
                open_f >> temp_student.egz;
                try
                {
                  if (temp_student.egz < 1 || temp_student.egz > 10) throw std::runtime_error("Egzamino ivertinimo pazymys turi buti nuo 1 iki 10. Patikrinkite txt faile esancius duomenis. ");
                }
                catch (std::runtime_error& e)
                {
                  cout <<e.what();
                  exit(1);
                }
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
    }*/
    if (read_type == "R" || read_type == "r")
    {
        cout << "Jei norite, kad studentu pazymiai butu generuojami AUTOMATISKAI spauskite \"A\".\n Jei norite pazymius suvesti PATYS spauskite \"P\".";
        cin >> ivestis;

        while (ivestis != "A" && ivestis != "a" && ivestis != "P" && ivestis != "p")
        {
          try
          {
            if (ivestis != "A" && ivestis != "a" && ivestis != "P" && ivestis != "p") throw std::invalid_argument("Netinkamai ivesta komanda. ");
          }
          catch (std::invalid_argument& e)
          {
            cout << e.what();
            cin.clear();
            cout << "Pasirinkite A (automatiskai) arba P (patys). ";
            cin >> ivestis;
          }
        }
        int studentu_sk, x;
        float laik_paz;
        cout << "Iveskite studentu skaiciu: ";
        cin >> studentu_sk;

        while (studentu_sk < 0)
        {
          try
          {
            if (studentu_sk < 0) throw std::invalid_argument("Studentu skaicius turi buti didesnis arba lygus 1. ");
          }
          catch (std::invalid_argument& e)
          {
            cout << e.what() << endl;
            cin.clear();
            cout << "Iveskite studentu skaiciu. ";
            cin >> studentu_sk;
          }
        }
        
        //while (ivestis != "A" && ivestis != "a" && ivestis != "P" && ivestis != "p")
        //{
        //    cout << "Netinkamas simbolis. Bandykite dar karta.  ";
        //    cin >> ivestis;
        //}

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
                  try
                  {
                    if (x < 0) throw std::invalid_argument("Namu darbu kiekis negali buti 0. Bandykite dar karta. ");
                  }
                  catch (std::invalid_argument& e)
                  {
                    cout << e.what() << endl;
                    cin.clear();
                    cout << "Iveskite namu darbu kieki: ";
                    cin >> x;
                  }
                  
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
            if (ivestis == "P" || ivestis == "p")
            {
                cout << "Iveskite namu darbu pazymius, kai baigsite paspauskite +: ";
                while (cin >> laik_paz)
                {
                  while (laik_paz < 1 || laik_paz > 10){
                  try 
                  {
                    if (laik_paz < 1 || laik_paz > 10) throw std::invalid_argument("Namu darbu pazymiai turi buti nuo 1 iki 10 (imtinai). ");
                  }
                  catch (std::invalid_argument& e)
                  {
                    cout << e.what() << endl;
                    cin.clear();
                    cout << "Iveskite namu darbu pazymi dar karta. ";
                    cin >> laik_paz;
                  }
                  }
                  temp_student.nd.push_back(laik_paz);

                }
                if (temp_student.nd.empty())
                {
                    cout << "Privaloma ivesti namu darbu pazymius. Bandykite dar karta.";
                    return 1; 
                }
                cin.clear();
                cin.ignore(10000, '\n');  

                cout << "Iveskite " << i+1 << "-o studento egzamino pazymi: ";
                cin >> temp_student.egz;

                while (temp_student.egz < 1 || temp_student.egz > 10)
                {
                  try
                  {
                    if (temp_student.egz < 1 || temp_student.egz > 10) throw std::invalid_argument("Egzamino pazymys turi buti nuo 1 iki 10 (imtinai). ");
                  }
                  catch (std::invalid_argument& e)
                  {
                    cout << e.what() << endl;
                    cin.clear();
                    cout << "Iveskite egzamino pazymi. ";
                    cin >> temp_student.egz;
                  }
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
      try
      {
        if (gal_ivestis != "V" && gal_ivestis != "v" && gal_ivestis != "M" && gal_ivestis != "m") throw std::invalid_argument("Neatpazinta komanda");
      }
      catch (std::invalid_argument& e)
      {
        cout << e.what() << endl;
        cin.clear();
        cout << "Pasirinkite V (vidurkis) arba M (mediana) ";
        cin >> gal_ivestis;
      }

    }

    print_student(grupe, gal_ivestis);

    cin.get();
    
}
