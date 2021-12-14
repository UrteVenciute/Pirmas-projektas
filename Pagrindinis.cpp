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

int uzklausa_kiekNdYra()
{
    int ndSkaicius;
    cout << "Iveskite, kiek bus namu darbu (1-10)" << endl;
    cin >> ndSkaicius;
    while (cin.fail() || ndSkaicius < 1 || ndSkaicius > 10)
    {
        cin.clear();
        cout << "Namu darbu skaicius yra netinkamas, iveskite skaiciu didesni uz 0" << endl;
        cin.ignore(256, '\n');
        cin >> ndSkaicius;
    }
    return ndSkaicius;
}


void darbasSuFailu(vector <int>& v1, int& ndKiek, char& atsakymas)
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

    cout << setw(46) << left << "| Atliktas darbas " << setw(25) << left << "| Laikas (s) su vektoriu " << setw(21) << left << "| Laikas (s) su list " << "|" << endl;
    cout << "---------------------------------------------------------------------------------------------" << endl;


    for (int i = 0; i < (v1.size()); i++)
    {
       
        rusiavimas(grupe_vector, grupe_list, protingi_vector, vargsiukai_vector, protingi_list, vargsiukai_list, laikas_vector, laikas_list, atsakymas);

        cout << v1.at(0) << setw(40) << left << " studentu surusiavimas i dvi grupes " << "| " << setw(23) << left << laikas_vector.at(1) << setw(19) << left << laikas_list.at(1) << endl;

        spausdinimas(v1.at(i), atsakymas, protingi_vector, pavP);
        spausdinimas(v1.at(i), atsakymas, vargsiukai_vector, pavV);
        spausdinimas(v1.at(i), atsakymas, protingi_list, pavP);
        spausdinimas(v1.at(i), atsakymas, vargsiukai_list, pavV);
        grupe_list.clear();
        grupe_vector.clear();
        protingi_list.clear();
        protingi_vector.clear();
    }
}

void failoNuskaitymas_list(list <studentas>& grupe1, vector <int>& v1, int& ndKiek)
{
    vector <double> laikas_list;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < (v1.size()); i++)
    {
        double temp;
        string temp2;
        //int i = 0;
        std::stringstream out_data;
        string pav = "Studentai " + to_string(v1.at(i)) + ".txt";
        ifstream nuskaitymas(pav);
        getline(nuskaitymas, temp2);
        out_data << nuskaitymas.rdbuf();

            studentas stu;
            out_data >> stu.vardas >> stu.pavarde;
            stu.paz.reserve(ndKiek);

            for (int i = 0; i < std::count(temp2.begin(), temp2.end(), ' ') - 2; i++)
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
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = end - start;
            laikas_list.push_back(diff.count());

            cout << v1.at(0) << setw(40) << left << " studentu nuskaitymas " << "| " << setw(23) << left << laikas_list.at(0)  << endl;

        }
    }

void failoNuskaitymas(vector <studentas>& grupe1, vector <int>& v1, int& ndKiek)
{
    vector <double> laikas_vector;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < (v1.size()); i++)
    {
        double temp;
        string temp2;
        //int i = 0;
        std::stringstream out_data;
        string pav = "Studentai " + to_string(v1.at(i)) + ".txt";
        ifstream nuskaitymas(pav);
        getline(nuskaitymas, temp2);
        out_data << nuskaitymas.rdbuf();

        studentas stu;
        out_data >> stu.vardas >> stu.pavarde;
        stu.paz.reserve(ndKiek);

        for (int i = 0; i < std::count(temp2.begin(), temp2.end(), ' ') - 2; i++)
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
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        laikas_vector.push_back(diff.count());

        cout << v1.at(0) << setw(40) << left << " studentu nuskaitymas " << "| " << setw(23) << left << laikas_vector.at(0) << endl;
    }
}


    void rusiavimas(vector <studentas>&grupe_vector, list <studentas>&grupe_list, vector <studentas>&protingi_vector, vector <studentas>&vargsiukai_vector, list <studentas>&protingi_list, list <studentas>&vargsiukai_list, vector <double>&laikas_vector, vector<double>&laikas_list, char& atsakymas)
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