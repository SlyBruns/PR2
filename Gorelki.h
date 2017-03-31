#include <string>
#include "Structure.h"

using namespace std;

#ifndef GORELKI_INCLUDED
#define GORELKI_INCLUDED

void add_gorelka(); // дописано
void del_gorelka(); // дописано

void nullGorelka(Gorelky* one);
bool read_gorelka(Gorelky* new_gorelka);
bool check_id(int id);
void print_Gorelka(Gorelky* one);

void free_memory(); // дописано
void print_all(); // дописано

void show_help(); // дописано

void change_Gorelka(); // дописано

void savefile(); // дописано
void readfile(); // дописано
#endif