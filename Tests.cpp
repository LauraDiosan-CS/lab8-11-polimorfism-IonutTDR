#include "Tests.h"
#include <cstring>
#include <string>

void test_comanda()
{
	Comanda m("Ionut", "Str.Husului", 60.0);

	assert(strcmp(m.getNume(), "Ionut") == 0);
	assert(strcmp(m.getAdresa(), "Str.Husului") == 0);
	assert(m.getPret() == 60.0);

	Comanda c = m;

	assert(strcmp(c.getNume(), "Ionut") == 0);
	assert(strcmp(c.getAdresa(), "Str.Husului") == 0);
	assert(c.getPret() == 60.0);
}

void test_mancare()
{
	Mancare m("Toader", "Str.Podului", "pizza hamburger", 70.0);
	assert(strcmp(m.getNume(), "Toader") == 0);
	assert(strcmp(m.getAdresa(), "Str.Podului") == 0);
	assert(m.getPret() == 70.0);
	string s = "pizza hamburger";
	assert(m.getListaPreparate().compare(s) == 0);
}