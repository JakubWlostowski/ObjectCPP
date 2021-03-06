// ProjektPO.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<time.h>
#include<iosfwd>
#include<conio.h>
#include"Swiat.h"
#include "Organizm.h"
#include "Zwierzeta.h"
#include"Wilk.h"
#include"Owca.h"
#include"Czlowiek.h"
#include"Lis.h"
#include"Zolw.h"
#include"Trawa.h"
#include"Antylopa.h"
#include"Mlecz.h"
#include"WilczeJagody.h"
#include"BarszczSosnowskiego.h"
#include"Guarana.h"
using namespace std;
using namespace Zwierzeta;

void losuj_org(Swiat &s)
{
	int x = 1;
	int y = 1;
	int liczba = s.getLiczba_org() / 10;
	
	for (int i = 0; i < s.getLiczba_org() - 1; i++)
	{
		if (i < liczba)
		{
			while (s.sprawdz(x, y) != -1)
			{
				x = rand() % s.getrozmX() + 1;
				y = rand() % s.getrozmY() + 1;
			}
			Wilk* w1 = new Wilk(x, y, s);
			s.dodaj_org(w1);
		}
		else if (i < liczba * 2)
		{
			while (s.sprawdz(x, y) != -1)
			{
				x = rand() % s.getrozmX() + 1;
				y = rand() % s.getrozmY() + 1;
			}
			Lis* l1 = new Lis(x, y, s);
			s.dodaj_org(l1);
		}
		else if (i < liczba * 3)
		{
			while (s.sprawdz(x, y) != -1)
			{
				x = rand() % s.getrozmX() + 1;
				y = rand() % s.getrozmY() + 1;
			}
			Zolw* l1 = new Zolw(x, y, s);
			s.dodaj_org(l1);
		}
		else if (i < liczba * 4)
		{
			while (s.sprawdz(x, y) != -1)
			{
				x = rand() % s.getrozmX() + 1;
				y = rand() % s.getrozmY() + 1;
			}
			Antylopa* l1 = new Antylopa(x, y, s);
			s.dodaj_org(l1);
		}
		else if (i < liczba * 5)
		{
			while (s.sprawdz(x, y) != -1)
			{
				x = rand() % s.getrozmX() + 1;
				y = rand() % s.getrozmY() + 1;
			}
			Trawa* l1 = new Trawa(x, y, s);
			s.dodaj_org(l1);
		}
		else if (i < liczba * 6)
		{
			while (s.sprawdz(x, y) != -1)
			{
				x = rand() % s.getrozmX() + 1;
				y = rand() % s.getrozmY() + 1;
			}
			Mlecz* l1 = new Mlecz(x, y, s);
			s.dodaj_org(l1);
		}
		else if (i < liczba * 7)
		{
			while (s.sprawdz(x, y) != -1)
			{
				x = rand() % s.getrozmX() + 1;
				y = rand() % s.getrozmY() + 1;
			}
			WilczeJagody* l1 = new WilczeJagody(x, y, s);
			s.dodaj_org(l1);
		}
		else if (i < liczba * 8)
		{
			while (s.sprawdz(x, y) != -1)
			{
				x = rand() % s.getrozmX() + 1;
				y = rand() % s.getrozmY() + 1;
			}
			BarszczSosnowskiego* l1 = new BarszczSosnowskiego(x, y, s);
			s.dodaj_org(l1);
		}
		else if (i < liczba * 9)
		{
			while (s.sprawdz(x, y) != -1)
			{
				x = rand() % s.getrozmX() + 1;
				y = rand() % s.getrozmY() + 1;
			}
			Guarana* l1 = new Guarana(x, y, s);
			s.dodaj_org(l1);
		}
		else
		{
			while (s.sprawdz(x, y) != -1)
			{
				x = rand() % s.getrozmX() + 1;
				y = rand() % s.getrozmY() + 1;
			}
			Owca* o1 = new Owca(x, y, s);
			s.dodaj_org(o1);
		}
	}


}


void menu()
{
	cout << "Jakub Wlostowski 171559" << endl;
	cout << "Wcisnij t, aby rozpoczac nowa ture" << endl;
	cout << "Strzalkami poruszaj czlowiekiem" << endl;
	cout << "Wcisnij s, aby zapisac stan gry" << endl;
	cout << "Wcisnij l, aby zaladowac stan gry" << endl;
	cout << "Wcisnij b, aby aktywowac supermoc" << endl;
}

int main()
{
	srand(time(NULL));
	int n;
	int a, b;
	int x = 3;
	int y = 3;
	menu();
	cin >> a;
	cin >> b;
	int l_org = (a*b) / 10;
	Swiat s1(a, b, l_org);
	while (s1.sprawdz(x, y) != -1)
	{
		x = rand() % s1.getrozmX() + 1;
		y = rand() % s1.getrozmY() + 1;
	}
	Czlowiek* c = new Czlowiek(x, y, s1);
	s1.dodaj_org(c);
	losuj_org(s1);

	
	s1.rysujSwiat();

	while (n = _getch())
	{
		s1.rysujSwiat();

		if (n == 98 && c->getFlagaMoc() == 0 && c->getZliczajTury() <5)
		{
			c->setFlagaMoc(1);
		}
		else if (n == 116)
		{
			s1.wykonajTure();
			c->setKierunek(5);
		}
		else if (n == 224)
		{
			n = _getch();

			switch (n)
			{
			case 72:
				c->setKierunek(0);
				break;
			case 80:
				c->setKierunek(1);
				break;
			case 75:
				c->setKierunek(2);
				break;
			case 77:
				c->setKierunek(3);
				break;
			default:
				break;
			}
			s1.wykonajTure();

		}
		else if (n == 27)
			break;
		else if (n == 115)
		{
			s1.zapisz();
		}
		else if (n == 108)
		{
			s1.wczytaj();
		}

	}

	return 0;

	}
	
    


