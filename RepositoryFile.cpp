#include "RepositoryFile.h"
template<class T> RepositoryFile<T>::RepositoryFile() :Repository<T>()
{
}

template<class T> RepositoryFile<T>::RepositoryFile(const char* name)
{
	this->fileName = new char[strlen(name) + 1];
	strcpy_s(this->fileName, strlen(name) + 1, name);
}

template<class T> RepositoryFile<T>::~RepositoryFile()
{
}

template<class T> void RepositoryFile<T>::saveToFile()
{
}

template<class T> void RepositoryFile<T>::loadFromFile()
{
}