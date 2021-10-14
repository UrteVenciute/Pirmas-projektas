// 0.4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <chrono>
using namespace std;
using std::left;
using std::cout;
using std::vector;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::setprecision;

struct studentas {
    string vardas, pavarde;
    vector<float> paz = { 0 };
    int egz;
    float gal = 0;
};

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


float galutBalas (vector<int> skaiciai) {
    studentas grupe;
    grupe.gal = 0.4 * std::accumulate(skaiciai.begin(), skaiciai.end(), 0) / skaiciai.size() + 0.6 * sugeneruojami_sakiciai();
    return grupe.gal;
}

int generavimas(vector<int> pazymiai)
{
    int kiek;
    cout << "Iveskite studentu skaiciu: " << endl;
    cin >> kiek;
    string pavadinimas = "Studentai_" + std::to_string(kiek) + ".txt";
    auto start = std::chrono::high_resolution_clock::now();
    auto st = start;
    std::ofstream out_data(pavadinimas);
    vector<int> skaiciai;
    studentas grupe;
    out_data << setw(20) << left << "Vardas"
        << setw(20) << left << "Pavarde"
        << setw(20) << left << "Galutinis(vid.)";
    for (int s = 1; s <= kiek; s = s + 1)
    {
        skaiciai = auto_marks(5);
        out_data << setw(20) << "Vardas" + std::to_string(s) <<
            setw(20) << "Pavarde" + std::to_string(s) <<
            setw(18) << galutBalas(skaiciai) << endl;;
        skaiciai.clear();

    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo su " + std::to_string(kiek) + " studentu/-ais kurimas uztruko: " << diff.count() << " s\n";

    return kiek;
}

void skaityti (vector<studentas>& grupe, int kiek)
{
    int student_counter = 0;
    ifstream fileRead;
    string pavadinimas = "Studentai_" + std::to_string(kiek) + ".txt";
    string buff;
    fileRead.open(pavadinimas);
    if (fileRead.is_open()) {

        auto start = std::chrono::high_resolution_clock::now();
        auto st = start;
        getline(fileRead >> std::ws, buff);
        while (student_counter < kiek)
        {

            grupe.resize(grupe.size() + 1);
            fileRead >> grupe.at(student_counter).vardas;
            fileRead >> grupe.at(student_counter).pavarde;
            fileRead >> grupe.at(student_counter).gal;
            student_counter++;
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        cout << "Failo su " + std::to_string(kiek) + " studentu/-ais nuskaitymas uztruko: " << diff.count() << " s\n";

    }
}

int main()
{
	vector<int> skaiciai;

	int kiek = generavimas(skaiciai);
	vector<studentas> studentai;
	skaityti(studentai, kiek);
	vector<studentas> protingi;
	vector<studentas> nuskriaustukai;
	int nuskr = 0;
	int prot = 0;

	auto start = std::chrono::high_resolution_clock::now();
	auto st = start;
	for (int i = 0; i < kiek; i++) {
		float paz = 5.00;
		if (studentai.at(i).gal < paz) {
			nuskriaustukai.push_back(studentai.at(i));
			nuskr++;
		}
	}
	for (int j = 0; j < kiek; j++) {
		float paz = 5.00;
		if (studentai.at(j).gal >= paz) {
			protingi.push_back(studentai.at(j));
			prot++;
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;
	cout << "Failo rusiavimas su " + std::to_string(kiek) + " studentais i dvi grupes uztruko : " << diff.count() << " s\n";



	std::string pav;
	pav = "nuskriaustukai" + std::to_string(kiek) + ".txt";
	std::ofstream nuskr_failas(pav);
	auto start1 = std::chrono::high_resolution_clock::now();
	auto st1 = start1;
	for (int i = 0; i < kiek; i++) {

		float paz = 5.00;
		if (studentai.at(i).gal < paz) {
			nuskr_failas << studentai.at(i).vardas << setw(20) << studentai.at(i).pavarde << setw(18) << studentai.at(i).gal <<endl;
		}

	}
	auto end1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff1 = end1 - start1;
	cout << "Failo isvedimas su " + std::to_string(kiek) + " studentais  i nuskriaustukus uztruko : " << diff1.count() << " s\n";

	pav = "protingi_" + std::to_string(kiek) + ".txt";
	std::ofstream prot_failas(pav);
	auto start2 = std::chrono::high_resolution_clock::now();
	auto st2 = start2;
	for (int j = 0; j < kiek; j++) {
		float paz = 5.00;
		if (studentai.at(j).gal >= paz) {
			prot_failas << studentai.at(j).vardas << setw(20) << studentai.at(j).pavarde << setw(18) << studentai.at(j).gal << endl;
		}
	}
	auto end2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff2 = end2 - start2;
	std::cout << "Failo isvedimas su " + std::to_string(kiek) + " studentais  i protingus uztruko : " << diff2.count() << " s\n";

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
