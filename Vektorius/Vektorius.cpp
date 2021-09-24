// Vektorius.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <iterator>
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

double mediana(vector<float>vec)
{
    typedef vector<float>::size_type vecSize;
    vecSize size = vec.size();
    if (size == 0) //std:domain_error deklaruota <stdexcept>
        throw std::domain_error("negalima skaiciuoti medianos tusciam vektoriui");
    sort(vec.begin(), vec.end());
    vecSize vid = size / 2;
    return size % 2 == 0 ? (vec[vid] + vec[vid - 1]) / 2 : vec[vid];
}

unsigned int countWordsInString(string const& str)
{
    stringstream stream(str);
    return distance(istream_iterator<string>(stream), istream_iterator<string>());
}

void read_from_file(vector<studentas>& grupe, int* pazymiu_sk)
{
    int sum = 0;
    int temp;
    ifstream fileRead;
    string buff;
    fileRead.open("Studentai10000.txt");
    if (fileRead.is_open())
    {
        getline(fileRead >> std::ws, buff);
        *pazymiu_sk = countWordsInString(buff) - 3;
        while (true)
        {
            grupe.resize(grupe.size() + 1);
            fileRead >> grupe.at(sum).vardas;
            if (fileRead.eof()) { grupe.pop_back(); break; }
            fileRead >> grupe.at(sum).pavarde;
            for (int i = 0; i < *pazymiu_sk; i++)
            {
                fileRead >> temp;
                grupe.at(sum).paz.push_back(temp);
            }
            fileRead >> grupe.at(sum).egz;
            grupe.at(sum).gal = grupe.at(sum).gal / *pazymiu_sk;
            grupe.at(sum).gal = grupe.at(sum).gal * 0.4 + 0.6 * grupe.at(sum).egz;
            sum++;
        }
    }
    else { std::cout << "-\n"; }
}

void spausdinti(vector<studentas> grupe, int pazymiu_sk)
{
    ofstream output;
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
            << mediana(grupe[i].paz) << endl;
    }
    cout << "\n\n";
}
int main()
{
    int pazymiu_sk;
    char temp;
    vector<studentas> grupe;
    read_from_file(grupe, &pazymiu_sk);
    spausdinti(grupe, pazymiu_sk);
    system("pause");
    return 0;
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
