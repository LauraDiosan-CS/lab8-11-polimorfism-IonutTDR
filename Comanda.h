#ifndef COMANDA_H
#define COMANDA_H
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include "Utils.h"
using namespace std;

class Comanda {
protected:
	string numeClient;
	string adresaClient;
	float pretTotal;
public:
	Comanda();

	virtual string getNume() = 0;
	virtual string getAdresa() = 0;
	virtual float getPret() = 0;

	virtual ~Comanda(){}
};

#endif // !COMANDA_H
