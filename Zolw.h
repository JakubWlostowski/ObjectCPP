#pragma once
#include "Zwierzeta.h"
namespace Zwierzeta
{
	class Zolw :
		public Zwierze
	{
	public:
		void rysowanie() override;
		virtual void akcja() override;
		virtual bool czyOdbilAtak(Organizm* org1) override;
		Zolw(int x, int y, Swiat& s);
		~Zolw();
	};
}

