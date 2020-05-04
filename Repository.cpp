#include "Repository.h"

template <class T> Repository<T>::Repository() { this->size = 0; }
template <class T> Repository<T>::~Repository() { this->size = 0; }

template <class T> void Repository<T>::add(const T& t)
{
	this->elems.insert(pair<int, T>(this->size++, t));
}

template <class T> void Repository<T>::remove(int poz)
{
	this->elems.erase(poz);
}

template <class T> void Repository<T>::update(int t, T& newT)
{
	this->elems[t] = newT;
}

template <class T> map<int, T> Repository<T>::getAll()
{
	return this->elems;
}

template <class T> int Repository<T>::getSize() {
	return this->elems.size();
}