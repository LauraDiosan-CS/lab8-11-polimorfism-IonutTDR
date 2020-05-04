#ifndef REPOSITORY_H
#define REPOSITORY_H
#include <map>
using namespace std;

template <class T>
class Repository {
protected:
	map<int, T> elems;
	int n;

public:
	Repository();
	Repository(const Repository<T>& r);
	void add(const T& t);
	void remove(int poz);
	void update(T& t, T& newT);
	map<int, T> get(int poz);
	int size();
	Repository<T>& operator=(const Repository<T>& r);
	~Repository();

};
#endif