#pragma once
#include "Zwierzeta.h"
namespace Zwierzeta
{
	class Antylopa :
		public Zwierze
	{
	public:
		void rysowanie() override;
		Antylopa(int x, int y, Swiat& s);
		void akcja() override;
		virtual void kolizja(Organizm* org1, int x, int y) override;
		~Antylopa();
	};
}
