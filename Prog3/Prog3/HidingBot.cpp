#include "stdafx.h"
#include "HidingBot.h"
HidingBot::HidingBot(int x, int y, Panel ^ drawingPanel) : VBot(x, y, drawingPanel) {
	image = gcnew Drawing::Bitmap("HidingBot.bmp");
}
void HidingBot::Move()
{
	if (x > panel->Width) {
		x = 0;
	}
	if (y > panel->Height) {
		y = 0;
	}
	if (panel->Width - x < panel->Width / 2 && x < panel->Width) {
		x += 1;
	}
	else
	{
		if (x > 0) {
			x -= 1;
		}
		
	}
	if (panel->Height - y < panel->Height / 2 && y < panel->Height) {
		y += 1;
	}
	else
	{
		if (y > 0) {
			y -= 1;
		}
		
	}
	++energy;
}

void HidingBot::Show()
{
	VBot::Show();
}

int HidingBot::EnergyToFightWith()
{
	return energy;
}
