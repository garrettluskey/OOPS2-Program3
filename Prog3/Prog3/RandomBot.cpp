#include "RandomBot.h"
RandomBot::RandomBot(int x, int y, Panel ^ drawingPanel) : VBot(x, y, drawingPanel) {
	image = gcnew Drawing::Bitmap("RandomBot.bmp");
	
}
void RandomBot::Move()
{
	Random R;
	if (x > panel->Width) {
		x = 0;
	}
	else if (x < 0) {
		x = panel->Width;
	}
	if (y > panel->Height) {
		y = 0;
	}
	else if (y < 0) {
		y = panel->Height;
	}
	x += (R.Next(-5,5));
	y += (R.Next(-5, 5));
	--energy;
}

void RandomBot::Show()
{
	VBot::Show();
}

int RandomBot::EnergyToFightWith()
{
	Random R;
	return R.Next(0, 200);
}
