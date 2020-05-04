#ifndef MANCARE_H
#define MANCARE_H
#include "Comanda.h"


class Mancare : public Comanda {
private:
	string listaPreparate;
public:
	Mancare();
	~Mancare();
	Mancare(const string nume, const string adresa, const string lista, const float pret);
	Mancare(const Mancare& m);
	Mancare(string line, char delim);
	string getNume();
	string getAdresa();
	float getPret();
	string getLista();

	Mancare& operator=(const Mancare& m);

	bool operator ==(const Mancare& s);

	friend ostream& operator<<(ostream& os, const Mancare& m);

};

#endif // !MANCARE_H