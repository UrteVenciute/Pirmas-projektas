#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <iterator>
#include <vector>
using std::vector;
#include "fileRead.h"
#include "Spausdinti.h"


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