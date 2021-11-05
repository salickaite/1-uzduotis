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
