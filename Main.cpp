#include "Tests.h"
#include "UI.h"

int main()
{
	test_entitati();
	test_repo();
	Repository<Mancare>* repoMancare = new RepositoryFileCSV<Mancare>("Mancare.csv");
	((RepositoryFile<Mancare>*)repoMancare)->loadFromFile();
	Repository<Shopping>* repoShopping = new RepositoryFileCSV<Shopping>("Shopping.csv");
	((RepositoryFile<Shopping>*)repoShopping)->loadFromFile();
	Repository<User>* repoUser = new RepositoryFileCSV<User>("User.csv");
	((RepositoryFile<User>*)repoUser)->loadFromFile();

	Service serviceCSV(repoMancare, repoShopping, repoUser);

	Repository<Mancare>* repo1 = new RepositoryFileHTML<Mancare>("Mancare.html");
	((RepositoryFile<Mancare>*)repo1)->loadFromFile();
	Repository<User>* repo2 = new RepositoryFileHTML<User>("User.html");
	((RepositoryFile<User>*)repo2)->loadFromFile();
	Repository<Shopping>* repo3 = new RepositoryFileHTML<Shopping>("Shopping.html");
	((RepositoryFile<Shopping>*)repo3)->loadFromFile();

	Service serviceHTML(repo1, repo3, repo2);

	UI uiCSV(serviceCSV);
	UI uiHTML(serviceHTML);

	char op;
	int ok = 0;
	while (ok == 0)
	{
		cout << "Alege tipul de fisier \n";
		cout << "1. CSV\n";
		cout << "2. HTML\n";
		cout << "3. Iesire\n";
		cout << "Optiune: ";
		cin >> op;
		if (op == '1')
			uiCSV.run();
		if (op == '2')
			uiHTML.run();
		if (op == '3')
			break;
	}
	return 0;
}