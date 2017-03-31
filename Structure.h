#include <string>

using namespace std;

#ifndef STRUCT_INCLUDED
#define STRUCT_INCLUDED



struct Gorelky
{
    int id;                     // ID
    string mark, type_of_con;   // марка, тип соединения
    int ves,power;              // Вес горелки, Мощность
    bool piezopodjig;           // Пьезоподжиг
};

#endif
