#include "Mediana.h"
#include <iostream>
#include <algorithm>
using namespace std;


double mediana(vector<int>vec)
{
    typedef vector<int>::size_type vecSize;
    vecSize size = vec.size();
    if (size == 0) //std:domain_error deklaruota <stdexcept>
        throw std::domain_error("negalima skaiciuoti medianos tusciam vektoriui");
    sort(vec.begin(), vec.end());
    vecSize vid = size / 2;
    return size % 2 == 0 ? (vec[vid] + vec[vid - 1]) / 2.0 : vec[vid];
}