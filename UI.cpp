#include "UI.h"
#include"Utils.h"

class exceptieUsername : public exception {
public:
	string what() throw() {
		return "Exista deja un User cu acest nume!";
	}
}exUsername;

class exceptiePaswword : public exception {
public:
	string what() throw() {
		return "Confirmare incorecta!";
	}
}exPass;

int checkPassword(string nume, map<int, User>users, string password) {
	typename map<int, User>::iterator it;
	for (it = users.begin(); it != users.end(); it++)
	{
		if (it->second.getUsername().compare(nume) == 0)
			if (it->second.getPassword().compare(password) != 0)
				return 1;
	}
	return 0;
}
int findUser(string nume, map<int, User> users) {
	typename map<int, User>::iterator it;
	for (it = users.begin(); it != users.end(); it++)
	{
		if (it->second.getUsername().compare(nume) == 0)
			return 1;
	}
	return 0;
}
void menuLogin() {
	cout << "1. Login\n";
	cout << "2. Register\n";
	cout << "x. Exit\n";
	cout << "\n";
}

void showMenu() {
	cout << "1. Afiseaza comenzile\n";
	cout << "2. Adauga o comanda\n";
	cout << "3. Logout\n";
	cout << "x. Exit\n";
	cout << "\n";
}

UI::UI(const Service& service) {
	this->s = service;
}

void UI::registrare(int& log) {
	try
	{
		string username, password, confirmPassword;
		int gasit = 0;
		cout << "Username: ";
		cin >> username;
		gasit = findUser(username, this->s.users());
		if (gasit == 1)
			throw exUsername;
		cout << "Password: ";
		cin >> password;
		cout << "Confirm password: ";
		cin >> confirmPassword;
		if (password.compare(confirmPassword) != 0)
			throw exPass;
		this->s.addUser(username, password);
		this->u = User(username, password);
		log = 1;
	}
	catch (exceptieUsername& e)
	{
		cout << e.what() << "\n";
	}
	catch (exceptiePaswword & e)
	{
		cout << e.what() << "\n";
	}
	cout << "\n";
}

void UI::logare(int& log) {
	try {
		string username, password;
		int gasit = 0;
		cout << "Username: ";
		cin >> username;
		gasit = findUser(username, this->s.users());
		if (gasit == 0)
		{
			throw exUsername;
		}
		cout << "Password: ";
		cin >> password;
		int check = 0;
		check = checkPassword(username, this->s.users(), password);
		if (check == 1)
		{
			throw exPass;
		}
		log = 1;
		this->u = User(username, password);
	}
	catch (exceptieUsername & e)
	{
		cout << "Nu exista niciun utilizator cu acest nume!" << "\n";
	}
	catch (exceptiePaswword & e)
	{
		cout << "Parola este incorecta!" << "\n";
	}
	cout << "\n";
}

void UI::afisareComenzi() {
	cout << "\n";
	map<int, Mancare> comenziMancare = this->s.comenziMancareDupaNume(this->u.getUsername());
	map<int, Shopping> comenziShopping = this->s.comenziShoppingDupaNume(this->u.getUsername());
	map<int, Mancare>::iterator it;
	cout << "Comenzi tip <Mancare>: \n";
	for (it = comenziMancare.begin(); it != comenziMancare.end(); it++)
		cout << it->first << "," << it->second << "\n";
	cout << "Comenzi tip <Shopping>: \n";
	cout << "\n";
	map<int, Shopping>::iterator itr;
	for (itr = comenziShopping.begin(); itr != comenziShopping.end(); itr++)
		cout << itr->first << "," << itr->second << "\n";
	cout << "\n";

}

void UI::adaugareMancare() {
	string nume, adresa, lista;
	float pret;
	cout << "Adresa: ";
	cin >> adresa;
	cout << "Lista preparate: ";
	cin >> lista;
	cout << "Pret: ";
	cin >> pret;

	this->s.addMancare(this->u.getUsername(), adresa, lista, pret);
	cout << "\n";
}

void UI::adaugareShopping() {
	string nume, adresa, lista;
	float pret;
	cout << "Adresa: ";
	cin >> adresa;
	cout << "Lista alimente: ";
	cin >> lista;
	cout << "Pret: ";
	cin >> pret;
	this->s.addShopping(this->u.getUsername(), adresa, lista, pret);
	cout << "\n";
}

UI::~UI(){}

void UI::run() {
	char firstOp;
	int first = 0;
	while (first == 0) {
		int log = 0;
		menuLogin();
		cout << "Alege optiune: ";
		cin >> firstOp;
		if (firstOp == '1')
		{
			this->logare(log);
		}
		if (firstOp == '2')
		{
			this->registrare(log);
		}
		if (log == 1)
		{
			char secondOp;
			int second = 0;
			while (second == 0)
			{
				showMenu();
				cout << "Alege optiune: ";
				cin >> secondOp;
				if (secondOp == '1')
					this->afisareComenzi();
				if (secondOp == '2')
				{
					cout << "a. Tip mancare\n";
					cout << "b. Tip shopping\n";
					char thirdOp;
					cout << "Alege optiune: ";
					cin >> thirdOp;
					if (thirdOp == 'a')
						this->adaugareMancare();
					if (thirdOp == 'b')
						this->adaugareShopping();
				}
				if (secondOp == '3')
				{
					this->u.logout();
					second = 1;
				}
				if (secondOp == 'x')
				{
					second = 1;
					first = 1;
				}
			}
		}
		if (firstOp == 'x')
		{
			first = 1;
		}
	}
}