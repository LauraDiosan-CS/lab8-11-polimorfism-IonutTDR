#include "RepositoryFileHTML.h"

template <class T> void RepositoryFileHTML<T>::saveToFile() {
	ofstream g(this->fileName);
	g << "<html>" << endl;
	g << "<head> <title> RepoHTML </title> </head>" << endl;
	g << "<body>" << endl;
	typename map<int, T>::iterator it;
	for (it = this->elems.begin(); it != this->elems.end(); it++)
		g << "<p>" << it->first << "," << it->second << "</p>" << endl;
	g << "</body>" << endl << "</html>";
}

template <class T> void RepositoryFileHTML<T>::loadFromFile() {
	ifstream f(this->fileName);
	string line;
	this->size = 0;
	this->elems.clear();
	while (getline(f, line)) {
		if (line[1] == 'p') {
			line.erase(line.end() - 4, line.end());
			T ob(line, ',');
			this->elems.insert(pair<int, T>(this->size++, ob));
		}
	}
}