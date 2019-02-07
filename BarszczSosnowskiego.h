#pragma once
#include "Roslina.h"
class BarszczSosnowskiego :
	public Roslina
{
public:
	BarszczSosnowskiego(int x, int y, Swiat& s);
	void rysowanie() override;
	void akcja() override;
	~BarszczSosnowskiego();
};

