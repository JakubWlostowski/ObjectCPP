#pragma once
#include<vector>
#include"Swiat.h"
class Swiat;
enum nazwa_org
{
	wilk,
	owca,
	lis,
	zolw,
	antylopa,
	czlowiek,
	trawa,
	mlecz,
	guarana,
	jagody,
	barszcz,
};

class Organizm
{
protected:
	int sila;
	int inicjatywa;
	int x, y;
	Swiat *s;
	nazwa_org nazwa;
	int wiek;

public:
	virtual void akcja() = 0;
	virtual void kolizja(Organizm* org1,int x,int y) = 0;
	virtual void rysowanie() = 0;
	virtual bool czyOdbilAtak(Organizm* org1) = 0;
	bool sprawdz_wokol();
	virtual int dodaj_sile();
	int getWiek();
	int getX();
	int getY();
	int getSila();
	int getInicjatywa();
	void setSila(int s);
	void setInicjatywa(int ini);
	void losuj_pozycje(int &X, int &Y);
	string nazwa_organizmu();
	nazwa_org getNazwa();
	Organizm(int, int, Swiat&);
};
