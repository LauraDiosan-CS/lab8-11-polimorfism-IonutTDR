#ifndef SHOPPING_H
#define SHOPPING_H
#include "Comanda.h"

class Shopping : public Comanda {
private:
	string listaCumparaturi;

public:
	Shopping();
	Shopping(const string nume, const string adresa, const string lista, const float pret);
	Shopping(const Shopping& s);
	Shopping(string line, char delim);

	string getLista();

	Shopping& operator = (const Shopping& s);
	string getNume();
	string getAdresa();

	float getPret();
	bool operator==(const Shopping& s);

	friend ostream& operator <<(ostream& os, const Shopping& s);

};
#endif // !SHOPPING_H
