#pragma once
#include "spausdinimas.h"
#include "Studentas.h"
#include <iostream>
#include <iomanip> 
#include <string>
#include <algorithm>
#include <vector>
#include <stdlib.h>    
#include <time.h>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <chrono>
#include <list>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setw;
using std::left;
using std::fixed;
using std::setprecision;
using std::sort;
using std::vector;
using std::ifstream;
using std::cerr;
using std::getline;
using std::ofstream;
using std::stringstream;
using std::to_string;
using std::list;


double vidurkis(studentas& s);

void failuKurimas(vector <int>& v1, int& ndKiek);
void darbasSuFailu(vector <int>& v1, int& ndKiek, char& atsakymas);
void failoNuskaitymas(vector <studentas>& grupe1, int& v1, vector <double>& laikas, int& ndKiek);
void failoNuskaitymas_list(list <studentas>& grupe1, int& v1, vector <double>& laikas, int& ndKiek);
void rusiavimas(vector <studentas>& grupe_vector, list <studentas>& grupe_list, vector <studentas>& protingi_vector, vector <studentas>& tinginiai_vector, list <studentas>& protingi_list, list <studentas>& tinginiai_list, vector <double>& laikas_vector, vector<double>& laikas_list, char& atsakymas);


