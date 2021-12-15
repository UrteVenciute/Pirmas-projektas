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
int uzklausakiekpaz();
void darbasSuFailu(vector <int>& v1, char& atsakymas);

void failoNuskaitymas_list(list <studentas>& grupe1, int& v1);
void failoNuskaitymas(vector <studentas>& grupe1, int& v1);
void rusiavimasVector(vector <studentas>& grupe_vector, vector <studentas>& protingi_vector, vector <studentas>& vargsiukai_vector, vector <double>& laikas_vector, char& atsakymas);
void rusiavimasList(list <studentas>& grupe_list, list <studentas>& protingi_list, list <studentas>& vargsiukai_list, vector<double>& laikas_list, char& atsakymas);
void rusiavimas2(vector <studentas>& grupe_vector, list <studentas>& grupe_list, vector <studentas>& vargsiukai_vector_2, list <studentas>& vargsiukai_list_2, vector <double>& time_vector, vector<double>& time_list, char& atsakymas)