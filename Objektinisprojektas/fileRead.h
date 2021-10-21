#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <iterator>
#include "Studentas.h"
#include "Spausdinti.h"
#include "Mediana.h"

int countWordsInString(std::string const& str);

void read_from_file(vector<studentas>& grupe, int* pazymiu_sk);
