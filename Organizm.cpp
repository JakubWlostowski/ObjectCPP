#include "stdafx.h"
#include<iostream>
#include"Swiat.h"
#include"Organizm.h"
#define ROZM 20
using namespace std;


int Organizm::getX()//ok
{
	return x;
}

int Organizm::getY()//ok
{
	return y;
}

void Organizm::setInicjatywa(int ini)//ok
{
	this->inicjatywa = ini;
}

void Organizm::setSila(int s)//ok
{
	this->sila = s;
}

int Organizm::getSila()//ok
{
	return sila;
}

int Organizm::getInicjatywa()//ok
{
	return inicjatywa;
}

int Organizm::getWiek()//ok
{
	return wiek;
}

Organizm::Organizm(int x, int y, Swiat& s)//ok
{
	this->x = x;
	this->y = y;
	this->s = &s;
	wiek = 0;
}

int Organizm::dodaj_sile()//ok
{
	return 0;
}

string Organizm::nazwa_organizmu()//ok
{
	switch (this->nazwa)
	{
	case wilk:
		return "Wilk";
		break;
	case owca:
		return "Owca";
		break;
	case lis:
		return "Lis";
		break;
	case zolw:
		return "Zolw";
		break;
	case antylopa:
		return "Antylopa";
		break;
	case trawa:
		return "Trawa";
		break;
	case mlecz:
		return "Mlecz";
		break;
	case jagody:
		return "Jagody";
		break;
	case barszcz:
		return "Barszcz";
		break;
	case czlowiek:
		return "Czlowiek";
		break;
	case guarana:
		return "Guarana";
		break;
	}
}

 bool Organizm::sprawdz_wokol()//ok
{
	 if ((s->sprawdz(x + 1, y) == -1 && x <= s->getrozmX() - 1) || (s->sprawdz(x - 1, y) == -1 && x > 1) || (s->sprawdz(x , y + 1) == -1 && y <= s->getrozmY() - 1) || (s->sprawdz(x, y - 1) == -1  && y > 1))
		 return true;
	 else return false;
} 

 void Organizm::losuj_pozycje(int &X, int &Y)//ok
 {
	 bool flaga = true;
	 while (flaga)
	 {
		 int opcja = rand() % 4;
		 if (opcja == 0 && X <= s->getrozmX() - 1)
		 {
			 X++;
			 flaga = false;
		 }
		 else if (opcja == 1 && X > 1)
		 {
			 X--;
			 flaga = false;
		 }
		 else if (opcja == 2 && Y <= s->getrozmY() - 1)
		 {
			 Y++;
			 flaga = false;
		 }
		 else if (opcja == 3 && Y > 1)
		 {
			 Y--;
			 flaga = false;
		 }
	 }
 }

nazwa_org Organizm::getNazwa()//ok
{
	return nazwa;
}


