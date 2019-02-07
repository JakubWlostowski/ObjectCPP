#include "stdafx.h"
#include "Trawa.h"
#include<iostream>
using namespace std;


Trawa::Trawa(int x, int y, Swiat& s)
	:Roslina(x, y, s)
{
	sila = 0;
	inicjatywa = 0;
	nazwa = trawa;
}

void Trawa::rysowanie()
{
	cout << 'T';
}

Trawa::~Trawa()
{
}
