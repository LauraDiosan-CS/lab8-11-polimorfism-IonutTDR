#pragma once
#include "Comanda.h"
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

class Mancare: public Comanda{

private:
	string lista;

public:
	Mancare();
	Mancare(const char* nume, const char* adresa, string lista, float pret);
	~Mancare();
	Mancare(const Mancare& m);
	string getListaPreparate();
	Mancare& operator=(const Mancare& m);
	friend ostream& operator<<(ostream& os, const Mancare& m);

};