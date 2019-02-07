#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<algorithm>
#include<string>
#include"Swiat.h"
#include "Zwierzeta.h"
#include"Organizm.h"
#include"Wilk.h"
#include"Lis.h"
#include"Owca.h"
#include"Zolw.h"
#include"Antylopa.h"
using namespace std;

namespace Zwierzeta
{

	bool Zwierze::czyOdbilAtak(Organizm *org1)//ok
	{
		return false;
	}

	void Zwierze::akcja()//ok
	{
		
		int X = this->x;
		int Y = this->y;

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

		this->wiek++;
	}

	void Zwierze::kolizja(Organizm* org1, int x, int y)
	{
		int k = s->sprawdz(x, y);
		if (org1->getNazwa() != this->getNazwa())
		{
			if (czyOdbilAtak(org1) == false)
			{
				if (this->sila >= org1->getSila())
				{
					this->sila += dodaj_sile();
					string n1 = to_string(x);
					string n2 = to_string(y);
					s->dodaj_info(this->nazwa_organizmu() + " zjada " + org1->nazwa_organizmu() + " na pozycji " + n1 + "," + n2);
					s->usun_org(org1);
				}
				else
				{
					string n1 = to_string(x);
					string n2 = to_string(y);
					s->dodaj_info(org1->nazwa_organizmu() + " zjada " + this->nazwa_organizmu() + " na pozycji " + n1 + "," + n2);
					s->usun_org(this);
					this->x = x;
					this->y = y;
				}
			}

		}
		else
		{
			int X = this->x;
			int Y = this->y;
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

			if (s->sprawdz(X, Y) != -1)
			{

				switch (this->nazwa)
				{
				case wilk:
				{
					Wilk* w = new Wilk(X, Y, *s);
					s->dodaj_org(w);
					string n1 = to_string(x);
					string n2 = to_string(y);
					s->dodaj_info("Wilk sie rozmnozyl");
					break;
				}


				case owca:
				{
					Owca* o = new Owca(X, Y, *s);
					s->dodaj_org(o);
					s->dodaj_info("Owca sie rozmnozyla");
					break;
				}
				case lis:
				{
					Lis* l = new Lis(X, Y, *s);
					s->dodaj_org(l);
					s->dodaj_info("Lis sie rozmnozyl");
					break;
				}

				case antylopa:
				{
					Antylopa* ant = new Antylopa(X, Y, *s);
					s->dodaj_org(ant);
					s->dodaj_info("Antylopa sie rozmnozyla");
					break;
				}

				case zolw:
				{
					Zolw* z = new Zolw(X, Y, *s);
					s->dodaj_org(z);
					s->dodaj_info("Zolw sie rozmnozyl");
					break;
				}
				default:
					break;

				}
			}
		}


	}

	Zwierze::Zwierze(int x, int y, Swiat& s)
		:Organizm(x, y, s)
	{

	}

	Zwierze::~Zwierze()
	{

	}
}