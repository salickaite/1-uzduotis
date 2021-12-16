# 1-uzduotis
# Užduoties aprašymas
- Vartotojas pasirenka, ar nori atlikti rūšiavimo strategijų spartos testą.
1. Jei pasirinko variantą 'T', bus atliktas rūšiavimo strategijų spartos testas (2 tokios pat strategijos vektoriams ir listams bei trečia strategija vektoriams su std::partition). Spartos testo rezultatai išvedami į ekraną.
  2. Jei vartotojas pasirinko variantą 'N', jis turi pasirinkti ar nori sugeneruoti failą su atsitiktiniais duomenimis (studentų vardai, pavardės, namų darbų pažymiai, egzamino įvertinimas).
      3. Jei buvo pasirinktas variantas 'T' (taip), vartotojas turi įvesti norimo sukurti failo pavadinimą bei kiek studentų duomenų nori sugeneruoti automatiškai. Tuomet bus sukuriamas .txt failas. 
      4. Jei buvo pasirinktas variantas 'N' (ne), tada reikia pasirinkti ar nuskaityti duomenis iš jau esamo failo.
        5. Jeigu taip, tuomet reikia įvesti failo pavadinimą ir pasirinkti ar nori juos surūšiuoti į dvi atskiras grupes ir išvesti į atskirus failus.

- Jeigu vartotojas į klausimą ar nori nuskaityti duomenis iš jau esnačio failo pasirenka atsakymą 'N' (ne), tuomet seka intrukcijas esančias ekrane (pvz., ar automatiškai sugeneruoti pažymius, su vidurkiu ar mediana pateikti galutinį pažymį).
     


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
- Buvo pridėtas išimčių valdymas.

# v0.4
- Pridėta galimybė vartotojui pasirinkti ar atlikti programos veiksmo greičio analizę ar ne;
- Įrašant duomenis į naujus txt failus yra naudojama ne srand funkcija, o panaudota random biblioteka;
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

|               | Nuskaitymas   | Dalijimas     |
| ------------- | ------------- | ------------- |
| 1 000         | 0.010055 s    | 0.0003372 s   |
| 10 000        | 0.0760551 s   | 0.0041694 s   |
| 100 000       | 0.778309 s    | 0.0371174 s   |
| 1 000 000     | 8.1402 s      | 0.405796 s    |


**List struktūra**

|               | Nuskaitymas   | Dalijimas     |
| ------------- | ------------- | ------------- |
| 1 000         | 0.0089445 s   | 0.0003225 s   |
| 10 000        | 0.0934584 s   | 0.0036227 s   |
| 100 000       | 0.821035 s    | 0.0414931 s   |
| 1 000 000     | 8.57483 s     | 0.391173 s    |


# v1.0

Lyginamos dvi strategijos, kurios nuskaito duomenis ir surūšiuoja studentus į dvi grupes.

1. Pridėtas papildomas studentų padalijimo metodas.
2. Atliktas testas tiek su vektoriais, tiek su listais siekiant ištirti rūšiavimo spartą.
3. Sukurtas rūšiavimo metodas su std::partition (su vektoriais).

Padalijimo laikai:

NAUDOJANT VEKTORIUS:

Padalijimas 1 budu uztruko: 0.0616207 s
Padalijimas 2 budu uztruko: 0.0466278 s

NAUDOJANT LISTUS:

Padalijimas 1 budu uztruko: 0.0422437 s
Padalijimas 2 budu uztruko: 0.0534314 s

Padalijimas 1 budu uztruko: 0.0581852 s
Padalijimas 2 budu uztruko: 0.0585955 s
Padalijimas 3 budu uztruko: 0.0218151 s

Išvados: 1-u būdu rūšiavimas su listais veikia greičiau. 2-u būdu, su vektoriais greičiau. 3-čias būdas, naudojant std::partition veikia greičiau už ankstesnius būdus.


