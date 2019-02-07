#pragma once
#include "Zwierzeta.h"
namespace Zwierzeta
{
	class Owca :
		public Zwierze
	{
	public:
		void rysowanie() override;
		Owca(int x, int y, Swiat& s);
		~Owca();
	};
}

