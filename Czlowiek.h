#pragma once
#include "Zwierzeta.h"
namespace Zwierzeta
{
	class Czlowiek :
		public Zwierze
	{
		int flaga_moc;
		int zliczaj_tury;
		int kierunek;
	public:
		int getFlagaMoc();
		int getZliczajTury();
		void setKierunek(int kier);
		void setFlagaMoc(int flaga);
		void rysowanie() override;
		Czlowiek(int x, int y, Swiat& s);
		virtual void akcja() override;
		virtual void kolizja(Organizm *org1, int x, int y) override;
		~Czlowiek();
	};
}
