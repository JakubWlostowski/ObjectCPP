#include "stdafx.h"
#include "BarszczSosnowskiego.h"
#include"Swiat.h"
#include<iostream>
using namespace std;

BarszczSosnowskiego::BarszczSosnowskiego(int x, int y, Swiat& s)
	:Roslina(x, y, s)
{
	sila = 100;
	inicjatywa = 0;
	nazwa = barszcz;
}

void BarszczSosnowskiego::rysowanie()
{
	cout << 'B';
}

void BarszczSosnowskiego::akcja()
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
			case barszcz:
			{	
				BarszczSosnowskiego* m = new BarszczSosnowskiego(X, Y, *s);
				s->dodaj_org(m);
				break;
			}
			}
		}

	}


		if (s->sprawdz(x + 1, y) != -1 && s->getOrg(s->sprawdz(x + 1, y))->getNazwa() != barszcz)
		{
			int k = s->sprawdz(x + 1, y);
			Organizm* w = s->getOrg(k);
			s->usun_org(w);
		}
		else if (s->sprawdz(x - 1, y) != -1  && s->getOrg(s->sprawdz(x - 1, y))->getNazwa() != barszcz)
		{
			int k = s->sprawdz(x - 1, y);
			Organizm* w = s->getOrg(k);
			s->usun_org(w);
		}
		else if (s->sprawdz(x, y + 1) != -1  && s->getOrg(s->sprawdz(x , y+1))->getNazwa() != barszcz)
		{
			int k = s->sprawdz(x, y + 1);
			Organizm* w = s->getOrg(k);
			s->usun_org(w);
		}
		else if (s->sprawdz(x, y - 1) != -1 && s->getOrg(s->sprawdz(x , y-1))->getNazwa() != barszcz)
		{
			int k = s->sprawdz(x, y - 1);
			Organizm* w = s->getOrg(k);
			s->usun_org(w);
		}
	
	

}

BarszczSosnowskiego::~BarszczSosnowskiego()
{
}
