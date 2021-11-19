#include "Spausdinimas.h"
#include "Funkcijos.h"

void spausdinimas(int& v1, char& atsakymas, vector <studentas>& sarasas, string& pav)
{
    string failoPav = pav + "_Studentai " + to_string(v1) + ".txt";
    ofstream rz("Vector_" + failoPav);

    rz << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << endl;
    rz << "-------------------------------------------------------------------------" << endl;
    for (const auto& stu : sarasas)
    {
        rz << setw(20) << left << stu.pavarde << setw(20) << left << stu.vardas << setw(20) << left << fixed << setprecision(2) << stu.galutinis_vidurkis << endl;
    }
}

void spausdinimas(int& v1, char& atsakymas, list <studentas>& sarasas, string& pav)
{
    string failoPav = pav + "_Studentai " + to_string(v1) + ".txt";
    ofstream rz("List_" + failoPav);
    
    rz << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << endl;
    rz << "-------------------------------------------------------------------------" << endl;
    for (const auto& stu : sarasas)
    {
        rz << setw(20) << left << stu.pavarde << setw(20) << left << stu.vardas << setw(20) << left << fixed << setprecision(2) << stu.galutinis_vidurkis << endl;
    }
}