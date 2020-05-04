#include "Mancare.h"
Mancare::Mancare() : Comanda() {}
Mancare::~Mancare() {}
Mancare::Mancare(const string nume, const string adresa, const string lista, const float pret) {
		this->numeClient = nume;
		this->adresaClient = adresa;
		this->pretTotal = pret;
		this->listaPreparate = lista;
	}
Mancare::Mancare(const Mancare& m) {
	this->numeClient = m.numeClient;
	this->adresaClient = m.adresaClient;
	this->listaPreparate = m.listaPreparate;
	this->pretTotal = m.pretTotal;
}

Mancare::Mancare(string line, char delim) {
	vector<string> elems = splitLine(line, delim);
	this->numeClient = elems[1];
	this->adresaClient = elems[2];
	this->listaPreparate = elems[3];
	this->pretTotal = strtof((elems[4]).c_str(), 0);
}
string Mancare::getNume() {
	return this->numeClient;
}
string Mancare::getAdresa() {
	return this->adresaClient;
}

float Mancare::getPret() {
	return this->pretTotal;
}
string Mancare::getLista() {
	return this->listaPreparate;
}

Mancare& Mancare::operator=(const Mancare& m) {
	this->numeClient = m.numeClient;
	this->adresaClient = m.adresaClient;
	this->listaPreparate = m.listaPreparate;
	this->pretTotal = m.pretTotal;
	return*this;
}

bool Mancare::operator ==(const Mancare& s) {
	return this->numeClient.compare(s.numeClient) == 0 && this->adresaClient.compare(s.adresaClient) == 0 && this->listaPreparate.compare(s.listaPreparate) == 0 && this->pretTotal == s.pretTotal;
}

ostream& operator<<(ostream& os, const Mancare& m) {
	os << m.numeClient << "," << m.adresaClient << "," << m.listaPreparate << "," << m.pretTotal;
	return os;
}