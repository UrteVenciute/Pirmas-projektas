#include "Funkcijos.h"
#include "Studentas.h"
#include <sstream>


double vidurkis(studentas& s)
{
    double sum = 0.;
    double kiekis = 0.;
    double vid = 0.;

    for (int i = 0; i < s.paz.size(); i++)
    {
        sum += s.paz.at(i);
        kiekis++;
    }
    vid = sum / kiekis;
    return vid;
}

int uzklausakiekpaz()
{
    int pazSkaicius;
    cout << "Namu darbu skaicius" << endl;
    cin >> pazSkaicius;
    while (cin.fail() || pazSkaicius < 1 || pazSkaicius > 10)
    {
        cin.clear();
        cout << "Namu darbu skaicius yra netinkamas, iveskite skaiciu didesni uz 0" << endl;
        cin.ignore(256, '\n');
        cin >> pazSkaicius;
    }
    return pazSkaicius;
}

void darbasSuFailu(vector <int>& v1,  char& atsakymas)
{
    string failoPav;
    vector <double> laikas_vector;
    vector <double> laikas_list;
    vector <studentas> protingi_vector;
    vector <studentas> vargsiukai_vector;
    vector <studentas> grupe_vector;
    list <studentas> grupe_list;
    list <studentas> protingi_list;
    list <studentas> vargsiukai_list;
    string pavP = "Protingi";
    string pavV = "Vargsiukai";


    cout << setw(46) << left << "Atliktas darbas " << setw(24) << left << "| Laikas su vektoriu " << setw(21) << left << "| Laikas su list "  << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < (v1.size()); i++)
    {
        laikas_vector.reserve(3);
        laikas_list.reserve(3);

        auto start = std::chrono::high_resolution_clock::now();
        failoNuskaitymas(grupe_vector, v1.at(i));
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        laikas_vector.push_back(diff.count());

        auto start1 = std::chrono::high_resolution_clock::now();
        failoNuskaitymas_list(grupe_list, v1.at(i));
        auto end1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff1 = end1 - start1;
        laikas_list.push_back(diff1.count());
        
        int o = 40 - i;

        cout  << v1.at(i) << setw(o) << " studentu nuskaitymas " << "| " << setw(23) << left << laikas_vector.at(0) << "| " << setw(19) << left << laikas_list.at(0) <<  endl;


        rusiavimasVector(grupe_vector, protingi_vector, vargsiukai_vector, laikas_vector, atsakymas);

        spausdinimas(v1.at(i), atsakymas, protingi_vector, pavP);
        spausdinimas(v1.at(i), atsakymas, vargsiukai_vector, pavV);

        grupe_vector.clear();
        protingi_vector.clear();
        vargsiukai_vector.clear();

        rusiavimasList(grupe_list, protingi_list, vargsiukai_list, laikas_list, atsakymas);

        cout  << v1.at(i) << setw(o) << " studentu surusiavimas " << "| " << setw(23) << left << laikas_vector.at(1) << "| " << setw(19) << left << laikas_list.at(1) << endl;


        spausdinimas(v1.at(i), atsakymas, protingi_list, pavP);
        spausdinimas(v1.at(i), atsakymas, vargsiukai_list, pavV);


        grupe_list.clear();
        protingi_list.clear();
        vargsiukai_list.clear();
        laikas_vector.clear();
        laikas_list.clear();
    }

}

void failoNuskaitymas_list(list <studentas>& grupe1, int& v1)
{
    double temp;
    string temp2;
    int i = 0;
    std::stringstream out_data;
    int zodziuSk = 0;
    string zodis;


    string pav = "Studentai " + to_string(v1) + ".txt";
    ifstream nuskaitymas(pav);
    getline(nuskaitymas, temp2);
    stringstream s(temp2);
    while (s >> zodis)
    {
        zodziuSk++;
    }
    int pazKiek = zodziuSk - 3;
    out_data << nuskaitymas.rdbuf();
    while (i < v1)
    {
        studentas stu;
        out_data >> stu.vardas >> stu.pavarde;
        stu.paz.reserve(pazKiek);

        for (int k = 0; k < (pazKiek); k++)
        {
            out_data >> temp;
            stu.paz.push_back(temp);
        }

        out_data >> stu.egz;

        double vid = vidurkis(stu);
        stu.galutinis_vidurkis = 0.4 * vid + 0.6 * stu.egz;

        grupe1.push_back(stu);
        stu.paz.clear();
        i++;
    }
    nuskaitymas.close();
}

void failoNuskaitymas(vector <studentas>& grupe1, int& v1)
{
    double temp;
    string temp2;
    int i = 0;
    std::stringstream out_data;
    int zodziuSk = 0;
    string zodis;


    string pav = "Studentai " + to_string(v1) + ".txt";
    ifstream nuskaitymas(pav);
    getline(nuskaitymas, temp2);
    stringstream s(temp2);
    while (s >> zodis)
    {
        zodziuSk++;
    }
    int pazKiek = zodziuSk - 3;
    out_data << nuskaitymas.rdbuf();
    while (i < v1)
    {
        studentas stu;
        out_data >> stu.vardas >> stu.pavarde;
        stu.paz.reserve(pazKiek);

        for (int k = 0; k < (pazKiek); k++)
        {
            out_data >> temp;
            stu.paz.push_back(temp);
        }

        out_data >> stu.egz;

        double vid = vidurkis(stu);
        stu.galutinis_vidurkis = 0.4 * vid + 0.6 * stu.egz;

        grupe1.push_back(stu);
        stu.paz.clear();
        i++;
    }
    nuskaitymas.close();
}


void rusiavimasVector(vector <studentas>& grupe_vector,  vector <studentas>& protingi_vector, vector <studentas>& vargsiukai_vector, vector <double>& laikas_vector,  char& atsakymas)
{
    auto start = std::chrono::high_resolution_clock::now();
    sort(grupe_vector.begin(), grupe_vector.end(), ([](studentas a, studentas b)
        {
            return a.galutinis_vidurkis < b.galutinis_vidurkis; }));

    for (const auto& stu : grupe_vector)
    {
        if (stu.galutinis_vidurkis >= 5.00)
        {
            protingi_vector.push_back(stu);
        }
        else vargsiukai_vector.push_back(stu);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    laikas_vector.push_back(diff.count());
}

void rusiavimasList(list <studentas>&grupe_list,  list <studentas>&protingi_list, list <studentas>&vargsiukai_list, vector<double>&laikas_list, char& atsakymas)
    {
    auto start1 = std::chrono::high_resolution_clock::now();
    grupe_list.sort([](studentas a, studentas b) {return a.galutinis_vidurkis < b.galutinis_vidurkis; });

    for (const auto& stu : grupe_list)
    {
        if (stu.galutinis_vidurkis >= 5.00)
        {
            protingi_list.push_back(stu);
        }
        else vargsiukai_list.push_back(stu);
    }
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff1 = end1 - start1;

    laikas_list.push_back(diff1.count());
}