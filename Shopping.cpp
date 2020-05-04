#include "Shopping.h"
Shopping::Shopping() : Comanda() {}
Shopping::Shopping(const string nume, const string adresa, const string lista, const float pret) {
	this->listaCumparaturi = lista;
	this->numeClient = nume;
	this->adresaClient = adresa;
	this->pretTotal = pret;
}
Shopping::Shopping(const Shopping& s) {
	this->numeClient = s.numeClient;
	this->adresaClient = s.adresaClient;
	this->listaCumparaturi = s.listaCumparaturi;
	this->pretTotal = s.pretTotal;
}
Shopping::Shopping(string line, char delim) {
	vector<string> elems = splitLine(line, delim);
	this->numeClient = elems[1];
	this->adresaClient = elems[2];
	this->listaCumparaturi = elems[3];
	this->pretTotal = strtof((elems[4]).c_str(), 0);
}

string Shopping::getLista() {
	return this->listaCumparaturi;
}

Shopping& Shopping::operator = (const Shopping& s) {
	this->numeClient = s.numeClient;
	this->adresaClient = s.adresaClient;
	this->listaCumparaturi = s.listaCumparaturi;
	this->pretTotal = s.pretTotal;
	return*this;
}
string Shopping::getNume() {
	return this->numeClient;
}
string Shopping::getAdresa() {
	return this->adresaClient;
}


float Shopping::getPret() {
	return this->pretTotal;
}
bool Shopping::operator==(const Shopping& s) {
	return this->numeClient.compare(s.numeClient) == 0 && this->adresaClient.compare(s.adresaClient) == 0 && this->listaCumparaturi.compare(s.listaCumparaturi) == 0 && this->pretTotal == s.pretTotal;
}

ostream& operator <<(ostream& os, const Shopping& s) {
	os << s.numeClient << "," << s.adresaClient << "," << s.listaCumparaturi << "," << s.pretTotal;
	return os;
}