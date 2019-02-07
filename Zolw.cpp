#include "stdafx.h"
#include "Zolw.h"
#include"Zwierzeta.h"
#include"Organizm.h"
#include<iostream>
namespace Zwierzeta
{
	Zolw::Zolw(int x, int y, Swiat& s)
		:Zwierze(x, y, s)
	{
		sila = 2;
		inicjatywa = 1;
		nazwa = zolw;
	}

	void Zolw::rysowanie()
	{
		cout << "Z";
	}

	bool Zolw::czyOdbilAtak(Organizm* org1)
	{
		if(org1->getSila() < 5)
		return true;
		else return false;
	}

	void Zolw::akcja()
	{
		int X = this->x;
		int Y = this->y;
		int szansa = rand() % 100;
		bool flaga = true;
		if (szansa >= 75)
		{
			losuj_pozycje(X, Y);
			int k = s->sprawdz(X, Y);

			if (k != -1)
			{
				Organizm* w = s->getOrg(k);

				kolizja(w, X, Y);

			}
			else
			{
				this->x = X;
				this->y = Y;
			}
		}
	}




	Zolw::~Zolw()
	{
	}

}