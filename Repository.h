#ifndef REPOSITORY_H
#define REPOSITORY_H
#include <map>
using namespace std;

template <class T>
class Repository {
protected:
	map<int, T> elems;
	int size;

public:
	Repository();
	void add(const T& t);
	void remove(int poz);
	void update(int poz, T& newT);
	map<int, T> getAll();
	int getSize();
	~Repository();

};
#endif