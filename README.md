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
