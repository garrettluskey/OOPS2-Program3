#pragma once

#include "VBot.h"
class RandomBot : public VBot {
	public:
		RandomBot(int x, int y, Panel ^ drawingPanel);
		//Move Randomly
		void Move();
		//Display Bot
		void Show();
		int EnergyToFightWith();
};