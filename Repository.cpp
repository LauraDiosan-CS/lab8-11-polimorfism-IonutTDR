#include "Repository.h"
#include <iostream>
using namespace std;

template <class T> Repository<T>::Repository() { this->n = 0; }
template <class T> Repository<T>::~Repository() { this->n = 0; }

template <class T> void Repository<T>::add(const T& t)
{
	this->elems.insert(pair<int, T>(this->n++, t));
}

template <class T> void Repository<T>::remove(int poz)
{
	this->elems.erase(poz);
}

template <class T> void Repository<T>::update(T& t, T& newT)
{
	typename map<int, T> ::iterator it;

}

template <class T> map<int, T> Repository<T>::get(int poz)
{
	return this->elems[poz];
}

template <class T> int Repository<T>::size() {
	return this->elems.size();
}

template <class T>Repository<T> :: Repository(const Repository<T>& r){
	this->elems = r.elems;
	this->n = r.n;
}

template <class T>Repository<T>& Repository<T>::operator=(const Repository<T>& r) {
	this->elems = r.elems;
	this->n = r.n;
	return*this;
}

