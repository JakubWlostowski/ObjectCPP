#include "stdafx.h"
#include "Owca.h"
#include<iostream>
using namespace std;

namespace Zwierzeta
{
	Owca::Owca(int x, int y, Swiat& s)
		:Zwierze(x, y, s)
	{
		sila = 4;
		inicjatywa = 4;
		nazwa = owca;
	}

	void Owca::rysowanie()
	{
		cout << 'O';
	}


	Owca::~Owca()
	{
	}

}