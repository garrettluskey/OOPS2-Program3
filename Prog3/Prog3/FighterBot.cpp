#include "stdafx.h"
#include "FighterBot.h"
FighterBot::FighterBot(int x, int y, Panel ^ drawingPanel) : VBot(x, y, drawingPanel)
{
	 image = gcnew Drawing::Bitmap("AttackBot.bmp");
	 energy = 100;
}
void FighterBot::Move()
{
	if (x > panel->Width) {
		x = 0;
	}
	if (y > panel->Height) {
		y = 0;
	}
	x += 5;
	y += 5;
	--energy;
}

void FighterBot::Show()
{
	VBot::Show();
}

int FighterBot::EnergyToFightWith()
{
	return energy;
}
