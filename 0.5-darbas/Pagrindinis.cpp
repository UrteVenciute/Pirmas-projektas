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

float galutBalas(vector<int> skaiciai) {
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
            out_data << setw(20) << right << "ND" << i+1;
            out_data << setw(20) << right << "Galutinis(vid.)" << endl;
        for (int s = 1; s < v1.at(i); s++) {
            skaiciai = auto_marks(5);
            out_data <<left<< setw(20) << "Vardas" + std::to_string(s) << left<<
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

    for (int i = 0; i < (v1.size()); i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        failoNuskaitymas(grupe_vector, v1.at(i), laikas_vector, ndKiek);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        laikas_vector.push_back(diff.count());

        auto start1 = std::chrono::high_resolution_clock::now();
        failoNuskaitymas_list(grupe_list, v1.at(i), laikas_list, ndKiek);
        auto end1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff1 = end1 - start1;
        laikas_list.push_back(diff1.count());

        rusiavimas(grupe_vector, grupe_list, protingi_vector, vargsiukai_vector, protingi_list, vargsiukai_list, laikas_vector, laikas_list, atsakymas);

        spausdinimas(v1.at(i), atsakymas, protingi_vector, pavP);
        spausdinimas(v1.at(i), atsakymas, vargsiukai_vector, pavV);
        spausdinimas(v1.at(i), atsakymas, protingi_list, pavP);
        spausdinimas(v1.at(i), atsakymas, vargsiukai_list, pavV);
        grupe_list.clear();
        grupe_vector.clear();
    }
    int vieta = 0;

    cout << setw(46) << left << "Atliktas darbas " << setw(25) << left << "| Laikas su vektoriu " << setw(21) << left << "| Laikas su list " <<  endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << v1.at(0) << setw(40) << left << " studentu nuskaitymas " << "| " << setw(23) << left << laikas_vector.at(vieta) << "| " << setw(19) << left << laikas_list.at(vieta) << endl;
    vieta++;
    cout  << v1.at(0) << setw(40) << left << " studentu surusiavimas i dvi grupes " << "| " << setw(23) << left << laikas_vector.at(vieta) << "| " << setw(19) << left << laikas_list.at(vieta) <<  endl;
    vieta++;
    cout  << v1.at(1) << setw(39) << left << " studentu nuskaitymas " << "| " << setw(23) << left << laikas_vector.at(vieta) << "| " << setw(19) << left << laikas_list.at(vieta) << endl;
    vieta++;
    cout  << v1.at(1) << setw(39) << left << " studentu surusiavimas i dvi grupes " << "| " << setw(23) << left << laikas_vector.at(vieta) << "| " << setw(19) << left << laikas_list.at(vieta) <<  endl;
    vieta++;
    cout << v1.at(2) << setw(38) << left << " studentu nuskaitymas " << "| " << setw(23) << left << laikas_vector.at(vieta) << "| " << setw(19) << left << laikas_list.at(vieta) <<  endl;
    vieta++;
    cout  << v1.at(2) << setw(38) << left << " studentu surusiavimas i dvi grupes " << "| " << setw(23) << left << laikas_vector.at(vieta) << "| " << setw(19) << left << laikas_list.at(vieta) << endl;
    vieta++;
    cout  << v1.at(3) << setw(37) << left << " studentu nuskaitymas " << "| " << setw(23) << left << laikas_vector.at(vieta) << "| " << setw(19) << left << laikas_list.at(vieta) <<  endl;
    vieta++;
    cout  << v1.at(3) << setw(37) << left << " studentu surusiavimas i dvi grupes " << "| " << setw(23) << left << laikas_vector.at(vieta) << "| " << setw(19) << left << laikas_list.at(vieta) << endl;
    vieta++;
    cout  << v1.at(4) << setw(36) << left << " studentu nuskaitymas " << "| " << setw(23) << left << laikas_vector.at(vieta) << "| " << setw(19) << left << laikas_list.at(vieta) << endl;
    vieta++;
    cout << v1.at(4) << setw(36) << left << " studentu surusiavimas i dvi grupes " << "| " << setw(23) << left << laikas_vector.at(vieta) << "| " << setw(19) << left << laikas_list.at(vieta) << endl;
}

void failoNuskaitymas_list(list <studentas>& grupe1, int& v1, vector <double>& laikas, int& ndKiek)
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
        stu.paz.clear();
        i++;
    }
}

void failoNuskaitymas(vector <studentas>& grupe1, int& v1, vector <double>& laikas, int& ndKiek)
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
        stu.paz.clear();
        i++;
    }
}
void rusiavimas(vector <studentas>& grupe_vector, list <studentas>& grupe_list, vector <studentas>& protingi_vector, vector <studentas>& vargsiukai_vector, list <studentas>& protingi_list, list <studentas>& vargsiukai_list, vector <double>& laikas_vector, vector<double>& laikas_list, char& atsakymas)
{
    auto start = std::chrono::high_resolution_clock::now();
    auto StartSorting = std::chrono::high_resolution_clock::now();
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
    auto EndSorting = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    laikas_vector.push_back(diff.count());

    auto start1 = std::chrono::high_resolution_clock::now();
    auto StartSorting1 = std::chrono::high_resolution_clock::now();
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
    auto EndSorting1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff1 = end1 - start1;

    laikas_list.push_back(diff1.count());
}