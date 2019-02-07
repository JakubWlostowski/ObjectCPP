#pragma once
#include "Organizm.h"
#include "Swiat.h"
#include<vector>

namespace Zwierzeta
{
	class Zwierze : public Organizm
	{

	public:

		virtual void akcja() override;
		virtual void kolizja(Organizm* org1, int x, int y) override;
		virtual bool czyOdbilAtak(Organizm* org1) override;
		void zwiekszSile(size_t s) { sila += s; };
		Zwierze(int x, int y, Swiat& s);
		virtual ~Zwierze();

	};
}