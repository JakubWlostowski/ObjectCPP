#pragma once
#include "Zwierzeta.h"
namespace Zwierzeta
{
	class Lis :
		public Zwierze
	{
	public:
		void rysowanie() override;
		virtual void akcja() override;
		Lis(int x, int y, Swiat& s);
		~Lis();
	};
}
