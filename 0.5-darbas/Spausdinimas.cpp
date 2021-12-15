#include "Spausdinimas.h"


void spausdinimas(int& v1, char& atsakymas, vector <studentas>& sarasas, string& pav)
{
    string failoPav = pav + "_Studentai " + to_string(v1) + ".txt";
    std::stringstream rez;
    ofstream out_data("Vector" + failoPav);

    rez << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << endl;
    rez << "-------------------------------------------------------------------------" << endl;
    for (const auto& stu : sarasas)
    {
        rez << setw(20) << left << stu.vardas << setw(20) << left << stu.pavarde << setw(20) << left << fixed << setprecision(2) << stu.galutinis_vidurkis << endl;
    }
    out_data << rez.str();
}

void spausdinimas(int& v1, char& atsakymas, list <studentas>& sarasas, string& pav)
{
    string failoPav = pav + "_Studentai " + to_string(v1) + ".txt";
    std::stringstream rez;
    ofstream out_data("List" + failoPav);

    rez << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << endl;
    rez << "-------------------------------------------------------------------------" << endl;
    for (const auto& stu : sarasas)
    {
        rez << setw(20) << left << stu.vardas << setw(20) << left << stu.pavarde << setw(20) << left << fixed << setprecision(2) << stu.galutinis_vidurkis << endl;
    }
    out_data << rez.str();
}