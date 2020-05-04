#ifndef REPOSITORYFILEHTML_H
#define REPOSITORYFILEHTML_H


#include "RepositoryFile.h"
#include <string>

template <class T>
class RepositoryFileHTML : public RepositoryFile<T> {
public:
	RepositoryFileHTML(const char* file):RepositoryFile<T>(file){}
	void loadFromFile();
	void saveToFile();
	~RepositoryFileHTML(){}
};
#endif // !REPOSITORYFILEHTML_H