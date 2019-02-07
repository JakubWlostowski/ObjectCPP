#include "stdafx.h"
#include "WilczeJagody.h"
#include<iostream>
using namespace std;

WilczeJagody::WilczeJagody(int x, int y, Swiat& s)
	:Roslina(x, y, s)
{
	sila = 99;
	inicjatywa = 0;
	nazwa = jagody;
}

void WilczeJagody::rysowanie()
{
	cout << 'J';
}


WilczeJagody::~WilczeJagody()
{
}
