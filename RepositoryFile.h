#ifndef REPOSITORYFILE_H
#define REPOSITORYFILE_H

#include "Repository.h"
#include <stdlib.h>
#include <fstream>
using namespace std;
template <class T> class RepositoryFile : public Repository<T>
{

protected:
	char* fileName;

public:
	RepositoryFile();
	RepositoryFile(const char*);
	virtual void saveToFile();
	virtual void loadFromFile();
	~RepositoryFile();
};

#endif // !REPOSITORYFILE_H
