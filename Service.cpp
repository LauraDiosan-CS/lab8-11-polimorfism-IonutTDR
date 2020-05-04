#include "Service.h"

class exceptiePret : public exception {
public:
	string what() throw() {
		return "Date invalide!";
	}
}ex;


Service::Service(){
	this->repoMancare = NULL;
	this->repoShopping = NULL;
	this->repoUser = NULL;
}

Service::Service(Repository<Mancare>* r1, Repository<Shopping>* r2, Repository<User>* r3) {
	this->repoMancare = r1;
	this->repoShopping = r2;
	this->repoUser = r3;
}

void Service::addMancare(const string nume, const string adresa, const string lista, const float pret)	{
	try
	{
		if (pret < 0.0)
			throw ex;
		if (lista.compare("") == 0)
			throw ex;
		Mancare m(nume, adresa, lista, pret);
		this->repoMancare->add(m);
		((RepositoryFile<Mancare>*)repoMancare)->saveToFile();

	}
	catch (exceptiePret& e)
	{
		cout << e.what() << "\n";
	}

}

void Service::addShopping(const string nume, const string adresa, const string lista, const float pret) {
	try
	{
		if (pret < 0.0)
			throw ex;
		if (lista.compare("") == 0)
			throw ex;
		Shopping s(nume, adresa, lista, pret);
		this->repoShopping->add(s);
		((RepositoryFile<Shopping>*)repoShopping)->saveToFile();

	}
	catch (exceptiePret & e)
	{
		cout << e.what() << "\n";
	}

}

void Service::addUser(string username, string password) {
	User u(username, password);
	this->repoUser->add(u);
	((RepositoryFile<User>*)repoUser)->saveToFile();
}

map<int, Mancare> Service::comenziMancareDupaNume(string nume) {
	map<int, Mancare> elems = this->repoMancare->getAll();
	map<int, Mancare> comenzi;
	typename map<int, Mancare>::iterator it;
	for (it = elems.begin(); it != elems.end(); it++)
		if (it->second.getNume().compare(nume) == 0)
			comenzi.insert(pair<int, Mancare>(it->first, it->second));
	return comenzi;
}

map<int, Shopping> Service::comenziShoppingDupaNume(string nume) {
	map<int, Shopping> elems = this->repoShopping->getAll(), comenzi;
	map<int, Shopping>::iterator it;
	for (it = elems.begin(); it != elems.end(); it++)
		if (it->second.getNume().compare(nume) == 0)
			comenzi.insert(pair<int, Shopping>(it->first, it->second));
	return comenzi;
}

map<int, User> Service::users() {
	return repoUser->getAll();
}

Service::~Service(){}

