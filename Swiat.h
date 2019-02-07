#pragma once
#define ROZM 20
#include<vector>
class Organizm;
using namespace std;

class Swiat
{
private:
	
	vector <Organizm*> organizmy;
	vector <string> info;
	int rozmX, rozmY;
	int liczba_org;
public:
	void wykonajTure();
	void rysujSwiat();
	void dodaj_org(Organizm* org);
	void usun_org(Organizm* org);
	void dodaj_info(string inf);
	int getLiczba_org();
	int getrozmX();
	int getrozmY();
	void zapisz();
	void wczytaj();
	Organizm* getOrg(int i);
	int sprawdz(int a, int b);
	Swiat(int rozmX, int rozmY, int liczba_org);
	~Swiat();
	Organizm* operator[](int i);
};
