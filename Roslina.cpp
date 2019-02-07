#include "stdafx.h"
#include "Roslina.h"
#include"Organizm.h"
#include"Swiat.h"
#include"Trawa.h"
#include"Mlecz.h"
#include"Guarana.h"
#include"WilczeJagody.h"

Roslina::Roslina(int x, int y, Swiat& s)
	:Organizm(x, y, s)
{
}

void Roslina::akcja()
{

	int X = this->x;
	int Y = this->y;

	int szansa = rand() % 100;
		if (szansa >= 75)
		{
			
			losuj_pozycje(X, Y);

			if (s->sprawdz(X, Y) == -1)
			{
				switch (this->nazwa)
				{
				case trawa:
				{
					Trawa* t = new Trawa(X, Y, *s);
					s->dodaj_org(t);
					break;
				}
				case jagody:
				{
					WilczeJagody* j = new WilczeJagody(X, Y, *s);
					s->dodaj_org(j);
					break;
				}
				case guarana:
				{
					Guarana* g = new Guarana(X, Y, *s);
					s->dodaj_org(g);
					break;
				}
				default:
					Mlecz* m = new Mlecz(X, Y, *s);
					s->dodaj_org(m);
					break;
				}
			}
			
		}
		this->wiek++;
	
}

void Roslina::kolizja(Organizm* org1, int x, int y)
{

}

bool Roslina::czyOdbilAtak(Organizm *org1)
{
	return false;
}


Roslina::~Roslina()
{
}
