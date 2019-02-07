#include "stdafx.h"
#include<iostream>
#include"Swiat.h"
#include "Wilk.h"
using namespace std;
namespace Zwierzeta
{
	Wilk::Wilk(int x, int y, Swiat& s)
		:Zwierze(x, y, s)
	{
		sila = 9;
		inicjatywa = 5;
		nazwa = wilk;
	}

	void Wilk::rysowanie()
	{
		cout << 'W';
	}
}