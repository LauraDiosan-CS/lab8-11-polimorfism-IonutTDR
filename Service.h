#ifndef SERVICE_H
#define SERVICE_H

#include "Tests.h"
#include "Mancare.h"
#include "Shopping.h"
#include "User.h"

class  Service {
protected:
	Repository<Mancare>* repoMancare;
	Repository<Shopping>* repoShopping;
	Repository<User>* repoUser;
public:
	Service();
	Service(Repository<Mancare>* r1, Repository<Shopping>* r2, Repository<User>* r3);
	~Service();
	void addMancare(const string nume, const string adresa, const string lista, const float pret);
	void addShopping(const string nume, const string adresa, const string lista, const float pret);
	void addUser(string username, string password);
	map<int, Mancare>comenziMancareDupaNume(string nume);
	map<int, Shopping>comenziShoppingDupaNume(string nume);
	map<int, User>users();

};
#endif