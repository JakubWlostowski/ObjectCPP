#pragma once
#include "Roslina.h"
class Mlecz :
	public Roslina
{
public:
	void rysowanie() override;
	void akcja() override;
	Mlecz(int x, int y, Swiat& s);
	~Mlecz();
};

