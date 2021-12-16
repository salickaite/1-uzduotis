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
