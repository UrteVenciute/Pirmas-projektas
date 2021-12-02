#include "Spausdinimas.h"
#include "Funkcijos.h"
#include <sstream>

/*
void spausdinti_vector(char& atsakymas, vector <studentas>& grupe1)
{
    ofstream rz("rezultatai.txt");
    rz << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << endl;
    rz << "-------------------------------------------------------------------------" << endl;
    for (int i = 0; i < grupe1.size(); i++)
    {
        rz << setw(20) << left << grupe1.at(i).pavarde << setw(20) << left << grupe1.at(i).vardas << setw(20) << left << fixed << setprecision(2) << grupe1.at(i).galutinis_vidurkis << endl;
    }
}

void spausdinti_struct(char& atsakymas, studentas(&grupe)[100], int& studentuSkaicius)
{
    cout << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << endl;
    cout << "---------------------------------------------------------------" << endl;
    for (int i = 0; i < studentuSkaicius; i++)
    {
        cout << setw(20) << left << grupe[i].pavarde << setw(20) << left << grupe[i].vardas << setw(20) << left << fixed << setprecision(2) << grupe[i].galutinis_vidurkis << endl;
    }
}
*/

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