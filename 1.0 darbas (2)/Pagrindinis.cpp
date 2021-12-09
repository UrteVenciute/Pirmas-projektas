#include "Funkcijos.h"
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

int sugeneruojami_sakiciai()
{
    return rand() % 10 + 1;
}

vector<int> auto_marks(int how_many_marks)
{
    vector<int> skaiciai;
    for (int i = 0; i < how_many_marks; i++)
    {
        skaiciai.push_back(sugeneruojami_sakiciai());
    }
    return skaiciai;
}

float galutBalas(vector<int> skaiciai)
{
    studentas grupe;
    grupe.galutinis_vidurkis = 0.4 * std::accumulate(skaiciai.begin(), skaiciai.end(), 0) / skaiciai.size() + 0.6 * sugeneruojami_sakiciai();
    return grupe.galutinis_vidurkis;
}


void failuKurimas(vector <int>& v1, int& ndKiek)
{
    string pav;
    double pazymys;
    std::stringstream out_data;
    for (int i = 0; i < (v1.size()); i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        pav = "Studentai " + to_string(v1.at(i)) + ".txt";
        std::ofstream isvedimas(pav);
        vector<int> skaiciai;
        studentas Eil;
        out_data << setw(20) << left << "Vardas"
            << setw(20) << left << "Pavarde";
        for (int i = 0; i < 5; i++)
            out_data << setw(20) << right << "ND" << i + 1;
        out_data << setw(20) << right << "Galutinis(vid.)" << endl;
        for (int s = 1; s < v1.at(i); s++) {
            skaiciai = auto_marks(5);
            out_data << left << setw(20) << "Vardas" + std::to_string(s) << left <<
                setw(20) << "Pavarde" + std::to_string(s);
            for (int i = 0; i < 5; i++)
                out_data << setw(20) << right << sugeneruojami_sakiciai();
            out_data << setw(20) << right << sugeneruojami_sakiciai() << endl;
            skaiciai.clear();
        }
        isvedimas << out_data.str();
        isvedimas.close();

        auto End = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = End - start;

        cout << v1.at(i) << " elementu kurimas uztruko: " << diff.count() << " s" << endl;
    }
}

void darbasSuFailu(vector <int>& v1, int& ndKiek, char& atsakymas)
{
    string failoPav;
    vector <double> time_vector;
    vector <double> time_list;
    vector <studentas> protingi_vector;
    vector <studentas> vargsiukai_vector1;
    vector <studentas> vargsiukai_vector2;
    vector <studentas> grupe_vector;
    vector <studentas> grupe_vector2;
    list <studentas> grupe_list;
    list <studentas> grupe_list2;
    list <studentas> protingi_list;
    list <studentas> vargsiukai_list1;
    list <studentas> vargsiukai_list2;
    string pavP = "Protingi";
    string pavV = "Vargsiukai";

    cout << setw(40) << left << " Atliktas darbas " << setw(23) << left << " Laikas su vektoriu " << setw(19) << left << " Laikas su list " << endl;

    for (int i = 0; i < (v1.size()); i++)
    {
        time_vector.reserve(2);
        time_list.reserve(2);

        failoNuskaitymas(grupe_vector, grupe_vector2, v1.at(i), ndKiek);
        failoNuskaitymas_list(grupe_list, grupe_list2, v1.at(i), ndKiek);

        rusiavimas1(grupe_vector, grupe_list, protingi_vector, vargsiukai_vector1, protingi_list, vargsiukai_list1, time_vector, time_list, atsakymas);
        rusiavimas2(grupe_vector2, grupe_list2, vargsiukai_vector2, vargsiukai_list2, time_vector, time_list, atsakymas);

        cout << v1.at(i) << " studentu surusiavimas 1 strategija " << " " << setw(23) << left << time_vector.at(0) << " " << setw(19) << left << time_list.at(0) << endl;
        cout << v1.at(i) << " studentu surusiavimas 2 strategija " << " " << setw(23) << left << time_vector.at(1) << " " << setw(19) << left << time_list.at(1) << endl;

        spausdinimas(v1.at(i), atsakymas, protingi_vector, pavP);
        spausdinimas(v1.at(i), atsakymas, vargsiukai_vector1, pavV);
        spausdinimas(v1.at(i), atsakymas, protingi_list, pavP);
        spausdinimas(v1.at(i), atsakymas, vargsiukai_list1, pavV);

        grupe_list.clear();
        grupe_vector.clear();
        time_vector.clear();
        time_list.clear();
    }
}

void failoNuskaitymas_list(list <studentas>& grupe1, list <studentas>& grupe2, int& v1, int& ndKiek)
{
    double temp;
    int i = 0;
    std::stringstream out_data;
    string pav = "Studentai " + to_string(v1) + ".txt";
    ifstream nuskaitymas(pav);
    nuskaitymas.ignore(1000, '\n');
    out_data << nuskaitymas.rdbuf();
    while (i < v1)
    {
        studentas stu;
        out_data >> stu.vardas >> stu.pavarde;
        stu.paz.reserve(ndKiek);

        for (int i = 0; i < 5; i++)
        {
            out_data >> temp;
            stu.paz.push_back(temp);
        }

        out_data >> stu.egz;

        double vid = vidurkis(stu);
        stu.galutinis_vidurkis = 0.4 * vid + 0.6 * stu.egz;

        grupe1.push_back(stu);
        grupe2.push_back(stu);
        stu.paz.clear();
        i++;
    }
}


void failoNuskaitymas(vector <studentas>& grupe1, vector <studentas>& grupe2, int& v1, int& ndKiek)
{
    double temp;
    int i = 0;
    std::stringstream out_data;
    string pav = "Studentai " + to_string(v1) + ".txt";
    ifstream nuskaitymas(pav);
    nuskaitymas.ignore(1000, '\n');
    out_data << nuskaitymas.rdbuf();
    while (i < v1)
    {
        studentas stu;
        out_data >> stu.vardas >> stu.pavarde;
        stu.paz.reserve(ndKiek);

        for (int i = 0; i < 5; i++)
        {
            out_data >> temp;
            stu.paz.push_back(temp);
        }

        out_data >> stu.egz;

        double vid = vidurkis(stu);
        stu.galutinis_vidurkis = 0.4 * vid + 0.6 * stu.egz;

        grupe1.push_back(stu);
        grupe2.push_back(stu);
        stu.paz.clear();
        i++;
    }
}

void rusiavimas1(vector <studentas>& grupe_vector, list <studentas>& grupe_list, vector <studentas>& protingi_vector, vector <studentas>& vargsiukai_vector, list <studentas>& protingi_list, list <studentas>& vargsiukai_list, vector <double>& time_vector, vector<double>& time_list, char& atsakymas)
{
    auto start = std::chrono::high_resolution_clock::now();
    auto StartSorting = std::chrono::high_resolution_clock::now();
    sort(grupe_vector.begin(), grupe_vector.end(), ([](studentas a, studentas b)
        {
            return a.galutinis_vidurkis < b.galutinis_vidurkis;
        }));
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
    time_vector.push_back(diff.count());

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
    time_list.push_back(diff1.count());
}

void rusiavimas2(vector <studentas>& grupe_vector, list <studentas>& grupe_list, vector <studentas>& vargsiukai_vector_2, list <studentas>& vargsiukai_list_2, vector <double>& time_vector, vector<double>& time_list, char& atsakymas)
{
    auto start = std::chrono::high_resolution_clock::now();
    vector<studentas>::iterator it1;
    std::partition(grupe_vector.begin(), grupe_vector.end(), [](studentas a)
        {
            return a.galutinis_vidurkis < 5;
        });
    auto itt = std::partition_point(grupe_vector.begin(), grupe_vector.end(), [](studentas a)
        {
            return a.galutinis_vidurkis < 5;
        });
    for (it1 = grupe_vector.begin(); it1 != itt; it1++)
    {
        vargsiukai_vector_2.push_back(*it1);
    }
    grupe_vector.erase(std::remove_if(grupe_vector.begin(), grupe_vector.end(), [](studentas a) {return (a.galutinis_vidurkis < 5); }), grupe_vector.end());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    time_vector.push_back(diff.count());

    auto start1 = std::chrono::high_resolution_clock::now();
    list<studentas>::iterator it = grupe_list.begin();
    grupe_list.sort([](studentas a, studentas b) {return a.galutinis_vidurkis < b.galutinis_vidurkis; });
    while (it != grupe_list.end())
    {
        if ((*it).galutinis_vidurkis < 5.00)
        {
            vargsiukai_list_2.push_back(*it);
            it = grupe_list.erase(it);
        }
        else ++it;
    }
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff1 = end1 - start1;
    time_list.push_back(diff1.count());
}