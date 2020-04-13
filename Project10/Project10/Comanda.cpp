#include "Comanda.h"
Comanda::Comanda()
{
	this->nume = NULL;
	this->adresa = NULL;
	pret = 0.0;
}
Comanda::Comanda(const char* nume, const char* adresa, float pret)
{
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);

	this->adresa = new char[strlen(adresa) + 1];
	strcpy_s(this->adresa, strlen(adresa) + 1, adresa);

	this->pret = pret;
}
Comanda::~Comanda()
{
	delete[] this->nume;
	delete[] this->adresa;
	pret = 0.0;
}
Comanda::Comanda(const Comanda& m)
{
	this->nume = new char[strlen(m.nume) + 1];
	strcpy_s(this->nume, strlen(m.nume) + 1, m.nume);

	this->adresa = new char[strlen(m.adresa) + 1];
	strcpy_s(this->adresa, strlen(m.adresa) + 1, m.adresa);

	this->pret = m.pret;
}
char* Comanda::getNume()
{
	return this->nume;
}
char* Comanda::getAdresa()
{
	return this->adresa;
}
float Comanda::getPret()
{
	return this->pret;
}

Comanda& Comanda::operator=(const Comanda& m)
{
	// TODO: insert return statement here
	this->nume = new char[strlen(m.nume) + 1];
	strcpy_s(this->nume, strlen(m.nume) + 1, m.nume);

	this->adresa = new char[strlen(m.adresa) + 1];
	strcpy_s(this->adresa, strlen(m.adresa) + 1, m.adresa);

	this->pret = m.pret;
	return*this;
}

ostream& operator<<(ostream& os, const Comanda& m)
{
	os << m.nume << " " << m.adresa << "  " << m.pret << "\n";
	return os;
}