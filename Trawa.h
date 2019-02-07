#pragma once
#include "Roslina.h"
class Trawa :
	public Roslina
{
public:
	void rysowanie() override;
	Trawa(int x, int y, Swiat& s);
	~Trawa();
};

