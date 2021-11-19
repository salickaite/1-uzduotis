# 1-uzduotis
# Užduoties aprašymas
1. Vartotojas pasirenka ar nori automatiškai generuoti failą ir atlikti jo duomenų nuskaitymo bei rūšiavimo į dvi grupes spartą. 
  - Jei pasirenkama 'T' (taip):
      - Prašoma įvesti duomenų kiekį. Pagal nurodytą skaičių programa sukuria failą su tiek studentų kiek nurodė vartotojas. Faile yra saugomi studentų vardai, pavardės, galutiniai įvertinimai. Programa nuskaito failą ir nuskaitymo laiką atspausdina ekrane.
      - Vartotojas pasirenka, kuria strategija rūšioti studentus pagal galutinį pažymį:
        - Kuriami du vektoriai 'kietiakai' ir 'vargsiukai';
        - Studentai, su mažesniu nei 5 galutiniu įvertinimu perkeliami į konteinerį 'vargsiukai' ir ištrinami iš pradinio.
      Ekrane išvedama informacija kiek laiko užtruko rūšiavimas, o urūšiuoti duomenys išvedami į du atskirus failus.
  - Jei vartotojas pasirenka 'N' (ne):
      - Prašoma pasirinkti ar duomenis nori nuskaityti iš failo ar įvesti patys.
          - Jei pasirenkama nuskaityti iš failo, tai duomenys yra nuskaitomi nuo failo "kursiokai.txt". Jei failas egzistuoja, duomenys nuskaitomi į vektorių ir leidžiama pasirinkti ar galutinį pažymį atspausdinti pagal vidurkį ar medianą.
          - Jei pasirenkamas įvedimas ranka, prašoma pasirinkti ar egzamino bei namų darbų pažymius sugeneruoti automatiškai ar įvesti ranka.
           
            - Abiem atvejais prašoma įvesti studentų skaičių bei vardus ir pavardes.
            - Pasirinkus automatinį pažymių generavimą prašomą įvesti jų kiekį.
            - Pasirinkus įvedimą patiems, suvedus visus pažymius parašyti simbolį '+'.
            - Prašoma pasirinkti ar galutinį pažymį norima matyti suskaičiuotą pagal medianą ar vidurkį.
      - Ekrane atspausdinami studentų vardai ir pavardės su pasirinktu galutinio pažymio išvedimu.
# v0.1
- Sukurta struktūra "studentas";
- Įvedamas studentų skaičius, vardai ir pavardės;
- Pildydamas duomenis, vartotojas gali pasirinkti ar studento namų darbų pažymius bei egzamino įvertį, nori suvesti pats, ar leis kompiuteriui automatiškai sugeneruoti;
- Spausdinant rezultatus vartotojas gali pasirinkti ar galutinį pažymį matyti su mediana, ar su vidurkiu.

# v0.2
- Versiją, kurioje buvo naudojamas vektorius, papildome nauja funkcija, kuri leidžiančia nuskaityti duomenis iš failo;
- Jei buvo pasirinkta duomenis imti iš pateikto "txt" failo, rezultatai bus atspausdinami į ekraną, taip pat, kaip ir suvedant ranka;
- Duomenys apie studentą rūšiuojami pagal pavardes.

# v0.3
- Sukurti atskiri header failai, į kuriuos buvo perkelta struktūra "studentas" bei kitos funkcijos;
- Buvo pridėtas išimčių valdymas (runtime_error, invalid_argument).

# v0.4
- Pridėta galimybė vartotojui pasirinkti ar atlikti programos veiksmo greičio analizę ar ne;
- Įrašasnt duomenis į naujus txt failus yra naudojama ne srand funkcija, o panaudota random biblioteka;
- Sugeneruoti atsitiktiniai failai su studentų vardais, pavardėm bei galutiniais pažymiais;
- Studentai, pagal galutinius įvertinimus buvo suskirtyti į "vargšiukus" ir "kietiakus" (jei galutinis balas < 5.0 "vargšiukai", jei galutinis balas >= 5.0 "kietiakai");
- Atskyrus studentus į dvi grupes, duomenys surašomi į txt failus.

![image](https://user-images.githubusercontent.com/90153125/139930341-c12f808c-d563-4ed9-9f8c-61300b7468f7.png)

![image](https://user-images.githubusercontent.com/90153125/139930472-9ee5fc3e-5941-429a-931b-bc25d407b99a.png)

![image](https://user-images.githubusercontent.com/90153125/139930620-f837a891-36db-454f-9d26-e3861882eed6.png)

![image](https://user-images.githubusercontent.com/90153125/139931186-651b7203-65c1-4555-9299-5afeeb6a1be1.png)

![image](https://user-images.githubusercontent.com/90153125/139939070-a586deaa-52e7-43af-b574-4d9da995b6d7.png)

# v0.5
- Atliktas Vector ir List struktūrų spartos palyginimas, kai duomenys yra nuskaitomi iš failų bei kai yra atliekamas studentų rūšiavimas į dvi grupes.
- Sistemos parametrai: CPU - AMD Ryzen 5 3500U with Radeon Vega Mobile Gfx 2.10 GHz; RAM - 8.00 GB; SSD - 237 GB.

**Vektoriaus struktūra**

|               | Nuskaitymas   | Rūšiavimas    |
| ------------- | ------------- | ------------- |
| 1 000         | 0.0256597 s   | 0.0002017 s   |
| 10 000        | 0.0427622 s   | 0.0005745 s   |
| 100 000       | 0.257686 s    | 0.0060052 s   |
| 1 000 000     | 2.38144 s     | 0.0625788 s   |
| 10 000 000    | 26.8282 s     | 0.637084 s    |


**List struktūra**

|               | Nuskaitymas   | Rūšiavimas    |
| ------------- | ------------- | ------------- |
| 1 000         | 0.0039055 s   | 0.0002804 s   |
| 10 000        | 0.024662 s    | 0.0027216 s   |
| 100 000       | 0.278273 s    | 0.0259769 s   |
| 1 000 000     | 2.76988 s     | 0.287499 s    |
| 10 000 000    | 30.5464 s     | 3.29583 s     |

# v1.0

Lyginamos dvi strategijos, kurios dalina nuskaito duomenis ir surūšiuoja studentus į dvi grupes.

1. Studentai dedami į konteinerius 'kietiakai' ir 'vargsiukai pagal galutinį įvertinimą;
2. Studentai, kurių pažymys yea mažesnis nei už 5, yra perkeliami į konteinerį 'vargsiukai' ir ištrinami iš pradinio konteinerio 'studentai'. Konteineryje 'studentai' lieka tik 'kietiakai' t.y. studentai, kurių galutinis balas yra lygus arba didesnis negu 5.

Rūšiavimo laikai:

**1 strategija**

|               | Rūšiavimas 'vector'  | Rūšiavimas 'list'   |
| ------------- | -------------        | -------------       |
| 1 000         | 4.36e-05 s           | 0.0002464 s         |
| 10 000        | 0.0010357 s          | 0.0025794 s         |
| 100 000       | 0.0081072 s          | 0.0545146 s         |
| 1 000 000     | 0.102605 s           | 0.345809 s          |
| 10 000 000    | 6.26013 s            | 8.96787 s           |


**2 strategija**

|               | Rūšiavimas 'vector'  | Rūšiavimas 'list'   |
| ------------- | -------------        | -------------       |
| 1 000         | 8.13e-05 s           | 0.0001993 s         |
| 10 000        | 0.0016487 s          | 0.0015196 s         |
| 100 000       | 0.0082672 s          | 0.0315691 s         |
| 1 000 000     | 0.0516942 s          | 0.333509 s          |
| 10 000 000    | 0.58994 s            | 3.46819 s           |

Iš rezultatų matyti, kad sparčiau veikia antra strategija.

