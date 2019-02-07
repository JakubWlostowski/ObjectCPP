#include "stdafx.h"
#include "Guarana.h"
#include"Organizm.h"
#include"Swiat.h"
#include"Roslina.h"
#include"Zwierzeta.h"
#include<iostream>
using namespace std;

Guarana::Guarana(int x, int y, Swiat& s)
	:Roslina(x, y, s)
{
	sila = 0;
	inicjatywa = 0;
	nazwa = guarana;
}

int Guarana::dodaj_sile()
{
	return 3;
}

void Guarana::rysowanie()
{
	cout << 'G';
}



Guarana::~Guarana()
{
}
