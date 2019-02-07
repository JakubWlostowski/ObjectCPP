#include "stdafx.h"*+++++++++
#include "Czlowiek.h"
#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

namespace Zwierzeta
{
	Czlowiek::Czlowiek(int x, int y, Swiat& s)
		:Zwierze(x, y, s)
	{
		sila = 5;
		inicjatywa = 4;
		flaga_moc = 0;
		zliczaj_tury = 0;
		nazwa = czlowiek;
		kierunek = 5;
	}

	void Czlowiek::rysowanie()
	{
		cout << 'C';
	}

	void Czlowiek::setKierunek(int kier)
	{
		this->kierunek = kier;
	}

	void Czlowiek::akcja()
	{
		int k = s->sprawdz(x , y);
		Organizm* w = s->getOrg(k);
		if (kierunek == 0 && y > 1) y--;
		else if (kierunek == 1 && y < s->getrozmY()) y++;
		else if (kierunek == 2 && x > 1) x--;
		else if (kierunek == 3 && x < s->getrozmX()) x++;


		if (flaga_moc == 1)
			Czlowiek::kolizja(w, x, y);
		else
			Zwierze::kolizja(w, x, y);

		zliczaj_tury++;

		if (zliczaj_tury == 5)
			flaga_moc = 0;
		else if (zliczaj_tury == 10)
		{
			zliczaj_tury = 0;
		}
	}

	int Czlowiek::getFlagaMoc()
	{
		return flaga_moc;
	}

	int Czlowiek::getZliczajTury()
	{
		return zliczaj_tury;
	}

	void Czlowiek::setFlagaMoc(int flaga)
	{
		this->flaga_moc = flaga;
	}

	void Czlowiek::kolizja(Organizm *org1, int x, int y)
	{
		

		

		if (this->s->sprawdz(x + 1, y) != -1 && s->getOrg(s->sprawdz(x + 1, y))->getNazwa() != czlowiek)
		{
			int k = s->sprawdz(x + 1, y);
			Organizm* w = s->getOrg(k);
			s->usun_org(w);
		}
		else if (this->s->sprawdz(x - 1, y) != -1 && s->getOrg(s->sprawdz(x - 1, y))->getNazwa() != czlowiek)
		{
			int k = s->sprawdz(x - 1, y);
			Organizm* w = s->getOrg(k);
			s->usun_org(w);
		}
		else if (this->s->sprawdz(x, y + 1) != -1 && s->getOrg(s->sprawdz(x , y +1))->getNazwa() != czlowiek)
		{
			int k = s->sprawdz(x, y + 1);
			Organizm* w = s->getOrg(k);
			s->usun_org(w);
		}
		else if (this->s->sprawdz(x, y - 1) != -1 && s->getOrg(s->sprawdz(x , y -1))->getNazwa() != czlowiek)
		{
			int k = s->sprawdz(x, y - 1);
			Organizm* w = s->getOrg(k);
			s->usun_org(w);
		}
	}


	Czlowiek::~Czlowiek()
	{
	}
}
