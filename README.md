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

