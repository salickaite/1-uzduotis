# 1-uzduotis
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

| Studentų skaičius | Testo laikas |
| ------------- | ------------- |
| 1 000  | 0.110009 s  |
| 10 000  | 0.699132 s  |
| 100 000  | 6.40064 s  |
| 1 000 000  | 58.0551 s  |
| 10 000 000  | 577.946 s  |
