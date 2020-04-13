#include "Mancare.h"
#include <iostream>
#include <ostream>
using namespace std;

Mancare::Mancare()
{
	this->nume = NULL;
	this->adresa = NULL;
	pret = 0.0;
	this->lista = "";
}
Mancare::Mancare(const char* nume, const char* adresa, string lista, float pret)
{
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);

	this->adresa = new char[strlen(adresa) + 1];
	strcpy_s(this->adresa, strlen(adresa) + 1, adresa);

	this->pret = pret;
	this->lista = lista;
}
Mancare::~Mancare()
{
	delete[] this->nume;
	delete[] this->adresa;
	pret = 0.0;
}
Mancare::Mancare(const Mancare& m)
{
	this->nume = new char[strlen(m.nume) + 1];
	strcpy_s(this->nume, strlen(m.nume) + 1, m.nume);

	this->adresa = new char[strlen(m.adresa) + 1];
	strcpy_s(this->adresa, strlen(m.adresa) + 1, m.adresa);

	this->pret = m.pret;
	this->lista = m.lista;
}
string Mancare::getListaPreparate()
{
	return this->lista;
}

Mancare& Mancare::operator=(const Mancare& m)
{
	// TODO: insert return statement here
	this->nume = new char[strlen(m.nume) + 1];
	strcpy_s(this->nume, strlen(m.nume) + 1, m.nume);

	this->adresa = new char[strlen(m.adresa) + 1];
	strcpy_s(this->adresa, strlen(m.adresa) + 1, m.adresa);

	this->pret = m.pret;
	this->lista = m.lista;
	return*this;
}


ostream& operator<<(ostream& os, const Mancare& m)
{
	os << m.nume << " " << m.adresa << " [ ";
	for (int i = 0; i < m.lista.length(); i++)
	{
		os << m.lista[i] << " ";
	}
	os << "] " << m.pret << "\n";
	return os;
}