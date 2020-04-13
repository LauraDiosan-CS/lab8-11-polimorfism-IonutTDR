#pragma once
#include <list>
#include <iostream>
#include <cstring>
#include <string>
#include <ostream>
using namespace std;

class Comanda {
protected:
	char* nume;
	char* adresa;
	float pret;

public:
	Comanda();
	Comanda(const char* nume, const char* adresa, float pret);
	~Comanda();
	Comanda(const Comanda& m);
	char* getNume();
	char* getAdresa();
	float getPret();
	Comanda& operator=(const Comanda& m);
	friend ostream& operator<<(ostream& os, const Comanda& m);
};