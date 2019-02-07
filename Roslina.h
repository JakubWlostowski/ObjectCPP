#pragma once
#include "Organizm.h"
class Roslina :
	public Organizm
{
public:
	Roslina(int x, int y, Swiat& s);
	virtual void akcja() override;
	virtual void kolizja(Organizm* org1, int x, int y) override;
	virtual bool czyOdbilAtak(Organizm *org1) override;
	~Roslina();
};

