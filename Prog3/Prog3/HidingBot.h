#pragma once
#include "VBot.h"
class HidingBot : public VBot {
public:
	HidingBot(int x, int y, Panel ^ drawingPanel);
	//Hides in nearest corner
	void Move();
	//Displays bot
	void Show();
	int EnergyToFightWith();
};