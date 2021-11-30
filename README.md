# Pirmas-projektas
# 0.1 versija
Atlikti darbai:
* sukurta struktūra (vardas, pavardė, namų darbai, egzamino rezultatai)
* parašoma funkcija, kuri skaičiuoja pažymių medianą
* sugeneruojami skaičiai. kurie bus naudojami automatiškam balų išrašymui
* funkcija automatiškai sugeneruojanti pažymius ir funkcija leidžianti patiems rašyti pažymius
* sukurtas duomenų apdorojimas skaičiuojant galutinį balo vidurkį ir medianą
# 0.2 versija
* pasianudojant 0.1 programa nuskaitomi duomenys iš failo
* tvarkingai išvesti duomenis
# 0.3 versija
* pasianudojant 0.2 programa atliekame kodo reorganizavimą, patikriname ir papildome struct'ūras
* sukuriame statines bibliotekas, kuriose aprašome kuriamų komandų aprašus
* faile "readfromfile" panaudojau išimčių valdymą, kad patikirintų ar gerai įvedamas failo pavadinimas.
# 0.4 versija
* sugeneruojame programą, kuri prašo įvesti studentų skaičių ir pagal tai sukuriamas failas
* sukurtą failą nuskaito
* pagal naujai sukurtą failą surušiuojame studentus į nuskriaustas ir protingas
* surūšiuotus studentus išvedame į du naujus failus
* atliekame programos greičio analizę:šmatuojame failų kūrimą, duomenų nuskaitymą iš failų, studentų rūšiavimą į dvi grupes, surūšiuotų studentų išvedimą į du naujus failus.
![04](https://user-images.githubusercontent.com/90273563/142179916-dece84a2-0384-440d-be6c-ba6c5358c030.png)
# 0.5 versija
* konteinerių testavimas
* išmatuojame veikimo spartą: duomenų nuskaitymą iš failų ir studentų rūšiąvimą į dvi grupes
* palagynam spartą naudojant vector (0.4 versijoje), o šioje versijoje list
* ![055](https://user-images.githubusercontent.com/90273563/142179950-38b4d8a4-aa7a-4d13-bac4-dece1625b448.png)
* testavimo paremetrai:CPU-Intel(R) Core(TM) i3-7100U CPU @ 2.40GHz   2.40 GHz, įdiegta RAM-8,00 GB, HDD- 932 GB
# 1.0 versija
1 strategija
* Bendro studentų konteinerio (vector ir list) skaidymas panaudojant tik vieną naują konteinerį: "vargšiukai". Tokiu būdu, jei studentas yra vargšiukas, jį turime perkeliame į naująjį "vargšiukų" konteinerį ir ištriname iš bendro studentai konteinerio. Po šio žingsnio studentai konteineryje liks vien tik kietiakai. Atminties atveju tai efektyviau.
* Atliekame pirmą ir antrą strategijas ir išvedame jų spartą.
