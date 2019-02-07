#pragma once
#include "Zwierzeta.h"
#include "Organizm.h"
namespace Zwierzeta
{
	class Wilk : public Zwierze
	{
	public:

		void rysowanie() override;
		Wilk(int x, int y, Swiat& s);
	};
}