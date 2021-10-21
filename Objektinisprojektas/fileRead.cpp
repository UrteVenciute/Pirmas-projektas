#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <iterator>
using namespace std;
using std::vector;
#include "fileRead.h"

int countWordsInString(std::string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}

ifstream fileRead("studentai10000.txt.txt");
void read_from_file(vector<studentas>& grupe, int* pazymiu_sk)
{
    int sum = 0;
    int temp;
    ifstream fileRead("studentai10000.txt.txt");
    string buff;
    try {

        if (!fileRead.is_open())
            throw 0;

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
    catch (int e)
    {
        std::cout << "Neteisingas failo pavadinimas " << e << std::endl;

    }
}
