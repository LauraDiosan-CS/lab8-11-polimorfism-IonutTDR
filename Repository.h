#ifndef REPOSITORYSTL_H
#define REPOSITORYSTL_H
#include "Comanda.h"
#include<iterator>
#include <map>
#include <iostream>
#include <ostream>
using namespace std;
template <class T>
class Repository {
protected:A
	map<int, T> elem;
	int size;
public:
	Repository();
	~Repository();
	void addElem(const T el);
	void removeElem(int poz);
	void updateElem(int poz, const T newElem);
	int getSize();
	map<int, T> getAll();
};
#endif // !REPOSITORY_H