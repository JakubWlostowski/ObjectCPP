#include "stdafx.h"
#include "Antylopa.h"
#include<iostream>

namespace Zwierzeta
{
	Antylopa::Antylopa(int x, int y, Swiat& s)
		:Zwierze(x, y, s)
	{
		sila = 4;
		inicjatywa = 4;
		nazwa = antylopa;
	}

	void Antylopa::rysowanie()
	{
		cout << 'A';
	}

	void Antylopa::akcja()
	{
		int x = this->x;
		int y = this->y;
		int szansa = rand() % 100;
		bool flaga = true;
		while (flaga)
		{
			int opcja = rand() % 4;
			if (opcja == 0 && x <= s->getrozmX() - 2)
			{
				x+=2;
				flaga = false;
			}
			else if (opcja == 1 && x > 2)
			{
				x-=2;
				flaga = false;
			}
			else if (opcja == 2 && y <= s->getrozmY() - 2)
			{
				y+=2;
				flaga = false;
			}
			else if (opcja == 3 && y > 2)
			{
				y-=2;
				flaga = false;
			}
		}

		int k = s->sprawdz(x, y);

		if (k != -1)
		{
			Organizm* w = s->getOrg(k);
			if(szansa >= 50)
			Zwierze::kolizja(w, x, y);
			else if(sprawdz_wokol() == true)
			{
				Antylopa::kolizja(w, x, y);
			}
			else
				Zwierze::kolizja(w, x, y);
		}
		else
		{
			this->x = x;
			this->y = y;
		}
	}

	void Antylopa::kolizja(Organizm* org1, int x, int y)
	{
		while (s->sprawdz(x, y) != -1)
		{
			bool flaga = true;
			while (flaga)
			{
				int opcja = rand() % 4;
				if (opcja == 0 && x <= s->getrozmX() - 1)
				{
					x++;
					flaga = false;
				}
				else if (opcja == 1 && x > 1)
				{
					x--;
					flaga = false;
				}
				else if (opcja == 2 && y <= s->getrozmY() - 1)
				{
					y++;
					flaga = false;
				}
				else if (opcja == 3 && y > 1)
				{
					y--;
					flaga = false;
				}
			}
		}
		this->x = x;
		this->y = y;
	}



	Antylopa::~Antylopa()
	{
	}

}