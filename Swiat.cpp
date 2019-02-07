#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string>
#include<fstream>
#include"Swiat.h"
#include"Organizm.h"
#include"Wilk.h"
#include"Owca.h"
#include"Lis.h"
#include"Antylopa.h"
#include"Zolw.h"
#include"Trawa.h"
#include"Mlecz.h"
#include"Guarana.h"
#include"BarszczSosnowskiego.h"
#include"WilczeJagody.h"
#include"Zwierzeta.h"
#include"Czlowiek.h"
#include"Roslina.h"
#define ROZM 20
using namespace std;

int Swiat::sprawdz(int a, int b)
{
	for (int i = 0; i < organizmy.size(); i++)
	{
		if (organizmy[i]->getX() == a && organizmy[i]->getY()== b)
		{
			return i;
		}
	}
	return -1;
}

void Swiat::rysujSwiat()
{
	system("cls");
	for (int i = 0; i <= rozmY+1; i++)
	{
		for (int j = 0; j <= rozmX +1; j++)
		{
			int k = sprawdz(j, i);

			if (i == 0 || j == 0 || i == rozmY +1 || j == rozmX+1 )
			{
				cout << 'X';
			}
			else if (k != -1)
			{
				organizmy[k]->rysowanie();
			}
			else cout << ' ';

			
		}
		cout << endl;
	}

	for (int l = 0; l < info.size(); l++)
	{
		cout << info[l]<<endl;
	}
	info.clear();
}

Swiat::Swiat(int rozmX, int rozmY,int liczba_org)
{
	this->rozmX = rozmX;
	this->rozmY = rozmY;
	this->liczba_org = liczba_org;
}

Organizm* Swiat::operator[](int i)
{
	return organizmy[i];
}

int Swiat::getLiczba_org()
{
	return liczba_org;
}

int Swiat::getrozmX()
{
	return rozmX;
}

int Swiat::getrozmY()
{
	return rozmY;
}

void Swiat::dodaj_org(Organizm* org)
{
	organizmy.push_back(org);
}

Organizm* Swiat::getOrg(int i)//ok
{
	return organizmy[i];
}

void Swiat::dodaj_info(string inf)
{
	info.push_back(inf);
}

void Swiat::zapisz()
{
	fstream plik("zapis.txt",ios::out);
	
	plik << rozmX << endl;
	plik << rozmY << endl;
	plik << organizmy.size() << endl;

	for (int i = 0; i < organizmy.size(); i++)
	{
		plik << organizmy[i]->getInicjatywa() << endl;
		plik << organizmy[i]->getSila() << endl;
		plik << organizmy[i]->getX() << endl;
		plik << organizmy[i]->getY() << endl;
		plik << organizmy[i]->nazwa_organizmu()<<endl;
	}
}

void Swiat::wczytaj()
{
	fstream plik;
	organizmy.clear();
	plik.open("zapis.txt", ios::in);
	plik >> this->rozmX;
	plik >> this->rozmY;
	plik >> this->liczba_org;
	
	int inic, sila, X, Y;
	string nazwa;
	
	for (int i = 0; i < this->liczba_org; i++)
	{
		plik >> inic;
		plik >> sila;
		plik >> X;
		plik >> Y;
		plik >> nazwa;
		Organizm* org;
		
		if (nazwa == "Wilk")
			org = new Zwierzeta::Wilk(X, Y, *this);
		else if (nazwa == "Owca")
			org = new Zwierzeta::Owca(X, Y, *this);
		else if (nazwa == "Lis")
			org = new Zwierzeta::Lis(X, Y, *this);
		else if (nazwa == "Zolw")
			org = new Zwierzeta::Zolw(X, Y, *this);
		else if (nazwa == "Antylopa")
			org = new Zwierzeta::Antylopa(X, Y, *this);
		else if (nazwa == "Czlowiek")
			org = new Zwierzeta::Czlowiek(X, Y, *this);
		else if (nazwa == "Trawa")
			org = new Trawa(X, Y, *this);
		else if (nazwa == "Mlecz")
			org = new Mlecz(X, Y, *this);
		else if (nazwa == "Jagody")
			org = new WilczeJagody(X, Y, *this);
		else if (nazwa == "Barszcz")
			org = new BarszczSosnowskiego(X, Y, *this);
		else if (nazwa == "Guarana")
			org = new Guarana(X, Y, *this);
		else
			org = nullptr;

		this->dodaj_org(org);
		organizmy[i]->setInicjatywa(inic);
		organizmy[i]->setSila(sila);
		
	}

}

Swiat::~Swiat()
{
}

void Swiat::usun_org(Organizm* org)
{
	organizmy.erase(remove(organizmy.begin(), organizmy.end(), org), organizmy.end());
}

void Swiat::wykonajTure()
{
	sort(organizmy.begin(), organizmy.end(), [](Organizm* lhs, Organizm* rhs) {return lhs->getWiek() > rhs->getWiek(); });
	sort(organizmy.begin(), organizmy.end(), [](Organizm* lhs, Organizm* rhs) {return lhs->getInicjatywa() > rhs->getInicjatywa(); });

	for (int i = 0; i < organizmy.size(); i++)
	{
		organizmy[i]->akcja();
	}
}

