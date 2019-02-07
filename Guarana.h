#pragma once
#include "Roslina.h"
class Guarana :
	public Roslina
{
public:
	void rysowanie() override;
	//void kolizja(Organizm* org1, int x, int y) override;
	virtual int dodaj_sile() override;
	Guarana(int x, int y, Swiat& s);
	~Guarana();
};

