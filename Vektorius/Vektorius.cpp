// Vektorius.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <time.h>
#include <fstream>
#include <stdexcept>
using namespace std;
using std::sort;
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
    vector<int> paz = { 0 };
    int egz;
    float gal = 0;
};

void mediana(vector<int>pazymiai)
{
    int counter = 0;
    for (int i = 0; i < 10; i++)
    {
        if (pazymiai[i] > 0)
        {
            counter++;
        }
        if (pazymiai[i] == -1)
        {
            pazymiai[i] = 0;
            counter--;
            break;
        }
    }
    if (counter % 2 == 0)
    {
        cout << float(((pazymiai[counter / 2 - 1]) + (pazymiai[(counter / 2)])) / 2.0);
    }
    else
    {
        cout << pazymiai[(counter / 2)];
    }
    cout << endl;
}

int sugeneruojami_sakiciai()
{
    srand(time(NULL));
    return rand() % 10 + 1;
}

void automatinis_generavimas(studentas grupe[], int i, int pazymiu_skaicius)
{
    grupe[i].egz = sugeneruojami_sakiciai();
    for (int x = 0; x < pazymiu_skaicius; x++)
    {
        grupe[i].paz.push_back(sugeneruojami_sakiciai());
    }
    grupe[i].gal = grupe[i].gal / pazymiu_skaicius;
    grupe[i].gal = grupe[i].gal * 0.4 + 0.6 * grupe[i].egz;
}

void suvedami_duomenys(studentas grupe[], int i) //funkcija duoda vartotojui suvest pazymius ir egzamino pazymi
{
    int temp;
    do {
        cout << "Iveskite studento egzamino pazymi:\n";
        cin >> grupe[i].egz;
    } while (grupe[i].egz < 0 || grupe[i].egz > 10);
    cout << "Iveskite studento pazymius (kai baigsite, iveskite -1):";
    int counter = 0;
    do {
        cin >> temp;
        grupe[i].paz.push_back(temp);
        if (grupe[i].paz.at(counter) != -1) { grupe[i].gal = grupe[i].gal + (float)grupe[i].paz.at(counter); }
        counter++;
    } while (grupe[i].paz.at(counter) != -1);
    counter--;
    grupe[i].gal = grupe[i].gal / counter;
    grupe[i].gal = grupe[i].gal * 0.4 + 0.6 * grupe[i].egz;
}
bool has_digit(std::string s)
{
    return (s.find_first_of("0123456789") != std::string::npos);
}
void vardu_suvedimas(studentas grupe[], int i)
{
    cout << "Iveskite studento nr. " << i + 1 << " duomenis:\n";
    do {
        cout << "Iveskite studento nr. " << i + 1 << " vardas:\n";
        cin >> grupe[i].vardas;
    } while (grupe[i].vardas.length() < 0 || grupe[i].vardas.length() > 25 || has_digit(grupe[i].vardas));
    do {
        cout << "Iveskite studento nr. " << i + 1 << " pavarde:\n";
        cin >> grupe[i].pavarde;
    } while (grupe[i].pavarde.length() < 0 && grupe[i].pavarde.length() > 25 || has_digit(grupe[i].pavarde));
    cout << endl;
}


void spausdinti (studentas grupe[], int studentu_sk) //atspausdina rezultatus
{
    cout << "\n\n";
    cout << setw(20) << left << "Vardas"
        << setw(20) << left << "Pavarde"
        << setw(18) << left << "Galutinis(vid.)/"
        << left << "Galutinis(med.)\n"
        << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < studentu_sk; i++)
    {
        cout << setw(20) << left << grupe[i].vardas
            << setw(20) << left << grupe[i].pavarde
            << setw(18) << left << grupe[i].gal;
        mediana(grupe[i].paz);
    }
    cout << "\n\n";
}

int main()
{
    cout << "\n\n\n\n\n";
    int studentu_sk;
    string temp;
    do
    {
        cout << "Iveskite studentu kieki:\n";
        cin >> studentu_sk;
    } while (int(studentu_sk) < 0 || int(studentu_sk) > 250);
    studentas grupe[25];
    do
    {
        cout << "Automatisko generavimo paspasukite \"R\"\n Duomenu suvedimo paspauskite \"P\"\n";
        cin >> temp;
        if ( temp != "R" &&  temp != "P") { cout << "pakartokite, netinkamas simbolis\n"; }
    } while ( temp != "R" &&  temp != "P");
    for (int i = 0; i < studentu_sk; i++)
    {
        vardu_suvedimas(grupe, i);
        if (temp == "p" || temp == "P") { suvedami_duomenys(grupe, i); }
        else { automatinis_generavimas(grupe, i, 5); }
    }
    spausdinti (grupe, studentu_sk);
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
