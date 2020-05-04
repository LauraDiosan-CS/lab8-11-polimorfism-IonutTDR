#ifndef REPOSITORYFILECSV_H
#define REPOSITORYFILECSV_H
#include <string>
#include "RepositoryFile.h"

template <class T>
class RepositoryFileCSV : public RepositoryFile<T> {
public:
	RepositoryFileCSV(const char* fileName) : RepositoryFile<T>(fileName){}
	~RepositoryFileCSV(){}
	void loadFromFile();
	void saveToFile();
};
#endif // !REPOSITORYFILECSV_H
