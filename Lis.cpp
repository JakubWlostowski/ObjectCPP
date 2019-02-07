#include "stdafx.h"
#include "Lis.h"
#include<iostream>

namespace Zwierzeta
{
	Lis::Lis(int x, int y, Swiat& s)
		:Zwierze(x, y, s)
	{
		sila = 3;
		inicjatywa = 7;
		nazwa = lis;
	}

	void Lis::rysowanie()
	{
		cout << "L";
	}

	void Lis::akcja()
	{
		
		int X = this->x;
		int Y = this->y;

		losuj_pozycje(X, Y);

		int k = s->sprawdz(X, Y);

		if (k != -1)
		{
			Organizm* w = s->getOrg(k);
			if(w->getSila() < this->sila)
			kolizja(w, X, Y);
		}
		else
		{
			this->x = X;
			this->y = Y;
		}
	}


	Lis::~Lis()
	{
	}
}