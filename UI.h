#ifndef UI_H
#define UI_H

#include "Service.h"

class UI{
private:
    Service s;
    User u;
public:
    UI(const Service& s);
    void registrare(int& log);
    void logare(int& log);
    void logout();
    void adaugareMancare();
    void adaugareShopping();
    void afisareComenzi();
    void run();
    ~UI();
 };
int checkPassword(string nume, map<int, User>users, string password);
int findUser(string nume, map<int, User> users);
void showMenu();
void menuLogin();

#endif 
