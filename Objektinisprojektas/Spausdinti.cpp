#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include "Spausdinti.h"
#include "Mediana.h"
using std::setw;
using std::setprecision;
using std::left;
using std::endl;

void spausdinti(std::vector<studentas> grupe, int pazymiu_sk)
{
    std::ofstream output;
    output.open("kursiokai.txt");
    output << setw(20) << left << "Vardas"
        << setw(20) << left << "Pavarde"
        << setw(20) << left << "Galutinis(vid.)/"
        << left << "Galutinis(med.)\n";
    for (int i = 0; i < grupe.size(); i++)
    {
        output << setw(20) << left << grupe[i].vardas
            << setw(20) << left << grupe[i].pavarde
            << setw(20) << left << grupe[i].gal
            << setprecision(2) << mediana(grupe[i].paz) << endl;
    }
    output << "\n\n";
}
