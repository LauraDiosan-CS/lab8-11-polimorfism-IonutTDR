#include "Tests.h"

void test_entitati()
{
	Comanda* c[3];
	c[0] = new Mancare("Ionut", "Str Husului vaslui", "hamburger pizza", 70.0);
	
	assert(c[0]->getPret() == 70.0);
	assert(c[0]->getAdresa().compare( "Str Husului vaslui") == 0);
	assert(c[0]->getNume().compare("Ionut") == 0);

	Mancare m1("Ionut", "Str Husului vaslui", "hamburger pizza", 70.0);
	Mancare m2;
	m2 = m1;
	assert(m2 == m1);

	string line = "0,Ionut,gsdgsdg,skate,50.0";
	Mancare m3(line, ',');
	assert(m3.getPret() == 50.0);

	c[1] = new Shopping("Toader", "Str Trandafirilor", "spray", 20.0);
	
	assert(c[1]->getAdresa().compare( "Str Trandafirilor") == 0);
	assert(c[1]->getNume().compare( "Toader") == 0);
	assert(c[1]->getPret() == 20.0);
	assert(c[1]->getNume().compare( "Toader") == 0);

	User u1("Ionut", "qazedcwsx123");

	assert(u1.getUsername().compare("Ionut") == 0);

}


void test_repo() {
	std::ofstream ofs;
	ofs.open("MancareTest.csv", std::ofstream::out | std::ofstream::trunc);
	ofs.close();
	Repository<Mancare> repo;
	Mancare m1("Ionut", "Str Husului vaslui", "hamburger pizza", 70.1);
	repo.add(m1);
	assert(repo.getSize() == 1);

	RepositoryFileCSV<Mancare> repofile("MancareTest.csv");
	repofile.loadFromFile();
	assert(repofile.getSize() == 0);

	repofile.add(m1);
	map<int, Mancare> elems = repofile.getAll();
	assert( ( fabs(elems[0].getPret() - 70.1) < 0.005) == 1);
	repofile.saveToFile();

	RepositoryFileHTML<Mancare> repof("MancareTest.html");
	repof.add(m1);
	repof.saveToFile();
	
	RepositoryFileHTML<Mancare> repohtml("MancareTest.html");
	repohtml.loadFromFile();

}