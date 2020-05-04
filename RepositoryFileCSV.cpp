#include "RepositoryFileCSV.h"

template <class T> void RepositoryFileCSV<T> ::loadFromFile() {
	ifstream file(this->fileName);
	this->elems.clear();
	this->size = 0;
	string line;
	while (getline(file, line))
	{
		T ob(line, ',');
		this->elems.insert(pair<int, T>(this->size++, ob));
	}
}

template <class T> void RepositoryFileCSV<T> ::saveToFile() {
	ofstream g(this->fileName);
	typename map<int, T>::iterator it;
	for (it = this->elems.begin(); it != this->elems.end(); it++)
		g << it->first << "," << it->second << endl;
}