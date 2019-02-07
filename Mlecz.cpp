#include "stdafx.h"
#include "Mlecz.h"
#include"Organizm.h"
#include"Swiat.h"
#include<iostream>
using namespace std;

Mlecz::Mlecz(int x, int y, Swiat& s)
	:Roslina(x, y, s)
{
	sila = 0;
	inicjatywa = 0;
	nazwa = mlecz;
}

void Mlecz::rysowanie()
{
	cout << 'M';
}

void Mlecz::akcja()
{
	int X = this->x;
	int Y = this->y;
	bool flaga = true;
	int szansa = rand() % 100;
	for (int i = 0; i < 3; i++)
	{
		if (szansa >= 75)
		{

			losuj_pozycje(X, Y);

			if (s->sprawdz(X, Y) == -1)
			{
				switch (this->nazwa)
				{
				case mlecz:
					Mlecz* m = new Mlecz(X, Y, *s);
					s->dodaj_org(m);
					break;
				}
			}

		}
	}

}


Mlecz::~Mlecz()
{
}
